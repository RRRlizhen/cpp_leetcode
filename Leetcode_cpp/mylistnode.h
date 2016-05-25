#ifndef MYLISTNODE_H_INCLUDED
#define MYLISTNODE_H_INCLUDED
#include <algorithm>
#include <climits>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;


class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(nullptr) {}
};
struct RandomListNode{
        int label;
        RandomListNode *next,*random;
        RandomListNode(int x):label(x),next(nullptr),random(nullptr){}
};
class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};

class LZ
{
public:

    ListNode* revOnPlace(ListNode *head)
    {
        ListNode dummy(-1);
        ListNode *curr = head;

        head = &dummy;
        while(curr)
        {
            ListNode *tmp = curr->next;
            curr->next = head->next;
            head->next = curr;
            curr = tmp;
        }

        return dummy.next;
    }

    ///
    void showList(ListNode *head)
    {
        while(head)
        {
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    void showList(RandomListNode *head){
        while(head){
            cout<<head->label<<" ";
            head = head->next;
        }cout<<endl;
    }

    ///
    void showTree(TreeNode *root){
        if(root){
            cout<<root->val<<" ";
            showTree(root->left);
            showTree(root->right);
        }
    }
    void showTreeInorder(TreeNode *root){
        if(root->left) showTreeInorder(root->left);
        cout<<root->val<<" ";
        if(root->right) showTreeInorder(root->right);

    }

    void reorderList(ListNode* head)
    {
        if(head==nullptr || head->next==nullptr) return;
        ListNode *slow, *fast;
        ListNode *prev;
        slow = fast = head;
        prev = nullptr;
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = prev->next;
        prev->next = nullptr;

        head2 = revOnPlace(head2);
        cout<<"head1: ";showList(head);
        cout<<"head2: ";showList(head2);

        ListNode *head1 = head;
        slow = head1;
        fast = head2;
        while(slow && fast){
            ListNode *t1 = slow->next;
            ListNode *t2 = fast->next;
            head1->next = slow;
            head1->next->next = fast;
            head1 = fast;
            slow = t1;
            fast = t2;
        }
        cout<<"done";showList(head);
    }


    ///
    TreeNode* sortedListToBST2(ListNode* head) {
        TreeNode *root = nullptr;
        if(head==nullptr) return root;
        root = new TreeNode(head->val);

        ListNode *curr = head->next;
        while(curr){
            ///find the insert localtion
            TreeNode *f = root;
            TreeNode *parent = nullptr;
            while(f){
                parent = f;
                if(curr->val < f->val) f = f->left;
                if(curr->val >= f->val) f = f->right;
            }
            if(curr->val < parent->val){
                parent->left = new TreeNode(curr->val);
            }else{
                parent->right = new TreeNode(curr->val);
            }

            curr = curr->next;
        }
        return root;
    }

    ///
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }else if(head->next==nullptr){
            return new TreeNode(head->val);
        }

        ListNode *slow,*fast,*prev;
        slow = fast = head;
        prev = nullptr;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        showList(head);
        showList(slow);
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }///


    ///
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        int carray = 0;
        ListNode *prev = nullptr;
        ListNode *head = l1;
        showList(l1);
        showList(l2);
        while(l1 && l2){
            int tmp = l1->val + l2->val + carray;
            carray = tmp>9 ? 1:0;
            l1->val = tmp%10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int tmp = l1->val+carray;
            carray = tmp>9 ? 1:0;
            l1->val = tmp%10;
            prev = l1;
            l1 = l1->next;
        }
        while(l2){
            int tmp = l2->val+carray;
            carray = tmp>9 ? 1:0;
            l2->val = tmp%10;
            prev->next = l2;
            prev = l2;
            l2 = l2->next;
        }
        if(carray==1) prev->next = new ListNode(1);
        return head;
    }


    ///
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *head1,*head2;
        ListNode *p1,*p2,*curr;
        ListNode dummy1(-1);
        ListNode dummy2(-1);
        curr = head;
        p1 = head1 = &dummy1;
        p2 = head2 = &dummy2;

        while(curr){
            if(curr->val < x){
                p1->next = curr;
                p1 = p1->next;
                //p1->next = nullptr;
            }else{
                p2->next = curr;
                p2 = p2->next;
                //p2->next = nullptr;
            }
            curr = curr->next;
        }
        p1->next = nullptr;
        p2->next = nullptr;
        showList(head1->next);
        showList(head2->next);

        p1->next = head2->next;
        return head1->next;
    }

    ///
    ListNode *findLocationInsert(ListNode *head,int x){
        for(;head->next;head = head->next){
            if(head->next->val >= x) break;
        }
        return head;
    }
    ListNode *insertionSortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode dummy(-1);
        ListNode *curr,*in;
        curr = head;
        for(;curr;){
            in = &dummy;
            in = findLocationInsert(in,curr->val);
            ListNode *tmp = curr->next;
            curr->next = in->next;
            in->next = curr;
            curr = tmp;
        }
        return dummy.next;
    }


    ///
    ListNode *mergeList(ListNode *l1, ListNode *l2){
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode dummy(-1);
        ListNode *p = &dummy;
        while(l1 || l2){
            int val1 = l1==nullptr? INT_MAX : l1->val;
            int val2 = l2==nullptr? INT_MAX : l2->val;
            if(val1<=val2){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        cout<<"---";showList(dummy.next);

        return dummy.next;
    }
    ListNode *sortList(ListNode *head){
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *fast,*slow;
        fast = slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = nullptr;

        //showList(head);
        //showList(slow);cout<<endl;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        head = mergeList(l1,l2);

        return head;
    }


    ///
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ///
        if(lists.empty()) return nullptr;

        ListNode *p = lists[0];
        for(int i = 1;i<(int)lists.size();i++){
            p = mergeList(p,lists[i]);
        }
        return p;
    }



    ///
    void CountingSort(int *A,int *B,int *Order,int N,int K){
        int *C = new int[K+1];
        int i;
        memset(C,0,sizeof(int)*(K+1));
        for(i = 1;i<=N;i++){///
            C[A[i]]++;
        }


        for(i = 2;i<=K;i++){
            C[i] += C[i-1];
        }
        cout<<endl;
        for(int i = 1;i<(K+1);i++){
            cout<<C[i]<<" ";
        }cout<<endl;

        for(i=N;i>=1;i--){
            B[C[A[i]]] = A[i];
            Order[C[A[i]]] = i;
            C[A[i]]--;
        }
    }

    void testCS(){
        ///=============
    int *A,*B,*Order,N = 15,K = 10,i;
    A = new int[N+1];
    B = new int[N+1];
    Order = new int[N+1];
    for(i = 1;i<=N;i++){
        A[i] = rand()%K+1;
    }
    printf("Before cs: \n");
    for(i = 1;i<=N;i++){
        printf("%d ",A[i]);
    }
    CountingSort(A,B,Order,N,K);
    printf("\nafter cs:\n");
    for(i = 1;i<=N;i++){
        printf("%d ",B[i]);
    }
    printf("\nOrder:\n");
    for(i = 1;i<=N;i++){
        printf("%d ",Order[i]);
    }
    cout<<"done"<<endl;
    ///================
    }

    ///
    const int BUCKET_NUM = 10;
    ListNode *insert(ListNode *head, int val){
        ListNode dummyNode(-1);
        ListNode *newNode = new ListNode(val);
        ListNode *prev,*curr;
        dummyNode.next = head;
        prev = &dummyNode;
        curr = head;
        while(curr && curr->val <= val){
            prev = curr;
            curr = curr->next;
        }///find location to insert; prev->next
        newNode->next = curr;
        prev->next = newNode;
        return dummyNode.next;
    }

    ListNode *mergebucket(ListNode *head1,ListNode *head2){
        ListNode dummy(-1);
        ListNode *h = &dummy;
        while(head1 && head2){
            if(head1->val <= head2->val){
                h->next = head1;
                head1 = head1->next;
            }else{
                h->next = head2;
                head2 = head2->next;
            }
            h = h->next;
        }
        if(head1) h->next = head1;
        if(head2) h->next = head2;
        return dummy.next;
    }

    void BucketSort(int n,int arr[]){
        vector<ListNode*> buckets(BUCKET_NUM,nullptr);
        for(int i = 0;i<n;i++){
            int index = arr[i]%BUCKET_NUM;
            ListNode *head = buckets[index];
            buckets[index] = insert(head,arr[i]);
        }///
        ListNode *head = buckets[0];
        for(int i = 1;i<BUCKET_NUM;i++){
            head = mergebucket(head,buckets[i]);
        }

        for(int i = 0;i<n;i++){
            arr[i] = head->val;
            head = head->next;
        }
    }

    ///
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode dummy1(-1);
        ListNode dummy2(-2);
        ListNode *h1 = &dummy1;
        ListNode *h2 = &dummy2;
        int k = 1;
        while(head){
            if(k%2==0){
                h1->next = head;
                h1 = h1->next;
            }else{
                h2->next = head;
                h2 = h2->next;
            }
            k++;
            head = head->next;
        }
        h2->next = dummy1.next;
        h1->next = nullptr;
        return dummy2.next;
    }


    ///

    RandomListNode *copyRandomList(RandomListNode *head){
        RandomListNode *curr = head;
        while(curr){
            RandomListNode *node = new RandomListNode(curr->label);
            node->next = curr->next;
            curr->next = node;
            curr = node->next;
        }///a->f_a->  b->f_b-> ...
        curr = head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        ///partition it into two linktable
        RandomListNode dummy(-1);
        RandomListNode *h = &dummy;
        curr = head;
        while(curr){
            h->next = curr->next;
            curr->next = curr->next->next;
            h = h->next;
            curr = curr->next;
        }
        h->next = nullptr;
        return dummy.next;
    }


    ///======
    void help_reverseKGroup(ListNode *prev,ListNode *curr,int k){
        ListNode *p = prev->next;
        prev->next = curr->next;
        for(int i = 0;i<k;i++){
            ListNode *tmp = p->next;
            p->next = prev->next;
            prev->next = p;
            p = tmp;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1) return head;
        if(head==nullptr || head->next==nullptr)return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *curr,*prev;
        curr = head;
        prev = &dummy;

        while(curr){
            int i = 1;
            for(;i<k;i++){
                if(curr->next)  curr = curr->next;
                else break;
            }
            if(i!=k) break;
            //showList(dummy.next);cout<<"k1"<<endl;

            help_reverseKGroup(prev,curr,k);

            //showList(dummy.next);cout<<"k2"<<endl;
            for(i = 0;i<k;i++){
                prev = curr;
                curr = curr->next;
            }
            //showList(head);cout<<"k3"<<endl;
        }///while
        return dummy.next;
    }


    ///
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> re;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        for(;it1!=nums1.end() && it2!=nums2.end();){
            if(*it1<*it2) it1++;
            else if(*it1 > *it2) it2++;
            else{
                re.push_back(*it1);
                it1++;
                it2++;
            }
        }
        return re;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> re;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        int prev = INT_MAX;
        for(;it1!=nums1.end() && it2!=nums2.end();){
            if(*it1<*it2) it1++;
            else if(*it1 > *it2) it2++;
            else{
                if(prev == *it1){
                    it1++;
                    it2++;
                    continue;
                }
                prev = *it1;
                re.push_back(*it1);
                it1++;
                it2++;
            }
        }
        return re;
    }


    ///
    string longestCommonPrefix(vector<string>& strs) {
        string re;
        if(strs.empty()) return re;
        for(int i = 0;i<(int)strs[0].size();i++){
            for(int j = 0;j<(int)strs.size();j++){
                if(i>=(int)strs[j].size()) return re;
                if(strs[j][i]==strs[0][i])
                    continue;
                else
                    return re;
            }
            re.push_back(strs[0][i]);
        }
        return re;
    }


    void showStack(stack<char> &s){
        while(s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    ///
    bool isValid(string s) {
        stack<char> stac;
        if(s.empty()) return true;
        for(int i = 0;i<(int)s.size();i++){
            if(stac.empty()){
                stac.push(s[i]);
                continue;
            }

            if('['==stac.top() && ']'==s[i])
                stac.pop();
            else if('{'==stac.top() && '}'==s[i])
                stac.pop();
            else if('('==stac.top() && ')'==s[i])
                stac.pop();
            else
                stac.push(s[i]);
        }
        return stac.empty()? true:false;
    }

    int myAtoi(string str) {
        int num = 0;
        int sign = 1;
        const int n = str.length();
        int i = 0;
        while(i<n && str[i]==' ') i++;

        if(str[i] == '+'){
            i++;
        }else if(str[i]=='-'){
            sign = -1;
            i++;
        }
        for(;i<n;i++){
            if(!isdigit(str[i])) break;
            if(num > INT_MAX/10 ||
                (num==INT_MAX/10 && (str[i]-'0')>INT_MAX%10)){
                return sign==-1? INT_MIN:INT_MAX;
            }
            num = num*10+str[i]-'0';
        }
        return num*sign;
    }

    ///
    int calculate(string s){
        stack<char> op;
        stack<int> num;
        const int n = s.size();
        char ch;
        int tmp = 0;
        int a = 0;
        for(int i = 0;i<n;i++){
            ch = s[i];
            if(ch==' ') continue;
            else if(ch=='*' || ch=='/' || ch=='+' || ch=='-'){
                op.push(ch);
            }else if(isdigit(ch)){
                tmp = tmp*10+ch-'0';
                while(i<n && isdigit(ch=s[++i])){
                    tmp = tmp*10+ch-'0';
                }
                if(!op.empty()){
                    char curr_op = op.top();
                    if(curr_op == '*'){
                        int a = num.top();num.pop();op.pop();
                        num.push(a*tmp);
                    }else if(curr_op == '/'){
                        a = num.top();num.pop();op.pop();
                        num.push(a/tmp);
                    }else{
                        if(curr_op == '-') tmp *=-1;
                        num.push(tmp);
                    }
                }else{
                    num.push(tmp);
                }
                tmp = 0;
                if(i==n) break;
                i--;
            }
        }

        while(!op.empty()){
            int a = num.top();num.pop();
            int b = num.top();num.pop();
            //char ch = op.top();
            op.pop();
            num.push(a+b);
        }///while
        int re = num.top();num.pop();
        return re;
    }


    ///
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]!=t[i]) return false;
        }
        return true;
    }


    ///
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int curr = 1;
        return curr;
    }


    ///
    void help_reverse(string &s,int start,int end){
        while(start<end){
            swap(s[start++],s[end--]);
        }
    }
    string removeDuplicateSpace(string s){
        string res;
        int b = 0;
        for(;b<(int)s.size();b++){
            if(s[b]!= ' '){
                break;
            }
        }///
        int e = s.size() - 1;
        for(;e>=0;e--){
            if(s[e]!=' '){
                break;
            }
        }

        bool is_space = false;
        for(int i = b;i<=e;i++){
            if(s[i] == ' '){
                if(!is_space) is_space = true;
                else continue;
            }else{
                is_space = false;
            }
            res.push_back(s[i]);
        }
        return res;
    }
    void reverseWords(string &s) {
        if(s.empty()) return;
        s = removeDuplicateSpace(s);
        int start = 0;
        for(size_t i = 0;i<s.size();i++){
            if(s[i]!=' '){
                start = i;
            }else{
                continue;
            }
            size_t j = i;
            while(j<s.size() && s[j]!=' '){
                j++;
            }
            j--;
            help_reverse(s,start,j);
            i = j++;
        }
        help_reverse(s,0,(int)s.size()-1);
    }

    ///
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> re;
        if(strs.empty()) return re;
        unordered_map<string,int> m;
        int k = 0;
        for(size_t i = 0;i<strs.size();i++){
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            unordered_map<string,int>::iterator mit = m.find(tmp);
            if(mit == m.end()){
                vector<string> t;
                t.push_back(strs[i]);
                m[tmp] = k++;
                re.push_back(t);
            }else{
                re[m[tmp]].push_back(strs[i]);
            }
        }///for
        for(size_t i = 0;i<re.size();i++){
            sort(re[i].begin(),re[i].end());
        }

        for(auto i:re){
            for(auto j:i){
                cout<<j<<" ";
            }cout<<endl;
        }cout<<endl;
        return re;
    }


    ///
    void myslipt(string &s,vector<string> &re,string &c){
        std::string::size_type pos1,pos2;
        pos2 = s.find(c);///find
        pos1 = 0;
        while(std::string::npos != pos2){
            string t = s.substr(pos1,pos2-pos1);///[p1,p2)
            if(!t.empty()){
                re.push_back(t);
            }
            pos1 = pos2+c.size();
            pos2 = s.find(c,pos1);
        }
        if(pos1!=s.length()){
            re.push_back(s.substr(pos1));
        }
    }

    string simplifyPath(string path) {
        vector<string> re;
        string c = "/";
        myslipt(path,re,c);
        stack<string> st;
        for(size_t i = 0;i<re.size();i++){
            if(re[i]==".") continue;
            else if(re[i]==".."){
                if(st.empty()){
                    continue;
                }else{
                    st.pop();
                }///if-else
            }else{
                st.push(re[i]);
            }
        }
        string result;
        while(!st.empty()){
            result.insert(0,st.top());
            result.insert(0,"/");
            st.pop();
        }
        return result;
    }

    ///
    struct keyval{
        int key;
        int val;
        keyval(int k=0,int v=0):key(k),val(v){}
    };
    static bool mykeyval(const keyval &l,const keyval &r){
        return l.val>r.val;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;///key,multis
        vector<int> re;
        for(auto i: nums){
            m[i]++;
        }
        vector<keyval> tmp(m.size());
        int d = 0;
        for(auto i: m){
            tmp[d].key = i.first;
            tmp[d++].val = i.second;
        }
        for(auto i:m){
            cout<<i.first<<"--"<<i.second<<" ";
        }cout<<endl;
        for(auto i:tmp){
            cout<<i.key<<":"<<i.val<<" ";
        }cout<<endl;
        sort(tmp.begin(),tmp.end(),mykeyval);
        cout<<"===="<<endl;
        for(auto i:tmp){
            cout<<i.key<<":"<<i.val<<" ";
        }cout<<endl;
        for(int i = 0;i<k;i++){
            re.push_back(tmp[i].key);
        }
        return re;
    }



    void test(ListNode *head){
        cout<<"begin test...\n";
        ListNode n1(6),n2(2),n3(4),n4(3),n5(5),n6(1);
        n1.next = &n2;
        //n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        //n5.next = &n6;
        ListNode *head2 = &n1;
        showList(head2);cout<<endl;
        vector<int> re = {1,1,1,2,2,3,3,3,3,3};
        re = topKFrequent(re,2);
        for(auto i: re){
            cout<<i<<" ";
        }cout<<endl;

        cout<<"end test...\n";
    }
};
#endif // MYLISTNODE_H_INCLUDED

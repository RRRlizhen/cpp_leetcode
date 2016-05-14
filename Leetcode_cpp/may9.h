#ifndef MAY9_H_INCLUDED
#define MAY9_H_INCLUDED
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<math.h>
#include<limits.h>
#include<deque>
#include<stack>
#include<numeric>
#include<sstream>
using namespace std;

class MyMapTest{
public:
    void mm_find_range(){
        std::multimap<char,int> mymm;
        mymm.insert(pair<char,int>('a',10));
        mymm.insert(pair<char,int>('a',20));
        mymm.insert(pair<char,int>('b',30));
        mymm.insert(pair<char,int>('b',30));
        cout<<"mymm contains:\n";

        for(char ch ='a';ch<='c';ch++){
            pair<multimap<char,int>::iterator,multimap<char,int>::iterator> ret;
            ret = mymm.equal_range(ch);
            cout<<ch<<"->";
            for(multimap<char,int>::iterator it = ret.first;
                it!=ret.second;++it){
                    cout<<" "<<it->second;
                }
            cout<<endl;
        }
    }///

    void mm_find_key(){
        std::multimap<char,int> mymm;
        mymm.insert(pair<char,int>('a',10));
        mymm.insert(pair<char,int>('a',20));
        mymm.insert(pair<char,int>('b',301));
        mymm.insert(pair<char,int>('b',30));
        cout<<"find_key in multimap\n";
        for(char ch = 'a';ch<='c';ch++){
            multimap<char,int>::iterator mmit;
            mmit = mymm.find(ch);
            cout<<ch<<"->"<< mmit->second <<endl;
        }
    }

    void mm_find_lower_bound(){
        std::multimap<char,int> mymm;
        mymm.insert(pair<char,int>('a',10));
        mymm.insert(pair<char,int>('b',201));
        mymm.insert(pair<char,int>('b',202));
        mymm.insert(pair<char,int>('c',30));
        mymm.insert(pair<char,int>('c',301));
        mymm.insert(pair<char,int>('d',40));
        mymm.insert(pair<char,int>('e',50));
        mymm.insert(pair<char,int>('g',60));
        cout<<"find_lower_bound\n";
        multimap<char,int>::iterator lower_iter;
        multimap<char,int>::iterator upper_iter;
        lower_iter = mymm.lower_bound('b');
        upper_iter = mymm.upper_bound('e');cout<<"-----upper->"<<upper_iter->first<<" "<<upper_iter->second<<endl;
        while(lower_iter!=upper_iter){
            cout<<lower_iter->first<<"->"<<lower_iter->second<<endl;
            lower_iter++;
        }
    }

    ///
    void mm_insert(){
        std::multimap<char,int> mymultimap;
        std::multimap<char,int>::iterator it;

        // first insert function version (single parameter):
        mymultimap.insert ( std::pair<char,int>('a',100) );
        mymultimap.insert ( std::pair<char,int>('z',150) );
        it=mymultimap.insert ( std::pair<char,int>('b',75) );

        // second insert function version (with hint position):
        mymultimap.insert (it, std::pair<char,int>('c',300));  // max efficiency inserting
        mymultimap.insert (it, std::pair<char,int>('z',400));  // no max efficiency inserting

        // third insert function version (range insertion):
        std::multimap<char,int> anothermultimap;
        anothermultimap.insert(mymultimap.begin(),mymultimap.find('c'));

        // showing contents:
        std::cout << "mymultimap contains:\n";
        for (it=mymultimap.begin(); it!=mymultimap.end(); ++it)
        std::cout << (*it).first << " => " << (*it).second << '\n';

        std::cout << "anothermultimap contains:\n";
        for (it=anothermultimap.begin(); it!=anothermultimap.end(); ++it)
        std::cout << (*it).first << " => " << (*it).second << '\n';

        //return false;
    }

};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeLinkNode{
    int val;
    TreeLinkNode *right;
    TreeLinkNode *left;
    TreeLinkNode *next;

    TreeLinkNode (int val):val(val),right(nullptr),left(nullptr),next(nullptr){}
};

class Queue {
public:
    Queue(){}
    // Push element x to the back of queue.
    void push(int x) {
        while(!mystack1.empty()){
            mystack2.push(mystack1.top());
            mystack1.pop();
        }
        mystack1.push(x);
        while(!mystack2.empty()){
            mystack1.push(mystack2.top());
            mystack2.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!mystack1.empty()){
            mystack1.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if(!mystack1.empty()){
            return mystack1.top();
        }
        return 0;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return mystack1.empty();
    }

    stack<int> mystack1;
    stack<int> mystack2;
};

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        deq1.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        deq1.pop_back();
    }

    // Get the top element.
    int top() {
        return deq1.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return deq1.empty();
    }
    deque<int> deq1;
};


class May{
public:
    string reverseString(string s){
        if(s.empty()) return s;
        reverseStrSE(s,0,s.size()-1);
        return s;
    }
    void reverseStrSE(string& s,int start,int end){
        char tmp = s[start];
        while(start<end){
            s[start++] = s[end];
            s[end--] = tmp;
            tmp = s[start];
        }
        for(auto i:s){
            cout<<i;
        }cout<<endl;
    }

    ///Add Digits
    int addDigits(int num) {
        return 1+(num-1)%9;
    }

    void moveZeroes(vector<int>& nums){
        vector<int>::iterator p = find(nums.begin(),nums.end(),0);
        if(p==nums.end()){
            return;
        }
        vector<int>::iterator q = p;
        for(q++; q!=nums.end() ;){
            if(*q!=0){
                swap(*p,*q);
                while(*p!=0){
                    p++;///find the next 0
                }
            }
            q++;
        }///for
        for(auto i:nums){
            cout<<i<< " ";
        }cout<<endl;
    }///end-function

    ///contains duplicate
    bool containsDuplicate(vector<int>& nums) {
        set<int> sint;
        for(auto i:nums){
            if(sint.insert(i).second==false){
                return true;
            }
        }
        return false;
    }

    ///romanToInt
    //int romanToInt(string s) {}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ///TreeNode *ppp = new TreeNode(1);
        return root;
    }

    ///power of three
    bool isPowerOfThree(int n) {
        int ls = log(243)/log(3);
        cout<<"==="<<ls<<endl;
        int tmp = pow(3,ls);
        cout<<tmp<<endl;
        if( tmp% n == 0){
            return true;
        }
        return false;
    }

    void mylevelOrderBottom(TreeNode* root) {
        TreeNode* tmp = root;
        deque<TreeNode*> mydeque;
        if(root==nullptr){
            return;
        }
        int currSize = 1;
        int nextSize = 0;
        mydeque.push_back(root);
        while(!mydeque.empty()){
            while(currSize-->0){
                tmp = mydeque.front();
                cout<<tmp->val<<",";
                mydeque.pop_front();
                if(tmp->left){
                    mydeque.push_back(tmp->left);
                    nextSize++;
                }
                if(tmp->right){
                    mydeque.push_back(tmp->right);
                    nextSize++;
                }
            }cout<<endl;
            currSize = nextSize;
            nextSize = 0;
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> result;
            TreeNode *tmp = root;
            deque<TreeNode*> mydeque;
            if(root==nullptr) return result;

            mydeque.push_back(root);
            int currLineSize = 1;
            int nextLineSize = 0;
            while(!mydeque.empty()){
                vector<int> vit;
                while(currLineSize-->0){
                    tmp = mydeque.front();
                    vit.push_back(tmp->val);
                    mydeque.pop_front();
                    if(tmp->left) {
                        mydeque.push_back(tmp->left);
                        nextLineSize++;
                    }
                    if(tmp->right){
                        mydeque.push_back(tmp->right);
                        nextLineSize++;
                    }
                }
                result.push_back(vit);
                vit.clear();
                currLineSize = nextLineSize;
                nextLineSize = 0;
            }
            reverse(result.begin(),result.end());
            return result;
    }

    ///reverseVowels
    string reverseVowels(string s) {
        set<char> myset = {'a','e','i','o','u','A','E','I','O','U'};
        if(s.empty()) return s;
        int left = 0;
        int right = s.size()-1;

        while(left<right){
            while(left<(int)s.size() && left<right && find(myset.begin(),myset.end(),s[left])==myset.end()) {
                left++;
            }
            while(right>=0&& left<right &&find(myset.begin(),myset.end(),s[right])==myset.end()){
                right--;
            }
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }///


    ///swapPairs
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *p = head;
        ListNode *q = head->next;
        head = q;
        while(q){
            p->next = q->next;
            q->next = p;
            p = p->next;
            if(!p){
                break;
            }
            q = p->next;
            if(!q){
                break;
            }
        }///while
    }


    bool isPowerOfTwo(int n) {
        int ls = log(INT_MAX)/log(2);
        //cout<<"==="<<ls<<endl;
        int tmp = pow(2,ls);
        //cout<<tmp<<endl;
        if( n>0 && tmp% n == 0){
            return true;
        }
        return false;
    }

    ///
    bool isUgly(int n) {
        if(n==1) return true;
        if(n<=0)    return false;
        while(n%2==0) n/=2;
        while(n%3==0) n/=3;
        while(n%5==0) n/=5;
        return n==1?true:false;
    }


    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            if(m+n>(int)nums1.size()) return ;
            int k = m+n-1;
            int p = m-1;
            int q = n-1;
            while(p>=0 && q>=0){
                if(nums1[p]>=nums2[q]){
                    nums1[k--] = nums1[p--];
                }
                if(nums1[p]<nums2[q]){
                    nums1[k--] = nums2[q--];
                }
            }
            while(p>=0){
                return ;
            }
            while(q>=0){
                nums1[k--] = nums2[q--];
            }
    }

    ///
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    ///=====
    unordered_map<int,int> map;
    for(int i = 0;i<(int)nums.size();i++){
        if(map.count(nums[i]) && (i-map[nums[i]]<=k)) return true;
        map[nums[i]] = i;
    }
    return false;
    }

    ///
    vector<int> getRow(int rowIndex) {
        vector<int> ret = {1};
        vector<int> tmp = ret;
        int c = 1;
        while(c<=rowIndex){
            for(int i = 1;i<(int)tmp.size();i++){
                ret[i] = tmp[i]+tmp[i-1];
            }
            ret.push_back(1);
            c++;
            tmp = ret;
        }///while

        for(auto i:ret){
            cout<<i<<" ";
        }cout<<endl;
        return ret;
    }

    ///
    void help_binaryTree(TreeNode *root,vector<string> &ret,string str){
        if(root==nullptr) return;
        if(str.empty()){
            str += to_string(root->val);
        }else{
            str += "->";
            str += to_string(root->val);
        }
        if(root->left==nullptr && root->right==nullptr){
            ret.push_back(str);
            return;
        }
        help_binaryTree(root->left,ret,str);
        help_binaryTree(root->right,ret,str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> mys;
        vector<string> ret;
        string str;
        if(root==nullptr) return ret;
        help_binaryTree(root,ret,str);

        for(auto i: ret){
            cout<<i<<endl;
        }
        return ret;
    }

    ///
    bool isValidBST(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode *p = root;
        bool iSfirst = true;
        int tmp = 0;
        while(!s.empty()||p!=nullptr){
            if(p!=nullptr){
                s.push(p);
                p = p->left;
            }else{
                p = s.top();
                s.pop();
                //result.push_back(p->val);
                if(iSfirst){
                    tmp = p->val;
                    iSfirst = false;
                }else if(tmp>=p->val){
                    return false;
                }else{
                    tmp = p->val;
                }
                p = p->right;
            }
        }
        return true;
    }///


    ///
    void help_sumNumbers(TreeNode *root,int &ret,vector<int> store){
        if(root==nullptr) return;
        store.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){

            int length = store.size();
            int tmp = 0;
            for(int i = 0;i<length;i++){
                tmp += pow(10,length-i-1)*store[i];
            }
            //cout<<"tmp"<<tmp<<endl;
            ret += tmp;
        }
        help_sumNumbers(root->left,ret,store);
        help_sumNumbers(root->right,ret,store);
    }
    int sumNumbers(TreeNode* root) {
        int ret = 0;
        vector<int> store;
        if(root==nullptr) return 0;
        help_sumNumbers(root,ret,store);
        return ret;
    }


    ///
    void help_pathSum(TreeNode* root,vector<vector<int>> &ret,const int sum,vector<int> tmp){
        if(root==nullptr) return;
        tmp.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            int v = std::accumulate(tmp.begin(),tmp.end(),0);
            if(sum == v){
                ret.push_back(tmp);
                //cout<<sum<<endl;
            }
        }
        help_pathSum(root->left,ret,sum,tmp);
        help_pathSum(root->right,ret,sum,tmp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if(root==nullptr) return ret;
        vector<int> tmp;
        help_pathSum(root,ret,sum,tmp);
        return ret;
    }


    ///
    bool isHave = false;
    void help_hasPathSum(TreeNode* root,const int sum,vector<int> tmp){
        if(root==nullptr) return;
        tmp.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            int v = std::accumulate(tmp.begin(),tmp.end(),0);
            if(sum == v){
                isHave = true;
                //cout<<sum<<endl;
            }
        }
        help_hasPathSum(root->left,sum,tmp);
        help_hasPathSum(root->right,sum,tmp);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr) return false;
        vector<int> tmp;
        help_hasPathSum(root,sum,tmp);
        return isHave;
    }

    ///
    void connect_1(TreeLinkNode *root) {
        if(root==nullptr) return;
        TreeLinkNode dummay(-1);

        for(TreeLinkNode *curr = root, *pre = &dummay;
            curr;
            curr = curr->next){
            if(curr->left != nullptr){
                pre->next = curr->left;
                pre = pre->next;
            }
            if(curr->right != nullptr){
                pre->next = curr->right;
                pre = pre->next;
            }
        }
        connect(dummay.next);
    }

    ///
    void connect_2(TreeLinkNode *root){
        if(root==nullptr) return;
        while(root){
            TreeLinkNode *next = nullptr;/// the first ndoe of next level
            TreeLinkNode *pre = nullptr;///previous node on the same level
            for(;root;root = root->next){
                if(next==nullptr) next = root->left? root->left: root->right;

                if(root->left){
                    if(pre) pre->next = root->left;
                    pre = root->left;
                }

                if(root->right){
                    if(pre) pre->next = root->right;
                    pre = root->right;
                }
            }///for
            root = next;
        }
    }///connect-end

    void connect(TreeLinkNode *root){
        while(root){
            TreeLinkNode *next = nullptr;///the start node of the next level
            TreeLinkNode *prev = nullptr;/// the previous node of the same level
            for(;root;root = root->next){
                if(next==nullptr) next = root->left? root->left:root->right;

                if(root->left){
                    if(prev) prev->next = root->left;
                    prev = root->left;
                }

                if(root->right){
                    if(prev) prev->next = root->right;
                    prev = root->right;
                }
            }///for
            root = next;
        }///while
    }


    ///build the tree from the inorder and prevOrder trans
    ///
    template<typename InputIterator>
    TreeNode* buildTree(InputIterator pre_first,InputIterator pre_last,InputIterator in_first,InputIterator in_last){
        if(pre_first == pre_last) return nullptr;
        if(in_first == in_last) return nullptr;
        auto root = new TreeNode(*pre_first);

        auto inRootPos = find(in_first,in_last,*pre_first);
        auto leftSize = distance(in_first,inRootPos);

        root->left = buildTree(next(pre_first),next(pre_first,leftSize+1),in_first,next(in_first,leftSize));
        root->right = buildTree(next(pre_first,leftSize+1),pre_last,next(inRootPos),in_last);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }


    ///Unique binary search trees;
    int numTree(int n){
            ///f[n] = E0..n{  f[i]*f[n-i]   };
        vector<int> f(n+1,0);
        f[0] = 1;
        f[1] = 1;
        for(int i = 2;i<=n;i++){
            for(int j = 0;j<i;j++){
               f[i] += f[j]*f[i-j-1];
               cout<<"f["<<i<<"]= "<<f[i]<<endl;
            }
        }///for
        return f[n];
    }

    ///
    int myAtoi(string str){
        if(str=="") return 0;
        int re = 0;
        int len = str.size();
        char *p = const_cast<char*> (str.c_str());
        bool isNegative = false;
        int k = str.find_first_not_of(' ');
        if(p[k]=='-'){
            isNegative = true;
            k++;
        }else if(p[k]=='+'){
            k++;
        }
        for(int i = k;i<len;i++){
            if(isdigit(p[i])){
                re = re*10+p[i]-'0';
            }
        }
        return isNegative? 0-re:re;
    }
};





#endif // MAY9_H_INCLUDED

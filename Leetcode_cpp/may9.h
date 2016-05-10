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

    helpBuildTreePreIn(vector<int>::iterator &sPre,vector<int>::iterator &ePre,
                        vector<int>::iterator &sIn,vector<int>::iterator &eIn)
    {
        int rootVale = *sPre;
        TreeNode *root = new TreeNode();
        root->val = rootVale;
        root->left = root->right = nullptr;

        if(sPre==ePre){
            if(sIn==eIn && *sPre==*sIn){
                return root;
            }
        }///if

        int
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder == nullptr || inorder==nullptr || preorder.size()!=inorder.size()) return nullptr;
        return helpBuildTreePreIn(preorder.begin(),preorder.empty()--,inorder.begin(),inorder.end()--);
    }///

};





#endif // MAY9_H_INCLUDED

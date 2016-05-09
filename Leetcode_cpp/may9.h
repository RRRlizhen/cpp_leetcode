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

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
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
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return mystack1.empty();
    }

    stack<int> mystack1;
    stack<int> mystack2;
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
};



#endif // MAY9_H_INCLUDED

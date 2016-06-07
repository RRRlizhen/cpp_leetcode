#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
/**********************************************
*Project:
*
*Author:lizhen
*email:lizhen_ok@aliyun.com
*
***********************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <climits>
#include <algorithm>
#include <bitset>
#include <queue>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};


class A{
public:

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

    int countPrimes(int n) {
        bitset<10000000> b;
        for(int i = 0;i<n;i++){
            b.set(i,1);
        }
        int re = 0;
        for(int i = 2;i*i<n;i++){
            if(b[i]){
                for(int k = i;k<(n+1);k = k+i){
                    if(k==i)continue;
                    b.set(k,0);
                }
            }///
        }///for

        for(int i = 2;i<n;i++){
            if(b[i]){
                re++;
            }
        }
        return re;
    }


    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0;
        int minlen = INT_MAX;
        int tsum = 0;
        for(int i = 0;i<(int)nums.size();i++){
            tsum +=nums[i];
            while(tsum >= s){
                minlen = min(minlen,i-start+1);
                tsum = tsum - nums[start++];
            }
        }
        return minlen==INT_MAX? 0: minlen;
    }


    ///
    int findDuplicate(vector<int>& nums) {
        if(nums.size()>1){
            int fast = nums[nums[0]];
            int slow = nums[0];
            while(slow!=fast){
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while(fast != slow){
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }

    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int curr,begin,end;
        curr = begin = 0;
        end = n-1;
        while(curr<=end){
            if(nums[curr]==0){
                swap(nums[begin++],nums[curr++]);
            }else if(nums[curr]==1){
                curr++;
            }else if(nums[curr]==2){
                swap(nums[end],nums[curr]);
                end--;
            }
        }
    }

    ///how to build a tree
    TreeNode *buildTree(TreeNode *p,vector<int> nums,int &i){
        if(i>=(int)nums.size()) return nullptr;
        if(nums[i]<0){
            i++;
            p = nullptr;
            cout<<nums[i]<<endl;
        }else{
            p = new TreeNode(nums[i]);cout<<nums[i]<<"+"<<endl;

            i++;
            p->left = buildTree(p->left,nums,i);
            p->right = buildTree(p->right,nums,i);
        }
        return p;
    }
    TreeNode* buildTree(vector<int> &nums){
        TreeNode *root = nullptr;
        int start = 0;
        root = buildTree(root,nums,start);
        return root;
    }


    ///
    int help_maxPathSum(int &max_sum,TreeNode *root){
        if(root==nullptr) return 0;
        int l = help_maxPathSum(max_sum,root->left);
        int r = help_maxPathSum(max_sum,root->right);
        int sum = root->val;
        if(l>0) sum += l;
        if(r>0) sum += r;
        max_sum = max(max_sum,sum);
        return max(r,l)>0? max(r,l)+root->val:root->val;
    }
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        help_maxPathSum(max_sum,root);
        return max_sum;
    }


    ///
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return NULL;
        if(root==p || root==q) return root;
        TreeNode *left_lca = lowestCommonAncestor(root->left,p,q);
        TreeNode *right_lca = lowestCommonAncestor(root->right,p,q);
        if(left_lca&&right_lca) return root;

        return left_lca==nullptr? right_lca:left_lca;
    }


    ///
    vector<TreeNode*> generateTrees(int n){
        if(n==0) return generateTrees(1,0);
        return generateTrees(1,n);
    }

    vector<TreeNode*> generateTrees(int start,int end){
        vector<TreeNode*> subTree;
        if(start>end){
            subTree.push_back(nullptr);
            return subTree;
        }

        for(int k = start;k<=end;k++){
            vector<TreeNode*> leftSubs = generateTrees(start,k-1);
            vector<TreeNode*> rightSubs = generateTrees(k+1,end);
            for(auto i:leftSubs){
                for(auto j:rightSubs){
                    TreeNode *node = new TreeNode(k);
                    node->left = i;
                    node->right = j;
                    subTree.push_back(node);
                }
            }
        }
        return subTree;
    }


    ///inorderMorrisTraversal
    void inorderMorrisTraversal(TreeNode *root){
        TreeNode *curr = root;
        TreeNode *prev = nullptr;
        while(curr!=nullptr){
            if(curr->left == nullptr){
                cout<<curr->val<<" ";
                curr = curr->right;
            }else{
                ///search predecessor
                prev = curr->left;
                while(prev->right !=nullptr && prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right==nullptr){
                    prev->right = curr;
                    curr = curr->left;
                }else{
                    prev->right = nullptr;///recover the tree
                    cout<<curr->val<<" ";
                    curr = curr->right;
                }
            }///if-else
        }///while
    }


    ///
    void recoverTree(TreeNode *root){
        pair<TreeNode *,TreeNode *> broken;
        TreeNode *curr = root;
        TreeNode *prev = nullptr;
        broken.first = broken.second = nullptr;

        while(curr!=nullptr){
            if(curr->left==nullptr){
                detect(broken,prev,curr);
                prev = curr;
                curr = curr->right;
            }else{
                auto node = curr->left;
                ///prev = curr->left;
                while(node->right != nullptr && node->right!=curr){
                    node = node->right;
                }

                ///find predecessor
                if(node->right==nullptr){
                    node->right = curr;
                    curr = curr->left;
                }else{
                    node->right = nullptr;
                    detect(broken,prev,curr);
                    prev = curr;
                    curr = curr->right;
                }
            }///if-else
        }///while

        swap(broken.first->val,broken.second->val);
    }
    void detect(pair<TreeNode *,TreeNode *> &broken,TreeNode *prev,
        TreeNode *curr){
        if(prev!=nullptr && prev->val > curr->val){
            if(broken.first == nullptr) broken.first = prev;
            broken.second = curr;
        }
    }


    ///
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> re;
        vector<int> path;
        if(root==nullptr) return re;
        help_zig(root,re,path);

        for(auto i:re){
            for(auto j:i){
                cout<<j<<" ";
            }cout<<endl;
        }cout<<endl;
        return re;
    }
    void help_zig(TreeNode *root,vector<vector<int>> &re,vector<int> &path){
        queue<TreeNode*> q;
        int curr = 1;
        int next = 0;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            if(curr>0){
                TreeNode *tmp = q.front();
                path.push_back(tmp->val);
                q.pop();
                curr--;
                if(tmp->left!=nullptr){
                    q.push(tmp->left);
                    next++;
                }
                if(tmp->right!=nullptr){
                    q.push(tmp->right);
                    next++;
                }
            }else{
                curr = next;
                next = 0;
                if(level%2!=0){
                    reverse(path.begin(),path.end());
                }
                re.push_back(path);
                path.clear();
                level++;
            }
        }///while
        if(level%2!=0) reverse(path.begin(),path.end());
        re.push_back(path);
    }


    ///
    TreeNode* _sortedArrayToBST(vector<int>& nums){
        if(nums.empty()) return nullptr;
        TreeNode *root;
        TreeNode *prev,*p;
        root = nullptr;
        for(int i = 0;i<(int)nums.size();i++){
            p = root;
            prev = nullptr;
            int v = nums[i];
            while(p!=nullptr){
                prev = p;
                if(v < p->val)
                    p = p->left;
                else
                    p = p->right;
            }

            if(root==nullptr){
                root = new TreeNode(v);
            }else if(v < prev->val){
                prev->left = new TreeNode(v);
            }else if(v > prev->val){
                prev->right = new TreeNode(v);
            }
        }///for
        return root;
    }

    ///
    TreeNode* sortedArrayToBST(vector<int> &nums){
        if(nums.empty()) return nullptr;
        TreeNode *root = help_saTobst(nums,0,nums.size()-1);
        return root;
    }
    TreeNode* help_saTobst(vector<int> &nums,int s,int end){
        if(s>end) return nullptr;
        int mid = (s+end)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = help_saTobst(nums,s,mid-1);
        root->right = help_saTobst(nums,mid+1,end);
        return root;
    }

    ///
    void preMorris(TreeNode* root){
        TreeNode *curr = root;
        TreeNode *prev = nullptr;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                cout<<curr->val<<" ";
                curr = curr->right;
            }else{
                prev = curr->left;
                while(prev->right!=nullptr && prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right==nullptr){
                    prev->right = curr;
                    cout<<curr->val<<" ";
                    curr = curr->left;
                }else{
                    prev->right = curr;
                    curr = curr->right;
                }
            }
        }///while
    }

    void flatten(TreeNode *root){
        if(root==nullptr) return;

        flatten(root->left);
        flatten(root->right);
        if(root->left == nullptr) return;

        TreeNode *p = root->left;
        while(p->right) p = p->right;
        p->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }



    ///
    vector<int> rightSideView(TreeNode* root) {
        vector<int> re;
        if(root==nullptr) return re;
        help_rightSv(root,re);

        for(auto i:re){
            cout<<i<<" ";
        }cout<<endl;
        return re;
    }

    void help_rightSv(TreeNode *root,vector<int> &path){
        queue<TreeNode*> q;
        int curr = 1;
        int next = 0;
        int level = 0;
        q.push(root);
        while(!q.empty()){
            if(curr>0){
                TreeNode *tmp = q.front();
                if(path.size()==level) {
                    path.push_back(tmp->val);
                }
                q.pop();
                curr--;
                if(tmp->right!=nullptr){
                    q.push(tmp->right);
                    next++;
                }
                if(tmp->left!=nullptr){
                    q.push(tmp->left);
                    next++;
                }
            }else{
                curr = next;
                next = 0;
                level++;
            }
        }///while
    }


    ///
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int sum = 0;
        int lh = tree_lh(root->left);
        int rh = tree_rh(root->right);

        if(lh==rh){
            sum += pow(2,lh)-1;
            sum += countNodes(root->right)+1;
        }else if(lh == (rh+1)){
            sum += pow(2,rh)-1;
            sum += countNodes(root->left)+1;
        }
        return sum;
    }

    int tree_rh(TreeNode* root){
        int h = 0;
        while(root!=nullptr){
            h++;
            root = root->right;
        }
        return h;
    }

    int tree_lh(TreeNode* root){
        int h = 0;
        while(root!=nullptr){
            h++;
            root = root->left;
        }
        return h;
    }


    ///help_buildTree_pi()
    template<typename Iteratorr>
    TreeNode *help_buildTree_pi(Iteratorr pre_first,Iteratorr pre_last,
        Iteratorr in_first,Iteratorr in_last){
        if(pre_first == pre_last) return nullptr;
        if(in_first == in_last) return nullptr;

        auto root = new TreeNode(*pre_first);
        auto inRootPos = find(in_first,in_last,*pre_first);
        auto leftSize = distance(in_first,inRootPos);

        root->left = help_buildTree_pi(next(pre_first),next(pre_first,leftSize+1),
                                        in_first,next(in_first,leftSize));
        root->right = help_buildTree_pi(next(pre_first,leftSize+1),pre_last,next(inRootPos),in_last);
        return root;
    }
    TreeNode* buildTree_pi(vector<int> &preorder,vector<int> &inorder){
        return help_buildTree_pi(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }



    ///
    template<typename Iterator>
    TreeNode *help_buildTree_ip(Iterator in_first,Iterator in_last,
        Iterator post_first,Iterator post_last){
        if(in_first == in_last) return nullptr;
        if(post_first == post_last) return nullptr;

        auto val = *prev(post_last);
        TreeNode *root = new TreeNode(val);

        auto in_root_pos = find(in_first,in_last,val);
        auto left_size = distance(in_first,in_root_pos);
        auto post_left_last = next(post_first,left_size);

        root->left = help_buildTree_ip(in_first,in_root_pos,post_first,post_left_last);
        root->right = help_buildTree_ip(next(in_root_pos),in_last,post_left_last,prev(post_last));

        return root;
    }
    TreeNode* buildTree_ip(vector<int> &inorder,vector<int> &postorder){
        return help_buildTree_ip(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }

    void test(){
        cout<<"begining"<<endl;
        TreeNode *root;
            TreeNode n1(1);TreeNode n2(2);TreeNode n3(3);TreeNode n4(4);TreeNode n5(5);
            TreeNode n6(6);TreeNode n7(7);TreeNode n8(8);TreeNode n9(9);TreeNode n10(10);
            TreeNode n11(11);

	n1.left = &n2;	n1.right = &n3;
	n2.left = &n4; 	n2.right = &n5; n3.left = &n6; n3.right = &n7;
	n4.left = &n8; n4.right = &n9;n6.left = &n10; n7.right = &n11;
	root = &n1;
        cout<<"working\n"<<endl;
        vector<int> c = {1,2,3};
        root = buildTree(c);

        int re = countNodes(root);
        cout<<"re;"<<re<<endl;
        cout<<"end"<<endl;
    }
};


#endif // HASHTABLE_H_INCLUDED

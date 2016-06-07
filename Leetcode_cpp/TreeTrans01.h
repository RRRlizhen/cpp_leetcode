/*
 * TreeTrans01.h
 *
 *  Created on: Apr 22, 2016
 *      Author: lizhen
 */

#ifndef TREETRANS01_H_
#define TREETRANS01_H_
#include <vector>
#include "treeNode.h"
#include <stack>
using namespace std;
class Trans01 {
public:
	// recursion 遍历
	//recursion 前序遍历
	vector<int> recursionPreT(TreeNode *root) {
		vector<int> result;
		recursionPreT(root, result);
		return result;
	}
	void recursionPreT(TreeNode *root, vector<int> &result) {
		if (root == nullptr)
			return;
		if (root != nullptr)
			result.push_back(root->val);
		if (root->left != nullptr)
			recursionPreT(root->left, result);
		if (root->right != nullptr)
			recursionPreT(root->right, result);
	}

	//recursion 中序遍历
	vector<int> recursionInorT(TreeNode *root) {
		vector<int> result;
		recursionInorT(root, result);
		return result;
	}
	void recursionInorT(TreeNode *root, vector<int> &result) {
		if (root == nullptr)
			return;
		if (root->left != nullptr)
			recursionInorT(root->left, result);
		if (root != nullptr)
			result.push_back(root->val);
		if (root->right != nullptr)
			recursionInorT(root->right, result);
	}

	// recursion 后序遍历
	vector<int> recursionPostT(TreeNode *root) {
		vector<int> result;
		recursionPostT(root, result);
		return result;
	}
	void recursionPostT(TreeNode *root, vector<int> &result) {
		if (root == nullptr)
			return;
		if (root->left != nullptr)
			recursionPostT(root->left, result);
		if (root->right != nullptr)
			recursionPostT(root->right, result);
		if (root != nullptr)
			result.push_back(root->val);
	}

	//非递归 利用栈
	//前序遍历 非递归 利用栈
	vector<int> stackPreT(TreeNode *root) {
		vector<int> result;
		stack<const TreeNode *> s;
		if (root != nullptr)
			s.push(root);
		while (!s.empty()) {
			const TreeNode *p = s.top();
			s.pop();
			result.push_back(p->val);
			if (p->right != nullptr)
				s.push(p->right);	//栈是后进先出的顺序，所以left后进，left先访问
			if (p->left != nullptr)
				s.push(p->left);
		}
		return result;
	}
	//中序遍历 非递归 利用栈
	vector<int> stackInorT(TreeNode *root) {
		vector<int> result;
		stack<const TreeNode *> s;
		const TreeNode *p = root;
		while (!s.empty() || p != nullptr) {
			if (p != nullptr) {
				s.push(p);
				p = p->left;
			} else {
				p = s.top();
				s.pop();
				result.push_back(p->val);
				p = p->right;
			}
		}
		return result;
	}

	//后序遍历 非递归 利用栈
	vector<int> stackPostT(TreeNode *root) {
		vector<int> result;
		stack<const TreeNode *> s;
		const TreeNode *p, *q;
		p = root;
		q = nullptr;

		//算法：
		//首先要认识到这是LRN，左节点-右节点-根节点的顺序
		//1,找到一个节点左子树，向左下方滑行，直到找到左下方的叶子节点，中间经过的每一个节点都要入s栈
		//当栈不为空的时候，出栈p=s.top,pop;
		//   如果p的右节点不存在或者右节点已经呗访问了，我们就访问当前节点;然后q=p来标记刚刚访问了p节点;
		//	 如果p有右节点&&没有被访问，需要将当前节点p再次入栈s.push(p)，处理p的右节点p=p->right;

		//实现
		//首先找到p的左下方叶子节点
		do {
			while (p != nullptr) {
				s.push(p);
				p = p->left;
			}
			q = nullptr;
			while (!s.empty()) {
				p = s.top();
				s.pop();

				//判断p节点的右孩子存在？被访问了码？
				//这是两个判断，先判断p->right==nullptr,再判断p->right是否已经被访问了
				//可以利用一个表达式来完成这一判断
				if (p->right == q) {				//p没有右孩子， || p的右孩子被访问了 两种情况
					result.push_back(p->val);
					q = p;
				} else {
					//p的右孩子没有被访问，p需要再次进栈，后面还会有出栈的动作
					s.push(p);
					p = p->right;
					break;						//------------------再一次找到p的右孩子
				}
			}						//while
		} while (!s.empty());
		return result;
	}

	//mirros 非递归
	//前序遍历 mirros 非递归
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
	//中序遍历 mirros 非递归
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

    //后序遍历 mirros 非递归
};

#endif /* TREETRANS01_H_ */
/*
 * int main(){
	TreeNode *root;
	TreeNode n1(1);TreeNode n2(2);TreeNode n3(3);TreeNode n4(4);TreeNode n5(5);
	TreeNode n6(6);TreeNode n7(7);TreeNode n8(8);TreeNode n9(9);TreeNode n10(10);
	TreeNode n11(11);

	n1.left = &n2;	n1.right = &n3;
	n2.left = &n4; 	n2.right = &n5; n3.left = &n6; n3.right = &n7;
	n4.left = &n8; n4.right = &n9;n6.left = &n10; n7.right = &n11;
	root = &n1;
	Trans01 s;
	vector<int> previt;

	previt = s.recursionPreT(root);
	for(auto i:previt){
		cout<< i<<" ";
	}cout<<"\t"<<"recursionPreT"<<endl;
	//========================
	vector<int> invit;
	invit = s.recursionInorT(root);
	for(auto i:invit){
		cout<<i<<" ";
	}cout<<"\t"<<"recursionInorT"<<endl;
	//========================
	vector<int> postvit;
	postvit = s.recursionPostT(root);
	for(auto i:postvit){
		cout<<i<<" ";
	}cout<<"\t"<<"recursionPostT"<<endl;

	//#####
	vector<int> stackPrevit;
	stackPrevit = s.stackPreT(root);
	for(auto i: stackPrevit){
		cout<<i<<" ";
	}cout<<"\t"<<"stackPreT"<<endl;
	//######
	vector<int> stackInorvit;
	stackInorvit = s.stackInorT(root);
	for(auto i:stackInorvit){
		cout<<i<<" ";
	}cout<<"\t"<<"stackInorT"<<endl;
	//######
	vector<int> stackPostvit;
	stackPostvit = s.stackPostT(root);
	for(auto i:stackPostvit){
		cout<<i<<" ";
	}cout<<"\t"<<"stackPostT"<<endl;
	return 0;
}
 * */

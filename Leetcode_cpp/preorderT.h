/*
 * preorderT.h
 *
 *  Created on: Apr 18, 2016
 *      Author: lizhen
 */

#ifndef PREORDERT_H_
#define PREORDERT_H_
#include <vector>
#include <stack>
#include "treeNode.h"
using namespace std;
class Solution{
public:
	vector<int> preorderTraveral(TreeNode *root){
		vector<int> result;
		stack<const TreeNode*> s;
		const TreeNode *p = root;
		if(root!=nullptr) s.push(root);
		while(!s.empty()){
			p = s.top();
			s.pop();
			result.push_back(p->val);
			if(p->right) s.push(p->right);
			if(p->left) s.push(p->left);
		}//while
		return result;
	}

	vector<int> inorderTraveral(TreeNode *root){
		vector<int> result;
		stack<const TreeNode*> s;
		const TreeNode *p = root;
		while(!s.empty()|| p!=nullptr){
			/*LNR中序遍历，在左子树node.left都被访问了，才能访问根节点node.val，然后将node.right入栈
			 * */
			if(p!=nullptr){
				s.push(p);
				p = p->left;
			}else{
				p = s.top();
				result.push_back(p->val);
				s.pop();
				p = p->right;
			}
		}//while
		return result;
	}//


	vector<int> postorderTraversal(TreeNode *root){
		vector<int> result;
		stack<const TreeNode*> s;
		const TreeNode *p;//curr
		const TreeNode *q;//pre
		p = root;
		do{
			while(p!= nullptr){//往左下方向走
				s.push(p);
				p = p->left;
			}
			q = nullptr;
			while(!s.empty()){
				p = s.top();
				s.pop();
				//右孩子不存在或已被访问，访问之
				if(p->right==q){
					result.push_back(p->val);
					q = p;//保存刚刚访问的节点
				}else{
					//当前节点不能访问，需要二次进栈
					s.push(p);
					//先处理右子树
					p = p->right;
					break;
				}//if-else
			}//while
		}while(!s.empty());
		return result;
	}

};

#endif /* PREORDERT_H_ */

/*
 * int main(){
	TreeNode *root;
	TreeNode n1(1);TreeNode n2(2);TreeNode n3(3);TreeNode n4(4);TreeNode n5(5);
	TreeNode n6(6);TreeNode n7(7);TreeNode n8(8);TreeNode n9(9);TreeNode n10(10);
	TreeNode n11(11);TreeNode n12(12);

	n1.left = &n2;	n1.right = &n3;
	n2.left = &n4; 	n2.right = &n5; n3.left = &n6; n3.right = &n7;
	n4.left = &n8; n4.right = &n9;n6.left = &n10; n7.right = &n11;
	root = &n1;
	Solution s;
	vector<int> previt;

	previt = s.preorderTraveral(root);
	for(auto i:previt){
		cout<< i<<" ";
	}cout<<endl;

	vector<int> invit;
	invit = s.inorderTraveral(root);
	for(auto i:invit){
		cout<< i<<" ";
	}cout<<endl;

	vector<int> postvit;
	postvit = s.postorderTraversal(root);
	for(auto i:postvit){
		cout<<i<<" ";
	}cout<<endl;
	return 0;
}
 * */

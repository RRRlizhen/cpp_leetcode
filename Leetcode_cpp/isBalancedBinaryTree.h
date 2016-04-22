/*
 * isBalancedBinaryTree.h
 *
 *  Created on: Apr 22, 2016
 *      Author: lizhen
 */

#ifndef ISBALANCEDBINARYTREE_H_
#define ISBALANCEDBINARYTREE_H_
#include<vector>
#include "treeNode.h"
using namespace std;
class Solution{
	//分析：
	//平衡二叉树，左右子树的高度差<=1
	//我们写一个求二叉树的高度的函数BHight，BHight能返回>=0的数，说明平衡
	//如果返回的是负数，就不是二叉树（这中间有一个剪枝判断的过程）
public:
	bool isBalanced(TreeNode *root){
		return balanceHeight(root) >=0;
	}

	int balanceHeight(TreeNode *root){
		if(root==nullptr) return 0;

		int left = balanceHeight(root->left);
		int right = balanceHeight(root->right);

		if(left<0 || right <0 || abs(left-right)>0) return -1;

		return max(left,right)+1;
	}
};
#endif /* ISBALANCEDBINARYTREE_H_ */

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

	return 0;
}
 * */

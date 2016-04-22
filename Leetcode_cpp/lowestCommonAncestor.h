/*
 * lowestCommonAncestor.h
 *
 *  Created on: Apr 18, 2016
 *      Author: lizhen
 */

#ifndef LOWESTCOMMONANCESTOR_H_
#define LOWESTCOMMONANCESTOR_H_
#include "treeNode.h"
using namespace std;

class Solution{
	/*当树为二叉查找树时：
	 * 从根root开始：
	 * 1,如果当前节点curr大于节点u，v，说明u，v都在curr的左侧，所以他们的共同祖先一定
	 * 		在curr的左子树上，所以从curr的左左子树中继续查找;
	 * 2,如果curr小于u，v，说明u，v都在curr的右侧，所以他们的共同祖先必定在右子树中，
	 * 		所以从curr.right中继续查找
	 * 3,如果curr满足， u.value<curr.value<v.value，说明u，v在curr的两侧，那么curr
	 * 		就是u，v的最近祖先
	 * 4,如果u是v的祖先，那么返回u的父节点;如果v是u的祖先，那么返回v的父节点
	 * */
public:
	TreeNode& lca(TreeNode *root,int va,int vb,
			TreeNode *&result,TreeNode *&parent){
		bool left = false;
		bool right = false;
		if(!result && root->left) left = lca(root->left,va,vb,result,root);
		if(!result && root->right) right = lca(root->right,va,vb,result,root);

		//mid,curr
		bool mid = false;
		if(root->val == va || root->val ==vb) mid = true;
		if(!result && int (left+right+mid)==2){
			if(mid)
				result = parent;
			else
				result = root;
		}
		return left | mid| right;
	}

};





#endif /* LOWESTCOMMONANCESTOR_H_ */

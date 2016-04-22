/*
 * treeNode.h
 *
 *  Created on: Apr 18, 2016
 *      Author: lizhen
 */

#ifndef TREENODE_H_
#define TREENODE_H_
class TreeNode{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x):val(x),left(nullptr),right(nullptr){}
};




#endif /* TREENODE_H_ */

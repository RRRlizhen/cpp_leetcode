/*
 * listnode.h
 *
 *  Created on: Apr 9, 2016
 *      Author: lizhen
 */

#ifndef LISTNODE_H_
#define LISTNODE_H_
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(0) {}
};




#endif /* LISTNODE_H_ */

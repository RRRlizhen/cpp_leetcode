/*
 * remoelistd2.h
 *
 *  Created on: Apr 9, 2016
 *      Author: lizhen
 */

#ifndef REMOELISTD2_H_
#define REMOELISTD2_H_
#include "listnode.h"
//main在后面

/*
 * struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(0) {}
};*/
class Solution {
public:


    ListNode* deleteDuplicates(ListNode* head) {
            if(head==nullptr){
                return nullptr;
            }
            if(head->next!=nullptr && head->next->val == head->val){
                while(head->next!=nullptr && head->next->val == head->val){
                    head = head->next;
                }
                return deleteDuplicates(head->next);
            }else{
                head->next = deleteDuplicates(head->next);
            }

            return head;
        }
};

/*
 *
 * ListNode* deleteDuplicates(ListNode* head) {
    	ListNode *curr,*pre_curr;
    	pre_curr = head;
    	if(pre_curr==nullptr){
    		return nullptr;
    	}
    	curr = pre_curr->next;
    	if(curr == nullptr){
    		return head;
    	}

    	if(pre_curr->val == curr->val && curr!=nullptr){
    		while(pre_curr->val == curr->val && curr!= nullptr){
    			pre_curr = curr;
    			curr = curr->next;
    		}
    		return deleteDuplicates(curr);
    	}else{
    		head->next = deleteDuplicates(curr);
    	}
    	return head;
    }
 * */




#endif /* REMOELISTD2_H_ */

/*
 * int main(){
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	ListNode l4(3);
	ListNode l5(4);
	ListNode l6(4);
	ListNode l7(5);
	ListNode *head;
	head = &l1;
	head->next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = nullptr;
	Solution s;
	ListNode *result;
	result = s.deleteDuplicates(head);
	while(result!=nullptr){
		cout<<result->val<<" ";
		result = result->next;
	}cout<<endl;
	return 0;
}
 * */

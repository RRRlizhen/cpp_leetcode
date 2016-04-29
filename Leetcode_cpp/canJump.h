/*
 * canJump.h
 *
 *  Created on: Apr 29, 2016
 *      Author: lizhen
 */

#ifndef CANJUMP_H_
#define CANJUMP_H_
#include <vector>
using namespace std;
class Solution {
	//本题正向贪心
public:
    bool canJump(vector<int>& nums) {
    	int maxLocation;//当前可能到达的最大位置(下标)
    	maxLocation = nums[0];
    	int length = nums.size();
    	for(int i = 0;i<length && maxLocation>=i;i++){
    		maxLocation = max(maxLocation,i+nums[i]);
    	}
    	return maxLocation >= (length-1);
    }
};




#endif /* CANJUMP_H_ */

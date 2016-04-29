/*
 * canJump2.h
 *
 *  Created on: Apr 29, 2016
 *      Author: lizhen
 */

#ifndef CANJUMP2_H_
#define CANJUMP2_H_
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
	//分析，给一个非负数组，判断最大几跳能到打数组的最后一个位置
public:
    int jump(vector<int>& nums) {
    	int step = 0;
    	int left = 0;
    	int right = 0;

    	int length = nums.size();

    	if(length==1) return 0;
    	while(left<=right){
    		step++;
    		const int old_right = right;
    		int maxNext = right;
    		for(int i=left;i<=old_right;i++){
    			if(nums[maxNext]+maxNext >= length-1){
    				return step;
    			}
    			if(nums[maxNext]+maxNext < nums[i]+i){
    				maxNext = i;
    			}
    		}
    		right = nums[maxNext]+maxNext;//[left,right]表示的范围，right每次取值是下一步能到达的位置，这个值不是maxNext，
    							//因为maxNext表示的是在当前范围中，的一个下标;思路要清楚
    		left  = old_right+1;
    	}//while

    	return 0;
    }
};


#endif /* CANJUMP2_H_ */

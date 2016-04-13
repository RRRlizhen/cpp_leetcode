/*
 * removed2.h
 *
 *  Created on: Apr 9, 2016
 *      Author: lizhen
 */

#ifndef REMOVED2_H_
#define REMOVED2_H_
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int index = 1;
    	for(unsigned int i = 1;i<nums.size();i++){
    		if(nums[i]!=nums[index-1])
    			nums[index++] = nums[i];
    	}
    	return index;
    }
};
class SolutionN{
public:
	int removeDuplicates(vector<int>& nums,unsigned int n){
		if(n>=nums.size()){
			return nums.size();
		}
		int index = n;
		for(unsigned int i = n;i<nums.size();i++){
			if(nums[i]!=nums[index-n]){
				nums[index++] = nums[i];
			}
		}
		return index;
	}
};



#endif /* REMOVED2_H_ */

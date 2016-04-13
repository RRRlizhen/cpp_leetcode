/*
 * findMiniRotatedSortedArray.h
 *
 *  Created on: Apr 10, 2016
 *      Author: lizhen
 */

#ifndef FINDMINIROTATEDSORTEDARRAY_H_
#define FINDMINIROTATEDSORTEDARRAY_H_
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
    	int low,high,mid,mark;
    	low = 0;
    	high = nums.size()-1;
    	mark = high;//下标
    	while(low<=high){
    		if((low+1)==high){
    			int temp = nums[low]<nums[high]?low:high;
    			if(nums[temp]<nums[mark])
    				mark = temp;
    			break;
    		}
    		mid = low+(high-low)/2;
    		if(nums[low]<nums[mid]){
    			if(nums[low]<nums[mark])
    				mark = low;
    			low = mid+1;
    		}else{
    			if(nums[mid]<nums[mark])
    				mark = mid;
    			high = mid-1;
    		}
    	}//while
    	return nums[mark];
    }
};
#endif /* FINDMINIROTATEDSORTEDARRAY_H_ */

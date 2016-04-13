/*
 * findMiniRotatedSortedArray2.h
 *
 *  Created on: Apr 10, 2016
 *      Author: lizhen
 */

#ifndef FINDMINIROTATEDSORTEDARRAY2_H_
#define FINDMINIROTATEDSORTEDARRAY2_H_
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
    		}else if(nums[low]>nums[mid]){
    			if(nums[mid]<nums[mark])
    				mark = mid;
    			high = mid-1;
    		}else{
    			low++;
    		}
    	}//while
    	cout<<"mark="<<mark<<endl;
    	return nums[mark];
    }
};
#endif /* FINDMINIROTATEDSORTEDARRAY2_H_ */
/*using namespace std;
int main(){
	vector<int> vit = {1,2,3,-2,-1,0};
	Solution s;
	cout<<s.findMin(vit)<<endl;
	return 0;
}
 * */

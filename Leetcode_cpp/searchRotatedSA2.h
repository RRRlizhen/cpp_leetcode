/*
 * searchRotatedSA2.h
 *
 *  Created on: Apr 10, 2016
 *      Author: lizhen
 */

#ifndef SEARCHROTATEDSA2_H_
#define SEARCHROTATEDSA2_H_
#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low,high,mid;
        low = 0;
        high = nums.size()-1;
        while(low<=high){
        	mid = low+(high-low)/2;
        	if(nums[mid]==target){
        		return true;
        	}
        	if(nums[low]<nums[mid]){
        		if(nums[low]<=target && target<nums[mid]){
        			high = mid-1;
        		}else{
        			low = mid+1;
        		}
        	}else if(nums[low]>nums[mid]){
        		if(nums[mid]<target && target<=nums[high]){
        			low = mid+1;
        		}else{
        			high = mid-1;
        		}
        	}else{
        		low++;
        	}
        }//while
        return false;
    }
};
#endif /* SEARCHROTATEDSA2_H_ */
/*
 int main(){
	vector<int> vit = {1,3,1,1,1,1};
	Solution s;
	if(s.search(vit,1)){
		cout<<"ture"<<endl;
	}else{
		cout<<"false"<<endl;
	}
	return 0;
}
 * */

/*
 * searchRotatedSA.h
 *
 *  Created on: Apr 10, 2016
 *      Author: lizhen
 */

#ifndef SEARCHROTATEDSA_H_
#define SEARCHROTATEDSA_H_
#include <vector>
using namespace std;
class Solution {
public://如果a[l]<a[m],那么a[l..m]就是递增数组
    int search(vector<int>& nums, int target) {
        int low,high,mid;
		low = 0;
		high = nums.size()-1;
		while(low<=high){
			mid = low+(high-low)/2;
			if(nums[mid]==target){
				return mid;
			}
			if(nums[low]<=nums[mid]){
				//判断nums[low...mid]是否是递增数组
				if(nums[low]<=target && target<nums[mid]){//判断target是否在递增数组部分搜索
					high = mid-1;
				}else{//否则，下面将要搜索截断（a[low..mid]被截断）的旋转数组
					low = mid+1;
				}
			}else{
				//那么nums[mid...high]是递增数组
				if(nums[mid]<target && target<=nums[high]){
					low = mid+1;
				}else{
					high = mid-1;
				}
			}//if-else
		}//while
		return -1;
	}
};
#endif /* SEARCHROTATEDSA_H_ */
/*
 int main(){
	vector<int> vit = {4,5,6,7,8,1,2,3};
	Solution s;
	cout<<">>"<<s.search(vit,8)<<endl;
	return 0;
}
 * */

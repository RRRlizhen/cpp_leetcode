/*
 * threesumclosest.h
 *
 *  Created on: Apr 13, 2016
 *      Author: lizhen
 */

#ifndef THREESUMCLOSEST_H_
#define THREESUMCLOSEST_H_
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
	//!!!!!!!!!does't work!!
    int threeSumClosest(vector<int>& nums, int target) {
        int result = INT_MAX;
        sort(nums.begin(),nums.end());
        auto last = nums.end();
        for(auto i = nums.begin();i<last-2;i++){
        	auto j=i+1;
        	auto k = last-1;
        	if(i>nums.begin() && *i==*(i-1)) continue;
        	for(;j<k;){
        		if((*i+*j+*k)==target) return target;
        		int temp = *i+*j+*k;
        		result = (abs(target-temp)-abs(result-target)>0)?result:temp;
        		j++;
        		k--;
        		while(*j==*(j-1)) j++;
        		while(*k==*(k+1)) k--;
        	}//for
        }//for
        return result;
    }
};




#endif /* THREESUMCLOSEST_H_ */

/*
 * meger.h
 *
 *  Created on: Apr 12, 2016
 *      Author: lizhen
 */

#ifndef MEGER_H_
#define MEGER_H_
#include <vector>
using namespace std;
class Solution {
public:
    double meger(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> result;
    	int lengtha = nums1.size();
    	int lengthb = nums2.size();
    	int i = 0,j = 0;
    	for(;i<lengtha && j<lengthb;){
    		if(nums1[i]<=nums2[j]){
    			result.push_back(nums1[i++]);
    		}else{
    			result.push_back(nums2[j++]);
    		}
    	}//for
    	for(;i<lengtha;){
    	    result.push_back(nums1[i++]);
    	}
    	for(;j<lengthb;){
    		result.push_back(nums2[j++]);
    	}
    	vector<int>::iterator vit = result.begin();
    	for(;vit!=result.end();){
    		cout<<*vit++<<" ";
    	}cout<<endl;
    	return -1;
    }
};
#endif /* MEGER_H_ */

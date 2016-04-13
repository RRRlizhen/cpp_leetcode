/*
 * twoSum.h
 *
 *  Created on: Apr 13, 2016
 *      Author: lizhen
 */

#ifndef TWOSUM_H_
#define TWOSUM_H_
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	unordered_map<int,int> hashtable;
    	int length = nums.size();
    	vector<int> result;
    	for(int i= 0;i<length;i++){
    		hashtable[nums[i]] = i;
    	}

    	for(int i = 0;i<length;i++){
    		const int other = target-nums[i];
    		if(hashtable.find(other) !=hashtable.end() && hashtable[other]>i){
    			result.push_back(i);
    			result.push_back(hashtable[other]);
    			break;
    		}
    	}//for
    	return result;
    }
};

#endif /* TWOSUM_H_ */

/*
 * int main(){
	vector<int> vit1 = {1,6,7,8};
	Solution s;
	vector<int> re;
	re = s.twoSum(vit1,15);
	for(auto i:re){
		cout<<i<<" ";
	}
	return 0;
}
 * */

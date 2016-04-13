/*
 * threeSum.h
 *
 *  Created on: Apr 13, 2016
 *      Author: lizhen
 */

#ifndef THREESUM_H_
#define THREESUM_H_
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<int> vit;
    	vector<vector<int>> vvit;
    	if(nums.size()<3) return vvit;
    	sort(nums.begin(),nums.end());
    	int length = nums.size();
    	for(int i = 0;i<length-2;i++){
    		int j = i+1;
    		int k = length-1;
    		if(i>0 && nums[i]==nums[i-1]) continue;
    		for(;j<k;){
    			if(nums[i]+nums[j]+nums[k]<0){
    				j++;
    				while(j<k && nums[j]==nums[j-1]) j++;
    			}else if(nums[i]+nums[j]+nums[k]>0){
    				k--;
    				while(j<k && nums[k]==nums[k+1]) k--;
    			}else{
    				vit.push_back(nums[i]);
    				vit.push_back(nums[j]);
    				vit.push_back(nums[k]);
    				vvit.push_back(vit);
    				vit.clear();
    				j++;
    				k--;
    				while(j<k && nums[j]==nums[j-1] && nums[k]==nums[k+1]){
    					k--;
    					j++;
    				}
    			}//if-elseif-else
    		}//for
    	}//for
    	return vvit;
    }
};



#endif /* THREESUM_H_ */
/*
 * int main(){
	vector<int> vit1 = {0,-1,1,6,7,8};
	Solution s;
	vector<int> vit;
	vector<vector<int>> vvit;
	vvit = s.threeSum(vit1);
	for(auto i:vvit){
		for(auto j:i){
			cout<<j<<" ";
		}cout<<endl;
	}
	return 0;
}
 * */

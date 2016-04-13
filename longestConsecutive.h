/*
 * longestConsecutive.h
 *
 *  Created on: Apr 13, 2016
 *      Author: lizhen
 */

#ifndef LONGESTCONSECUTIVE_H_
#define LONGESTCONSECUTIVE_H_
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	unordered_map<int,bool> hash_used;
    	for(auto i:nums){
    		hash_used[i] = false;
    	}
    	int longest = 0;
    	for(auto i:nums){
    		if(hash_used[i])
    			continue;
    		int length = 1;

    		hash_used[i] = true;

    		for(int j = i+1;hash_used.find(j)!=hash_used.end();j++){
    			hash_used[j] = true;
    			length++;
    		}
    		for(int j = i-1;hash_used.find(j)!=hash_used.end();j--){
    			hash_used[j] = true;
    			length++;
    		}
    		longest = max(longest,length);
    	}//for
    	return longest;
    }
};




#endif /* LONGESTCONSECUTIVE_H_ */

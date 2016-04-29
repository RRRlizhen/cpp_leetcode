#ifndef MAXSUBARRAY_H_INCLUDED
#define MAXSUBARRAY_H_INCLUDED
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int> &nums){
        /**dp
        f[i] = max{f[i-1]+nums[i],nums[i]},1<=i<n
        return max{f[i]} 0<=i<n
        */

        int length = nums.size();
        vector<int> f(length);
        f[0] = nums[0];
        for(int i = 1;i<length;i++){
            f[i] = max(f[i-1]+nums[i],nums[i]);
        }

        vector<int>::iterator iter;
        iter = max_element(f.begin(),f.end());
        return *iter;
    }
};


#endif // MAXSUBARRAY_H_INCLUDED

/*
 * MySqrt.h
 *
 *  Created on: Apr 7, 2016
 *      Author: lizhen
 */
#ifndef MYSQRT_H_
#define MYSQRT_H_
#include <cstdlib>
#include <math.h>
class Solution {
	/*分析，二分法求平方根
	 * 时间复杂度O（logn），空间复杂度O(1)
	 * 因为本题的结果是想下取整的，即9,10,11,12,13,14,15的平方根的结果都是3
	 * 这样的话，在利用二分搜索的时候，就要判断是否已经到达结果了;
	 * 怎么判断呢？m*m <= x <(m+1)*(m+1)的时候，直接向下取m值就可以了;
	 *
	 * 另外，oj判题系统会分配很大的整数，利用m*m会溢出，应该利用差法代替乘法
	 * */
public:
    int mySqrt(int x) {
    	if(x<0) return -1;
    	if(x==0) return 0;
    	if(x<2) return 1;
    	int left = 1;
    	int right = x/2+1;
    	while(left<=right){
    		int mid = left+(right-left)/2;
    		if(mid<=(x/mid) && x/(mid+1)<(mid+1)){
    			return mid;
    		}
    		if(mid<x/mid){
    			//说明根在上半部分
    			left = mid+1;
    		}else{
    			//根在下半部分
    			right = mid-1;
    		}
    	}
    	return 0;
    }
};
#endif /* MYSQRT_H_ */

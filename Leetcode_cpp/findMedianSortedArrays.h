/*
 * findMedianSortedArrays.h
 *
 *  Created on: Apr 13, 2016
 *      Author: lizhen
 */

#ifndef FINDMEDIANSORTEDARRAYS_H_
#define FINDMEDIANSORTEDARRAYS_H_
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	const int m = nums1.size();
    	const int n = nums2.size();
    	int total = m+n;
    	if(total & 0x1){
    		return find_kth(nums1.begin(),m,nums2.begin(),n,total/2+1);
    	}else{
    		return (find_kth(nums1.begin(),m,nums2.begin(),n,total/2)+
    				find_kth(nums1.begin(),m,nums2.begin(),n,total/2+1))/2.0;
    	}
    }
private:
    static int find_kth(std::vector<int>::const_iterator A,int m,
    		std::vector<int>::const_iterator B,int n,int k){
    	//always assume that m <=n
    	if(m>n)	return find_kth(B,n,A,m,k);
    	if(m==0) return *(B+k-1);
    	if(k==1) return min(*A,*B);

    	//divide k into two parts
    	int ia = min(k/2,m);
    	int ib = k - ia;
    	if(*(A+ia-1)<*(B+ib-1)){
    		return find_kth(A+ia,m-ia,B,n,k-ia);
    	}else if(*(A+ia-1)>*(B+ib-1)){
    		return find_kth(A,m,B+ib,n-ib,k-ib);
    	}else{
    		return A[ia-1];
    	}
    }
};
#endif /* FINDMEDIANSORTEDARRAYS_H_ */

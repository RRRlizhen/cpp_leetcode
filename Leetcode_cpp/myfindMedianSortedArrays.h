/*
 * myfindMedianSortedArrays.h
 *
 *  Created on: Apr 13, 2016
 *      Author: lizhen
 */

#ifndef MYFINDMEDIANSORTEDARRAYS_H_
#define MYFINDMEDIANSORTEDARRAYS_H_
#include <vector>
using namespace std;
class mySolution {
public:
    double myfindMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int lengtha = nums1.size();
    	int lengthb = nums2.size();
    	int total = lengtha+lengthb;
    	if(total & 0x1){
    		return find_kth(nums1,nums2,total/2+1);
    	}else{
    		return (find_kth(nums1,nums2,total/2)+
    				find_kth(nums1,nums2,total/2+1))/2.0;
    	}
    }
private:
    int find_kth(vector<int> &A,vector<int> &B,int k){
    	std::vector<int>::const_iterator p1 = A.begin();
    	std::vector<int>::const_iterator p2 = B.begin();
    	int m = 0;
    	while(p1!=A.end() && p2!=B.end()){
    		if(*p1<=*p2 && m==(k-1)){
    			return *p1;
    		}else if(*p1>*p2 && m==(k-1)){
    			return *p2;
    		}
    		if(*p1<=*p2)
    			p1++;
    		else
    			p2++;
    		m++;
    	}//while
    	while(p1!=A.end()){
    		if(m==(k-1)){
    			return *p1;
    		}
    		p1++;
    		m++;
    	}
    	while(p2!=B.end()){
    		if(m==(k-1)){
    			return *p2;
    		}
    		p2++;
    		m++;
    	}
    	return -1;
    }
};




#endif /* MYFINDMEDIANSORTEDARRAYS_H_ */

/*
 * main.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: lizhen
 */

#include <iostream>
#include "MySqrt.h"
#include <math.h>
#include "findMedianSortedArrays.h"
#include "myfindMedianSortedArrays.h"
#include <vector>
using namespace std;

int main(){
	vector<int> vit1 = {1,2,3,4};
	vector<int> vit2 = {1,2,3,4};
	Solution s;
	mySolution mys;
	cout<<s.findMedianSortedArrays(vit1,vit2)<<endl;
	cout<<mys.myfindMedianSortedArrays(vit1,vit2)<<endl;
	return 0;
}
/*class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    }
};
 * */


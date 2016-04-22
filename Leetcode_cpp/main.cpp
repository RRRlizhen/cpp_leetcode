/*
 * main.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: lizhen
 */

#include <iostream>
#include "MySqrt.h"
#include <math.h>
//#include "findMedianSortedArrays.h"
//#include "myfindMedianSortedArrays.h"
//#include "longestConsecutive.h"
//#include "threeSum.h"
//#include "threesumclosest.h"
//#include "nextPermutation.h"
//#include "trap.h"
//#include "rotateImage.h"
//#include "setMatrixZeroes.h"
//#include "treeNode.h"
#include <vector>
//#include "preorderT.h"
//#include "findMinpathsum.h"
//#include "TreeTrans01.h"
#include "triangle.h"
using namespace std;

int main() {
	vector<vector<int>> vvit = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
	Solution s;
	for (auto i : vvit) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
	int m = s.minimumTotal(vvit);
	cout << "-----" << m << endl;

	return 0;
}


/*
 * triangle.h
 *
 *  Created on: Apr 22, 2016
 *      Author: lizhen
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	/*
	 *o
	 *o o
	 *o o o
	 *o o o o													->
	 *题目上说，我们每一步只能超下一行的相邻位置移动，是|\，不是/|\，也不是/|\
	 *所以状态转换方程可以这么写：f[i,j]=min(f[i+1][j],f[i+1][j+1])+[i][j]
	 * 这是从下向上的方式
	 * */

	int minimumTotal(vector<vector<int>> &triangle){
		int length_tr = triangle.size();
		for(int i = length_tr-2;i>=0;i--){//从triangle的倒数第二行开始算起
			for(int j = 0;j<i+1;j++){
				//这是一个正三角形，所以我们可以利用j<i+1作为判断条件
				triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
			}
		}

		return triangle[0][0];
	}
};
#endif /* TRIANGLE_H_ */

/*
 * int main() {
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
 * */

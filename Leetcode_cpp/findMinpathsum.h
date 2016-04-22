/*
 * findMinpathsum.h
 *
 *  Created on: Apr 21, 2016
 *      Author: lizhen
 */

#ifndef FINDMINPATHSUM_H_
#define FINDMINPATHSUM_H_
#include <vector>
using namespace std;
class Solution{
public:
	int minPathSum(vector<vector<int> > &grid){
		if(grid.size()==0) return 0;
		const int m = grid.size();
		const int n = grid[0].size();

		int f[m][n];
		f[0][0] = grid[0][0];
		for(int i = 1;i<m;i++){
			//初始化状态方程第一行
			f[i][0] = f[i-1][0]+grid[i][0];
		}
		for(int i = 1;i<n;i++){
			//初始化状态方程第一列
			f[0][i] = f[0][i-1]+grid[0][i];
		}

		//运用状态方程求解
		for(int i = 1;i<m;i++){
			for(int j = 1;j<n;j++){
				if(f[i-1][j]<f[i][j-1]){
					cout<<i-1<<"-"<<j<<endl;
				}else{
					cout<<i<<"-"<<j-1<<endl;
				}
				f[i][j] = min(f[i-1][j],f[i][j-1])+grid[i][j];
			}
		}

		return f[m-1][n-1];
	}
};
#endif /* FINDMINPATHSUM_H_ */

/*
 * int main(){
	Solution s;
	vector<vector<int> > vvit = {
								{1,2,3,4},
								{5,1,7,8},
								{11,2,1,4},
								{10,11,2,1}};
	cout<<s.minPathSum(vvit)<<endl;
	return 0;
}
 * */

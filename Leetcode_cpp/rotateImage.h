/*
 * rotateImage.h
 *
 *  Created on: Apr 15, 2016
 *      Author: lizhen
 */

#ifndef ROTATEIMAGE_H_
#define ROTATEIMAGE_H_
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
	/*
	 思路：按顺时针方向反转矩阵，分为两步可以完成
	 1,先沿着水平中线反转
	 2,再沿着主对角线反转
	 ---按照1234画图就可理解
	 * */
public:
    void rotate(vector<vector<int>>& matrix) {
    	int c_length = matrix.size();//多少行，n*n
    	for(int i = 0;i<c_length/2;i++){
    		for(int j = 0;j<c_length;j++){
    			swap(matrix[i][j],matrix[c_length-i-1][j]);
    		}
    	}//水平反转
    	for(auto i:matrix){
    		for(auto j:i){
    			cout<<j<<" ";
    		}cout<<endl;
    	}cout<<endl;

    	//按照主对角线反转
    	for(int i = 0;i<c_length;i++){
    		for(int j = i+1;j<c_length;j++){
    			swap(matrix[i][j],matrix[j][i]);
    		}
    	}

    	for(auto i:matrix){
    	    		for(auto j:i){
    	    			cout<<j<<" ";
    	    		}cout<<endl;
    	    	}cout<<endl;
    }
};
#endif /* ROTATEIMAGE_H_ */

/*
 * int main(){
	vector<int> vit1 = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<vector<int>> vvit = {{1,2,3},{4,5,6},{7,8,9}};
	Solution s;
	s.rotate(vvit);
	return 0;
}
 * */

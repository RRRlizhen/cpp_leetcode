/*
 * setMatrixZeroes.h
 *
 *  Created on: Apr 15, 2016
 *      Author: lizhen
 */

#ifndef SETMATRIXZEROES_H_
#define SETMATRIXZEROES_H_
#include<vector>
using namespace std;

class Solution {
	/*
	 思路：
	 给的条件有行列式m×n，如果行列式存在0值，那么该值所在的行、所在的列都得变为0
	 空间复杂度：O(m+n)
	 申请两个数组，a[],b[],分别记录每行、每列是不是0值，然后设定。
	 * */
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	int c_len = matrix.size();//多少行
    	int r_len = matrix.size();//多少列
    	vector<bool> a(c_len,false);
    	vector<bool> b(r_len,false);

    	for(auto i:matrix){
    		for(auto j:i){
    			cout<<j<<" ";
    		}cout<<endl;
    	}cout<<endl;

    	for(int i = 0;i<c_len;i++){
    		for(int j = 0;j<r_len;j++){
    			if(matrix[i][j]==0){
    				a[i] = true;
    				b[j] = true;
    			}
    		}
    	}

    	for(int i = 0;i<c_len;i++){
    		if(a[i]){
    			for(int j= 0;j<r_len;j++){
    				matrix[i][j] = 0;
    			}
    		}
    	}

    	for(int j = 0;j<r_len;j++){
    		if(b[j]){
    			for(int i = 0;i<c_len;i++){
    				matrix[i][j] = 0;
    			}
    		}
    	}

    	for(auto i:matrix){
    	    		for(auto j:i){
    	    			cout<<j<<" ";
    	    		}cout<<endl;
    	    	}cout<<endl;

    }
};
#endif /* SETMATRIXZEROES_H_ */

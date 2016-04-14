/*
 * isValidSudoku.h
 *
 *  Created on: Apr 14, 2016
 *      Author: lizhen
 */

#ifndef ISVALIDSUDOKU_H_
#define ISVALIDSUDOKU_H_
#include <vector>
using namespace std;
class Solution {
	/*一个合法的数独应该符合三条规则
	 * 1,每一行必须有数字1-9出现，而且必须出现一次
	 * 2,每一列必须有数字1-9出现，而且必须出现一次
	 * 3,面板中每9个连续的子面板，必须由数字1-9出现，而且必须出现一次
	 * 规则连接：http://sudoku.com.au/TheRules.aspx
	 *
	 *
	 * 实现方法：
	 * 先按照行检查，在按照列检查，最后对子面板检查
	 * 检查的过程是使用hash_table形式的数组实现的
	 *
	 * */
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	bool used[9];
    	for(int i = 0;i<9;i++){
    		fill(used,used+9,false);

    		for(int j = 0;j<9;j++){//check row
    			if(!check(board[i][j],used))
    				return false;
    		}

    		fill(used,used+9,false);
    		for(int j = 0;j<9;j++){//check |
    			if(!check(board[j][i],used))
    				return false;
    		}
    	}

    	for(int r = 0;r<3;r++){
    		for(int c = 0;c<3;c++){
    			fill(used,used+9,false);

    			for(int i = r*3;i<r*3+3;i++){
    				for(int j = c*3;j<c*3+3;j++){
    					if(!check(board[i][j],used))
    						return false;
    				}
    			}
    		}
    	}//for-for
    }//isValidSudoku
private:
    bool check(char ch,bool used[9]){
    	if(ch == '.') return true;
    	if(used[ch - '1']) return false;/*
    									char型字节码可以充当数组下表，
    									利用char类型的字面值就可以索引char字面值<key>对应的数组值<value>
    									这是数据结构hash_table的体现：  key->value
    									*/
    	return used[ch-'1'] = true;
    }
};
#endif /* ISVALIDSUDOKU_H_ */

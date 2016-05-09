/*
 * trap.h
 *
 *  Created on: Apr 15, 2016
 *      Author: lizhen
 */

#ifndef TRAP_H_
#define TRAP_H_
#include <vector>
using namespace std;
class Solution {
	/*思路:
	 *对每一根柱子，找到它左右两边最高的柱子，那么该柱子能容纳的面积就是min(max_left,max_right)-hight
	 * 	hight就是这根柱子的高度。
	 *步骤：
	 *	1,第一遍扫描数组，找到每根柱子的左边最大值
	 *	2,第二遍扫描数组，找到每根柱子右边的最大值
	 *	3,第三遍扫描数组，求每根柱子的面积并且累加
	 * */
public:
    int trap(vector<int>& height) {
    	int length = height.size();
    	vector<int> left_max(length,0);
    	vector<int> right_max(length,0);

    	for(int i = 1;i<length;i++){
    		//这一步有一个迭代的过程，因为我们所要求得是每个柱子左面的最大值，那么这个最大值可能具有传递性，
    		//可能当前柱子左面的最大值，也是右面柱子的最大值
    		//处理数组height[0],它左面没有元素了，那么left_max[0]=?
    		//我们可以让left_max[0]=0，那么接下来该柱子的面积0-high，只要计算柱子面积大于0的情况就可以了;
    		left_max[i] = max(left_max[i-1],height[i-1]);
    	}//for
    	for(int j = length-2;j>=0;j--){
    		//分析同上
    		right_max[j] = max(right_max[j+1],height[j+1]);
    	}

    	//现在我们已经得到了每根柱子左面最大值和右面的最大值
    	int total = 0;
    	for(int i= 0;i<length;i++){
    		int Isok = min(left_max[i],right_max[i])-height[i];
    		if(Isok>0){
    			total += Isok;
    		}
    	}

    	return total;
    }
};
#endif /* TRAP_H_ */

/*
 * int main(){
	vector<int> vit1 = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution s;
	cout<<s.trap(vit1);
	return 0;
}*/

/*
 * nextPermutation.h
 *
 *  Created on: Apr 13, 2016
 *      Author: lizhen
 */

#ifndef NEXTPERMUTATION_H_
#define NEXTPERMUTATION_H_
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/*http://fisherlei.blogspot.sg/
	 * thanks for :水中的鱼，
	 * 给出的算法：
	 * 第一步：从右到左，找到第一个分割数字（partionNumbers）,这个数字隔断了从右到左的升序
	 * 第二部：从右到左，找到第一个比分割数字（partionNumbers）大的数字，我们叫他changeNumber数字
	 * 第三部：对分割数字与changeNumber交换
	 * 第四步：对分割数字下标右面的数字序列进行反转reverse
	 * 真厉害
	 * */
    void nextPermutation(vector<int>& nums) {
    	auto last = nums.end();
    	int length = nums.size();
    	if(length<2) return;
    	auto i = last-1;
    	auto j = nums.begin();
    	while(i>nums.begin() && *(i-1)>=*(i)){
    		i--;
    	}//跳出循环的时候，i-1 = partionNumbers

    	if(i==nums.begin()){
    		reverse(i,nums.end());
    		    	for(auto re:nums){
    		    		cout<<re<<" ";
    		    	}cout<<endl;
    		    	return;
    	}
    	i--;
    	cout<<"partionNumbers= "<<*i<<endl;
    	for(auto k = nums.end()-1;k>i;k--){
    		if(*k > *i){
    			j = k;
    			cout<<"chanage_numbers= "<<*j<<endl;
    			break;
    		}
    	}//找到change_numbers

    	//交换
    	int temp = *i;
    	*i = *j;
    	*j = temp;

    	//反转
    	reverse(i+1,nums.end());
    	for(auto re:nums){
    		cout<<re<<" ";
    	}cout<<endl;
    }
};
#endif /* NEXTPERMUTATION_H_ */

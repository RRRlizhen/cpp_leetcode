/*
 * maxProfit.h
 *
 *  Created on: Apr 29, 2016
 *      Author: lizhen
 */

#ifndef MAXPROFIT_H_
#define MAXPROFIT_H_
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//只能买卖一次股票，取得最大值，应该在最低点买，在最高点卖
    int maxProfit(vector<int>& prices) {
    	int length = prices.size();
    	int maxProfit = 0;//到目前为止，能得到的最大的利润
    	int minprice;//到目前位置，最低的价格
    	for(int i = 0;i<length;i++){
    		maxProfit = max(maxProfit,prices[i]-minprice);
    		minprice = min(minprice,prices[i]);
    	}
    	return maxProfit;
    }
};

#endif /* MAXPROFIT_H_ */

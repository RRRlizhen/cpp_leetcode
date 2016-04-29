/*
 * maxProfit2.h
 *
 *  Created on: Apr 29, 2016
 *      Author: lizhen
 */

#ifndef MAXPROFIT2_H_
#define MAXPROFIT2_H_
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
	//这一次你可以买一只股票，卖一只股票多次;但是你不能在同一时间进行多次交易，
	//就是说你必须在你买股票之前，卖掉所有的股票
public:
    int maxProfit(vector<int>& prices) {
    	//举个例子[5,1,4,5,3,4,5]
    	//        [0,3,1,0,1,1]
    	//j就是说所有能赚钱的机会，你都能抓住
    	//而不是只能作一次交易，只能赚5-1=4
    	int length = prices.size();
    	int total = 0;
    	for(int i = 1;i<length;i++){
    		if(prices[i]>prices[i-1]){
    			total += prices[i]-prices[i-1];
    		}
    	}//

    	return total;
    }
};
#endif /* MAXPROFIT2_H_ */

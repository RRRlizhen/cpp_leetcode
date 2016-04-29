/*
 * pow.h
 *
 *  Created on: Apr 28, 2016
 *      Author: lizhen
 */

#ifndef POW_H_
#define POW_H_
using namespace std;
class Solution{
	/*实现pow(x,n)，就是x的n次幂pow(2,5)=32,pow(3,4)=81
	 * 采用二分法实现
	 * 思路：
	 * 因为n有可能是负数，pow(2,-1)=1/2;
	 * assume n>=0
	 * 	if n<0
	 * 		then return 1.0/(power(x,-n));
	 * 	-------
	 * 	if n%2==0,那么直接递归求
	 * 		v = power(x,n/2);
	 * 		return v*v;
	 * 	if n%2!=0,then
	 * 		v = power(x,n/2)
	 * 		return v*v*x;
	 * 	power(double x,int n)递归的结束条件是：
	 * 		n==0 return 1;
	 * */
public:
    double myPow(double x, int n) {
    	if(n<0)
    		return 1.0/pows(x,-n);
    	else
    		return pows(x,n);
    }
private:
    double pows(double x,int n){
    	if(n==0)
    		return 1;
    	double v = pows(x,n/2);
    	if(n%2==0)
    		return v*v;
    	else
    		return v*v*x;
    }
};




#endif /* POW_H_ */

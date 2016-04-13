/*
 * MySqrt.h
 *
 *  Created on: Apr 7, 2016
 *      Author: lizhen
 */
#ifndef MYSQRT_H_
#define MYSQRT_H_
#include <cstdlib>
#include <math.h>
/*
 * class solution_mySqrt{
public:
	int mySqrt(int x){
		int result;
		int hight,low;
		hight = x;
		low = 1;
		result = x/2;
		if(x<=1){
			return x;
		}
		while(result<x){
			if(pow(result,2)>x){
				result--;
			}else if(pow(result,2)<x){
				result++;
			}else{
				return result;
			}
		}//while
	}
};
 * */
#endif /* MYSQRT_H_ */

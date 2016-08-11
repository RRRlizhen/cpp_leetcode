/*main.c*/
#include <stdio.h>
#include "a.h"

extern void function_two();
extern void function_three();

int main(){
	function_two();
	function_three();

	printf("main done\n");
	return 0;
}

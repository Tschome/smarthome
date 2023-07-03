#include <stdio.h>
#include <stdlib.h>

#include "common.h"
int main(int argc, char **argv)
{
	printf("HELLO World!\n");


	int a = 5, b = 10;

	int ret = add(a,b);

	printf("ret:%d\n", ret);

	return 0;
}


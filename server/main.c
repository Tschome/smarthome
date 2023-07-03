#include <stdio.h>
#include <stdlib.h>
//#include <log.h>
#include "sqlite3.h"
#include "common.h"
int main(int argc, char **argv)
{
	printf("HELLO World!\n");


	sqlite3* db;
	int a = 5, b = 10;

	int ret = add(a,b);

	printf("ret:%d\n", ret);
	//log_set_flags(LOG_SKIP_REPEATED | LOG_PRINT_LEVEL);//跳过重复的信息 + 显示打印级别

	return 0;
}


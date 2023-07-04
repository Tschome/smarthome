
/*
 * 项目分析：基于树莓派的智能家居控制系统  *后台服务 + 显示屏GUI界面显示/控制 + web/移动端显示/控制
 *
 * 		该项目代码是“后台服务”程序，用于接收各个模块的信息，存储，展示，并能够做出控制的后台服务程序；
 *
 * 技术涉及：串口通信/蓝牙通讯/USB通讯/摄像头/网口通讯等
 *
 *
 * 代码结构：采用多线程方式：主线程+日志线程+调试线程(debug)+采集线程+上报线程（多方式）+存储线程（存sd卡/存sata等）
 *
 *
 * 暂定命名方式：
 * sh_server: 	smartHome_server
 * sh_gui:	smartHome_gui
 * sh_**
 *
 *
 * 项目阶段1：搭建项目框架
 *
 * 基本内容：	1.搭建框架，起草数据库存储方式，数据导出方式，上报报文,确定编译链，基于一个版本下进行项目开发，使用固定的编译工具，并确定是否使用cmake
 * 		2.获取温湿度信息，并保存数据库
 * 		3.基于温度信息，自动控制继电器开关
 *
 * 代码结构的话：比如说数据库，可能会使用多种数据库，那么每一个数据库一个文件夹，每种方式可以切换配置；最终该项目将只会使用一种数据库，其他数据库方式仅用于学习
 *
 * author: van.ghylivan
 * time:   2023.07.01
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#include "common.h"

#define TAG "main"

//#define log_error()

//SH_GLOBAL_T *glb = NULL;

/*
static int init_sqlite3(SH_GLOBAL_T *glb)
{
	int ret = 0;
	
	ret = init_db(glb->db_log, LOG_DATABASE_FILE, CREATE_DB_LOG);
	if (ret != 0) {
		log(TAG, LOG_ERROR,"init_db_log failed!\n");
		return ret;
	}

	return ret;
}
*/


int main(int argc, char **argv)
{
	int ret = 0;

	/* parse cmd */
	//解析命令行参数，包含日志等级===>在配置文件尚未弄好之前使用当前方式

	/* init log */
	log_set_flags(LOG_SKIP_REPEATED | LOG_PRINT_LEVEL);//跳过重复的信息 + 显示打印级别
	log_set_level(LOG_MAX_OFFSET);

	log(TAG, LOG_INFO, "server init\n");

#if 0
	if (glb != NULL) free(glb);
	glb = (SH_GLOBAL_T *)malloc(sizeof(SH_GLOBAL_T));
	if (glb == NULL) {
		log(TAG, LOG_ERROR, "malloc glb failed!\n");
		return -1;
	}



	/* parse config file */
	//使用xml配置文件，对相关参数进行配置
	ret = parse_config();
	if (ret != 0) {
		log(TAG, LOG_ERROR,"parse_config failed!\n");
		return ret;
	}

	/* init db thread */
	//确认使用数据库方式
	if (glb->tConfig.db_type == 0) {
		ret = init_sqlite3(glb);
		if (ret != 0) {
			log(TAG, LOG_ERROR,"%s failed!\n", __func__);
			return ret;
		}
	}
	/* init collect thread */
#endif

	log(TAG, LOG_QUIET, "LOG_QUIET\n");
	log(TAG, LOG_PANIC, "LOG_PANIC\n");
	log(TAG, LOG_FATAL, "LOG_FATAL\n");
	log(TAG, LOG_ERROR, "LOG_ERROR\n");
	log(TAG, LOG_WARNING, "LOG_WARNING\n");
	log(TAG, LOG_INFO, "LOG_INFO\n");
	log(TAG, LOG_VERBOSE, "LOG_VERBOSE\n");
	log(TAG, LOG_DEBUG, "LOG_DEBUG\n");
	log(TAG, LOG_TRACE, "LOG_TRACE\n");
	log(TAG, LOG_MAX_OFFSET, "LOG_MAX_OFFSET\n");
	return;
}



#if 0

#include <stdio.h>
#include <stdlib.h>



static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}





int main(int argc, char **argv)
{
	printf("HELLO World!\n");


	//sqlite3* db;
	int a = 5, b = 10;

	int ret = add(a,b);

	printf("ret:%d\n", ret);
	log_set_flags(LOG_SKIP_REPEATED | LOG_PRINT_LEVEL);//跳过重复的信息 + 显示打印级别


sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);






	return 0;
}

#endif



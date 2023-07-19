
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

#include "common.h"

#define TAG "main"

//#define log_error()

GLOBAL_T *glb = NULL;

int init(void)
{
	int ret = 0;
	//参数初始化（default）

	log(TAG, LOG_INFO, "server init successfully!!!\n");
	return ret;
}

int main(int argc, char **argv)
{
	int ret = 0;

	/* parse cmd */
	//解析命令行参数，包含日志等级===>在配置文件尚未弄好之前使用当前方式

	/* init log */
	log_set_flags(LOG_SKIP_REPEATED | LOG_PRINT_LEVEL);//跳过重复的信息 + 显示打印级别
	log_set_level(LOG_MAX_OFFSET);

	if (glb != NULL) free(glb);
	glb = (GLOBAL_T *)malloc(sizeof(GLOBAL_T));
	if (glb == NULL) {
		log(TAG, LOG_ERROR, "malloc glb failed!\n");
		return -1;
	}

	do {
		/* init */
		ret = init();
		if (ret != 0) {
			break;
		}

		/* parse config file */
		//使用xml配置文件，对相关参数进行配置
		ret = parse_config();
		if (ret != 0) {
			log(TAG, LOG_ERROR,"parse_config failed!\n");
			break;
		}

		/* init db thread */
		//确认使用数据库方式
		ret = init_db();
		if (ret != 0) {
			log(TAG, LOG_ERROR,"init_db failed!\n");
			goto err_init_db;
		}

		/* 1.打开定时器 */
		/* 2.开辟fifo，用于调试 */



		/* init log thread用于记录实时数据，以及错误信息等*/
		/* init collect thread */
		/* init upload thread */

	} while(0);

err_init_db:
	deinit_db();	
	return ret;
}





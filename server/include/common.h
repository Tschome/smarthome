#ifndef __COMMON__
#define __COMMON__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <time.h>
#include "log.h"




#define VERSION 1.0.0
#define DATA	6.1

/***********************************
 * define
 *
 * *********************************/
#define MAX_SQLITE_CNTS 8


#define CREATE_LOG_DB	"CREATE TABLE COMPANY("  \
         		"ID INT PRIMARY KEY     NOT NULL," \
         		"NAME           TEXT    NOT NULL," \
         		"TIME           CHAR    NOT NULL," \
			"EVENT		CHAR	NOT NULL);"
#define CREATE_DATA_DB  "NULL"
/***********************************
 * enum
 *
 * *********************************/
typedef enum{
	STATUS_INIT = 0,
	STATUS_CLOSE,
	STATUS_OPEN,
	STATUS_READ,
	STATUS_UPLOAD,
	STATUS_RECORD,
}STATUS_E;

enum{
	eSQLITE_MAIN = 0,
	eSQLITE_LOG,
	eSQLITE_DATA,
}DB_SQLITE_TYPE_E;

/***********************************
 * struct
 *
 * *********************************/
typedef struct{
	time_t time;
	float  fTemp;
	float  fHum;
}STATUS_FAST_T;


typedef struct{
	STATUS_E status;
	int 	cycle;
}PTHREAD_COLLECT_T;

typedef struct{
	char name[64];
	sqlite3* sqlite;
	char createSql[256];

}DB_SQLITE_T;

typedef struct{
	int isInit;
}CONFIG_COMMON_T;;

typedef struct{
	int 	status;
	time_t 	tTime;
	char*	pStrTime[64];//string of time e.g. 2023.01.01 09:00
	float  	tTemp;
	
	/* sqlite3 handle */
	DB_SQLITE_T db[MAX_SQLITE_CNTS];
	/* glb status */
	STATUS_FAST_T tFastStatus;

	/* configure*/
	CONFIG_COMMON_T *pConfig;
	/* collect pthread */
	PTHREAD_COLLECT_T *pThreadCollect;
}GLOBAL_T;




extern int add(int a, int b);

int parse_config();
int init_db(void);
int deinit_db(void);

extern GLOBAL_T *glb;

#endif

# 其中log需要使用编译成静态库，然后用于该工程使用；需要学习一下cmake如何使用的
#
# 需要静态编译(交叉)的：log sqlite3


CROSS_COMPILE ?= arm-linux-gnueabihf-
CC := $(CROSS_COMPILE)gcc
LD := $(CROSS_COMPILE)gcc
AR := $(CROSS_COMPILE)ar cr
STRIP := $(CROSS_COMPILE)strip

INCLUDES += -I$(PWD)/include
INCLUDES += -I$(PWD)/../../external/sqlite/include
CFLAGS = $(INCLUDES) -Wall
#CFLAGS +=

# 正则表达式表示目录下所有.c文件，相当于：SRCS = main.c a.c b.c
SRCS = $(wildcard *.c common/*.c)

# OBJS表示SRCS中把列表中的.c全部替换为.o，相当于：OBJS = main.o a.o b.o
OBJS = $(patsubst %c, %o, $(SRCS))

COMMON_SRCS = $(wildcard common/*.c)
COMMON_OBJS = $(patsubst %c, %o, $(COMMON_SRCS))

LIBS_PATH := $(PWD)/../../external
LIBS := -lpthread -lm  
LIBS += -L$(LIBS_PATH)/sqlite/lib -lsqlite3

# 可执行文件的名字
TARGET = server

# .PHONE伪目标，具体含义百度一下一大堆介绍
.PHONY:all clean

# 要生成的目标文件
all: $(TARGET)

# 第一行依赖关系：冒号后面为依赖的文件，相当于Hello: main.o a.o b.o
# 第二行规则：$@表示目标文件，$^表示所有依赖文件，$<表示第一个依赖文件
$(TARGET): $(OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# 上一句目标文件依赖一大堆.o文件，这句表示所有.o都由相应名字的.c文件自动生成
%.o:%.c *.h
	$(CC) $(CFLAGS) -c $^ $(LIBS)

# make clean删除所有.o和目标文件
clean:
	rm -f $(OBJS) $(TARGET)





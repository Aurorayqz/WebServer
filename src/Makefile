#
# Makefile
# web_server
#
#

CXX = g++
EXEC_HTTP = server_http

SOURCE_HTTP = main_http.cpp

OBJECTS_HTTP = main_http.o

# 开启编译器 O3 优化, pthread 启用多线程支持
LDFLAGS_COMMON = -std=c++11 -O3 -pthread -lboost_system
LDFLAGS_HTTP =

#-I, 指定头文件所在的文件夹
LPATH_COMMON = -I/usr/include/boost
LPATH_HTTP =

#-L，指定函数库所在的文件夹
LLIB_COMMON = -L/usr/lib
LLIB_HTTP = 

http:
	$(CXX) $(SOURCE_HTTP) $(LDFLAGS_COMMON) $(LDFLAGS_HTTP) $(LPATH_COMMON) $(LPATH_HTTP) $(LLIB_COMMON) $(LLIB_HTTP) -o $(EXEC_HTTP)

clean:
	rm -f $(EXEC_HTTP) *.o
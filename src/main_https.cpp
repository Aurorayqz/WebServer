//
// main_https.cpp
// web_server
//

#include "server_https.hpp"
#include "handler.hpp"
using namespace AurorayqzWeb;

int main(int argc, char const *argv[])
{
	//HTTPS 服务运行在 12345 端口，并启用四个线程
	Server<HTTPS> server(12345,4,"server.crt","server.key");
	start_server<Server<HTTPS>>(servent);
	return 0;
}
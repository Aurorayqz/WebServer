#Web 服务框架

##项目介绍
----------

 - 服务器开发中 Web服务是一个基本的代码单元，将服务端的请求和响应部分的逻辑抽象出来形成框架，能够做到最高级别的框架级代码复用。该项目将综合使用 C++11及 Boost 中的 Asio 实现 HTTP 和 HTTPS 的服务器框架。

##C++相关
------
 - 基本知识
 - 面向对象
 - 模板
 - 命名空间
 - 常用 IO 库
 - C++11 相关
 - lambda expression
 - std::shared_ptr
 - std::make_shared
 - std::unordered_map
 - std::regex
 - std::smatch
 - std::regex_match
 - std::function
 - std::thread
##Boost Asio 相关
------
 - boost::asio::io_service
 - boost::asio::ip::tcp::socket
 - boost::asio::ip::tcp::v4()
 - boost::asio::ip::tcp::endpoint
 - boost::asio::ip::tcp::acceptor
 - boost::asio::streambuf
 - boost::asio::async_read
 - boost::asio::async_read_until
 - boost::asio::async_write
 - boost::asio::transfer_exactly
 - boost::asio::ssl::stream
 - boost::asio::ssl::stream_base::server
 - boost::asio::ssl::context
 - boost::asio::ssl::context::sslv23
 - boost::asio::ssl::context::pem
 - boost::system::error_code

##HTTP 服务器框架测试
------
 - 使用 make http 来编译代码，并通过 ./server_http 来运行服务器，并在浏览器中测试服务器运行情况：
 - 对于 GET 请求，直接在浏览器中访问：

```
localhost:12345/                # 会访问到 index.html
localhost:12345/match/123abc    # 会获得到一个 123abc 的字符串
localhost:12345/info/           # 会获得整个请求体的信息
```
 - 对于 POST 请求，我们可以使用 curl 命令进行测试：

```
curl -d "test string" "http://localhost:12345/string/"
```

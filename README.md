# Web 服务框架

## 项目介绍
 - 服务器开发中 Web服务是一个基本的代码单元，将服务端的请求和响应部分的逻辑抽象出来形成框架，能够做到最高级别的框架级代码复用。该项目将综合使用 C++11及 Boost 中的 Asio 实现 HTTP 和 HTTPS 的服务器框架。

## C++相关
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
## Boost Asio 相关
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

## HTTP 服务器框架测试
 - 使用 make http 来编译代码，并通过 ./server_http 来运行服务器，并在浏览器中测试服务器运行情况：
 - 对于 GET 请求，直接在浏览器中访问：

```
localhost:12345/                # 会访问到 index.html
localhost:12345/match/123abc    # 会获得到一个 123abc 的字符串
localhost:12345/info/           # 会获得整个请求体的信息
```
 - 对于 POST 请求，使用 curl 命令进行测试：

```
curl -d "test string" "http://localhost:12345/string/"
```

## HTTPS 服务器框架测试
 - 使用 make https 来编译代码，并通过 ./server_http 来运行服务器，并在浏览器中测试服务器运行情况：
 - 源码中已经生成SSL 证书
 - 在浏览器中输入：

```
https://localhost:12345
```
 - 这时，我们会看到浏览器正在告诉我们这个链接不安全。
这是由于我们的证书是自签名的产生的原因。一般情况下，自签名的 SSL 证书可以随意的签发，没有第三方监督的审核，并不能收到浏览器的信任。这就非常容易造成伪造证书的中间人攻击，从而导致劫持 SSL 加密流量。
我们刚才在创建证书的时候，指定了这个证书会被用于 aurorayqz.com 这个域名，而实际上我们在访问时，访问的 URL 是 localhost，这时浏览器识别到这个不同，也就阻止了这次连接。

 - 为了测试，我们可以将本次连接添加新人列表中，增加一个安全例外
这样我们就能看到使用 HTTPS 访问到的资源内容了

 - 可惜的是，我们依然不能做到像『正经』厂商一样，让那一把小锁变成绿色：
原因就如同之前我们所提到的那样，SSL 证书受到第三方监管，浏览器信任的证书一般来自国外的几个指明 SSL 证书签发商，而这种证书的签发往往需要向签发商支付一定的费用，虽然也有诸如 StartSSL 这样的提供免费 SSL 证书的签发商，但由于我们没有域名进行测试，这里就不再赘述了。

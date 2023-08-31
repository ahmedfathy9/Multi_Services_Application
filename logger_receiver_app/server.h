#ifndef SERVER_H
#define SERVER_H

#include <boost/asio.hpp>

class Server {
public:
    Server(boost::asio::io_service& io_service, int port);
};

#endif  // SERVER_H

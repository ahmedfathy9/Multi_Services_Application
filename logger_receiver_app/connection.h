#ifndef CONNECTION_H
#define CONNECTION_H

#include <boost/asio.hpp>

class Connection {
public:
    typedef boost::shared_ptr<Connection> pointer;

    static pointer create(boost::asio::io_service& io_service);
    boost::asio::ip::tcp::socket& socket();
    void start();
};

#endif // CONNECTION_H

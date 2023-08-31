#include "server.h"
#include "connection.h"

Server::Server(boost::asio::io_service& io_service, int port)
    : acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {
    startAccept();
}

void Server::startAccept() {
    Connection::pointer new_connection = Connection::create(acceptor_.get_io_service());

    acceptor_.async_accept(new_connection->socket(),
        boost::bind(&Server::handleAccept, this, new_connection,
        boost::asio::placeholders::error));
}

void Server::handleAccept(Connection::pointer new_connection, const boost::system::error_code& error) {
    if (!error) {
        new_connection->start();
    }

    startAccept();
}

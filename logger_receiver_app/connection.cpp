#include "connection.h"

Connection::pointer Connection::create(boost::asio::io_service& io_service) {
    return pointer(new Connection(io_service));
}

boost::asio::ip::tcp::socket& Connection::socket() {
    return socket_;
}

void Connection::start() {
    auto self(shared_from_this());  
    boost::asio::async_read_until(socket_, buffer_, '\n',
        [this, self](const boost::system::error_code& ec, std::size_t length) {
            if (!ec)
             {
                std::istream stream(&buffer_);
                std::string message;
                std::getline(stream, message);  // Because we read until '\n'
                std::cout << "Received: " << message << std::endl;  // Log the message

                // Continue reading from the socket
                start();
            }
        });
}

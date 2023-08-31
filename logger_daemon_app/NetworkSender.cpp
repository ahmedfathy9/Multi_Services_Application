#include <boost/asio.hpp>

boost::asio::io_service io_service;
boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(192.168.1.11), 22);  
boost::asio::ip::tcp::socket socket(io_service);
socket.connect(endpoint);

void send_log(const std::string& message) {
 boost::asio::write(socket, boost::asio::buffer(message + "\n"));
}

#include "receiver.h"
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <stdexcept>
#include <syslog.h>
#include <iostream>
#include <vector>

Receiver::Receiver(const std::string& queue_name) : queue_name(queue_name) {
    mq = mq_open(this->queue_name.c_str(), O_RDONLY);
    if (mq == (mqd_t)-1) {
        throw std::runtime_error(std::strerror(errno));
    }
    if (mq_getattr(mq, &attr) == -1) {
        throw std::runtime_error(std::strerror(errno));
    }
}

Receiver::~Receiver() {
    if (mq_close(mq) == -1) {
        std::cerr << "Failed to close message queue: " << std::strerror(errno) << std::endl;
    }
}

std::string Receiver::receive(bool blocking) {
    std::vector<char> buffer(attr.mq_msgsize);
    ssize_t nbytes;
    if (blocking) {
        nbytes = mq_receive(mq, buffer.data(), buffer.size(), NULL);
    } else {
        mqd_t non_blocking_mq = mq_open(queue_name.c_str(), O_RDONLY | O_NONBLOCK);
        nbytes = mq_receive(non_blocking_mq, buffer.data(), buffer.size(), NULL);
        mq_close(non_blocking_mq);
    }
    if (nbytes == -1) {
        std::cerr << "Failed to receive message: " << std::strerror(errno) << std::endl;
        return "";
    }
    return std::string(buffer.data(), nbytes);
}

#include "sender.h"
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <stdexcept>
#include <syslog.h>
#include <iostream>
#include <cstring>           /* Needed for std::strerror */
#include <mqueue.h> 

Sender::Sender(const char* queue_name) {
    mq = mq_open(queue_name, O_WRONLY);
    if (mq == (mqd_t)-1) {
        throw std::runtime_error(std::strerror(errno));
    }
}

Sender::~Sender() {
    if (mq_close(mq) == -1) {
        std::cerr << "Failed to close message queue: " << std::strerror(errno) << std::endl;
    }
}

bool Sender::send(const std::string& message) {
    if (mq_send(mq, message.c_str(), message.size(), 0) == -1) {
        std::cerr << "Failed to send message: " << std::strerror(errno) << std::endl;
        return false;
    }
    return true;
}

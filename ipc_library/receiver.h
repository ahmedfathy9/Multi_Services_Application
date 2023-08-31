#ifndef RECEIVER_H
#define RECEIVER_H

#include <string>
#include <mqueue.h>
#include <cstring>

class Receiver {
private:
    mqd_t mq;
    mq_attr attr;
    std::string queue_name;
public:
    Receiver(const std::string& queue_name);
    ~Receiver();
    std::string receive(bool blocking);
};

#endif // RECEIVER_H

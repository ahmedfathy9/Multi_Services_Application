#ifndef SENDER_H
#define SENDER_H

#include <string>
#include <mqueue.h>
#include <cstring>

class Sender {
private:
    mqd_t mq;
public:
    Sender(const char* queue_name);
    ~Sender();
    bool send(const std::string& message);
};

#endif // SENDER_H

#include "receiver.h"
#include <iostream>

int main() {
    Receiver receiver("received_queue"); 
    std::string message = receiver.receive(0);
    std::cout << "Received: " << message << std::endl;
    return 0;
}

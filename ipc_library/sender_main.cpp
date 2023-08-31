#include "sender.h"
#include <iostream>

int main() {
    Sender sender("sent_queue_for_testing");
    sender.send("Hello, world!");
    
    return 0;
}

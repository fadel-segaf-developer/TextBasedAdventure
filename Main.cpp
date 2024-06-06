#include "Main.h"
#include <iostream>
#include <thread>


void init()
{

}

void update()
{

}

int main() {
    //Main loop
    init();
    
    while (true) {
        update();
        // Optional: Sleep for a short duration to prevent maxing out the CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }



    return 0;
}
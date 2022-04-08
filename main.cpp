#include "graphics.h"
#include <iostream>


int main() {
    Graphics graphics;
    try {
        graphics.draw();
    }
    catch (const MyException& exception){
        std::cerr<<exception.get_error()<<"\n";
    }
    return 0;
}
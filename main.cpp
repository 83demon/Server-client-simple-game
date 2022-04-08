#include "sockets.h"
#include "calculator.h"
#include <iostream>

int milliseconds = 20;


int main() {
    try {
        Socket socket;
        Calculator calculator;
        bool first_start = true;
        calculator.init();
        socket.init();
        socket.listen();
        socket.accept();
        int command = socket.receive(milliseconds);
        while(command==-1){command = socket.receive(milliseconds);}
        do{
            std::vector<float> temp_calc;
            command = socket.receive(milliseconds);
            if(command!=-1){calculator.set_last_command(command);}
            temp_calc = calculator.calculate();
            sf::Packet to_sent;
            to_sent << 4 << temp_calc[0] << temp_calc[1] << temp_calc[2] << temp_calc[3];
            socket.send(to_sent);
        }
        while (!calculator.win());
        sf::Packet res;
        res << 295888;
        socket.send(res);
        socket.disconnect();
    }
    catch (const MyException& exception){
        std::cerr<<exception.get_error()<<"\n";
    }
    return 0;
}

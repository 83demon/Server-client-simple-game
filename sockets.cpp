//
// Created by vo1 on 07.12.20.
//

#include "sockets.h"

void Socket::listen() {
    std::cout << "Binding..." << std::endl;
    status = listener.listen(port);
    if (status != sf::Socket::Done)  {
        throw MyException("Listening failed");
    }
    std::cout << "Listen OK." << std::endl;
}

void Socket::accept() {
    std::cout << "Waiting for connection..." << std::endl;
    status = listener.accept(socket);
    if (status != sf::Socket::Done)
    {
        throw MyException("Accepting error");
    }
    std::cout << "Connection accepted." << std::endl;
    selector.add(socket);
}

void Socket::send(sf::Packet packet) {
    status = socket.send(packet);
    if(status!=sf::Socket::Done){
        throw MyException("Sending error");
    }
}

void Socket::init() {
    Reader reader;
    std::pair<int,std::string> temp = reader.read();
    address = temp.second;
    port = temp.first;
}

void Socket::disconnect() {
    socket.disconnect();
}

int Socket::receive(int milliseconds) {
    int command_number = -1;
    if(selector.wait(sf::milliseconds(milliseconds))){
        status = socket.receive(received_data);
        if(status!=sf::Socket::Done && status!=sf::Socket::Disconnected){
            throw MyException("Receiving error");
        }
        received_data >> command_number;
    }
    return command_number;
}

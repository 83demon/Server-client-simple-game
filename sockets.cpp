//
// Created by vo1 on 07.12.20.
//

#include "sockets.h"

void Socket::init() {
    Reader reader;
    std::pair<int,std::string> temp = reader.read();
    address = temp.second;
    port = temp.first;
}

void Socket::connect() {
    status = socket.connect(address, port);
    if (status != sf::Socket::Done)
    {
        throw MyException("Connecting error");
    }
    selector.add(socket);
}

std::vector<float> Socket::receive(int milliseconds) {
    if(selector.wait(sf::milliseconds(milliseconds))){
        status = socket.receive(received_data);
        if(status!=sf::Socket::Done && status!=sf::Socket::Disconnected){
            throw MyException("Receiving error");
        }
    }
    float n, hunter_x, hunter_y, victim_x, victim_y;
    received_data >> n >> hunter_x >> hunter_y >> victim_x >> victim_y;
    std::vector<float> res = {n,hunter_x,hunter_y,victim_x,victim_y};
    return res;
}

void Socket::send() {
    status = socket.send(data);
    if(status!=sf::Socket::Done){
        throw MyException("Sending error");
    }
}

void Socket::disconnect() {
    socket.disconnect();
}

void Socket::set_data(sf::Packet &data_) {
    data = data_;
}

//
// Created by vo1 on 07.12.20.
//

#pragma once
#include "SFML/Network.hpp"
#include "/common/exception.h"
#include "/common/point.h"
#include "/common/reader.h"
#include <string>
class Socket{
    std::string address;
    int port;
    sf::TcpSocket socket;
    sf::Packet data, received_data;
    sf::SocketSelector selector;
    sf::Socket::Status status;
public:
    void set_data(sf::Packet &data);
    void init();
    void connect();
    void send();
    std::vector<float> receive(int milliseconds);
    void disconnect();
};
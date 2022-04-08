//
// Created by vo1 on 07.12.20.
//

#pragma once
#include "SFML/Network.hpp"
#include "/point.h"
#include "/common/exception.h"
#include "/common/reader.h"
#include <iostream>
class Socket{
    std::string address;
    sf::TcpListener listener;
    int port;
    sf::Socket::Status status;
    sf::TcpSocket socket;
    sf::SocketSelector selector;
    sf::Packet data, received_data;
public:
    void init();
    void listen();
    void accept();
    void send(sf::Packet packet);
    int receive(int milliseconds);
    void disconnect();
};

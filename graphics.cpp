//
// Created by vo1 on 07.12.20.
//

#include "graphics.h"

void Graphics::draw() {
    init();
    socket.init();
    socket.connect();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::A)||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::S)||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::D)||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    {
                        sf::Packet data;
                        data << event.text.unicode;
                        socket.set_data(data);
                        socket.send();
                    }
                    break;
                default:
                    break;
            }

        }
        temp_received_data = socket.receive(milliseconds);
        if(abs(temp_received_data[0])>=15000){
            std::cout<<"YOU WON!";
            break;//win
        }
        else if(temp_received_data[0]>=0 && temp_received_data[0]<15000){
            hunter.set_position(temp_received_data[1], temp_received_data[2]);
            victim.set_position(temp_received_data[3], temp_received_data[4]);
        }
        else{
            throw  MyException("Inappropriate values received");
        }
        window.clear();
        hunter.draw(window);
        victim.draw(window);
        window.display();
    }
    socket.disconnect();
}

void Graphics::init() {
    window.create(sf::VideoMode(width, height), "Client is running!");
    hunter.set_color(hunter_color);
    hunter.set_radius(hunter_radius);
    victim.set_radius(victim_radius);
    victim.set_color(victim_color);
}


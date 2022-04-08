//
// Created by vo1 on 07.12.20.
//

#pragma once
#include "SFML/Graphics.hpp"
#include "sockets.h"
#include "/common/point.h"
class Graphics{
    Socket socket;
    sf::RenderWindow window;
    const int height = 600, width = 1300;
    int milliseconds = 20;
    std::vector<float> temp_received_data;
    Point hunter, victim;
    float hunter_radius = 30, victim_radius = 15;
    sf::Color hunter_color = sf::Color::Yellow, victim_color = sf::Color::White;
public:
    void init();
    void draw();
};

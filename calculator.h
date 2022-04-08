//
// Created by vo1 on 08.12.20.
//

#pragma once
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include "/home/vo1/Documents/Навчання/2 course/OOP/OOP/server_client/common/point.h"
#include "/home/vo1/Documents/Навчання/2 course/OOP/OOP/server_client/common/exception.h"
#include <cmath>
class Calculator{
    int width = 1300, height = 600;
    int last_command;
    Point hunter;
    Point victim;
    float hunter_radius = 30, victim_radius = 10;
    sf::Color hunter_color = sf::Color::Yellow, victim_color = sf::Color::White;
    float hunter_speed=5, victim_speed=3.5;
    bool victim_bumped = false, victim_bumped1 = false;
    void victim_retreat();
    void bumps();
    float distance(float x1,float y1,float x2, float y2);
    void bumps_for_victim();
    static bool sortByVal(std::pair<int, float> &a, std::pair<int, float> &b);
public:
    void set_last_command(int command_);
    void init();
    void commands_control();
    bool win();
    std::vector<float> calculate();
};

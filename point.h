//
// Created by vo1 on 07.12.20.
//

#pragma once
#include "SFML/Graphics.hpp"
class Point{
    float x,y;
    float radius;
    sf::Color color;
public:
    Point(){};
    Point(float a, float b, float r, sf::Color input_color){x=a,y=b,radius=r,color=input_color;}
    void set_position(float a, float b){
        x=a;
        y=b;
    }
    void set_color(sf::Color color_){
        color = color_;
    }
    void set_radius(float radius_){
        radius = radius_;
    }
    void draw(sf::RenderWindow &window){
        sf::CircleShape shape(radius);
        shape.setFillColor(color);
        shape.setPosition(x,y);
        window.draw(shape);
    }
    bool contains(float x_, float y_){
        sf::CircleShape shape(radius);
        shape.setPosition(x,y);
        return shape.getGlobalBounds().contains(sf::Vector2f(x_,y_));
    }
    float get_x(){
        return x;
    }
    float get_y(){
        return y;
    }
};

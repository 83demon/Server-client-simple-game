//
// Created by vo1 on 08.12.20.
//

#include "calculator.h"

std::vector<float> Calculator::calculate() {
    commands_control();
    bumps();
    victim_retreat();
    bumps_for_victim();
    std::vector<float> res = {hunter.get_x(),hunter.get_y(),victim.get_x(),victim.get_y()};
    return res;
}

bool Calculator::win() {
    return hunter.contains(victim.get_x()+victim_radius, victim.get_y()+victim_radius);
}

void Calculator::init() {
    hunter.set_radius(hunter_radius);
    hunter.set_color(hunter_color);
    hunter.set_position(1000,100);
    victim.set_radius(victim_radius);
    victim.set_color(victim_color);
    victim.set_position(300,200);
}

void Calculator::set_last_command(int command_) {
    last_command = command_;
}

void Calculator::commands_control() {
    if(last_command==3){
        hunter.set_position(hunter.get_x()+hunter_speed,hunter.get_y());
    }
    else if(last_command==22){
        hunter.set_position(hunter.get_x(),hunter.get_y()-hunter_speed);
    }
    else if(last_command==0){
        hunter.set_position(hunter.get_x()-hunter_speed,hunter.get_y());
    }
    else if(last_command==18){
        hunter.set_position(hunter.get_x(),hunter.get_y()+hunter_speed);
    }
    else if(last_command==57){}
}

void Calculator::bumps() {
   if(0>=hunter.get_x()-hunter_speed){last_command=3;}
   else if(0>=hunter.get_y()-hunter_speed){last_command=18;}
   else if(hunter.get_x()+hunter_speed+2*hunter_radius>=width){last_command=0;}
   else if(hunter.get_y()+hunter_speed+2*hunter_radius>=height){last_command=22;}
}

void Calculator::victim_retreat() {
    float x = hunter.get_x()+hunter_radius, y = hunter.get_y()+hunter_radius;
    float max_dist = -INFINITY;
    int index;
    std::vector<std::pair<int,float>> distances;
    max_dist = distance(x,y,victim.get_x()+victim_speed,victim.get_y());
    distances.emplace_back(0,max_dist);

    max_dist = distance(x,y,victim.get_x(),victim.get_y()+victim_speed);
    distances.emplace_back(1,max_dist);

    max_dist = distance(x,y,victim.get_x()-victim_speed,victim.get_y());
    distances.emplace_back(2,max_dist);

    max_dist = distance(x,y,victim.get_x(),victim.get_y()-victim_speed);
    distances.emplace_back(3,max_dist);

    std::sort(distances.begin(),distances.end(),sortByVal);

    if(victim_bumped){
        if(victim_bumped1){
            index=distances[1].first;
        }
        else{
            index=distances[2].first;
        }
        victim_bumped1=victim_bumped= false;
    }
    else{
        index=distances.back().first;
    }
    if(index==0){victim.set_position(victim.get_x()+victim_speed,victim.get_y());}
    else if(index==1){victim.set_position(victim.get_x(),victim.get_y()+victim_speed);}
    else if(index==2){victim.set_position(victim.get_x()-victim_speed,victim.get_y());}
    else if(index==3){victim.set_position(victim.get_x(),victim.get_y()-victim_speed);}



}

float Calculator::distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}

void Calculator::bumps_for_victim() {
    if(0>=victim.get_x()-victim_speed){
        victim.set_position(victim.get_x()+victim_speed,victim.get_y());
        victim_bumped = true;
    }
    if(0>=victim.get_y()-victim_speed){
        victim.set_position(victim.get_x(),victim.get_y()+victim_speed);
        victim_bumped = true;
    }
    if(0>=victim.get_x()-victim_speed && 0>=victim.get_y()-victim_speed){
        victim_bumped1 = true;
    }
    if(victim.get_x()+victim_speed+2*victim_radius>=width){
        victim.set_position(victim.get_x()-victim_speed,victim.get_y());
        victim_bumped = true;
    }
    if(victim.get_y()+victim_speed+2*victim_radius>=height){
        victim.set_position(victim.get_x(),victim.get_y()-victim_speed);
        victim_bumped = true;
    }
    if(victim.get_x()+victim_speed+2*victim_radius>=width &&
    victim.get_y()+victim_speed+2*victim_radius>=height){
        victim_bumped1=true;
    }
}

bool Calculator::sortByVal(std::pair<int, float> &a, std::pair<int, float> &b) {
    return (a.second < b.second);
}


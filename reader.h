//
// Created by vo1 on 08.12.20.
//

#pragma once
#include <string>
#include <fstream>
class Reader{
public:
    std::pair<int, std::string> read(){
        std::vector<Point> res;
        std::ifstream file("/home/vo1/Documents/Навчання/2 course/OOP/OOP/server_client/common/params.txt");
        int a;
        std::string b;
        file >> a >> b;
        file.close();
        return std::make_pair(a,b);
    }
};

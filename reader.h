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
        std::ifstream file("/common/params.txt");
        int a;
        std::string b;
        file >> a >> b;
        file.close();
        return std::make_pair(a,b);
    }
};

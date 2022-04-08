//
// Created by vo1 on 07.12.20.
//

#pragma once
#include <exception>
#include <string>
#include <iostream>
class MyException : public std::exception
{
    std::string error_msg;
public:
    MyException(const char* err) : std::exception() {
        error_msg = err;
    }
    std::string get_error() const {
        return error_msg;
    }
};

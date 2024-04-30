// util.cpp

#include "util.hpp"

uuid generate_uuid() {
    auto gen = random_generator();
    return gen();
}

bool is_alpha(const string& str) {
    for (char c: str) {
        if(!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

bool is_num(const string& str) {
    for (char c: str) {
        if(!isdigit(c)) {
            return false;
        }
    }
    return true;
}
// util.cpp

#include "util.hpp"

uuid generate_uuid() {
    auto gen = random_generator();
    return gen();
}
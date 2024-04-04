// library.cpp

#include "library.hpp"
using namespace std;

Library::Library() : name("empty"), year(0) {}

Library& Library::get_instance() {
   static Library instance;
   return instance;
}

void Library::set_name(const std::string& name) {
   this->name = name;
}

void Library::set_year(unsigned short year) {
   this->year = year;
}

void Library::display() const {
   std::cout << "Library Information:" << std::endl;
   std::cout << setfill('.') << setw(10) << "Name: " << name << std::endl;
   std::cout << setfill('.') << setw(10) << "Year: " << year << std::endl;
}

const std::string& Library::get_name() const {
   return name;
}

const short Library::get_year() const {
   return year;
}

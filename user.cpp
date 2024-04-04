// user.cpp

#include "user.hpp"
#include "util.hpp"
using namespace std;

User::User(const string& name, unsigned short age) : name(name), age(age) {
    id = generate_uuid();
    premium = false;
}

void User::display() const {
   std::cout << "User Information:" << std::endl;
   std::cout << setfill('.') << setw(13) << "Name: " << name << std::endl;
   std::cout << setfill('.') << setw(13) << "ID: " << id << std::endl;
   std::cout << setfill('.') << setw(13) << "Age: " << age << std::endl;
   std::cout << boolalpha << setfill('.') << setw(13) << "Premium: " << premium << std::endl;
}
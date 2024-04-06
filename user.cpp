// user.cpp

#include "user.hpp"
#include "util.hpp"
using namespace std;

/**
 * Constructor for the User class.
 * @param[in] name The name of the user.
 * @param[in] age The age of the user.
 */
User::User(const string& name, unsigned short age) : name(name), age(age) {
    if( name == "null"  && age == 0) {
        return;
    }
    id = generate_uuid();
    premium = false;
}

/**
 * Print out the user information.
 */
void User::display() const {
   std::cout << "User Information:" << std::endl;
   std::cout << setfill('.') << setw(13) << "Name: " << name << std::endl;
   std::cout << setfill('.') << setw(13) << "ID: " << id << std::endl;
   std::cout << setfill('.') << setw(13) << "Age: " << age << std::endl;
   std::cout << boolalpha << setfill('.') << setw(13) << "Premium: " << premium << std::endl;
}

/**
 * Get the ID of the user.
 * @return The ID of the user.
*/
const uuid User::get_id() const {
    return id;
}

/**
 * Set the premium status of the user.
 * @param[in] premium True if the user is premium, false otherwise.
 */
void User::set_premium(bool premium) {
    this->premium = premium;
}

/**
 * Set the name of the user.
 * @param[in] name The name of the user.
*/
void User::set_name(const std::string& name) {
    this->name = name;
}

/**
 * Set the age of the user.
 * @param[in] age The age of the user.
*/
void User::set_age(unsigned short age) {
    this->age = age;
}

/**
 * Get the premium status of the user.
 * @return True if the user is premium, false otherwise.
*/
const bool User::get_premium() const {
    return premium;
}

/**
 * Get the name of the user.
 * @return The name of the user.
*/
const std::string User::get_name() const {
    return name;
}

/**
 * Get the age of the user.
 * @return The age of the user.
*/
const unsigned short User::get_age() const {
    return age;
}
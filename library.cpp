// library.cpp

#include "library.hpp"
using namespace std;
using namespace boost::uuids;

/**
 * Constructor for the Library class.
*/
Library::Library() : name("empty"), established_year(0, "AD") {}

/**
 * Static instance of the empty User class.
*/
User Library::empty_user("null", 0);

/**
 * Singleton instance of the Library class.
 * @return Library& - Reference to the Library instance.
*/
Library& 
Library::get_instance() {
   static Library instance;
   return instance;
}

/**
 * Set the name of the Library.
 * @param name Name of the Library.
*/
void 
Library::set_name(const string& name) {
   this->name = name;
}

/**
 * Set the year of the Library.
 * @param[in] year Year of the Library.
*/
void 
Library::set_year(unsigned short year, std::string era) {
   this->established_year.first = year;
   this->established_year.second = era;
}

/**
 * Print out the library information.
*/
void 
Library::display() const {
   cout << "Library Information:" << endl;
   cout << setfill('.') << setw(10) << "Name: " << name << endl;
   cout << setfill('.') << setw(10) << "Year: " << this->established_year.first << " " << this->established_year.second << endl;
}

/**
 * Print out the users in the library.
*/
void 
Library::display_users() const {
   cout << "USERS:" << endl;
   size_t length = 0;
   for (auto it = users.begin(); it != users.end(); ++it) {
      length = to_string((*it)->get_id()).length();
      cout << "+" << std::string(length + 14, '-') << "+" << endl;
      cout << "|" << setw(10) << setfill(' ') << "Name: " << (*it)->get_name();
      cout << setw(to_string((*it)->get_id()).length() - (*it)->get_name().length() + 5) << setfill(' ') << "|" << endl;
      cout << "|" << setw(10) << setfill(' ') << "Age: " << (*it)->get_age();
      cout << setw(to_string((*it)->get_id()).length() - to_string((*it)->get_age()).length() + 5) << setfill(' ') << "|" << endl;
      cout << "|" << setw(10) << setfill(' ') << "UUID: " << to_string((*it)->get_id());
      cout << setw(5) << setfill(' ') << "|" << endl;

   }
   cout << "+" << std::string(length + 14, '-') << "+" << endl;
}

/**
 * Get the name of the Library.
 * @return The name of the Library.
*/
const std::string& 
Library::get_name() const {
   return name;
}

/**
 * Get the year of the Library.
 * @return The year of the Library.
*/
const std::pair<unsigned short, std::string> 
Library::get_established_year() const {
   return established_year;
}

/**
 * Add a user to the Library.
 * @param[in] user User to add to the Library.
*/
void 
Library::add_user(User* user) {
   users.push_back(user);
}

/**
 * Delete a user from the Library.
 * @param[in] user User to delete from the Library.
*/
void 
Library::delete_user(User* user) {
   for (auto it = users.begin(); it != users.end(); ++it) {
      if (*it == user) {
         users.erase(it);
         cout << "User \"" << user->get_name() << "\" deleted from Library's database." << endl;
         break;
      }
   }
}

/**
 * Delete a user from the Library.
 * @param[in] name Name of the user to delete from the Library.
*/
void 
Library::delete_user(const std::string& name) {
   for (auto it = users.begin(); it != users.end(); ++it) {
      if ((*it)->get_name() == name) {
         users.erase(it);
         cout << "User \"" << (*it)->get_name() << "\" deleted from Library's database." << endl;
         break;
      }
   }
}

/**
 * Delete a user from the Library.
 * @param[in] id UUID of the user to delete from the Library.
*/
void 
Library::delete_user(const boost::uuids::uuid& id) {
   for (auto it = users.begin(); it != users.end(); ++it) {
      if ((*it)->get_id() == id) {
         users.erase(it);
         cout << "User \"" << (*it)->get_name() << "\" deleted from Library's database." << endl;
         break;
      }
   }
}

/**
 * Find a user in the Library.
 * @param[in] user User to find in the Library.
*/
User&
Library::find_user(User* user) const {
   for (auto it = users.begin(); it != users.end(); ++it) {
      if (*it == user) {
         cout << "User \"" << (*it)->get_name() << "\" found in the Library's database." << endl;
         return **it;
      }
   }
   return empty_user;
}

/**
 * Find a user in the Library.
 * @param[in] name Name of the user to find in the Library.
*/
User& 
Library::find_user(const std::string& name) const {
   for (auto it = users.begin(); it != users.end(); ++it) {
      if((*it)->get_name() == name) {
         cout << "User \"" << (*it)->get_name() << "\" found in the Library's database." << endl;
         return **it;
      }
   }
   return empty_user;
}

/**
 * Find a user in the Library.
 * @param[in] id UUID of the user to find in the Library.
*/
User& 
Library::find_user(const boost::uuids::uuid& id) const {
   for (auto it = users.begin(); it != users.end(); ++it) {
      if((*it)->get_id() == id) {
         cout << "User \"" << (*it)->get_name() << "\" found in the Library's database." << endl;
         return **it;
      }
   }
   return empty_user;
}
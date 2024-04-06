#ifndef _LIBRARY_HPP
#define _LIBRARY_HPP

#include "user.hpp"
#include <bits/stdc++.h>
#include <boost/uuid/uuid_io.hpp>

// Singleton
class Library {
public:
   static Library& get_instance();

   // Print
   void display() const;
   void display_users() const;

   // Setters
   void set_name(const std::string& name);
   void set_year(unsigned short year, std::string era);

   // Getters
   const std::vector<User*>& get_users() const;
   const std::string& get_name() const;
   const std::pair<unsigned short, std::string> get_established_year() const;

   // Add
   void add_user(User* user);

   // Delete
   void delete_user(User* user);
   void delete_user(const std::string& name);
   void delete_user(const boost::uuids::uuid& id);

   // Find
   User& find_user(User* user) const;
   User& find_user(const std::string& name) const;
   User& find_user(const boost::uuids::uuid& id) const;
private:
   Library();
   ~Library() = default;
   Library(const Library&) = delete;
   Library& operator=(const Library&) = delete;

   std::string name;
   std::pair<unsigned short, std::string> established_year;

   std::vector<User*> users;
   static User empty_user;
   //vector<Books*> books;
};

#endif
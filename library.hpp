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
   void set_year(unsigned short year);

   // Getters
   const std::vector<User*>& get_users() const;
   const std::string& get_name() const;
   const short get_year() const;

   void add_user(User* user);

   void delete_user(User* user);
   void delete_user(const std::string& name);
   void delete_user(const boost::uuids::uuid& id);
private:
   Library();
   ~Library() = default;
   Library(const Library&) = delete;
   Library& operator=(const Library&) = delete;

   std::string name;
   unsigned short year;

   std::vector<User*> users;
   //vector<Books*> books;
};

#endif
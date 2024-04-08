#ifndef _USER_HPP
#define _USER_HPP

#include <bits/stdc++.h>
#include <boost/uuid/uuid.hpp>
using namespace boost::uuids;

class User {
public:
   User(const std::string& name, unsigned short age);
   ~User() = default;

   // Print
   void display() const;

   // Setters
   void set_premium(bool premium);
   void set_name(const std::string& name);
   void set_age(unsigned short age);

   // Getters
   const boost::uuids::uuid get_id() const;
   bool get_premium() const;
   std::string get_name() const;
   unsigned short get_age() const;

private:
   std::string name;
   uuid id;
   unsigned short age;
   bool premium;
};

#endif
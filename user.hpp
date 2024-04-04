#ifndef _USER_HPP
#define _USER_HPP

#include <bits/stdc++.h>
#include <boost/uuid/uuid.hpp>
using namespace boost::uuids;

class User {
public:
   User(const std::string& name, unsigned short age);
   ~User() = default;

   void display() const;
private:
   std::string name;
   uuid id;
   unsigned short age;
   bool premium;
};

#endif
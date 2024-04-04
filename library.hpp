#ifndef _LIBRARY_HPP
#define _LIBRARY_HPP

#include <bits/stdc++.h>

// Singleton
class Library {
public:
   static Library& get_instance();

   void set_name(const std::string& name);
   void set_year(unsigned short year);

   void display() const;

   const std::string& get_name() const;
   const short get_year() const;
private:
   Library();
   ~Library() = default;
   Library(const Library&) = delete;
   Library& operator=(const Library&) = delete;

   std::string name;
   unsigned short year;

   //vector<Users*> users;
   //vector<Books*> books;
};

#endif
#ifndef _BOOK_HPP
#define _BOOK_HPP

#include "user.hpp"
#include <bits/stdc++.h>

class Book {
public:
   Book(
         const std::string& title, 
         const std::list<std::string>& authors, 
         unsigned short page_count, 
         const std::pair<unsigned short, 
         std::string>& publication
      );

   Book(
         const std::string& title, 
         const std::list<std::string>& authors, 
         unsigned short page_count, 
         const std::string& publication
      );

   ~Book() = default;

   void display() const;
   void rent_to(User* user);
   User* get_current_user() const;
   unsigned short get_current_page() const;
private:
   std::string _title;
   std::list<std::string> _authors;
   unsigned short _page_count;
   std::pair<unsigned short, std::string> _pair_publication_year;
   std::string _publication_year;

   User* _current_user = nullptr;
   unsigned short _current_page = 0;
};

#endif
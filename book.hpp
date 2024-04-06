#ifndef _BOOK_HPP
#define _BOOK_HPP

#include <bits/stdc++.h>

class Book {
public:
   Book(const std::string& title, const std::list<std::string>& authors, const std::pair<unsigned short, std::string>& publication);
   Book(const std::string& title, const std::list<std::string>& authors, const std::string& publication);
   ~Book() = default;

   void display() const;

private:
   std::string _title;
   std::list<std::string> _authors;
   std::pair<unsigned short, std::string> _pair_publication_year;
   std::string _publication_year;
};

#endif
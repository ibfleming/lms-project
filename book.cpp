// book.cpp

#include "book.hpp"
using namespace std;

/**
 * Constructor for the Book class.
 * @param[in] title The title of the book.
 * @param[in] authors The authors of the book.
 * @param[in] publication_year The publication year of the book.
*/

Book::Book(const string& title, const list<string>& authors, const pair<unsigned short, string>& publication) : _title(title), _authors(authors), _pair_publication_year(publication) {
   _publication_year.clear();
}

Book::Book(const string& title, const list<string>& authors, const string& publication) : _title(title), _authors(authors), _publication_year(publication) {
   _pair_publication_year.first = 0;
   _pair_publication_year.second = "null";
}

/**
 * Print out the book information.
*/
void
Book::display() const {
   cout << "Book Information:" << endl;
   cout << setfill('.') << setw(22) << "Title: " << "\"" << _title << "\"" << endl;
   cout << setfill('.') << setw(22) << "Author(s): ";
   for(const auto& author : _authors) {
      if(author == _authors.back()) {
         cout << "\"" << author << "\"";
         break;
      } else {
         cout << "\"" << author << "\"" << ", ";
      }
   }
   cout << endl;

   if(_publication_year.empty()) {
      cout << setfill('.') << setw(22) << "Publication Year: " << _pair_publication_year.first << " " << _pair_publication_year.second << endl;
   } else {
      cout << setfill('.') << setw(22) << "Publication Year: " << _publication_year << endl;
   }
}
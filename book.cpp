// book.cpp

#include "book.hpp"
using namespace std;

/**
 * Constructor for the Book class.
 * @param[in] title The title of the book.
 * @param[in] authors The authors of the book.
 * @param[in] publication_year The publication year of the book.
*/

Book::Book(const string& title, const list<string>& authors, unsigned short page_count, const pair<unsigned short, string>& publication) 
   : _title(title), _authors(authors), _page_count(page_count), _pair_publication_year(publication) {
   _publication_year.clear();
}

Book::Book(const string& title, const list<string>& authors, unsigned short page_count, const string& publication) 
   : _title(title), _authors(authors), _page_count(page_count), _publication_year(publication) {
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

   cout << setfill('.') << setw(22) << "Page Count: " << _page_count << endl;
   cout << setfill('.') << setw(22) << "Current Page: " << _current_page << endl;
}

/**
 * Rent the book to a user.
 * @param[in] user The user to rent the book to.
*/
void
Book::rent_to(User* user) {
   _current_user = user;
   cout << "\"" << _title << "\"" << " is now rented to " << user->get_name() << "." << endl;
}

/**
 * Get the current user of the book.
*/
void Book::get_current_user() const {
   if(_current_user == nullptr) {
      cout << "No user has rented this book." << endl;
   } else {
      cout << "The current user is " << _current_user->get_name() << "." << endl;
   }
}
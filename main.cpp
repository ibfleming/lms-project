// main.cpp

#include "library.hpp"
#include "user.hpp"
#include "book.hpp"
#include <bits/stdc++.h>
using namespace std;

int main() {

   Library& library = Library::get_instance();

   library.set_name("Library of Alexandria");
   library.set_year(285, "BC");

   cout << endl;
   library.display();
   cout << endl;

   User user1("Jesus Christ", 33);
   User user2("John the Baptist", 35);
   User user3("Mary Magdalene", 30);

   library.add_user(&user1);
   library.add_user(&user2);
   library.add_user(&user3);

   Book book1("The Holy Bible", {"Lord God Almighty", "Jesus Christ"}, 1200, "The Beginning of Time");
   Book book2("The False Quran", {"Muhammad"}, 700, pair(632, "AD/CE"));
   book1.display();
   cout << endl;
   book2.display();

   cout << endl;
   book1.rent_to(&user1);
   cout << endl;

   book1.get_current_user();

   book2.get_current_user();

   return 0;
}
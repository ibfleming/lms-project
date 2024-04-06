// main.cpp

#include "library.hpp"
#include "user.hpp"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {

   Library& library = Library::get_instance();

   library.set_name("Library of Congress");
   library.set_year(1800);

   cout << endl;
   library.display();

   User user1("Jesus Christ", 33);
   User user2("John the Baptist", 35);
   User user3("Mary Magdalene", 30);

   library.add_user(&user1);
   library.add_user(&user2);
   library.add_user(&user3);

   cout << endl;
   library.display_users();
   cout << endl;

   library.delete_user(user3.get_id());

   cout << endl;
   library.display_users();
   cout << endl;

   return 0;
}
// main.cpp

#include "library.hpp"
#include "user.hpp"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {

   Library& library = Library::get_instance();

   library.set_name("Library of Congress");
   library.set_year(1800);

   library.display();

   User user("John Doe", 25);
   user.display();

   return 0;
}
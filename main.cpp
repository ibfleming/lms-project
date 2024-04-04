// main.cpp

#include "library.hpp"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {

   Library& library = Library::get_instance();

   library.set_name("Library of Congress");
   library.set_year(1800);

   library.display();

   return 0;
}
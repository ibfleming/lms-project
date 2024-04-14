// main.cpp

#include "library.hpp"
#include "user.hpp"
#include "book.hpp"
#include <bits/stdc++.h>
using namespace std;

void display_hud();

int main() {

   /*

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
   
   */

   cout << endl;
   display_hud();
   bool running = true;
   while(running) {
      cout << endl;
      cout << "> ";
      char command;
      cin >> command;
      cout << endl;
      switch(command) {
         case '0':
            cout << "Creating custom library..." << endl;
            break;
         case '1':
            cout << "Creating premade library..." << endl;
            break;
         case '2':
            cout << "Creating custom user..." << endl;
            break;
         case '3':
            cout << "Creating premade user..." << endl;
            break;
         case '4':
            cout << "Displaying library info..." << endl;
            break;
         case '5':
            cout << "Displaying user info..." << endl;
            break;
         case 'd':
            display_hud();
            break;
         case 'q':
            cout << "Exiting program..." << endl;
            running = false;
            break;
         default:
            cout << "Invalid command." << endl;
            break;
      }
   }
   return 0;
}

void display_hud() {

   #define TAB 4

   size_t ui_width   = 48;
   string ui_title   = "Library Management System";
   string ui_author  = "by Ian Fleming";
   string ui_version = "Version 1.0";

   // Header

   cout << '+' << string(ui_width, '-') << '+' << endl;
   cout << '|' << string((ui_width - ui_title.length()) / 2, ' ') << ui_title << string((ui_width - ui_title.length()) / 2 + 1, ' ') << '|' << endl;
   cout << '|' << string((ui_width - ui_author.length()) / 2 - 1, ' ') << ui_author << string((ui_width - ui_author.length()) / 2 + 1, ' ') << '|' << endl;
   cout << '|' << string((ui_width - ui_version.length()) / 2, ' ') << ui_version << string((ui_width - ui_version.length()) / 2 + 1, ' ') << '|' << endl;
   cout << '|' << string(ui_width, '-') << '|' << endl;\
   cout << '|' << string(ui_width, ' ') << '|' << endl;

   // Body

   string ui_menu[] = {
      "0 - Create custom library",
      "1 - Create premade library",
      "2 - Create custom user",
      "3 - Create premade user",
      "4 - Display library info",
      "5 - Display user info",
      "d - Display this menu",
      "q - Exit program"
   };

    size_t ui_menu_size = sizeof(ui_menu) / sizeof(ui_menu[0]);
    for(size_t i = 0; i < ui_menu_size; i++) {
        cout << '|' << setw(2) << left << string((ui_width - ui_title.length()) / 2, ' ') << setw(ui_width - 11) << left << ui_menu[i] << '|' << endl; // Added 4 spaces for padding
    }

   cout << '|' << string(ui_width, ' ') << '|' << endl;
   cout << '+' << string(ui_width, '-') << '+' << endl;
}
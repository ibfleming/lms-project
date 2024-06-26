// gui.cpp

#include "gui.hpp"
#include "util.hpp"
using namespace std;

#define TAB 4
size_t ui_width = 48;

void display_hud() {

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
      "clear - Clear console",
      "q - Exit program"
   };

    size_t ui_menu_size = sizeof(ui_menu) / sizeof(ui_menu[0]);
    for(size_t i = 0; i < ui_menu_size; i++) {
        cout << '|' << setw(2) << setfill(' ') << left << string((ui_width - ui_title.length()) / 2, ' ') << setw(ui_width - 11) << left << ui_menu[i] << '|' << endl; // Added 4 spaces for padding
    }

   cout << '|' << string(ui_width, ' ') << '|' << endl;
   cout << '+' << string(ui_width, '-') << '+' << endl;
}

Library* display_library_menu(bool custom) {

   string ui_title = "Library Creation Menu";

    cout << '+' << string(ui_width, '-') << '+' << endl;
    cout << '|' << string((ui_width - ui_title.length()) / 2, ' ') << ui_title << string((ui_width - ui_title.length()) / 2 + 1, ' ') << '|' << endl;
    cout << '+' << string(ui_width, '-') << '+' << endl;

   Library& library = Library::get_instance();

   if(custom) {

      string name;
      string year_input;
      unsigned short year;
      string era;

      cout << "Enter library name: ";
      cin.ignore();
      getline(cin, name);

      if( !is_alpha(name) ) {
         cout << "Invalid library name." << endl;
         return nullptr;
      }

      cout << "Enter library year: ";
      getline(cin, year_input);

      if( !is_num(year_input) ) {
         cout << "Invalid library year." << endl;
         return nullptr;
      }

      stringstream(year_input) >> year;

      cout << "Enter library era (AD or BC only): ";
      getline(cin, era);

      // Set values
      library.set_name(name);
      library.set_year(year, era);

      cout << endl;
      library.display();

      return &library;
   } else {
      
      library.set_name("Library of Alexandria");
      library.set_year(285, "BC");

      library.display();

      return &library;
   }
}
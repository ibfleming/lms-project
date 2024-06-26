// main.cpp

#include "library.hpp"
#include "user.hpp"
#include "book.hpp"
#include "gui.hpp"
using namespace std;

void display_hud();

int main(void) {

   Library* library = nullptr;

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
   while (running) {
      cout << endl;
      cout << "> ";
      
      string input;
      cin >> input;

      cout << endl;

      if (input.length() == 1) { 
         char command = input[0];
         switch (command) {
               case '0':
                  library = display_library_menu(true);
                  break;
               case '1':
                  library = display_library_menu(false);
                  break;
               case '2':
                  cout << "Creating custom user..." << endl;
                  break;
               case '3':
                  cout << "Creating premade user..." << endl;
                  break;
               case '4':
                  cout << "Displaying library info..." << endl;
                  if (library != nullptr) library->display();
                  else cout << "No library created." << endl;
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
      } else {
         if (input == "clear") {
               // Clear the console
               cout << "\033[2J\033[1;1H";
               display_hud();
         } else {
               cout << "Invalid command." << endl;
         }
      }
   }
   return 0;
}
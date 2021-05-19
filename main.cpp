#include <iostream>
#include <fstream>
#include <vector>

#include "Ticket.h"
#include "app.h"

using namespace std;

int main() {
  std::vector<Ticket> v;
  int sort_option = 1;
  string filter_string = "";

  // read file "data.txt" to fill in vector with actual data
  int result_code = load_data("data.txt", v);
  if (result_code) {
    return result_code;
  }

  bool done = false; // flag to stop the app
  while (!done) {
    int top_menu_option = top_menu();
    
    switch (top_menu_option) {
      case 1:
        dump_table(v, sort_option, filter_string);
        break;
      case 2:
        sort_option = sort_menu();
        break;
      case 3:
        filter_string = filter_menu();
        break;
      case 4:
        sort_option = 1;
        filter_string = "";
        cout << endl << "Sorting and filtering was reseted." << endl;
        break;
      case 5:
        // exit the app
        cout << "Bye!" << endl;
        done = true;
        break;
      case 6:
        // DEBUG: show options
        cout << endl << "Sorting option: " << sort_option;
        cout << ", Filter string: \"" << filter_string << "\"" << endl;
        break;
      default:
        cerr << "Wrong option. Or not yet implemented. Please restart.";
        break;
    }
    
  }

  return 0;
}


#pragma once
#include <iostream>

using namespace std;

int top_menu() {

  int menu_option;
  bool done = false;

  while (!done) {

    // show menu
    cout << "Choose option" << endl;
    cout << "1 - sort, 2 - filter, 3 - reset" << endl;
    cout << "? ";
    cin >> menu_option;

    cout << "SELECTED: " << menu_option << endl;

    if (menu_option >= 1 && menu_option <= 3) {
      done = true;
    } else {
      cout << "Wrong option." << endl;
    }
  }

  return menu_option;
}


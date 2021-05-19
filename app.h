#pragma once
#include <iostream>

using namespace std;

int top_menu() {

  int selected_option;
  bool done = false;

  while (!done) {

    // show menu
    cout << endl;
    cout << "Choose option:" << endl;
    cout << " 1 - sort" << endl;
    cout << " 2 - filter" << endl;
    cout << " 3 - reset" << endl;
    cout << " 4 - exit" << endl;
    cout << " ? ";
    cin >> selected_option;

    // debug
    cout << "SELECTED: " << selected_option << endl;

    if (selected_option >= 1 && selected_option <= 4) {
      done = true;
    } else {
      cout << "Wrong option. Try again." << endl;
    }
  }

  return selected_option;
}

int sort_menu() {

  int selected_option;

  cout << endl;
  cout << "How to sort?" << endl;
  cout << " 1 - by Route No" << endl;
  cout << " 2 - by Point of Departure" << endl;
  cout << " 3 - by Destination" << endl;
  cout << " 4 - by Departure Time" << endl;
  cout << " 5 - by Arrival Time" << endl;
  cout << " 6 - by Price" << endl;
  cout << " ? ";

  bool done = false;
  while(!done) {
    cin >> selected_option;
    if (selected_option >= 1 && selected_option <= 6) {
      done = true;
    } else {
      cout << "Wrong option. Try again." << endl;
    }
  }

  return selected_option;
}

string filter_menu() {

  string filter_string = "";

  cout << endl;
  cout << "Enter a string to search for: ";
  cin >> filter_string;

  return filter_string;
}


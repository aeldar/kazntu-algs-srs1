#pragma once
#include <iostream>

using namespace std;

/**
 * Ask a user about top level options
 */
int top_menu() {

  int selected_option;

  // show menu
  cout << endl;
  cout << "Choose option:" << endl;
  cout << " 1 - print the table" << endl;
  cout << " 2 - sort" << endl;
  cout << " 3 - filter" << endl;
  cout << " 4 - reset" << endl;
  cout << " 5 - exit" << endl;
  cout << " 6 - show active options" << endl;
  cout << " ? ";

  bool done = false;
  while (!done) {
    cin >> selected_option;
    if (selected_option >= 1 && selected_option <= 6) {
      done = true;
    } else {
      cout << "Wrong option. Try again." << endl;
    }
  }

  return selected_option;
}

/**
 * Ask a user about a sorting option
 */
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

/**
 * Ask a user to specify a filter string
 */
string filter_menu() {

  string filter_string = "";

  cout << endl;
  cout << "Enter a string to search for: ";
  cin >> filter_string;

  return filter_string;
}

/**
 * Print the table of tickets
 */
void dump_table(const std::vector<Ticket> v) {
  cout << endl;
  cout << "RouteNo PointOfDeparture DepartureTime Destination ArrivalTime Price" << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}

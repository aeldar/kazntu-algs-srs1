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
  Ticket t;
  ifstream data_file;
  data_file.open("data.txt");
  if (!data_file.is_open()) {
    cerr << "ERROR. Cannot find file 'data.txt'. See README.md for usage details." << endl;
    return 127;
  }
  while(data_file >> t) {
    v.push_back(t);
  }
  data_file.close();

  // dump the content of vector
  cout << "RouteNo PointOfDeparture DepartureTime Destination ArrivalTime Price" << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }

  int top_menu_option = top_menu();
  cout << "selected option: " << top_menu_option << endl;
  
  switch (top_menu_option) {
    case 1:
      sort_option = sort_menu();
      break;
    case 2:
      filter_string = filter_menu();
      break;
    case 3:
      sort_option = 1;
      filter_string = "";
      break;
    case 4:
      // exit the app
      return 0;
    default:
      cerr << "Wrong option. Or not yet implemented. Please restart.";
      break;
  }

  // debug
  cout << "Sorting option: " << sort_option << endl;
  cout << "Filter string: " << filter_string << endl;

  return 0;
}


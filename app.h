#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

std::vector<Ticket> clone_vector(const std::vector<Ticket> &);

//declarations
int top_menu();
int sort_menu();
string filter_menu();

bool compareRouteNo(Ticket, Ticket);
bool comparePointOfDeparture(Ticket, Ticket);
bool compareDestination(Ticket, Ticket);
bool compareDepartureTime(Ticket, Ticket);
bool compareArrivalTime(Ticket, Ticket);
bool comparePrice(Ticket, Ticket);

void sort_tickets(std::vector<Ticket> &, int);
std::vector<Ticket> filter_tickets(std::vector<Ticket> &, string);
void dump_table(const std::vector<Ticket> &, int, string);
std::vector<Ticket> clone_vector(const std::vector<Ticket> &);
int load_data(string, std::vector<Ticket> &);

// --- Implamentation ---

// Ask a user about top level options
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

// Ask a user about a sorting option
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

// Ask a user to specify a filter string
string filter_menu() {

  string filter_string = "";

  cout << endl;
  cout << "Enter a string to search for: ";
  cin >> filter_string;

  return filter_string;
}

// Ticket field compare functions
bool compareRouteNo(Ticket t1, Ticket t2) {
  return t1.get_route_no() < t2.get_route_no();
}
bool comparePointOfDeparture(Ticket t1, Ticket t2) {
  return t1.get_point_of_departure() < t2.get_point_of_departure();
}
bool compareDestination(Ticket t1, Ticket t2) {
  return t1.get_destination() < t2.get_destination();
}
bool compareDepartureTime(Ticket t1, Ticket t2) {
  return t1.get_departure_time() < t2.get_departure_time();
}
bool compareArrivalTime(Ticket t1, Ticket t2) {
  return t1.get_arrival_time() < t2.get_arrival_time();
}
bool comparePrice(Ticket t1, Ticket t2) {
  return t1.get_price() < t2.get_price();
}

// sort tickets vector
void sort_tickets(std::vector<Ticket> &v, int sort_option) {
  switch(sort_option) {
    case 1:
      sort(v.begin(), v.end(), compareRouteNo);
      break;
    case 2:
      sort(v.begin(), v.end(), comparePointOfDeparture);
      break;
    case 3:
      sort(v.begin(), v.end(), compareDestination);
      break;
    case 4:
      sort(v.begin(), v.end(), compareDepartureTime);
      break;
    case 5:
      sort(v.begin(), v.end(), compareArrivalTime);
      break;
    case 6:
      sort(v.begin(), v.end(), comparePrice);
      break;
    default:
      break;
  }
}

// filter tickets vector
std::vector<Ticket> filter_tickets(std::vector<Ticket> v, string filter_string) {
  if (filter_string == "") {
    return clone_vector(v); // do nothing, if filter is an empty string
  }

  std::vector<Ticket> v_tmp;

  for(int i = 0; i < v.size(); i++) {
    if (v[i].get_point_of_departure().find(filter_string) != std::string::npos) {
      v_tmp.push_back(v[i]);
    }
  }

  return v_tmp;
}

// Print the table of tickets
void dump_table(const std::vector<Ticket> &v, int sort_option = 1, string filter_string = "") {
  std::vector<Ticket> v_tmp = filter_tickets(v, filter_string);
  sort_tickets(v_tmp, sort_option);
  cout << endl;
  cout << "RouteNo PointOfDeparture DepartureTime Destination ArrivalTime Price" << endl;
  for (int i = 0; i < v_tmp.size(); i++) {
    cout << v_tmp[i] << endl;
  }
}

// clone Tickets vector
std::vector<Ticket> clone_vector(const std::vector<Ticket> &orig) {
  std::vector<Ticket> copy;
  for (int i = 0; i < orig.size(); i++) {
    copy.push_back(orig[i]);
  }
  return copy;
}

// load data from file
int load_data(string file_name, std::vector<Ticket> &v) {
  Ticket t;
  ifstream data_file;
  data_file.open(file_name);
  if (!data_file.is_open()) {
    cerr << "ERROR. Cannot find file \"" << file_name << "\". See README.md for usage details." << endl;
    return 127;
  }
  while(data_file >> t) {
    v.push_back(t);
  }
  data_file.close();

  return 0;
}
#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

#include "Vector.h"

using namespace std;

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

Vector<Ticket> sort_tickets(Vector<Ticket> &, int);
Vector<Ticket> filter_tickets(Vector<Ticket> &, string);
void dump_table(const Vector<Ticket> &, int, string);
template<typename T>
Vector<T> vToV2(const std::vector<T> &);
template<typename T>
std::vector<T> v2ToV(const Vector<T> &);
int load_data(string, Vector<Ticket> &);

// --- Implamentation ---

// Ask user about top level options
int top_menu() {

  int selected_option;

  // show menu
  cout << endl;
  cout << "Choose option:" << endl;
  cout << " 1 - print the table" << endl;
  cout << " 2 - sort" << endl;
  cout << " 3 - filter" << endl;
  cout << " 4 - reset" << endl;
  cout << " 5 - show active options" << endl;
  cout << " 6 - exit" << endl;
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

// Ask user about a sorting option
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

// Ask user to specify a filter string
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
Vector<Ticket> sort_tickets(Vector<Ticket> &v, int sort_option) {
  std::vector<Ticket> v_tmp;
  v_tmp = v2ToV(v);
  switch(sort_option) {
    case 1:
      sort(v_tmp.begin(), v_tmp.end(), compareRouteNo);
      break;
    case 2:
      sort(v_tmp.begin(), v_tmp.end(), comparePointOfDeparture);
      break;
    case 3:
      sort(v_tmp.begin(), v_tmp.end(), compareDestination);
      break;
    case 4:
      sort(v_tmp.begin(), v_tmp.end(), compareDepartureTime);
      break;
    case 5:
      sort(v_tmp.begin(), v_tmp.end(), compareArrivalTime);
      break;
    case 6:
      sort(v_tmp.begin(), v_tmp.end(), comparePrice);
      break;
    default:
      break;
  }

  return vToV2(v_tmp);
}

// filter tickets vector
Vector<Ticket> filter_tickets(Vector<Ticket> &v, string filter_string) {
  if (filter_string == "") {
    return Vector<Ticket>(v); // do nothing, if filter is an empty string
  }

  Vector<Ticket> v_tmp;

  for(int i = 0; i < v.size(); i++) {
    if (
      to_string(v[i].get_route_no()).find(filter_string) != std::string::npos
      || v[i].get_point_of_departure().find(filter_string) != std::string::npos
      || v[i].get_destination().find(filter_string) != std::string::npos
      || v[i].get_departure_time().find(filter_string) != std::string::npos
      || v[i].get_arrival_time().find(filter_string) != std::string::npos
      || to_string(v[i].get_price()).find(filter_string) != std::string::npos
    ) {
      v_tmp.push_back(v[i]);
    }
  }

  return v_tmp;
}

// Print the table of tickets
void dump_table(Vector<Ticket> &v, int sort_option = 1, string filter_string = "") {
  Vector<Ticket> v_tmp2 = filter_tickets(v, filter_string);
  Vector<Ticket> v_tmp = sort_tickets(v_tmp2, sort_option);
  cout << endl;
  cout << "-------------------------------------------------------------------------------------" << endl;
  cout << "Route No | Point Of Departure | Departure Time | Destination | Arrival Time | Price" << endl;
  cout << "---------+--------------------+----------------+-------------+--------------+--------" << endl;
  for (int i = 0; i < v_tmp.size(); i++) {
    cout << v_tmp[i] << endl;
  }
  cout << "-------------------------------------------------------------------------------------" << endl;
}

template<typename T>
Vector<T> vToV2(const std::vector<T> & v) {
  Vector<T> tmp;
  for (int i = 0; i < v.size(); i++) {
    tmp.push_back(v[i]);
  }
  return tmp;
}

template<typename T>
std::vector<T> v2ToV(const Vector<T> & v2) {
  std::vector<T> tmp;
  for (int i = 0; i < v2.size(); i++) {
    tmp.push_back(v2[i]);
  }
  return tmp;
}

// load data from file
int load_data(string file_name, Vector<Ticket> &v) {
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
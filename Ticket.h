#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ticket {
private:
  int route_no;
  string point_of_departure;
  string departure_time;
  string destination;
  string arrival_time;
  double price;

public:
  Ticket();
  Ticket(int route_no, string point_of_departure, string departure_time,
      string destination, string arrival_time, double price);
  string to_string();
  friend ostream& operator<<(ostream& os, Ticket t);
};

// ----- implementation -----

Ticket::Ticket() {
  route_no = 0;
  point_of_departure = "---";
  departure_time = "--/--/--";
  destination = "---";
  arrival_time = "--/--/--";
  price = 0.0;
}

Ticket::Ticket(int route_no, string point_of_departure, string departure_time,
    string destination, string arrival_time, double price) {
  this->route_no = route_no;
  this->point_of_departure = point_of_departure;
  this->departure_time = departure_time;
  this->destination = destination;
  this->arrival_time = arrival_time;
  this->price = price;
}

string Ticket::to_string () {
  return std::to_string(route_no)
    + " " + point_of_departure
    + " " + departure_time
    + " " + destination
    + " " + arrival_time
    + " " + std::to_string(price);
}

ostream& operator<< (ostream& os, Ticket t) {
  os << t.to_string();
  return os;
}

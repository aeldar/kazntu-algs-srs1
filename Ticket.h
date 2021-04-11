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
  friend ostream& operator<<(ostream& os, const Ticket& t);
  friend istream& operator>>(istream& is, Ticket& t);
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

ostream& operator<< (ostream& os, const Ticket& t) {
  os << t.route_no
    << " " << t.point_of_departure
    << " " << t.departure_time
    << " " << t.destination
    << " " << t.arrival_time
    << " " << t.price;
  return os;
}

istream& operator>>(istream& is, Ticket& t) {
  is >> t.route_no >> t.point_of_departure >> t.departure_time >> t.destination >> t.arrival_time >> t.price;
  return is;
}


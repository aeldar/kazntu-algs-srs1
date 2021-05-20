#pragma once
#include <iostream>
#include <iomanip>
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
  // constructors
  Ticket();
  Ticket(int route_no, string point_of_departure, string departure_time,
      string destination, string arrival_time, double price);
  // operator overloading
  friend ostream& operator<<(ostream& os, const Ticket& t);
  friend istream& operator>>(istream& is, Ticket& t);
  // accessors
  int get_route_no() const;
  string get_point_of_departure() const;
  string get_departure_time() const;
  string get_destination() const;
  string get_arrival_time() const;
  double get_price() const;
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
  os << setw(8) << t.route_no
    << " | " << setw(18) << t.point_of_departure
    << " | " << setw(14) << t.departure_time
    << " | " << setw(11) << t.destination
    << " | " << setw(12) << t.arrival_time
    << " | " << t.price;
  return os;
}

istream& operator>>(istream& is, Ticket& t) {
  is >> t.route_no >> t.point_of_departure >> t.departure_time >> t.destination >> t.arrival_time >> t.price;
  return is;
}

// getters
int Ticket::get_route_no() const {
  return this->route_no;
}
string Ticket::get_point_of_departure() const {
  return this->point_of_departure;
}
string Ticket::get_departure_time() const {
  return this->departure_time;
}
string Ticket::get_destination() const {
  return this->destination;
}
string Ticket::get_arrival_time() const {
  return this->arrival_time;
}
double Ticket::get_price() const {
  return this->price;
}


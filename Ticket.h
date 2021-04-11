#pragma once
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
  string to_string();
};

Ticket::Ticket () {
  route_no = 0;
  point_of_departure = "";
  departure_time = "";
  destination = "";
  arrival_time = "";
  price = 0.0;
}

string Ticket::to_string () {
  return route_no + " " + point_of_departure + " " +  departure_time;
}

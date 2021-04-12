#include <iostream>
#include <vector>

#include "Ticket.h"

using namespace std;

int main() {
  std::vector<Ticket> v;

  // show help info
  cout << "Please enter data line by line in the following format:" << endl;
  cout << "RouteNo PointOfDeparture DepartureTime Destination ArrivalTime Price" << endl;

  Ticket t;
  while(cin >> t) {
    v.push_back(t);
  }

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }

  return 0;
}

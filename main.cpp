#include <iostream>

#include "Ticket.h"

using namespace std;

int main() {
  Ticket ts[10];

  ts[0] = Ticket(1, "fdsfd", "afaf", "fdfd", "asda", 123.54);

  cin >> ts[1];

  for (int i = 0; i < 10; i++) {
    cout << ts[i] << endl;
  }

  return 0;
}

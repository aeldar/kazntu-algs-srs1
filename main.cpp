#include <iostream>

#include "Ticket.h"

using namespace std;

int main() {
  Ticket t;
  Ticket tx[10];

  cout << sizeof(tx)/sizeof(Ticket[1]) << endl;

  tx[0] = Ticket(1, "fdsfd", "afaf", "fdfd", "asda", 123.54);

  for (int i = 0; i < 10; i++) {
    cout << tx[i] << endl;
  }

  cout << t << endl;

  return 0;
}

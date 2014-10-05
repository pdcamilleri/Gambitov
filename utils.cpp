#include <bitset>
#include <iostream>

using namespace std;

void showBits(int64_t i) {
  bitset<64> x(i);
  cout << "bits: " << x << endl;
}

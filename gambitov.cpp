#include "gambitov.h"
#include <iostream>

using namespace std;

Gambitov::Gambitov() {
  cout << "creating gambitov object" << endl;
  testVariable = 4;
}

Gambitov::~Gambitov() {
  cout << "destroying gambitov object" << endl;
}

void Gambitov::think() {
  cout << "Thinking..." << endl;
  privateTestMethod();
}

void Gambitov::privateTestMethod() {
  cout << "test variable is " << testVariable << endl;
}


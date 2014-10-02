#include "gambitov.h"
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

Gambitov::Gambitov() {
  //cout << "creating gambitov object" << endl;
  testVariable = 4;
}

Gambitov::~Gambitov() {
  //cout << "destroying gambitov object" << endl;
}

int Gambitov::think() {
  //cout << "Thinking..." << endl;
  privateTestMethod();
  return 2;
}

vector<int> Gambitov::getAllMoves() {
  vector<int> v;
  return v;
}

void Gambitov::loadBoardState(string pos) {
  position = pos;
}

void Gambitov::privateTestMethod() {
  //cout << "test variable is " << testVariable << endl;
}



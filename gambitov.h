#include <string>
#include <vector>
#include "board.h"

using namespace std;

class Gambitov {

  public:
    Gambitov();
    ~Gambitov();

    int think();

    vector<int> getAllMoves();
    void loadBoardState(string pos);

  private:
    int testVariable;
    string position;

    void privateTestMethod();

};


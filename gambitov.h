#include <string>
#include <vector>

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


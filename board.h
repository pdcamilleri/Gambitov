#include <string>
using namespace std;

class Board {

  public:
    Board();
    ~Board();

    void loadBoardState(string pos);
    bool isPawn(int rank, int file);

  private:
    int64_t pawns;

};

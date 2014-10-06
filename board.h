#include <string>

#define PAWN_WHITE 'P'
#define PAWN_BLACK 'p'

using namespace std;

class Board {

  public:
    Board();
    ~Board();

    void loadBoardState(string pos);
    bool isPawn(int rank, int file);
    bool isWhite(int rank, int file);

  private:
    int64_t whitePieces;
    int64_t blackPieces;
    int64_t whitePawns;
    int64_t blackPawns;

    inline int64_t rankFileBit(int rank, int file) {
      return (1LL << (8LL * rank)) << file;
    }

};

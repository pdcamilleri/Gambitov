#include <string>

const char PAWN_WHITE = 'P';
const char PAWN_BLACK = 'p';
const char BISHOP_WHITE = 'B';
const char BISHOP_BLACK = 'b';
const char KNIGHT_WHITE = 'N';
const char KNIGHT_BLACK = 'n';
const char ROOK_WHITE = 'R';
const char ROOK_BLACK = 'r';
const char QUEEN_WHITE = 'Q';
const char QUEEN_BLACK = 'q';
const char KING_WHITE = 'K';
const char KING_BLACK = 'k';

using namespace std;

class Board {

  public:
    Board();
    ~Board();

    void loadBoardState(const string pos);
    bool isPawn(const int file, const int rank);
    bool isBishop(const int file, const int rank);
    bool isKnight(const int file, const int rank);
    bool isRook(const int file, const int rank);
    bool isQueen(const int file, const int rank);
    bool isKing(const int file, const int rank);
    bool isWhite(const int file, const int rank);

  private:
    int64_t whitePieces;
    int64_t blackPieces;
    int64_t whitePawns;
    int64_t blackPawns;
    int64_t whiteBishops;
    int64_t blackBishops;
    int64_t whiteKnights;
    int64_t blackKnights;
    int64_t whiteRooks;
    int64_t blackRooks;
    int64_t whiteQueens;
    int64_t blackQueens;
    int64_t whiteKing;
    int64_t blackKing;

    // TODO make issue, would changing the board representation
    // so that we dont have to do the 8 - file - 1,
    // make the program significantly faster, ie, increase search depth
    // so would slight modifications in boardrepresentation improve performance?
    inline int64_t rankFileBit(const int file, const int rank) {
      return (1LL << (8LL * rank)) << (8 - file - 1);
    }

};

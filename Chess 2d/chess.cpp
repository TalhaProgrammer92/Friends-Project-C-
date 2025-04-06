#include <iostream>
#include <io.h>
#include <fcntl.h>

using namespace std;

//////////////////////////
// UNICODE CHESS PIECES //
//////////////////////////
#define WHITE_KING   L"\u2654"
#define WHITE_QUEEN  L"\u2655"
#define WHITE_ROOK   L"\u2656"
#define WHITE_BISHOP L"\u2657"
#define WHITE_KNIGHT L"\u2658"
#define WHITE_PAWN   L"\u2659"

#define BLACK_KING   L"\u265A"
#define BLACK_QUEEN  L"\u265B"
#define BLACK_ROOK   L"\u265C"
#define BLACK_BISHOP L"\u265D"
#define BLACK_KNIGHT L"\u265E"
#define BLACK_PAWN   L"\u265F"

#define FILLED_CIRCLE  L"\u25CF"
#define HOLLOW_CIRCLE  L"\u25CB"

//* const wchar_t* white_rook = WHITE_ROOK;
//* wcout << white_rook << endl;

int main()
{
    //! Set console to Unicode mode
    _setmode(_fileno(stdout), _O_U16TEXT);

    return 0;
}

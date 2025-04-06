#include <iostream>
#include <string>

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

using namespace std;

//////////////////
// CHESS PIECES //
//////////////////
namespace ChessPieces
{
    const string WhiteKing = "♔";
    const string WhiteQueen = "♕";
    const string WhiteRook = "♖";
    const string WhiteBishop = "♗";
    const string WhiteKnight = "♘";
    const string WhitePawn = "♙";

    const string BlackKing = "♚";
    const string BlackQueen = "♛";
    const string BlackRook = "♜";
    const string BlackBishop = "♝";
    const string BlackKnight = "♞";
    const string BlackPawn = "♟";
}

//* Setup Unicode Console
void setup_unicode_console();

///////////////////
// MAIN FUNCTION //
///////////////////
int main()
{
    //? Setup Unicode Console
    setup_unicode_console();

    wcout << "King: " << ChessPieces::WhiteKing << endl;
}

//* Setup Unicode Console
void setup_unicode_console()
{

#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT); //! Windows: UTF-16
    // std::wcout << L"♔ White King\n";       //! Wide-string (UTF-16)
#else
    // std::cout << u8"♔ White King\n"; //! UTF-8 (Linux/macOS)
#endif
}

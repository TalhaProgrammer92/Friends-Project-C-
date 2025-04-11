#include <iostream>
#include <vector>

//! To display Unicode characters in the console
#include <io.h>
#include <fcntl.h>

using namespace std;

//////////////////////////
// UNICODE CHESS PIECES //
//////////////////////////

//! Important for rendering chess pieces in the console
#define WHITE_KING L"\u2654"   //? ♔
#define WHITE_QUEEN L"\u2655"  //? ♕
#define WHITE_ROOK L"\u2656"   //? ♖
#define WHITE_BISHOP L"\u2657" //? ♗
#define WHITE_KNIGHT L"\u2658" //? ♘
#define WHITE_PAWN L"\u2659"   //? ♙

#define BLACK_KING L"\u265A"   //? ♚
#define BLACK_QUEEN L"\u265B"  //? ♛
#define BLACK_ROOK L"\u265C"   //? ♜
#define BLACK_BISHOP L"\u265D" //? ♝
#define BLACK_KNIGHT L"\u265E" //? ♞
#define BLACK_PAWN L"\u265F"   //? ♟

#define FILLED_CIRCLE L'\u25CF' //? ●
#define HOLLOW_CIRCLE L'\u25CB' //? ○

/*
 ! Example of displaying Unicode characters:

 ? const wchar_t* white_rook = WHITE_ROOK;
 ? wcout << white_rook << endl;
*/

///////////////
// Functions //
///////////////
//* Set console to Unicode mode
void setUnicodeMode();

//* Clear the console
void clearConsole();

/////////////////
// Entry Point //
/////////////////
int main()
{
    //* Set console to Unicode mode
    setUnicodeMode();

    return 0;
}

///////////////
// Functions //
///////////////
//* Set console to Unicode mode
void setUnicodeMode()
{
    //! To display Unicode characters in the console
    _setmode(_fileno(stdout), _O_U16TEXT);

    //! To read Unicode characters from the console
    _setmode(_fileno(stdin), _O_U16TEXT);

    //! To display Unicode characters in the console (error output)
    _setmode(_fileno(stderr), _O_U16TEXT);
}

//* Clear the console (cross-platform)
void clearConsole()
{
//! Windows OS
#ifdef _WIN32
    system("cls");
//! Linux/Unix OS
#else
    system("clear");
#endif
}
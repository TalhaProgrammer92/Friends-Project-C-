#include <iostream>
#include <windows.h>

using namespace std;

/*
WHITE:	♚ ♛ ♜ ♝ ♞ ♟
BLACK:	♔ ♕ ♖ ♗ ♘ ♙

'black' : {
    'king' : '\u2654',
    'queen' : '\u2655',
    'rook' : '\u2656',
    'bishop' : '\u2657',
    'knight' : '\u2658',
    'pawn' : '\u2659'
},
'white' : {
    'king' : '\u265A',
    'queen' : '\u265B',
    'rook' : '\u265C',
    'bishop' : '\u265D',
    'knight' : '\u265E',
    'pawn' : '\u265F'
}
*/

///////////////
//  Unicode  //
///////////////
class Black
{
public:
    static const string king;
    static const string queen;
    static const string rook;
    static const string bishop;
    static const string knight;
    static const string pawn;
};
const string Black::king = "\u2654";
const string Black::queen = "\u2655";
const string Black::rook = "\u2656";
const string Black::bishop = "\u2657";
const string Black::knight = "\u2658";
const string Black::pawn = "\u2659";

class White
{
public:
    static const string king;
    static const string queen;
    static const string rook;
    static const string bishop;
    static const string knight;
    static const string pawn;
};
const string White::king = "\u265A";
const string White::queen = "\u265B";
const string White::rook = "\u265C";
const string White::bishop = "\u265D";
const string White::knight = "\u265E";
const string White::pawn = "\u265F";


/////////////
//  MAIN   //
/////////////
int main()
{
    // Set console code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);

    cout << Black::king << ' ' << White::king << endl;
}

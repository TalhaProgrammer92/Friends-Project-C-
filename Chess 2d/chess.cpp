#include <iostream>
#include <windows.h>

using namespace std;

//////////////////////
// ANSI Color Codes //
//////////////////////
//? https://en.wikipedia.org/wiki/ANSI_escape_code#Colors

//* Forground colors
enum class FGColor {
    Black = 30, Red, Green, Yellow, Blue, Magenta, Cyan, White, Default = 39
};

//* Background colors
enum class BGColor {
    Black = 40, Red, Green, Yellow, Blue, Magenta, Cyan, White, Default = 49
};

//* Styles
enum class TextStyle {
    Reset = 0, Bold = 1, Dim = 2, Italic = 3, Underline = 4, Blink = 5, Reverse = 7, Hidden = 8
};

//* Get color string function
//! Works with FGColor, BGColor, and TextStyle enums
//? Returns a string that can be used to set the color of text in the console
string getColorString(FGColor fg = FGColor::Default, BGColor bg = BGColor::Default, TextStyle style = TextStyle::Reset) {
    return "\033[" + to_string(static_cast<int>(style)) + ";" +
           to_string(static_cast<int>(fg)) + ";" +
           to_string(static_cast<int>(bg)) + "m";
}

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

////////////////////
// POSITION CLASS //
////////////////////
class Position {
public:
    //* row and column of the position on the chessboard
    int row, column;

    //* Constructor
    Position(int r, int c) : row(r), column(c) {}

    //* Get the position as a string
    string toString() const {
        return "(" + to_string(row) + ", " + to_string(column) + ")";
    }

    //! The following function will be used to perform calculations with positions for movement validations
    //* Subtract two positions - deal with absolute values
    Position operator-(const Position& other) const {
        return Position(abs(row - other.row), abs(column - other.column));
    }
};


/////////////
//  MAIN   //
/////////////
int main()
{
    //! Set console code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);

    //* check position
    Position p1(5, 3);
    Position p2(3, 1);
    Position p3 = p1 - p2;
    cout << p3.toString() << endl; // (3, 4)
}
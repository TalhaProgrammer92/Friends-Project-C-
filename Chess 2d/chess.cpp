#include <iostream>

using namespace std;

//////////////////////
// ANSI Color Codes //
//////////////////////
enum class FGColor {
    Black = 30, Red, Green, Yellow, Blue, Magenta, Cyan, White, Default = 39
};

enum class BGColor {
    Black = 40, Red, Green, Yellow, Blue, Magenta, Cyan, White, Default = 49
};

enum class TextStyle {
    Reset = 0, Bold = 1, Dim = 2, Italic = 3, Underline = 4, Blink = 5, Reverse = 7, Hidden = 8
};

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

//////////////
// POSITION //
//////////////
class Position
{
private:
    //* Variables
    int row, column;

public:
    //* Constructor
    Position(int row = 0, int column = 0) : row(row), column(column) {}

    //* Getters and Setters
    int getRow();
    int getColumn();
    void setRow(int row);
    void setColumn(int column);

    //* Set both
    void setBoth(int row, int column);

    //* Display
    void display();

    //* Equal overload
    bool operator==(Position &position);
};

///////////////////
//  CHESS PIECE  //
///////////////////
class ChessPiece {
protected:
    //* Variables
    string unicode;

public:
    Position position;

    //* Constructor
    ChessPiece(Position position, string unicode) : position(position), unicode(unicode) {}

    //* Getters
    string getUnicode() { return unicode; }
};

////////////
//  PAWN  //
////////////
class Pawn : public ChessPiece
{
public:
    //* Constructor
    Pawn(Position position) : ChessPiece(position, "") {}
};

//////////////////
//  WHITE PAWN  //
//////////////////
class WhitePawn : public Pawn
{
public:
    //* Constructor
    WhitePawn(Position position) : Pawn(position) { unicode = White::pawn; }
};

//////////////////
//  BLACK PAWN  //
//////////////////
class BlackPawn : public Pawn
{
public:
    //* Constructor
    BlackPawn(Position position) : Pawn(position) { unicode = Black::pawn; }
};

///////////////////
// FUNCTION TO PRINT COLORS //
///////////////////

string setColor(FGColor fg = FGColor::Default, BGColor bg = BGColor::Default, TextStyle style = TextStyle::Reset) {
    return "\033[" + to_string(static_cast<int>(style)) + ";" +
           to_string(static_cast<int>(fg)) + ";" +
           to_string(static_cast<int>(bg)) + "m";
}

// Function to draw chess board - Sample
void drawChessBoard() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            // Alternate colors (like real chess board)
            BGColor bgColor = (row + col) % 2 == 0 ? BGColor::White : BGColor::Black;
            FGColor fgColor = (row + col) % 2 == 0 ? FGColor::Black : FGColor::White;

            // Print square
            cout << setColor(fgColor, bgColor) << "  " << setColor();
        }
        cout << endl;
    }
}

/////////////
//  MAIN   //
/////////////
int main()
{
    // Set console code page to UTF-8
    // SetConsoleOutputCP(CP_UTF8);

    // Draw chess board
    drawChessBoard();

    // cout << setColor(FGColor::Green, BGColor::White) << White::king << setColor() << endl;
}

//////////////
// POSITION //
//////////////
int Position::getRow()
{
    return row;
}

int Position::getColumn()
{
    return column;
}

void Position::setRow(int row)
{
    this->row = row;
}

void Position::setColumn(int column)
{
    this->column = column;
}

void Position::setBoth(int row, int column)
{
    this->row = row;
    this->column = column;
}

void Position::display()
{
    cout << '(' << row << ", " << column << ')';
}

bool Position::operator==(Position &position)
{
    return row == position.row && column == position.column;
} 
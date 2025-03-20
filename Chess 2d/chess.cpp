#include <iostream>

using namespace std;

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
};

/////////////
//  MAIN   //
/////////////
int main()
{
    // Set console code page to UTF-8
    // SetConsoleOutputCP(CP_UTF8);

    cout << Black::king << ' ' << White::king << endl;
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

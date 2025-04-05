#include <iostream>
#include <windows.h>

using namespace std;

//////////////////////
//  Unicode Pieces  //
//////////////////////
enum class BlackPiece
{
    king = 0x2654,
    queen = 0x2655,
    rook = 0x2656,
    bishop = 0x2657,
    knight = 0x2658,
    pawn = 0x2659
};

enum class WhitePiece
{
    king = 0x265A,
    queen = 0x265B,
    rook = 0x265C,
    bishop = 0x265D,
    knight = 0x265E,
    pawn = 0x265F
};

////////////////////
// POSITION CLASS //
////////////////////
class Position {
public:
    //* row and column of the position on the chessboard
    int row, column;

    //* Constructor
    Position(int r, int c) : row(r), column(c) {}

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

    //* Not equal overload
    bool operator!=(Position &position);

    //* Subtract overload
    Position operator-(Position &position);
};

///////////////////
//  CHESS PIECE  //
///////////////////
class ChessPiece
{
protected:
    //! To check if the piece is alive
    bool alive;

public:
    //* Attributes

    /*
     ! To track the piece's position
     ? Format: (row, column)
    */
    Position position;

    //* Constructor
    ChessPiece(Position position);

    //* Getters and Setters
    bool isAlive();
    void kill();

    //* Estimate the distance between two positions
    Position estimateDistance(Position destination);
};

/////////////////////////
//  WHITE CHESS PIECE  //
/////////////////////////
class WhiteChessPiece : public ChessPiece
{
protected:
    //* Attributes
    WhitePiece piece;

public:
    //* Constructor
    WhiteChessPiece(Position position, WhitePiece piece);
};

/////////////////////////
//  BLACK CHESS PIECE  //
/////////////////////////
class BlackChessPiece : public ChessPiece
{
protected:
    //* Attributes
    BlackPiece piece;

public:
    //* Constructor
    BlackChessPiece(Position position, BlackPiece piece);
};

/////////////
//  MAIN   //
/////////////
int main()
{
    //! Set console code page to UTF-8
    //! Set console code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);

    return 0;
}

//////////////
// POSITION //
//////////////

//* Getters and Setters
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
    //! In range
    if (row >= 0 && row <= 7)
        this->row = row;

    //! Out of range (throw exception)
    else
        throw out_of_range("Row is out of range (0-7)");
}

void Position::setColumn(int column)
{
    //! In range
    if (column >= 0 && column <= 7)
        this->column = column;

    //! Out of range (throw exception)
    else
        throw out_of_range("Column is out of range (0-7)");
}

void Position::setBoth(int row, int column)
{
    //! Set both
    this->setRow(row);
    this->setColumn(column);
}

/*
 * Display the position
 ? Format: (row, column)
 */
void Position::display()
{
    cout << '(' << row << ", " << column << ')';
}

//* Equal overload
bool Position::operator==(Position &position)
{
    return row == position.row && column == position.column;
}

//* Not equal overload
bool Position::operator!=(Position &position)
{
    return row != position.row || column != position.column;
}

//* Subtract overload
Position Position::operator-(Position &position)
{
    return Position(abs(row - position.row), abs(column - position.column));
}

///////////////////
//  CHESS PIECE  //
///////////////////

//* Constructor
ChessPiece::ChessPiece(Position position) : position(position), alive(true) {}

//* Getters and Setters

//? Check if the piece is alive
bool ChessPiece::isAlive()
{
    return alive;
}

//? Kill the piece
void ChessPiece::kill()
{
    alive = false;
}

/*
 * Estimate the distance between two positions
 ? Format: (row, column)
 */
Position ChessPiece::estimateDistance(Position destination)
{
    return this->position - destination;
}

/////////////////////////
//  WHITE CHESS PIECE  //
/////////////////////////

//* Constructor
WhiteChessPiece::WhiteChessPiece(Position position, WhitePiece piece) : ChessPiece(position)
{
    this->piece = piece;
}

/////////////////////////
//  BLACK CHESS PIECE  //
/////////////////////////

//* Constructor
BlackChessPiece::BlackChessPiece(Position position, BlackPiece piece) : ChessPiece(position)
{
    this->piece = piece;
}
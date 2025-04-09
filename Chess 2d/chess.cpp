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

////////////////////
// Position class //
////////////////////
class Position
{
public:
    int row, column;

    //* Constructors
    Position() {}           //! Default constructor
    Position(int r, int c); //! Constructor with row and column (parameters)

    //* Overloaded operator for comparison
    bool operator==(const Position &other) const;
    bool operator!=(const Position &other) const;
    Position operator-(const Position &other) const;
};

//////////////////
// Symbol Class //
//////////////////
class Symbol
{
public:
    //* Unicode of a chess piece or a circle
    wchar_t unicode;

    //* Constructor
    Symbol() {}           //! Default constructor
    Symbol(wchar_t item); //! Constructor with item (parameter)

    //* Display the box with the item
    void display();

    //* Override == operator
    bool operator==(const Symbol &other) const;

    //* Override != operator
    bool operator!=(const Symbol &other) const;
};

///////////////////////
// Chess Piece Class //
///////////////////////
class ChessPiece
{
protected:
    Position position; //! Position & destination of the chess piece

public:
    //* Constructor
    ChessPiece() {} //! Default constructor

    //* Constructor with position and symbol (parameters)
    ChessPiece(Position pos);

    //* Get the position of the chess piece
    Position getPosition();

    //* Get displacement of the chess piece
    Position getDisplacement(Position destinaiton);
};

/////////////////
// Board Class //
/////////////////
class Board
{
    //* 8x8 array of boxes
    Symbol boxes[8][8];

public:
    //* Constructor
    Board();

    //* Clear/Reset the board
    void clear();

    //* Get the box at a specific position
    Symbol getBox(Position position);

    //* Set the box at a specific position
    void setBox(Position position, Symbol symbol);

    //* Display the board
    void display();
};

////////////////
// Pawn Class //
////////////////
class Pawn : public ChessPiece
{
protected:
    //! Possible displacement moves of the pawn
    vector<Position> valid_displament = {
        Position(1, 0), //? Forward move
        Position(2, 0), //? Double forward move, only on the initial displacement move
        Position(1, 1)  //? Diagonal capture move
    };

    //* Check valdity of the move
    bool checkMoveValidity(Position destination, vector<Position> initial_positions, Board &board);

public:
    //* Constructor with position and symbol (parameters)
    Pawn(Position pos) : ChessPiece(pos) {}

    //* Check if the move is valid
    virtual bool isValidMove(Position displacement, Board &board) = 0; //! Pure virtual function
};

//////////////////////
// White Pawn class //
//////////////////////
class WhitePawn : public Pawn
{
private:
    vector<Position> initial_positions = {
        Position(6, 0), //? Initial position of the white pawn
        Position(6, 1),
        Position(6, 2),
        Position(6, 3),
        Position(6, 4),
        Position(6, 5),
        Position(6, 6),
        Position(6, 7)};

public:
    //* Constructor with position and symbol (parameters)
    WhitePawn(Position pos) : Pawn(pos) {}

    //* Check if the move is valid
    bool isValidMove(Position destination, Board &board) override;
};

//////////////////////
// Black Pawn class //
//////////////////////
class BlackPawn : public Pawn
{
private:
    vector<Position> initial_positions = {
        Position(1, 0), //? Initial position of the black pawn
        Position(1, 1),
        Position(1, 2),
        Position(1, 3),
        Position(1, 4),
        Position(1, 5),
        Position(1, 6),
        Position(1, 7)};

public:
    //* Constructor with position and symbol (parameters)
    BlackPawn(Position pos) : Pawn(pos) {}

    //* Check if the move is valid
    bool isValidMove(Position destination, Board &board) override;
};

///////////////
// Functions //
///////////////
//* Set console to Unicode mode
void setUnicodeMode();

//* Clear the console
void clearConsole();

//* Get appropriate empty box symbol based on position
Symbol getEmptyBoxSymbol(Position position);

/////////////////
// Entry Point //
/////////////////
int main()
{
    //* Set console to Unicode mode
    setUnicodeMode();

    //* Clear the console
    clearConsole();

    Board board;     //! Create a board object
    board.display(); //! Clear the board

    //* Dislpay chess pieces
    wcout << endl;

    wcout << "Black: " << BLACK_KING << " " << BLACK_QUEEN << " " << BLACK_ROOK << " " << BLACK_BISHOP << " " << BLACK_KNIGHT << " " << BLACK_PAWN << endl;

    wcout << "White: " << WHITE_KING << " " << WHITE_QUEEN << " " << WHITE_ROOK << " " << WHITE_BISHOP << " " << WHITE_KNIGHT << " " << WHITE_PAWN << endl;

    return 0;
}

////////////////////
// Position class //
////////////////////

//* Constructor with row and column (parameters)
Position::Position(int r, int c) : row(r), column(c) {}

//* Overloaded operator for comparison
bool Position::operator==(const Position &other) const
{
    return (row == other.row && column == other.column);
}

bool Position::operator!=(const Position &other) const
{
    return !(*this == other);
}

Position Position::operator-(const Position &other) const
{
    return Position(abs(row - other.row), abs(column - other.column));
}

//////////////////
// Symbol Class //
//////////////////

//* Constructor
Symbol::Symbol(wchar_t item) : unicode(item) {}

//* Display the box with the item
void Symbol::display()
{
    wcout << unicode;
}

//* Override == operator
bool Symbol::operator==(const Symbol &other) const
{
    return (unicode == other.unicode);
}

//* Override != operator
bool Symbol::operator!=(const Symbol &other) const
{
    return !(*this == other);
}

///////////////////////
// Chess Piece Class //
///////////////////////

//* Constructor with position and symbol (parameters)
ChessPiece::ChessPiece(Position pos) : position(pos) {}

//* Get the position of the chess piece
Position ChessPiece::getPosition()
{
    return position;
}

//* Get displacement of the chess piece
Position ChessPiece::getDisplacement(Position destination)
{
    return position - destination;
}

/////////////////
// Board Class //
/////////////////

//* Constructor
Board::Board()
{
    clear();
}

//* Clear/Reset the board
void Board::clear()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            //? Initialize the mepty boxes
            boxes[i][j] = getEmptyBoxSymbol(Position(i, j));
        }
    }
}

//* Get the box at a specific position
Symbol Board::getBox(Position position)
{
    return boxes[position.row][position.column];
}

//* Set the box at a specific position
void Board::setBox(Position position, Symbol symbol)
{
    boxes[position.row][position.column] = symbol;
}

//* Display the board
void Board::display()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            boxes[i][j].display();
            wcout << " ";
        }
        wcout << endl;
    }
}

////////////////
// Pawn Class //
////////////////

//* Check valdity of the move
bool Pawn::checkMoveValidity(Position destination, vector<Position> initial_positions, Board &board)
{
    //* Get the displacement of the pawn
    Position displacement = getDisplacement(destination);

    //* Check if the pawn is moving forward
    if (displacement == valid_displament[0]) //? (1, 0)
    {
        return true; //! Forward move
    }

    //* Check if the double move is valid
    else if (displacement == valid_displament[1]) //? (2, 0)
    {
        for (auto &&pos : initial_positions)
        {
            if (position == pos)
            {
                return true; //! Double forward move, only on the initial displacement move
            }
        }
        return false; //! Not a double forward move
    }

    //* Check if the pawn is capturing a piece diagonally
    else if (displacement == valid_displament[2] && (board.getBox(destination) != Symbol(HOLLOW_CIRCLE) || board.getBox(destination) != Symbol(FILLED_CIRCLE))) //? (1, 1)
    {
        return true; //! Diagonal capture move
    }

    //* Not a valid move
    return false; //! Not a valid move
}

//////////////////////
// White Pawn class //
//////////////////////

//* Check if the move is valid
bool WhitePawn::isValidMove(Position destination, Board &board)
{
    //! Check if the pawn is not moving backward
    if (position.row > destination.row)
    {
        return checkMoveValidity(destination, initial_positions, board); //! Check if the move is valid
    }

    return false;
}

//////////////////////
// Black Pawn class //
//////////////////////

//* Check if the move is valid
bool BlackPawn::isValidMove(Position destination, Board &board)
{
    //! Check if the pawn is not moving backward
    if (position.row < destination.row)
    {
        return checkMoveValidity(destination, initial_positions, board); //! Check if the move is valid
    }

    return false;
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

//* Get appropriate empty box symbol based on position
Symbol getEmptyBoxSymbol(Position position)
{
    int i = position.row;
    int j = position.column;

    if ((i + j) % 2 == 0)
        return Symbol(HOLLOW_CIRCLE);
    return Symbol(FILLED_CIRCLE);
}
#include <iostream>
#include <vector>
#include <windows.h>

//! This program contain bugs and is not fully functional. It is a work in progress and should not be used in production.
//! The code is not complete and may not compile or run as expected. Use at your own risk.

using namespace std;

//////////////////////
//  Unicode Pieces  //
//////////////////////
/*
// Unicode Chess Piece Macros
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

// Example usage:
#include <iostream>
#include <io.h>
#include <fcntl.h>

int main() {
    // Set console to Unicode mode
    _setmode(_fileno(stdout), _O_U16TEXT);
    
    // Store in variable
    const wchar_t* white_rook = WHITE_ROOK;

    std::wcout << L"Chess pieces:\n";
    std::wcout << WHITE_KING << L" White King\n";
    std::wcout << WHITE_QUEEN << L" White Queen\n";
    std::wcout << WHITE_ROOK << L" White Rook\n";
    std::wcout << WHITE_BISHOP << L" White Bishop\n";
    std::wcout << WHITE_KNIGHT << L" White Knight\n";
    std::wcout << WHITE_PAWN << L" White Pawn\n";
    std::wcout << BLACK_KING << L" Black King\n";
    std::wcout << BLACK_QUEEN << L" Black Queen\n";
    std::wcout << BLACK_ROOK << L" Black Rook\n";
    std::wcout << BLACK_BISHOP << L" Black Bishop\n";
    std::wcout << BLACK_KNIGHT << L" Black Knight\n";
    std::wcout << BLACK_PAWN << L" Black Pawn\n";
    
    return 0;
}

Notes:
1. The _setmode and _O_U16TEXT are Windows-specific. For Linux/macOS, you might need different setup.

2. For cross-platform compatibility, you might want to wrap the console setup in platform-specific code.

3. Make sure your console/terminal uses a font that supports these Unicode characters (most modern ones do).

4. Notice there was a typo in WHITE_KNIGHT (should be WHITE_KNIGHT) which I've corrected in the example usage.

5. For C++20 and later, you could also use char8_t and UTF-8 string literals.
*/

//* Set console to support Unicode characters
void setUnicodeSupport();

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

    //! Fixed-size array for valid positions
    vector<Position> valid;

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

//////////////////
//  PAWN PIECE  //
//////////////////
class PawnPiece : public ChessPiece
{
private:
    //* Attributes
    int moves;          //! Number of moves made by the pawn
    bool firstMove;     //! Check if the pawn is on its first move

public:
    //* Constructor
    PawnPiece(Position position);

    //* Getters and Setters
    int getMoves();
    bool isFirstMove();

    //* Setters
    void incrementMoves();

    //* Destructor
    ~PawnPiece();
};

////////////////////////
//  WHITE PAWN PIECE  //
////////////////////////
class WhitePawnPiece : public PawnPiece
{
private:
    //* Attributes
    WhitePiece piece = WhitePiece::pawn; //! Piece type
public:
    //* Constructor
    WhitePawnPiece(Position position) : PawnPiece(position) {}

};

/////////////
//  MAIN   //
/////////////
int main()
{
    //? Set console to support Unicode characters
    setUnicodeSupport();

    //? Chess piece - testing
    cout << "White King: " << (char)WhitePiece::king << endl;

    return 0;
}

//* Set console to support Unicode characters
void setUnicodeSupport()
{
    //? Set console code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    //? Set console font to a font that supports Unicode characters
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.dwFontSize.X = 0;       //! Width of each character in the font
    cfi.dwFontSize.Y = 16;      //! Height
    cfi.FontFamily = FF_DONTCARE;       //! Font family
    cfi.FontWeight = FW_NORMAL;         //! Font weight
    cfi.nFont = 0;      //! Font number
    wcscpy_s(cfi.FaceName, L"Consolas"); //! Font name
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);         //! Set text color to white
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

//////////////////
//  PAWN PIECE  //
//////////////////

//* Constructor
PawnPiece::PawnPiece(Position position) : ChessPiece(position)
{
    //? Set the pawn to be alive
    moves = 0;
    firstMove = true;

    //? Set valid positions for the pawn to move
    valid.push_back(Position(1, 0));    //! First move (1 box)
    valid.push_back(Position(2, 0));    //! First move (2 boxes)
    valid.push_back(Position(1, 1));    //! Diagonal move
}

//* Getters and Setters
int PawnPiece::getMoves()
{
    return moves;
}

bool PawnPiece::isFirstMove()
{
    return firstMove;
}

//* Setters
void PawnPiece::incrementMoves()
{
    moves++;
    firstMove = false;
}

//* Destructor
PawnPiece::~PawnPiece()
{
    valid.clear();
    valid.shrink_to_fit();
}
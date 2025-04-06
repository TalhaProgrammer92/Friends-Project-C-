#include <iostream>
#include <io.h>
#include <fcntl.h>

using namespace std;

//////////////////////////
// UNICODE CHESS PIECES //
//////////////////////////

//! Important for rendering chess pieces in the console
#define WHITE_KING L"\u2654"    //? ♔
#define WHITE_QUEEN L"\u2655"   //? ♕
#define WHITE_ROOK L"\u2656"    //? ♖
#define WHITE_BISHOP L"\u2657"  //? ♗
#define WHITE_KNIGHT L"\u2658"  //? ♘
#define WHITE_PAWN L"\u2659"    //? ♙

#define BLACK_KING L"\u265A"    //? ♚
#define BLACK_QUEEN L"\u265B"   //? ♛
#define BLACK_ROOK L"\u265C"    //? ♜
#define BLACK_BISHOP L"\u265D"  //? ♝
#define BLACK_KNIGHT L"\u265E"  //? ♞
#define BLACK_PAWN L"\u265F"    //? ♟

#define FILLED_CIRCLE L'\u25CF' //? ●
#define HOLLOW_CIRCLE L'\u25CB' //? ○

/*
 ! Example of displaying Unicode characters:

 ? const wchar_t* white_rook = WHITE_ROOK;
 ? wcout << white_rook << endl;
*/

///////////////
// Box Class //
///////////////
class Box
{
public:
    //* Item is a chess piece or a circle
    wchar_t item;

    //* Constructor
    Box() {}           //! Default constructor
    Box(wchar_t item); //! Constructor with item (parameter)

    //* Display the box with the item
    void display();
};

/////////////////
// Board Class //
/////////////////
class Board
{
public:
    //* 8x8 array of boxes
    Box boxes[8][8];

    //* Constructor
    Board();

    //* Clear/Reset the board
    void clear();

    //* Display the board
    void display();
};

///////////////
// Functions //
///////////////
//* Set console to Unicode mode
void setUnicodeMode();

/////////////////
// Entry Point //
/////////////////
int main()
{
    //* Set console to Unicode mode
    setUnicodeMode();

    Board board;     //! Create a board object
    board.display(); //! Clear the board

    //* Dislpay chess pieces
    wcout << endl;
    
    wcout << WHITE_KING << " " << WHITE_QUEEN << " " << WHITE_ROOK << " " << WHITE_BISHOP << " " << WHITE_KNIGHT << " " << WHITE_PAWN << endl;
    
    wcout << BLACK_KING << " " << BLACK_QUEEN << " " << BLACK_ROOK << " " << BLACK_BISHOP << " " << BLACK_KNIGHT << " " << BLACK_PAWN << endl;

    return 0;
}

///////////////
// Box Class //
///////////////

//* Constructor
Box::Box(wchar_t item) : item(item) {}

//* Display the box with the item
void Box::display()
{
    wcout << item;
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

            //! Even row
            if (i % 2 == 0)
            {
                //! Even column
                if (j % 2 == 0)
                    boxes[i][j] = Box(HOLLOW_CIRCLE);

                //! Odd column
                else
                    boxes[i][j] = Box(FILLED_CIRCLE);
            }

            //! Odd row
            else
            {
                //! Even column
                if (j % 2 == 0)
                    boxes[i][j] = Box(FILLED_CIRCLE);

                //! Odd column
                else
                    boxes[i][j] = Box(HOLLOW_CIRCLE);
            }
        }
    }
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

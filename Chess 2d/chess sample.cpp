/*
! Normal Example
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

! cross platform compatibility
#include <iostream>
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

int main() {

#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);  //! Windows: UTF-16
    std::wcout << L"♔ White King\n";       //! Wide-string (UTF-16)
#else
    std::cout << u8"♔ White King\n";       //! UTF-8 (Linux/macOS)
#endif

    return 0;
}

! Cross-platform sample code (C++ 17)
#include <iostream>
#include <string>

// Unicode Chess Pieces (UTF-8)
namespace ChessPieces {
    const std::string WhiteKing   = "♔";
    const std::string WhiteQueen  = "♕";
    const std::string WhiteRook   = "♖";
    const std::string WhiteBishop = "♗";
    const std::string WhiteKnight = "♘";
    const std::string WhitePawn   = "♙";
    const std::string BlackKing   = "♚";
    const std::string BlackQueen  = "♛";
    const std::string BlackRook   = "♜";
    const std::string BlackBishop = "♝";
    const std::string BlackKnight = "♞";
    const std::string BlackPawn   = "♟";
}

// Cross-platform Unicode setup
void setup_unicode_console() {
#ifdef _WIN32
    // Windows: Enable UTF-16 mode for wcout (optional)
    #include <io.h>
    #include <fcntl.h>
    _setmode(_fileno(stdout), _O_U16TEXT);
#endif
    // Linux/macOS: Just use UTF-8 (no setup needed)
}

int main() {
    setup_unicode_console();

    // Example chessboard (8x8 grid)
    std::string board[8][8] = {
        { ChessPieces::BlackRook, ChessPieces::BlackKnight, ChessPieces::BlackBishop, ChessPieces::BlackQueen, 
          ChessPieces::BlackKing, ChessPieces::BlackBishop, ChessPieces::BlackKnight, ChessPieces::BlackRook },
        { ChessPieces::BlackPawn, ChessPieces::BlackPawn,   ChessPieces::BlackPawn,   ChessPieces::BlackPawn,
          ChessPieces::BlackPawn, ChessPieces::BlackPawn,   ChessPieces::BlackPawn,   ChessPieces::BlackPawn },
        { " ", " ", " ", " ", " ", " ", " ", " " },
        { " ", " ", " ", " ", " ", " ", " ", " " },
        { " ", " ", " ", " ", " ", " ", " ", " " },
        { " ", " ", " ", " ", " ", " ", " ", " " },
        { ChessPieces::WhitePawn, ChessPieces::WhitePawn,   ChessPieces::WhitePawn,   ChessPieces::WhitePawn,
          ChessPieces::WhitePawn, ChessPieces::WhitePawn,   ChessPieces::WhitePawn,   ChessPieces::WhitePawn },
        { ChessPieces::WhiteRook, ChessPieces::WhiteKnight, ChessPieces::WhiteBishop, ChessPieces::WhiteQueen,
          ChessPieces::WhiteKing, ChessPieces::WhiteBishop, ChessPieces::WhiteKnight, ChessPieces::WhiteRook }
    };

    // Print the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

! Piece repsentation wrapper (ChatGPT)
enum class Piece {
    WhiteKing, WhiteQueen, WhiteRook, WhiteBishop, WhiteKnight, WhitePawn,
    BlackKing, BlackQueen, BlackRook, BlackBishop, BlackKnight, BlackPawn,
    Empty
};

std::string getUnicode(Piece piece) {
    using namespace ChessPieces;
    switch (piece) {
        case Piece::WhiteKing: return WhiteKing;
        case Piece::WhiteQueen: return WhiteQueen;
        case Piece::WhiteRook: return WhiteRook;
        case Piece::WhiteBishop: return WhiteBishop;
        case Piece::WhiteKnight: return WhiteKnight;
        case Piece::WhitePawn: return WhitePawn;
        case Piece::BlackKing: return BlackKing;
        case Piece::BlackQueen: return BlackQueen;
        case Piece::BlackRook: return BlackRook;
        case Piece::BlackBishop: return BlackBishop;
        case Piece::BlackKnight: return BlackKnight;
        case Piece::BlackPawn: return BlackPawn;
        default: return " ";
    }
}


! Notes:
1. The _setmode and _O_U16TEXT are Windows-specific. For Linux/macOS, you might need different setup. Just like cross-platform example above.

2. For cross-platform compatibility, you might want to wrap the console setup in platform-specific code.

3. Make sure your console/terminal uses a font that supports these Unicode characters (most modern ones do).

4. Notice there was a typo in WHITE_KNIGHT (should be WHITE_KNIGHT) which I've corrected in the example usage.

5. For C++20 and later, you could also use char8_t and UTF-8 string literals.
*/

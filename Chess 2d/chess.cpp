#include <iostream>

using namespace std;

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

int main()
{
    
}

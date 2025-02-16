#include <iostream>

using namespace std;

/////////////
// Colors
/////////////
class Color{
public:
    static const string Reset;
    class ForeGround{
        public:
            static const string Red;
            static const string Green;
            static const string Yellow;
            static const string Blue;
            static const string Cyan;
    };
};

// Reset
const string Color::Reset = "\033[0m";

// ForeGround Colors
const string Color::ForeGround::Red = "\033[91m";
const string Color::ForeGround::Green = "\033[92m";
const string Color::ForeGround::Yellow = "\033[93m";
const string Color::ForeGround::Blue = "\033[94m";
const string Color::ForeGround::Cyan = "\033[96m";

int main()
{
    string message = "Welcome to Tic Tac Game ☻";
    cout << Color::ForeGround::Green + message + Color::Reset << endl;
}

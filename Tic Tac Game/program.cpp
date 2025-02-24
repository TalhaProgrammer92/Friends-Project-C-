#include <iostream>

using namespace std;

//////////////////////////
// Foreground Colors
//////////////////////////
const string RESET = "\033[0m";
const string GREEN = "\033[32m";      /* Green */
const string YELLOW = "\033[33m";     /* Yellow */
const string BLUE = "\033[34m";       /* Blue */


int main()
{
    string message = "Welcome to Tic Tac Game";
    cout << Color::ForeGround::Green + message + Color::Reset << endl;
}

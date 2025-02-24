#include <iostream>

using namespace std;

//////////////////////////
//? Foreground Colors
//////////////////////////
const string RESET = "\033[0m";
const string GREEN = "\033[32m";      /* Green */
const string YELLOW = "\033[33m";     /* Yellow */
const string BLUE = "\033[34m";       /* Blue */
const string MAGENTA = "\033[35m";    /* Magenta */
const string CYAN = "\033[36m";       /* Cyan */


////////////////////////////
//? Functions (Prototypes)
////////////////////////////
void printColor(string text, const string color);
void printColor(char character, const string color);


////////////////////////////
//? Main Function
////////////////////////////
int main()
{
    string message = "Welcome to Tic Tac Game";
    cout << GREEN << message << RESET << endl;
}


////////////////////////////
//? Functions (Definition)
////////////////////////////
//* Print text (string) with color
void printColor(string text, const string color)
{
    cout << color << text << RESET;
}

//* Print text (char) with color
void printColor(char character, const string color)
{
    cout << color << character << RESET;
}
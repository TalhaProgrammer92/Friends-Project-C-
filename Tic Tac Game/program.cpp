#include <iostream>

using namespace std;

//////////////////////////
//? Foreground Colors
//////////////////////////
const string RESET = "\033[0m";
const string GREEN = "\033[32m";   /* Green */
const string YELLOW = "\033[33m";  /* Yellow */
const string BLUE = "\033[34m";    /* Blue */
const string MAGENTA = "\033[35m"; /* Magenta */
const string CYAN = "\033[36m";    /* Cyan */

//? Setting
struct Setting
{
    //? Player
    struct PlayerColor
    {
        const string wonColor = GREEN;
        const string signColor = YELLOW;
        const string nameColor = CYAN;
    };
    
    //? Board
    struct BoardColor
    {
        const string borderColor = BLUE;
    };

    //? Game
    struct GameColor
    {
        const string tieColor = MAGENTA;
        const string turnColor = CYAN;
        const string winColor = GREEN;
    };
};


////////////////////////////
//? Functions (Prototypes)
////////////////////////////
void printColor(string text, const string color);
void printColor(char character, const string color);

////////////////////////////
//? Player Class
////////////////////////////
class Player
{
    string name;
    char sign;

public:
    Player() {}
    Player(string name, char sign)
    {
        this->name = name;
        this->sign = sign;
    }
    string getName()
    {
        return name;
    }
    char getSign()
    {
        return sign;
    }
    void display()
    {
        printColor(name, Setting::PlayerColor().nameColor);
        cout << endl;
        printColor(sign, Setting::PlayerColor().signColor);
        cout << endl;
    }
};

////////////////////////////
//? Main Function
////////////////////////////
int main()
{
    Player p("Talha Ahmad", 'X');
    p.display();
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
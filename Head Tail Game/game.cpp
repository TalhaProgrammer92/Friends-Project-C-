#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

//////////////////////////////
//? Function Prototypes
//////////////////////////////
void shuffleVector(vector<int> &vec);

/////////////////////
//? Dice class
/////////////////////
class Dice
{

    vector<int> dice;

    void fill();

public:
    Dice();

    int get();
};

/////////////////////
//? Player class
/////////////////////
class Player
{
    //* Attributes
    string name;
    int score;

public:
    //* Constructor
    Player(string name)
    {
        this->name = name;
        this->score = 0;
    }
};

//////////////////////////////
//? Main Function
//////////////////////////////
int
main()
{
    Dice dice;

    while (true)
    {
        cout << "Press Enter to roll the dice...";
        cin.get();
        cout << "Dice:\t" << dice.get() << endl;
    }
}

//////////////////////////////
//? Function Definition
//////////////////////////////
void shuffleVector(vector<int> &vec)
{
    srand(time(0)); // Seed for randomization
    shuffle(vec.begin(), vec.end(), default_random_engine(rand()));
}

/////////////////////
//? Dice class
/////////////////////
void Dice::fill()
{
    vector<int> temp = {1, 2, 3, 4, 5, 6};
    shuffleVector(temp);
    dice = temp;
}

Dice::Dice()
{
    this->fill();
}

int Dice::get()
{
    if (dice.empty())
        this->fill();
    int result = dice.back();
    dice.pop_back();

    return result;
}
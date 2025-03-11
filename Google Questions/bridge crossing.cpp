#include <iostream>
#include <vector>

using namespace std;

/*
? Question

There are 4 person
1. A - 1 min
2. B - 2 min
3. C - 5 min
4. D - 10 min

They have to cross a bridge in minimum time (minutes). They have only 1 torch and the bridge can only hold 2 persons at the same time.
*/

//* Person class
class Person
{
    //* Person class with name and time_in_minutes
    string name;
    int time_in_minutes;

public:
    //? Constructor
    Person(string name, int time_in_minutes)
    {
        this->name = name;
        this->time_in_minutes = time_in_minutes;
    }

    //? Getters
    string get_name()
    {
        return name;
    }
    int get_time()
    {
        return time_in_minutes;
    }
};

//* Function to find the fastest person in a vector and return its address
Person* get_fastest_person(vector<Person>& persons)
{
    //* Find the fastest person
    Person fastest = persons[0];
    for (int i = 1; i < persons.size(); i++)
        if (persons[i].get_time() < fastest.get_time())
            fastest = persons[i];

    //* Return the fastest person
    return &fastest;
}

int main()
{
    //* Person objects
    vector<Person> left = {
        Person("A", 1),
        Person("B", 2),
        Person("C", 5),
        Person("D", 10)
    }, right;
    int total_persons = left.size();

    //* Algorithm to cross the bridge in minimum time
    while (right.size() != total_persons)
    {
        //* Find the fastest person in left
        
    }
    
}
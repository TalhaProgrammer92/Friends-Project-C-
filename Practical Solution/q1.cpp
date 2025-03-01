#include <iostream>

using namespace std;

/*
? Question

Write a program in C++ that contain:
1. Abstract Course class having data member name and a virtual function displayContent().
2. "Video Course" child class of Course and have data member duration in minutes and displayContent()
function.
3. "Text Course" child class of Course and have data member pages and displayContent() function.
4. Main function that do:
    a. Create array of Video and Text Courses.
    b. Get number of courses from user.
    c. Get data of each course from user.
    d. Display data of each course.
*/

//* Course class having data member name and a virtual function displayContent().
class Course
{
public:
    string name;
    virtual void displayContent() = 0;
};

//* "Video Course" child class of Course and have data member duration in minutes and displayContent() function.
class VideoCourse : public Course
{
public:
    int duration;
    void displayContent()
    {
        cout << name << " course contain " << duration << " minutes duration" << endl;
    }
};

//* "Text Course" child class of Course and have data member pages and displayContent() function.
class TextCourse : public Course
{
public:
    int pages;
    void displayContent()
    {
        cout << name << " course contain " << pages << " pages" << endl;
    }
};

int main()
{
    //* Create array of Video and Text Courses.
    VideoCourse *vc;
    TextCourse *tc;
    int n, vi, ti;

    //* Get number of courses from user.
    cout << "Enter number of courses: ";
    cin >> n;

    //* Allocate memory for n courses
    vc = new VideoCourse[n];
    tc = new TextCourse[n];

    //* Get data of each course from user.
    for (int i = 0; i < n; i++)
    {
        //* Get user's choice
        int choice;
        cout << "Enter type of course (1 for Video, 2 for Text): ";
        cin >> choice;

        //* Get data of choosen course by user
        switch (choice)
        {
            //* Video Course
        case 1:
            cout << "Enter name of Video Course: ";
            cin >> vc[vi].name;
            cout << "Enter duration of Video Course (in minutes): ";
            cin >> vc[vi].duration;
            vi++;
            break;

            //* Text Course
        case 2:
            cout << "Enter name of Text Course: ";
            cin >> tc[ti].name;
            cout << "Enter pages of Text Course: ";
            cin >> tc[ti].pages;
            ti++;
            break;

        default:
            break;
        }
    }

    //* Display data of each course.
    cout << "\n\n";
    for (int i = 0; i < vi; i++)
        vc[i].displayContent();
    
    for (int i = 0; i < ti; i++)
        tc[i].displayContent();
}

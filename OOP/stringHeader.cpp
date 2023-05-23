// Fig. 16.3: fig16_03.cpp
// Define class GradeBook with a member function that takes a parameter,
// create a GradeBook object and call its displayMessage function.

#include <iostream>
#include <string>

using namespace std;

class GradeBook {
    public:
        void displayMessage(string courseName) {
            cout<<"Welcome to the grade book for "<<courseName<<" !"<<endl;
        }
};

int main(void)
{
    GradeBook myGradeBook;

    string nameOfCourse;

    cout<<"Enter course name: "<<endl;
    getline(cin,nameOfCourse);   //read a course name with blanks
    cout<<endl;

    myGradeBook.displayMessage(nameOfCourse);


    return 0;
}
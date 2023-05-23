// Fig. 16.5: fig16_05.cpp
// Define class GradeBook that contains a courseName data member
// and member functions to set and get its value.
// Create and manipulate a GradeBook object with these functions.

#include <iostream>
#include <string>

using namespace std;

class GradeBook {
    public:
        void setCourseName(string name) {
            courseName = name;
        }

        string getCourseName() {
            return courseName;
        }

        void displayMessage() {
            cout<<"Welcome to the grade book for "<<getCourseName()<<" !"<<endl;
        }

    private:
        string courseName;

};

int main(void) {

    GradeBook myGradeBook;

    string nameOfCourse;

    cout<<"Initial course name is: "<<myGradeBook.getCourseName()<<endl;

    cout<<"Enter course name: ";
    getline(cin,nameOfCourse);

    myGradeBook.setCourseName(nameOfCourse);

    cout<<endl;

    myGradeBook.displayMessage();

    return 0;
}
// Fig. 16.1: fig16_01.cpp
// Define class GradeBook with a member function displayMessage,
// create a GradeBook object, and call its displayMessage function.

#include <iostream>

using namespace std;

class GradeBook {
    public:
        void displayMessage() {
            cout<<"Welcome to the Grade Book!"<<endl;
        }
};

int main(void) {
    GradeBook myGradeBook;
    
    myGradeBook.displayMessage();
    
    return 0;
}
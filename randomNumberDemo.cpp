/*//    Show how to use a random number generator

#include <iostream>
#include <ctime>        // Needed to set the random number seed to be the current time
using namespace std;    // So that we don't need to preface cin and cout with std::

int main() {
    // Seed the random number generator so that the results are predictably
    // the same.  Leave the seed to be 1 for the program you turn in, so that
    // your output will match the expected output.  Similarly if you call rand()
    // more times than needed, your output will not match the expected output.
    srand( 1);   // make it predictable for now

    cout << "Numbers that are the same every time: " << endl;
    // Generate some random numbers
    for( int i=0; i<3; i++) {
        cout << rand() << endl;
    }
    cout << endl;
    
    cout << "Numbers that are the same every time, in the range 0..99 : " << endl;
    // Generate some random numbers
    for( int i=0; i<3; i++) {
        // Get the remainder when you divide by 100, so the remainder will be 0..99
        cout << rand() % 100 << endl;
    }
    cout << endl;

    
    cout << "Now for numbers that are different every time: " << endl;
    
    // If instead you set the random number generator to be the time of day
    // then you always get a different sequence. DON'T do this for the code
    // you turn in to us, because your output will not match our expected output.
    srand( time( NULL));     // Seed the random number generator to be the time of day
    // Generate some random numbers
    for( int i=0; i<3; i++) {
        cout << rand() << endl;
    }
    cout << endl;

    return 0;
}*/

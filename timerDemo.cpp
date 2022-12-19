/*timerDemo.cpp
    Show how to implement a timer by keeping track of a starting time
    and the end time, and checking if the difference between those
    two times is within some preset limit.



#include <iostream>   // For Input and Output
#include <ctime>      // Timer functions
using namespace std;

//---------------------------------------------------------------------------
int timerDemo()
{
    char userInput = ' ';       // used for user input
    int elapsedSeconds = 0;     // Will store number of elapsed seconds
            
    // Declare a variable to hold a time, and set it to the current time
    time_t startTime = time( NULL);
    
    cout << "Press x and then enter when exactly 5 seconds have elapsed: ";
    cin >> userInput;
    
    // Find the difference between the current time and the start time
    elapsedSeconds = difftime( time( NULL), startTime);
    // Display the difference
    cout << "Elapsed time was " << elapsedSeconds << " seconds." << endl;
    
    return 0;
}
*/
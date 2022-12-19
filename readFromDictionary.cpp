/* readFromDictionaryAndLookup.cpp
    Show how to read from a dictionary file into a vector.
   Running program looks like:
   
        Reading words in from dictionary
        Dictionary has 263533 words.
        Here are a few dictionary words:
           0. banding
           1. tenon
           2. evolutionarily
           3. khalifate
           4. infangthiefs
        The word at position 10 is: aardvarks and has length 9
        Two words are: abandoner and abstractionist.
        compareValue is: 0


#include <iostream>   // For Input and Output
#include <fstream>    // For file input and output
#include <vector>     // Input file is stored in a vector
#include <cassert>    // For the assert statement used to validate file open
#include <cctype>     // Allows using the tolower() function
using namespace std;


//---------------------------------------------------------------------------
// Read words into dictionary vector.
// Dictionary must be a reference parameter, otherwise changes won't stick
// once we get back to the calling code.
void readWordsIntoDictionary( vector <string> & dictionary)
{
   // Read in dictionary into dictionary vector
    ifstream inStream;                      // Declare an input stream for reading
    inStream.open( "dictionary.txt");       // Open dictionary file
    assert( inStream.fail() == false );     // Ensure file open worked
    
    // If you had previously used vector dictionary, then you might want to clear it
    // before continuing to use it, though that is not the case here.
    dictionary.clear();
    
    // Keep repeating while input from the file yields a word
    string newWord;                         // Store a single input word
    while( inStream >> newWord) {           // While there is another word to be read
        // Add this new word to the end of the vector, growing it in the process
        dictionary.push_back( newWord);
    }
    
    // Close the dictionary file
    inStream.close();
}
    
    
//---------------------------------------------------------------------------
int main()
{
    vector< string> dictionary; // Stores words from input file into dictionary vector
    string someWord;            // User input word used to lookup in dictionary
    
    cout << "Reading words in from dictionary" << endl;
    readWordsIntoDictionary( dictionary);
    
    cout << "Dictionary has " << dictionary.size() << " words." << endl;
    cout << "Here are a few dictionary words:" << endl;
    for( int i=0; i<5; i++) {
        int wordIndex = rand() % dictionary.size();
        cout << "   " << i << ". " << dictionary.at( wordIndex) << endl;
    }
    
    // We can check the length of a word, storing it in a variable or using it in place
    int index = 10;
    cout << "The word at position " << index << " is: " <<  dictionary.at( index)
         << " and has length " << dictionary.at( index).length()
         << endl;
         
    // Strings can be contatenated, which can make it easier to create an output string
    string outputMessage = "";
    outputMessage = "Two words are: " + dictionary.at(51) +
                    " and " + dictionary.at(777) + ".";
    cout << outputMessage
         << endl;
    
    // Strings can also be compared using the .compare() function, which returns a value of
    // 0 when two strings are equal
    int compareValue = dictionary.at( 51).compare( "abandoner");
    cout << "compareValue is: " << compareValue << endl;
    
    return 0;
}//end main()*/

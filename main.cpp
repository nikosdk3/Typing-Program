/* ----------------------------------------------------------------------
    Program 3: Typing
        Typing program.

    Course: CS 141, Fall 2021
    System: Windows using Visual Studio Code, repl.it
    Author: Nikos Kotsopulos, Matthew Danque
    
    Running the program looks like:
        . . .
    Class: CS 141             
Program: #3 Typing      
  
There are 263533 words in the full dictionary.
There are 114 commonly misspelled words.

Select a menu option:
   1. Spell commonly misspelled words (timed)
   2. Type random words from full dictionary (timed)
   3. Display some words from one of the lists
   4. Use binary search to lookup a word in full dictionary
   5. Set word length to use with full dictionary
   6. Exit the program
Your choice --> 
   ----------------------------------------------------------------------
*/
//current progress on zybooks: 25/55
#include <iostream>
#include <vector> //vector use import
#include <fstream>//for inputting/ outputting the files
#include <cassert>// validates the file
#include <ctime>//used for timer
#include <string>
#include <ctime> //random number     
using namespace std;

vector<string> dictionary; //dictionary vector
vector<string> misspelled; //misspelled words vector
vector<string> correctMisspelled; //right hand side of misspelled
vector<string> incorrectMisspelled; //left hand side of misspelled //object of time_t, to be used later.
int bestScore = 0; //cumulative score at the end of the game
int incorrectCount; // words typed incorrectly
int correctCount; //word typed correctly
int wordLength = 5; // keeping track of wordLength for option 5
const void openOptions(int &option);//to avoid problems with functions not being declared when they call each other.

void dictionaryFunction(){ //import dictionary and misspelled
  
  ifstream inStream; //declared for reading into the input inStream
  inStream.open("dictionary.txt");
  assert(inStream.fail() == false);
  dictionary.clear();
  string newWord;

  while(inStream >> newWord) {
    dictionary.push_back(newWord);
  }
  inStream.close();

  inStream.open("misspelledWords.txt");
  assert(inStream.fail() == false);
  misspelled.clear();
  string newWord2;

  while(inStream >> newWord2){
    misspelled.push_back(newWord2);
  }
  inStream.close();
  for(int i = 0; i<misspelled.size();i++){
    if(i%2==0){
      incorrectMisspelled.push_back(misspelled.at(i));
    }
    else{
      correctMisspelled.push_back(misspelled.at(i));
    }
  }
}

void timerAndScore(vector<string> &userWords, int multiplier, int multiplier2) { // keeps track of time and updates score
    //multiplier parameters are used to change points per word for option 1 and 2
    int elapsedSeconds = 0;     // Will store number of elapsed seconds
    int secondsGoal = 15;
    int bonus = (secondsGoal - elapsedSeconds)*2;
    int tempScore=0;
            
    // Declare a variable to hold a time, and set it to the current time
    time_t startTime = time(NULL);
    
    // Find the difference between the current time and the start time
    elapsedSeconds += difftime(time(NULL), startTime);

    // Display the difference
    if(elapsedSeconds<secondsGoal){
      cout << "   Elapsed time: " << elapsedSeconds << " seconds. " << bonus << " point bonus for finishing " << secondsGoal-elapsedSeconds <<" seconds early."<< endl;
    } else{
      cout << "   Elapsed time: " << elapsedSeconds << " seconds. " << bonus << " points for finishing " << elapsedSeconds-secondsGoal <<" seconds late."<< endl;
    }
    cout<< "   "<<correctCount*multiplier << " points: " << correctCount << " spelled correctly x " << multiplier << " points each"<<endl;
    if(incorrectCount!=0){
      cout<< "   "<<incorrectCount*multiplier2<<" point penalty: " << incorrectCount << " spelled incorrectly x " << multiplier2 << " points each"<<endl;
    }
    tempScore=bonus+(correctCount*multiplier)-(incorrectCount*multiplier2);
    cout<<"   Score: " <<tempScore<<endl;
    if(tempScore>bestScore){
      bestScore=tempScore;
    }
    return;
}

//dictSize is the size of the array.
//this was made due to the test cases adding more not found outputs than the 1.
void binarySearch2(vector<string> &dictionary, int dictSize, string key) {//function for option 4
  int count = 1;
  int middle;
  int high = dictSize - 1;
  int low = 0;
  while (high >= low){
    middle = ((high + low)/2);
    if (dictionary.at(middle) == key) {//checks to see if the word is the same
      cout << count << ". Comparing to: " << dictionary.at(middle) << endl;
      break;
    //checks if its in the lesser half
    } else if (dictionary.at(middle) >= key) {
      cout << count << ". Comparing to: " << dictionary.at(middle) << endl;
      count++;
      high = middle - 1;
    //Checking if the search element is present in greater half
    } else if(dictionary.at(middle) <= key) {
      cout << count << ". Comparing to: " << dictionary.at(middle) << endl;
      count++;
      low = middle + 1;
    }
  }
  if(dictionary.at(middle).compare(key)==0)//print if found or not found
    {
      cout<< key << " was found."<<endl;
      return;
    }
    else{
      cout<< key <<" was NOT found."<<endl;
      return;
    }
}

void menuDisplay(){//at the start of the program or when an option is done, display this menu again
  cout<<"Select a menu option:"<<endl; 
  cout<<"   1. Spell commonly misspelled words (timed)"<<endl;
  cout<<"   2. Type random words from full dictionary (timed)"<<endl;
  cout<<"   3. Display some words from one of the lists"<<endl;
  cout<<"   4. Use binary search to lookup a word in full dictionary"<<endl;
  cout<<"   5. Set word length to use with full dictionary"<<endl;
  cout<<"   6. Exit the program"<<endl;
  cout<<"Your choice --> ";
}

void getInput(string &word, int &option){//function to execute binary search function.
  while (option != 6){
    cout << "Enter the word to lookup: ";
    cin>>word;
    binarySearch2(dictionary,dictionary.size(),word);
    openOptions(option);
  }
}

//opens the options menu + display menu
const void openOptions(int &option){
  string word;
  string word1,word2,word3,word4,word5;
  menuDisplay();
  cin>> option;
  //checking user input for the menu option
  if(option == 1){//code that works option 1 
    vector<string> userWords;
    vector<string> incorrectRandVector;
    vector<int> nums;
    int misspelled=0;
    int multiplierCorrect=3;
    int multiplierIncorrect=6;
    cout<<"Using commonly misspelled words"<<endl;
    for( int i=0; i<5; i++) {//gets 5 random words, pushes them into a new vector, and prints them
      nums.push_back(rand()%incorrectMisspelled.size());
      incorrectRandVector.push_back(incorrectMisspelled.at(nums.at(i)));
      cout<<incorrectRandVector.at(i)<<" ";
    }
    cout<<endl;
    cout<<"Type in those words within goal of 15 seconds: "<<endl;
    cin >> word1 >> word2 >> word3 >> word4 >> word5;
    userWords.push_back(word1);
    userWords.push_back(word2);
    userWords.push_back(word3);
    userWords.push_back(word4);
    userWords.push_back(word5);//getting words of user
    for(int i = 0;i<5;i++){//comparing user word to the random for spelling
      if(correctMisspelled.at(nums.at(i)).compare(userWords.at(i))!=0){
        misspelled++;
        incorrectCount++;
      }
      else if(correctMisspelled.at(nums.at(i)).compare(userWords.at(i))==0){
        correctCount++;
      }
    }
    if(misspelled==0){
      cout<<"   No misspelled words!"<<endl;
    } else{
      cout<<"   Misspelled words: "<<endl;
    }
    for(int i = 0; i<5;i++){//executes if there are misspelled words
      if(correctMisspelled.at(nums.at(i)).compare(userWords.at(i))!=0){
        cout<<"       "<<userWords.at(i)<< " should be: " << correctMisspelled.at(nums.at(i)) <<endl;
      }
    }
    timerAndScore(userWords,multiplierCorrect,multiplierIncorrect);//shows elapsed time and point breakdown
    incorrectCount=0;
    correctCount=0;
    misspelled=0;//resetting all variables
    openOptions(option);
  }

  else if(option == 2){//option 2
    vector<string> dictWords;
    vector<string> dictVector;
    int dictMisspelled=0;
    int multiplier = wordLength-4;
    int multiplierWrong = multiplier*2;
    cout<<"Using full dictionary"<<endl;
    while(dictVector.size()<5){//5 random words from dictionary with length wordLength
      int randNum = rand() % dictionary.size();
      if(dictionary[randNum].length()==wordLength){
        cout<<dictionary[randNum]<<" ";
        dictVector.push_back(dictionary[randNum]);
      }
    }
    cout<<endl;
    cout<<"Type in those words within goal of 15 seconds: "<<endl;
    cin >> word1 >> word2 >> word3 >> word4 >> word5;
    dictWords.push_back(word1);
    dictWords.push_back(word2);
    dictWords.push_back(word3);
    dictWords.push_back(word4);
    dictWords.push_back(word5);//getting user input
    for(int i = 0;i<5;i++){//comparing user input to dictionary words
      if(dictVector.at(i).compare(dictWords.at(i))!=0){
        dictMisspelled++;
        incorrectCount++;
      }
      else if(dictVector.at(i).compare(dictWords.at(i))==0){
        correctCount++;
      }
    }
    if(dictMisspelled==0){
      cout<<"   No misspelled words!"<<endl;
    } else{
      cout<<"   Misspelled words: "<<endl;
    }
    for(int i = 0; i<5;i++){//shows what words user incorrectly spelled
      if(dictVector.at(i).compare(dictWords.at(i))!=0){
        cout<<"       "<<dictWords.at(i)<< " should be: " << dictVector.at(i) <<endl;
      }
    }
    timerAndScore(dictWords,multiplier, multiplierWrong);// displays elapsed time and scores
    incorrectCount=0;
    correctCount=0;
    dictMisspelled=0;//resetting 
    wordLength++;//increasing wordLength every time option 2 is executed
    openOptions(option);
  }

  else if(option == 3){//option 3
    char option3;
    cout<<"Displaying word list entries."<<endl;
    cout<<"Which words do you want to display?"<<endl;
    cout<<"  A. Dictionary of all words"<<endl;
    cout<<"  B. Wrongly spelled common misspelled words"<<endl;
    cout<<"  C. Correctly spelled common misspelled words"<<endl;
    cout<<"Your choice -->";
    cin>>option3;
    if(option3=='a'){//executes for 'a' input
      int startindex;
      int endindex;
      cout<<"Enter the start and end indices between 0 and 263532: ";
      cin>>startindex;
      cin>>endindex;
      for(int i = startindex;i<=endindex;i++){//displaying words in an index range from the dictionary
        cout<< i <<". "<<dictionary.at(i)<<endl;
      }
      openOptions(option);
    }
    else if(option3=='b'){
      int startindex;
      int endindex;
      cout<<"Enter the start and end indices between 0 and 113: ";
      cin>>startindex;
      cin>>endindex;
      for(int i = startindex*2;i<=endindex*2;i+=2){//displaying the incorrect words in an index range from the misspelled list
        cout<< i/2 <<". "<<misspelled.at(i)<<endl;
      }
      openOptions(option);
    }
    else if(option3=='c'){
      int startindex;
      int endindex;
      cout<<"Enter the start and end indices between 0 and 113: ";
      cin>>startindex;
      cin>>endindex;
      for(int i = startindex*2;i<=endindex*2;i++){//displaying the correct words in an index range from the misspelled list
        if(i%2==0){
          cout<< i/2 <<". "<<misspelled.at(i+1)<<endl;
        }
      }
      openOptions(option);      
    }
  }

  else if(option==4){//option 4
      getInput(word,option);//executes binary search function
  }

  else if (option==5){//option 5
    int newWordLength;
    cout<<"Enter new wordLength: ";
    cin>>newWordLength;
    wordLength=newWordLength;//user setting their own word length to use for option 2
    openOptions(option);
  }

  else if(option==6){//option 6; exits program
    cout<<"Exiting program"<<endl;
    cout<<"Best score was "<< bestScore;
    return;
  }
}

int main() {
  srand(1);//seed for the random numbers
  dictionaryFunction();
  cout << "There are " << dictionary.size() << " words in the full dictionary." << endl;
  cout << "There are " << misspelled.size()/2 << " commonly misspelled words." << endl;
  int option = 0;//default option
  openOptions(option);
  return 0;
}
//this is a simple pig latin prorgam
// there is a bug with the word cool
#include <iostream>
#include <string>

using namespace std;


bool isVowel(char x){
  if((x) == 'a'||(x) == 'e'||(x) == 'i'||(x) == 'o'||(x) == 'u'||(x) == 'y'){
    return true;
  }
  else{
    return false;
  }
}

bool isConsonant(char s){
  if(tolower(s) == 'b'||(s) == 'c'||(s) == 'd'||(s) == 'f'||
  (s) == 'g'||(s) == 'h'||(s) == 'j'||(s) == 'k'||(s) == 'l'||
  (s) == 'm'||(s) == 'n'||(s) == 'p'||(s) == 'q'||(s) == 'r'||
  (s) == 's'||(s) == 't'||(s) == 'v'||(s) == 'w'||(s) == 'x'||(s) == 'y'||(s) == 'z'){
    return true;
  }
  else{
    return false;
  }
}

string converter(string input){
  if(input.length() < 2){
    if(isVowel(input[0])){
      input += "way";
      return input;
    }
    else if(isConsonant(input[0])){
      return input;
    }
  }
  char firstLetter = input[0];
  char secondLetter = input[1];
  string way = "way";
  string ay = "ay";
  if(isVowel(firstLetter)){ // this works
    input += way;
    return input;
  }
  if(isConsonant(firstLetter)){
    if(isConsonant(secondLetter)){
      string newString = "";
      for(int i = 2; i < input.length() - 2; i++){
        char ch = input[i];
        newString += ch;
      }
      newString += firstLetter;
      newString += secondLetter;
      newString += ay;
      return newString;
    }
    else if(isVowel(secondLetter)){
      string newstring;
      for(int i = 1; i < input.length() - 1; i++){
        char k = input[i];
        newstring += k;
      }
      newstring += firstLetter;
      newstring += ay;
      return newstring;
    }
  }
}


int main(){
  cout << "welcome to the pig latin program!" << endl;
  bool flag = true;
  while(flag == true){
    int choice;
    cout << "if you would like to translate a single word|| press 1" << endl;
    cout << "if you would like to translate an entire sentence, press 2" << endl;
    cout << "if you would like to exit the program, press 3" << endl;
    cout << "Choice:";
    cin >> choice;
    if(choice == 1){
      string wordTranslate;
      cout << "you have chosen to translate a single word"<< endl;
      cout << "Enter a single word: ";
      cin >> wordTranslate;
      cout << endl;
      wordTranslate = converter(wordTranslate);
      cout << wordTranslate << endl;
      cout << endl;
    }
    else if(choice == 2){
      string sample;
      cout << "You have chosen to translate a sentence" << endl;
      cout << "Enter a sentence with spaces: " << endl;
      cin.ignore();
      getline(cin, sample);
      sample = sample += " ";
      cout << endl;
      int sampleCounter = 1;
      for(char x : sample){
        if(x == ' '){
          sampleCounter += 1;
        }
      }
      string sampleArray[sampleCounter];
      int indexArray = 0;
      string outputword = "";
      cout << "The answer is: ";
      for(char str : sample){
        if(str == ' '){
          sampleArray[indexArray] = outputword;
          outputword = "";
          indexArray += 1;
        }
        else{
          outputword += str;
        }
      }
      for(string fir : sampleArray){
        cout << converter(fir) + " ";
      }
      cout << endl;
      cout << endl;
    }
    else if(choice == 3){
      cout << "exiting program" << endl;
      exit(0);
    }
    else{
      cout << "invlaid input" << endl;
    }
  }
}

#include <iostream>
#include<fstream>
#include <vector>
#include <stdlib.h>   
using namespace std;

int getUserInput() {
    int amount = 0;
    cout << "Type a number for how many words you want in your passphrase\n";
    try {
        cin >> amount;
    }catch(exception e) {
        cout << "Invalid input, type a number such as 5 or 10\n";
    }
    return amount;
}

string getWordsFromFile(int amount) {
    int lineCount = 0;
    string currentWord;
    string passPhrase = "";
    vector<string> wordList;
    
    fstream filePath("words_alpha.txt");
    while(getline(filePath,currentWord)) {
        wordList.push_back(currentWord);
        lineCount += 1;
       // cout << currentWord << endl;
    
    }
     filePath.close();
    for(int i = 0; i < amount; i++) {
        int rn = rand() % lineCount - 1;
        passPhrase.append(wordList[rn]);
    }

   
    return passPhrase;
}

int main() {
     srand(time(0)); // used to randomize 
    std::cout.flush();
 string result = getWordsFromFile(getUserInput());
cout << result << endl;
 
 cout << endl;
//std::cout << combinedWords << endl;
    std::cout.flush();
   
    cin.get();
 


return 0;
}
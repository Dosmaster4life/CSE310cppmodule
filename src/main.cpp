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

vector<string> getWordsFromFile(int amount) {
    int lineCount = 0;
    string currentWord;
    vector<string> listOfWords;
    vector<string> wordList;
    
    ifstream filePath("words_alpha.txt");
    while(getline(filePath,currentWord)) {
        wordList.push_back(currentWord);
        lineCount += 1;
    
    }
    for(int i = 0; i < amount; i++) {
        listOfWords.push_back(wordList[rand() % lineCount]);
    }


    return listOfWords;
}

int main() {
 vector<string> result = getWordsFromFile(getUserInput());
    string combinedWords = "";
 for(int i = 0; i < result.size(); i++) {
    combinedWords += result[i] +  " ";
    cout << result[i] << endl;
    cin.get();
    cin.get();

 }
cout << combinedWords << endl;
 
 


return 0;
}
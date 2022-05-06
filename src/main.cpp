#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <Time.h>
using namespace std;

class PassPhraseCreation
{

public:
    string promptFilePath() // returns the name the user wants for the text file
    {
        cout << "Type a filename for this passphrase to be saved.";
        cout << endl;
        string filename = "";
        cin >> filename;
        return filename;
    }
    bool writeAnother() // returns whether the user wants to generate and write another passphrase to a file
    {
        string writeAnother = "";
        cout << "Would you like to generate another Passphrase, y for yes or anything else to exit)\n";
        cin >> writeAnother;
        if (writeAnother == "y" || writeAnother == "Y" || writeAnother == "Yes" || writeAnother == "yes")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getUserInput() // Asks the user how many words they want in the passphrase
    {
        int amount = 0;

        cout << "Type a number for how many words you want in your passphrase\n";
        ;
        try // catches errors if the user types a number or an invalid charactar
        {
            cin >> amount;
        }
        catch (exception e)
        {
            cout << "Invalid input, type a number such as 5 or 10\n";
        }
        return amount;
    }
    void writeStringToFile(string fileContents, string filename)
    {
        ofstream outputFile; // used for writing to files
        outputFile.open(filename + ".txt"); // opens a new file with the users desired file name
        outputFile << fileContents; // writes to the file
        outputFile.close(); // closes the file
    }
    string getWordsFromFile(int amount) // reads the passphrases and chooses random words to return as one string
    {
        int lineCount = 0;
        string currentWord;
        string passPhrase = "";
        vector<string> wordList; // a vector that contains every word in the word list

        fstream filePath("words_alpha.txt"); // opens the file containing every passphrase word
        while (getline(filePath, currentWord)) // reads each word line by line
        {
            wordList.push_back(currentWord); // adds each word to the vector
            lineCount += 1; // counts how many lines are in the file
            // cout << currentWord << endl;
        }

        filePath.close(); // closes the file
         srand(time(0)); // used to randomize based on time
        for (int i = 0; i < amount; i++)
        {
            string randomString = wordList[rand()%lineCount] + ' ';
            passPhrase.append(randomString); // The random word is added to the final passphrase
        }

        return passPhrase;
    }
};

int main()
{
    bool isRunning = true; // while true the loop will allow more passphrases to be created
    PassPhraseCreation prompt; // class containing each method neccessary to run the program
    do
    {

        std::cout.flush(); // used to help display output on m1 mac
        string result = prompt.getWordsFromFile(prompt.getUserInput()); // gets the passphrase
        cout << result << endl; // displays the passphrase

        cout << endl;

        string filename = prompt.promptFilePath(); // Gets the desired filename from the user
        cout << endl;
        prompt.writeStringToFile(result, filename); // writes the passphrase to a file
        cout << "File written to successfully.\n"; // Lets the user know the operation was completed
        std::cout.flush(); // helps with display output on m1 mac

        isRunning = prompt.writeAnother(); // checks if the user wants to create more passphrases.

    } while (isRunning); // while the user wants to create more passphrases, loop

    return 0;
}

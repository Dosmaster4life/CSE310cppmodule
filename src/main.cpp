#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <Time.h>
using namespace std;

class PassPhraseCreation
{

public:
    string promptFilePath()
    {
        cout << "Type a filename for this passphrase to be saved.";
        cout << endl;
        string filename = "";
        cin >> filename;
        return filename;
    }
    bool writeAnother()
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
    int getUserInput()
    {
        int amount = 0;

        cout << "Type a number for how many words you want in your passphrase\n";
        ;
        try
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
        ofstream outputFile;
        outputFile.open(filename + ".txt");
        outputFile << fileContents;
        outputFile.close();
    }
    string getWordsFromFile(int amount)
    {
        int lineCount = 0;
        string currentWord;
        string passPhrase = "";
        vector<string> wordList;

        fstream filePath("words_alpha.txt");
        while (getline(filePath, currentWord))
        {
            wordList.push_back(currentWord);
            lineCount += 1;
            // cout << currentWord << endl;
        }
        filePath.close();
        for (int i = 0; i < amount; i++)
        {
            int rn = rand() % lineCount - 1;
            passPhrase.append(wordList[rn] + ' ');
        }

        return passPhrase;
    }
};

int main()
{
    bool isRunning = true;
    PassPhraseCreation prompt;
    do
    {
        srand(time(0)); // used to randomize
        std::cout.flush();
        string result = prompt.getWordsFromFile(prompt.getUserInput());
        cout << result << endl;

        cout << endl;

        string filename = prompt.promptFilePath();
        cout << endl;
        prompt.writeStringToFile(result, filename);
        cout << "File written to successfully.";
        std::cout.flush();

        isRunning = prompt.writeAnother();

    } while (isRunning);

    return 0;
}

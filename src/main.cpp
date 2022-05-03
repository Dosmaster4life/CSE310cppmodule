#include <iostream>
#include<fstream>
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

int main() {
getUserInput();

return 0;
}
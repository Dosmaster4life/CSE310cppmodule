# Overview

PassPhrase is a program that generates pass phrases and saves them for the user to view later. 

PassPhrase does the following, 
1. Prompts the user how many words they want in a pass phrase
2. Searches a file and selects random pass phrases
3. Displays the pass phrase
4. Prompts the user to ask what filename they want.
5. Saves the passphrase to a file
6. Repeats if the user wants to create more pass phrases.


This software was developed to help users create unique pass phrases. Often hardware wallets for crypto currency have pass phrases as a backup if the user forgot their password. PassPhrase will create unique pass phrases based on how many words the user wants in their phrase.


[Software Demo Video](https://youtu.be/GR01rjbUmFI)

# Development Environment

I developed this in Visual Studio Code and Codeblocks

I used C++ with (iostream, fstream, vector, stdlib.h, Time.h)

# Useful Websites

* [W3 Schools](https://www.w3schools.com/cpp/cpp_class_methods.asp)
* [cpluscplus.com](https://www.cplusplus.com/doc/tutorial/files/)

# Future Work

* Pass Phrases are in an encrypted file
* Pass Phrases are protected by a password
* A graphical user interface
* A better random function
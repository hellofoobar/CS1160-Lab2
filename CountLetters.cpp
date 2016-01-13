//
//  CountLetters.cpp
//  Lab2

//
//  Created by Jun Yuan on 2016-01-13.
//  Copyright © 2016 Jun Yuan. All rights reserved.

// This program ask user for a sentence and outputs the number of occurences for each alphabet (case insensitive) in the sentence excluding zero occurences.

#include <iostream>

using namespace std;

char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','r','s','t','u','v','w','x','y','z'};
const int LETTERS_IN_ALPHABET = 26;
int counts[LETTERS_IN_ALPHABET];

void count(const string& s, int counts[]) {
    // loop through char in string then loop through alphabet until one matches char, increment counts array at index of alphabet
    for (int i = 0; i < s.length(); i++) {
        bool found = false;
        int j = 0;
        while (!found && j < LETTERS_IN_ALPHABET) {
            if ( s[i] == alphabet[j] ) {
                counts[j]++;
                found = true;
            }
            j++;
        }
    }
    // loop through counts array and prints occurences of each alphabet
    for (int i = 0; i < LETTERS_IN_ALPHABET; i++) {
         if ( counts[i] > 0 ) {
             if (counts[i] == 1) {
                cout << alphabet[i] << ": " << counts[i] << " time\n"; // details matter
             } else {
                cout << alphabet[i] << ": " << counts[i] << " times\n";
             }
        }
    }
    
}

string toLower(string input) {
    for (int i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
    return input;
}

int main() {
    cout << "Enter a string: ";
    string input;
    getline(cin, input);
    const string lowercaseStr = toLower(input); // convert input to lowercase before calling count
    count(lowercaseStr, counts);
    
    cout << "\nPress ENTER to terminate...";
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    return 0;
}

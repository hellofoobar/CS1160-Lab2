//
//  CheckPalinPrime.cpp
//  Lab2
//
//  Created by Jun Yuan on 2016-01-12.
//  Copyright © 2016 Jun Yuan. All rights reserved.

// This program outputs the first hundred palindromic primes for users to geek over.

#include <iostream>
#include <math.h>

using namespace std;

int printCount = 0; // keep track of numbers printed to console

void printFormattedTenPerLine(int num) {
    printCount++;
    cout.width(5);
    cout << right << num << " ";
    if ( (printCount % 10) == 0 ) {
        cout << endl;
    }
}

bool isPalindrome(int num) {
    // reverse num then compare
    int lastDigit = 0;
    int reverse = 0;
    int n = num;
    
    while (num > 0) {
        lastDigit = num % 10;
        reverse = reverse*10 + lastDigit;
        num /= 10;
    }
    
    if (n == reverse) {
        return true;
    }
    return false;
}

bool isPrimeTrialDivision(int num) {
    //prime test through trial division from 3 to square root of num
    //even num skipped in main() hence starting at 3
    for (int i = 3; i <= sqrt(num); i++) {
        if ( (num % i) == 0 ) {
            return false;
        }
    }
    
    return true;
}

long modularExponentiation(long factor, long power, long mod){
    long result = 1;
    
    while (power > 0){
        if (power&1) {
        result *= factor;
        result %= mod;
        }
        power >>= 1;
        factor *= factor;
        factor %= mod;
    }
    return result;
}

bool isPrimeFermatsLittleTheorem(int num){
    // prime test using Fermats little theorem (less reliable due to false positives)
    // If p is a prime number, then for any integer a, a^p − a will be evenly divisible by p
    // a^p ≡ a mod p  ==  a^(p-1) ≡ 1 mod p
    long a;

    // set test loop to at least 6 times to prevent the palindromic Carmichael number 101101 from ruin the party if testing for first 114 palindromic primes
    for ( int i = 0; i < 6; i++ ){
        a = rand() % num;
        if ( a == 0 || a == 1 )
            a++;
        if ( modularExponentiation(a, num-1, num) != 1 )
            return false;
    }
    
    return true;
}

int main() {
    const int sizePalinPrimes = 100;
    int numPalinPrimes = 0;
    int i = 3; // iterator starting at 3
    
    cout << "The first " << sizePalinPrimes << " palindromic primes are: \n\n";
    
    //a case to handle 2
    printFormattedTenPerLine(2);
    numPalinPrimes++;
    
    while (numPalinPrimes < sizePalinPrimes) {
        //do palindrome check before prime check since there are less palindrome numbers than primes
        if ( isPalindrome(i) && isPrimeTrialDivision(i) ) {
           printFormattedTenPerLine(i);
           numPalinPrimes++;
        }
        
        i += 2; // even numbers are a composite witness, skip all even numbers to cut iterations in half
    }
    
    cout << "\nPress ENTER to terminate...";
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    return 0;
}


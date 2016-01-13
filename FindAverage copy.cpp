//
//  FindAverage.cpp
//  Lab2
//
//  Created by Jun Yuan on 2016-01-12.
//  Copyright © 2016 Jun Yuan. All rights reserved.

//  This program output the average of two explicitly defined arrays of type int and double.
//  ASIDE: Function template would be more appropriate over overloading for this case since operations are same following DRY principle and polymorphism. But for the sake of sticking to specs, overloading is used.

#include <iostream>
#include <cstdlib>

using namespace std;

double average(const int num[] , int size) {
    double sum = 0;
    
    for (int i = 0; i < size ; i++) {
        sum += num[i];
    }
    return (sum / size);
}

double average(const double num[] , int size) {
    double sum = 0.0;
    
    for (int i = 0; i < size; i++) {
        sum += num[i];
    }
    return (sum / size);
}

int main() {
    const int SIZE = 10;
    int arrInteger[]  = {0, 1, 2 , 3, 4, 5, 6, 7, 8, 9};
    double arrDouble[] = {0.0, 1.0, 2.0 , 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    double arrIntegerAvg;
    double arrDoubleAvg;
    
    arrIntegerAvg = average(arrInteger, SIZE);
    arrDoubleAvg = average(arrDouble, SIZE);
    
    cout << "The average of int array " << "{0, 1, 2 , 3, 4, 5, 6, 7, 8, 9}" << " is " << arrIntegerAvg << "\n";
    cout << "The average of double array " << "{0.0, 1.0, 2.0 , 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0}" << " is " << arrDoubleAvg << "\n";
    
    cout << "\nPress ENTER to terminate...";
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    
    return 0;
}


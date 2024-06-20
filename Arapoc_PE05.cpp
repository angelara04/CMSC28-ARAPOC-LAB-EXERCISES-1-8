// Angel Grace P. Arapoc 
// BSCS CMSC 28 Programming Exercise 05 - OOP 1
// May 11, 2024

#include <iostream>
#include <cmath>
#include <iomanip>

const int MAX = 10; //input limit
int i; 	//Global variable for loops

//Accepting inputs until 0 or up to max size
void inputNumbers(int num[], int &size) {
	std::cout << "Programming Exercise 05\nSubmitted by: Angel Grace P. Arapoc\n-------------------------------------------------------------------------------\nThis program will ask the user to input various numbers \n(positive or negative but not zero) and perform basic statistics on these numbers.\n" << std::endl;
    std::cout << "Enter integers (0 to stop):" << std::endl;
    int input;
    
    for (size = 0; size < MAX; ++size) {
        std::cout << "Input an integer: ";
        std::cin >> input;
        if (input == 0 || size == MAX) break;
        num[size] = input;
    }
}


//Finding the largest number
int Largest(int num[], int size) {
    int largest = num[0];
    for (i = 1; i < size; ++i) {
        if (num[i] > largest) largest = num[i];
    }
    return largest;
}

//Finding the smallest number
int Smallest(int num[], int size) {
    int smallest = num[0];
    for (i = 1; i < size; ++i) {
        if (num[i] < smallest) smallest = num[i];
    }
    return smallest;
}

//Finding the average 
float Average(int num[], int size) {
    double sum = 0;
    for (i = 0; i < size; ++i) {
        sum += num[i];
    }
    return sum / size;
}

//Finding the variance
float Variance(int num[], int size, double average) {
    double variance = 0;
    for (i = 0; i < size; ++i) {
        variance += pow(num[i] - average, 2);
    }
    return variance / size;
}

//Finding the standard deviation
float StandardDeviation(double variance) {
    return sqrt(variance);
}

//Output statistics with precision
void output(int largest, int smallest, double average, double standardDeviation, double variance) {
    std::cout << "\nLargest:\t\t " << largest << std::endl;
    std::cout << "Smallest: \t \t" << smallest << std::endl;
    std::cout << "Average: \t\t" << std::fixed << std::setprecision(2) << average << std::endl;
    std::cout << "Standard deviation: \t" << std::fixed << std::setprecision(2)<<standardDeviation << std::endl;
    std::cout << "Variance: \t\t" <<std::fixed << std::setprecision(2) << variance << std::endl;
}

//Main function
int main() {
    int number[MAX];
    int size;
    inputNumbers(number, size);
    
    int largest = Largest(number, size);
    int smallest = Smallest(number, size);
    float average = Average(number, size);
    float variance = Variance(number, size, average);
    float standardDeviation = StandardDeviation(variance);
    
    output(largest, smallest, average, standardDeviation, variance);
    
    return 0;
}


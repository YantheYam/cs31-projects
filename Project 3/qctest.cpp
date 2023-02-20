// Ryan Lim, 005969674
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// prototyping functions
bool isValidQC(string results);
bool isValidQCHelper(string subResults);
int passQC(string results);
int defectQC(string results);
int totalQC(string results);
int batches(string results);

int main() {
    string inputString = "Q2d0p2Q3d3p0Q4d2p2Q5d2p3Q6p3d3Q7p4d3Q8p5d3Q9p3d6";
    // assert (isValidQC(inputString) == true);

    // cout << "Enter input: ";
    // getline(cin, inputString);
        cout << "Input is " << inputString;
        cout << "\nInput is " << boolalpha << isValidQC(inputString);
    // if (isValidQC(inputString)) {
        cout << "\nTotal number of batches: " << batches(inputString);
        cout << "\nTotal number of tests: " << totalQC(inputString);
        cout << "\nTotal number of passes: " << passQC(inputString);
        cout << "\nTotal number of defects: " << defectQC(inputString);
    // } else cout << "Input is invalid";

    return 0;
}

bool isValidQC(string results) {
    int startPos = 0;
    int endPos = 1;
    string subResults = "";

    if (size(results) < 6) return false; // checks that string is correct size

    while (endPos <= size(results)) { // runs until end of string
        for (endPos; results[endPos] != 'Q' &&endPos < size(results); endPos++); // used to increment endPos until next Q or end of string
        subResults = results.substr(startPos, endPos - startPos); // creates substring        
        if (size(subResults) < 6) return false; // checks that substring is correct size
        if (!isValidQCHelper(subResults)) return false; // calls helper function with actual QC checks

        startPos = endPos; // sets startPos to position of next Q
        endPos++; // sets endPos to position of next Q + 1
    }

    return true;
}

bool isValidQCHelper(string subResults) { // helper function used so that isValidQC doesn't get too messy
    int numQ = 0, numP = 0, numD = 0;
    string temp = "";

    if (subResults[0] != 'Q') return false; // checks if starts with Q
    if (size(subResults) < 6) return false; // checks if batch is correct size
    if (subResults[1] == '0') return false; // checks for 0 after Q
    
    for (int i = 0; i < size(subResults); i++) { // checks for leading zeroes
        if (subResults[i] == '0') { 
            if (isdigit(subResults[i + 1])) return false; 
        }
    }

    for (int i = 0; i < size(subResults); i++) { // checks that all letters are either Q, p, or d
        if (subResults[i] == ' ') return false; // checks that there are no spaces
        if (isalpha(subResults[i])) {
            if (subResults[i] != 'Q' && subResults[i] != 'p' && subResults[i] != 'd') return false;
        }
    }

    int qCheck = 0, pCheck = 0, dCheck = 0;
    for (int i = 0; i < size(subResults); i++) { // checks that there are only one Q, one P, and one D
        if (subResults[i] == 'Q') qCheck++;
        if (subResults[i] == 'p') pCheck++;
        if (subResults[i] == 'd') dCheck++;
    }
    if (qCheck != 1 || pCheck != 1 || dCheck != 1) return false;

    for (int i = 0; i < size(subResults); i++) { // finds number of tests, number of passes, and number of defects
        if (subResults[i] == 'Q' || subResults[i] == 'p' || subResults[i] == 'd')
            if (!isdigit(subResults[i + 1])) return false; // checks that char after Q, p, or d is a number
        if (subResults[i] == 'Q') {
            for (int k = i + 1; isdigit(subResults[k]); k++)
                temp += subResults[k];
            numQ = stoi(temp);
            temp = "";
        }
        if (subResults[i] == 'p') {
            for (int k = i + 1; isdigit(subResults[k]); k++)
                temp += subResults[k];
            numP = stoi(temp);
            temp = "";
        }
        if (subResults[i] == 'd') {
            for (int k = i + 1; isdigit(subResults[k]); k++)  
                temp += subResults[k];
            numD = stoi(temp);
            temp = "";        
        }
    }

    if (numP + numD != numQ) return false; // checks if pass + defect = total

    return true;
}


int passQC(string results) {
    if (!isValidQC(results)) return -1; // if invalid, return -1 as stated in specs
    
    int totalPasses = 0;
    string temp;
    
    for (int i = 0; i < size(results); i++) {
        if (results[i] == 'p') {
            for (int k = i + 1; isdigit(results[k]); k++)
                temp += results[k];
            totalPasses += stoi(temp);
            temp = "";
        }
    }

    return totalPasses;
}


int defectQC(string results) {
    if (!isValidQC(results)) return -1; // if invalid, return -1 as stated in specs
    
    int totalDefects = 0;
    string temp;
    
    for (int i = 0; i < size(results); i++) {
        if (results[i] == 'd') {
            for (int k = i + 1; isdigit(results[k]); k++)
                temp += results[k];
            totalDefects += stoi(temp);
            temp = "";
        }
    }

    return totalDefects;
}


int totalQC(string results) {
    if (!isValidQC(results)) return -1; // if invalid, return -1 as stated in specs
    
    int totalTests = 0;
    string temp;
    
    for (int i = 0; i < size(results); i++) {
        if (results[i] == 'Q') {
            for (int k = i + 1; isdigit(results[k]); k++)
                temp += results[k];
            totalTests += stoi(temp);
            temp = "";
        }
    }

    return totalTests;
}


int batches(string results) {
    if (!isValidQC(results)) return -1; // if invalid, return -1 as stated in specs

    int totalBatches = 0;
    
    for (int i = 0; i < size(results); i++) {
        if (results[i] == 'Q') totalBatches++;
    }

    return totalBatches;
}
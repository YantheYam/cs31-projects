// Ryan Lim, 005969674
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// prototyping functions
int locateMaximum(const string array[], int n);
int countFloatingPointValues(const string array[], int n);
bool hasNoCapitals(const string array[], int n);
int shiftLeft(string array[], int n, int amount, string placeholder);

// main routine used to test functions
int main() {
    string data[5] = {"mamaBbcca", "mamaBbcca", "12,", "98", "tyrion"};
    string folks[8] = {"samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "magdalena", "jon"};
    string bruh[8] = {"afkakw", "noohoo", "zdzoadoa", "Bruh", "25", "44.76", "00151.31", "24"};
    string man[8] = {"zdzoadoa", "noohoo", "zdzoadoa", "+5120521", "-66", "44.76", "00151.31", "24..24"};

    assert(locateMaximum(bruh, 8) == 2);
    assert(locateMaximum(bruh, -1) == -1);
    assert(countFloatingPointValues(bruh, 8) == 4);
    assert(countFloatingPointValues(bruh, -1) == -1);
    assert(countFloatingPointValues(bruh, 4) == 0);
    assert(hasNoCapitals(bruh, 8) == false);
    assert(hasNoCapitals(bruh, -1) == true);
    assert(hasNoCapitals(bruh, 3) == true);
    assert(shiftLeft(bruh, 8, 2, "PLACEHOLDER") == 2);
    assert(shiftLeft(bruh, 5, 2, "PLACEHOLDER") == 2);
    assert(shiftLeft(bruh, 8, 9, "PLACEHOLDER") == 8);
    assert(shiftLeft(bruh, -1, 5, "PLACEHOLDER") == -1);
    assert(shiftLeft(bruh, 8, -1, "PLACEHOLDER") == -1);

    assert(locateMaximum(man, 8) == 0);
    assert(countFloatingPointValues(man, 8) == 2);
   



    // cout << locateMaximum(bruh, 8) << endl;
    // cout << countFloatingPointValues(bruh, 8) << endl;
    // cout << boolalpha << hasNoCapitals(bruh, 3) << endl;
    // cout << shiftLeft(bruh, 8, -1, "PLACEHOLDER") << endl;
    // for (int i = 0; i < size(bruh); i++)
    //     cout << bruh[i] << ' ';

    // cout << locateMaximum(folks, 4) << endl;
    // cout << countFloatingPointValues(folks, 4) << endl;
    // cout << boolalpha << hasNoCapitals(folks, 4) << endl;
    // cout << shiftLeft(folks, 1, 1, "sheebar") << endl;
    // for (int i = 0; i < size(folks); i++) cout << folks[i] << ' ';    


    return 0;
}

int locateMaximum(const string array[], int n){ 
    if (n <= 0) return -1; // specs say to return -1 if n <= 0
    
    int indexOfMax = 0;
    string maxString = "";

    for (int i = 0; i < n; i++) { // loops through all entries in the array
        if (array[i] > maxString) {
            // if the current string is bigger than the previous max string, then set indexOfMax to the current string's position and set maxString to the strng
            indexOfMax = i;
            maxString = array[i];
        }
    }

    return indexOfMax;
}

int countFloatingPointValues(const string array[], int n){
    if (n <= 0) return -1; // specs say to return -1 if n <= 0

    int totalFloatingPointValues = 0;

    for (int i = 0; i < n; i++) { // loop through all entries in the array
        bool bruh = 0; // bool that represents if string is valid floating point value or not
        int totalDecimalPoints = 0;
        for (int k = 0; k < array[i].size(); k++) { // loop through the chars in the string
            if (!isdigit(array[i][k]) && array[i][k] != '.') { // checks if char is a digit or a decimal point
                bruh = 0;
                break; // if not, then breaks
            }   
            if (array[i][k] == '.')
                totalDecimalPoints++;
            bruh = 1;
        }
        if (array[i] == ".") // if the string is just a decimal point, set bruh to false
            bruh = 0;
        if (bruh && (totalDecimalPoints == 0 || totalDecimalPoints == 1)) // checks that string is valid floating point value and that there is only one decimal point before incrementing totalFloatingPointValues
            totalFloatingPointValues++;
    }

    return totalFloatingPointValues;
}

bool hasNoCapitals(const string array[], int n) {
    if (n <= 0) return true; // return true if n <= 0, as said in specs

    for (int i = 0; i < n; i++) // loops through each entry in array
        for (int k = 0; k < array[i].size(); k++) // loops through each char of entry
            if (isupper(array[i][k]))
                return false; // return false if any chars are uppercase

    return true;
}

int shiftLeft(string array[], int n, int amount, string placeholder) {
    if (n <= 0 || amount < 0) return -1; // return -1 if n <= 0 or amount < 0, as said in specs

    int totalPlaceholder = 0;

    if (amount >= n) { // if the amount to be shifted left is greater than n, then all entries will become placeholder
        for (int i = 0; i < n; i++)
            array[i] = placeholder;
        return n; // return n since n = total # of placeholders as everything will become a placeholder
        }

    for (int i = amount; i < n; i++) // this shifts the entries left
        array[i - amount] = array[i];

    for (int i = n - 1; i >= n - amount; i--) { // this adds the placeholders at the end
         array[i] = placeholder;
         totalPlaceholder++;
    }

    return totalPlaceholder;
}
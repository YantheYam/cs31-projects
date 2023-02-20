// Ryan Lim, 005969674
#include <iostream>
#include <string>
using namespace std;

int main() {
    // variables
    string stateName;
    bool stateNameCheck = 0;

    double purchaseAmount = 0;
    bool purchaseAmountCheck = 0;

    string month;
    bool monthCheck = 0;

    int day = 0;
    bool dayCheck = 0;

    int year = 0;
    bool yearCheck = 0;

    double stateTaxRate = 0;
    double avgLocalTaxRate = 0;
    double levy = 0;
        
    
    // getting user input
    cout << "State Name: ";
    getline(cin, stateName);        
 
    cout << "Purchase amount: ";
    cin >> purchaseAmount;
    cin.clear(); // used to clear "dirty data" in the buffer (in case user gives wrong data type)
    cin.ignore(10000, '\n');

    cout << "Provide the month: ";
    getline(cin, month);

    cout << "Provide the day: ";
    cin >> day;
    cin.clear();
    cin.ignore(10000, '\n');    
    
    cout << "Provide the year: ";
    cin >> year;
    cin.clear();
    cin.ignore(10000, '\n');    


    // checking if inputs are valid
    if (stateName == "Alabama" || stateName == "Alaska" || stateName == "Arizona" || stateName == "Arkansas" || stateName == "California" || stateName == "Colorado" || stateName == "Connecticut" || stateName == "Delaware" || stateName == "Florida" || stateName == "Georgia" || stateName == "Hawaii" || stateName == "Idaho" || stateName == "Illinois" || stateName == "Indiana" || stateName == "Iowa" || stateName == "Kansas" || stateName == "Kentucky" || stateName == "Louisiana" || stateName == "Maine" || stateName == "Maryland" || stateName == "Massachusetts" || stateName == "Michigan" || stateName == "Minnesota" || stateName == "Mississippi" || stateName == "Missouri" || stateName == "Montana" || stateName == "Nebraska" || stateName == "Nevada" || stateName == "New Hampshire" || stateName == "New Jersey" || stateName == "New Mexico" || stateName == "New York" || stateName == "North Carolina" || stateName == "North Dakota" || stateName == "Ohio" || stateName == "Oklahoma" || stateName == "Oregon" || stateName == "Pennsylvania" || stateName == "Rhode Island" || stateName == "South Carolina" || stateName == "South Dakota" || stateName == "Tennessee" || stateName == "Texas" || stateName == "Utah" || stateName == "Vermont" || stateName == "Virginia" || stateName == "Washington" || stateName == "West Virginia" || stateName == "Wisconsin" || stateName == "Wyoming") {
        stateNameCheck = 1;
    }

    if (purchaseAmount > 0) {
        purchaseAmountCheck = 1;
    }

    if (month == "January" || month == "February" || month == "March" || month == "April" || month == "May" || month == "June" || month == "July" || month == "August" || month == "September" || month == "October" || month == "November" || month == "December") {
        monthCheck = 1;
    }

    if (1 <= day && day <= 31) {
        dayCheck = 1;
    }

    if (1 <= year && year <= 2025) {
        yearCheck = 1;
    }


    // error messages
    if (stateNameCheck == 0) {
        cout << "Invalid state!";
    } else if (purchaseAmountCheck == 0) {
        cout << "Invalid amount!";
    } else if (monthCheck == 0) {
        cout << "Invalid month!";
    } else if (dayCheck == 0) {
        cout << "Invalid day!";
    } else if (yearCheck == 0) {
        cout << "Invalid year!";
    }


    // setting tax rates and calculating total tax
    if (stateName == "Alabama") {
        stateTaxRate = 4.00;
        avgLocalTaxRate = 5.14;
        levy = 0.00;
    }
    
    if (stateName == "Alaska") {
        stateTaxRate = 0.00;
        avgLocalTaxRate = 1.43;
        levy = 0.00;
    }

    if (stateName == "Arizona") {
        stateTaxRate = 5.60;
        avgLocalTaxRate = 2.77;
        levy = 0.00;
    }
    
    if (stateName == "Arkansas") {
        stateTaxRate = 6.50;
        avgLocalTaxRate = 2.93;
        levy = 0.00;
    }

    if (stateName == "California") {
        stateTaxRate = 7.25;
        avgLocalTaxRate = 1.31;
        levy = 1.00;
    }

    if (stateName == "Connecticut") {
        stateTaxRate = 6.35;
        avgLocalTaxRate = 0.00;
        levy = 0.00;
    }

    if (stateName == "Delaware") {
        stateTaxRate = 0.00;
        avgLocalTaxRate = 0.00;
        levy = 0.00;
    }

    if (stateName == "Florida") {
        stateTaxRate = 6.00;
        avgLocalTaxRate = 1.05;
        levy = 0.00;
    }

    if (stateName == "Georgia") {
        stateTaxRate = 4.00;
        avgLocalTaxRate = 3.29;
        levy = 0.00;
    }

    if (stateName == "Hawaii") {
        stateTaxRate = 4.00;
        avgLocalTaxRate = 0.41;
        levy = 0.00;
    }

    if (stateName == "Idaho") {
        stateTaxRate = 6.00;
        avgLocalTaxRate = 0.03;
        levy = 0.00;
    }

    if (stateName == "Illinois") {
        stateTaxRate = 6.25;
        avgLocalTaxRate = 2.49;
        levy = 0.00;
    }

    if (stateName == "Indiana") {
        stateTaxRate = 7.00;
        avgLocalTaxRate = 0.00;
        levy = 0.00;
    }

    if (stateName == "Iowa") {
        stateTaxRate = 6.00;
        avgLocalTaxRate = 0.82;
        levy = 0.00;
    }

    if (stateName == "Kansas") {
        stateTaxRate = 6.50;
        avgLocalTaxRate = 2.17;
        levy = 0.00;
    }

    if (stateName == "Kentucky") {
        stateTaxRate = 6.00;
        avgLocalTaxRate = 0.00;
        levy = 0.00;
    }

    if (stateName == "Louisiana") {
        stateTaxRate = 4.45;
        avgLocalTaxRate = 5.00;
        levy = 0.00;
    }

    if (stateName == "Maine") {
        stateTaxRate = 5.50;
        avgLocalTaxRate = 0.00;
        levy = 0.00;
    }

    if (stateName == "Maryland") {
        stateTaxRate = 6.00;
        avgLocalTaxRate = 0.00;
        levy = 0.00;
    }

    if (stateName == "Massachusetts") {
        stateTaxRate = 6.25;
        avgLocalTaxRate = 0.00;
        levy = 0.00;
    }

    if (stateName == "Michigan") {
        stateTaxRate = 6.00;
        avgLocalTaxRate = 0.00;
        levy = 0.00;
    }

    if (stateName == "Minnesota") {
        stateTaxRate = 6.88;
        avgLocalTaxRate = 0.55;
        levy = 0.00;
    }

    if (stateName == "Mississippi") {
        stateTaxRate = 7.00;
        avgLocalTaxRate = 0.07;
        levy = 0.00;
    }

    if (stateName == "Missouri") {
        stateTaxRate = 4.23;
        avgLocalTaxRate = 3.90;
        levy = 0.00;
    }
    
    if (stateName == "Montana") {
        stateTaxRate = 0.00;
        avgLocalTaxRate = 0.00;
        levy = 0.00;
    }

    if (stateName == "Nebraska") {
        stateTaxRate = 5.50;
        avgLocalTaxRate = 1.35;
        levy = 0.00;
    }

    if (stateName == "Nevada") {
        stateTaxRate = 6.85;
        avgLocalTaxRate = 1.29;
        levy = 0.00;
    }

    if (stateName == "New Hampshire") {
        stateTaxRate = 0.00;
        avgLocalTaxRate = 0.00;
        levy = 0.00;
    }

    if (stateName == "New Jersey") {
        stateTaxRate = 6.63;
        avgLocalTaxRate = -0.03;
        levy = 0.00;
    }

    if (stateName == "New Mexico") {
        stateTaxRate = 5.13;
        avgLocalTaxRate = 2.69;
        levy = 0.00;
    }

    if (stateName == "New York") {
        stateTaxRate = 4.00;
        avgLocalTaxRate = 4.49;
        levy = 0.00;
    }

    if (stateName == "North Carolina") {
        stateTaxRate = 4.75;
        avgLocalTaxRate = 2.22;
        levy = 0.00;
    }

    if (stateName == "North Dakota") {
        stateTaxRate = 5.00;
        avgLocalTaxRate = 1.85;
        levy = 0.00;
    }

    if (stateName == "Ohio") {
        stateTaxRate = 5.75;
        avgLocalTaxRate = 1.42;
        levy = 0.00;
    }

    if (stateName == "Oklahoma") {
        stateTaxRate = 4.50;
        avgLocalTaxRate = 4.42;
        levy = 0.00;
    }

    if (stateName == "Oregon") {
        stateTaxRate = 0.00;
        avgLocalTaxRate = 0.00;
        levy = 0.00;
    }

    if (stateName == "Pennsylvania") {
        stateTaxRate = 6.00;
        avgLocalTaxRate = 0.34;
        levy = 0.00;
    }

    if (stateName == "Rhode Island") {
        stateTaxRate = 7.00;
        avgLocalTaxRate = 0.00;
        levy = 0.00;
    }

    if (stateName == "South Carolina") {
        stateTaxRate = 6.00;
        avgLocalTaxRate = 1.43;
        levy = 0.00;
    }

    if (stateName == "South Dakota") {
        stateTaxRate = 4.50;
        avgLocalTaxRate = 1.90;
        levy = 0.00;
    }

    if (stateName == "Tennessee") {
        stateTaxRate = 7.00;
        avgLocalTaxRate = 2.47;
        levy = 0.00;
    }

    if (stateName == "Texas") {
        stateTaxRate = 6.25;
        avgLocalTaxRate = 1.94;
        levy = 0.00;
    }

    if (stateName == "Utah") {
        stateTaxRate = 5.95;
        avgLocalTaxRate = 0.99;
        levy = 1.25;
    }
    
    if (stateName == "Vermont") {
        stateTaxRate = 6.00;
        avgLocalTaxRate = 0.18;
        levy = 0.00;
    }

    if (stateName == "Virginia") {
        stateTaxRate = 5.30;
        avgLocalTaxRate = 0.35;
        levy = 1.00;
    }

    if (stateName == "Washington") {
        stateTaxRate = 6.50;
        avgLocalTaxRate = 2.67;
        levy = 0.00;
    }

    if (stateName == "West Virginia") {
        stateTaxRate = 6.00;
        avgLocalTaxRate = 0.39;
        levy = 0.00;
    }

    if (stateName == "Wisconsin") {
        stateTaxRate = 5.00;
        avgLocalTaxRate = 0.44;
        levy = 0.00;
    }

    if (stateName == "Wyoming") {
        stateTaxRate = 4.00;
        avgLocalTaxRate = 1.36;
        levy = 0.00;
    }

    // used to simplify calculation of final price
    double totalTax = 1 + (stateTaxRate + avgLocalTaxRate + levy) / 100;


    // magic formula to show decimal places
    cout.setf(ios::fixed); // setting precision
    cout.precision(2); // two decimal places


    // outputting the total payment
    // if statements for tax free days
    if (stateNameCheck && purchaseAmountCheck && monthCheck && dayCheck && yearCheck) {    
        if (stateName == "Alabama" && month == "July" && 15 <= day && day <= 17) {
            cout << "Please pay a total of $" << purchaseAmount;
        } else if (stateName == "Arkansas" && month == "August" && 6 <= day && day <= 7) {
            cout << "Please pay a total of $" << purchaseAmount;            
        } else if (stateName == "Connecticut" && month == "August" && 21 <= day && day <= 27) {
            cout << "Please pay a total of $" << purchaseAmount;            
        } else if (stateName == "Iowa" && month == "August" && 5 <= day && day <= 6) {
            cout << "Please pay a total of $" << purchaseAmount;            
        } else if (stateName == "Maryland" && month == "August" && 14 <= day && day <= 20) {
            cout << "Please pay a total of $" << purchaseAmount;            
        } else if (stateName == "Massachusetts" && month == "August" && 14 <= day && day <= 15) {
            cout << "Please pay a total of $" << purchaseAmount;            
        } else if (stateName == "Mississippi" && month == "July" && 29 <= day && day <= 30) {
            cout << "Please pay a total of $" << purchaseAmount;            
        } else if (stateName == "Missouri" && month == "April" && 19 <= day && day <= 25) {
            cout << "Please pay a total of $" << purchaseAmount;             
        } else if (stateName == "Nevada" && month == "August" && 5 <= day && day <= 7) {
            cout << "Please pay a total of $" << purchaseAmount;            
        } else if (stateName == "Ohio" && month == "August" && 5 <= day && day <= 7) {
            cout << "Please pay a total of $" << purchaseAmount;            
        } else if (stateName == "Oklahoma" && month == "August" && 6 <= day && day <= 8) {
            cout << "Please pay a total of $" << purchaseAmount;            
        } else if (stateName == "South Carolina" && month == "August" && 5 <= day && day <= 7) {
            cout << "Please pay a total of $" << purchaseAmount;            
        } else if (stateName == "Tennessee" && month == "July" && 29 <= day && day <= 31) {
            cout << "Please pay a total of $" << purchaseAmount;            
        } else if (stateName == "Texas" && month == "August" && 5 <= day && day <= 7) {
            cout << "Please pay a total of $" << purchaseAmount;            
        } else if (stateName == "West Virginia" && month == "August" && 5 <= day && day <= 7) {
            cout << "Please pay a total of $" << purchaseAmount;            
        } else {
         cout << "Please pay a total of $" << purchaseAmount * totalTax;
        }
    } 

    return 0;
}
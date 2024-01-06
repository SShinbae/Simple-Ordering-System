// Simple Ordering System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <windows.h>

using namespace std;

struct Menu
{
    public:
        string product, brand[5];
        float price[5];

};

vector<string>productName;
vector<string>brandName;
vector<float>price;
vector<int>quantity;

string accName;
int pinNum;
int addMore, productChoice, brandChoice;
float totalPrice = 0;
string doubleLine = "============================================\n";
string singleLine = "--------------------------------------------\n";

Menu menu[5]{
    {"Soap  ", {"Safeguard ","Dove ", "Bioderm" , "Lifebouy" , "Renew "},
    {50.99,22.10,19.45,15.35,16.79}},

    {"Shampoo  ", {"Clear ","Head & Shoulder ", "Pantene " , "Watson " , "Tresemme "},
    {10.99,11.99,12.99,13.99,14.99}},

    {"Toothpaste  ", {"Clear ","Head & Shoulder ", "Pantene " , "Watson " , "Tresemme "},
    {10.99,11.99,12.99,13.99,14.99}},

    {"Laundry  ", {"Clear ","Head & Shoulder ", "Pantene " , "Watson " , "Tresemme "},
    {10.99,11.99,12.99,13.99,14.99}},

    {"Sanitizer  ", {"Clear ","Head & Shoulder ", "Pantene " , "Watson " , "Tresemme "},
    {10.99,11.99,12.99,13.99,14.99}}
};

void mainMenu();

int main()
{
    mainMenu();
    return 0;
}

void userInfo() {

    string firstName, lastName, middleName;
    string name, address, paymentMethod, proceed;
    int choice;
    long phoneNumber;

    while (1) {
        system("cls");
        cout << "\t\t-----------------\n";
        cout << "\t\t|Profile Info|\n";
        cout << "\t\t-----------------\n";
        cin.ignore();

        cout << "First Name : ";
        getline(cin, firstName);
        cout << "Middle Name :";
        getline(cin, middleName);
        cout << "Last Name :";
        getline(cin, lastName);

        cout << "Address :";
        getline(cin, address);
        cout << "Phone Number";
        cin >> phoneNumber;

        cout << "\n-----------------------------";
        cout << "\nIs this information correct?\n";
        cout << "[1] Yes\n";
        cout << "[2] No\n";
        cout << "----------------------------\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            break;
        }
        else {
            continue;
        }
        cin.ignore();
        cout << "\n--------------Press Enter to proceed--------------\n";

        getline(cin, proceed);

        Sleep(250);
        system("cls");

    }

};

void paymentMethod() {
    int choice;
    system("cls");
    while (1){
        cout << "\t -----------------------\n";
        cout << "\t | Payment Method | \n";
        cout << "\t -----------------------\n\n";
        cout << "[1] Cash on Delivery\n";
        cout << "[2] Online Banking\n";
        cout << "[3] Credit / Debit Card\n";
        cout << "-------------------\nChoice :";
        cin >> choice;
        if (choice > 0 && choice < 3) {
            break;
        }
        else {
            system("cls");
            cout << "Invalid Input\n";
            continue;
        }

    }
}

void showOrder() {
    string proceed;
    cout << singleLine;
    cout << "   List of Order\n";
    cout << singleLine;
    for(int z = 0; z < productName.size(); z++)
    {
        float combinePrice = static_cast<float>(price[z] * quantity[z]);
        cout << "Product    :" << productName[z] << endl;
        cout << "Brand    :" << brandName[z] << endl; 
        cout << "Price    :" << price[z] << endl;
        cout << "Quantity    :" << quantity[z] << endl;
        cout << "Total Price    :" << combinePrice << endl;
        totalPrice += (price[z] * quantity[z]);
        cout << singleLine << endl;
    }
    cout << fixed << setprecision(2) << "\nOrder Total Cost:" << totalPrice << "Presos" << endl;
    cin.ignore();
    cout << "\n\n-------------Press Enter to Proceed-------------\n";
    getline(cin, proceed);
    Sleep(1000);
}

void toDo() {
    bool addMoreItems = true;
    while (addMoreItems) {
        cout << "\tAvailable Product\n";
        cout << doubleLine;

        for (int i = 0; i < 5; i++) {
            cout << "|" << i + 1 << "|" << menu[i].product << endl;
        }
        cout << "[6] Exit\n";
        cout << doubleLine;
        cout << "Choice: ";
        cin >> productChoice;

        if (productChoice == 6) {
            mainMenu();
            break; // Exit the loop if user chooses to exit
        }

        // Display brands and prices for the selected product
        system("cls");
        cout << menu[productChoice - 1].product << "\tPrice\n";
        cout << doubleLine;
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << "." << menu[productChoice - 1].brand[i] << "\t\t"
                << menu[productChoice - 1].price[i] << " Pcs\n";
        }
        cout << doubleLine;

        // Get brand choice and quantity
        cout << "Brand Choice: ";
        cin >> brandChoice;
        cout << "Quantity: ";
        cin >> addMore;

        // Add the selected items to the cart
        productName.push_back(menu[productChoice - 1].product);
        brandName.push_back(menu[productChoice - 1].brand[brandChoice - 1]);
        price.push_back(menu[productChoice - 1].price[brandChoice - 1]);
        quantity.push_back(addMore);

        // Ask if the user wants to add more items
        int add;
        system("cls");
        cout << "   Your Order has been added to the cart\n\n";
        cout << "Do you want to add another order?\n";
        cout << doubleLine;
        cout << "[1] Yes\n";
        cout << "[2] No\n";
        cout << "Input: ";
        cin >> add;

        if (add != 1) {
            addMoreItems = false;
        }
    }
}


void centerProgramFunc() {
    string choice;
    system("cls");
    toDo();
    showOrder();
    paymentMethod();
    userInfo();
    system("cls");
    cout << "\tTransaction Successfully Finished!\n\n";
    cout << "\n-------------Press Enter to Exit-------------\n";
    getline(cin, choice);
    system("cls");
    mainMenu();
}

// Function to get the width of the console window
int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    return columns;
}

// Function to center text and print it
void printCentered(string text) {
    int consoleWidth = getConsoleWidth();
    int textLength = text.length();
    int startPosition = (consoleWidth - textLength) / 2;

    cout << string(startPosition, ' '); // Print spaces before the text
    cout << text << endl;
}

void mainMenu() {
    string str;
    int choice = 0;
    while (1) {
        system("cls");

        printCentered("--------------------------");
        printCentered("| Welcome to SShinbe Store! |");
        printCentered("Please Choose an option");
        printCentered("[1] Order Products");
        printCentered("[2] Exit");
        printCentered("---------------");

        cout << "\t|"; // The input line can remain left-aligned or be centered as well
        cin >> choice;

        switch (choice) {
        case 1:
            centerProgramFunc();
            break;
        case 2:
            system("cls");
            printCentered("Thank You for shopping with us");
            return;
        default:
            system("cls");
            printCentered("Invalid Choice");
            continue;
        }
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

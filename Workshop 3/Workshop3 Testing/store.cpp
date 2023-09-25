
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std; 

char* validPostalCode(char* postalCode) {
    if (!validateString(postalCode)) return NULL;
    char formattedPostalCode[7] = "";
    int j = 0;
    for (int i = 0; i < 7; i++) {
        if (!isspace(postalCode[i])) {
            formattedPostalCode[j++] = toupper(postalCode[i]);
        }
    }
    formattedPostalCode[j] = '\0';

    if (strlen(formattedPostalCode) != 6 || !isalpha(formattedPostalCode[0]) || !isdigit(formattedPostalCode[1]) ||
        !isalpha(formattedPostalCode[2]) || !isspace(formattedPostalCode[3]) || !isalnum(formattedPostalCode[4]) ||
        !isalnum(formattedPostalCode[5])) {
        return NULL;
    }

    strcpy(postalCode, formattedPostalCode);
    return postalCode;
}

bool validateString(char* val, int minlen) {
    if (val == NULL || strlen(val) < minlen || val[strlen(val) - 1] == '\n' || strlen(val) == 0) return false;
    return true;
}

Customer loadCustomer() {
    Customer customer;

    cout << "Enter customer information:";

    do
    {
        cout << endl << "First Name: ";
        fgets(customer.firstName, sizeof(customer.firstName), stdin);
        customer.firstName[strlen(customer.firstName) - 1] = '\0';
        if (!validateString(customer.firstName)) cout << "Cannot enter an empty name. Try Again: ";
    } while (!validateString(customer.firstName));
    
    do
    {
        cout << endl << "Last Name: ";
        fgets(customer.lastName, sizeof(customer.lastName), stdin);
        customer.lastName[strlen(customer.lastName) - 1] = '\0'; 
        if (!validateString(customer.lastName)) cout << "Cannot enter an empty name. Try Again: ";
    } while (!validateString(customer.lastName));


    do
    {
        cout << endl << "Street Address: ";
        fgets(customer.streetAddress, sizeof(customer.streetAddress), stdin);
        customer.streetAddress[strlen(customer.streetAddress) - 1] = '\0';
        if (!validateString(customer.streetAddress)) cout << "Cannot enter an empty name. Try Again: ";
    } while (!validateString(customer.streetAddress));

    do
    {
        cout << endl << "City: ";
        fgets(customer.city, sizeof(customer.city), stdin);
        customer.city[strlen(customer.city) - 1] = '\0';
        if (!validateString(customer.city)) cout << "Cannot enter an empty name. Try Again: ";
    } while (!validateString(customer.city));

    do
    {
        cout << endl << "Province in 2 charcter format: ";
        fgets(customer.province, sizeof(customer.province), stdin);
        customer.province[strlen(customer.province) - 1] = '\0';
        if (!validateString(customer.province, PROVINCE)) cout << "Cannot enter an empty name. Try Again: ";
    } while (!validateString(customer.province, PROVINCE));

    do {
        cout << endl << "Postal Code: ";
        fgets(customer.postalCode, sizeof(customer.postalCode), stdin);
        customer.postalCode[strlen(customer.postalCode) - 1] = '\0'; 

        if (!validPostalCode(customer.postalCode)) cout << "Invalid postal code format. Please enter a valid postal code.";
    } while (!validPostalCode(customer.postalCode));

    return customer;
}

void displayCustomer(Customer customer) {
    cout << "\nCustomer Information:" << endl;
    cout << "First Name: " << customer.firstName << endl;
    cout << "Last Name: " << customer.lastName << endl;
    cout << "Street Address: " << customer.streetAddress << endl;
    cout << "City: " << customer.city << endl;
    cout << "Province: " << customer.province << endl;
    cout << "Postal Code: " << customer.postalCode << endl;
}

int main() {
    displayCustomer(loadCustomer());
    return 0;
}

#pragma once
#ifndef STORE_H
#define STORED_H

#define MAX_NAME 50
#define MAX_ADDRESS 100
#define PROVINCE 2
#define POS_CODE 7


struct Customer {
    char firstName[MAX_NAME+1];
    char lastName[MAX_NAME+1];
    char streetAddress[MAX_ADDRESS+1];
    char city[MAX_NAME+1];
    char province[PROVINCE+1];
    char postalCode[POS_CODE+1];
};

struct Customer loadCustomer();

bool validateString(char* val, int minlen = 2);

char* validPostalCode(char* postalCode);

void displayCustomer(Customer customer);
#endif // !STORE_H


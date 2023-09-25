#pragma once
#ifndef STOREDATABASE_H
#define STOREDATABASE_H

#define MAX_NAME 15
#define MAX_ADDRESS 45
#define PROVINCE 2
#define POS_CODE 7
struct Customer
{
	char fName[MAX_NAME + 1];
	char lName[MAX_NAME + 1];
	char address[MAX_ADDRESS + 1];
	char city[MAX_NAME + 1];
	char province[PROVINCE + 1];
	char postalCode[POS_CODE + 1];

};

Customer loadCustomer(char *inputFile, char* outputFile);

bool validPostalCode(char* posCode);

void displayCustomer(Customer customer);
#endif // !STOREDATABASE_H

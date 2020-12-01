#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <string.h>
#include <fstream>
#include <datetimeapi.h>// or another maybe??? 
#define MAX_EMAIL 8 //רק לקידומת
#define MAX_ID 9
#define MAX_PHONE 10
#define MAX_NAME 15 //enough???
#define MAX_PASSWORD 10 //less???
#define BUFFER 20
typedef struct amenities { bool disabledAccess, wifi, kitchen, tv, balcony, washingMachine, 
airConditioning, swimmingPool, parkingLot;};

typedef struct ad { bool available; string description; int price; int discount; string location;
int numOfPeople; int numOfRooms; int numOfBeds; amenities ameNities; string attraction; int rating;};
//also- landlord name, phone number,		and it's own calender??

typedef struct landlord { string fullName; int id; string email; string password; int phoneNumber; int sumOfDeals; int adSize; ad* properties; };
using namespace std;

//-------------print to file
void printToFile(int arrSize, landlord* landlordArr) {
	ofstream outFile;
	try {
		outFile.open("landlord.data");//open file in ios::out default mode
		if (!outFile)
			throw("couldn't open file");
	}
	catch (const char* const x) {
		cout << x << endl;
		throw;
	}
	catch (...) {
		cout << "ERROR!" << endl;
		throw;
	}
	//if opening file succeeded
	outFile << arrSize << endl;//prints size of landlord array
	for (int i = 0; i < arrSize; ++i) {
		outFile << landlordArr[i].fullName << endl
			<< landlordArr[i].id << endl
			<< landlordArr[i].email << endl
			<< landlordArr[i].password << endl
			<< landlordArr[i].phoneNumber << endl
			<< landlordArr[i].sumOfDeals << endl
			<< landlordArr[i].adSize << endl;
	}
	outFile.close();//close file
}
//-------------read from file

//-------------sign in

//-------------sign up(after successful signup redirect to signin)

//-------------sort(display options in loop)

//-------------filter(display options in loop)

//-------------search

//-------------dates availability

//-------------occupy dates

//-------------confirm credit card info

//-------------total rent sum

//-------------support(print only)

//-------------faq(print only)

//-------------travelers homepage

//-------------landlord menu

//-------------landlord homescreen

//-------------new ad

//-------------edit ad

//-------------delete ad

//-------------total gainings for landlord

//-------------rate property(on last rent day)

//-------------calculate and update rates

//-------------prints ad for traveler(to screen)

//-------------prints list of ads for landlord(to screen)- also print ad for landlord???

//-------------print deal confirmation(to screen)

////***************also looped menus and instructions in each screen***************

//-------------delete all allocated data
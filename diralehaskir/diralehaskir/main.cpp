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
#define AMENITIES 9
typedef struct amenities { bool disabledAccess, wifi, kitchen, tv, balcony, washingMachine, 
airConditioning, swimmingPool, parkingLot;};

typedef struct ad { bool available; string description; int price; int discount; string location;
int numOfPeople; int numOfRooms; int numOfBeds; amenities ameNities; string attraction; int rating;};
//also- landlord name, phone number,		and it's own calender??

typedef struct landlord { string fullName; string phoneNumber; string password; int id; 
string email;  int sumOfDeals; int adSize; ad* properties; };

typedef struct traveler { string fullName; string phoneNumber; string password; };
using namespace std;

//-------------print to file
void printToFile(int landlordSize, landlord* landlordArr, int travelerSize, traveler* travelerArr) {
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
	outFile << landlordSize << endl;//prints size of landlord array
	int i = 0;
	for (; i < landlordSize; ++i) {
		outFile << landlordArr[i].fullName << endl
			<< landlordArr[i].phoneNumber << endl
			<< landlordArr[i].password << endl
			<< landlordArr[i].id << endl
			<< landlordArr[i].email << endl
			<< landlordArr[i].sumOfDeals << endl
			<< landlordArr[i].adSize << endl;
		printAdsToFile(landlordArr[i].adSize, landlordArr[i].properties);
		printTravelerToFile(travelerSize, travelerArr);
	}
	outFile.close();//close file
}
//-------------printAdsToFile
void printAdsToFile(int size, ad* adsArr) {
	ofstream outFile;
	try {
		outFile.open("properties.data");//open file in ios::out default mode
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
	outFile << size << endl;//prints size of landlord array
	int i = 0;
	for (; i < size; ++i) {
		outFile << adsArr[i].available << endl
			<< adsArr[i].description << endl
			<< adsArr[i].price << endl
			<< adsArr[i].discount << endl
			<< adsArr[i].location << endl
			<< adsArr[i].numOfPeople << endl
			<< adsArr[i].numOfRooms << endl
			<< adsArr[i].numOfBeds << endl;
		//print amenities
		outFile << adsArr[i].ameNities.disabledAccess << endl
			<< adsArr[i].ameNities.wifi << endl
			<< adsArr[i].ameNities.kitchen << endl
			<< adsArr[i].ameNities.tv << endl
			<< adsArr[i].ameNities.balcony << endl
			<< adsArr[i].ameNities.washingMachine << endl
			<< adsArr[i].ameNities.airConditioning << endl
			<< adsArr[i].ameNities.swimmingPool << endl
			<< adsArr[i].ameNities.parkingLot << endl;
		//print rest
		outFile << adsArr[i].attraction << endl
			<< adsArr[i].rating << endl;
	}
	outFile.close();//close file
}
//-------------printTravelerToFile
void printTravelerToFile(int size, traveler* travelerArr) {
	ofstream outFile;
	try {
		outFile.open("traveler.data");//open file in ios::out default mode
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
	outFile << size << endl;//prints size of landlord array
	int i = 0;
	for (; i < size; ++i) {
		outFile << travelerArr[i].fullName << endl
			<< travelerArr[i].phoneNumber << endl
			<< travelerArr[i].password << endl;
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
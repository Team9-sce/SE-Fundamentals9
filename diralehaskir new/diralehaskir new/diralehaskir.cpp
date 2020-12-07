#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
//#include <cstdlib>
#include <stdio.h>
//#include <cstring>
#include <string>
//#include <cstringt.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include "structs.h"
#include "diralehaskir.h"
//#include <datetimeapi.h>// or another maybe??? 
#define MAX_EMAIL 8 //רק לקידומת
#define MAX_ID 9
#define MAX_PHONE 10
#define MAX_NAME 15 //enough???
#define MAX_PASSWORD 10 //less???
#define BUFFER 20
#define AMENITIES 9
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
		printAdsToFile(landlordArr[i].adSize, landlordArr[i].properties);//print ads for landlord
	}
	printTravelerToFile(travelerSize, travelerArr);//print all travelers
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
			<< adsArr[i].rating << endl
			<< adsArr[i].dateSize << endl;
		//print occupied dates
		for (int j = 0; j < adsArr[i].dateSize; ++i) {
			outFile << adsArr[i].occupied[j].fromDay << endl
				<< adsArr[i].occupied[j].fromMonth << endl
				<< adsArr[i].occupied[j].fromYear << endl
				<< adsArr[i].occupied[j].toDay << endl
				<< adsArr[i].occupied[j].toMonth << endl
				<< adsArr[i].occupied[j].toYear << endl;
		}
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
void readFromFile(landlord* landlordArr, traveler* travelerArr) {
	ifstream inFile;
	try {
		inFile.open("landlord.data");//open in default mode
		if (!inFile)
			throw("can't open file");
	}
	catch (const char* const x) {
		cout << x << endl;
		throw;
	}
	catch (...) {
		cout << "ERROR!" << endl;
		throw;
	}
	//if succeeded
	int arrSize = 0;
	inFile >> arrSize;
	char tempBuff = '0';
	inFile >> tempBuff;//intake of \n
	try {
		landlordArr = new landlord[arrSize];
		if (!landlordArr)
			throw("allocation failed in readFromFile-landlord");
	}
	catch (const char* const x) {
		cout << x << endl;
		inFile.close();
		throw;
	}
	catch (...) {
		cout << "ERROR!" << endl;
		throw;
	}
	//if succeeded
	int i = 0;
	while (i < arrSize)
	{
		inFile >> landlordArr[i].fullName;
		inFile >> tempBuff;//intake of \n
		inFile >> landlordArr[i].phoneNumber;
		inFile >> tempBuff;//intake of \n
		inFile >> landlordArr[i].password;
		inFile >> tempBuff;//intake of \n
		inFile >> landlordArr[i].id;
		inFile >> tempBuff;//intake of \n
		inFile >> landlordArr[i].email;
		inFile >> tempBuff;//intake of \n
		inFile >> landlordArr[i].sumOfDeals;
		inFile >> tempBuff;//intake of \n
		inFile >> landlordArr[i].adSize;
		inFile >> tempBuff;//intake of \n
		try {
			landlordArr[i].properties = new ad[landlordArr[i].adSize];
			if (!landlordArr)
				throw("allocation failed in readFromFile-ads");
		}
		catch (const char* const x) {
			cout << x << endl;
			inFile.close();
			throw;
		}
		catch (...) {
			cout << "ERROR!" << endl;
			throw;
		}
		//call read ads
		readAdsFromFile(landlordArr[i].adSize, landlordArr[i].properties);//read ads for landlord
		++i;
	}
	//read all travelers
	readTravelerFromFile(travelerArr);
	inFile.close();//close file
}//return value???

 //-------------readAdsFromFile
void readAdsFromFile(int size, ad* adsArr) {//read ads for landlord
	ifstream inFile;
	try {
		inFile.open("properties.data");//open file in ios::out default mode
		if (!inFile)
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
	char tempBuff = '0';
	//if opening file succeeded
	int i = 0;
	for (; i < size; ++i) {
		inFile >> adsArr[i].available;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].description;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].price;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].discount;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].location;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].numOfPeople;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].numOfRooms;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].numOfBeds;
		inFile >> tempBuff;//intake of \n
		//print amenities
		inFile >> adsArr[i].ameNities.disabledAccess;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].ameNities.wifi;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].ameNities.kitchen;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].ameNities.tv;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].ameNities.balcony;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].ameNities.washingMachine;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].ameNities.airConditioning;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].ameNities.swimmingPool;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].ameNities.parkingLot;
		inFile >> tempBuff;//intake of \n
		//read rest
		inFile >> adsArr[i].attraction;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].rating;
		inFile >> tempBuff;//intake of \n
		inFile >> adsArr[i].dateSize;
		inFile >> tempBuff;//intake of \n
		try {
			adsArr[i].occupied = new date[adsArr[i].dateSize];
			if (!adsArr[i].occupied)
				throw("allocation failed in readFromFile-dates");
		}
		catch (const char* const x) {
			cout << x << endl;
			inFile.close();
			throw;
		}
		catch (...) {
			cout << "ERROR!" << endl;
			throw;
		}
		//print occupied dates
		for (int j = 0; j < adsArr[i].dateSize; ++i) {
			inFile >> adsArr[i].occupied[j].fromDay;
			inFile >> tempBuff;//intake of \n
			inFile >> adsArr[i].occupied[j].fromMonth;
			inFile >> tempBuff;//intake of \n
			inFile >> adsArr[i].occupied[j].fromYear;
			inFile >> tempBuff;//intake of \n
			inFile >> adsArr[i].occupied[j].toDay;
			inFile >> tempBuff;//intake of \n
			inFile >> adsArr[i].occupied[j].toMonth;
			inFile >> tempBuff;//intake of \n
			inFile >> adsArr[i].occupied[j].toYear;
			inFile >> tempBuff;//intake of \n
		}
	}
	inFile.close();//close file
}
//-------------readTravelerFromFile
void readTravelerFromFile(traveler* travelerArr) {
	ifstream inFile;
	try {
		inFile.open("traveler.data");//open file in ios::out default mode
		if (!inFile)
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
	int size = 0;
	inFile >> size;//reads size of traveler array
	char tempBuff = '0';
	inFile >> tempBuff;//intake of \n
	try {
		travelerArr = new traveler[size];
		if (!travelerArr)
			throw("allocation failed in readFromFile-traveler");
	}
	catch (const char* const x) {
		cout << x << endl;
		inFile.close();
		throw;
	}
	catch (...) {
		cout << "ERROR!" << endl;
		throw;
	}
	//if allocation succeeded
	int i = 0;
	for (; i < size; ++i) {
		inFile >> travelerArr[i].fullName;
		inFile >> tempBuff;//intake of \n
		inFile >> travelerArr[i].phoneNumber;
		inFile >> tempBuff;//intake of \n
		inFile >> travelerArr[i].password;
	}
	inFile.close();//close file
}//return value???
//-------------sign in

//-------------sign up(after successful signup redirect to signin)-add new user to db
void signUp(traveler* travelerArr, int size)
{
	string name, phonumber, password;
	cout << "Enter user name, phone-number and password" << endl;
	cin >> name >> phonumber >> password;
	for (int i = 0; i < size; i++)
	{
		if (phonumber == travelerArr[i].phoneNumber)
			cout << "Existing user in the system" << endl;
	}

}
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
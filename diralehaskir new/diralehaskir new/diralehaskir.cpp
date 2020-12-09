#define _CRT_SECURE_NO_WARNINGS
#include "structs.h"
#include "diralehaskir.h"
//#include <datetimeapi.h>// or another maybe??? 
using namespace std;


//-------------print to file
void printToFile(int landlordSize, landlord* landlordArr, int travelerSize, traveler* travelerArr) {
	printLandlordToFile(landlordSize, landlordArr);//print all landlords
	printTravelerToFile(travelerSize, travelerArr);//print all travelers
}

//-------------printLandlordToFile
void printLandlordToFile(int size, landlord* landlordArr) {
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
	outFile << size << endl;//prints size of landlord array
	int i = 0;
	for (; i < size; ++i) {
		outFile << landlordArr[i].fullName << endl
			<< landlordArr[i].phoneNumber << endl
			<< landlordArr[i].password << endl
			<< landlordArr[i].id << endl
			<< landlordArr[i].email << endl
			<< landlordArr[i].sumOfDeals << endl
			<< landlordArr[i].adSize << endl;
		printAdsToFile(landlordArr[i].adSize, landlordArr[i].properties);//print ads for landlord
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
	//read all landlords
	readLandlordFromFile(landlordArr);//read all landlords
	//read all travelers
	readTravelerFromFile(travelerArr);
}//return value???

 //-------------readlandlordFromFile
void readLandlordFromFile(landlord* landlordArr) {//read all landlord

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
	if (!arrSize)
		return;
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
	string a, b;
	while (i < arrSize)
	{
		inFile >> a >> b;
		landlordArr[i].fullName = a + ' ' + b;
		inFile >> landlordArr[i].phoneNumber;
		inFile >> landlordArr[i].password;
		inFile >> landlordArr[i].id;
		inFile >> landlordArr[i].email;
		inFile >> landlordArr[i].sumOfDeals;
		inFile >> landlordArr[i].adSize;
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
	//if opening file succeeded
	int i = 0;
	for (; i < size; ++i) {
		inFile >> adsArr[i].available;
		inFile >> adsArr[i].description;
		inFile >> adsArr[i].price;
		inFile >> adsArr[i].discount;
		inFile >> adsArr[i].location;
		inFile >> adsArr[i].numOfPeople;
		inFile >> adsArr[i].numOfRooms;
		inFile >> adsArr[i].numOfBeds;
		//print amenities
		inFile >> adsArr[i].ameNities.disabledAccess;
		inFile >> adsArr[i].ameNities.wifi;
		inFile >> adsArr[i].ameNities.kitchen;
		inFile >> adsArr[i].ameNities.tv;
		inFile >> adsArr[i].ameNities.balcony;
		inFile >> adsArr[i].ameNities.washingMachine;
		inFile >> adsArr[i].ameNities.airConditioning;
		inFile >> adsArr[i].ameNities.swimmingPool;
		inFile >> adsArr[i].ameNities.parkingLot;
		//read rest
		inFile >> adsArr[i].attraction;
		inFile >> adsArr[i].rating;
		inFile >> adsArr[i].dateSize;
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
			inFile >> adsArr[i].occupied[j].fromMonth;
			inFile >> adsArr[i].occupied[j].fromYear;
			inFile >> adsArr[i].occupied[j].toDay;
			inFile >> adsArr[i].occupied[j].toMonth;
			inFile >> adsArr[i].occupied[j].toYear;
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
bool landlordSignIn(int size, landlord* landlordArr) {//returns true if login successful
	string tempId, tempPass;
	cout << "***LANDLORD - LOG IN***" << endl << "Please enter details according to instructions" << endl;
	//get id input
	cout << "ID must be exactly " << MAX_ID << " digits, numbers only." << endl;
	cout << "Please enter your ID:" << endl;
	cin >> tempId;
	//check length and input correctness
	if (tempId.length() != MAX_ID) {
		cout << "No such ID..." << endl;
		return false;
	}
	//find index for landlord in array by id- assuming no two identical id's
	int index = findLandlordById(size, landlordArr, tempId);
	if (index == -1) {//landlord not found
		cout << "No such ID..." << endl;
		return false;
	}

	//get password
	cout << "Password must be minimum: " << MIN_PASSWORD
		<< " characters and maximum: " << MAX_PASSWORD << " characters," << endl
		<< "Can contain any characters you wish except 'enter'." << endl;
	cout << "Please enter your password:" << endl;
	cin >> tempPass;
	//check length and input correctness
	if (tempPass.length() > MAX_PASSWORD || tempPass.length() < MIN_PASSWORD) {
		cout << "Incorrect password...try again." << endl;
		return false;
	}
	if (tempPass != landlordArr[index].password) {//password equal
		cout << "Incorrect password...try again." << endl;
		return false;
	}
	return true;
}

bool isStringAllDig(string str) {//check id the string is all digits
	for (int i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i]))//if false
			return false;
	}
	return true;
}
//-------------find landlord by id
int findLandlordById(int size,const landlord* const landlordArr, string id) {
	int i = 0;
	for (; i < size; ++i) {
		if (landlordArr[i].id == id)//if equal
			return i;
	}
	return -1;
}

bool travelerSignIn(int size, traveler* travelerArr){
	string tempName, tempPass;
	cout << "***TRAVELER - LOG IN***" << endl << "Please enter details according to instructions" << endl;
	//get name input
	cout << "name must be up to: " << MAX_NAME << " letters." << endl;
	cout << "Please enter your full name:" << endl;
	cin >> tempName;
	//check length and input correctness
	if (tempName.length() > MAX_NAME) {
		cout << "No such user..." << endl;
		return false;
	}
	//find index for traveler in array by name- assuming no two identical names
	int index = findTravelerByName(size, travelerArr, tempName);
	if (index == -1) {//traveler not found
		cout << "No such user..." << endl;
		return false;
	}

	//get password
	cout << "Password must be minimum: " << MIN_PASSWORD
		<< " characters and maximum: " << MAX_PASSWORD << " characters," << endl
		<< "Can contain any characters you wish except 'enter'." << endl;
	cout << "Please enter your password:" << endl;
	cin >> tempPass;
	//check length and input correctness
	if (tempPass.length() > MAX_PASSWORD || tempPass.length() < MIN_PASSWORD) {
		cout << "Incorrect password...try again." << endl;
		return false;
	}
	if (tempPass != travelerArr[index].password) {//password equal
		cout << "Incorrect password...try again." << endl;
		return false;
	}
	return true;
}

//-------------find traveler by full name
int findTravelerByName(int size, const traveler* const travelerArr, string name)
{
	int i = 0;
	for (; i < size; ++i) {
		if (travelerArr[i].fullName == name)//traveler found
			return i;
	}
	return -1;
}

//-------------sign up(after successful signup redirect to signin)-add new user to db
void landlordSignUp(int size, landlord* landlordArr) {

}//return value???

void travelerSignUp(traveler* travelerArr, int size)
{
	//string name, phonumber, password;
	//cout << "***SIGN UP***" << endl << "Please enter details according to instrctions" << endl;
	////get name & phoneNumber input
	//cout << "Please enter your full name, letters only." << endl;
	//cin >> name;
	//do {
	//	cout << "PhoneNumber must be exactly " << MAX_PHONE << " digits, numbers only." << endl;
	//	cout << "Please enter your phoneNumber:" << endl;
	//	cin >> phonumber;
	//	//check length and input correctness
	//} while (phonumber.length() < MAX_PHONE || phonumber.length() > MAX_PHONE || !isStringAllDig(phonumber));
	////get password
	//cout << "Password must be exactly " << MAX_PASSWORD << " characters," << endl
	//	<< "Can contain any characters you wish except 'enter'." << endl;
	//cout << "Please enter your password:" << endl;
	//cin >> password;
}

//-------------sort(display options in loop)

//-------------filter(display options in loop)

//-------------search

//-------------dates availability

//-------------occupy dates

//-------------confirm credit card info

//-------------total rent sum

//-------------support(print only)
void printSupport()
{
	cout<< "Your request has been sent!"<<endl
		<<"Case number :"<<'1234'<<endl
		<<"had been opened with your request for support"<<endl;
}

//-------------faq(print only)
void printFaq()
{
	cout << "THE SOFTWARE IS NOT WORKING PROPERLY, HOW DO I FIX IT?" << endl
		<< "Please try using a different deviceand if there is no improvement try to reset your router." << endl
		<< "IS THE SITE SECURE ?" << endl
		<< "Yes, the payment is secured by the payment platform you will use." << endl
		<< "HOW DO I RATE MY STAY ?" << endl
		<< "At the end of rent time a rating screen will be displayed in which you can rate your stay." << endl;
}
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
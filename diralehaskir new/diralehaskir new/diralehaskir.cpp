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
		inFile.ignore();
		getline(inFile, landlordArr[i].fullName);
		//inFile >> a >> b;
		//landlordArr[i].fullName = a + ' ' + b;
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
		inFile.ignore();
		getline(inFile, adsArr[i].description);
		inFile >> adsArr[i].price;
		inFile >> adsArr[i].discount;
		inFile.ignore();
		getline(inFile, adsArr[i].location);
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
		inFile.ignore();
		getline(inFile, adsArr[i].attraction);
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
		inFile.ignore();
		getline(inFile, travelerArr[i].fullName);
		inFile >> travelerArr[i].phoneNumber;
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
	if (index == NOT_FOUND) {//landlord not found
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
	return NOT_FOUND;
}

bool travelerSignIn(int size, traveler* travelerArr){
	string tempName, tempPass;
	cout << "***TRAVELER - LOG IN***" << endl << "Please enter details according to instructions" << endl;
	//get name input
	cout << "Name must be up to: " << MAX_NAME << " letters only." << endl;
	cout << "Please enter your full name:" << endl;
	//cin >> tempName;
	cin.ignore();
	getline(cin, tempName);
	//check length and input correctness
	if (tempName.length() > MAX_NAME) {
		cout << "No such user..." << endl;
		return false;
	}
	//find index for traveler in array by name- assuming no two identical names
	int index = findTravelerByName(size, travelerArr, tempName);
	if (index == NOT_FOUND) {//traveler not found
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
	return NOT_FOUND;
}

//-------------sign up(after successful signup redirect to signin)-add new user to db
void landlordSignUp(int size, landlord* landlordArr) {
	
	bool flag = true;
	landlord tempL;
	string buffer;
	cout << "***LANDLORD - SIGN UP***" << endl << "Please enter details according to instrctions" << endl;
	//get name input
	do {
		cout << "Name must be up to: " << MAX_NAME << " letters only." << endl;
		cout << "Please enter your full name:" << endl;
		cin.ignore();
		getline(cin, buffer);
		if (buffer.length() <= MAX_NAME && buffer.length() > 0) {
			if (isStringAllLetters(buffer))
				break;
			cout << "Incorrect input, try again." << endl;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempL.fullName = buffer;
	
	//get phone number
	do {
		cout << "PhoneNumber must be exactly " << MAX_PHONE << " digits, no spaces, numbers only." << endl;
		cout << "Please enter your phoneNumber:" << endl;
		cin.ignore();
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() == MAX_PHONE) {
			if (isStringAllDig(buffer))
				break;
			cout << "Incorrect input, try again." << endl;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempL.phoneNumber = buffer;

	//get password
	do {
		cout << "Password can be minimum: " << MIN_PASSWORD
			<< " characters and maximum: " << MAX_PASSWORD << " characters," << endl
			<< "Can contain any characters you wish except 'enter'." << endl;
		cout << "Please enter your password:" << endl;
		cin.ignore();
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() <= MAX_PASSWORD && buffer.length() >= MIN_PASSWORD) {
			break;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempL.password = buffer;

	//get id
	do {
		cout << "PhoneNumber must be exactly " << MAX_ID << " digits, no spaces, numbers only." << endl;
		cout << "Please enter your phoneNumber:" << endl;
		cin.ignore();
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() == MAX_ID) {
			if (isStringAllDig(buffer))
				break;
			cout << "Incorrect input, try again." << endl;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempL.id = buffer;

	//get mail
	int choice = 0;
	do {
		cout << "Choose your mail type:" << endl
			<< "1. " << GMAIL << endl
			<< "2. " << WALLA << endl;
		cin >> choice;
		cout << "Your mail prefix can be maximum: " << MAX_EMAIL << " characters," << endl
			<< "Can contain any characters you wish except 'enter'." << endl;
		cout << "Please enter your email:" << endl;
		cin.ignore();
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() <= MAX_EMAIL && buffer.length() > 0) {
			break;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	if (choice == 1)
		tempL.email = buffer + GMAIL;
	else
		tempL.email = buffer + WALLA;

}//return value???

bool isStringAllLetters(string str) {
	for (int i = 0; i < str.length(); ++i) {
		if (!isalpha(str[i]))//if false
			return false;
	}
	return true;
}
void travelerSignUp(traveler* travelerArr, int size)
{
	bool flag = true;
	traveler tempT;
	string buffer;
	cout << "***TRAVELER - SIGN UP***" << endl << "Please enter details according to instrctions" << endl;
	//get name input
	do {
		cout << "Name must be up to: " << MAX_NAME << " letters only." << endl;
		cout << "Please enter your full name:" << endl;
		cin.ignore();
		getline(cin, buffer);
		if (buffer.length() <= MAX_NAME && buffer.length() > 0) {
			if (isStringAllLetters(buffer))
				break;
			cout << "Incorrect input, try again." << endl;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempT.fullName = buffer;

	//get phone number
	do {
		cout << "PhoneNumber must be exactly " << MAX_PHONE << " digits, no spaces, numbers only." << endl;
		cout << "Please enter your phoneNumber:" << endl;
		cin.ignore();
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() == MAX_PHONE) {
			if (isStringAllDig(buffer))
				break;
			cout << "Incorrect input, try again." << endl;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempT.phoneNumber = buffer;

	//get password
	do {
		cout << "Password can be minimum: " << MIN_PASSWORD
			<< " characters and maximum: " << MAX_PASSWORD << " characters," << endl
			<< "Can contain any characters you wish except 'enter'." << endl;
		cout << "Please enter your password:" << endl;
		cin.ignore();
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() <= MAX_PASSWORD && buffer.length() >= MIN_PASSWORD) {
			break;
		}
		cout << "Incorrect length, try again." << endl;
	} while (flag);
	tempT.password = buffer;
}

//-------------sort(display options in loop)

//-------------filter(display options in loop)
//ad** collectAllAds(int size, landlord* arr) {
//	ad**adsArr = NULL;
//	for (int i = 0; i < size; ++i) {
//		if (arr[i].adSize != 0)
//			++numOfAdArr;
//	}
//	try {
//		adsArr = new ad*[numOfAdArr];
//		if (!adsArr)
//			throw("allocation failed in readFromFile-traveler");
//	}
//	catch (const char* const x) {
//		cout << x << endl;
//		throw;
//	}
//	catch (...) {
//		cout << "ERROR!" << endl;
//		throw;
//	}
//	//if allocation succeeded
//	for (int i = 0; i < size; ++i) {
//		if (arr[i].adSize != 0)
//			++numOfAdArr;
//	}
//
//	return adsArr;
//}
ad** filterAds(int size, landlord* arr) {
	//runs over landlors arr returns all ads that has the requested filters
	ad** adArr = NULL;
	cout << "please choose the filters you wish to apply" << endl;
	amenities filters = amenitiesCtor();//gets amenities from user
	int numOfGoodAds = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < arr[i].adSize; ++j) {
		//check if amenities equal
			if (compareAmenities(filters, arr[i].properties[j].ameNities))
				++numOfGoodAds;//counts how many ads qualify
		}
	}
	try {
		adArr = new ad*[numOfGoodAds];
		if (!adArr)
			throw("allocation failed in filter ads");
	}
	catch (const char* const x) {
		cout << x << endl;
		throw;
	}
	catch (...) {
		cout << "ERROR!" << endl;
		throw;
	}
	//if allocation successfull
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < arr[i].adSize; ++j) {
			//check if amenities equal
			if (compareAmenities(filters, arr[i].properties[j].ameNities))
				adArr[i] = &(arr[i].properties[j]);//add ad to adArr if filters are matching
		}
	}
	return adArr;//double pointer array of ads
}

bool compareAmenities(amenities& filters, amenities obj) {//true if equal
	if (filters.airConditioning != obj.airConditioning)
		return false;
	if (filters.balcony != obj.balcony)
		return false;
	if (filters.disabledAccess != obj.disabledAccess)
		return false;
	if (filters.kitchen != obj.kitchen)
		return false;
	if (filters.parkingLot != obj.parkingLot)
		return false;
	if (filters.swimmingPool != obj.swimmingPool)
		return false;
	if (filters.tv != obj.tv)
		return false;
	if (filters.washingMachine != obj.washingMachine)
		return false;
	if (filters.wifi != obj.wifi)
		return false;
	return true;
}
//-------------search
ad** searchAds(int size, landlord* arr) {
	//runs over landlors arr returns all ads that has the requested filters
	ad** adArr = NULL;
	cout << "please enter the required location:" << endl;
	string location = ValidLocation();//gets location from user
	int numOfGoodAds = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < arr[i].adSize; ++j) {
			//check if amenities equal
			if (iequals(location, arr[i].properties[j].location))
				++numOfGoodAds;//counts how many ads qualify
		}
	}
	try {
		adArr = new ad*[numOfGoodAds];
		if (!adArr)
			throw("allocation failed in filter ads");
	}
	catch (const char* const x) {
		cout << x << endl;
		throw;
	}
	catch (...) {
		cout << "ERROR!" << endl;
		throw;
	}
	//if allocation successfull
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < arr[i].adSize; ++j) {
			//check if amenities equal
			if (iequals(location, arr[i].properties[j].location))
				adArr[i] = &(arr[i].properties[j]);//add ad to adArr if locations are matching
		}
	}
	return adArr;//double pointer array of ads
}

bool iequals(const string& a, const string& b)//compare strings, insenstive to lower/upper case
{
	unsigned int sz = a.size();
	if (b.size() != sz)
		return false;
	for (unsigned int i = 0; i < sz; ++i)
		if (tolower(a[i]) != tolower(b[i]))
			return false;
	return true;
}
//-------------dates availability------------------------------------------------------ 
bool isDateAvailable(date d, const date& adDate) 
{//doesn't check validity of dates, needs to happen prior

	//checkin= d.fromDate, checkout= d.toDate, beginning= adDate.fromDate, ending= adDate.toDate
	//(beginning >= checkin && checkout >= beginning)||(checkin >= beginning && ending >= checkin)
	if ((isDateBiggerE(adDate.fromDay, adDate.fromMonth, adDate.fromYear, d.fromDay, d.fromMonth, d.fromYear)
		&& isDateBiggerE(d.toDay, d.toMonth, d.toYear, adDate.fromDay, adDate.fromMonth, adDate.fromYear))
		|| (isDateBiggerE(d.fromDay, d.fromMonth, d.fromYear, adDate.fromDay, adDate.fromMonth, adDate.fromYear)
			&& isDateBiggerE(adDate.toDay, adDate.toMonth, adDate.toYear, d.fromDay, d.fromMonth, d.fromYear)))
		return false;
	return true;
}//checks if dated are overlapping, false if UNavailable

bool legalInput(int day, int month, int year, int mode = 0) {//-------------------------------------------
	time_t t = time(ZERO);
	tm* now = localtime(&t);

	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (!mode) {
			return (ValidInput(day, MINinput, 31) &&
				isDateBiggerE(day, month, year, now->tm_mday, now->tm_mon + 1, now->tm_year + 1900)
				&& ValidInput(year, CURRENT_YEAR, MAX_YEAR));
		}
		return (ValidInput(day, MINinput, 31) && ValidInput(year, CURRENT_YEAR, MAX_YEAR));
		break;
	case 2:
		if (!mode) {
			return (ValidInput(day, MINinput, isLeap(year) ? 29 : 28) &&
				isDateBiggerE(day, month, year, now->tm_mday, now->tm_mon + 1, now->tm_year + 1900)
				&& ValidInput(year, CURRENT_YEAR, MAX_YEAR));
		}
		return (ValidInput(day, MINinput, isLeap(year) ? 29 : 28) && ValidInput(year, CURRENT_YEAR, MAX_YEAR));
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (!mode) {
			return (ValidInput(day, MINinput, 30) &&
				isDateBiggerE(day, month, year, now->tm_mday, now->tm_mon + 1, now->tm_year + 1900)
				&& ValidInput(year, CURRENT_YEAR, MAX_YEAR));
		}
		return (ValidInput(day, MINinput, 30) && ValidInput(year, CURRENT_YEAR, MAX_YEAR));
		break;
	default:
		return false;
	}
	return false;
}
date validDateInput() {//----------------------------------------------------------------
	bool flag = true;
	bool valid = true;
	int d, m, y, dd, mm, yy;
	int confirm = 1;
	date dt;
	system("CLS");
	do {
		cout << "Enter values according to instructions." << endl;
		do {
			cout << "please enter date: " << endl;
			cout << "*************CHECK IN**************" << endl;

			//test if legal d/m/y
			cout << "Day (from " << MINinput << " to " << MAX_DAY << "): ";
			cin >> d;
			cout << endl << "Month (from " << MINinput << " to " << MAX_MONTH << "): ";
			cin >> m;
			cout << endl << "Year (from " << CURRENT_YEAR << " to " << MAX_YEAR << "): ";
			cin >> y;
			//bigger or equal to today
			valid = legalInput(d, m, y);
			if (valid)
				flag = false;
			else {
				cout << "invalid date, please try again." << endl;
			}
			cout << "***********************************" << endl;
		} while (flag);
		flag = true;
		dt.fromDay = d;
		dt.fromMonth = m;
		dt.fromYear = y;
		//same for check out
		do {
			cout << "please enter date: " << endl;
			cout << "************CHECK OUT**************" << endl;
			//test if legal d/m/y
			cout << "Day (from " << d << " to " << MAX_DAY << "): ";
			cin >> dd;
			cout << endl << "Month (from " << MINinput << " to " << MAX_MONTH << "): ";
			cin >> mm;
			cout << endl << "Year (from " << y << " to " << MAX_YEAR << "): ";
			cin >> yy;
			//bigger or equal to today
			valid = (legalInput(d, m, y, 1) && isDateBiggerE(dd, mm, yy, d, m, y));
			if (valid)
				flag = false;
			else {
				cout << "invalid date, please try again." << endl;
			}
			cout << "***********************************" << endl;
		} while (flag);
		flag = true;
		dt.toDay = dd;
		dt.toMonth = mm;
		dt.toYear = yy;
		printDate(dt);
		cout << "enter 0 to confirm dates, else to try again." << endl;
		cin >> confirm;
	} while (confirm);
	return dt;
}//returns date with valid input from user

void printDate(const date& t) {//---------------------------------------------------
	cout << "CHECK IN: ";
	cout << t.fromDay << "/" << t.fromMonth << "/" << t.fromYear << endl;
	cout << "CHECK OUT: ";
	cout << t.toDay << "/" << t.toMonth << "/" << t.toYear << endl;
}

//-------------occupy dates

//-------------confirm credit card info

//-------------print deal confirmation(to screen)
void orderConfirmation(landlord* l, date* d)
{
	//generate random order number
	srand(time(NULL));
	int num = rand() % 100 + 1234;     // num in the range 1000 to 10000
	cout << "Your order is complete" << endl;
	cout << "Payment proccess has been successful" << endl;
	cout << "Order Number: " << num << endl;
	cout << "Dates From: " << d->fromDay << "/" << d->fromMonth << "/" << d->fromYear << " To:" << d->toDay << "/" << d->toMonth << "/" << d->toYear;
	cout << "Total price: " << difference_of_days(d->fromDay, d->fromMonth, d->fromYear, d->toDay, d->toMonth, d->toYear)*l->properties->price <<"NIS" <<endl;
	cout << "Landlord Details:" << endl;
	cout << "NAME: " << l->fullName << endl;
	cout << "PHONE NUMBER: " << l->phoneNumber << endl;
}

//-------total rent sum

//-------------support(print only)
void printSupport()
{
	//generate random case number
	srand(time(NULL));
	int num = rand() % 100 + 2567;     // num in the range 1000 to 10000
	cout << "Your request has been sent!" << endl
		<< "Case number :" << num << endl
		<< "had been opened with your request for support" << endl;
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
ad NewAd()
{//User input for new ad.
	ad newAd;
	newAd.available = true;
	cout << "New ad: " << endl;
	cout << "Ad discription: ";
	getline(cin, newAd.description);
	cout << "Price: ";
	newAd.price = ValidInput(ZERO, INT_MAX);
	cout << "Discount(0 ~ Price): ";
	newAd.discount = ValidInput(ZERO, newAd.price);
	newAd.location = ValidLocation();
	cout << "Number of people(up to 30): ";
	newAd.numOfPeople = ValidInput(1, 30);
	cout << "Number of rooms(up to 15): ";
	newAd.numOfRooms = ValidInput(1, 15);
	cout << "Number of beds(up to 30): ";
	newAd.numOfBeds = ValidInput(1, 30);
	cout << "Atractions: ";
	cin.ignore();
	getline(cin, newAd.attraction);
	cout << "Select amenities: ";
	newAd.ameNities = amenitiesCtor();
	newAd.rating = 5;
	return newAd;
}

//-------------check correctness of location input
string ValidLocation()
{
	//Location format <city>, <street> st.
	string location = "";
	string tmp;
	cout << "Please enter city: ";
	cin.ignore();
	getline(cin, tmp);
	location += tmp + ", ";
	cout << "Please enter street name: ";
	cin.ignore();
	getline(cin, tmp);
	location += tmp + " st.";
	return location;
}

//-------------check correctnes of input for new/edit ad
int ValidInput(int min, int max)
{
	//gets int as input from user: (min <= USER_INPUT <= max)
	//if wrong gets another one and prints error message.
	int num;
	cin >> num;
	while (num < min || num >max)
	{
		cout << "Wrong number!\n Must be: " << min << " <= YOUR_NUMBER <= " << max << ": " << endl;
		cin >> num;
	}
	return num;
}

bool ValidInput(char truevaluechar)
{//returns true for 'truevaluechar' else return false.
	char tmp;
	cin >> tmp;
	if (tmp == truevaluechar) return true;
	else return false;
}

bool ValidInput(int num, int min, int max)//--------------------------------------------
{
	//gets int as input from user: (min <= USER_INPUT <= max)
	if (num < min || num >max) {
		cout << "Wrong input!\n Must be: " << min << " <= YOUR_INPUT <= " << max << ". " << endl;
		return false;
	}
	return true;
}

//-------------get amenities
amenities amenitiesCtor()
{//User input for each amenity.
	amenities obj;
	cout << "enter 'y' for yes, other for no" << endl;
	cout << AMENITIES_NAMES[0] << ": ";
	obj.disabledAccess = ValidInput('y');
	cout << AMENITIES_NAMES[1] << ": ";
	obj.wifi = ValidInput('y');
	cout << AMENITIES_NAMES[2] << ": ";
	obj.kitchen = ValidInput('y');
	cout << AMENITIES_NAMES[3] << ": ";
	obj.tv = ValidInput('y');
	cout << AMENITIES_NAMES[4] << ": ";
	obj.balcony = ValidInput('y');
	cout << AMENITIES_NAMES[5] << ": ";
	obj.washingMachine = ValidInput('y');
	cout << AMENITIES_NAMES[6] << ": ";
	obj.airConditioning = ValidInput('y');
	cout << AMENITIES_NAMES[7] << ": ";
	obj.swimmingPool = ValidInput('y');
	cout << AMENITIES_NAMES[8] << ": ";
	obj.parkingLot = ValidInput('y');
	return obj;
}

//-------------edit ad
void EditAdMenu(ad* ad)
{
	int choose = 1;
	while (choose)
	{
		system("CLS");
		cout << "Edit ad menu.\nYour ad:" << endl;
		PrintAd(*ad);
		cout << ADSBREAK << endl;
		cout << "What you want to edit?" << endl;
		cout << "1)Change avilability (now: " << ad->available << ")." << endl
			<< "2)Change Discription." << endl
			<< "3)Change Price." << endl
			<< "4)Change Discount." << endl
			<< "5)Change num of people." << endl
			<< "6)Change num of rooms." << endl
			<< "7)Change num of beds." << endl
			<< "8)Edit amenities." << endl
			<< "9)Change attractions." << endl
			<< "0)Back to previous menu." << endl
			<< "Please enter your choise: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			ad->available = !ad->available;
			break;
		case 2:
			cout << "Enter new discription:";
			cin.ignore();
			getline(cin, ad->description);
			break;
		case 3:
			cout << "Enter new price: ";
			ad->price = ValidInput(ZERO, INT_MAX);
			break;
		case 4:
			cout << "Enter new discount: ";
			ad->discount = ValidInput(ZERO, 100);
			break;
		case 5:
			cout << "People amount(up to 30): ";
			ad->numOfPeople = ValidInput(1, 30);
			break;
		case 6:
			cout << "Amount of rooms(up to 15): ";
			ad->numOfRooms = ValidInput(1, 15);
			break;
		case 7:
			cout << "Number of beds(up to 30): ";
			ad->numOfBeds = ValidInput(1, 30);
			break;
		case 8:
			cout << "Select amenities: ";
			ad->ameNities = amenitiesCtor();
			break;
		case 9:
			cout << "Enter new attractions:";
			cin.ignore();
			getline(cin, ad->attraction);
			break;
		case 0:
			return;
			break;
		default:
			cout << "You entered wrong choise!!\n Try again: ";
			cin >> choose;
			break;
		}
	}
}

//-------------delete ad
void DeleteAd(ad* adsArr, int& adsize, int index)
{
	//delete the ad at [index] location.
	if (!adsize) cout << "No ads to delete!!!" << endl;
	else
	{
		ad* tmp = new ad[adsize - 1];
		for (int i = 0, j = 0; i < adsize - 1; j++, i++)
		{
			if (i == index) j++;
			tmp[i] = adsArr[j];
		}
		delete[] adsArr;
		adsArr = tmp;
		adsize--;
	}

}
//-------------total gainings for landlord

//-------------rate property(on last rent day)

//-------------calculate and update rates
void rateProperty(ad* a)
{
	int temp;
	cout << "Welcome to the rating system!" << endl;
	do
	{
		cout << "Please rate the experience on a property by enter 1-5 " << endl
			<< "1 being the lowest and 5 the highest" << endl;
		cin >> temp;
	} while (temp < 1 || temp>5);
	a->rating = (a->rating + temp) / 2;

}

//-------------prints ad for traveler(to screen)
//-------------print ad for landlord
void PrintAd(ad obj)
{
	cout << ADSBREAK << endl;
	cout << "Location: " << obj.location << endl;
	cout << "Ad discription: " << obj.description << endl;
	cout << "Price before discount: " << obj.price << endl;
	cout << "Price after discount:  " << obj.price - obj.discount << endl;
	cout << "Discount: " << "-" << obj.discount << "$" << endl;
	cout << "Number of people: " << obj.numOfPeople << "\trooms: " << obj.numOfRooms << "\tbeds: " << obj.numOfBeds << endl;
	cout << "Atractions: " << obj.attraction << endl;
	PrintAmenities(obj.ameNities);
}

//-------------print amenities
void PrintAmenities(amenities obj)
{
	string str = "Amenities:";
	if (obj.disabledAccess) str += AMENITIES_NAMES[0] + ", ";
	if (obj.wifi) str += AMENITIES_NAMES[1] + ", ";
	if (obj.kitchen) str += AMENITIES_NAMES[2] + ", ";
	if (obj.tv) str += AMENITIES_NAMES[3] + ", ";
	if (obj.balcony) str += AMENITIES_NAMES[4] + ", ";
	if (obj.washingMachine) str += AMENITIES_NAMES[5] + ", ";
	if (obj.airConditioning) str += AMENITIES_NAMES[6] + ", ";
	if (obj.swimmingPool) str += AMENITIES_NAMES[7] + ", ";
	if (obj.parkingLot) str += AMENITIES_NAMES[8] + ", ";
	str[str.length() - 2] = '.';
	cout << str << endl;
}


//-------------3 funcs: isLeap, DaysCountFrom1900, DateDaysCount calculates the days from start date to end date.
bool isLeap(int Y)
{
	if (Y % 400 == 0) return true;
	else if (Y % 100 == 0) return false;
	else if (Y % 4 == 0) return true;
	else return false;
}
int DaysCountFrom1900(int year, int month, int day)
{
	int ans = 0;
	for (int i = 1900; i < year; ++i) {
		if (isLeap(i)) {
			ans += 366;
		}
		else {
			ans += 365;
		}
	}
	for (int i = 1; i < month; ++i) {
		switch (i) {
		case 1: ans += 31; break;
		case 2: ans += isLeap(year) ? 29 : 28; break;
		case 3: ans += 31; break;
		case 4: ans += 30; break;
		case 5: ans += 31; break;
		case 6: ans += 30; break;
		case 7: ans += 31; break;
		case 8: ans += 31; break;
		case 9: ans += 30; break;
		case 10: ans += 31; break;
		case 11: ans += 30; break;
		case 12: ans += 31; break;
		}
	}
	return ans += day - 1;
}
int DateDaysCount(date date)
{
	return DaysCountFrom1900(date.toYear, date.toMonth, date.toDay) -
		DaysCountFrom1900(date.fromYear, date.fromMonth, date.fromDay);
}
//-------------calculate the profit from an ad.
int AdProfit(ad ad)
{
	//sum of all the ordered dates * price
	int profit = 0;
	if (!ad.dateSize) return ZERO;
	for (int i = 0; i < ad.dateSize; i++)
		profit += DateDaysCount(ad.occupied[i]) * (ad.price - ad.discount);
	return profit;
}
//-------------calculates landlords profit from all his ads.
void LandlordSumOfDealsUpdate(landlord ll)
{
	//calculate landlords profit and update the field.
	int sum = 0;
	if (ll.adSize)
		for (int i = 0; i < ll.adSize; i++)
			sum += AdProfit(ll.properties[i]);
	ll.sumOfDeals = sum;
}

//-------------Landlords menu : sub fuction- realloc the the ads array and adds 1 more ad.
void RealocateAdsPointer(ad* adsArr, int& adsize)
{
	//reallocates the pointer and changes the size:
	ad* tmp;
	tmp = new ad[adsize + 1];
	for (int i = 0; i < adsize; i++)
		tmp[i] = adsArr[i];
	adsize++;
	delete[] adsArr;
	adsArr = tmp;
}

//-------------Landlords menu : prints list of ads for landlord(to screen)
void LandlordsMenu(landlord ll)
{
	int choise = 1;
	LandlordSumOfDealsUpdate(ll);
	cout << "Landlords Menu:" << endl;
	cout << "Total profit: " << ll.sumOfDeals << endl;
	if (ll.adSize)
		for (int i = 0; i < ll.adSize; i++)
		{
			cout << ADSBREAK << endl << "\tAd no: " << i + 1 << endl;
			PrintAd(ll.properties[i]);
		}
	cout << ADSBREAK << endl;
	int input;
	while (choise != 4)
	{
		cout << "Please selet an option:" << endl
			<< "1)edit an ad." << endl
			<< "2)add new ad." << endl
			<< "3)delete an ad." << endl
			<< "4)Exit." << endl
			<< "enter your choise: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "Please insert ads number: ";
			input = ValidInput(1, ll.adSize) - 1;
			EditAdMenu(&ll.properties[input]);
			break;
		case 2:
			RealocateAdsPointer(ll.properties, ll.adSize);
			ll.properties[ll.adSize - 1] = NewAd();
			break;
		case 3:
			cout << "Please insert ads number: ";
			input = ValidInput(1, ll.adSize) - 1;
			DeleteAd(ll.properties, ll.adSize, input);
			break;
		case 4:
			//exit
			system("CLS");
			cout << "Good bye!!" << endl;
			break;
		default:
			cout << "Wrong choise!!\nTry again!\n ";
			break;
		}
	}


}

////***************also looped menus and instructions in each screen***************

//-------------delete all allocated data
void deleteAllocatedData(int sizeL, landlord* landlordArr, int sizeT, traveler* travelerArr) {
	deleteLandlordArr(sizeL, landlordArr);
	deleteTravelerArr(sizeT, travelerArr);
}

void deleteLandlordArr(int size, landlord* arr) {
	for (int i = 0; i < size; i++)
		delete[] arr[i].properties;//free each landlord's ad array
	delete[] arr;//free landlord array
}

void deleteTravelerArr(int size, traveler* arr) {
	delete[] arr;//free traveler array
}

//check_leap_year
int check_leap_year(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)   //if year is a leap year
		return 1;

	else
		return 0;
}
//no_of_days_in_month
int no_of_days_in_month(int month, int year)
{
	// jan, march, may, july, aug, oct, dec contains 31 days
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	// april, jun, sept, nov contains 30 days
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	if (month == 2)
	{
		if (check_leap_year(year) == 1)    // if year is a leap year then Feb will contain 29 days, otherwise it contains 28 days
			return 29;
		else
			return 28;
	}
}

//difference_of_days
int difference_of_days(int day1, int month1, int year1, int day2, int month2, int year2)
{
	if (year1 == year2)
	{
		if (month1 == month2)
		{
			if (day1 == day2)      //for same dates
				return 0;
			else
				return abs(day1 - day2);  //for same year, same month but diff days
		}
		else if (month1 < month2)
		{
			int result = 0;
			for (int i = month1; i < month2; i++)
				result = result + no_of_days_in_month(i, year1);

			if (day1 == day2)      //for same year, same day but diff month 
				return result;
			else if (day1 < day2)
			{
				result = result + (day2 - day1);
				return result;
			}
			else
			{
				result = result - (day1 - day2);
				return result;
			}
		}
		else
		{
			int result = 0;
			for (int i = month2; i < month1; i++)
				result = result + no_of_days_in_month(i, year1);

			if (day1 == day2)
				return result;
			else if (day2 < day1)
			{
				result = result + (day1 - day2);
				return result;
			}
			else
			{
				result = result - (day2 - day1);
				return result;
			}
		}
	}
	else if (year1 < year2)
	{
		int temp = 0;
		for (int i = year1; i < year2; i++)
		{
			if (check_leap_year(i))
				temp = temp + 366;
			else
				temp = temp + 365;
		}

		if (month1 == month2)
		{
			if (day1 == day2)      //for same month, same day but diff year
				return temp;
			else if (day1 < day2)
				return temp + (day2 - day1);
			else
				return temp - (day1 - day2);
		}
		else if (month1 < month2)
		{
			int result = 0;
			for (int i = month1; i < month2; i++)
				result = result + no_of_days_in_month(i, year2);

			if (day1 == day2)      // for same day, diff year and diff month
				return temp + result;
			else if (day1 < day2)
			{
				result = result + (day2 - day1);
				return temp + result;
			}
			else
			{
				result = result - (day1 - day2);
				return temp + result;
			}
		}
		else
		{
			int result = 0;
			for (int i = month2; i < month1; i++)
				result = result + no_of_days_in_month(i, year2);

			if (day1 == day2)
				return temp - result;
			else if (day2 < day1)
			{
				result = result + (day1 - day2);
				return temp - result;
			}
			else
			{
				result = result - (day2 - day1);
				return temp - result;
			}
		}
	}
	else
	{
		int temp = 0;
		for (int i = year2; i < year1; i++)
		{
			if (check_leap_year(i))
				temp = temp + 366;
			else
				temp = temp + 365;
		}

		if (month1 == month2)
		{
			if (day1 == day2)      // for same day, same month but diff year
				return temp;
			else if (day2 < day1)
				return temp + (day1 - day2);
			else
				return temp - (day2 - day1);
		}
		else if (month2 < month1)
		{
			int result = 0;
			for (int i = month2; i < month1; i++)
				result = result + no_of_days_in_month(i, year1);

			if (day1 == day2)
				return temp + result;
			else if (day2 < day1)
			{
				result = result + (day1 - day2);
				return temp + result;
			}
			else
			{
				result = result - (day2 - day1);
				return temp + result;
			}
		}
		else
		{
			int result = 0;
			for (int i = month1; i < month2; i++)
				result = result + no_of_days_in_month(i, year1);

			if (day1 == day2)      // for same day, diff year and diff month
				return temp - result;
			else if (day1 < day2)
			{
				result = result + (day2 - day1);
				return temp - result;
			}
			else
			{
				result = result - (day1 - day2);
				return temp - result;
			}
		}
	}
}
bool isDateBiggerE(int d, int m, int y, int dd, int mm, int yy) {//--------------------------
	//gets two dates checks if the 1st is bigger or equal
	if (y == yy && m == mm && d == dd)
		return true;
	if (y > yy)
		return true;
	else if (y == yy) {
		if (m > mm)
			return true;
		else if (m == mm) {
			if (d > dd)
				return true;
		}
	}
	return false;//first date is not bigger or equal
}

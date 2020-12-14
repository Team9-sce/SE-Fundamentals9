#define _CRT_SECURE_NO_WARNINGS
#include "structs.h"
#include "diralehaskir.h"
//#include <datetimeapi.h>// or another maybe??? 
using namespace std;

/*
//-------------print to file
void printToFile(int landlordSize, landlord* landlordArr, int travelerSize, traveler* travelerArr, int adSize, ad* adArr) {
	printLandlordToFile(landlordSize, landlordArr);//print all landlords
	printAdsToFile(adSize, adArr);//print all ads
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
			<< landlordArr[i].adSize << endl;//num of ads for this landlord
	}
	outFile.close();//close file
}
//-------------printAdsToFile
void printAdsToFile(int size, landlord* arr) {
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
	outFile << numOfAds(size, arr) << endl;//prints amount of all ads
	int i = 0;
	for (; i < size; ++i) {
		for (int j = 0; j < arr[i].adSize; ++j) {
			outFile << arr[i].properties[j].available << endl
				<< arr[i].properties[j].description << endl
				<< arr[i].properties[j].price << endl
				<< arr[i].properties[j].discount << endl
				<< arr[i].properties[j].location << endl
				<< arr[i].properties[j].numOfPeople << endl
				<< arr[i].properties[j].numOfRooms << endl
				<< arr[i].properties[j].numOfBeds << endl;
			//print amenities
			outFile << arr[i].properties[j].ameNities.disabledAccess << endl
				<< arr[i].properties[j].ameNities.wifi << endl
				<< arr[i].properties[j].ameNities.kitchen << endl
				<< arr[i].properties[j].ameNities.tv << endl
				<< arr[i].properties[j].ameNities.balcony << endl
				<< arr[i].properties[j].ameNities.washingMachine << endl
				<< arr[i].properties[j].ameNities.airConditioning << endl
				<< arr[i].properties[j].ameNities.swimmingPool << endl
				<< arr[i].properties[j].ameNities.parkingLot << endl;
			//print rest
			outFile << arr[i].properties[j].attraction << endl
				<< arr[i].properties[j].rating << endl
				<< arr[i].properties[j].dateSize << endl;
			//print occupied dates
			for (int k = 0; k < arr[i].properties[j].dateSize; ++k) {
				outFile << arr[i].properties[j].occupied[k].fromDay << endl
					<< arr[i].properties[j].occupied[k].fromMonth << endl
					<< arr[i].properties[j].occupied[k].fromYear << endl
					<< arr[i].properties[j].occupied[k].toDay << endl
					<< arr[i].properties[j].occupied[k].toMonth << endl
					<< arr[i].properties[j].occupied[k].toYear << endl;
			}
		}
	}
	outFile.close();//close file
}

int numOfAds(int size, landlord* arr) {
	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += arr[i].adSize;
	return sum;
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
			<< travelerArr[i].password << endl
			<< travelerArr[i].order.fromDay << endl
			<< travelerArr[i].order.fromMonth << endl
			<< travelerArr[i].order.fromYear << endl
			<< travelerArr[i].order.toDay << endl
			<< travelerArr[i].order.toMonth << endl
			<< travelerArr[i].order.toYear << endl;
	}
	outFile.close();//close file
}

//-------------read from file
void readFromFile(landlord* landlordArr, ad* adArr, traveler* travelerArr) {
	//read all landlords
	int lSize = readLandlordFromFile(landlordArr);//read all landlords
	//read all ads
	int aSize = readAdsFromFile(adArr);//read all landlords
	//read all travelers
	int tSize = readTravelerFromFile(travelerArr);
	//distribute ads to corresponding landlords
	splitAds(lSize, landlordArr, aSize, adArr);
}

 //-------------readlandlordFromFile
int readLandlordFromFile(landlord* landlordArr) {//read all landlords
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
	while (i < arrSize)
	{
		inFile.ignore();
		getline(inFile, landlordArr[i].fullName);
		inFile >> landlordArr[i].phoneNumber;
		inFile >> landlordArr[i].password;
		inFile >> landlordArr[i].id;
		inFile >> landlordArr[i].email;
		inFile >> landlordArr[i].sumOfDeals;
		inFile >> landlordArr[i].adSize;
	}
	inFile.close();//close file
	return arrSize;
}

 //-------------readAdsFromFile
int readAdsFromFile(ad* adsArr) {//read ads for landlord
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
	int arrSize = 0;
	inFile >> arrSize;
	if (!arrSize)
		return;
	try {
		adsArr = new ad[arrSize];
		if (!adsArr)
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
	//if succeeded

	int i = 0;
	for (; i < arrSize; ++i) {
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
		inFile >> adsArr[i].email;
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
		//read occupied dates
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
	return arrSize;
}
//-------------readTravelerFromFile
int readTravelerFromFile(traveler* travelerArr) {
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
		inFile >> travelerArr[i].order.fromDay;
		inFile >> travelerArr[i].order.fromMonth;
		inFile >> travelerArr[i].order.fromYear;
		inFile >> travelerArr[i].order.toDay;
		inFile >> travelerArr[i].order.toMonth;
		inFile >> travelerArr[i].order.toYear;
	}
	inFile.close();//close file
}//return value???
*/
//-------------sign in
int landlordSignIn(int size, landlord** landlordArr) {//returns true if login successful

	return size;
}

void splitAds(int lSize, landlord* arr, int aSize, ad* adArr) {//assigns each landlord his ads
	allocateAdArrays(lSize, arr);//allocates all landlords adArr and turns sizes to 0
	for (int i, k = 0; i < aSize; ++i) {
		for (int j = 0; j < lSize; ++j) {
			k = arr[j].adSize;
			if (adArr[i].email == arr[j].email) {
				arr[j].properties[k] = adArr[i];
				++k;
			}
		}
	}
	delete[] adArr;//delete ad arr after distributing all ads to their landlords
}

void allocateAdArrays(int size, landlord* arr){//allocates all landlords adArr and turns sizes to 0
	for (int i = 0; i < size; ++i) {
		try {
			arr[i].properties = new ad[arr[i].adSize];
			if (!arr[i].properties)
				throw("allocation failed in readFromFile-allocate ads array");
		}
		catch (const char* const x) {
			cout << x << endl;
			throw;
		}
		catch (...) {
			cout << "ERROR!" << endl;
			throw;
		}
		arr[i].adSize = 0;
	}
}
 //-------------sign in
int landlordSignIn(int size, landlord* landlordArr) {//returns true if login successful
	string tempId, tempPass;
	cout << "***LANDLORD - LOG IN***" << endl << "Please enter details according to instructions" << endl;
	//get id input
	cout << "ID must be exactly " << MAX_ID << " digits, numbers only." << endl;
	cout << "Please enter your ID:" << endl;
	cin >> tempId;
	//check length and input correctness
	if (tempId.length() != MAX_ID) {
		cout << "No such ID..." << endl;
		return NOT_FOUND;
	}
	//find index for landlord in array by id- assuming no two identical id's
	int index = findLandlordById(size, *landlordArr, tempId);
	if (index == NOT_FOUND) {//landlord not found
		cout << "No such ID..." << endl;
		return NOT_FOUND;
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
		return NOT_FOUND;
	}
	if (tempPass != landlordArr[index]->password) {//password equal
		cout << "Incorrect password...try again." << endl;
		return NOT_FOUND;
	}
	return index;
}

bool isStringAllDig(string str) {//check id the string is all digits
	for (int i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i]))//if false
			return false;
	}
	return true;
}
//-------------find landlord by id
int findLandlordById(int size, const landlord* const landlordArr, string id) {
	int i = 0;
	for (; i < size; ++i) {
		if (landlordArr[i].id == id)//if equal
			return i;
	}
	return NOT_FOUND;
}

int travelerSignIn(int size, traveler** travelerArr) {
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
		return NOT_FOUND;
	}
	//find index for traveler in array by name- assuming no two identical names
	int index = findTravelerByName(size, *travelerArr, tempName);
	if (index == NOT_FOUND) {//traveler not found
		cout << "No such user..." << endl;
		return NOT_FOUND;
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
		return NOT_FOUND;
	}
	if (tempPass != travelerArr[index]->password) {//password equal
		cout << "Incorrect password...try again." << endl;
		return not NOT_FOUND;
	}
	return index;
}

//-------------find traveler by full name
int findTravelerByName(int size, const traveler* travelerArr, string name)
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

bool isStringAllLetters(string str)
{
	for (int i = 0; i < str.length(); ++i)
		if (!isalpha(str[i]) && str[i] != ' ')
			return false;
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
		cout << "Phone number must be exactly " << MAX_PHONE << " digits, no spaces, numbers only." << endl;
		cout << "Please enter your phone number:" << endl;
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
/*
//-------------sort(display options in loop)
//------sort by low lo high*************************************************************
bool sortByLTH(ad* ad1, ad* ad2) {
	if (ad1->price + ad1->discount > ad2->price + ad2->discount)
		return true;
	return false;
}
//------sort by high to low*************************************************************
bool sortByHTL(ad* ad1, ad* ad2) {
	if (ad1->price + ad1->discount < ad2->price + ad2->discount)
		return true;
	return false;
}
//------sort by popularity(default)*****************************************************
bool sortByPopularity(ad* ad1, ad* ad2) {
	if (ad1->rating < ad2->rating)
		return true;
	return false;
}
// An optimized version of Bubble Sort**************************************************
/*
void bubbleSort(int size, ad** adArr, int mode = 0)
{
	int i, j;
	bool swapped;
	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (mode == 0) {//popularity(default)
				if (sortByPopularity(adArr[j], adArr[j + 1])) {
					swap(adArr[j], adArr[j + 1]);
					swapped = true;
				}
			}
			else if (mode == 1) {//low to high
				if (sortByLTH(adArr[j], adArr[j + 1])) {
					swap(adArr[j], adArr[j + 1]);
					swapped = true;
				}
			}
			else {//high to low
				if (sortByHTL(adArr[j], adArr[j + 1])) {
					swap(adArr[j], adArr[j + 1]);
					swapped = true;
				}
			}
		}
		// IF no two elements were swapped by inner loop, then break
		if (swapped == false)
			break;
	}
}

//------sort by dates***************************************************************

ad** sortAdsByDate(int& newSize, ad** adArr, int size, landlord* arr) {
	//get date
	date d = validDateInput();
	if (newSize == NOT_FOUND) {
		newSize = 0;
		//runs over landlors arr returns all ads available at the requested dates
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < arr[i].adSize; ++j) {
				for (int k = 0; k < arr[i].properties[j].dateSize; ++k) {
					//check if dates in ad are available
					if (isDateAvailable(d, arr[i].properties[j].occupied[k]))
						++newSize;//counts how many ads qualify
				}
			}
		}
		try {
			adArr = new ad*[newSize];
			if (!adArr)
				throw("allocation failed in sort ads by date");
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
				for (int k = 0; k < arr[i].properties[j].dateSize; ++k) {
					//check if dates in ad are available
					if (isDateAvailable(d, arr[i].properties[j].occupied[k]))
						adArr[i] = &(arr[i].properties[j]);//add ad to adArr if dates available
				}
			}
		}
	}
	else {
		int tempSize = 0;
		//run over existing adArr and return matching ads
		//runs over adArr returns all ads available at the requested dates
		for (int i = 0; i < newSize; ++i) {
			for (int j = 0; j < adArr[i]->dateSize; ++j) {
				//check if dates in ad are available
				if (isDateAvailable(d, adArr[i]->occupied[j]))
					++tempSize;//counts how many ads qualify
			}
		}
		if (!tempSize) {//found qualified ads in adArr
			int index = 0;
			for (int i = 0; i < newSize; ++i) {
				for (int j = 0; j < adArr[i]->dateSize; ++j) {
					//check if dates in ad are available
					if (isDateAvailable(d, adArr[i]->occupied[j])) {//if available
						adArr[i] = adArr[index];//enter to index's location in adArr
						++index;//inc index after assignment
					}
				}
			}
			newSize = tempSize;
		}
		else cout << "No ads with the previous filters match your description." << endl
			<< "Clear all filters and try again." << endl;
	}
	return adArr;//double pointer array of ads
}
*/
//-------------filter(display options in loop)
ad** filterAds(int& newSize, ad** adArr, int size, landlord* arr) {//***********************
	amenities filters = amenitiesCtor();//gets amenities from user
	if (newSize == NOT_FOUND) {
		newSize = 0;
		//runs over landlors arr returns all ads that has the requested filters
		cout << "please choose the filters you wish to apply" << endl;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < arr[i].adSize; ++j) {
				//check if amenities equal
				if (compareAmenities(filters, arr[i].properties[j].ameNities))
					++newSize;//counts how many ads qualify
			}
		}
		try {
			adArr = new ad * [newSize];
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
	}
	else {
		int tempSize = 0;
		//run over existing adArr and return matching ads
		//runs over adArr returns all ads with matches
		for (int i = 0; i < newSize; ++i) {
			//check if amenities qualify
			if (compareAmenities(filters, adArr[i]->ameNities))
				++tempSize;//counts how many ads qualify
		}
		if (!tempSize) {//found qualified ads in adArr
			int index = 0;
			for (int i = 0; i < newSize; ++i) {
				//check if amenities qualify
				if (compareAmenities(filters, adArr[i]->ameNities)) {//if available
					adArr[i] = adArr[index];//enter to index's location in adArr
					++index;//inc index after assignment
				}
			}
			newSize = tempSize;
		}
		else cout << "No ads with the previous filters match your description." << endl
			<< "Clear all filters and try again." << endl;
	}
	return adArr;//double pointer array of ads
}

ad** travelerExplore(int& newSize, ad** adArr, int size, landlord* arr) {//**********************
	newSize = 0;
	//runs over landlors arr returns all ads that has the requested filters
	newSize = numOfAds(size, arr);
	try {
		adArr = new ad *[newSize];
		if (!adArr)
			throw("allocation failed in traveler explore");
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
			//if ()
			adArr[i] = &(arr[i].properties[j]);//add ad to adArr if filters are matching
		}
		for (int i, k = 0; i < size; ++i) {
			for (int j = 0; j < arr[i].adSize&& k < newSize; ++j, ++k)
				adArr[k] = &(arr[i].properties[j]);//add ad to adArr if filters are matching
		}
	}
	printAndChooseFromAdArr(newSize, adArr);//prints all ads
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
//-------------search*********************************************************************
ad** searchAds(int& newSize, ad** adArr, int size, landlord* arr) {
	cout << "please enter the required location:" << endl;
	string location = ValidLocation();//gets location from user
	if (newSize == NOT_FOUND) {
		newSize = 0;
		//runs over landlors arr returns all ads that has the requested filters
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < arr[i].adSize; ++j) {
				//check if amenities equal
				if (iequalsContain(arr[i].properties[j].location, location))//if equal/contains
					++newSize;//counts how many ads qualify
			}
		}
		try {
			adArr = new ad * [newSize];
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
				if (iequalsContain(arr[i].properties[j].location, location))
					adArr[i] = &(arr[i].properties[j]);//add ad to adArr if locations are matching
			}
		}
	}
	else {
		int tempSize = 0;
		//run over existing adArr and return matching ads
		//runs over adArr returns all ads with sub string location
		for (int i = 0; i < newSize; ++i) {
			//check if ads qualify
			if (iequalsContain(adArr[i]->location, location))
				++tempSize;//counts how many ads qualify
		}
		if (!tempSize) {//found qualified ads in adArr
			int index = 0;
			for (int i = 0; i < newSize; ++i) {
				//check if ads qualify
				if (iequalsContain(adArr[i]->location, location)) {//if location is equal/contained
					adArr[i] = adArr[index];//enter to index's location in adArr
					++index;//inc index after assignment
				}
			}
			newSize = tempSize;
		}
		else cout << "No ads with the previous filters match your description." << endl
			<< "Clear all filters and try again." << endl;
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
/*
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
*/
void printDate(const date& t) {//---------------------------------------------------
	cout << "CHECK IN: ";
	cout << t.fromDay << "/" << t.fromMonth << "/" << t.fromYear << endl;
	cout << "CHECK OUT: ";
	cout << t.toDay << "/" << t.toMonth << "/" << t.toYear << endl;
}


void ReallococcupyDatesArr(ad* a)
{
	date* temp = new date[a->dateSize + 1];
	for (int i = 0; i < a->dateSize; i++) temp[i] = a->occupied[i];
	a->dateSize++;
	delete[] a->occupied;
	a->occupied = temp;
}

//-------------occupy dates
void occupyDates(date d, ad* a)
{
	ReallococcupyDatesArr(a);
	a->occupied[a->dateSize - 1] = d;
}


//-------------confirm credit card info
bool creditCardValidation(const string cardNumber, const string expirationMonth, const string expirationYear, const string cvv, const string ownerID)
{
	time_t t = time(0);
	tm* now = localtime(&t);

	if (!isStringAllDig(cardNumber) || cardNumber.length() != 16) return false;//check card number
	if (!isStringAllDig(expirationYear) || stoi(expirationYear) < (now->tm_year + 1900) || (stoi(expirationYear) + 1900) > 9999) return false;//check expiration year
	if ((stoi(expirationYear) == now->tm_year + 1900) && (!isStringAllDig(expirationMonth) || stoi(expirationMonth) < (now->tm_mon + 1) || stoi(expirationMonth) > 12)) return false;//check expiration month if expiration year is current year
	if (!isStringAllDig(expirationMonth) || stoi(expirationMonth) < 0 || stoi(expirationMonth) > 12) return false;//check expiration month otherwise
	if (!isStringAllDig(cvv) || cvv.length() != 3) return false;//check cvv
	if (!isStringAllDig(ownerID) || ownerID.length() != 9) return false;//check ID

	return true;//if nothing wrong was found
}

//-------------print deal confirmation(to screen)
void orderConfirmation(landlord* l, date* d)
{
	//generate random order number
	srand(time(NULL));
	int num = rand() % 100 + 1234;     // num in the range 1234 to 1334
	int total = difference_of_days(d->fromDay, d->fromMonth, d->fromYear, d->toDay, d->toMonth, d->toYear)*l->properties->price;
	cout << "Your order is complete!" << endl;
	cout << "Payment proccess has been successful" << endl;
	cout << "Order Number: " << num << endl;
	cout << "Dates From: " << d->fromDay << "/" << d->fromMonth << "/" << d->fromYear << " To:" << d->toDay << "/" << d->toMonth << "/" << d->toYear;
	cout << "Total price: " << difference_of_days(d->fromDay, d->fromMonth, d->fromYear, d->toDay, d->toMonth, d->toYear) * l->properties->price << "NIS" << endl;
	cout << "Total price: " << total <<"NIS" <<endl;
	cout << "Landlord Details:" << endl;
	cout << "NAME: " << l->fullName << endl;
	cout << "PHONE NUMBER: " << l->phoneNumber << endl;
	//call occupy dates
	//call sum of deals
}

//-------total rent sum

//-------------support(print only)
void printSupport()
{
	//generate random case number
	srand(time(NULL));
	int num = rand() % 100 + 2567;     // num in the range 2567 to 2667
	cout << "Your request has been sent!" << endl
		<< "Case number :" << num << endl
		<< "had been opened with your request for support" << endl;
}

//-------------faq(print only)
void printFaq()
{
	cout << "THE SOFTWARE IS NOT WORKING PROPERLY, HOW DO I FIX IT?" << endl
		<< "Please try using a different deviceand if there is no improvement try to reset your router." << endl << endl
		<< "IS THE SITE SECURE ?" << endl
		<< "Yes, the company uses a security company in order to secure all your personal information." << endl << endl
		<< "HOW DO I RATE MY STAY ?" << endl
		<< "At the end of rent time a rating screen will be available in which you can rate your stay." << endl;
}
//-------------travelers homepage
/*
void travelerMenu(int lSize, landlord* lArr, int tSize, traveler* tArr) {//NOT FINISHED*******
	int choice = 0;
	int newSize = NOT_FOUND;
	ad** adArr = NULL;
	bool support = false;//can't request support twice
	bool order = false;//if has one order can't order anymore
	do {
		cout << "----WELCOME TRAVELER!----" << endl
			<< "Find the best place for your next vacation!" << endl
			<< "This is your basic menu-Please choose how you wish to proceed:" << endl
			<< "-------------------------------" << endl
			<< "1. Explore- displays all ads in default order." << endl
			<< "2. Enter specific dates to sort by." << endl
			<< "3. Search by location." << endl
			<< "4. Filter ads." << endl
			<< "5. Sort ads." << endl
			<< "6. Clear all my filters, searches and sorts." << endl
			<< "7. FAQ." << endl
			<< "8. Support." << endl
			<< "9. Rate." << endl
			<< "0. LOG OUT." << endl
			<< "-------------------------------" << endl;
		cout << "-> We recommend you first enter location and/or "
			<< "choose dates in order to maximize the filtering and sorting options." << endl;
		cout << "When printed the ads will be numbered and you could choose one and place," << endl
			<< "or you could return here and use different sorting options." << endl
			<< "-------------------------------" << endl
			<< "Please enter your choice:" << endl;

		cin >> choice;
		if (choice == 1) {
			deleteAdArr(adArr);
			adArr = NULL;
			newSize = -1;
			adArr = travelerExplore(newSize, adArr, lSize, lArr);
			int res = printAndChooseFromAdArr(newSize, adArr);
			if (res != NOT_FOUND) {
				//placeOrder()//then payment()//then orderConfirmation()
			}
		}
		else if (choice == 2) {
			if (!newSize) {// no ads qualified previous filters
				cout << "No ads with the previous filters match your description." << endl
					<< "Clear all filters and try again." << endl;
			}
			adArr = sortAdsByDate(newSize, adArr, lSize, lArr);
		}
		else if (choice == 3) {
			if (!newSize) {// no ads qualified previous filters
				cout << "No ads with the previous filters match your description." << endl
					<< "Clear all filters and try again." << endl;
			}
			adArr = searchAds(newSize, adArr, lSize, lArr);
		}
		else if (choice == 4) {

		}
		else if (choice == 5) {

		}
		else if (choice == 6) {
			adArr = NULL;
			newSize = -1;
		}
		else if (choice == 7) {

		}
		else if (choice == 8) {
			if (!support) {
				printSupport();
				support = true;
			}
			else cout << "You already sent a request..." << endl;
		}
		else if (choice == 9) {

		}
		else if (choice < 0 || choice > 9) {
			cout << "Invalid input, try again." << endl;
		}
	} while (choice != 0);
	cout << "THANK YOU! Logging out..." << endl;
}
*/
//-------------landlord menu

//-------------new ad
ad NewAd()
{//User input for new ad.
	ad newAd;
	newAd.available = true;
	cout << "New ad: " << endl;
	cout << "Ad description: ";
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
	cout << "Atraction: ";
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
	char answer;
	cout << "Please enter city: ";
	cin.ignore();
	getline(cin, tmp);
	location += tmp;
	cout << "Do you want to enter address?" << endl << "'y' for yes, else for no: ";
	cin >> answer;
	if (answer == 'y')
	{
		cout << "Please enter street name: ";
		cin.ignore();
		getline(cin, tmp);
		location += ", " + tmp + " st.";
	}
	else location += ".";
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
		cout << "EDIT AD MENU \nYour ad:" << endl;
		PrintAd(*ad);
		cout << ADSBREAK << endl;
		cout << "What do you want to edit?" << endl;
		cout << "1) Change avilability (now: " << ad->available << ")." << endl
			<< "2) Change Description." << endl
			<< "3) Change Price." << endl
			<< "4) Change Discount." << endl
			<< "5) Change num of people." << endl
			<< "6) Change num of rooms." << endl
			<< "7) Change num of beds." << endl
			<< "8) Edit amenities." << endl
			<< "9) Change attractions." << endl
			<< "0) Back to previous menu." << endl
			<< "Please enter your choice: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			ad->available = !ad->available;
			break;
		case 2:
			cout << "Enter new description:";
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
			cout << "Number of people(up to 30): ";
			ad->numOfPeople = ValidInput(1, 30);
			break;
		case 6:
			cout << "Number of rooms(up to 15): ";
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
			cout << "Enter a new attraction:";
			cin.ignore();
			getline(cin, ad->attraction);
			break;
		case 0:
			return;
			break;
		default:
			cout << "You entered a wrong choice!!\n Try again: ";
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
//-------------rate property(on last rent day)

//-------------calculate and update rates
void rateProperty(ad* a)
{
	time_t t = time(ZERO);
	tm* now = localtime(&t);
	if ()
	int temp;
	cout << "Welcome to the rating system!" << endl;
	do
	{
		cout << "Please rate the experience on a property by entering 1-5 " << endl
			<< "1 being the lowest and 5 the highest" << endl;
		cin >> temp;
	} while (temp < 1 || temp>5);
	a->rating = (a->rating + temp) / 2;

}

//-------------prints ad for traveler(to screen)
int printAndChooseFromAdArr(int newSize, ad** adArr) {//*********************************************
	//print for TRAVELER to choose from
	for (int i = 0; i < newSize; ++i) {
		cout << "NUMBER " << i + 1 << " :" << endl
			<< "**==============================**" << endl;
		cout << "Ad description: " << adArr[i]->description << endl;
		cout << "Price before discount: " << adArr[i]->price << endl;
		cout << "Price after discount:  " << adArr[i]->price - adArr[i]->discount << endl;
		cout << "Discount: " << "-" << adArr[i]->discount << "NIS" << endl;
		cout << "Location: " << adArr[i]->location << endl;
		cout << "Number of People: " << adArr[i]->numOfPeople << endl
			<< "Number of Rooms: " << adArr[i]->numOfRooms << endl
			<< "Number of Beds: " << adArr[i]->numOfBeds << endl;
		PrintAmenities(adArr[i]->ameNities);
		cout << "Atractions: " << adArr[i]->attraction << endl;
		cout << "Landlord Email: " << adArr[i]->email << endl;
		cout << "Rating: " << adArr[i]->rating << endl;
		cout << "**==============================**" << endl;
	}
	cout << "If you want to choose an ad and procced to order-" << endl
		<< "Please enter the number of the ad, if you wish to go back to menu press 0" << endl;
	cout << "enter your choice: ";
	int choice = 0;
	cin >> choice;
	if (!choice)
		return NOT_FOUND;//doesn't want to order yet
	return choice - 1;
}

//-------------print ad for landlord
void PrintAd(ad obj)
{
	cout << ADSBREAK << endl;
	cout << "Location: " << obj.location << endl;
	cout << "Ad description: " << obj.description << endl;
	cout << "Price before discount: " << obj.price << endl;
	cout << "Price after discount:  " << obj.price - obj.discount << endl;
	cout << "Discount: " << "-" << obj.discount << "NIS" << endl;
	cout << "Number of people: " << obj.numOfPeople << endl;
	cout << "Number of rooms: " << obj.numOfRooms << endl;
	cout << "Number of beds: " << obj.numOfBeds << endl;
	cout << "Atraction: " << obj.attraction << endl;
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
	for (int i = 1900; i < year; ++i)
		if (isLeap(i))ans += 366;
		else ans += 365;
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
//-------------total gainings for landlord
//-------------calculate the profit from an ad.
//-------------calculates landlords profit from all his ads.

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
//-------------landlord homescreen
//-------------Landlords menu : prints list of ads for landlord(to screen)
void LandlordsMenu(landlord ll)
{
	int choise = 1;
	cout << "LANDLORD MENU:" << endl;
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
		cout << "Please select an option:" << endl
			<< "1) edit an ad." << endl
			<< "2) add new ad." << endl
			<< "3) delete an ad." << endl
			<< "4) Exit." << endl
			<< "enter your choice: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "Please enter ad number: ";
			input = ValidInput(1, ll.adSize) - 1;
			EditAdMenu(&ll.properties[input]);
			break;
		case 2:
			RealocateAdsPointer(ll.properties, ll.adSize);
			ll.properties[ll.adSize - 1] = NewAd();
			break;
		case 3:
			cout << "Please enter ad number: ";
			input = ValidInput(1, ll.adSize) - 1;
			DeleteAd(ll.properties, ll.adSize, input);
			break;
		case 4:
			//exit
			system("CLS");
			cout << "Good bye!!" << endl;
			break;
		default:
			cout << "Wrong choice!!\nTry again!\n ";
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

void deleteAdArr(ad** arr) {
	delete[] arr;
}

//difference_of_days
int difference_of_days(int day1, int month1, int year1, int day2, int month2, int year2)
{
	return abs(DaysCountFrom1900(year1, month1, day1) - DaysCountFrom1900(year2, month2, day2));
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
string strToLower(string a) {//*************************************************************
	//converts entire string to lowerCase
	for (int i = 0; i < a.length(); ++i)
		a[1] = tolower(a[i]);
	return a;
}
bool iequalsContain(const string& a, const string& b)//*************************************
{//compare strings, insenstive to lower/upper case

	//a bigger
	//firstly check if equal
	if (iequals(a, b))
		return true;
	//else create new lowercase strings
	string a1, b1;
	a1 = strToLower(a);
	b1 = strToLower(b);
	//check if b1 is subtring of a1
	for (int i = 0; i < a1.length() && b1.length(); ++i)
		if (a1[i] != b1[i])
			return false;
	return true;
}
void swap(ad* ad1, ad* ad2)//***********************************************************
{
	//swap ads in adArr
	ad* temp = ad1;
	ad1 = ad2;
	ad2 = temp;
}


void RealloctravelersArr(traveler** arr, int& size)
{
	size++;
	traveler** tmp = new traveler * [size];
	if (!tmp) cout << "Memory allocate fail!" << endl;
	for (int i = 0; i < size - 1; i++) tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}
void ReallocLandlordsArr(landlord** arr, int size)
{
	landlord** tmp = new landlord * [size + 1];
	for (int i = 0; i < size; i++) tmp[i] = arr[i];
	size++;
	delete[] arr;
	arr = tmp;
}

void Register(landlord** landlordsArr, int& landlordSize, traveler** travelersArr, int& travelersSize)
{
	system("CLS");
	int choise = 1;
	while (choise != 3)
	{
		cout << "Register:" << endl
			<< "1)Landlord." << endl
			<< "2)Traveler." << endl
			<< "3)Return to previous menu." << endl
			<< "Please enter your choise: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			RegisterLandlord(landlordsArr, landlordSize, travelersArr, travelersSize);
			//update db
			system("CLS");
			break;
		case 2:
			RegisterTraveler(travelersArr, travelersSize);
			//update db
			//RealloctravelersArr(travelersArr, travelersSize);
			//cout << trv->phoneNumber;
			//travelersArr[travelersSize - 1] = NewTraveler();
			system("CLS");
			cout << "Traveler added successfuly!" << endl;
			break;
		case 3:
			system("CLS");
			break;
		default:
			cout << "Wrong choise!!\nTry again: ";
			break;
		}
	}
}

void MainPage(landlord** landlordsArr, int& landlordSize, traveler** travelersArr, int& travelersSize)
{
	//system("CLS");
	int landlord_index = NOT_FOUND;
	int traveler_index = NOT_FOUND;
	int choise = 0;
	while (choise != 4)
	{
		cout << "main menu:" << endl//need to be changed! add beutiful header.
			<< "1) Log in as traveler." << endl
			<< "2) Log in as landlord." << endl
			<< "3) Register." << endl
			<< "4) Exit." << endl
			<< "Please enter your choise:";
		cin >> choise;
		switch (choise)
		{
		case 1:
			traveler_index = travelerSignIn(travelersSize, travelersArr);
			cout << traveler_index;
			break;
		case 2:
			landlord_index = landlordSignIn(landlordSize, landlordsArr);// -  change to duble pointer.
			cout << landlord_index;
			break;
		case 3:
			Register(landlordsArr, landlordSize, travelersArr, travelersSize);
			break;
		case 4:
			cout << "Good bye!";
			break;
		default:
			cout << "Wrong choise!!\nTry again: ";
			break;
		}

	}
}


void PrintLandlordsAds(landlord ll)
{
	if (!ll.adSize)
	{
		cout << "No ads!" << endl;
		return;
	}
	for (int i = 0; i = ll.adSize; i++)
	{
		PrintAd(ll.properties[i]);
	}
	cout << ADSBREAK << endl;
}

string NameInput()
{
	bool flag;
	string buffer;
	do {
		flag = false;
		cout << "Name must be up to  " << MAX_NAME << " letters only." << endl;
		cout << "Please enter your full name:";
		cin.ignore();
		getline(cin, buffer);
		if (!(buffer.length() <= MAX_NAME && buffer.length() > 0)) flag = true;
		if (!isStringAllLetters(buffer)) flag = true;
		if (flag) cout << "Incorrect input, try again." << endl;
	} while (flag);
	return buffer;
}
string PhoneInput()
{
	bool flag;
	string buffer;
	do {
		flag = false;
		cout << "PhoneNumber must be exactly " << MAX_PHONE << " digits, no spaces, numbers only." << endl;
		cout << "Please enter your phoneNumber:";
		getline(cin, buffer);
		if (buffer.length() != MAX_PHONE) flag = true;
		if (!isStringAllDig(buffer)) flag = true;
		if (flag) cout << "Incorrect length, try again." << endl;
	} while (flag);
	return buffer;
}
string PasswordInput()
{
	bool flag;
	string buffer;
	do {
		flag = false;
		cout << "Password can be minimum: " << MIN_PASSWORD
			<< " characters and maximum: " << MAX_PASSWORD << " characters," << endl
			<< "Can contain any characters you wish except 'enter'." << endl;
		cout << "Please enter your password:";
		getline(cin, buffer);
		//check length and input correctness
		if (buffer.length() < MIN_PASSWORD || buffer.length() > MAX_PASSWORD) flag = true;
		if (flag) cout << "Incorrect length, try again." << endl;
	} while (flag);
	return buffer;
}
traveler* NewTraveler()
{
	traveler* trv = new traveler;
	trv->fullName = NameInput();
	trv->phoneNumber = PhoneInput();
	trv->password = PasswordInput();
	cout << "NewTraveler: " << trv->fullName << endl;
	cout << "NewTraveler: " << trv->phoneNumber << endl;
	cout << "NewTraveler: " << trv->password << endl;
	return trv;
}
void RegisterTraveler(traveler** travelersArr, int& size)
{
	size++;
	traveler** tmp = new traveler * [size];
	if (!tmp) cout << "Memory allocate fail!" << endl;
	for (int i = 0; i < size - 1; i++) tmp[i] = travelersArr[i];
	travelersArr = tmp;
	//cout << trv->phoneNumber;
	travelersArr[size - 1] = NewTraveler();
	//cout <<endl<<"dd: "<< trv->password;
	cout << travelersArr[size - 1]->phoneNumber;
}
string ValidId()
{
	string id;
	bool has_only_digits = false;
	while (!has_only_digits)
	{
		cout << "Please enter id(9 digits): ";
		cin >> id;
		has_only_digits = true;
		for (int i = 0; i < id.length(); i++)
			if (!isdigit(id[i])) has_only_digits = false;
		if (!has_only_digits) cout << "Wrong id! Please try again!" << endl;
	}
	return id;
}
string ValidEmail()
{
	/// gets a valid email form from user.
	string email;
	bool at = false, dot = false;
	while (!at || !dot)
	{
		at = false;
		dot = false;
		cout << "Please enter email: ";
		cin >> email;
		for (int i = 0; i < email.length(); i++)
		{
			if (email[i] == '@') at = true;
			if (at && email[i] == '.') dot = true;
		}
		if (!at || !dot) cout << "Wrong email! Please try again!" << endl;
	}
	return email;
}
void RegisterLandlord(landlord** landlordsArr, int& landlordSize, traveler** travelersArr, int& travelersSize)
{
	RegisterTraveler(travelersArr, travelersSize);
	landlord* newLandlord = new landlord;
	newLandlord->fullName = travelersArr[travelersSize - 1]->fullName;
	newLandlord->phoneNumber = travelersArr[travelersSize - 1]->phoneNumber;
	newLandlord->password = travelersArr[travelersSize - 1]->password;
	newLandlord->id = ValidId();
	newLandlord->email = ValidEmail();
	newLandlord->sumOfDeals = 0;
	newLandlord->adSize = 0;
	ReallocLandlordsArr(landlordsArr, landlordSize);
	landlordsArr[landlordSize - 1] = newLandlord;
}

int main()
{
	landlord** landlord_arr = new landlord*[0];
	int landlord_arr_size = 0;
	traveler** travelers_arr = new traveler*[0];
	int travelers_arr_size = 0;
	MainPage(landlord_arr, landlord_arr_size, travelers_arr, travelers_arr_size);
	return 0;
}


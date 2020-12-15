#ifndef DIRALEHASKIR_H
#define DIRALEHASKIR_H
#include <iostream>
#include <stdlib.h>
//#include <cstdlib>
#include <stdio.h>
//#include <cstring>
#include <string>
//#include <string.h>
#include <fstream>
#include <ctime>
#include <ctype.h>

#define ADSBREAK "========================================="
#define ZERO 0
#define MAX_EMAIL 8 
#define MAX_ID 9
#define MAX_PHONE 10
#define MAX_NAME 15 //enough???
#define MAX_PASSWORD 10 //less???
#define MIN_PASSWORD 4
#define BUFFER 20
#define AMENITIES 9
#define NOT_FOUND -1
#define MINinput 1
#define MAX_DAY 31
#define MAX_MONTH 12
#define CURRENT_YEAR 2020
#define MAX_YEAR 2030

const string AMENITIES_NAMES[AMENITIES] = { "disabledAccess", "wifi", "kitchen", "tv", "balcony", "washingMachine", "airConditioning", "swimmingPool", "parkingLot" };


using namespace std;
//--------------------------------------------------------------
//---------------------Checked and Work-------------------------
//--------------------------------------------------------------
//Fields:
landlord* landlord_arr = NULL;
int landlord_arr_size = 0;
traveler* travelers_arr = NULL;
int travelers_arr_size = 0;
ad* ads_arr = NULL;
int ads_arr_size = 0;
//Register:
void Register();
traveler NewTraveler();
void RegisterTraveler();
void RegisterLandlord();
//Sign-in funcs:
int landlordSignIn();
int findLandlordById(string id);
int travelerSignIn();
int findTravelerByName(string name);
//input validation:
bool isStringAllDig(string str);
bool isStringAllLetters(string str);
string ValidLocation();
int ValidInput(int min, int max);
bool ValidInput(char truevaluechar);
bool ValidInput(int num, int min, int max);
string NameInput();
string PhoneInput();
string PasswordInput();
string ValidId();
string ValidEmail();
amenities amenitiesCtor();
//Menus:
void MainPage();
void LandlordsLoginMenu(int ll_index, int trv_index);
void LandlordsMenu(int index);
void PrintAd(ad obj);
void EditAdMenu(int ll_index, int ad_index);
//Ads manipulations:
void DeleteAd(int landlord_index, int ad_index);
ad NewAd();
//Realloc:
void RealloctravelersArr();
void ReallocLandlordsArr();
void RealocateAdsPointer(int landlord_index);
//Output:
void PrintLandlordsAds(landlord ll);
void PrintAmenities(amenities obj);
//delete allocated data:
void deleteAllocatedData();
void deleteAdArr(ad** arr);
//--------------------------------------------------------------

void printToFile();
void printLandlordToFile();
void printAdsToFile();
void printTravelerToFile();
void readFromFile();
void readLandlordFromFile();
void readAdsFromFile();
void readTravelerFromFile();
int numOfAds();
void splitAds();
void allocateAdArrays();

int difference_of_days(int day1, int month1, int year1, int day2, int month2, int year2);
bool compareAmenities(amenities& filters, amenities obj);//true if equal
ad** filterAds(int size, landlord* arr);
bool iequals(const string& a, const string& b);//compare strings, insenstive to lower/upper case
bool ValidInput(int num, int min, int max);//check
bool isDateBiggerE(int d, int m, int y, int dd, int mm, int yy);
bool isDateAvailable(date d, const date& adDate);
bool legalInput(int day, int month, int year, int mode = 0);//check
date validDateInput();
void printDate(const date& t);
string strToLower(string a);
bool iequalsContain(const string& a, const string& b);
void swap(ad* ad1, ad* ad2);
bool sortByLTH(ad* ad1, ad* ad2);
bool sortByHTL(ad* ad1, ad* ad2);
bool sortByPopularity(ad* ad1, ad* ad2);
void bubbleSort(int size, ad** adArr, int mode = 0);
ad** sortAdsByDate(int& newSize, ad** adArr, int size, landlord* arr);
ad** travelerExplore(int& newSize, ad** adArr, int size, landlord* arr);
int printAndChooseFromAdArr(int newSize, ad** adArr);
void travelerMenu(int lSize, landlord* lArr, int tSize, traveler* tArr);
bool creditCardValidation(const string cardNumber, const string expirationMonth, const string expirationYear, const string cvv, const string ownerID);//confirm credit card details


#endif // !DIRALEHASKIR_H

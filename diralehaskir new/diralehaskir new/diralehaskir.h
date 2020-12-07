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

#define MAX_EMAIL 8 //רק לקידומת
#define MAX_ID 9
#define MAX_PHONE 10
#define MAX_NAME 15 //enough???
#define MAX_PASSWORD 10 //less???
#define BUFFER 20
#define AMENITIES 9

using namespace std;

void printToFile(int landlordSize, landlord* landlordArr, int travelerSize, traveler* travelerArr);
void printAdsToFile(int size, ad* adsArr);
void printTravelerToFile(int size, traveler* travelerArr);
void readFromFile(landlord* landlordArr, traveler* travelerArr);
void readAdsFromFile(int size, ad* adsArr);	//read ads for landlord
void readTravelerFromFile(traveler* travelerArr);
void landlordSignIn(int size, landlord* landlordArr);
void travelerSignIn(int size, traveler* travelerArr);
void travelerSignUp(traveler* travelerArr, int size);
void landlordSignUp(int size, landlord* landlordArr);


#endif // !DIRALEHASKIR_H
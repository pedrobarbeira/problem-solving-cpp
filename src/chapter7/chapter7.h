#ifndef _CHAPTER_7_H
#define _CHAPTER_7_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <string>

int outOfOrder(double[], int);
void readArray();
void letterBox();
template<typename T>
void print(T[], size_t);

using namespace std;



void ch7Exercise1();
bool firstLast2(int[], size_t);


void ch7Exercise2();
int countNum2s(int arr[], size_t);


void ch7Exercise3();
void swapFrontBack(int[], size_t);


void ch7Exercise4();
string lookupName(string, string[], string[], size_t);


void ch7ProgProject1();


void ch7ProgProject2();
void readHex(char[], bool&);
void convertHex(char[], long long int&);
int hexToDec(char);
char decToHex(int);


void ch7ProgProject3();
void delete_repeats(char [], int&);


void ch7ProgProject4();
double stDev(double[], int);


void ch7ProgProject5();
template<typename T>
void index(T[], int&);
template<typename T>
void readArray(istream&,T[], int&);
template<typename T>
void sortArray(T[], int&);
template<typename T>
void countFrequency(T[], int[], int&);


void ch7ProgProject6();
void insertionSort(int* arr, int size);


void ch7ProgProject7();
char* storeInArray(std::string in, char* n, size_t size);
char* addIntegersArr(char* n1, char* n2, char* ret, size_t size);
int handleOverflow();
int repeatComputation();


void ch7ProgProject8();
void letterOccurrences(const std::string&, char*, uint16_t*);
void printLetterOccurrences(char*, uint16_t*);
void sortOccurrences(char*, uint16_t*);
void defragmentOccurences(char*, uint16_t*);

void ch7ProgProject9();
void readCardInput(int* values, char* suits);
void checkHand(int* values, char* suits);

void ch7ProgProject10();
void gameState(string[][3]);
void makePlay(string[][3], int, string);
bool checkWin(string[][3], string);


void ch7ProgProject11();
bool bookSeat(bool* seats[], std::string in);
void printSeats(bool* seats[]);

void ch7ProgProject12();


void ch7ProgProject13();


void ch7ProgProject14();


void ch7ProgProject15();


void ch7ProgProject16();


void ch7ProgProject17();


void ch7ProgProject18();


void ch7ProgProject19();


void ch7ProgProject20();


#endif
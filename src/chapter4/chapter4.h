//SOLVED
#ifndef _CHAPTER_4_H
#define _CHAPTER_4_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

#define L_PER_GALLON		0.264179
#define UNI_GRAVIT			6.673 * pow(10, -8) 
#define KG_TO_POUNDS		2.20462262



void ch4Exercise1();
double milesPerGalon(double, double);
bool valid(char);


void ch4Exercise2();


void ch4Exercise3();
double stockCalc(int, int, int);


void ch4Exercise4();
double infCalc(double, double);


void ch4Exercise5();
double estimateCalc(double, double);


void ch4Exercise6();
double interestCalc(double, double, int);


void ch4Exercise7();
double gravitation(double, double, double);


void ch4Exercise8();
int absRe(int);
float absRe(float);
double absRe(double);
long absRe(long);


void ch4Exercise9();
double max(double, double);
double max(double, double, double);


void ch4ProgProject1();
double afterTax(double, double);
double taxSavings(double);


void ch4ProgProject2();
double hatSize(double, double);
double jackSize(double, double, int);
double waistSize(double, int);


void ch4ProgProject3();

void ch4ProgProject4();
string tenths(int);
string teens(int);
string units(int);


void ch4ProgProject5();
double basalMetabolicRate(double);
double physicalActivityCal(int, double, int);
double toPounds(double);


void ch4ProgProject6();
bool valid_coin(char);
double insert_coin(char);
double give_change(double);


void ch4ProgProject7();
bool valid_AM(char);
int compute_difference(int, int, bool, int, int, bool);


void ch4ProgProject8();
void ch4ProgProject9();


#endif

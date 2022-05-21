//SOLVED
#ifndef _CHAPTER_5_H
#define _CHAPTER_5_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <string>
#include <random>

using namespace std;

#define METER_IN_FOOT		0.3048
#define INCH_IN_FOOT		12
#define CM_IN_METER			100
#define LB_TO_KG			2.2046
#define G_TO_KG				1000
#define OZ_TO_LB			16



void ch5Exercise1();
void computation(double, double, double, double, double&, double&);
void average(double, double, double, double, double&);
void stdDev(double, double, double, double, double&);


void ch5Exercise2();
void getInput(double&, double&);
void meterConversion(double&, double&, double, double);
void showOutput(double, double, bool);


void ch5Exercise3();
void feetConversion(double&, double&, double, double);


void ch5Exercise4();
void meterToFeet(double&, double&, double, double);
void feetToMeter(double&, double&, double, double);


void ch5Exercise5();
void input(double&, double&);
void toKilos(double&, double&, double, double);
void output(double&, double&, bool);


void ch5Exercise6();
void toPounds(double&, double&, double, double);


void ch5Exercise7();
void poundsToKg(double&, double&, double, double);
void kgToPounds(double&, double&, double, double);


void ch5Exercise8();


void ch5Exercise9();
void triangle(double&, double&, double, double, double);


void ch5ProgProject1();
void hourReader(int&, int&);
void hourConversion(char&, int&, int);
void printTime(int, int, char);


void ch5ProgProject2();
void getTime(int&, int&);
void waitingPeriod(int&, int);
void printTime(int);


void ch5ProgProject3();
void hourConversion(char&, int&);
void printTime(int, char);


void ch5ProgProject4();
void getCoin(int&);
void computeCoin(int, int&, int&);
void showOutput(int, int, int, int);


void ch5ProgProject5();
void wChillInput(double&, double&);
void windChill(double&, double, double);
void showOutput(double);


void ch5ProgProject6();
void shoot(bool&, double);
void startDuel(int&);


void ch5ProgProject7();
void getInput(int&, int&, int&);
bool isLeapYear(int);
int getCenturyValue(int);
int getYearValue(int);
int getMonthValue(int, int);


void ch5ProgProject8();
int dayOfWeek(int, int, int);



#endif
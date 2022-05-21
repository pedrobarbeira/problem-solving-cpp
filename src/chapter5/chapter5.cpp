//SOLVED
#include "chapter5.h"



void ch5Exercise1() {
	/*Write a function that computes the average and standard deviation of four 
	scores. The standard deviation is defined to be the square root of the average 
	of the four values: (si– a)^2, where a is average of the four scores s1, s2, 
	s3, and s4. The function will have six parameters and will call two other 
	functions. Embed the function in a driver program that allows you to test 
	the function again and again until you tell the program you are finished.*/
	double a, b, c, d, avg, stDev;

	while (true) {
		cout << "$";

		cin >> a;
		if (a == -1) break;
		cin >> b >> c >> d;

		computation(a, b, c, d, avg, stDev);

		cout << fixed << setprecision(4)
			<< "Average: " << avg << endl
			<< "Std Dev: " << stDev << endl << endl;
	}
}

void computation(double a, double b, double c, double d, double& avg, double& stDev) {
	average(a, b, c, d, avg);
	stdDev(a - avg, b - avg, c - avg, d - avg, stDev);
}
void average(double a, double b, double c, double d, double& avg){
	avg = (a + b + c + d) / 4;
}
void stdDev(double a, double b, double c, double d, double& stDev) {
	stDev = sqrt((pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2)) / 4);
}



void ch5Exercise2() {
	/*Write a program that reads in a length in feet and inches and outputs the 
	equivalent length in meters and centimeters. Use at least three functions: 
	one for input, one or more for calculating, and one for output. Include a 
	loop that lets the user repeat this computation for new input values until 
	the user says he or she wants to end the program. There are 0.3048 meters 
	in a foot, 100 centimeters in a meter, and 12 inches in a foot.*/
	double feet, inches,
		meters, centimeters;

	while (true) {

		getInput(feet, inches);
		if (feet == -1) break;

		meterConversion(meters, centimeters, feet, inches);
		showOutput(meters, centimeters, true);
	}

}

void getInput(double& feet, double& inches){
	cout << "$";
	cin >> feet;
	if (feet == -1) return;
	cin >> inches;
	cin.ignore(100000, '\n');
}
void meterConversion(double& meters, double& centimeters, double feet, double inches){
	feet += inches / INCH_IN_FOOT;
	meters = int(feet * METER_IN_FOOT);
	centimeters = (feet * METER_IN_FOOT - meters) * CM_IN_METER;
}
void showOutput(double meters, double centimeters, bool metric) {
	if (metric) cout << meters << "," << setprecision(2) << centimeters << "m.\n\n";
	else cout << meters << "'" << setprecision(2) << centimeters << "\".\n\n";
}



void ch5Exercise3(){
	/*Write a program like that of the previous exercise that converts from meters 
	and centimeters into feet and inches. Use functions for the subtasks.*/
	double meters, centimeters,
		feet, inches;
	while (true) {
		getInput(meters, centimeters);
		if (meters == -1) break;
		feetConversion(feet, inches, meters, centimeters);
		showOutput(feet, inches, false);
	}
}

void feetConversion(double& feet, double& inches, double meters, double centimeters){
	double inchInCm = 100 / (12 / METER_IN_FOOT);
	centimeters += meters * 100;
	inches = centimeters / inchInCm;
	feet = (int)(inches / INCH_IN_FOOT);
	inches -= feet * INCH_IN_FOOT;
}



void ch5Exercise4(){
	/*(You should do the previous two Practice Programs before doing this 
	one.) Write a program that combines the functions in the previous two 
	Practice Programs. The program asks the user if he or she wants to convert 
	from feet and inches to meters and centimeters or from meters and 
	centimeters to feet and inches. The program then performs the desired 
	conversion. Have the user respond by typing the integer 1 for one type of 
	conversion and 2 for the other conversion. The program reads the user’s 
	answer and then executes an if-else statement. Each branch of the 
	if-else statement will be a function call. The two functions called in 
	the if-else statement will have function definitions that are very similar 
	to the programs for the previous two Practice Programs. Thus, they will be 
	function definitions that call other functions in their function bodies. 
	Include a loop that lets the user repeat this computation for new input values 
	until the user says he or she wants to end the program.*/
	int choice;
	double m, cm, ft, in;

	cout << "[1] Metric to Imperial\n"
		<< "[2] Imperial to Metric\n"
		<< "[0] Exit\n\n";

	do{
		cout << "$";
		cin >> choice;

		switch (choice) {
		case 1:
			meterToFeet(m, cm, ft, in);
			break;
		case 2:
			feetToMeter(ft, in, m, cm);
			break;
		case 0: continue;
		default: cout << "Invalid Input";
		}
	} while (choice != 0);
}
void meterToFeet(double& ft, double& in, double m, double cm){
	getInput(m, cm);
	feetConversion(ft, in, m, cm);
	showOutput(ft, in, false);
}
void feetToMeter(double& m, double& cm, double ft, double in){
	getInput(ft, in);
	meterConversion(m, cm, ft, in);
	showOutput(m, cm, true);
}



void ch5Exercise5() {
	/*Write a program that reads in a weight in pounds and ounces and outputs 
	the equivalent weight in kilograms and grams. Use at least three functions: 
	one for input, one or more for calculating, and one for output. 
	Include a loop that lets the user repeat this computation for new input 
	values until the user says he or she wants to end the program. There are 
	2.2046 pounds in a kilogram, 1000 grams in a kilogram, and 16 ounces 
	in a pound.*/
	double lb, oz,
		kg, g;

	while (true) {
		input(lb, oz);
		if (lb == -1) break;
		toKilos(kg, g, lb, oz);
		output(kg, g, true);
	}
}

void input(double& lb, double& oz){
	cout << "$";
	cin >> lb;
	if (lb == -1) return;
	cin >> oz;
}
void toKilos(double& kg, double& g, double lb, double oz){
	double oz_to_kg = LB_TO_KG * OZ_TO_LB;
	oz += lb * OZ_TO_LB;
	kg = int(oz / oz_to_kg);
	g = (oz / oz_to_kg - kg) * G_TO_KG;
}
void output(double& kg, double& g, bool metric) {
	if (metric)
		cout << kg << " kg and " << g << " grams\n";
	else
		cout << kg << " lb and " << g << " oz\n";
}



void ch5Exercise6() {
	/*Write a program like that of the previous exercise that converts from 
	kilograms and grams into pounds and ounces. Use functions for the subtasks*/
	double lb, oz,
		kg, g;

	while (true) {
		input(kg, g);
		if (kg == -1) break;
		toPounds(lb, oz, kg, g);
		output(lb, oz, false);
	}
}

void toPounds(double& lb, double& oz, double kg, double g) {
	kg += g / G_TO_KG;
	lb = int(kg * LB_TO_KG);
	oz = ((kg * LB_TO_KG) - lb) * 16;
}



void ch5Exercise7() {
	/*(You should do the previous two Practice Programs before doing this 
	one.) Write a program that combines the functions of the previous two 
	Practice Programs. The program asks the user if he or she wants to convert 
	from pounds and ounces to kilograms and grams or from kilograms 
	and grams to pounds and ounces. The program then performs the desired 
	conversion. Have the user respond by typing the integer 1 for one type of 
	conversion and 2 for the other. The program reads the user’s answer and 
	then executes an if-else statement. Each branch of the if-else statement 
	will be a function call. The two functions called in the if-else statement 
	will have function definitions that are very similar to the programs for the 
	previous two Practice Programs. Thus, they will be function definitions that 
	call other functions in their function bodies. Include a loop that lets the 
	user repeat this computation for new input values until the user says he or 
	she wants to end the program.*/
	int choice;
	double kg = 0, g = 0, lb = 0, oz = 0;

	cout << "[1] Metric to Imperial\n"
		<< "[2] Imperial to Metric\n"
		<< "[0] Exit\n\n";

	do {
		cout << "$";
		cin >> choice;

		switch (choice) {
		case 1:
			kgToPounds(kg, g, lb, oz);
			break;
		case 2:
			poundsToKg(lb, oz, kg, g);
			break;
		case 0: continue;
		default: cout << "Invalid Input";
		}
		cout << endl;
	} while (choice != 0);
}

void poundsToKg(double& kg, double& g, double lb, double oz){
	input(lb, oz);
	toKilos(kg, g, lb, oz);
	output(kg, g, true);
}
void kgToPounds(double& lb, double& oz, double kg, double g){
	input(kg, g);
	toPounds(lb, oz, kg, g);
	output(lb, oz, false);
}



void ch5Exercise8() {
	/*(You need to do Practice Programs 4 and 7 before doing this one.) 
	Write a program that combines the functions of Practice Programs 4 
	and 7. The program asks the user if he or she wants to convert lengths or 
	weights. If the user chooses lengths, then the program asks the user if he 
	or she wants to convert from feet and inches to meters and centimeters 
	or from meters and centimeters to feet and inches. If the user chooses 
	weights, a similar question about pounds, ounces, kilograms, and grams 
	is asked. The program then performs the desired conversion. Have the 
	user respond by typing the integer 1 for one type of conversion and 2 
	for the other. The program reads the user’s answer and then executes an 
	if-else statement. Each branch of the if-else statement will be a function 
	call. The two functions called in the if-else statement will have function 
	definitions that are very similar to the programs for Practice Programs 4 
	and 7. Thus, these functions will be function definitions that call other 
	functions in their function bodies; however, they will be very easy to write 
	by adapting the programs you wrote for Practice Programs 4 and 7.
	Notice that your program will have if-else statements embedded inside of 
	if-else statements, but only in an indirect way. The outer if-else statement 
	will include two function calls as its two branches. These two function calls 
	will each in turn include an if-else statement, but you need not think about 
	that. They are just function calls and the details are in a black box that you 
	create when you define these functions. If you try to create a four-way branch, 
	you are probably on the wrong track. You should only need to think about 
	two-way branches (even though the entire program does ultimately branch 
	into four cases). Include a loop that lets the user repeat this computation for 
	new input values until the user says he or she wants to end the program.*/
	int choice;
	double m = 0, cm = 0, ft = 0, in = 0,
		kg = 0, g = 0, lb = 0, oz = 0;

	cout << "[1] Lengths\n"
		<< "[2] Weights\n"
		<< "[0] Exit\n\n";
	
	do {
		cout << "$";
		cin >> choice;

		if (choice == 0) exit(0);
		else if (choice == 1) {
			cin.ignore(1000, '\n');
			cout << "\t\tLenghts\n\n"
				<< "\t[1] Metric to Imperial\n"
				<< "\t[2] Imperial to Metric\n"
				<< "\t[0] Back\n\n";

			do {
				cout << "$";
				cin >> choice;

				switch (choice) {
				case 1:
					meterToFeet(ft, in, m, cm);
					break;
				case 2:
					feetToMeter(m, cm, ft, in);
					break;
				case 0: continue;
				default: cout << "Invalid Option\n";
				}
			} while (choice != 0);
		}
		else if (choice == 2) {
			cin.ignore(1000, '\n');
			cout << "\t\tWeights\n\n"
				<< "\t[1] Metric to Imperial\n"
				<< "\t[2] Imperial to Metric\n"
				<< "\t[0] Back\n\n";

			do {
				cout << "$";
				cin >> choice;

				switch (choice) {
				case 1:
					kgToPounds(kg, g, lb, oz);
					break;
				case 2:
					poundsToKg(lb, oz, kg, g);
					break;
				case 0: continue;
				default: cout << "Invalid Option\n";
				}
			} while (choice != 0);
		}
		else cout << "Invalid Option\n";

		choice = 4;
		cin.ignore(1000, '\n');
	} while (choice != 0);
}



void ch5Exercise9() {
	/*The area of an arbitrary triangle can be computed using the formula

		area = s(s – a)(s – b)(s – c)
 
	where a, b, and c are the lengths of the sides, and s is the semiperimeter.

		s = (a + b + c)/2
 
	 Write a void function that computes the area and perimeter (not the 
	semiperimeter) of a triangle based on the length of the sides. The function 
	should use five parameters—three value parameters that provide the lengths 
	of the edges and two reference parameters that store the computed area 
	and perimeter. Make your function robust. Note that not all combinations 
	of a, b, and c produce a triangle. Your function should produce correct 
	results for legal data and reasonable results for illegal combinations.*/

	while(true){
		double a = 0, b = 0, c = 0, area = 0, perimeter = 0;

		cout << "$";
		
		cin >> a >> b >> c;

		triangle(area, perimeter, a, b, c);
		if (area != 0 && perimeter != 0) {
			cout << "Area: " << area << endl
				<< "Perimeter: " << perimeter << endl;
		}
	}
}

void triangle(double& area, double& perimeter, double a, double b, double c) {
	
	if (a <= 0 || b <= 0 || c <= 0) {
		cout << "Lengths must be nonzero positive values!\n";
		return;
	}

	if (a + b <= c || a + c <= b || c + b <= a) {
		cout << "Thats not a triangle!\n";
		return;
	}
	
	double s;
	perimeter = a + b + c;
	s = perimeter / 2;
	area = s * (s - a) * (s - b) * (s - c);
}



void ch5ProgProject1() {
	/*Write a program that converts from 24-hour notation to 12-hour notation. 
	For example, it should convert 14:25 to 2:25 PM. The input is given as two 
	integers. There should be at least three functions, one for input, one to do the 
	conversion, and one for output. Record the AM/PM information as a value of 
	type char, ‘A’ for AM and ‘P’ for PM. Thus, the function for doing the conversions 
	will have a call-by-reference formal parameter of type char to record 
	whether it is AM or PM. (The function will have other parameters as well.) 
	Include a loop that lets the user repeat this computation for new input values 
	again and again until the user says he or she wants to end the program.*/
	int hour, min;
	char period;

	do {
		hourReader(hour, min);
		hourConversion(period, hour, min);
		printTime(hour, min, period);

		cout << "Repeat(y/n): ";
		cin >> period;
	} while (period != 'N' && period != 'n');
}

void hourReader(int& hour, int& min){
	bool valid = false;

	while (!valid) {
		cout << "$";
		
		cin >> hour;
		
		if (hour < 0 || hour >= 24) cout << "Invalid hour\n";
		else valid = true;
		
		cin.get();
		
		cin >> min;
		
		if (min < 0 || min >= 60) {
			cout << "Invalid minute\n";
			valid = false;
		}
	}
}
void hourConversion(char& period, int& hour, int min){
	if (hour <= 12) period = 'A';
	else {
		hour %= 12;
		period = 'P';
	}
}
void printTime(int hour, int min, char period) {
	cout << "Converts to " << hour << ":" << min << " " << period << "M\n";
}



void ch5ProgProject2() {
	/*Write a program that requests the current time and a waiting time as two 
	integers for the number of hours and the number of minutes to wait. The 
	program then outputs what the time will be after the waiting period. Use 
	24-hour notation for the times. Include a loop that lets the user repeat this 
	calculation for additional input values until the user says she or he wants 
	to end the program.*/
	int currentTime, waitingTime;

	do {
		getTime(currentTime, waitingTime);
		waitingPeriod(currentTime, waitingTime);
		printTime(currentTime);

		cout << "Repeat(y/n): ";
	} while (cin.get() != 'N' && cin.get() != 'n');
}

void getTime(int& time1, int& time2) {
	cout << "$";
	cin >> time1 >> time2;
}
void waitingPeriod(int& time1, int time2) {
	int hours = time1 / 100;
	int minutes = time1 % 100;

	minutes += time2 % 100;
	hours += minutes / 60;
	minutes %= 60;

	hours += time2 / 100;
	hours %= 24;

	time1 = hours * 100 + minutes;
}
void printTime(int time) {
	cout << setfill('0') << "Finish Time: " 
		 << setw(2) << time / 100 << ":" 
		 << setw(2) << time % 100 << endl;
} 



void ch5ProgProject3() {
	/*Modify your program for Programming Project 2 so that it uses 12-hour 
	notation, such as 3:45 PM.*/

	int currentTime, waitingTime;
	char period;

	do {
		getTime(currentTime, waitingTime);
		waitingPeriod(currentTime, waitingTime);
		hourConversion(period, currentTime);
		printTime(currentTime, period);

		cout << "Repeat(y/n): ";
	} while (cin.get() != 'N' && cin.get() != 'n');
}

void hourConversion(char& period, int& time1) {
	if (time1 / 100 < 12 || time1 / 100 == 12) period = 'A';
	else {
		period = 'P';
		time1 %= 1200;
	}
}
void printTime(int time1, char period) {
	cout << setfill('0') << "Finish Time: "
		<< setw(2) << time1 / 100 << ":"
		<< setw(2) << time1 % 100 
		<< " " << period << "M\n";
}



void ch5ProgProject4() {
	/*Write a program that tells what coins to give out for any amount of change 
	from 1 cent to 99 cents. For example, if the amount is 86 cents, the output 
	would be something like the following:
		
		86 cents can be given as
		3 quarter(s) 1 dime(s) and 1 penny(pennies)
	
	Use coin denominations of 25 cents (quarters), 10 cents (dimes), and 1 cent 
	(pennies). Do not use nickel and half-dollar coins. Your program will use 
	the following function (among others):
		
		void compute_coins(int coin_value, int& num, int& amount_left);
		//Precondition: 0 < coin_value < 100; 0 <= amount_left < 100.
		//Postcondition: num has been set equal to the maximum number
		//of coins of denomination coin_value cents that can be obtained
		//from amount_left. Additionally, amount_left has been decreased
		//by the value of the coins, that is, decreased by
		//num * coin_value.
 
	For example, suppose the value of the variable amount_left is 86. Then, 
	after the following call, the value of number will be 3 and the value of 
	amount_left will be 11 (because if you take 3 quarters from 86 cents, that 
	leaves 11 cents):
		
		compute_coins(25, number, amount_left);
	
	Include a loop that lets the user repeat this computation for new input 
	values until the user says he or she wants to end the program. (Hint: Use 
	integer division and the % operator to implement this function.)*/
	int quarters, dimes, pennies, change;

	while (true) {
		getCoin(change);
		if (change == -1) break;
		computeCoin(25, quarters, change);
		if (change != -1) {
			computeCoin(10, dimes, change);
			computeCoin(1, pennies, change);
			change = 25 * quarters + 10 * dimes + pennies;
			showOutput(change, quarters, dimes, pennies);
		}
	}
}

void getCoin(int& change) {
	cout << "$";
	cin >> change;
}
void computeCoin(int coinValue, int& num, int& ammountLeft){
	if (coinValue <= 0 || coinValue >= 100) {
		ammountLeft = -1;
		cout << "Invalid coin value!\n";
		return;
	}
	else if (ammountLeft < 0 || ammountLeft >= 100) {
		ammountLeft = -1;
		cout << "Invalid ammount value!\n";
		return;
	}
	num = ammountLeft / coinValue;
	ammountLeft %= coinValue;
}
void showOutput(int change, int quarters, int dimes, int pennies) {
	cout << change << " cents can be given as\n"
		<< quarters << " quarter(s), "
		<< dimes << " dime(s) and "
		<< pennies << " penny(ies)\n";
}



void ch5ProgProject5() {
	/*In cold weather, meteorologists report an index called the windchill factor,
	that takes into account the wind speed and the temperature. The index 
	provides a measure of the chilling effect of wind at a given air temperature. 
	Windchill may be approximated by the formula:
	
		W = 13.12 + 0.6215 * t – 11.37 * v^0.16 + 0.3965 * t * v^0.016
	
	where
 
		v = wind speed in m/sec
		t = temperature in degrees Celsius: t <= 10
		W = windchill index (in degrees Celsius)
	
	Write a function that returns the windchill index. Your code should ensure 
	that the restriction on the temperature is not violated. Look up some 
	weather reports in back issues of a newspaper in your university library and 
	compare the windchill index you calculate with the result reported in the 
	newspaper.*/
	double v, t, wChill;

	do{
		wChillInput(v, t);
		if (t > 10) {
			t = 11;
			cout << "Invalid temperature!\n";
		}
		else {
			windChill(wChill, v, t);
			showOutput(wChill);
			cout << "Repeat(y/n): ";
		}
	} while (getchar() != 'n' && getchar() != 'N');
}

void wChillInput(double& v, double& t) {
	cout << "$";
	cin >> v;
	cin >> t;
}
void windChill(double& wChill, double v, double t){
	wChill = 13.12 + 0.6215 - 11.37 * pow(v, 0.016) + 0.3965 * t * pow(v, 0.016);
}
void showOutput(double wChill){
	cout << "Windchill Index: " << wChill << "oC\n";
}


void ch5ProgProject6() {
	/*In the land of Puzzlevania, Aaron, Bob, and Charlie had an argument
	over which one of them was the greatest puzzler of all time. To end the
	argument once and for all, they agreed on a duel to the death. Aaron is a
	poor shooter and only hits his target with a probability of 1/3. Bob is a
	bit better and hits his target with a probability of 1/2. Charlie is an expert
	marksman and never misses. A hit means a kill and the person hit drops
	out of the duel.
	To compensate for the inequities in their marksmanship skills, it is decided
	that the contestants would fire in turns starting with Aaron, followed by Bob,
	and then by Charlie. The cycle would repeat until there was one man standing.
	And that man would be remembered as the greatest puzzler of all time.

	a. Write a function to simulate a single shot. It should use the following
	declaration:

		void shoot(bool& targetAlive, double accuracy);

	This would simulate someone shooting at targetAlive with the given
	accuracy by generating a random number between 0 and 1. If the random
	number is less than accuracy, then the target is hit and targetAlive
	should be set to false. Chapter 4 illustrates how to generate random
	numbers.
	For example, if Bob is shooting at Charlie, this could be invoked as:

		shoot(charlieAlive, 0.5);

	Here, charlieAlive is a Boolean variable that indicates if Charlie is alive.
	Test your function using a driver program before moving on to step b.

	b. An obvious strategy is for each man to shoot at the most accurate
	shooter still alive on the grounds that this shooter is the deadliest and
	has the best chance of hitting back. Write a second function named
	startDuel that uses the shoot function to simulate an entire duel
	using this strategy. It should loop until only one contestant is left,
	invoking the shoot function with the proper target and probability of
	hitting the target according to who is shooting. The function should
	return a variable that indicates who won the duel.

	c. In your main function, invoke the startDuel function 1000 times in a
	loop, keeping track of how many times each contestant wins. Output
	the probability that each contestant will win when everyone uses the
	strategy of shooting at the most accurate shooter left alive.

	d. A counterintuitive strategy is for Aaron to intentionally miss on his first
	shot. Thereafter, everyone uses the strategy of shooting at the most accurate
	shooter left alive. This strategy means that Aaron is guaranteed
	to live past the first round, since Bob and Charlie will fire at each other.
	Modify the program to accommodate this new strategy and output the
	probability of winning for each contestant.*/
	int wint;
	double aaronWins = 0,
		bobWins = 0,
		charlieWins = 0;
	
	for (int i = 0; i < 1000; i++) {
		startDuel(wint);
		switch (wint) {
		case 1: aaronWins++; break;
		case 2: bobWins++; break;
		case 3: charlieWins++; break;
		}
	}

	double aaronWinP = aaronWins / 10,
		bobWinP = bobWins / 10,
		charlieWinP = charlieWins / 10;

	cout << "Arron Wins: " << aaronWins << "\t(" << aaronWinP << "%)\n"
		<< "Bob Wins: " << bobWins << "\t(" << bobWinP << "%)\n"
		<< "Charlie Wins: " << charlieWins << "\t(" << charlieWinP << "%)\n";

}

void shoot(bool& targetAlive, double accuracy) {
	random_device rnd;
	mt19937 gen(rnd());
	uniform_real_distribution<>dis(0, 1);
	double shot = dis(gen);
	if (shot < accuracy) targetAlive = false;
}
void startDuel(int& winner) {
	bool charlieAlive = true,
		aaronAlive = true,
		bobAlive = true,
		firstShot = true;
	double charlie = 1,
		aaron = 1.0 / 3,
		bob = 0.5;
	int alive = 3;

	while (alive > 1) {
		if (firstShot) {
			shoot(charlieAlive, bob);
			if (!charlieAlive) alive--;
			else {
				shoot(bobAlive, charlie);
				alive--;
			}
			firstShot = false;
		}
		if (charlieAlive) {
			shoot(charlieAlive, aaron);
			if (!charlieAlive) {
				alive--;
				shoot(aaronAlive, bob);
				if (!aaronAlive) {
					alive--;
					winner = 2;
				}
			}
			else {
				if (bobAlive) {
					shoot(charlieAlive, bob);
					if (!charlieAlive) alive--;
					else {
						shoot(bobAlive, charlie);
						alive--;
					}
				}
				else {
					shoot(aaronAlive, charlie);
					alive--;
					winner = 3;
				}
			}
		}
		else {
			shoot(bobAlive, aaron);
			if (!bobAlive) {
				alive--;
				winner = 1;
			}
			else {
				shoot(aaronAlive, bob);
				if (!aaronAlive) {
					alive--;
					winner = 2;
				}
			}
		}
	}
}



void ch5ProgProject7() {
	/*Write a program that inputs a date (for example, July 4, 2008) and outputs 
	the day of the week that corresponds to that date. The following algorithm 
	is from http://en.wikipedia.org/wiki/Calculating_the_day_of_the_week. 
	The implementation will require several functions.
	
		bool isLeapYear(int year);

		int getCenturyValue(int year);

		int getYearValue(int year);

		int getMonthVa0lue(int month, int year);

	Finally, to compute the day of the week, compute the sum of the date’s
	day plus the values returned by getMonthValue, getYearValue, and
	getCenturyValue. Divide the sum by 7 and compute the remainder. A
	remainder of 0 corresponds to Sunday, 1 corresponds to Monday, etc., P
	up to 6, which corresponds to Saturday. For example, the date July 4,
	2008 should be computed as (day of month) + (getMonthValue) +
	(getYearValue) + (getCenturyValue) = 4 + 6 + 10 + 6 = 26. 26/7 = 3
	with a remainder of 5. The fifth day of the week corresponds to Friday.
	Your program should allow the user to enter any date and output the
	corresponding day of the week in English.
	
	This program should include a void function named getInput that 
	prompts the user for the date and returns the month, day, and year using 
	pass-by-reference parameters. You may choose to have the user enter the 
	date’s month as either a number (1–12) or a month name.*/
	int day, month, year, weekday;

	getInput(day, month, year);
	weekday = (day + getCenturyValue(year) + getYearValue(year) + getMonthValue(month, year)) % 7;
	switch (weekday) {
	case 0: cout << "Sunday\n"; break;
	case 1: cout << "Monday\n"; break;
	case 2: cout << "Tuesday\n"; break;
	case 3: cout << "Wednesday\n"; break;
	case 4: cout << "Thursday\n"; break;
	case 5: cout << "Friday\n"; break;
	case 6: cout << "Saturday\n"; break;
	}
}

void getInput(int& day, int& month, int& year) {
	char sep;
	cout << "$(dd/mm/yyyy):";
	cin >> day >> sep >> month >> sep >> year;
}
bool isLeapYear(int year) {
	/*This function should return true if year is a leap year and false if it is not. 
	Here is pseudocode to determine a leap year:
		
		leap_year = (year divisible by 400) or (year divisible by 4 and 
		year not divisible by 100))*/
	if (year % 400 == 0) return true;
	else if (year % 4 == 0 && year % 100 != 0) return true;
	else return false;
}
int getCenturyValue(int year) {
	/*	This function should take the first two digits of the year (that is, the century), 
	divide by 4, and save the remainder. Subtract the remainder from 3
	and return this value multiplied by 2. For example, the year 2008 becomes: 
		
		(20/4) = 5 with a remainder of 0. 3 − 0 = 3. Return 3 * 2 = 6.*/
	int century = year / 100,
		remainder = century % 4;
	return (3 - remainder) * 2;

}
int getYearValue(int year) {
	/*This function computes a value based on the years since the beginning of 
	the century. First, extract the last two digits of the year. For example, 08 is 
	extracted for 2008. Next, factor in leap years. Divide the value from the 
	previous step by 4 and discard the remainder. Add the two results together 
	and return this value. For example, from 2008 we extract 08. Then (8/4) = 2 
	with a remainder of 0. Return 2 + 8 = 10.*/
	int centYears = year % 100,
		leapFactor = centYears / 4;
	return centYears + leapFactor;
}
int getMonthValue(int month, int year) {
	/*This function should return a value based on the table below and will
	require invoking the isLeapYear function.

		Month		Return Value
		January			0 (6 if year is a leap year)
		February		3 (2 if year is a leap year)
		March			3
		April			6
		May				1
		June			4
		July			6
		August			2
		September		5
		October			0
		November		3
		December		5*/
	bool isLeap(isLeapYear(year));

	switch (month) {
	case 1: if (isLeap) return 6; break;
	case 10: return 0; break;
	case 2: if (isLeap) return 2; break;
	case 3:
	case 11: return 3; break;
	case 4: 
	case 7: return 6; break;
	case 5: return 1; break;
	case 6: return 4; break;
	case 8: return 2; break;
	case 9:
	case 12: return 5; break;
	}
}



void ch5ProgProject8() {
	/*Complete the previous Programming Project and create a top-level function 
	named dayOfWeek with the header:
		
		int dayOfWeek(int month, int day, int year);
 
	The function should encapsulate the necessary logic to return the day of 
	the week of the specified date as an int (Sunday = 0, Monday = 1, etc.) You 
	should add validation code to the function that tests if any of the inputs are 
	invalid. If so, the function should return –1 as the day of the week. In your 
	main function write a test driver that checks if dayOfWeek is returning the 
	correct values. Your set of test cases should include at least two cases with 
	invalid inputs.*/
	int day, month, year, weekday;

	getInput(day, month, year);
	weekday = dayOfWeek(day, month, year);
	if (weekday == -1) cout << "Invalid Date\n";
	else cout << weekday << endl;
}
int dayOfWeek(int day, int month, int year) {
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day > 31 || day <= 0) return -1;
		break;
	case 2:
		if (isLeapYear(year)) {
			if (day > 29 || day <= 0) return -1;
		}
		else {
			if (day > 28 || day <= 0) return -1;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day > 30 || day <= 0) return -1;
		break;
	default: return -1;
	}

	return (day + getCenturyValue(year) + getYearValue(year) + getMonthValue(month, year)) % 7;
}
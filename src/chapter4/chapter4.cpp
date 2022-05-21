//SOLVED
#include "chapter4.h"

void ch4Exercise1() {
	/* A liter is 0.264179 gallons. Write a program that will read in the number
	of liters of gasoline consumed by the user’s car and the number of miles
	traveled by the car and will then output the number of miles per gallon the
	car delivered. Your program should allow the user to repeat this calculation
	as often as the user wishes. Define a function to compute the number of
	miles per gallon. Your program should use a globally defined constant for
	the number of liters per gallon.*/
	double liters, miles;
	char repeat;

	do {
		cout << "$";
		cin >> liters >> miles;

		cout << "Miles per Galon: " << milesPerGalon(liters, miles) << endl;

		do {
			cout << "Repeat (y/n)? ";
			cin >> repeat;
		} while (!valid(repeat));

	} while (repeat != 'n' && repeat != 'N');
}

double milesPerGalon(double liters, double miles) {
	double gallon = liters * L_PER_GALLON;
	return miles / gallon;
}
bool valid(char check) {
	return check == 'y' || check == 'Y' || check == 'n' || check == 'N';
}



void ch4Exercise2() {
	/*Modify your program from Practice Program 1 so that it will take input
	data for two cars and output the number of miles per gallon delivered by
	each car. Your program will also announce which car has the best fuel ef-
	ficiency (highest number of miles per gallon*/
	double litersCar1, milesCar1, litersCar2, milesCar2;
	char repeat;

	do {
		cout << "$Car 1: ";
		cin >> litersCar1 >> milesCar1;
		cout << "$Car 2: ";
		cin >> litersCar2 >> milesCar2;

		double effCar1 = milesPerGalon(litersCar1, milesCar1),
			effCar2 = milesPerGalon(litersCar2, milesCar2);


		cout << "Miles per Galon" << endl
			<< "Car 1: " << effCar1 << endl
			<< "Car 2: " << effCar2 << endl;

		if (effCar1 > effCar2) cout << "Car 1 is more efficient\n";
		else if (effCar1 == effCar2) cout << "The cars are equally efficient\n";
		else cout << "Car 2 is more efficient\n";

		do {
			cout << "Repeat (y/n)? ";
			cin >> repeat;
		} while (!valid(repeat));


		cout << endl;

	} while (repeat != 'n' && repeat != 'N');
}



void ch4Exercise3() {
	/*The price of stocks is sometimes given to the nearest eighth of a dollar; for
	example, 297/8 or 891/2. Write a program that computes the value of the
	user’s holding of one stock. The program asks for the number of shares of
	stock owned, the whole-dollar portion of the price, and the fraction portion.
	The fraction portion is to be input as two int values, one for the numerator
	and one for the denominator. The program then outputs the value of the
	user’s holdings. Your program should allow the user to repeat this calculation
	as often as the user wishes and will include a function definition that has
	three int arguments consisting of the whole-dollar portion of the price and
	the two integers that make up the fraction part. The function returns the price
	of one share of stock as a single number of type double.*/
	double stockShares, stockValue;
	int pricePortion, priceNumerator, priceDenominator;

	while (true) {
		cout << "$";

		cin >> stockShares;
		if ((stockShares == -1)) break;
		cin >> pricePortion >> priceNumerator >> priceDenominator;

		stockValue = stockCalc(pricePortion, priceNumerator, priceDenominator);

		cout << "Your stock is worth " << stockValue << "$ each\n";
	}
}

double stockCalc(int price, int num, int denom) {
	return price + double(num) / denom;
}



void ch4Exercise4() {
	/*Write a program to gauge the rate of inflation for the past year. The program
	asks for the price of an item (such as a hot dog or a 1-carat diamond) both
	one year ago and today. It estimates the inflation rate as the difference
	in price divided by the year-ago price. Your program should allow the user
	to repeat this calculation as often as the user wishes. Define a function to
	compute the rate of inflation. The inflation rate should be a value of type
	double giving the rate as a percent, for example 5.3 for 5.3 percent.*/
	double oldPrice, newPrice, inflation;

	while (true) {
		cout << "$";
		cin >> oldPrice;
		if (oldPrice == -1) break;
		cin >> newPrice;
		inflation = infCalc(oldPrice, newPrice);
		cout << inflation << "% of inflation since last year\n";
	}
}

double infCalc(double priceOld, double priceNew) {
	return ((priceNew - priceOld) / priceOld) * 100;
}



void ch4Exercise5() {
	/*Enhance your program from the previous Practice Program by having it
	also print out the estimated price of the item in one and in two years
	from the time of the calculation. The increase in cost over one year is
	estimated as the inflation rate times the price at the start of the year.
	Define asecond function to determine the estimated cost of an item in one
	year, given the current price of the item and the inflation rate as arguments*/
	double oldPrice, newPrice, inflation, estimate;

	while (true) {
		cout << "$";
		cin >> oldPrice;
		if (oldPrice == -1) break;
		cin >> newPrice;
		inflation = infCalc(oldPrice, newPrice);
		cout << inflation << "% of inflation since last year\n";
		estimate = estimateCalc(newPrice, inflation);
		cout << "The product should cost " << estimate << "$ next year\n";
	}
}

double estimateCalc(double price, double inflation) {
	return price + price / inflation;
}



void ch4Exercise6() {
	/*Write a function declaration for a function that computes interest on a credit
	card account balance. The function takes arguments for the initial balance,
	the monthly interest rate, and the number of months for which interest must
	be paid. The value returned is the interest due. Do not forget to compound
	the interest—that is, to charge interest on the interest due. The interest due
	is added into the balance due, and the interest for the next month is computed
	using this larger balance. Use a while loop that is similar to (but need
	not be identical to) the one shown in Display 2.14. Embed the function in
	a program that reads the values for the interest rate, initial account balance,
	and number of months, then outputs the interest due. Embed your function
	definition in a program that lets the user compute interest due on a credit
	account balance. The program should allow the user to repeat the calculation
	until the user says he or she wants to end the program*/
	double initialBalance, monthlyInterest, interestDue;
	int months;

	while (true) {
		cout << "$";
		cin >> initialBalance;
		if (initialBalance == -1) break;
		cin >> monthlyInterest >> months;
		interestDue = interestCalc(initialBalance, monthlyInterest, months);
		cout << setprecision(4) << "You're due " << interestDue << "$ in interest\n";
	}
}

double interestCalc(double balance, double interest, int months) {
	for (int i = 1; i < months; i++) balance += balance / interest;
	return balance / interest;
}



void ch4Exercise7() {
	/*The gravitational attractive force between two bodies with masses m1 and m2
	separated by a distance d is given by:

				F = (Gm1m2)/d^2

	where G is the universal gravitational constant:

				G = 6.673 × 10^(-8) cm3/(g × sec^2)

	Write a function definition that takes arguments for the masses of two bodies
	and the distance between them and that returns the gravitational force.
	Since you will use the preceding formula, the gravitational force will be in
	dynes. One dyne equals

				(g × cm)/sec^2

	You should use a globally defined constant for the universal gravitational
	constant. Embed your function definition in a complete program that
	computes the gravitational force between two objects given suitable inputs.
	Your program should allow the user to repeat this calculation as often as
	the user wishes*/
	double m1, m2, d;

	while (true) {
		cout << "$";
		cin >> m1;
		if (m1 == -1) break;
		cin >> m2 >> d;
		double answer = gravitation(m1, m2, d);
		cout << "The gravitational force is " << answer << " dynes\n";
	}
}

double gravitation(double m1, double m2, double d) {
	return (UNI_GRAVIT * m1 * m2) / pow(d, 2);
}



void ch4Exercise8() {
	/*That we are “blessed” with several absolute value functions is an accident
	of history. C libraries were already available when C++ arrived; they could
	be easily used, so they were not rewritten using function overloading. You
	are to find all the absolute value functions you can and rewrite all of them
	overloading the abs function name. At a minimum, you should have the
	int, long, float, and double types represented*/
	int x;
	float y;
	double z;
	long w;

	cout << "$";
	cin >> x >> y >> z >> w;

	x = absRe(x);
	y = absRe(y);
	z = absRe(z);
	w = absRe(w);

	cout << x << "\t" << y << "\t" << z << "\t" << w << endl;
}

int absRe(int x) {
	if (x > 0) return x;
	else return -x;
}
double absRe(double x) {
	if (x > 0) return x;
	else return -x;
}
float absRe(float x) {
	if (x > 0) return x;
	else return -x;
}
long absRe(long x) {
	if (x > 0) return x;
	else return -x;
}




void ch4Exercise9() {
	/*Write an overloaded function max that takes either two or three parameters
	of type double and returns the largest of them*/
	double x, y, z;

	while (true) {
		cout << "$";
		cin >> x;
		if (x == -1) break;
		cin >> y >> z;

		cout << x << "vs" << y << ": " << max(x, y) << endl;
		cout << x << "vs" << z << ": " << max(x, z) << endl;
		cout << y << "vs" << z << ": " << max(y, z) << endl;
		cout << "largest of the bunch: " << max(x, y, z) << endl;
	}

}

double max(double x, double y) {
	if (x > y) return x;
	else return y;
}
double max(double x, double y, double z) {
	double maxVal = x;
	if (y > maxVal) maxVal = y;
	if (z > maxVal) maxVal = z;
	return maxVal;
}



void ch4ProgProject1() {
	/*Write a program that computes the annual after-tax cost of a new house for
	the first year of ownership. The cost is computed as the annual mortgage
	cost minus the tax savings. The input should be the price of the house
	and the down payment. The annual mortgage cost can be estimated as
	3 percent of the initial loan balance credited toward paying off the loan
	principal plus 6 percent of the initial loan balance in interest. The initial
	loan balance is the price minus the down payment. Assume a 35 percent
	marginal tax rate and assume that interest payments are tax deductible. So,
	the tax savings is 35 percent of the interest payment. Your program should
	use at least two function definitions and should allow the user to repeat
	this calculation as often as the user wishes*/
	double price, downPay;

	while (true) {
		cout << "$";
		cin >> price;
		if (price == -1) break;
		cin >> downPay;
		double atCost = afterTax(price, downPay);
		cout << "The annual after-tax cost of the house is " << atCost << "$\n";
	}
}

double afterTax(double housePrice, double downPayment) {
	double loanBalance = housePrice - downPayment;
	double intPayment = 0.06 * loanBalance;
	double annualMortgage = 0.03 * loanBalance + intPayment;
	return annualMortgage - taxSavings(intPayment);
}
double taxSavings(double interestPayment) {
	double taxRate = 0.35;
	return interestPayment * taxRate;
}


void ch4ProgProject2() {
	/*Write a program that asks for the user’s height, weight, and age, and then
	computes clothing sizes according to the formulas:
	■   Hat size = weight in pounds divided by height in inches and all that
	multiplied by 2.9.
	■ Jacket size (chest in inches) = height times weight divided by 288 and then
	adjusted by adding 1/8 of an inch for each 10 years over age 30. (Note
	that the adjustment only takes place after a full 10 years. So, there is no
	adjustment for ages 30 through 39, but 1/8 of an inch is added for age 40.)
	■ Waist in inches = weight divided by 5.7 and then adjusted by adding
	1/10 of an inch for each 2 years over age 28. (Note that the adjustment
	only takes place after a full 2 years. So, there is no adjustment for age 29,
	but 1/10 of an inch is added for age 30.)
	Use functions for each calculation. Your program should allow the user to
	repeat this calculation as often as the user wishes.*/
	double height, weight;
	int age;

	while (true) {
		cout << "$";
		cin >> height;
		if (height == -1) break;
		cin >> weight >> age;
		double hat = hatSize(weight, height);
		double jacket = jackSize(height, weight, age);
		double waist = waistSize(weight, age);
		cout << "Hat Size: " << hat << endl
			<< "Jacket Size: " << jacket << endl
			<< "Waist Size: " << waist << endl;
	}
}

double hatSize(double weight, double height) {
	return (weight / height) * 2.9;
}
double jackSize(double height, double weight, int age) {
	int increment;
	if (age > 30) increment = (age - 30) / 10;
	else increment = 0;
	cout << "increment: " << increment << endl;
	return (height * weight) / 288 + 0.125 * increment;
}
double waistSize(double weight, int age) {
	double increment;
	if (age > 28) increment = (age - 28) / 2;
	else increment = 0;
	return (weight / 5.7) + 0.1 * increment;
}



void ch4ProgProject3() {
	/*Modify your program from Programming Project 2 so that it also calculates
	the user’s jacket and waist sizes after 10 years.*/
	double height, weight;
	int age;

	while (true) {
		cout << "$";
		cin >> height;
		if (height == -1) break;
		cin >> weight >> age;
		double hat = hatSize(weight, height);
		double jacket = jackSize(height, weight, age + 10);
		double waist = waistSize(weight, age + 10);
		cout << "Hat Size: " << hat << endl
			<< "Jacket Size: " << jacket << endl
			<< "Waist Size: " << waist << endl;
	}

}



void ch4ProgProject4() {
	/*Write a program that outputs the lyrics for the song “Ninety-Nine Bottles
	of Beer on the Wall.” Your program should print the number of bottles in
	English, not as a number. For example:
		Ninety-nine bottles of beer on the wall,
		Ninety-nine bottles of beer,
		Take one down, pass it around,
		Ninety-eight bottles of beer on the wall.
			…
		One bottle of beer on the wall,
		One bottle of beer,
		Take one down, pass it around,
		Zero bottles of beer on the wall.
	Design your program with a function that takes as an argument an integer
	between 0 and 99 and returns a string that contains the integer value in
	English. Your function should not have 100 different if-else statements!
	Instead, use % and / to extract the tens and ones digits to construct the English
	string. You may need to test specifically for values such as 0, 10–19, etc.*/
	int tens, unit;
	string numBottles;


	for (int i = 99; i > 0; i--) {
		if (i >= 10 && i <= 19) numBottles = teens(i);
		else {
			tens = i / 10;
			unit = i % 10;
			if (unit == 0) numBottles = tenths(tens);
			else if (tens == 0) numBottles = units(unit);
			else numBottles = tenths(tens) + "-" + units(unit);
		}
		if (i == 1) {
			cout << numBottles << " bottle of beer on the wall,\n"
				<< numBottles << " bottle of beer,\n"
				<< "Take one down, pass it around\n"
				<< units(unit - 1) << " bottes of beer on the wall.\n\n";
		}
		else {
			cout << numBottles << " bottles of beer on the wall,\n"
				<< numBottles << " bottles of beer,\n"
				<< "Take one down, pass it around\n";
		}
	}
}

string teens(int i) {
	if (i == 19) return "Nineteen";
	else if (i == 18) return "Eighteen";
	else if (i == 17) return "Seventeen";
	else if (i == 16) return "Sixteen";
	else if (i == 15) return "Fifteen";
	else if (i == 14) return "Fourteen";
	else if (i == 13) return "Thirteen";
	else if (i == 12) return "Twelve";
	else if (i == 11) return "Eleven";
	else if (i == 10) return "Ten";
}
string units(int i) {
	if (i == 9) return "Nine";
	else if (i == 8) return "Eigh";
	else if (i == 7) return "Seven";
	else if (i == 6) return "Six";
	else if (i == 5) return "Five";
	else if (i == 4) return "Four";
	else if (i == 3) return "Three";
	else if (i == 2) return "Two";
	else if (i == 1) return "One";
	else if (i == 0) return "Zero";
}
string tenths(int i) {
	if (i == 9) return "Ninety";
	else if (i == 8) return "Eighty";
	else if (i == 7) return "Seventy";
	else if (i == 6) return "Sixty";
	else if (i == 5) return "Fifty";
	else if (i == 4) return "Fourty";
	else if (i == 3) return "Thirty";
	else if (i == 2) return "Twenty";
}


void ch4ProgProject5() {
	/*To maintain one’s body weight, an adult human needs to consume enough
	calories daily to (1) meet the basal metabolic rate (energy required to
	breathe, maintain body temperature, etc.), (2) account for physical activity
	such as exercise, and (3) account for the energy required to digest the food
	that is being eaten. For an adult that weighs P pounds, we can estimate
	these caloric requirements using the following formulas:

		A. Basal metabolic rate: Calories required = 70 * (P / 2.2)^0.756

		B. Physical activity: Calories required = 0.0385 * Intensity * P * Minutes

	Here, Minutes is the number of minutes spent during the physical activity,
	and Intensity is a number that estimates the intensity of the activity. Here
	are some sample numbers for the range of values:

					Activity		Intensity
					Running 10 mph:		17
					Running 6 mph:		10
					Basketball:			 8
					Walking 1 mph:		 1

		C. Energy to digest food: calories required = TotalCaloriesConsumed * 0.1

	In other words, 10 percent of the calories we consume goes towards digestion.
	Write a function that computes the calories required for the basal metabolic
	rate, taking as input a parameter for the person’s weight. Write another
	function that computes the calories required for physical activity, taking as
	input parameters for the intensity, weight, and minutes spent exercising.
	Use these functions in a program that inputs a person’s weight, an estimate
	for the intensity of physical activity, the number of minutes spent performing
	the physical activity, and the number of calories in one serving of your
	favorite food. The program should then calculate and output how many
	servings of that food should be eaten per day to maintain the person’s current
	weight at the specified activity level. The computation should include the
	energy that is required to digest food.
	You can find estimates of the caloric content of many foods on the Web.
	For example, a double cheeseburger has approximately 1000 calories*/
	double weight, calories, servings;
	int intensity, minutes;

	cout << "$";

	cin >> calories >> weight >> intensity >> minutes;

	weight = toPounds(weight);
	servings = (basalMetabolicRate(weight) + physicalActivityCal(intensity, weight, minutes) + calories * 0.1) / calories;

	cout << "You can have " << servings << " of your favorite food per day \n";
}

double basalMetabolicRate(double weight) {
	return 70 * pow(weight / 2.2, 0.756);
}
double physicalActivityCal(int intensity, double weight, int minutes) {
	return 0.0385 * intensity * weight * minutes;
}
double toPounds(double kg) {
	return kg * KG_TO_POUNDS;
}



void ch4ProgProject6() {
	/*You have invented a vending machine capable of deep frying twinkies.
	Write a program to simulate the vending machine. It costs $3.50 to buy a
	deep-fried twinkie, and the machine only takes coins in denominations of
	a dollar, quarter, dime, or nickel. Write code to simulate a person putting
	money into the vending machine by repeatedly prompting the user for the
	next coin to be inserted. Output the total entered so far when each coin is
	inserted. When $3.50 or more is added, the program should output “Enjoy
	your deep-fried twinkie” along with any change that should be returned.
	Use top-down design to determine appropriate functions for the program.*/
	double total = 0;
	char coin;
	cout << "Enter your coin: \n"
		<< "- D for dollar,\n"
		<< "- q for quarter,\n"
		<< "- d for dime,\n"
		<< "- n for nickel.\n\n";

	while (total < 3.50) {

		cout << "$";
		cin >> coin;

		total += insert_coin(coin);

		cout << "\tTotal: " << total << endl;
	}

	cout << "\nHeres your change:\n"
		<< give_change(total) << "$" << endl
		<< "\nEnjoy your deep fried twinkie!\n";
}

bool valid_coin(char ch) {
	return ch == 'D' || ch == 'q' || ch == 'd' || ch == 'n';
}
double insert_coin(char ch) {
	if (valid_coin(ch)) {
		switch (ch) {
		case 'D': return 1;
		case 'q': return 0.25;
		case 'd': return 0.10;
		case 'n': return 0.05;
		}
	}
	else return 0;

}
double give_change(double total) {
	return total - 3.5;
}



void ch4ProgProject7() {
	/*Your time machine is capable of going forward in time up to 24 hours.
	The machine is configured to jump ahead in minutes. To enter the proper
	number of minutes into your machine, you would like a program that can
	take a start time (in hours, minutes, and a Boolean indicating AM or PM)
	and a future time (in hours, minutes, and a Boolean indicating AM or PM)
	and calculate the difference in minutes between the start and future time.
	A time is specified in your program with three variables:

		int hours, minutes;
		bool isAM;

	For example, to represent 11:50 PM, you would store:

		hours = 11
		minutes = 50
		isAM = false;

	This means that you need six variables to store a start and future time.
	Write a program that allows the user to enter a start time and a future time.
	Include a function named computeDifference that takes the six variables
	as	parameters that represent the start time and future time. Your function
	should return, as an int, the time difference in minutes. For example, given
	a start time of 11:59 AM and a future time of 12:01 PM, your program
	should compute 2 minutes as the time difference. Given a start time of
	11:59 AM and a future time of 11:58 AM, your program should compute
	1439 minutes as the time difference (23 hours and 59 minutes).
	You may need “AM” or “PM” from the user’s input by reading in two
	character values. (Display 2.3 illustrates character input.) Characters can
	be compared just like numbers. For example, if the variable a_char is of
	type char, then (a_char == 'A') is a Boolean expression that evaluates to
	true if a_char contains the letter A.*/
	int hour1, min1,
		hour2, min2;
	char AM;
	bool isAM1, isAM2;

	cout << "Enter two times(hours, mins, A/P):\n";

	do {
		cout << "$";
		cin >> hour1 >> min1;
	} while (cin.fail());
	do {
		cin >> AM;
	} while (!valid_AM(AM));
	if (AM == 'A') isAM1 = true;
	else isAM1 = false;

	do {
		cout << "$";
		cin >> hour2 >> min2;
	} while (cin.fail());
	do {
		cin >> AM;
	} while (!valid_AM(AM));
	if (AM == 'A') isAM2 = true;
	else isAM2 = false;

	cout << "The time difference is " << compute_difference(hour1, min1, isAM1, hour2, min2, isAM2)
		<< " minutes.\n";
}

bool valid_AM(char ch) {
	return ch == 'A' || ch == 'P';
}
int compute_difference(int hour1, int min1, bool isAM1, int hour2, int min2, bool isAM2) {
	min1 += hour1 * 60;
	min2 += hour2 * 60;
	if (isAM1 && isAM2) return min2 - min1 + 24 * 60;
	else return min2 - min1;
}



void ch4ProgProject8() {}



void ch4ProgProject9() {
	/*Your sports league uses the following lottery system to select draft picks for
	the four worst teams in the league:

		■ The last place team gets 20 balls in an urn.
		■ The second-to-last place team gets 10 balls in the urn.
		■ The third-to-last place team gets 6 balls in the urn
		■ The fourth-to-last place team gets 4 balls in the urn.

	To determine the first pick in the draft a ball is selected at random. The team
	owning that ball gets the first pick. The ball is then put back in the urn.
	To determine the second pick in the draft a ball is selected at random. If the
	ball belongs to the team that got the first pick then it is put back in and the
	process repeats until a ball is selected that does not belong to the first pick.
	To determine subsequent picks in the draft the process repeats until a ball
	is selected that belongs to a team that has not already been chosen.
	Write a function that takes as input which of the four teams have already
	been granted picks, simulates selecting a ball from the urn according to the
	lottery rules, and returns the team that belongs to the selected ball. You get
	to choose how to design your function to perform these actions. Write a
	main function that outputs the draft order (e.g., a possible order is: second-
	to-last picks 1, last place picks 2, third-to-last picks 3, and fourth-to-last
	picks 4). If you change the random seed then the order should differ if you
	run the program multiple times.
	For a slightly harder version of the problem, allow the user to input the
	names of the four teams. The program should then output the team names
	in the draft order.*/
	time_t now;
	time(&now);
	srand(now);

	bool last = 0, secondLast = 0,
		thirdLast = 0, fourthLast = 0;
	int i = 0;

	string lastTeam, secondTeam,
		thirdTeam, fourthTeam;

	cout << "Enter team names in ascending order:\n";

	cout << "$";
	getline(cin, lastTeam);
	cout << "$";
	getline(cin, secondTeam);
	cout << "$";
	getline(cin, thirdTeam);
	cout << "$";
	getline(cin, fourthTeam);



	while (i < 4) {
		int n = rand() % 40;
		if (n == 1 && !last) {
			last = 1;
			cout << lastTeam << endl;;
			i++; 
		}
		else if (n == 2 && !secondLast) {
			secondLast = 1;
			cout << secondTeam << endl;
			i++;
		}
		else if (n == 3 && !thirdLast) {
			thirdLast = 1;
			cout << thirdTeam << endl;
			i++;
		}
		else if (n == 4 && !fourthLast) {
			fourthLast = 1;
			cout << fourthTeam << endl;
			i++;
		}
	}

	cout << "\nThere's your draft. Good luck!\n";

}
int define_teams(int n) {
	if (n <= 20) return 1;
	else if (n <= 30) return 2;
	else if (n <= 36) return 3;
	else if (n <= 40) return 4;
}
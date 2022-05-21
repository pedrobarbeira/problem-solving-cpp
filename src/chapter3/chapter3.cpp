//SOLVED
#define _USE_MATH_DEFINES
#include "chapter3.h"

void ch3Exercise1() {
	/*Write a program to score the paper-rock-scissor game. Each of two users 
	types in either P, R, or S. The program then announces the winner as well 
	as the basis for determining the winner: Paper covers rock, Rock breaks 
	scissors, Scissors cut paper, or Nobody wins. Be sure to allow the users 
	to use lowercase as well as uppercase letters. Your program should include 
	a loop that lets the user play again until the user says she or he is done.*/
	char p1, p2;
	int scoreP1 = 0, scoreP2 = 0;
	char rst;

	do {
		cout << "\nP1: " << scoreP1 << "\tP2: " << scoreP2 << endl;
		cout << "Player 1 (R/P/S): ";
		cin >> p1;
		while (p1 != 'P' && p1 != 'R' && p1 != 'S') {
			cin.ignore();
			cout << "Player 1 (R/P/S): ";
			cin >> p1;
		}

		cout << "Player 2 (R/P/S): ";
		cin >> p2;
		while (p2 != 'P' && p2 != 'R' && p2 != 'S') {
			cin.ignore();
			cout << "Player 1 (R/P/S): ";
			cin >> p2;
		}

		switch (p1) {
		case 'r':
		case 'R':
			switch (p2) {
			case 'r':
			case 'R': cout << "Nobody wins\n";
				break;
			case 'p':
			case 'P': cout << "Player 2 wins: Paper covers Rock\n";
				scoreP2++;
				break;
			case 's':
			case 'S': cout << "Player 1 wins: Rock breaks Scissors\n";
				scoreP1++;
				break;
			}
			break;
		case 'p':
		case 'P':
			switch (p2) {
			case 'r':
			case 'R': cout << "Player 1 wins: Paper covers Rock\n";
				scoreP1++;
				break;
			case 'p':
			case 'P': cout << "Nobody wins\n";
				break;
			case 's':
			case 'S': cout << "Player 2 wins: Scissors cuts Paper\n";
				scoreP2++;
				break;
			}
			break;
		case 's':
		case 'S':
			switch (p2) {
			case 'r':
			case 'R': cout << "Player 2 wins: Rock breaks Scissors\n";
				scoreP2++;
				break;
			case 'p':
			case 'P': cout << "Player 1 wins: Scissors cut paper\n";
				scoreP1++;
				break;
			case 's':
			case 'S': cout << "Nobody wins\n";
				break;
			}
		}

		cout << "Play again (y/n)? ";
		cin >> rst;
		while (rst != 'y' && rst != 'Y' && rst != 'n' && rst != 'N') {
			cin.ignore();
			cout << "Play again (y/n)? ";
			cin >> rst;
		}
	} while (rst != 'n' && rst != 'N');

	if (scoreP1 > scoreP2) cout << "Game Over! Player 1 wins!\n";
	else if (scoreP1 < scoreP2) cout << "Game Over! Playe 2 wins!\n";
	else cout << "Game Over! Nobody wins!\n";

	char re;

	cout << "Rematch(y/n)? ";
	cin >> re;
	while (re != 'y' && re != 'Y' && re != 'n' && re != 'N') {
		cin.ignore();
		cout << "Rematch(y/n)? ";
		cin >> re;
	}

	if (re == 'y' || re == 'Y') ch3Exercise1();
	else return;
}



void ch3Exercise2() {
	/*Write a program to compute the interest due, total amount due, and the 
	minimum payment for a revolving credit account. The program accepts the 
	account balance as input, then adds on the interest to get the total amount 
	due. The rate schedules are the following: The interest is 1.5 percent on the 
	first $1,000 and 1 percent on any amount over that. The minimum payment is 
	the total amount due if that is $10 or less; otherwise, it is $10 or 
	10 percent of the total amount owed, whichever is larger. Your program 
	should include a loop that lets the user repeat this calculation until the user 
	says she or he is done.*/
	double interestRate = 1.5,
		interestDue,
		totalDue,
		minPayment;

	do {
		cout << "$";
		cin >> totalDue;

		interestDue = totalDue;

		while (interestDue > 1000) {
			interestDue -= 1000;
			interestRate++;
		}

		interestDue = totalDue * (interestRate / 100);
		totalDue += interestDue;

		if (totalDue <= 10) minPayment = totalDue;
		else if (totalDue * 0.1 < 10) minPayment = 10;
		else minPayment = totalDue * 0.1;

		cout << "Total: " << totalDue << "$" << endl
			<< "Interest: " << interestDue << "$" << endl
			<< "Minimum Payment: " << minPayment << "$" << endl
			<< endl;

	} while (totalDue > 0);
}



void ch3Exercise3() {
	/*Write an astrology program. The user types in a birthday, and the program
	responds with the sign and horoscope for that birthday. The month may
	be entered as a number from 1 to 12. Then enhance your program so
	that if the birthday is only one or two days away from an adjacent sign,
	the program announces that the birthday is on a “cusp” and also outputs
	the horoscope for that nearest adjacent sign. This program will have a
	long multiway branch. Make up a horoscope for each sign. Your program
	should include a loop that lets the user repeat this calculation until the user
	says she or he is done.

	The horoscope signs and dates are:

		Aries			March 21–April 19
		Taurus			April 20–May 20
		Gemini			May 21–June 21
		Cancer			June 22–July 22
		Leo				July 23–August 22
		Virgo			August 23–September 22
		Libra			September 23–October 22
		Scorpio			October 23–November 21
		Sagittarius		November 22–December 21
		Capricorn		December 22–January 19
		Aquarius		January 20–February 18
		Pisces			February 19–March 20*/
	int day, month;
	bool cusp;

	while(true){
		cout << "$";
		cin >> day;
		if (day == -1) break;
		cin.get();
		cin >> month;

		switch (month) {
		case 1:
			if (day < 20) {
				if (day >= 18) cout << "Capricorn cusp Aquarius\n";
				else cout << "Capricorn\n";
				cout << "You'll be a good chill with Taurus and Virgo\n";
			}
			else if (day < 31) {
				if (day <= 22) cout << "Aquarius cusp Capricorn\n";
				else cout << "Aquarius\n";
				cout << "You'll be a good chill with Gemini and Libra\n";
			}
			else cout << "Invalid day";
			break;
		case 2:
			if (day < 19) {
				if (day >= 17) cout << "Aquarius cusp Pisces\n";
				else cout << "Aquarius\n";
				cout << "You'll be a good chill with Gemini and Libra\n";
			}
			else if (day < 29) {
				if (day <= 21) cout << "Pisces cusp Aquarius\n";
				else cout << "Pisces\n";
				cout << "You'll be a good chill with Cancer and Scorpio\n";
			}
			else cout << "Invalid day\n";
			break;
		case 3:
			if (day < 20) {
				if (day >= 18) cout << "Pises cusp Aries\n";
				else cout << "Pisces\n";
				cout << "You'll be a good chill with Cancer and Scorpio\n";
			}
			else if (day < 31) {
				if (day <= 22) cout << "Aries cusp Pisces\n";
				else cout << "Aries";
				cout << "You'll be a good chill with Leo and Sagittarius\n";
			}
			else cout << "Invalid day\n";
			break;
		case 4:
			if (day < 20) {
				if (day >= 18) cout << "Aries cusp Taurus\n";
				else cout << "Aries\n";
				cout << "You'll be a good chill with Leo and Sagittarius\n";
			}
			else if (day < 30) {
				if (day <= 22) cout << "Taurus cusp Aries\n";
				else cout << "Taurus\n";
				cout << "You'll be a good chill with Virgo and Capricorn\n";
			}
			else cout << "Invalid day\n";
			break;
		case 5:
			if (day < 21) {
				if (day >= 19) cout << "Taurus cusp Gemini\n";
				else cout << "Taurus\n";
				cout << "You'll be a good chill with Virgo and Capricorn\n";
			}
			else if (day < 31) {
				if (day <= 21) cout << "Gemini cusp Taurus\n";
				else cout << "Gemini\n";
				cout << "You'll be a good chill with Libra and Aquarius\n";
			}
			else cout << "Invalid day\n";
			break;
		case 6:
			if (day < 21) {
				if (day >= 19) cout << "Gemini cusp Cancer\n";
				else cout << "Gemini\n";
				cout << "You'll be a good chill with Libra and Aquarius\n";
			}
			else if (day < 30) {
				if (day <= 23) cout << "Cancer cusp Gemini\n";
				else cout << "Cancer\n";
				cout << "You'll be a good chill with Scorpio and Pisces\n";
			}
			else cout << "Invalid day\n";
			break;
		case 7:
			if (day < 22) {
				if (day >= 22) cout << "Cancer cusp Leo\n";
				else cout << "Cancer\n";
				cout << "You'll be a good chill with Scorpio and Pisces\n";
			}
			else if (day < 31) {
				if (day <= 24) cout << "Leo cusp Cancer\n";
				else cout << "Leo\n";
				cout << "You'll be a good chill with Aries and Sagittarius\n";
			}
			else cout << "Invalid day\n";
			break;
		case 8:
			if (day < 22) {
				if (day >= 20) cout << "Leo cusp Virgo\n";
				else cout << "Leo\n";
				cout << "You'll be a good chill with Aries and Sagittarius\n";
			}
			else if (day < 31) {
				if (day <= 24) cout << "Virgo cusp Leo\n";
				else cout << "Virgo\n";
				cout << "You'll be a good chill with Taurus and Capricorn\n";
			}
			else cout << "Invalid day\n";
			break;
		case 9:
			if (day < 22) {
				if (day >= 20) cout << "Virgo cusp Libra\n";
				else cout << "Virgo\n";
				cout << "You'll be a good chill with Taurus and Capricorn\n";
			}
			else if (day < 30) {
				if (day <= 24) cout << "Libra cusp Virgo\n";
				else cout << "Libra\n";
				cout << "You'll be a good chill with Gemini and Aquarius\n";
			}
			else cout << "Invalid day\n";
			break;
		case 10:
			if (day < 22) {
				if (day >= 20) cout << "Libra cusp Scorpio\n";
				else cout << "Libra\n";
				cout << "You'll be a good chill with Gemini and Aquarius\n";
			}
			else if (day < 31) {
				if (day <= 24) cout << "Scorpio cusp Libra\n";
				else cout << "Scorpio\n";
				cout << "You'll be a good chill with Cancer and Pisces\n";
			}
			else cout << "Invalid day\n";
			break;
		case 11:
			if (day < 21) {
				if (day >= 19) cout << "Scorpio cusp Sagittarius\n";
				else cout << "Scorpio\n";
				cout << "You'll be a good chill with Cancer and Pisces\n";
			}
			else if (day < 30) {
				if (day <= 23) cout << "Sagittarius cusp Scorpio\n";
				else cout << "Sagittarius\n";
				cout << "You'll be a good chill with Aries and Leo\n";
			}
			else cout << "Invalid day\n";
			break;
		case 12:
			if (day < 20) {
				if (day >= 18) cout << "Sagittarius cusp Capricon\n";
				else cout << "Sagitarius\n";
				cout << "You'll be a good chill with Aries and Leo\n";
			}
			else if (day < 31) {
				if (day <= 22) cout << "Capricorn cusp Sagittarius\n";
				else cout << "Capricorn\n";
				cout << "You'll be a good chill with Taurus and Virgo\n";
			}
			else cout << "Invalid day\n";
			break;
		}
	}
}



void ch3Exercise4() {
	/*Horoscope Signs of the same Element are most compatible. There are 4
	Elements in astrology, and 3 Signs in each: FIRE (Aries, Leo, Sagittarius),
	EARTH (Taurus, Virgo, Capricorn), AIR (Gemini, Libra, Aquarius) , WATER
	(Cancer, Scorpio, Pisces).
	According to some astrologers, you are most comfortable with your own sign
	and the other two signs in your Element. For example, Aries would be most
	comfortable with other Aries and the two other FIRE signs, Leo and Sagittarius.
	Modify your program from Practice Program 3 to also display the name of
	the signs that will be compatible for the birthday.*/
}



void ch3Exercise5() {
	/*Write a program that finds and prints all of the prime numbers between 3
	and 100. A prime number is a number such that 1 and itself are the only
	numbers that evenly divide it (for example, 3, 5, 7, 11, 13, 17, …).*/
	bool isPrime;
	int prime = 0;
	for (int n = 2; n <= 100; n++) {
		isPrime = true;
		for (int i = 2; i <= sqrt(n); i++)
			if (n % i == 0) isPrime = false;
		if (isPrime) {
			cout << n << " ";
			prime++;
		}
	}
	cout << endl;
}



void ch3Exercise6() {
	/*Buoyancy is the ability of an object to float. Archimedes’ principle states 
	that the buoyant force is equal to the weight of the fluid that is displaced 
	by the submerged object. The buoyant force can be computed by
		
		Fb = V × y
	
	where Fb is the buoyant force, V is the volume of the submerged object, 
	and y is the specific weight of the fluid. If Fb is greater than or equal 
	to the weight of the object, then it will float, otherwise it will sink.
	
	Write a program that inputs the weight (in pounds) and radius (in feet) 
	of a sphere and outputs whether the sphere will sink or float in water. Use 
		
		y = 62.4 lb/ft3 
	
	as the specific weight of water. The volume of a sphere is computed by 
		
		(4/3)πr3*/
	double weight, radius,
		fb, volume,
		y = 62.4;
	
	do {
		cout << "$";		
		cin >> weight >> radius;
		
		volume = 4.0 / 3 * M_PI * pow(radius, 3);
		fb = volume * y;

		if (fb >= weight) cout << "The sphere will float\n";
		else cout << "The sphere won't float\n";

		cout << "Repeat(y/n): ";
	} while (getchar() != 'n' && getchar() != 'N');
}



void ch3Exercise7() {
	/*Write a program that finds the temperature that is the same in both Celsius 
	and Fahrenheit. The formula to convert from Celsius to Fahrenheit is
		
		Fahrenheit = (9 × Celsius)/5 + 32
	
	Your program should create two integer variables for the temperature in 
	Celsius and Fahrenheit. Initialize the temperature to 100 degrees Celsius. 
	In a loop, decrement the Celsius value and compute the corresponding 
	temperature in Fahrenheit until the two values are the same.
	Since you are working with integer values, the formula may not give an 
	exact result for every possible Celsius temperature. This will not affect 
	your solution to this particular problem.*/
	int celsius = 100, fahrenheit;

	fahrenheit = (9 * celsius) / 5 + 32;

	while (celsius != fahrenheit) {
		celsius--;
		fahrenheit = (9 * celsius) / 5 + 32;
	}

	cout << celsius << "oC = " << fahrenheit << "oF\n";
}



void ch3ProgProject1() {
	/*Write a program that computes the cost of a long-distance call. The cost of 
	the call is determined according to the following rate schedule:
	
		a. Any call started between 8:00 am and 6:00 pm, Monday through Friday, 
		is billed at a rate of $0.40 per minute.
		
		b. Any call starting before 8:00 am or after 6:00 pm, Monday through 
		Friday, is charged at a rate of $0.25 per minute.
 
		c. Any call started on a Saturday or Sunday is charged at a rate of $0.15 per 
		minute.
	
	The input will consist of the day of the week, the time the call started, and 
	the length of the call in minutes. The output will be the cost of the call. The 
	time is to be input in 24-hour notation, so the time 1:30 pm is input as
		
		13:30
	
	The day of the week will be read as one of the following pairs of character 
	values, which are stored in two variables of type char:
		
		Mo Tu We Th Fr Sa Su
	
	Be sure to allow the user to use either uppercase or lowercase letters or a 
	combination of the two. The number of minutes will be input as a value 
	of type int. (You can assume that the user rounds the input to a whole 
	number of minutes.) Your program should include a loop that lets the user 
	repeat this calculation until the user says she or he is done*/
	int length, hours, minutes;
	char day1, day2, sep;
	bool weekend = false;
	double bizPrice = 0.4,
		primePrice = 0.25,
		wkndPrice = 0.15,
		totalPrice = 0;


	cout << "$";
	cin >> day1 >> day2 >> hours >> sep >> minutes >> length;


	day1 = tolower(day1);
	day2 = tolower(day2);

	if (day1 == 'm' && day2 != 'o') {
		cout << "Invalid day!\n";
		exit(1);
	}
	if (day1 == 't' && (day2 != 'u' || day2!= 'h')) {
		cout << "Invalid day!\n";
		exit(1);
	}
	if (day1 == 'w' && day2 != 'e') {
		cout << "Invalid day!\n";
		exit(1);
	}
	if (day1 == 'f' && day2 != 'r') {
		cout << "Invalid day!\n";
		exit(1);
	}
	if (day1 == 's' && (day2 != 'a' || day2 != 'u')) {
		cout << "Invalid day!\n";
		exit(1);
	}
	if (hours < 0 || hours > 24) {
		cout << "Invalid time!\n";
		exit(1);
	}
	if (length < 0) {
		cout << "Invalid call length!\n";
		exit(1);
	}
	

	if (day1 == 's') totalPrice = length * wkndPrice;
	else if (hours < 8 || hours > 17) totalPrice = length * primePrice;
	else totalPrice = length * bizPrice;

	cout << "Call price: " << totalPrice << "$" << endl;

}



void ch3ProgProject2() {
	/*(This Project requires that you know some basic facts about complex numbers, 
	so it is only appropriate if you have studied complex numbers in some mathematics class.)
	Write a C++ program that solves a quadratic equation to find its roots. The 
	roots of a quadratic equation
		
		ax^2 + bx + c = 0
	
	(where a is not zero) are given by the formula
		
		(–b ± sqrt(b^2 – 4ac)) / 2a

	The value of the discriminant (b^2 – 4ac) determines the nature of roots. 
	If the value of the discriminant is zero, then the equation has a single real 
	root. If the value of the discriminant is positive then the equation has two 
	real roots. If the value of the discriminant is negative, then the equation 
	has two complex roots.
	The program takes values of a, b, and c as input and outputs the roots. Be 
	creative in how you output complex roots. Include a loop that allows the 
	user to repeat this calculation for new input values until the user says she 
	or he wants to end the program*/
	double a, b, c,
		disc, root1, root2;

	cout << "$";
	cin >> a >> b >> c;

	disc = pow(b, 2) - 4 * a * c;

	if (disc > 0) {
		root1 = (-b + sqrt(disc)) / 2 * a;
		root2 = (-b - sqrt(disc)) / 2 * a;
		cout << "The equation has 2 real roots: " << root1 << " and " << root2 << endl;
	}
	else if (disc == 0){
		root1 = -b / 2 * a;
		cout << "The equation has 1 real root: " << root1 << endl;
	}
	else {
		root1 = sqrt(-disc) / 2 * a;
		root2 = -b / 2 * a;
		cout << "The equation has 2 imaginary roots: "
			<< root2 << "+" << root1 << "i" << " and "
			<< root2 << "-" << root1 << "i" << endl;
	}
}



void ch3ProgProject3() {
	/*Write a program that accepts a year written as a four-digit Arabic (ordinary) 
	numeral and outputs the year written in Roman numerals. Important 
	Roman numerals are V for 5, X for 10, L for 50, C for 100, D for 500, and M 
	for 1,000. Recall that some numbers are formed by using a kind of subtraction 
	of one Roman “digit”; for example, IV is 4 produced as V minus I, XL 
	is 40, CM is 900, and so on. A few sample years: MCM is 1900, MCML is 
	1950, MCMLX is 1960, MCMXL is 1940, MCMLXXXIX is 1989. Assume the 
	year is between 1000 and 3000. Your program should include a loop that 
	lets the user repeat this calculation until the user says she or he is done.*/
	string roman = "";
	int num = 0;
	int check = 0;

	cout << "$";
	cin >> num;

	check = num / 1000;
	for (int i = 0; i < check; i++)
		roman += "M";
	num %= 1000;

	check = num / 100;
	if (check == 9)
		roman += "CM";
	else {
		if (check >= 5)
			roman += "D";
		check %= 5;
		if (check == 4)
			roman += "CD";
		else for (int i = 0; i < check; i++)
			roman += "C";
	}

	num %= 100;

	check = num / 10;
	if (check == 9)
		roman += "XC";
	else {
		if (check >= 5)
			roman += "L";
		check %= 5;
		if (check == 4)
			roman += "XL";
		else for (int i = 0; i < check; i++)
			roman += "X";
	}

	num %= 10;
	if (num == 9)
		roman += "IX";
	else {
		if (num >= 5)
			roman += "V";
		num %= 5;
		if (num == 4)
			roman += "IV";
		else for (int i = 0; i < num; i++)
			roman += "I";
	}
	
	cout << roman << endl;
}



void ch3ProgProject4() {
	/* Write a program that scores a blackjack hand. In blackjack, a player receives 
	from two to five cards. The cards 2 through 10 are scored as 2 through 
	10 points each. The face cards—jack, queen, and king—are scored as 10 
	points. The goal is to come as close to a score of 21 as possible without 
	going over 21. Hence, any score over 21 is called “busted.” The ace can 
	count as either 1 or 11, whichever is better for the user. For example, an 
	ace and a 10 can be scored as either 11 or 21. Since 21 is a better score, this 
	hand is scored as 21. An ace and two 8s can be scored as either 17 or 27. 
	Since 27 is a “busted” score, this hand is scored as 17.
 
	The user is asked how many cards she or he has, and the user responds with 
	one of the integers 2, 3, 4, or 5. The user is then asked for the card values. Card 
	values are 2 through 10, jack, queen, king, and ace. A good way to handle 
	input is to use the type char so that the card input 2, for example, is read as the 
	character '2', rather than as the number 2. Input the values 2 through 9 as the 
	characters '2' through '9'. Input the values 10, jack, queen, king, and ace as 
	the characters 't', 'j', 'q', 'k', and 'a'. (Of course, the user does not type in 
	the single quotes.) Be sure to allow upper- as well as lowercase letters as input.
	
	After reading in the values, the program should convert them from character 
	values to numeric card scores, taking special care for aces. The output is 
	either a number between 2 and 21 (inclusive) or the word Busted. You are 
	likely to have one or more long multiway branches that use a switch statement 
	or nested if-else statement. Your program should include a loop that 
	lets the user repeat this calculation until the user says she or he is done*/
	short hand = 0;
	int score = 0;
	char card;
	cout << "How many cards do you have: ";
	cin >> hand;

	do {
		cin >> card;
		card = toupper(card);
		switch (card) {
		case '2': score += 2; hand--; break;
		case '3': score += 3; hand--; break;
		case '4': score += 4; hand--; break;
		case '5': score += 5; hand--; break;
		case '6': score += 6; hand--; break;
		case '7': score += 7; hand--; break;
		case '8': score += 8; hand--; break;
		case '9': score += 9; hand--; break;
		case  'T': score += 10; hand--; break;
		case 'J': score += 10; hand--; break;
		case 'Q': score += 10; hand--; break;
		case 'K': score += 10; hand--; break;
		case 'A': if (score + 11 > 21) score += 1;
				else score += 11; 
			hand--; break;
		default: cout << "That's not a valid card\n";
			break;
		}
	} while (hand > 0);

	if (score > 21) cout << "Busted\n";
	else cout << "Score: " << score << endl; 
	
}



void ch3ProgProject5() {
	/*Interest on a loan is paid on a declining balance, and hence a loan with an 
	interest rate of, say, 14 percent can cost significantly less than 14 percent 
	of the balance. Write a program that takes a loan amount and interest rate 
	as input and then outputs the monthly payments and balance of the loan 
	until the loan is paid off. Assume that the monthly payments are one-twentieth 
	of the original loan amount, and that any amount in excess of 
	the interest is credited toward decreasing the balance due. Thus, on a loan 
	of $20,000, the payments would be $1,000 a month. If the interest rate is 
	10 percent, then each month the interest is one-twelfth of 10 percent of 
	the remaining balance. The first month, (10 percent of $20,000)/12, or 
	$166.67, would be paid in interest, and the remaining $833.33 would decrease 
	the balance to $19,166.67. The following month the interest would 
	be (10 percent of $19,166.67)/12, and so forth. Also have the program 
	output the total interest paid over the life of the loan.
 
	Finally, determine what simple annualized percentage of the original loan 
	balance was paid in interest. For example, if $1,000 was paid in interest on 
	a $10,000 loan and it took 2 years to pay off, then the annualized interest 
	is $500, which is 5 percent of the $10,000 loan amount. Your program 
	should allow the user to repeat this calculation as often as desired.*/
	double loanAmmount, balance;
	double interest, interestRate, totalInterest = 0;
	int nPayments = 0, payment;
	
	while (true) {
		cout << "$";
		cin >> loanAmmount;
		if (loanAmmount == 0)
			break;
		cin >> interestRate;
		balance = loanAmmount;
		while (loanAmmount > 0) {
			payment = balance / 20;
			interest = (loanAmmount * (interestRate/100.0))/12.0;
			payment -= interest;
			loanAmmount -= payment;
			cout << "Payment: " << payment << "\tInterest: " << interest << "\tBalance: " << loanAmmount << endl;
			nPayments++;
			totalInterest += interest;
		}	
		cout << "Total Interest: " << totalInterest << endl;
		nPayments /= 12;
		nPayments++;
		totalInterest /= nPayments;
		cout << totalInterest << endl;
		totalInterest = totalInterest / balance;
		totalInterest *= 100;
		cout << "That was " << totalInterest << "% per year\n";
	}

}



void ch3ProgProject6() {
	int pounds, days;
	cout << "$";
	cin >> pounds >> days;

	int day1, day2;
	day1 = 0;
	day2 = pounds;

	days /= 5;

	while (days > 0) {
		int temp = day1;
		day1 = day2;
		day2 += temp;
		days--;
	}
	cout << "Pounds: " << day2;
}



void ch3ProgProject7() {
	/* The value e^x can be approximated by the sum
		
		1 + x + x^2/2! + x^3/3! + ... + x^n/n!

	Write a program that takes a value x as input and outputs this sum for n 
	taken to be each of the values 1 to 100. The program should also output e^x
	calculated using the predefined function exp. The function exp is a predefined 
	function such that exp(x) returns an approximation to the value ex. 
	
	The function exp is in the library with the header file cmath. Your program 
	should repeat the calculation for new values of x until the user says she 
	or he is through.
	
	Use variables of type double to store the factorials or you are likely to produce 
	integer overflow (or arrange your calculation to avoid any direct calculation 
	of factorials). 100 lines of output might not fit comfortably on your screen. 
	Output the 100 output values in a format that will fit all 100 values on the 
	screen. For example, you might output 10 lines with 10 values on each line*/
	double x, fact = 1, res, total = 0;

	do {
		cout << "$ ";
		cin >> x;

		res = exp(x);

		for (int i = 0; i < 101; i++) {
			if (i != 0) {
				fact *= i;
			}
			total += pow(x, i) / fact;
			cout << total << "\t";
			if (i % 10 == 0) cout << endl;
		}
		cout << "Res: " << res << endl;
	} while (x != -1);

}



void ch3ProgProject8() {
	/*An approximate value of pi can be calculated using the series given below:
	
		pi = 4 [ 1 – 1/3 + 1/5 – 1/7 + 1/9 ... + ((–1)^n)/(2n + 1) ]
 
	Write a C++ program to calculate the approximate value of pi using this 
	series. The program takes an input n that determines the number of terms 
	in the approximation of the value of pi and outputs the approximation. 
	Include a loop that allows the user to repeat this calculation for new values 
	n until the user says she or he wants to end the program.*/

	double n, pi;

	do {
		cout << "$ ";
		cin >> n;

		pi = 0;

		for (int i = 0; i < n; i++) 
			pi += (pow(-1, i) / (2 * i + 1));
			
		pi *= 4;

		cout << "Pi: " << pi << endl;
	} while (n != -1);

}



void ch3ProgProject9() {
	/*The following problem is sometimes called “The Monty Hall Game Show 
	Problem.” You are a contestant on a game show and have won a shot at the 
	grand prize. Before you are three closed doors. Behind one door is a brand 
	new car. Behind the other two doors are consolation prizes. The location of 
	the prizes is randomly selected. The game show host asks you to select a door, 
	and you pick one. However, before revealing the contents behind your door, 
	the game show host reveals one of the other doors with a consolation prize. 
	
	At this point, the game show host asks if you would like to stick with your 
	original choice or switch your choice to the other closed door. What choice 
	should you make to optimize your chances of winning the car? Does it matter 
	whether you stick with your original choice or switch doors?
	
	Write a simulation program to solve the game show problem. Your program should 
	make 10,000 simulated runs through the problem, randomly selecting locations 
	for the prize, and then counting the number of times ´the car was won when 
	sticking with the original choice, and counting the number of times the car 
	was won when switching doors. Output the estimated probability of winning for 
	both strategies. Be sure that your program exactly simulates the process of 
	selecting the door, revealing one, and then switching. Do not make assumptions 
	about the actual solution (for example, simply assuming that there is a 1/3 or 
	1/2 chance of getting the prize).
 
	Appendix 4 gives library functions for generating random numbers. A more 
	detailed description is provided in Chapter 4.*/
	bool door1, door2, door3, stick;
	int answer, rightDoor, removeDoor, secondPick,
		numStick = 0, numSwitch = 0, totalStick = 0, totalSwitch = 0,
		trials = 10000;

	door1 = door2 = door3 = false;
	stick = true;

	random_device rand;
	mt19937 gen(rand());
	uniform_int_distribution<> initial(1, 3);
	uniform_int_distribution<> switchDoor(1, 2);

	for (int i = 0; i < trials; i++) {
		rightDoor = initial(gen);		//1
		answer = initial(gen);		//2

		//Ensures the removed door isn't the right one or the one the user selected
		do {
			removeDoor = initial(gen);
		} while (removeDoor == rightDoor || removeDoor == answer);

		//Randomly generates a switch
		if (switchDoor(gen) == 2) {
			stick = false;
			totalSwitch++;
			//Ensures the second pick is valid and different from the first
			do {
				secondPick = initial(gen);
			} while (secondPick == answer || secondPick == removeDoor);
			answer = secondPick;
		}
		else totalStick++;
		
		if (answer == rightDoor) {
			if (!stick)
				numSwitch++;
			else numStick++;
		}

		stick = true;
	}

	double stickProb = double(numStick) / totalSwitch * 100;
	double switchProb = double(numSwitch) / totalStick * 100;
	
	cout << "Stick Probability:\t" << stickProb << "%\n";
	cout << "Switch Probability:\t" << switchProb << "%\n";
	cout << trials - numStick - numSwitch << " missed attempts\n";

}



void ch3ProgProject10() {
	/*Repeat Programming Project 13 from Chapter 2 but in addition ask the 
	user if he or she is:
		
		a. Sedentary
		b. Somewhat active (exercise occasionally)
		c. Active (exercise 3–4 days per week)
		d. Highly active (exercise every day)
	
	If the user answers “Sedentary,” then increase the calculated BMR by 20 
	percent. If the user answers “Somewhat active,” then increase the calculated 
	BMR by 30 percent. If the user answers “Active,” then increase the 
	calculated BMR by 40 percent. Finally, if the user answers “Highly active,” 
	then increase the calculated BMR by 50 percent. Output the number of 
	chocolate bars based on the new BMR value.*/
	double weight, height, bmr, numBars;
	int chocolateBar = 230,
		age;
	char gender;
	string activity;
	bool valid;

	while (true) {
		cout << "$";

		cin >> weight;
		if (weight == -1) break;
		cin >> height;
		do {
			cin >> gender;
		} while (gender != 'M' && gender != 'F');
		cin >> age;

		switch (gender) {
		case 'M': bmr = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
			break;
		case 'F': bmr = 665 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
			break;
		}
		do {
			valid = true;

			cin >> activity;

			if (activity == "Sedentary") bmr += bmr * 0.2;
			else if (activity == "Somewhat active") bmr += bmr * 0.3;
			else if (activity == "Active") bmr += bmr * 0.4;
			else if (activity == "Highly active") bmr += bmr * 0.5;
			else valid = false;

		} while (!valid);

		numBars = bmr / chocolateBar;

		cout << "You can have " << int(numBars) << " chocolate bars\n";
	}
}



void ch3ProgProject11() {
	/*The keypad on your oven is used to enter the desired baking temperature
	and is arranged like the digits on a phone:

		1 2 3
		4 5 6
		7 8 9
		  0

	Unfortunately the circuitry is damaged and the digits in the leftmost column
	no longer function. In other words, the digits 1, 4, and 7 do not work.
	If a recipe calls for a temperature that can’t be entered, then you would
	like to substitute a temperature that can be entered. Write a program that
	inputs a desired temperature. The temperature must be between 0 and 999
	degrees. If the desired temperature does not contain 1, 4, or 7, then output
	the desired temperature. Otherwise, compute the next largest and the next
	smallest temperature that does not contain 1, 4, or 7 and output both.
	For example, if the desired temperature is 450, then the program
	should output 399 and 500. Similarly, if the desired temperature is
	375, then the program should output 380 and 369*/
	int temperature, hunds, tens, units;
	int aboveh, abovet, aboveu, belowh, belowt, belowu;
	bool flag = false;

	cout << "$";
	cin >> temperature;

	hunds = temperature / 100;
	tens = (temperature % 100) / 10;
	units = temperature % 10;

	if (hunds == 1 || hunds == 4 || hunds == 7) {
		aboveh = hunds + 1;
		abovet = 0;
		aboveu = 0;
		belowh = hunds - 1;
		belowt = 9;
		belowu = 9;
		flag = true;
	}
	else if (tens == 1 || tens == 4 || tens == 7) {
		aboveh = belowh = hunds;
		abovet = tens + 1;
		aboveu = 0;
		belowt = tens - 1;
		belowu = 9;
		flag = true;
	}
	else if (units == 1 || units == 4 || units == 7) {
		aboveh = belowh = hunds;
		abovet = belowt = tens;
		aboveu = units + 1;
		belowu = units - 1;
		flag = true;
	}
	if(flag)
		cout << aboveh << abovet << aboveu << "\t" << belowh << belowt << belowu << endl;

}



void ch3ProgProject12() {
	/*The game of “23” is a two-player game that begins with a pile of 23 toothpicks. 
	Players take turns, withdrawing either 1, 2, or 3 toothpicks at a time. 
	The player to withdraw the last toothpick loses the game. Write a human vs. 
	computer program that plays “23”. The human should always move first. 
	When it is the computer’s turn, it should play according to the following rules:
		
		•	If there are more than 4 toothpicks left, then the computer should
			withdraw 4 – X toothpicks, where X is the number of toothpicks the 
			human withdrew on the previous turn.
		•	If there are 2 to 4 toothpicks left, then the computer should withdraw
			enough toothpicks to leave 1.
		•	If there is 1 toothpick left, then the computer has to take it and loses.

	When the human player enters the number of toothpicks to withdraw, 
	the program should perform input validation. Make sure that the entered 
	number is between 1 and 3 and that the player is not trying to withdraw 
	more toothpicks than exist in the pile*/
	unsigned int playerPick, computerPick;
	bool playerWins = false;
	int totalPicks = 23;

	while (totalPicks > 0) {
		
		cout << "Remaining toothpicks: " << totalPicks << endl;

		do {
			cout << "$";
			cin >> playerPick;
		} while (playerPick > 3 && totalPicks - playerPick > 0);
		
		totalPicks -= playerPick;
		if (totalPicks == 0) playerWins = false;

		if (totalPicks > 4)
			computerPick = 4 - playerPick;
		else if (totalPicks > 2)
			computerPick = abs(1 - totalPicks);
		else {
			computerPick = 1;
			playerWins = true;
		}

		cout << "Computer picks " << computerPick << endl;
		totalPicks -= computerPick;
	}

	if (playerWins) cout << "You win!\n";
	else cout << "Git gud scrub!\n";
}



void ch3ProgProject13() {
	/*Holy digits Batman! The Riddler is planning his next caper somewhere on 
	Pennsylvania Avenue. In his usual sporting fashion, he has left the address 
	in the form of a puzzle. The address on Pennsylvania is a four-digit 
	number where:

		•	 All four digits are different
		•	 The digit in the thousands place is three times the digit in the tens place
		•	 The number is odd
		•	 The sum of the digits is 27
	
	Write a program that uses a loop (or loops) to find the address where the 
	Riddler plans to strike*/
	int thousand, hundred, decimal, unit, total;
	bool solved = false;
	decimal = 1;
	
	while (decimal < 4) {
		thousand = 3 * decimal;
		hundred = 0;
		while (hundred < 9) {
			unit = 1;
			while (unit < 9) {
				total = thousand + hundred + decimal + unit;
				if (total == 27) {
					solved = true;
					break;
				}
				else unit += 2;
			}
			if (solved) break;
			hundred++;
		}
		if (solved) break;
		decimal++;
	}

	cout << "The address is " << thousand << hundred << decimal << unit << endl;

}
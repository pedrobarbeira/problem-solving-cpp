//SOLVED
#define _USE_MATH_DEFINES
#include "chapter2.h"



void ch2Exercise1() {
	/*A metric ton is 35,273.92 ounces. Write a program that will read the weight 
	of a package of breakfast cereal in ounces and output the weight in metric 
	tons as well as the number of boxes needed to yield 1 metric ton of cereal. 
	Your program should allow the user to repeat this calculation as often as 
	the user wishes.*/
	double METRIC_TON = 32273.92;
	double ounces;
	double metricTon;
	char cont;

	do {
		cout << "Enter cereal ounces: ";
		cin >> ounces;

		metricTon = ounces / METRIC_TON;

		cout << fixed << setprecision(6);
		cout << "That ammounts to " << metricTon << " metric tons\n";
		cout << "Continue(Y/N)? ";
		cin >> cont;
	} while (cont == 'Y' || cont == 'y');

}



void ch2Exercise2() {
	/*The Babylonian algorithm to compute the square root of a number n is as 
	follows:
	
		1. Make a guess at the answer (you can pick n/2 as your initial guess).
		2 . Compute r = n / guess
		3. Set guess = (guess + r) / 2
		4. Go back to step 2 for as many iterations as necessary. The more that 
		steps 2 and 3 are repeated, the closer guess will become to the square 
		root of n.

	Write a program that inputs a double for n and iterates through the 
	Babylonian algorithm 100 times. For a more challenging version, iterate 
	until guess is within 1% of the previous guess, and outputs the answer as 
a	double.*/
	double n;

	cout << "Enter n: ";
	cin >> n;

	double guess = n / 2;

	while (true) {
		double r = n / guess;
		if (guess - ((guess + r) / 2) <= guess * 0.01) {
			guess = (guess + r) / 2;
			break;
		}
		else guess = (guess + r) / 2;
	}

	cout << "Square root approximation: " << guess << endl;
}



void ch2Exercise3() {
	/* Many treadmills output the speed of the treadmill in miles per hour 
	(mph) on the console, but most runners think of speed in terms of a pace. 
	A common pace is the number of minutes and seconds per mile instead 
	of mph.
	Write a program that starts with a quantity in mph and converts the 
	quantity into minutes and seconds per mile. As an example, the proper 
	output for an input of 6.5 mph should be 9 minutes and 13.8 seconds per 
	mile. If you need to convert a double to an int, which will discard any 
	value after the decimal point, then you may use

		intValue = static_cast<int>(dblVal);*/
	double mph;
	double seconds;

	cout << "Enter mph: ";
	cin >> mph;

	seconds = 3600 / mph;
	int minutes = seconds / 60;
	seconds -= minutes * 60;

	cout << setprecision(4)
		<< mph << "mph = " << minutes
		<< " minutes and " << seconds
		<< " seconds per mile" << endl;
}



void ch2Exercise4() {
	/*Write a program that plays the game of Mad Lib. Your program should 
	prompt the user to enter the following strings:
		
		■ The first or last name of your instructor
		■ Your name
		■ A food
		■ A number between 100 and 120
		■ An adjective
		■ A color
		■ An animal

	After the strings are input, they should be substituted into the story below 
	and output to the console.
	
		Dear Instructor [Instructor Name],
		I am sorry that I am unable to turn in my homework at this time. First, 
		I ate a rotten [Food], which made me turn [Color] and extremely ill. I 
		came down with a fever of [Number 100-120]. Next, my [Adjective] pet 
		[Animal] must have smelled the remains of the [Food] on my homework, 
		because he ate it. I am currently rewriting my homework and hope you 
		will accept it late.
		Sincerely,
		[Your Name]*/
	string prof, name, food, num, adj, color, animal;

	cout << "Enter the following names,\nProfessor: ";
	cin >> prof;
	cout << "You: ";
	cin >> name;
	cout << "Food: ";
	cin >> food;
	cout << "Number (100<n<120): ";
	cin >> num;
	cout << "Adjective: ";
	cin >> adj;
	cout << "Color: ";
	cin >> color;
	cout << "Animal: ";
	cin >> animal;

	cout << "\nDear instructor " << prof
		<< "\n\nI am sorry that I am unable to turn in my homework at this time. First,\n"
		<< "I ate a rotten " << food << ", which made me turn " << color
		<< " and extremely ill. I came down with a fever of " << num
		<< ". Nest, my " << adj << " pet " << animal << " must have smelled the remains of the "
		<< food << " on my homwork, because he ate it. I am currently rewriting"
		<< " my homework and hope you will accept it late.\n\nSincery,\n" << name << endl;

}



void ch2Exercise5(){
	/*The following is a short program that computes the volume of a sphere 
	given the radius. It will compile and run, but it does not adhere to the 
	program style recommended in Section 2.5. Rewrite the program using 
	the style described in the chapter for indentation, adding comments, and 
	appropriately named constants.
		
		#include <iostream>
		using namespace std;
		int main() 
		{
			double radius, vm;
			cout << “Enter radius of a sphere.” << endl; cin >> radius;
			vm = (4.0 / 3.0) * 3.1415 * radius * radius * radius;
			cout << “ The volume is “ << vm << endl;
			return 0;
		}*/
	double radius, vm;
	cout << "Enter radius of a sphere." << endl;
	cin >> radius;
	vm = (4.0 / 3.0) * 3.1415 * radius * radius * radius;
	cout << "The volume is" << vm << endl;
}



void ch2ProgProject1() {
	/*A government research lab has concluded that an artificial sweetener 
	commonly used in diet soda pop will cause death in laboratory mice. A 
	friend of yours is desperate to lose weight but cannot give up soda pop. 
	Your friend wants to know how much diet soda pop it is possible to drink 
	without dying as a result. Write a program to supply the answer. The input 
	to the program is the amount of artificial sweetener needed to kill a mouse 
	(use 5 grams), the mass of the mouse (use 35 grams), and the weight of 
	the dieter (use 45400 grams for a 100 pound person). Assume that the 
	lethal dose for a mouse is proportional to the lethal dose for the human. 
	A single can of soda pop has a mass of 350 grams. To ensure the safety of 
	your friend, be sure the program requests the weight at which the dieter 
	will stop dieting, rather than the dieter’s current weight. Assume that diet 
	soda contains 1/10th of 1% artificial sweetener. Use a variable declaration 
	with the modifier const to give a name to this fraction. You may want to 
	express the percent as the double value 0.001. Your program should allow 
	the calculation to be repeated as often as the user wishes.*/
	double lethalDose = 5.0 / 35;
	double personWeight;
	const double sodaPoison = 350 * 0.001;
	char repeat;

	do {
		cout << "Enter your weight (kg): ";
		cin >> personWeight;

		personWeight *= 1000;
		double deadPerson = personWeight * lethalDose;
		double sodaCans = deadPerson / sodaPoison;

		cout << "You can drink " << (int)sodaCans << " cans of soda\n";

		cout << "Repeat operation (y/n)?";
		cin >> repeat;
	} while (repeat != 'n' && repeat != 'N');
}



void ch2ProgProject2() {
	/*Workers at a particular company have won a 7.6% pay increase retroactive 
	for 6 months. Write a program that takes an employee’s previous annual 
	salary as input, and outputs the amount of retroactive pay due the employee,
	the new annual salary, and the new monthly salary. Use a variable 
	declaration with the modifier const to express the pay increase. Your program
	should allow the calculation to be repeated as often as the user wish*/
	const double PAY_RAISE = 0.076;
	char repeat;

	do {
		double oldSalary, newSalary, monthlySalary;
		double retroPay, raise;

		cout << "Enter your last year's salary: ";
		cin >> oldSalary;
		cout << "Enter duration of raise: ";
		cin >> raise;
		retroPay = oldSalary * PAY_RAISE / (12.0 / raise);
		newSalary = oldSalary + retroPay;
		monthlySalary = newSalary / 12;

		cout << "You had a " << retroPay << "$ increase on your old salary.\n"
			<< "Your new salary is: " << newSalary << "$ (" << monthlySalary << "/month)\n";

		cout << "Repeat(y/n)? ";
		cin >> repeat;

	} while (repeat != 'n' && repeat != 'N');
}



void ch2ProgProject3(){
	/* Modify your program from Programming Project 2 so that it calculates the 
	retroactive salary for a worker for any number of months, instead of just 
	6 months. The number of months is entered by the user.*/
}



void ch2ProgProject4() {
	/*Negotiating a consumer loan is not always straightforward. One form of 
	loan is the discount installment loan, which works as follows. Suppose a 
	loan has a face value of $1,000, the interest rate is 15%, and the duration 
	is 18 months. The interest is computed by multiplying the face value of 
	$1,000 by 0.15, to yield $150. That figure is then multiplied by the loan 
	period of 1.5 years to yield $225 as the total interest owed. That amount is 
	immediately deducted from the face value, leaving the consumer with only 
	$775. Repayment is made in equal monthly installments based on the face 
	value. So the monthly loan payment will be $1,000 divided by 18, which 
	is $55.56. This method of calculation may not be too bad if the consumer 
	needs $775 dollars, but the calculation is a bit more complicated if the 
	consumer needs $1,000. Write a program that will take three inputs: the 
	amount the consumer needs to receive, the interest rate, and the duration 
	of the loan in months. The program should then calculate the face value 
	required in order for the consumer to receive the amount needed. It should 
	also calculate the monthly payment. Your program should allow the calculations 
	to be repeated as often as the user wishes*/
	double receive, interest, duration;
	double faceValue, monthlyPayment;
	char repeat;

	do {
		cout << "Enter quantity to receive: ";
		cin >> receive;
		cout << "Enter interest rate: ";
		cin >> interest;
		cout << "Enter loan duration (months): ";
		cin >> duration;

		duration /= 12.0;
		interest /= 100.0;

		faceValue = receive / (1 - interest * duration);

		monthlyPayment = faceValue / (12 * duration);
		cout << "Face Value: " << faceValue << "$" << endl
			<< setprecision(4) << "Monthly Payments: " << monthlyPayment
			<< "$" << endl;

		cout << "Repeat(y/n): ";
		cin >> repeat;
	} while (repeat != 'n' && repeat != 'N');
}



void ch2ProgProject5() {
	/*Write a program that determines whether a meeting room is in violation 
	of fire law regulations regarding the maximum room capacity. The program 
	will read in the maximum room capacity and the number of people 
	attending the meeting. If the number of people is less than or equal to the 
	maximum room capacity, the program announces that it is legal to hold 
	the meeting and tells how many additional people may legally attend. If 
	the number of people exceeds the maximum room capacity, the program 
	announces that the meeting cannot be held as planned due to fire regulations 
	and tells how many people must be excluded in order to meet the 
	fire regulations. For a harder version, write your program so that it allows 
	the calculation to be repeated as often as the user wishes. If this is a class 
	exercise, ask your instructor whether you should do this harder version.*/
	int maxPeople;
	int peopleAttending;

	cout << "Enter max of people (-1 to quit): ";
	cin >> maxPeople;
	while (maxPeople > 0) {

		cout << "Enter no of people in meeting: ";
		cin >> peopleAttending;

		if (peopleAttending <= maxPeople) {
			cout << "You can have your meeting. There are "
				<< maxPeople % peopleAttending << " seats left\n";
		}
		else {
			cout << "Fire regulations make it impossible to hold this meeting. "
				<< "\nYou should exclude " << peopleAttending % maxPeople << " people\n";
		}

		cout << "Enter max of people (-1 to quit): ";
		cin >> maxPeople;
	}
}



void ch2ProgProject6() {
	/*An employee is paid at a rate of $16.78 per hour for the first 40 hours
	worked in a week. Any hours over that are paid at the overtime rate of
	one-and-one-half times that. From the worker’s gross pay, 6% is withheld for
	Social Security tax, 14% is withheld for federal income tax, 5% is withheld
	for state income tax, and $10 per week is withheld for union dues. If the
	worker has three or more dependents, then an additional $35 is withheld
	to cover the extra cost of health insurance beyond what the employer pays.
	Write a program that will read in the number of hours worked in a week
	and the number of dependents as input and will then output the worker’s
	gross pay, each withholding amount, and the net take-home pay for the
	week. For a harder version, write your program so that it allows the calculation
	to be repeated as often as the user wishes. If this is a class exercise, ask
	your instructor whether you should do this harder version.*/
	int hours, dependents;
	double pay = 16.78,
		grossPay,
		takeHome,
		socialSecurity,
		federalIncome,
		stateIncome;

	while (true) {

		cout << "$";

		cin >> hours;
		if (hours == -1) break;
		cin >> dependents;

		if (hours <= 40) grossPay = hours * pay;
		else grossPay = pay * 40 + 1.5 * pay * (hours - 40);

		socialSecurity = grossPay * 0.06;
		federalIncome = grossPay * 0.14;
		stateIncome = grossPay * 0.05;

		takeHome = grossPay - socialSecurity - federalIncome - stateIncome - 10;

		if (dependents >= 3) takeHome -= 35;

		cout << fixed << setprecision(2)
			<< "Gross Pay: " << grossPay << "$" << endl
			<< "Social Sec. Tax: " << socialSecurity << "$" << endl
			<< "Fed. Income Tax: " << federalIncome << "$" << endl
			<< "State Income Tax: " << stateIncome << "$" << endl
			<< "Take-home Pay: " << takeHome << "$" << endl << endl;
	}
}



void ch2ProgProject7(){
	/*It is difficult to make a budget that spans several years, because prices are 
	not stable. If your company needs 200 pencils per year, you cannot simply 
	use this year’s price as the cost of pencils 2 years from now. Because 
	of inflation the cost is likely to be higher than it is today. Write a program 
	to gauge the expected cost of an item in a specified number of years. The 
	program asks for the cost of the item, the number of years from now that 
	the item will be purchased, and the rate of inflation. The program then 
	outputs the estimated cost of the item after the specified period. Have 
	the user enter the inflation rate as a percentage, like 5.6 (percent). Your 
	program should then convert the percent to a fraction, like 0.056, and 
	should use a loop to estimate the price adjusted for inflation. (Hint: This 
	is similar to computing interest on a charge card account, which was disussed 
	in this chapter.)*/
	double itemCost, inflation;
	int years;

	while (true) {
		cout << "$";

		cin >> itemCost;
		if (itemCost == -1) break;
		cin >> years >> inflation;

		inflation /= 100;

		for (int i = 0; i < years; i++) {
			itemCost += itemCost * inflation;
		}

		cout << itemCost << "$" << endl;
	}
}



void ch2ProgProject8() {
	/*You have just purchased a stereo system that cost $1,000 on the following 
	credit plan: no down payment, an interest rate of 18% per year (and hence 
	1.5% per month), and monthly payments of $50. The monthly payment of 
	$50 is used to pay the interest and whatever is left is used to pay part of the 
	remaining debt. Hence, the first month you pay 1.5% of $1,000 in interest. 
	That is $15 in interest. So, the remaining $35 is deducted from your debt, 
	which leaves you with a debt of $965.00. The next month you pay interest 
	of 1.5% of $965.00, which is $14.48. Hence, you can deduct $35.52 (which 
	is $50 – $14.48) from the amount you owe. Write a program that will tell 
	you how many months it will take you to pay off the loan, as well as the 
	total amount of interest paid over the life of the loan. Use a loop to calculate 
	the amount of interest and the size of the debt after each month. (Your final 
	program need not output the monthly amount of interest paid and remaining debt, 
	but you may want to write a preliminary version of the program 
	that does output these values.) Use a variable to count the number of loop 
	iterations and hence the number of months until the debt is zero. You may 
	want to use other variables as well. The last payment may be less than $50. 
	Do not forget the interest on the last payment. If you owe $50, then your 
	monthly payment of $50 will not pay off your debt, although it will come 
	close. One month’s interest on $50 is only 75 cents.*/
	int months=0;
	double totalInterest = 0,
		debt = 1000,
		monthlyInterest = 0.015;

	while (debt > 0) {
		totalInterest += debt * monthlyInterest;
		debt -= (50 - debt * monthlyInterest);
		months++;
	}

	cout << fixed << setprecision(2)
		<<"You need " << months << " months to pay your debt\n"
		<< "The total paid interest was " << totalInterest << "$\n";
}



void ch2ProgProject9(){
	/*Write a program that reads in ten whole numbers and that outputs the 
	sum of all the numbers greater than zero, the sum of all the numbers less 
	than zero (which will be a negative number or zero), and the sum of all 
	the numbers, whether positive, negative, or zero. The user enters the ten 
	numbers just once each and the user can enter them in any order. Your 
	program should not ask the user to enter the positive numbers and the 
	negative numbers separately.*/
	int positive = 0,
		negative = 0,
		total = 0,
		num;
	cout << "$";

	for (int i = 0; i < 10; i++) {
		cin >> num;
		total += num;
		if (num > 0) positive += num;
		else negative += num;
	}

	cout << "Positive Numbers: " << positive << endl
		<< "Negative Numbers: " << negative << endl
		<< "Total Sum: " << total << endl;
}



void ch2ProgProject10() {
	/* Modify your program from Programming Project 9 so that it outputs the 
	sum of all positive numbers, the average of all positive numbers, the sum 
	of all nonpositive numbers, the average of all nonpositive numbers, the 
	sum of all positive and nonpositive numbers, and the average of all numbers	
	entered.*/
	int positive = 0,
		positiveSum = 0,
		negative = 0,
		negativeSum = 0,
		total = 0,
		num;

	cout << "$";

	for (int i = 0; i < 10; i++) {
		cin >> num;
		total += num;
		if (num > 0) {
			positive++;
			positiveSum += num;
		}
		else {
			negative++;
			negativeSum += num;
		}
	}

	double posAvg, negAvg, totalAvg;
	
	if (positive == 0) positive++;
	if (negative == 0) negative++;

	posAvg = static_cast<double>(positiveSum) / positive;
	negAvg = static_cast<double>(negativeSum) / negative;
	totalAvg = static_cast<double>(total) / (positive + negative);

	cout << "Positive Numbers: " << positiveSum << endl
		<< "Positive Average: " << posAvg << endl
		<< "Negative Numbers: " << negativeSum << endl
		<< "Negative Average: " << negAvg << endl
		<< "Total Sum: " << total << endl
		<< "Total Average: " << totalAvg << endl;
}



void ch2ProgProject11() {
	/* Sound travels through air as a result of collisions between the molecules in 
	the air. The temperature of the air affects the speed of the molecules, which 
	in turn affects the speed of sound. The velocity of sound in dry air can be 
	approximated by the formula:
		
		velocity ≈ 331.3 + 0.61 × Tc
	
	where Tc is the temperature of the air in degrees Celsius and the velocity is 
	in meters/second.
	Write a program that allows the user to input a starting and an ending 
	temperature. Within this temperature range, the program should output 
	the temperature and the corresponding velocity in 1° increments. For 
	example, if the user entered 0 as the start temperature and 2 as the end 
	temperature, then the program should output
	
		At 0 degrees Celsius the velocity of sound is 331.3 m/s
		At 1 degrees Celsius the velocity of sound is 331.9 m/s
		At 2 degrees Celsius the velocity of sound is 332.5 m/s*/

	int lowTemp, highTemp;
	double sound;

	cout << "$";

	cin >> lowTemp >> highTemp;

	for (int i = lowTemp; i <= highTemp; i++) {
		sound = 331.3 + 0.61 * i;
		cout << fixed << setprecision(1)
			<< "At " << i << " degrees Celsius the velocity of sound is " << sound << " m/s\n";
	}
}



void ch2ProgProject12() {
	/* Many private water wells produce only 1 or 2 gallons of water per minute. 
	One way to avoid running out of water with these low-yield wells 
	is to use a holding tank. A family of four will use about 250 gallons of 
	water per day. However, there is a “natural” water holding tank in the 
	casing (that is, the hole) of the well itself. A deeper well stores more 
	water that can be pumped out for household use. But how much water 
	will be available?
	Write a program that allows the user to input the radius of the well 
	casing in inches (a typical well will have a 3-inch radius) and the depth 
	of the well in feet (assume water will fill this entire depth, although in 
	practice that will not be true since the static water level will generally be 
	50 feet or more below the ground surface). The program should output 
	the number of gallons stored in the well casing. For your reference, the 
	volume of a cylinder is 
		
		pi*r^2 * h,
		
	where r is the radius and h is the height, and 1 cubic foot = 7.48 gallons of water. 
	For example, a 300-foot-well full of water with a radius of 3 inches for the 
	casing holds about 441 gallons of water—plenty for a family of four and 
	no need to install a separate holding tank.*/
	double radius, height;

	cout << "$";
	cin >> radius >> height;

	radius /= 12;
	double volWell = M_PI * pow(radius, 2) * height;
	double gallonsWell = volWell * GL_IN_F3;

	cout << gallonsWell << " gallons in the well\n";	
}



void ch2ProgProject13() {
	/*The Harris–Benedict equation estimates the number of calories your body 
	needs to maintain your weight if you do no exercise. This is called your 
	basal metabolic rate, or BMR.
	The formula for the calories needed for a woman to maintain her weight is

		BMR = 655 + (4.3 × weight in pounds) + (4.7 × height in inches) – (4.7 × age in years)
	
	The formula for the calories needed for a man to maintain his weight is

		BMR = 66 + (6.3 × weight in pounds) + (12.9 × height in inches) – (6.8 × age in years)
	
	A typical chocolate bar will contain around 230 calories. Write a program 
	that allows the user to input his or her weight in pounds, height in 
	inches, age in years, and the character M for male and F for female. The 
	program should then output the number of chocolate bars that should 
	be consumed to maintain one’s weight for the appropriate sex of the 
	specified weight, height, and age.*/
	double weight, height, bmr, numBars;
	int chocolateBar = 230,
		age;
	char gender;

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
		
		numBars = bmr / chocolateBar;

		cout << "You can have " << int(numBars) << " chocolate bars\n";
	}

}



void ch2ProgProject14() {
	/*Write a program that calculates the total grade for N classroom exercises 
	as a percentage. The user should input the value for N followed by each of 
	the N scores and totals. Calculate the overall percentage (sum of the total 
	points earned divided by the total points possible) and output it as a percentage. 
	Sample input and output is shown below.
		
		How many exercises to input? 3

		Score received for exercise 1: 10
		Total points possible for exercise 1: 10

		
		Score received for exercise 2: 7
		Total points possible for exercise 2: 12

		Score received for exercise 3: 5
		Total points possible for exercise 3: 8

		Your total is 22 out of 30, or 73.33%*/
	int totalSum = 0, maxSum = 0, score;
	int exNum;

	cout << "How many exercises to input? ";
	cin >> exNum;

	for (int i = 1; i <= exNum; i++) {
		cout << "\nScore received for exercise " << i << ": ";

		cin >> score;
		totalSum += score;

		cout << "Total points possible for exercise " << i << ": ";

		cin >> score;
		maxSum += score;
	}

	score = (static_cast<double>(totalSum) / maxSum) * 100;

	cout << fixed << showpoint << setprecision(2)
		<< "\nYour total is " << totalSum << " out of " << maxSum
		<< ", or " << score << "%\n";
}



void ch2ProgProject15() {
	/*It is important to consider the effect of thermal expansion when building a 
	structure that must withstand changes in temperature. For example, a metal 
	beam will expand in hot temperatures. The additional stress could cause 
	the structure to fail. Similarly, a material will contract in cold temperatures. 
	The linear change in length of a material if it is allowed to freely expand is 
	described by the following equation:
		
		L∆ = L0T∆

	Here, L0 is the initial length of the material in meters, L∆ is the displacement 
	in meters, T∆ is the change in temperature in Celsius, and  is a coefficient 
	for linear expansion.
	Write a program that inputs , L∆, and T∆, then calculates and outputs 
	the linear displacement. If the displacement is positive then output 
	that “The material will expand by” the displacement in meters. If the 
	displacement is negative then output that “The material will contract by” 
	the displacement in meters. You shouldn’t output the displacement as a 
	negative number. Here are some values for  for different materials.

		Aluminum	2.31e-5
		Copper		1.70e-5
		Glass		8.50e-6
		Steel		1.20e-5*/
	double alpha, length, dTemp,
		displacement;

	cout << "$";
	cin >> alpha >> length >> dTemp;

	displacement = alpha * length * dTemp;

	if (displacement > 0)
		cout << "The material will expand by " << scientific 
			<< setprecision(2) << displacement << " meters\n";
	else cout << "The material will contract by " << scientific 
			<< setprecision(2) << abs(displacement) << " meters\n";
}
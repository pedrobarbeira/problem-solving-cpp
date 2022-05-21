#define _CRT_SECURE_NO_WARNINGS
#include "chapter7.h"

int outOfOrder(double a[], int size) {
	double last = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] < last) return i;
		else last = a[i];
	}
	return -1;
}

void readArray() {
	int arr[10] = { 0 };
	int load;

	cout << "$";

	for (int i = 0; i < 10; i++) {
		cin >> load;
		if (load > 0) arr[i] = load;
	}

	cout << "Array: ";

	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";

	cout << endl;
}

void letterBox() {
	char letterBox[11];
	bool out = false;

	cout << "$";

	for (int i = 0; i < 11; i++) {
		cin >> letterBox[i];
		if (letterBox[i] == '.') break;
	}

	for (int i = 10; i >= 0; i--) {
		if (out) cout << letterBox[i];
		if (letterBox[i] == '.') out = true;
	}

	cout << endl;
}

bool search(const int a[], int number_used, int target, int& where) {
	for (int i = 0; i < number_used; i++) {
		if (a[i] == target) where = i;
		return true;
	}
	return false;
}

template<typename T>
void print(T arr[], size_t size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}



void ch7Exercise1() {
	/*Write a function named firstLast2 that takes as input an array of integers
	and an integer that specifies how many entries are in the array. The function
	should return true if the array starts or ends with the digit 2. Otherwise it
	should return false. Test your function with arrays of different length
	with the digit 2 at the beginning of the array, end of the array, middle of
	the array, and missing from the array*/
	int arr1[5] = { 2, 3, 4, 5, 2 };
	int arr2[3] = { 1, 2, 3 };
	int arr3[4] = { 2, 1, 4, 3 };
	int arr4[4] = { 1, 3, 4, 2 };

	if (firstLast2(arr1, 5)) cout << "checkpoint 1\n";
	if (!firstLast2(arr2, 3)) cout << "checkpoint 2\n";
	if (!firstLast2(arr3, 4)) cout << "checkpoint 3\n";
	if (!firstLast2(arr4, 4)) cout << "checkpoint 4\n";
}
bool firstLast2(int arr[], size_t size) {
	return arr[0] == 2 && arr[size - 1] == 2;
}


void ch7Exercise2() {
	/*Write a function named countNum2s that takes as input an array of integers
	and an integer that specifies how many entries are in the array. The function
	should return the number of 2’s in the array. Test your function with
	arrays of different length and with varying number of 2’s*/
	int arr1[5] = { 2, 3, 4, 5, 2 };
	int arr2[3] = { 1, 2, 3 };
	int arr3[4] = { 7, 1, 4, 3 };
	int arr4[4] = { 1, 3, 4, 2 };

	assert(countNum2s(arr1, 5) == 2);
	assert(countNum2s(arr2, 3) == 1);
	assert(countNum2s(arr3, 4) == 0);
	assert(countNum2s(arr4, 4) == 1);

	cout << "Izy pizy\n";
}
int countNum2s(int arr[], size_t size) {
	int count = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] == 2) count++;
	return count;
}


void ch7Exercise3(){
	int arr1[5] = { 2, 3, 4, 5, 2 };
	int arr2[3] = { 1, 2, 3 };
	int arr3[4] = { 7, 1, 4, 3 };
	int arr4[4] = { 1, 3, 4, 2 };

	swapFrontBack(arr1, 5);
	swapFrontBack(arr2, 3);
	swapFrontBack(arr3, 4);
	swapFrontBack(arr4, 4);

	print(arr1, 5);
	print(arr2, 3);
	print(arr3, 4);
	print(arr4, 4);
}
void swapFrontBack(int arr[], size_t size) {
	int temp = arr[size - 1];
	arr[size - 1] = arr[0];
	arr[0] = temp;
}


void ch7Exercise4() {
	using namespace std;
	string names[] = { "Michael Myers","Ash Williams","Jack Torrance","Freddy Krueger" };
	string phoneNumbers[] = { "333-8000","333-2323","333-6150","339-7970" };
	string targetName, targetPhone;
	char c;
	do{
		cout << "Enter a name to find the corresponding phone number.\n";
		getline(cin, targetName);
		targetPhone = lookupName(targetName, names, phoneNumbers, 4);
		
		if (targetPhone.length() > 0)
			cout << "The number is: " << targetPhone << endl;
		else cout << "Name not found.\n";

		cout << "Look up another name? (y/n)\n";
		cin >> c;
		cin.ignore();
	} while (c == 'y');
}
string lookupName(string name, string names[], string phoneNumbers[], size_t size) {
	int i;
	for (i = 0; i < size; i++) {
		if (name == names[i])
			return phoneNumbers[i];
	}
	return "";
}


void ch7ProgProject1(){}


void ch7ProgProject2() {
	/*Hexadecimal numerals are integers written in base 16. The 16 digits used 
	are ‘0’ through ‘9’ plus ‘a’ for the “digit 10”, ‘b’ for the “digit 11”, ‘c’ for 
	the “digit 12”, ‘d’ for the “digit 13”, ‘e’ for the “digit 14”, and ‘f ’ for the 
	“digit 15”. For example, the hexadecimal numeral d is the same as base 10 
	numeral 13 and the hexadecimal numeral 1d is the same as the base 
	10 numeral 29. Write a C++ program to perform addition of two hexadecimal numerals 
	each with up to 10 digits. If the result of the addition is more 
	than 10 digits long, then simply give the output message “Addition Overflow” and 
	not the result of the addition. Use arrays to store hexadecimal 
	numerals as arrays of characters. Include a loop to repeat this calculation 
	for new numbers until the user says she or he wants to end the program*/
	
	char hex1[10]{' '}, hex2[10]{' '};
	long long int int1 = 0, int2 = 0;
	bool stop = true;


	cout << "[Hex Adder (Q to Quit)}\n";
	readHex(hex1, stop);

	while(stop){
		readHex(hex2, stop);
		
		if (!stop) break;

		convertHex(hex1, int1);
		convertHex(hex2, int2);

		int1 += int2;

		if (int1 > 0xFFFFFFFFFF)
			cout << "Addition Overflow\n";
		else {

			int it = 0;

			while (it < 10) {
				int2 = int1 % 16;
				hex1[9 - it] = decToHex(int2);
				int1 /= 16;
				it++;
			}
			cout << ">";
			for (it = 0; it < 10; it++)
				cout << hex1[it];
			cout << endl;
		}
	} 


}
void readHex(char hex[], bool& stop) {
	string input;
	bool flag = true;
	size_t size;

	while (flag){
		cout << ">";
		cin >> input;
		if (input.size() > 10)
			cout << "10 digits max\n";
		else flag = false;
	}
	if (input == "Q" || input == "q") {
		stop = false;
		return;
	}

	size = 10 - input.size();

	for (int i = 0; i < input.size(); i++)
		hex[size + i] = input[i];
}
void convertHex(char hex[], long long int& dec) {
	for (int i = 0; i < 10; i++) {
		dec += hexToDec(hex[9 - i]) * pow(16, i);
	}
}
int hexToDec(char hex) {
	if (hex == 'a') return 10;
	else if (hex == 'b') return 11;
	else if (hex == 'c') return 12;
	else if (hex == 'd') return 13;
	else if (hex == 'e') return 14;
	else if (hex == 'f') return 15;
	else if (isdigit(hex)) return hex - '0';
	else return 0;
}
char decToHex(int dec) {
	if (dec == 10) return 'a';
	else if (dec == 11) return 'b';
	else if (dec == 12) return 'c';
	else if (dec == 13) return 'd';
	else if (dec == 14) return 'e';
	else if (dec == 15) return 'f';
	else return dec + '0';
}


void ch7ProgProject3() {
	/*Write a function called delete_repeats that has a partially filled array of
	characters as a formal parameter and that deletes all repeated letters from the
	array. Since a partially filled array requires two arguments, the function will
	actually have two formal parameters: an array parameter and a formal parameter
	of type int that gives the number of array positions used. When a letter is
	deleted, the remaining letters are moved forward to fill in the gap. This will
	create empty positions at the end of the array so that less of the array is used.
	Since the formal parameter is a partially filled array, a second formal parameter
	of type int will tell how many array positions are filled. This second formal
	parameter will be a call-by-reference parameter and will be changed to show
	how much of the array is used after the repeated letters are deleted.

	For example, consider the following code:

		char a[10];
		a[0] = 'a';
		a[1] = 'b';
		a[2] = 'a';
		a[3] = 'c';
		int size = 4;
		delete_repeats(a, size);

	After this code is executed, the value of a[0] is 'a', the value of a[1] is
	'b', the value of a[2] is 'c', and the value of size is 3. (The value of a[3]
	is no longer of any concern, since the partially filled array no longer uses
	this indexed variable.)
	You may assume that the partially filled array contains only lowercase
	letters. Embed your function in a suitable test program.*/

	string intention;
	cout << "> ";
	getline(cin, intention);

	int size = intention.size();
	char *intent = new char[size * sizeof(char) + 1]();

	strcpy(intent, intention.c_str());


	delete_repeats(intent, size);
	print(intent, size);

	free(intent);

}
void delete_repeats(char arr[], int& size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] == arr[j]) {
				for (int k = j; k < size - 1; k++)
					arr[k] = arr[k + 1];
				size--;
			}
		}
	}
}


void ch7ProgProject4() {
	/*The standard deviation of a list of numbers is a measure of how much the 
	numbers deviate from the average. If the standard deviation is small, the 
	numbers are clustered close to the average. If the standard deviation is large, 
	the numbers are scattered far from the average. The standard deviation, S, of 
	a list of N numbers x is defined as follows:

		S = sqrt(∑[(xi-x)^2]/N)

	where x is the average of the N numbers x1, x2, . . . . Define a function 
	that takes a partially filled array of numbers as its arguments and returns 
	the standard deviation of the numbers in the partially filled array. Since 
	a partially filled array requires two arguments, the function will actually 
	have two formal parameters: an array parameter and a formal parameter 
	of type int that gives the number of array positions used. The numbers 
	in the array will be of type double. Embed your function in a suitable test 
	program*/

	const int size = 5;
	double arr[size] = { 1.1, 2.2, 3.14, 4.42, 5 };
	
	cout << stDev(arr, size) << endl;
}
double stDev(double arr[], int size) {
	double avg = 0, sum = 0;
	int i;
	
	//Computes average
	for (i = 0; i < size; i++)
		avg += arr[i];
	
	avg /= double(size);
	
	//Calculates sum of deviations
	for (i = 0; i < size; i++)
		sum += pow((arr[i] - avg), 2);

	//Returns standard deviation
	return sqrt(sum / double(size));
}


void ch7ProgProject5() {
	/*Write a program that reads in a list of integers into an array with base 
	type int. Provide the facility to either read this array from the keyboard or 
	from a file, at the user’s option. If the user chooses file input, the program 
	should request a file name. You may assume that there are fewer than 
	50 entries in the array. Your program determines how many entries there 
	are. The output is to be a two-column list. The first column is a list of the 
	distinct array elements; the second column is the count of the number of 
	occurrences of each element. The list should be sorted on entries in the first 
	column, largest to smallest.
	For example, for the input
		
		-12 3 -12 4 1 1 -12 1 -1 1 2 3 4 2 3 -12

	the output should be
		
		N Count
		4 2
		3 3
		2 2
		1 4
	   -1 1
	  -12 4*/

	int size = 50;
	int *arr = new int[50];
	int freq[50];
	
	index(arr, size);
	sortArray(arr, size);
	countFrequency(arr, freq, size);

	cout << endl << setw(4) << left << "N" << "Count\n";
	for (int i = 0; i < size; i++) {
		cout << setw(4) << left << arr[i] << freq[i] << endl;
	}

}
template<typename T>
void index(T arr[], int& size) {
	char sel;

	cout << "F - File; K - Keyboard\n";

	do {
		cout << "$";
		cin >> sel;
		if (sel == 'K' || sel == 'k') {
			cout << "$";
			readArray(cin, arr, size);
		}
		else if (sel == 'F' || sel == 'f') {
			string filename;
			ifstream infile;

			cout << "&";
			cin >> filename;

			filename = "chapter7//" + filename;

			infile.open(filename);
			if (infile.fail()) cout << "error\n";
			readArray(infile, arr, size);
		}
	} while (sel != 'F' || sel != 'f' || sel != 'K' || sel != 'k');
}
template<typename T>
void readArray(istream& in, T arr[], int& size) {
	T load;
	int i = 0;

	while(in >> load){
		arr[i] = load;
		i++;
	} 

	size = i;
}
template<typename T>
void sortArray(T arr[], int& size) {
	T temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
template<typename T>
void countFrequency(T arr[], int freq[], int& size) {
	int count;
	int j;
	for (int i = 0; i < size; i++) {
		j = i + 1;
count = 1;
while (arr[i] == arr[j] && i < size - 1) {
	count++;
	for (int k = i + 1; k < size - 1; k++)
		arr[k] = arr[k + 1];
	size--;
}
freq[i] = count;
	}
}


void ch7ProgProject6(){
    /*Problem description includes a long description of how to implement the
      solution. It basically boils down to an implementation of insertion sort*/
    int SIZE = 10;
    int* arr = new int[SIZE];
    for(int i = 0; i < 10; i++)
        arr[i] = i+1;
    insertionSort(arr, SIZE);
    for(int i = 0; i < SIZE; i++)
        std::cout << arr[i] << ' ';
    std::cout << endl;
}
void insertionSort(int* arr, int size) {
    for(int i = 1; i < size; i++){
        for(int j = i - 1; j >= 0; j--)
            if(arr[j] > arr[i]){
                int temp = arr[i];
                arr[j] = arr[i];
                arr[i] = temp;
            }
    }
}


void ch7ProgProject7(){
    /*An array can be used to store large integers one digit at a time. For example,
     the integer 1234 could be stored in the array a by setting a[0] to 1, a[1]
     to 2, a[2] to 3, and a[3] to 4. However, for this exercise you might find it
     more useful to store the digits backward, that is, place 4 in a[0], 3 in a[1],
     2 in a[2], and 1 in a[3].

     In this exercise you will write a program that reads in two positive integers
     that are 20 or fewer digits in length and then outputs the sum of the two
     numbers. Your program will read the digits as values of type char so that
     the number 1234 is read as the four characters '1', '2', '3', and '4'.
     After they are read into the program, the characters are changed to values
     of type int. The digits will be read into a partially filled array, and you
     might find it useful to reverse the order of the elements in the array after
     the array is filled with data from the keyboard. (Whether or not you
     reverse the order of the elements in the array is up to you. It can be done
     either way, and each way has its advantages and disadvantages.)

     Your program will perform the addition by implementing the usual
     paper-and-pencil addition algorithm. The result of the addition is stored
     in an array of size 20, and the result is then written to the screen. If the
     result of the addition is an integer with more than the maximum number
     of digits (that is, more than 20 digits), then your program should issue a
     message saying that it has encountered “integer overflow.” You should be
     able to change the maximum length of the integers by changing only one
     globally defined constant. Include a loop that allows the user to continue
     to do more additions until the user says the program shoudl end*/

    size_t C7E6SIZE = 20;

    char* res = new char[C7E6SIZE];
    char* n1 = new char[C7E6SIZE];
    char* n2 = new char[C7E6SIZE];

    std::string int1, int2;
    do {
        for(int i = 0; i < C7E6SIZE; i++){
            n1[i] = '0';
            n2[i] = '0';
        }

        while (true) {
            std::cout << "Integer 1: ";
            std::cin >> int1;
            if (storeInArray(int1, n1, C7E6SIZE) == nullptr)
                std::cout << "Invalid input: insert a number with under "
                          << C7E6SIZE << " digits\n";
            else break;
        }
        while (true) {
            std::cout << "Integer 2: ";
            std::cin >> int2;
            if (storeInArray(int2, n2, C7E6SIZE) == nullptr)
                std::cout << "Invalid input: insert a number with under "
                          << C7E6SIZE << " digits\n";
            else break;
        }

        if (addIntegersArr(n1, n2, res, C7E6SIZE) == nullptr) {
            if (!handleOverflow()) {
                std::cout << "New size: ";
                cin >> C7E6SIZE;
                res = new char[C7E6SIZE];
                n1 = new char[C7E6SIZE];
                n2 = new char[C7E6SIZE];
            }
        } else {
            for(int i = C7E6SIZE-1; i >= 0; i--)
                std::cout << res[i];
            std::cout << endl;
        }
    }while(repeatComputation());
}

int repeatComputation(){
    char opt = '\0';
    while(true){
        std::cout << "Repeat computation?[y/n]";
        cin >> opt;
        opt = toupper(opt);
        if(opt == 'Y') return 1;
        else if(opt == 'N') return 0;
    }
}

int handleOverflow(){
    char opt = '\0';
    std::cout << "Integer overflow\n";
    while(true){
        std::cout << "Change max integer size? [y/n]";
        cin >> opt;
        toupper(opt);
        if(opt == 'Y') return 0;
        else if(opt == 'N') return 1;
    }
}

char* storeInArray(std::string in, char* ret, size_t size){
    if(in.length() > size) return nullptr;
    else{
        int length = in.length() - 1;
        for(int i = 0; i <= length; i++)
            ret[i] = in[length-i];
        return ret;
    }
}

char* addIntegersArr(char* n1, char* n2, char* ret, size_t size){
    int i1, i2, overflow = 0;
    for(int i = 0; i < size; i++){
        i1 = (n1[i]-'0') + (n2[i]-'0') + overflow;
        if(i1 < 10) {
            ret[i] = i1+'0';
            overflow = 0;
        }
        else{
            i2 = i1 % 10;
            overflow = i1 / 10;
            ret[1] = i2+'0';
        }
    }
    if(overflow) return nullptr;
    else return ret;
}

void ch7ProgProject8(){
    /*Write a program that will read a line of text and output a list of all the
      letters that occur in the text together with the number of times each letter
      occurs in the line. End the line with a period that serves as a sentinel value.
      The letters should be listed in the following order: the most frequently oc-
      curring letter, the next most frequently occurring letter, and so forth. Use
      two arrays, one to hold integers and one to hold letters. You may assume
      that the input uses all lowercase letters. For example, the input


        do be do bo.

     should produce output similar to the following:

        Letter NoOccurrences
            o         3
            d         2
            b         2
            e         1

    Your program will need to sort the arrays according to the values in the
    integer array. This will require that you modify the function sort given
    in Display 7.12. You cannot use sort to solve this problem without
    changing the function. If this is a class assignment, ask your instructor if
    input/output should be done with the keyboard and screen or if it should
    be done with files. If it is to be done with files, ask your instructor for
    instructions on file names.*/

#define ALPHABETSIZE    26
    std::string LINE = "do be do bo";

    char* letterArr = new char[ALPHABETSIZE];
    uint16_t* letterCount = new uint16_t[ALPHABETSIZE];

    for(int i = 0; i < ALPHABETSIZE; i++){
        letterArr[i] = '\0';
        letterCount[i] = 0;
    }

    letterOccurrences(LINE, letterArr, letterCount);
    sortOccurrences(letterArr, letterCount);
    printLetterOccurrences(letterArr, letterCount);
}

void letterOccurrences(const std::string& s, char* letterArr, uint16_t* letterCount){
    int ASCII_LOWERCASE_A = 97, index;
    for(int i = 0; i < s.length(); i++){
        index = s[i] - ASCII_LOWERCASE_A;
        if(letterArr[index] == '\0') letterArr[index] = s[i];
        letterCount[index]++;
    }
}

void printLetterOccurrences(char* letterArr, uint16_t* letterCount){
    for(int i = 0; letterArr[i] != '\0'; i++){
        std::cout << letterArr[i] << ' ' << letterCount[i] << std::endl;
    }
}

void defragmentOccurences(char* letterArr, uint16_t* letterCount){
    int nullIndex = 0;
    bool dirty = true;
    for(int i = 0; i < ALPHABETSIZE; i++) {
        if (dirty) {
            while (letterArr[nullIndex] != '\0') nullIndex++;
            dirty = false;
        }
        if (letterArr[i] != '\0') {
            letterArr[nullIndex] = letterArr[i];
            letterArr[i] = '\0';
            letterCount[nullIndex] = letterCount[i];
            letterCount[i] = 0;
            dirty = true;

        }
    }
}

void sortOccurrences(char* letterArr, uint16_t* letterCount){
    defragmentOccurences(letterArr, letterCount);
    for(int i = 1; letterArr[i] != '\0'; i++){
        for(int j = i; j > 0; j--){
            if(letterCount[j] > letterCount[j-1]){
                swap(letterArr[j-1], letterArr[j]);
                swap(letterCount[j-1], letterCount[j]);
            }
        }
    }
}


void ch7ProgProject9(){
    /*Write a program to score five-card poker hands into one of the following
    categories: nothing, one pair, two pairs, three of a kind, straight (in order,
    with no gaps), flush (all the same suit, for example, all spades), full house
    (one pair and three of a kind), four of a kind, straight flush (both a straight
    and a flush). Use two arrays, one to hold the value of the card and one to
    hold the suit. Include a loop that allows the user to continue to score more
    hands until the user says the program should end.*/

#define PP9HANDSIZE 5

    int values[PP9HANDSIZE] = {1, 6, 3, 4, 5};
    char suits[PP9HANDSIZE] = {'A', 'C', 'A', 'A', 'A'};

    readCardInput(values, suits);
    checkHand(values, suits);
}

void readCardInput(int* values, char* suits){
    int value;
    char suit;
    for(int i = 0; i < 5; i++){
        std::cout << "Card " << i+1 << ":";
        std::cin >> value;
        values[i] = value;
        std::cout << "Suit :";
        std::cin >> suit;
        suits[i] = suit;
    }
}
void checkHand(int* values, char* suits){
    bool straight = true;
    for(int i = 0; i < 4; i++){
        if(values[i] + 1 != values[i+1]){
            straight = false;
            break;
        }
    }
    bool flush = true;
    for(int i = 0; i < 4; i++){
        if(suits[i] != suits[i+1]){
            flush = false;
            break;
        }
    }

    int count;
    bool onePair = false, twoPair = false,
         threeKind = false, fourKind = false;
    for(int i = 0; i < 5; i++){
        count = 1;
        for(int j = i+1; j < 5; j++){
            if(values[i] == values[j]) count ++;
        }
        switch(count){
            case 2: onePair? twoPair = true : onePair = true; break;
            case 3: threeKind = true; break;
            case 4: fourKind = true; break;
        }
    }

    if(fourKind) std:cout << "Four of a Kind!";
    else if(onePair && threeKind) std::cout << "Full House!";
    else if(threeKind) std::cout << "Three of a Kind";
    else if(twoPair) std::cout << "Two Pairs!";
    else if(onePair) std::cout << "One Pair!";
    else if(straight && flush) std::cout << "Straight Flush!";
    else if(straight) std::cout << "Straight!";
    else if(flush) std::cout << "Flush!";
    else std::cout << "Nothing!";
    std::cout << endl;
}


void ch7ProgProject10() {
	/*. Write a program that will allow two users to play tic-tac-toe. The program
	should ask for moves alternately from player X and player O. The program
	displays the game positions as follows:
		1 2 3
		4 5 6
		7 8 9

	The players enter their moves by entering the position number they wish
	to mark. After each move, the program displays the changed board. A
	sample board configuration is as follows:

		X X O
		4 5 6
		O 8 9*/

	string game[3][3] = { {"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"} };
	int round = 0, p1score = 0, p2score = 0;
	int move;
	char repeat;
	bool player1 = true, p1win = false, p2win = false;

	do {

		cout << "[SCORE]\n"
			<< "Player 1: " << p1score << "\t" 
			<< "Player 2: " << p2score << endl << endl;
		
		while (round < 5 && !p1win && !p2win) {

			gameState(game);

			if (player1) {
				round++;
				//Ensures output is valid
				do {
					cout << "Player 1: ";
					cin >> move;
				} while (move < 1 || move > 9);

				//Updates game array and triggers player flag
				makePlay(game, move, "X");
				player1 = false;

				//Checks if the game is over
				if (round >= 3) p1win = checkWin(game, "X");
			}
			else {
				do {
					cout << "Player 2: ";
					cin >> move;
				} while (move < 1 || move > 9);

				makePlay(game, move, "O");
				player1 = true;

				if (round >= 3) p2win = checkWin(game, "O");
			}


			cout << endl;
		}

		gameState(game);

		if (p1win) {
			cout << "Player 1 Wins!\n";
			p1score++;
		}
		else if (p2win) {
			cout << "Pleyr 2 Wins!\n";
			p2score++;
		}
		else cout << "It's a tie!\n";

		do {
			cout << "Play again (y/n)? ";
			cin >> repeat;
		} while (repeat != 'n' && repeat != 'N' &&
			repeat != 'y' && repeat != 'Y');

	} while (repeat != 'n' && repeat != 'N');

}
void gameState(string arr[][3]) {
	//Prints the game state onto the console
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
void makePlay(string arr[][3], int pos, string play) {
	//Reads the player's input and updates map accordingly
	switch (pos) {
	case 1: arr[0][0] = play; break;
	case 2: arr[0][1] = play; break;
	case 3: arr[0][2] = play; break;
	case 4: arr[1][0] = play; break;
	case 5: arr[1][1] = play; break;
	case 6: arr[1][2] = play; break;
	case 7: arr[2][0] = play; break;
	case 8: arr[2][1] = play; break;
	case 9: arr[2][2] = play; break;
	}
}
bool checkWin(string arr[][3], string player) {
	//Checks different combinations to see if anyone has won
	if (arr[1][1] == player) {
		if ((arr[0][0] == player && arr[2][2] == player) ||
			(arr[2][0] == player && arr[0][2] == player) ||
			(arr[0][1] == player && arr[2][1] == player) ||
			(arr[1][0] == player && arr[1][2] == player)) {
			return true;
		}
	}
	else if (arr[0][0] == player) {
		if ((arr[0][1] == player && arr[0][2] == player) ||
			(arr[1][0] == player && arr[2][0] == player)) {
			return true;
		}
	}
	else if (arr[2][2] == player) {
		if ((arr[0][2] == player && arr[1][2] == player) ||
			(arr[2][0] == player && arr[2][1] == player)) {
			return true;
		}
	}
	return false;
}


void ch7ProgProject11(){
    /*Write a program to assign passengers seats in an airplane. Assume a small
      airplane with seat numbering as follows:

        1 A B C D
        2 A B C D
        3 A B C D
        4 A B C D
        5 A B C D
        6 A B C D
        7 A B C D

      The program should display the seat pattern, with an X marking the seats
      already assigned. For example, after seats 1A, 2B, and 4C are taken, the
      display should look like this:

        1 X B C D
        2 A X C D
        3 A B C D
        4 A B X D
        5 A B C D
        6 A B C D
        7 A B C D

      After displaying the seats available, the program prompts for the seat
      desired, the user types in a seat, and then the display of available seats is
      updated. This continues until all seats are filled or until the user signals
      that the program should end. If the user types in a seat that is already
      assigned, the program should say that that seat is occupied and ask for
      another choice. */
#define PP11ROWS 7
#define PP11COLS 4
    bool* seats[PP11ROWS], flag = true;
    for(int i = 0; i < PP11ROWS; i++) {
        seats[i] = new bool[PP11COLS];
        for(int j = 0; j < PP11COLS; j++){
            seats[i][j] = true;
        }
    }


    std::string in;
    char opt;
    while(flag) {
        printSeats(seats);
        while (true) {
            std::cout << "Enter booked seat: ";
            cin >> in;
            in[1] = toupper(in[1]);
            if (in.size() > 2 || !isdigit(in[0]) || (in[0] - '0') == 0
                || (in[0] - '0') > 7 || in[1] < 'A' || in[1] > 'D')
                std::cout << "Invalid seat\nChoose a seat between [1-7][A-D]\n";
            else break;
        }

        if (bookSeat(seats, in)) {
            printSeats(seats);
            while (true) {
                std::cout << "Continue?[y/n]";
                cin >> opt;
                opt = toupper(opt);
                if (opt == 'Y') break;
                if (opt == 'N') {
                    flag = false;
                    break;
                }
            }
        } else {
            std::cout << "That seat is alreaady taken\nPlease chose an available seat:\n";
        }
    }
}

bool bookSeat(bool* seats[], std::string in){
    bool toReturn;
    int row = in[0] - '0' - 1;
    int col = in[1] - 'A';
    toReturn = seats[row][col];
    seats[row][col] = false;
    return toReturn;
}
void printSeats(bool* seats[]){
    for(int i = 0; i < PP11ROWS; i++){
        std::cout << i+1 << " ";
        for(int j = 0; j < PP11COLS; j++) {
            char out = j + 'A';
            if (seats[i][j]) std::cout << out << " ";
            else std::cout << "X ";
        }
        std::cout << '\n';
    }
}

void ch7ProgProject12();


void ch7ProgProject13();


void ch7ProgProject14();


void ch7ProgProject15();


void ch7ProgProject16();


void ch7ProgProject17();


void ch7ProgProject18();


void ch7ProgProject19();


void ch7ProgProject20();
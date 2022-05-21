#include "chapter6.h"

const int NUMBER_OF_CHAPTERS = 17;

//Self-Test
void copy_char(istream& in) {
	char c;
	in.get(c);
	cout << c << endl;
}

void copy_line(istream& in) {
	char next;
	do {
		in.get(next);
		cout << next;
	} while (next != '\n');
}

void send_line(ostream& out){
	char next;
	do {
		cin.get(next);
		out << next;
	} while (next != '\n');
}

void text_to_screen(ifstream& in) {
	char next;
	in.get(next);
	while (!in.eof()) {
		cout.put(next);
		in.get(next);
	}
}

void upper_deleted(istream& in) {
	char next;
	in.get(next);
	while(next != '\n'){
		if (!isupper(next)) cout << next;
	}
}



void ch6Exercise1(){
	/*Write a program that will search a file of numbers of type int and write the 
	largest and the smallest numbers to the screen. The file contains nothing 
	but numbers of type int separated by blanks or line breaks. If this is being 
	done as a class assignment, obtain the file name from your instructor.*/
	int num, max = 0, min = 0;

	ifstream infile;
	infile.open("chapter6\\ex1numbers.txt");

	if (infile.fail()) {
		cout << "Error opening file!\n";
		exit(1);
	}

	while (infile >> num) {
		if (num > max) max = num;
		if (num < min) min = num;
	}

	cout << "Largest value: " << max << endl
		<< "Smallest value: " << min << endl;	
}



void ch6Exercise2() {
	/* Write a program that takes its input from a file of numbers of type double
	and outputs the average of the numbers in the file to the screen. The file 
	contains nothing but numbers of type double separated by blanks and/or 
	line breaks. If this is being done as a class assignment, obtain the file name 
	from your instructor.*/
	double load, avg,
		sum = 0;
	int count = 0;
	ifstream infile;
	infile.open("chapter6\\ex2numbers.txt");
	
	if (infile.fail()) {
		cout << "Error opening file\n";
		exit(1);
	}

	while (infile >> load) {
		sum += load;
		count++;
	}

	avg = sum / count;

	cout << "The average is: " << avg << endl;
}



void ch6Exercise3(){
	/* a. Compute the median of a data file. The median is the number that 
	has the same number of data elements greater than the number as 
	there are less than the number. For purposes of this problem, you are 
	to assume that the data is sorted (that is, is in increasing order). The 
	median is the middle element of the file if there are an odd number 
	of elements, or the average of the two middle elements if the file has 
	an even number of elements. You will need to open the file, count 
	the elements, close the file and calculate the location of the middle 
	of the file, open the file again (recall the “start over” discussion in 
	this chapter), count up to the file entries you need, and calculate the 
	middle.
	If your instructor has assigned this problem, ask for a data file to test 
	your program with. Otherwise, construct several files on your own, including 
	one with an even number of data points, increasing, and one with an odd number, 
	also increasing.
	
	b.  For a sorted file, a quartile is one of three numbers: The first has 
	one-fourth the data values less than or equal to it, one-fourth the data 
	values between the first and second numbers, one-fourth the data points between 
	the second and the third, and one-fourth above the third quartile. 
	Find the three quartiles for the data file you used for part (a).
	(Hint: You should recognize that having done part (a) you have one-third 
	of your job done—you have the second quartile already. You also 
	should recognize that you have done almost all the work toward finding 
	the other two quartiles as well.)*/
	int count = 0;
	int num = 0;
	int i = 0;
	double median = 0;
	double firstQuart = 0, thirdQuart = 0;
	bool odd;
	string fileName = "chapter6\\ex3data1.txt";
	ifstream infile;

	infile.open(fileName);

	if (infile.fail()) {
		cout << "Error opening file!";
		exit(1);
	}

	while (infile >> num) {
		count++;
	}

	infile.close();


	if (count % 2 == 1) {
		odd = true;
	}
	else odd = false;

	infile.open(fileName);

	if (odd) {
		while (infile >> num) {
			if (i == count / 4)
				firstQuart = num;
			else if (i == count / 2)
				median = num;
			else if (i == (count * 3) / 4)
				thirdQuart = num;
			i++;
		}
	}
	else {
		while (infile >> num) {
			if (i == count / 4 - 1) {
				infile >> firstQuart;
				firstQuart += num;
				firstQuart /= 2;
			}
			else if (i == count / 2 - 2) {
				infile >> median;
				median += num;
				median /= 2;
			}
			else if (i == (count * 3) / 4 - 2) {
				infile >> thirdQuart;
				thirdQuart += num;
				thirdQuart /= 2;
			}
			i++;
		}
	}

	cout << "First Quartile: " << firstQuart << endl
		<< "Second Quartile: " << median << endl
		<< "Third Quartile: " << thirdQuart << endl;
}



void ch6Exercise4(){
	/*Write a program that takes its input from a file of numbers of type double. 
	The program outputs to the screen the average and standard deviation of 
	the numbers in the file. The file contains nothing but numbers of type 
	double separated by blanks and/or line breaks. The standard deviation of 
	a list of numbers n1, n2, n3, and so forth is defined as the square root of the 
	average of the following numbers:
		
		(n1 – a)^2, (n2 – a)^2, (n3 – a)^2, and so forth

	The number a is the average of the numbers n1, n2, n3, and so forth. 
	If this is being done as a class assignment, obtain the file name from 
	your instructor.
	(Hint: Write your program so that it first reads the entire file and computes 
	the average of all the numbers, and then closes the file, then 
	reopens the file and computes the standard deviation.*/
	int count = 0;
	double avg = 0,
		stDev = 0,
		num = 0;
	string fileName = "chapter6\\ex4data.txt";
	ifstream infile;

	infile.open(fileName);
	if (infile.fail()) {
		cout << "File doesn't exist\n";
		exit(1);
	}

	while (infile >> num) {
		avg += num;
		count++;
	}

	infile.close();
	avg /= count;

	infile.open(fileName);
	
	while (infile >> num) {
		stDev += pow(num - avg, 2);
	}
	
	infile.close();
	stDev /= count;
	stDev = sqrt(stDev);

	cout << "Avg: " << avg << endl
		<< "StDev: " << stDev << endl;

}



void ch6Exercise5(){
	/*Write a program that gives and takes advice on program writing. The program 
	starts by writing a piece of advice to the screen and asking the user to 
	type in a different piece of advice. The program then ends. The next person 
	to run the program receives the advice given by the person who last ran 
	the program. The advice is kept in a file, and the contents of the file change 
	after each run of the program. You can use your editor to enter the initial 
	piece of advice in the file so that the first person who runs the program 
	receives some advice. Allow the user to type in advice of any length so that 
	it can be any number of lines long. The user is told to end his or her advice 
	by pressing the Return key two times. Your program can then test to see 
	that it has reached the end of the input by checking to see when it reads 
	two consecutive occurrences of the character '\n'.*/
	string fileName = "chapter6\\ex5data.txt",
		advice;
	ifstream infile;
	ofstream outfile;

	infile.open(fileName);
	if (infile.fail()) {
		cout << "File does not exist\n";
		exit(1);
	}
	getline(infile, advice);
	infile.close();

	cout << advice << endl << "$";
	getline(cin, advice);

	outfile.open(fileName);
	outfile << advice;
	outfile.close();
}



void ch6Exercise6(){
	/*Write a program that reads text from one file and writes an edited version 
	of the same text to another file. The edited version is identical to the unedited 
	version except that every string of two or more consecutive blanks 
	is replaced by a single blank. Thus, the text is edited to remove any extra 
	blank characters. Your program should define a function that is called with 
	the input- and output-file streams as arguments. If this is being done as a 
	class assignment, obtain the file names from your instructor*/
	string infileName = "chapter6\\ex6data.txt",
		outfileName = "chapter6\\ex6out.txt";
	ifstream infile;
	ofstream outfile;
	string next;

	infile.open(infileName);
	if (infile.fail()) {
		cout << "Error opening infile\n";
		exit(1);
	}
	outfile.open(outfileName);
	if (outfile.fail()) {
		cout << "Error opening outfile\n";
		exit(1);
	}
	
	removeDoubleSpace(infile, outfile);

	infile.close();
	outfile.close();
}
void removeDoubleSpace(ifstream& istream, ofstream& ostream) {
	char next;
	bool space = false;
	istream.get(next);
	while (!istream.eof()){
		if (!space && next == ' ') {
			space = true;
			ostream << next;
		}
		else if (next == '\t') {
			if (!space) {
				space = true;
				ostream << " ";
			}
		}
		else if (!space || (space && next != ' ')) {
			ostream << next;
			space = false;
		}
		istream.get(next);
	}
}



void ch6Exercise7(){
	/* Write a program that merges the numbers in two files and writes all the 
	numbers into a third file. Your program takes input from two different 
	files and writes its output to a third file. Each input file contains a list of 
	numbers of type int in sorted order from the smallest to the largest. After 
	the program is run, the output file will contain all the numbers in the two 
	input files in one longer list in sorted order from smallest to largest. Your 
	program should define a function that is called with the two input-file 
	streams and the output-file stream as three arguments. If this is being done 
	as a class assignment, obtain the file names from your instructor*/
	ifstream infile1, infile2;
	ofstream outfile;
	string infileName1 = "chapter6\\ex7data1.txt",
		infileName2 = "chapter6\\ex7data2.txt",
		outfileName = "chapter6\\ex7out.txt";

	infile1.open(infileName1);
	if (infile1.fail()) {
		cout << "Error opening infile 1\n";
		exit(1);
	}
	infile2.open(infileName2);
	if (infile2.fail()) {
		cout << "Error opening infile 2\n";
		exit(1);
	}
	outfile.open(outfileName);
	if (outfile.fail()) {
		cout << "Error opening outfile\n";
		exit(1);
	}

	mergeFiles(infile1, infile2, outfile);

	infile1.close();
	infile2.close();
	outfile.close();
}
void mergeFiles(ifstream& istream1, ifstream& istream2, ofstream& ostream) {
	int num1, num2;
	bool file1 = true,
		file2 = true;

	istream1 >> num1;
	istream2 >> num2;
	
	while (file1 || file2) {
		if (istream1.eof()) file1 = false;
		if (istream2.eof()) file2 = false;
		if (num1 < num2) ostream << num1 << "\n" << num2 << "\n";
		else ostream << num2 << "\n" << num1 << "\n";

		istream1 >> num1;
		istream2 >> num2;
	}
}



void ch6ProgProject1(){
	/*Write a program to generate personalized junk mail. The program takes 
	input both from an input file and from the keyboard. The input file contains 
	the text of a letter, except that the name of the recipient is indicated 
	by the three characters #N#. The program asks the user for a name and then 
	writes the letter to a second file but with the three letters #N# replaced by 
	the name. The three-letter string #N# will occur exactly once in the letter.
	(Hint: Have your program read from the input file until it encounters the three 
	characters #N#, and have it copy what it reads to the output file as it goes. 
	When it encounters the three letters #N#, it then sends output to the screen 
	asking for the name from the keyboard. 
	You should be able to figure out the rest of the details. Your program 
	should define a function that is called with the input- and output-file 
	streams as arguments. If this is being done as a class assignment, obtain 
	the file names from your instructor.)
	Harder version (using material in the optional section “File Names as 
	Input”): Allow the string #N# to occur any number of times in the file. 
	In this case, the name is stored in two string variables. For this version, 
	assume that there is a first name and last name but no middle names 
	or initials*/
	ifstream infile;
	ofstream outfile;
	string infileName = "chapter6\\pp1data.txt";
	string outfileName = "chapter6\\pp1out.txt";
	char next;
	string userName;
	string userLast;

	infile.open(infileName);
	if (infile.fail()) {
		cout << "Error opening infile\n";
		exit(1);
	}
	outfile.open(outfileName);
	if (outfile.fail()) {
		cout << "Error opening outfile\n";
		exit(1);
	}

	cout << "$";
	cin >> userName >> userLast;

	while (infile.get(next)) {
		if (next == '#'){
			if (infile.peek() == 'N') {
				infile.get(next);
				if (infile.peek() == '#') {
					infile.get(next);
					outfile << userName;
				}
				else if (infile.peek() == 'L') {
					infile.get(next);
					if (infile.peek() == '#') {
						infile.get(next);
						outfile << userName << " " << userLast;
					}
				}
			}
			else if(infile.peek() == 'L'){
				infile.get(next);
				if (infile.peek() == '#') {
					infile.get(next);
					outfile << userLast;
				}
			}
			else outfile << next;
		}
		else outfile << next;
	}

	infile.close();
	outfile.close();
}



void ch6ProgProject2(){
	/*. Write a program to compute numeric grades for a course. The course records 
	are in a file that will serve as the input file. The input file is in exactly the 
	following format: Each line contains a student’s last name, then one space, then 
	the student’s first name, then one space, then ten quiz scores all on one line. 
	The quiz scores are whole numbers and are separated by one space. Your 
	program will take its input from this file and send its output to a second file. 
	The data in the output file will be the same as the data in the input file except 
	that there will be one additional number (of type double) at the end of each 
	line. This number will be the average of the student’s ten quiz scores. If this is 
	being done as a class assignment, obtain the file names from your instructor. 
	Use at least one function that has file streams as all or some of its arguments.*/
	
	ifstream infile("chapter6//pp2data.txt");
	if (infile.fail()) {
		cout << "Error opening infile\n";
		return;
	}

	ofstream outfile("chapter6//pp2out.txt");
	if (outfile.fail()) {
		cout << "Error opening outfile\n";
		return;
	}

	string line;
	int num, nGrades = 10;
	double avg = 0;
	char c;

	while (infile.get(c)){
		if (c != '\n') {
			outfile.put(c);
			num = 0;
			if (isdigit(c)) {
				num = c - '0';
				if (isdigit(infile.peek())) {
					infile.get(c);
					outfile.put(c);
					num *= 10;
					num += c - '0';
				}
				avg += num;
			}
		}
		else {
			avg /= (double)nGrades;
			outfile << " " << avg;
			outfile.put(c);

		}
		
	}
	
}



void ch6ProgProject3(){
	/* Enhance the program you wrote for Programming Project 2 in all of the 
	following ways.
 
		a. The list of quiz scores on each line will contain ten or fewer quiz scores. 
		(If there are fewer than ten quiz scores, that means the student missed 
		one or more quizzes.) The average score is still the sum of the quiz 
		scores divided by 10. This amounts to giving the student a 0 for any 
		missed quiz.
 
		b. The output file will contain a line (or lines) at the beginning of the file 
		explaining the output. Use formatting instructions to make the layout 
		neat and easy to read.
 
		c. After placing the desired output in an output file, your program will close 
		all files and then copy the contents of the “output” file to the “input” file 
		so that the net effect is to change the contents of the input file.

	Use at least two functions that have file streams as all or some of their 
	arguments. If this is being done as a class assignment, obtain the file 
	names from your instructor*/

	ifstream infile("chapter6//pp2data.txt");
	if (infile.fail()) {
		cout << "Error opening infile\n";
		return;
	}

	ofstream outfile("chapter6//pp2out.txt");
	if (outfile.fail()) {
		cout << "Error opening outfile\n";
		return;
	}

	string line;
	int num, nGrades = 10;
	double avg = 0;
	char c;

	while (infile.get(c)) {
		if (c != '\n') {
			outfile.put(c);
			num = 0;
			if (isdigit(c)) {
				num = c - '0';
				if (isdigit(infile.peek())) {
					infile.get(c);
					outfile.put(c);
					num *= 10;
					num += c - '0';
				}
				avg += num;
			}
		}
		else {
			avg /= (double)nGrades;
			outfile << " " << avg;
			outfile.put(c);

		}

	}

}



void ch6ProgProject4(){
	/*Write a program that will compute the average word length (average 
	number of characters per word) for a file that contains some text. A word is 
	defined to be any string of symbols that is preceded and followed by one 
	of the following at each end: a blank, a comma, a period, the beginning of 
	a line, or the end of a line. Your program should define a function that is 
	called with the input-file stream as an argument. This function should also 
	work with the stream cin as the input stream, although the function will 
	not be called with cin as an argument in this program. If this is being done 
	as a class assignment, obtain the file names from your instructor*/
	ifstream infile("chapter6//pp4data.txt");
	if (infile.fail()) {
		cout << "Error opening infile\n";
		return;
	}
	vector<string> words;
	double wordLength = 0;
	
	getWords(infile, words);
	for (unsigned int i = 0; i < words.size(); i++)
		wordLength += words[i].length();

	wordLength /= words.size();

	cout << "The average word length is " << wordLength << endl;
	
}
void getWords(ifstream& infile, vector<string>& output) {
	string line;
	int last;

	while (getline(infile, line)) {
		last = 0;
		for (unsigned int i = 0; i < line.size(); i++) {
			if ((last == 0 || isWord(line[last])) && isWord(line[i])) {
				if(last != 0) last++;
				if (last != i) {
					output.push_back(line.substr(last, i - last));
					last = i;
				}
			}
		}
	}

}
bool isWord(char c) {
	return c == ' ' || c == ',' || c == '.' || c == '(' || c == ')' || c == '[' 
		|| c == ']' || c == '{' || c == '}' || c == '\n';
}



void ch6ProgProject5(){
	/*rite a program that will correct a C++ program that has errors in which 
	operator, << or >>, it uses with cin and cout. The program replaces each 
	(incorrect) occurrence of
		
		cin <<
	with the corrected version
 
		cin >>

	and each (incorrect) occurrence of
		
		cout >>
	
	with the corrected version
		
		cout <<
	
	For an easier version, assume that there is always exactly one blank space 
	between any occurrence of cin and a following <<, and similarly assume 
	that there is always exactly one blank space between each occurrence of 
	cout and a following >>.
	For a harder version, allow for the possibility that there may be any 
	number of blanks, even zero blanks, between cin and << and between 
	cout and >>. In this harder case, the replacement corrected version has 
	only one blank between the cin or cout and the following operator. The 
	program to be corrected is in one file and the corrected version is output 
	to a second file. Your program should define a function that is called with 
	the input- and output-file streams as arguments.
	If this is being done as a class assignment, obtain the file names from 
	your instructor and ask your instructor whether you should do the 
	easier version or the harder version.
	(Hint: Even if you are doing the harder version, you will probably find 
	it easier and quicker to first do the easier version and then modify your 
	program so that it performs the harder task.)*/
	ifstream infile("chapter6//pp5data.txt");
	if (infile.fail()) {
		cout << "Error opening infile\n";
		return;
	}
	ofstream outfile("chapter6//pp5out.txt");
	if (outfile.fail()) {
		cout << "Error opening outfile\n";
		return;
	}

	if (correctCode(infile, outfile) == 0)
		cout << "Your code has been successfuly corrected\n";
	else cout << "There was an error correcting your code\n";
}
int correctCode(ifstream& infile, ofstream& outfile) {
	string line;
	while (getline(infile, line)) {
		for (unsigned int i = 0; i < line.size(); i++) {
			if (line[i] == ' '){
				if (line.substr(1, i) == "cout")
					correctCall(line, true);
				else if (line.substr(1, i) == "cin")
					correctCall(line, false);
				else break;
			}
		}
		outfile << line << endl;
	}
	return 0;
}
void correctCall(string& line, bool out) {
	stringstream ss;
	string word;
	int last = 0;
	for (unsigned int i = 0; i < line.size(); i++) {
		if (line[i] == ' ' || i == line.size()-1) {
			word = line.substr(last, i - last);
			if (word == ">>" && out)
				ss << "<<";
			else if (word == "<<" && !out)
				ss << ">>";
			else ss << word;
			if (i < line.size()) ss << " ";
			last = i + 1;
		}
	}
	line = ss.str();
}


void ch6ProgProject6(){
	/*. Write a program that allows the user to type in any one-line question and 
	then answers that question. The program will not really pay any attention 
	to the question, but will simply read the question line and discard all that 
	it reads. It always gives one of the following answers:
		
		I'm not sure, but I think you will find the answer in Chapter #N.
		That's a good question.
		If I were you, I would not worry about such things.
		That question has puzzled philosophers for centuries.
		I don't know. I'm just a machine.
		Think about it and the answer will come to you.
		I used to know the answer to that question, but I've forgotten it.
		The answer can be found in a secret place in the woods.
	
	These answers are stored in a file (one answer per line), and your program 
	simply reads the next answer from the file and writes it out as the answer 
	to the question. After your program has read the entire file, it simply 
	closes the file, reopens the file, and starts down the list of answers again.
	Whenever your program outputs the first answer, it should replace 
	the two symbols #N with a number between 1 and 18 (including the 
	possibility of 1 and 18). In order to choose a number between 1 and 18, 
	your program should initialize a variable to 18 and decrease the variable’s 
	value by 1 each time it outputs a number so that the chapter numbers 
	count backward from 18 to 1. When the variable reaches the value 0, 
	your program should change its value back to 18. Give the number 17 
	the name NUMBER_OF_CHAPTERS with a global named constant declaration 
	using the const modifier.
		(Hint: Use the function new_line defined in this chapter.)*/
	string question;
	ifstream infile("chapter6//pp6data.txt");
	int answerNo, chapterNo;
	chapterNo = NUMBER_OF_CHAPTERS;
	answerNo = 0;

	do {
		answerNo %= 7;
		cout << "$ ";
		getline(cin, question);
		getline(infile, question);
		//Resets answer file if it reaches the end
		if (infile.eof()) {
			infile.close();
			infile.open("chapter6//pp6data.txt");
			getline(infile, question);
		}
		//Changes the #N placeholder in the first question
		if (answerNo == 0) {
			stringstream ss;
			for (unsigned int i = 0; i < question.size(); i++) {
				if (question.substr(i, 2) == "#N") {
					ss << question.substr(0, i) << chapterNo + 1;
					chapterNo--;
				}
			}
			question = ss.str();
		}
		cout << question << endl;
		answerNo++;
		//Resets the chapter counter
		if (chapterNo == 0) chapterNo = NUMBER_OF_CHAPTERS;

	} while (question != "-exit");
	
}


void ch6ProgProject7() {
	/*This project is the same as Programming Project 6, except that in this
	project your program will use a more sophisticated method for choosing
	the answer to a question. When your program reads a question, it counts
	the number of characters in the question and stores the number in a variable
	named count. It then responds with answer number count % ANSWERS. The
	first answer in the file is answer number 0, the next is answer number 1, then
	2, and so forth. ANSWERS is defined in a constant declaration, as shown next,
	so that it is equal to the number of answers in the answer file:

		const int ANSWERS = 8;

	This way you can change the answer file so that it contains more or fewer
	answers and you need change only the constant declaration to make
	your program work correctly for a different number of possible answers.
	Assume that the answer listed first in the file will always be the following,
	even if the answer file is changed:
	I'm not sure, but I think you will find the answer in Chapter #N.
	When replacing the two characters #N with a number, use the number
	(count % NUMBER_OF_CHAPTERS + 1), where count is the variable
	discussed above, and NUMBER_OF_CHAPTERS is a global named constant
	defined to be equal to the number of chapters in this book*/
	const int ANSWERS = 8;
	string question;
	ifstream infile("chapter6//pp6data.txt");
	int answerNo, chapterNo;
	chapterNo = NUMBER_OF_CHAPTERS;
	answerNo = 0;

	do {
		cout << "$ ";
		getline(cin, question);
		answerNo = question.size() % 8;
		if (answerNo > 0) {
			for (int i = 0; i < answerNo; i++)
				getline(infile, question);
		}
		getline(infile, question);
		//Resets file
		infile.close();
		infile.open("chapter6//pp6data.txt");
		//Changes the #N placeholder in the first question
		if (answerNo == 0) {
			stringstream ss;
			for (unsigned int i = 0; i < question.size(); i++) {
				if (question.substr(i, 2) == "#N") {
					ss << question.substr(0, i) << chapterNo + 1;
					chapterNo--;
				}
			}
			question = ss.str();
		}
		cout << question << endl;
		answerNo++;
		//Resets the chapter counter
		if (chapterNo == 0) chapterNo = NUMBER_OF_CHAPTERS;

	} while (question != "-exit");

}



void ch6ProgProject8() {
	/*This program numbers the lines found in a text file. Write a program that
	reads text from a file and outputs each line to the screen and to another file
	preceded by a line number. Print the line number at the start of the line
	and right-adjusted in a field of three spaces. Follow the line number with a
	colon, then one space, then the text of the line. You should get a character
	at a time and write code to ignore leading blanks on each line. You may
	assume that the lines are short enough to fit within a line on the screen.
	Otherwise, allow default printer or screen output behavior if the line is too
	long (that is, wrap or truncate).
	A somewhat harder version determines the number of spaces needed
	in the field for the line numbers by counting lines before processing
	the lines of the file. This version of the program should insert a new
	line after the last complete word that will fit within a 72-character line*/
	int lineCount = 0,
		lineNum = 1,
		spacing;
	char c;
	bool lead = false,
		newline = true,
		overflow = false;

	ifstream infile("chapter6//pp8data.txt");
	if (infile.fail()) {
		cout << "Error opening infile\n";
		return;
	}
	ofstream outfile("chapter6//pp8out.txt");
	if (outfile.fail()) {
		cout << "Error opening outfile\n";
		return;
	}
	while (!infile.eof()) {
		infile.get(c);
		if (c == '\n') lineCount++;
	}
	infile.close();

	if (lineCount / 10 == 0) spacing = 1;
	else if (lineCount / 100 == 0) spacing = 2;
	else spacing = 3;
	lineCount = 0;

	infile.open("chapter6//pp8data.txt");
	while (!infile.eof()) {
		if (newline) {
			outfile << setw(spacing) << right << lineNum << ", ";
			newline = false;
		}
		infile.get(c);
		lineCount++;
		if (lineCount > 72) {
			overflow = true;
			if (c == ' ' || c == '\n') {
				lineCount = 0;
				cout << '\n';
				outfile.put('\n');
				lead = false;
				newline = true;
				lineNum++;
			}
			else {
				cout << c;
				outfile.put(c);
			}
		}
		else {
			if (c == '\n') {
				if (!overflow) {
					lead = false;
					newline = true;
					lineNum++;
					cout << c;
					outfile.put(c);
				}
				else overflow = false;
			}
			else if (!lead && c != ' ')
				lead = true;
			if (lead && c != '\n') {
				cout << c;
				outfile.put(c);
			}

		}
	}
	infile.close();
}



void ch6ProgProject9(){
	/*Write a program that computes all of the following statistics for a file 
	and outputs the statistics to both the screen and to another file: the total 
	number of occurrences of characters in the file, the total number of non-whitespace 
	characters in the file, and the total number of occurrences of letters in the file*/
	ifstream infile("chapter6//pp9data.txt");
	if (infile.fail()) {
		cout << "Error opening infile\n";
		return;
	}

	char c;
	int allChars = 0, 
		nonWspce = 0, 
		letters = 0;

	while (infile.get(c)) {
	
		allChars++;
		if (!isspace(c)) {
			nonWspce++;
			if (isalpha(c))
				letters++;
		}
	}
	cout << "[File Statistics]\n"
		<< setw(20) << left << "Characters:" << "\t" << allChars << endl
		<< setw(20) << left << "Non-whitespace:" << "\t" << nonWspce << endl
		<< setw(20) << left << "Letters:" << "\t" <<letters << endl;
}



void ch6ProgProject10() {
	/*The text file babynames2012.txt, which is included in the source code for
	this book and is available online from the book’s Web site, contains a list
	of the 1000 most popular boy and girl names in the United States for the
	year 2012 as compiled by the Social Security Administration.

	This is a space-delimited file of 1000 entries in which the rank is listed
	first, followed by the corresponding boy name and girl name. The most
	popular names are listed first and the least popular names are listed last.
	For example, the file begins with

		1 Jacob Sophia
		2 Mason Emma
		3 Ethan Isabella

	This indicates that Jacob is the most popular boy name and Sophia is the
	most popular girl name. Mason is the second most popular boy name and
	Emma is the second most popular girl name.

	Write a program that allows the user to input a name. The program
	should then read from the file and search for a matching name among the
	girls and boys. If a match is found, it should output the rank of the name.

	The program should also indicate if there is no match.
	For example, if the user enters the name “Justice,” then the program
	should output:

		Justice is ranked 519 in popularity among boys.
		Justice is ranked 518 in popularity among girls.

	If the user enters the name “Walter,” then the program should output:

		Walter is ranked 376 in popularity among boys.
		Walter is not ranked among the top 1000 girl names.*/
	string name, line, boyName, girlName;
	int boyCount = 0, girlCount = 0, lineCount = 0,
		firstSpace = 0, secondSpace = 0;
	bool boyFound = false, girlFound = false;

	ifstream infile("chapter6//pp10data.txt");
	if (infile.fail()) {
		cout << "Error opening infile\n";
		return;
	}

	cout << "$";
	cin >> name;
	
	while (getline(infile, line)) {
		lineCount++;
		for (unsigned int i = 0; i < line.size(); i++) {
			if (line.substr(i, 1) == " ") {
				if (firstSpace == 0)
					firstSpace = i + 1;
				else
					secondSpace = i + 1;
			}
		}

		if (!girlFound) {
			girlName = line.substr(firstSpace, secondSpace - firstSpace - 1);
			if (girlName == name) {
				girlCount = lineCount;
				girlFound = true;
			}
		}

		if (!boyFound) {
			boyName = line.substr(secondSpace);
			if (boyName == name) {
				boyCount = lineCount;
				boyFound = true;
			}
		}

		if (girlFound && boyFound) break;
		else firstSpace = secondSpace = 0;
	}


	if (boyFound)
		cout << name << " is ranked " << boyCount << " in popularity among boys.\n";
	else cout << name << " is not ranked among the top 1000 boys.\n";
	if (girlFound)
		cout << name << " is ranked " << girlCount << " in popularity among girls.\n";
	else cout << name << " is not ranked among the top 1000 girls.\n";
	
}


void ch6ProgProject11(){
	stringstream ss;
	unsigned int ret1, ret2, ret3, ret4;
	cout << "$";
	cin >> ret1 >> ret2 >> ret3 >> ret4;

	ss << "<?xml version=\"1.0\" standalone=\"no\"?>\n"
		<< "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n"
		<< "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\" >\n"
		<< "<svg width = \"500\" height = \"500\"\n"
		<< "xmlns = \"http://www.w3.org/2000/svg\">\n"
		<< "<line x1 = \"0\" y1 = \"0\" x2 = \"0\" y2 = \"500\"\n"
		<< "style = \"stroke:black;stroke-width:2\"/>\n"
		<< "<line x1 = \"0\" y1 = \"500\" x2 = \"500\" y2 = \"500\"\n"
		<< "style = \"stroke:black;stroke-width:1\"/>\n"
		<< "<rect x = \"20\" y = \"" << 500 - ret1 << "\" width = \"50\" height = \"" << ret1 << "\"\n"
		<< "style = \"fill:green;\"/>\n"
		<< "<rect x = \"160\" y = \"" << 500 - ret2 << "\" width = \"50\" height = \"" << ret2 << "\"\n"
		<< "style = \"fill:magenta;\"/>\n"
		<< "<rect x = \"300\" y = \"" << 500 - ret3 << "\" width = \"50\" height = \"" << ret3 << "\"\n"
		<< "style = \"fill:blue;\"/>\n"
		<< "<rect x = \"430\" y = \"" << 500 - ret4 << "\" width = \"50\" height = \"" << ret4 << "\"\n"
		<< "style = \"fill:purple;\"/>\n"
		<< "</svg>";

	ofstream outfile("chapter6//pp11out.svg");
	outfile << ss.str();
	outfile.close();
}



void ch6ProgProject12(){}



void ch6ProgProject13(){
	/*Write a program that prompts the user to input the name of a text file and 
	then outputs the number of words in the file. You can consider a “word” to 
	be any text that is surrounded by whitespace (for example, a space, carriage 
	return, newline) or borders the beginning or end of the file.*/
	char c;
	bool word = false;
	int wordCount = 0;

	ifstream infile("chapter6//pp13data.txt");
	if (infile.fail()) {
		cout << "Error opening infile\n";
		return;
	}

	while (infile.get(c)) {
		if (!word && isalpha(c))
			word = true;
		if (word)
			if (isspace(infile.peek()) || infile.peek() == EOF) {
				wordCount++;
				word = false;
			}
	}

	cout << "The file has " << wordCount << " words.\n";
}



void ch6ProgProject14(){
	/*The following is an old word puzzle: “Name a common word, besides 
	tremendous, stupendous and horrendous, that ends in dous.” If you think 
	about this for a while, it will probably come to you. However, we can also 
	solve this puzzle by reading a text file of English words and outputting 
	the word if it contains “dous” at the end. The text file “words.txt” contains 
	87, 314 English words, including the word that completes the puzzle. This 
	file is available online with the source code for the book. Write a program 
	that reads each word from the text file and outputs only those containing 
	“dous” at the end to solve the puzzle.*/
	string word;
	ifstream infile("chapter6//pp14data.txt");
	if (infile.fail()) {
		cout << "Error opening infile\n";
		return;
	}
	while (getline(infile, word)) {
		if (word.length() >= 4) {
			if (word.substr(word.length() - 4) == "dous")
				cout << word << endl;
		}
	}

}
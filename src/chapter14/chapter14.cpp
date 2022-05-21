#include "chapter14.h"

/**Self Tests*/
void ch14SelfTest2(){
    int n;
    std::cout << "How many asterisks? ";
    std::cin >> n;
    asterisk(n);
}
void asterisk(int n){
    if(n == 0) return;
    else{
        std::cout << "*";
        asterisk(n-1);
    }
}

void ch14SelfTest3(){
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;
    backward(n);
}
void backward(int n){
    if(n < 10) std::cout << n;
    else{
        std::cout << n % 10;
        backward(n / 10);
    }
}

void ch14SelfTest4(){
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;
    counter(n);
}
void counter(int n){
    if(n == 1) std::cout << n << ' ';
    else{
        counter(n-1);
        std::cout << n << ' ';
    }
}

void ch14SelfTest5(){
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;
    counterReverse(n);
}
void counterReverse(int n){
    if(n == 1) std::cout << n << ' ';
    else{
        std::cout << n << ' ';
        counterReverse(n-1);
    }
}

void ch14SelfTest7(){
    cheersIterative(3);
}
void cheersIterative(int n){
    while(n != 1){
        std::cout << "Hip ";
        n--;
    }
    std::cout << "Hurray!\n";
}

void ch14SelfTest8(){
    int n;
    std::cout << "How many asterisks? ";
    std::cin >> n;
    asteriskIterative(n);
}
void asteriskIterative(int n){
    for(int i = 0; i < n; i++){
        std::cout << "*";
    }
}

void ch14SelfTest9(){
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;
    backwardIterative(n);
}
void backwardIterative(int n){
    while(n != 0){
        std::cout << n % 10;
        n /= 10;
    }
}

void ch14SelfTest14(){
    int x, n;
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "To the power of ";
    std::cin >> n;
    std::cout << " is " << power(x, n);
}
double power(int x, int n){
    if(n < 0) return 1 / power(x, abs(n)-1);
    else if (n == 0) return 1;
    else return power(x, n-1) * x;
}

void ch14SelfTest15(){
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Result: " << squares(n);
}
int squares(int n){
    if(n == 1) return 1;
    else return n * n + squares(n-1);
}

void ch14SelfTest16(){
    //Will be done later - requires code from the Classes chapter, which
    //I haven't gone through yet
}

void ch14Exercise1(){
    /*Write a recursive function definition for a function that has one parameter
      n of type int and that returns the nth Fibonacci number. See Programming
      Project 6 in Chapter 3 for the definition of Fibonacci numbers. Embed the
      function in a program and test it.*/
    int n;
    std::cout << "Which term do you want? ";
    std::cin >> n;
    std::cout << recursiveFib(n);
}
int recursiveFib(int n){
    if(n == 1) return 0;
    else if(n == 2) return 1;
    else return recursiveFib(n-1) + recursiveFib(n-2);
}

void ch14Exercise2(){
    /*Write a recursive version of the function index_of_smallest that was used
      in the sorting program in Display 7.12 of Chapter 7. Embed the function
      in a program and test it*/
    int arr[10] = {12, 3, 52, 4, 42, 3, 14, 16, 1, -1};
    assert(indexOfSmallest(arr, INT_MAX, 0, 0) == 8);
}
int indexOfSmallest(const int arr[], int n, int smallIndex, int startIndex){
    if(arr[startIndex] == -1) return smallIndex;
    else if (arr[startIndex] < n){
        n = arr[startIndex];
        smallIndex = startIndex;
    }
    return indexOfSmallest(arr, n, smallIndex, ++startIndex);
}

void ch14Exercise3(){
    /* Write a recursive version of the search function in Display 7.10
       of Chapter 7.*/
    int arr[10] = {12, 3, 52, 4, 42, 5, 14, 16, 1, -1};
    assert(search(arr, 10, 3, 0) == 1);
    assert(search(arr, 10, 3, 3) == -1);
    assert(search(arr, 5, 42, 0) == 4);
    assert(search(arr, 5, 5, 0) == -1);

}
int search(const int arr[], int maxIndex, int target, int i){
    if(i >= maxIndex) return -1;
    else if (arr[i] == target) return i;
    else return search(arr, maxIndex, target, ++i);
}

void ch14Exercise4(){
    /*There are n people in a room, where n is an integer greater than or equal
      to 2. Each person shakes hands once with every other person. What is the
      total number of handshakes in the room? Write a recursive function to
      solve this problem, with the following header:

        int handshake(int n)

      where handshake(n) returns the total number of handshakes for n people
      in the room. To get you started, if there are only one or two people in the
      room, then:

        handshake(1) = 0
        handshake(2) = 1*/
    assert(handshake(3) == 1);
    assert(handshake(4) == 2);
    assert(handshake(-5) == -1);
    assert(handshake(42) == 21);
    assert(handshake(37) == 18);
}
int handshake(int n){
    if(n < 0) return -1;
    else if(n == 0) return 0;
    else if(n == 1) return 0;
    else if (n == 2) return 1;
    else return 1 + handshake(n-2);
}

void ch14Exercise5(){
    /*Write a recursive function that returns true if an input string is a
      palindrome and false if it is not. You can do this by checking if the
      first character equals the last character, and if so, make a recursive
      call with the input string minus the first and last characters. You will
      have to define a suitable stopping condition. Test your function with
      several palindromes and non-palindromes.*/
    assert(recursivePal("aabbaa"));
    assert(!recursivePal("pedro"));
    assert(recursivePal("a nut for a jar of tuna"));
    assert(!recursivePal("antonio costa"));
}
//Might look weird - had to stretch it a bit to handle spaces
bool recursivePal(std::string pal) {
    if (pal.length() <= 1) return pal == "";
    int firstIndex = 0, lastIndex = 1, adjust = 2;
    if (pal[0] != pal[pal.length() - 1]) {
        if(pal[0] == ' ') firstIndex++;
        else if (pal[pal.length()-1] == ' ') lastIndex++;
        else return false;
    }
    if(firstIndex > 0 || lastIndex > 1) adjust++;
    return pal[firstIndex] == pal[pal.length()-lastIndex]
            && recursivePal(pal.substr(++firstIndex, pal.length() - adjust));
}

void ch14ProgProject1(){
    /*The formula for computing the number of ways of choosing r different
      things from a set of n things is the following:

        C(n, r) = n!/(r! * (n – r)!)

      The factorial function n! is defined by

        n! = n* (n – 1) * (n – 2) *. . .*1

      Discover a recursive version of this formula and write a recursive function
      that computes the value of the formula. Embed the function in a program
      and test it*/
    int n, r;
    std::cout << "Enter size of set: ";
    std::cin >> n;
    std::cout << "Enter size of sample: ";
    std::cin >> r;
    std::cout << "There are " << combinations(n, r) << " possible combinations\n";
}
int combinations(int n, int r){
    return factorial(n) / (factorial(r) * factorial(n - r));
}
int factorial(int n){
    if (n == 1) return n;
    else return n * factorial(n-1);
}

void ch14ProgProject2(){
    /*Write a recursive function that has an argument that is an array of
      characters and two arguments that are bounds on array indexes. The function
      should reverse the order of those entries in the array whose indexes are
      between the two bounds. For example, if the array is

        a[0] == 'A' a[1] == 'B' a[2] == 'C' a[3] == 'D' a[4] == 'E'

      and the bounds are 1 and 4, then after the function is run the array
      elements should be

        a[0] == 'A' a[1] == 'E' a[2] == 'D' a[3] == 'C' a[4] == 'B'

      Embed the function in a program and test it. After you have fully debugged
      this function, define another function that takes a single argument which
      is an array that contains a string value and that reverses the spelling of the
      string value in the array argument. This function will include a call to the
      recursive definition you did for the first part of this project. Embed this
      second function in a program and test it*/
}
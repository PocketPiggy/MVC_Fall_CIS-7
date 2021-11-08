#include <iostream>
#include <algorithm>
using namespace std;

void prob1();
void prob2();
void prob3();
void prob4();
int fib(int);
int fib2(int);
int fib3(int);
int factorial(int);

int main(int argc, char** argv) {
    cout << "Problem 1" << endl << endl;
    prob1();
    cout << endl;

    cout << "Problem 2" << endl << endl;
    prob2();
    cout << endl;

    cout << "Problem 3" << endl << endl;
    prob3();
    cout << endl;

    cout << "Problem 4" << endl << endl;
    prob4();
    cout << endl;

    return 0;
}

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int fib2(int n) {
    int a = 0, b = 1, c, i;
    if (n == 0) {
        return a;
    }
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fib3(int n) {
    int f[n + 2], i;
    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    }
    else {
        return 1;
    }
}

void prob1() {
    int n = 11;
    cout << fib(n) << endl;
    cout << fib(18) << endl << endl;
    cout << "1a. F11 = F10 + F9, (34 + 55 = 89)." << endl;
    cout << "1b. The function is called by returning base if true. Otherwise,"
         << " it calls itself and builds off from the previous results." << endl;
};

void prob2() {
    int n = 9;
    cout << fib2(n) << endl << endl;
    cout << fib2(14) << endl << endl;
    //  Fn = F n-1 + F n - 2, though swapped
    cout << "2b. F9 = F8 + F7 = (21 + 13) = 34" << endl;
    cout << "2c. Temp variable (c), holds the sum of the values of the two previous"
         << " elements. Reassigning values through the for loop for the new fib"
         << " function, which is iterative rather than recursive." << endl;
    cout << "2d. F14 = F13 + F12" << endl;
    cout << "2e. The recursive solution does more function calls, but the iterative"
         << " solution uses memory for variables. Overall, for fibonacci"
         << " the recursive solution is more simple to understand and cleaner "
         << "in this specific instance. Otherwise it might be using more memory overall."
         << endl;
};

void prob3() {
    int n = 9;
    cout << fib3(n) << endl << endl;
    n = 18;
    cout << fib3(n) << endl << endl;
    cout << "3b. F9 = F7 + F8 = (13 + 21) = 34" << endl;
    cout << "3c. Array that stores fibonacci numbers, defines usual base case in"
         << " the first two elements of the array.";
    cout << "3e. Compared to the previous two, this one is uses an array and like"
         << " the second approach, is iterative and not recursive.";
};

void prob4() {
    int n;
    cout << "Enter a number to find factorial: ";
    cin >> n;
    cout << "Factorial of " << n << " = " << factorial(n) << endl;
    cout << "15! = " << factorial(15) << endl;
    cout << "20! = " << factorial(20) << endl;
    cout << "4b. If n is 4, f(n) = 4!, which is 24" << endl;
    cout << "4c. Checks if the number is one. If not, returns next descending"
         << " element. This is while constantly calling itself until returning 1."
         << endl;
    cout << "4e. Recursion tends to use more memory due to storing all values"
         << " until finished, and it's also usually the slower approach. It also"
         << " doesn't help that it is often harder to understand at first glance"
         << " when viewing the code." << endl;
};

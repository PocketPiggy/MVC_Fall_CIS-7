#include <iostream>  //Input/Output Library
#include <algorithm>
#include <array>
#include <cstring>

using namespace std;
//Function Prototypes

/****  Problem1 ****/
int fact(int); //  Factorial 
int nCr(int, int);
void prob1();
/****  Problem2 ****/
int binomialCoeff(int, int);
void prob2();
/****  Problem3 ****/
int binomialCoeff3(int, int);
void prob3();
/****  Problem4 ****/
int binomialCoefficients(int, int);
void prob4();

int main(int argc, char** argv) {
    //  Problem 1
    cout << "Problem 1" << endl << endl;
    //int p1_n = 5, p1_r = 3;
    //int p1_n2 = 7, p1_r2 = 4;
    //cout << nCr(p1_n, p1_r) << endl;
    //cout << nCr(p1_n2, p1_r2) << endl;
    prob1();
    cout << endl << endl;

    //  Problem 2
    cout << "Problem 2" << endl << endl;
    //int p2_n = 5, p2_r = 3;
    //int p2_n2 = 8, p2_r2 = 4;
    //cout << "The value of C(" << p2_n << ", " << p2_r << ") is: "
         //<< binomialCoeff(p2_n, p2_r) << endl;
    //cout << "The value of C(" << p2_n2 << ", " << p2_r2 << ") is: "
         //<< binomialCoeff(p2_n2, p2_r2) << endl;
    prob2();
    cout << endl << endl;

    //  Problem 3
    cout << "Problem 3" << endl << endl;
    //int p3_n = 8, p3_r = 2;
    //cout << "The value of C(" << p3_n << ", " << p3_r << ") is: "
         //<< binomialCoeff3(p3_n, p3_r) << endl;

    //int p3_n2 = 9, p3_r2 = 4;
    //cout << "The value of C(" << p3_n2 << ", " << p3_r2 << ") is: "
         //<< binomialCoeff3(p3_n2, p3_r2) << endl;
    prob3();
    cout << endl << endl;

    //  Problem 4
    cout << "Problem 4" << endl << endl;
    //  Should get 56
    //int p4_n = 8, p4_r = 5;
    //cout << "The value of C(" << p4_n << ", " << p4_r << ") is: "
         //<< binomialCoefficients(p4_n, p4_r) << endl;
    //int p4_n2 = 8, p4_r2 = 6;
    // Should get 28
    //cout << "The value of C(" << p4_n2 << ", " << p4_r2 << ") is: "
         //<< binomialCoefficients(p4_n2, p4_r2) << endl;
    prob4();
    cout << endl << endl;

    return 0;
}

/****  Problem 2 ****/
int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

int nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

void prob1() {
    int p1_n = 5, p1_r = 3;
    int p1_n2 = 7, p1_r2 = 4;
    cout << nCr(p1_n, p1_r) << endl;
    cout << nCr(p1_n2, p1_r2) << endl;
    cout << "1a. The value of n is 5, the value of r is 3." << endl;
    cout << "1b. C(7,4) formula is: 7!/((4! * (7-4!)) " << endl;
    cout << "1c. The output for C(7, 4) is: 35." << endl;
    cout << "1d. There is a factorial function, that calculates the factorial."
         << " The nCr function calls the factorial function and implements it into"
         << " the binomial coefficient." << endl;
}

/****  Problem 2 ****/
int binomialCoeff(int n, int r) {
    //  Base
    if (r == 0 || r == n) {
        return 1;
    }

    return binomialCoeff(n - 1, r - 1) + binomialCoeff(n - 1, r);
}

void prob2() {
    int p2_n = 5, p2_r = 3;
    int p2_n2 = 8, p2_r2 = 4;
    cout << "The value of C(" << p2_n << ", " << p2_r << ") is: "
         << binomialCoeff(p2_n, p2_r) << endl;
    cout << "The value of C(" << p2_n2 << ", " << p2_r2 << ") is: "
         << binomialCoeff(p2_n2, p2_r2) << endl;
    cout << "2a. The vlaue of n is 5, the value of r is 3." << endl;
    cout << "2b. C(8, 4) the formula is: (4! / (2! * 2!)) + (4! / (3! * 1))" << endl;
    cout << "2c. The output for C(8, 4) is: 70. [8! / (4! * (8 - 4)!)]" << endl;
    cout << "2d. Depends on input. A loop is linear, " 
         << endl;
}

/****  Problem 3 ****/
int binomialCoeff3(int n, int r) {

    int res = 1;

    //  C(n, r) = C(n, n - r)
    if (r > n - r) {
        r = n - r;
    }

    //  Calc value of [n * (n - 1) - (n - r + 1)] / [r * (r - 1) * 1]
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

void prob3 () {
    int p3_n = 8, p3_r = 2;
    cout << "The value of C(" << p3_n << ", " << p3_r << ") is: "
         << binomialCoeff3(p3_n, p3_r) << endl;

    int p3_n2 = 9, p3_r2 = 4;
    cout << "The value of C(" << p3_n2 << ", " << p3_r2 << ") is: "
         << binomialCoeff3(p3_n2, p3_r2) << endl;

    cout << "3a. The value of n is 8, the value of r is 2."
         << " nCr = 8! / ((2! * (8 - 2)!)) which equals 28." << endl;
    cout << "3b. C(9, 4) the formula is: nCr = 9! / ((4! * (9 - 4)!)" << endl;
    cout << "3c. " << endl;
    cout << "3d. T = r, O(r)" << endl;
    cout << "3e. I think two is the least efficient. Though since they both "
         << "depend on inputs, I think 1 is faster than 3." << endl;
}


/****  Problem 4 ****/
int binomialCoefficients(int n, int r) {
    int coef[r + 1];
    memset(coef, 0, sizeof(coef));
    coef[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--) {
            coef[j] = coef[j] + coef[j - 1];
        }
    }
    return coef[r];
}

void prob4() {
    //  Should get 56
    int p4_n = 8, p4_r = 5;
    cout << "The value of C(" << p4_n << ", " << p4_r << ") is: "
         << binomialCoefficients(p4_n, p4_r) << endl;
    int p4_n2 = 8, p4_r2 = 6;
    // Should get 28
    cout << "The value of C(" << p4_n2 << ", " << p4_r2 << ") is: "
         << binomialCoefficients(p4_n2, p4_r2) << endl;

    cout << "4a. The value of n is 8, the value of r is 5. "
         << "nCr = (8!) / (5! * (8 - 4)!) = 56" << endl;
    cout << "4b. The value of n is 8, the value of r is 6."
         << "nCr = (8!) / (6! * (8 - 6)!) = 28" << endl;
    cout << "4c. C(8, 6) = 28." << endl;
    cout << "4d. Memory. Similar to dynamic memory, using pointers you can store"
         << " the value. This trades space for time." << endl;
    cout << "4e. This program is more efficient even though it has a nested "
         << "for loop. Upon some searching, it could be due to memset and "
         << "pointer utilization." << endl;
}

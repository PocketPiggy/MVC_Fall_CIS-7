#include <iostream>
#include <algorithm>
using namespace std;

void prob1();
void prob2();
void prob3();
void prob4();
int Nth_of_AP(int, int, int);
int sumOfAP(int, int, int);
int sumOfGP(float, float, int);

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

int Nth_of_AP(int a, int d, int N) {
    //  Find Nth term, aka f(n) = a * 1 + (n - 1) * diff
    return (a + (N - 1) * d);
}

int sumOfAP(int a, int d, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum = sum + a;
        a = a + d;
    }
    return sum;
};

int sumOfGP(float a, float r, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + a;
        a = a * r;
    }
    return sum;
}

void prob1() {
    int a = 2, d = 5, N = 5;
    cout << "The " << N << "th term of the sequence is : "
         << Nth_of_AP(a, d, N) << endl;
    a = 1, d = 7, N = 15;
    cout << "New sequence 1, 8, 15, 22, 29...15th term is: "
         << Nth_of_AP(a, d, N) << endl << endl;
    // Since given t(n) = a + (n - 1) * d:
    // t(1) = 2 + (1 - 1) * 5
    // t(2) = 2 + (2 - 1) * 5 etc...
    // 5 diff, since d = 5!
    cout << "1a. t(1) = 2\tt(2) = 7\tt(3) = 12\tt(4) = 17\tt(5) = 22" << endl;
    cout << "1b. t(20) = 2 + (20 - 1) * 5 = 97" << endl;
    cout << "1c. Yes, it does match." << endl;
    cout << "1e. a = 1, d = 7, N = 15: t(15) = 99" << endl;
};

void prob2() {
    int n = 5, a = 1, d = 2;
    cout << "Arithmetic sequence sum: " << sumOfAP(a, d, n) << endl;
    n = 30, a = 4, d = 10;
    cout << "New sequence 4, 14, 24, 34, 44...sum is: " << sumOfAP(a, d, n)
         << endl << endl;
    //  T(1) = 1 + (1 - 1) * 2 = 1
    //  T(2) = 1 + (2 - 1) * 2 = 3
    //  T(3) = 1 + (3 - 1) * 2 = 5, etc.
    cout << "2a. t(1) = 1\tt(2) = 3\tt(3) = 5\tt(4) = 7\tt(5) = 9" << endl;
    cout << "2b. 1st Term = 1, Last Term = 9, Num Term = 5: (5/2) * (1 + 9) = 25"
         << endl;
    // t(30) = 4 + (30 - 1) * 10
    cout << "2c. 30th Term = 294, Arithmetic is 30/2 * (4 + 294): 4470" << endl;
};

void prob3() {
    float a, d, n, i, sum;
    cout << "Enter starting value ";
    cin >> a;
    cout << "Enter difference ";
    cin >> d;
    cout << "Enter the term ";
    cin >> n;
    cout << endl;

    for (int i = a; i < ((n) * d + a); i += d) {
        sum += i;
        cout << i << ", " << endl;
    }

    cout << sum << " is the sum." << endl;
    //  Assuming a = 3, d = 6 & n = 10
    //  t(1) = 3 + (1 - 1) * 6 = 3, etc...
    //  t(10) = 3 + (10 - 1) * 6 = 57
    //  Which means result = (10 / 2) * (3 + 57)

    cout << "3a. Sequence = {3, 9, 15, 21, 27, 33, 39, 45, 51, 57} Sum = 300"
         << endl;
    cout << "3b. The equation gets each step of the sequence, starting from 1"
         << " to the 10th. Within the for loop, the equation from the arithmetic"
         << " formula, to help get the next value of the sequence from the first."
         << endl;
};

void prob4() {
    float a = 1, r = 3, n = 7;
    cout << sumOfGP(a, r, n) << endl;
    a = 2, r = .25f, n = 8;
    cout << sumOfGP(a, r, n) << endl << endl;
    //  T(1) = 1 * (3 ^1-1) = 1
    //  T(2) = 1 * (3 ^2-1) = 3
    //  T(3) = 1 * (3 ^3-1) = 9
    //  From calc sum, 1093
    cout << "4a. 1093" << endl;
    //  t(1) = 2 * 1/4 ^1-1
    //  t(2) = 2 * 1/4 ^2-1
    //  t(3) = 2 * 1/4 ^3-1
    cout << "4c. .26" << endl;
    cout << "4d. Getting the common ratio from the previous value, then returns"
         << " the sum." << endl;
};

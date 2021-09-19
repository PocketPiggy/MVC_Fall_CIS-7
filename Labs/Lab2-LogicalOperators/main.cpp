#include <iostream>

using namespace std;

//  Function prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();

int main (int argc, char** argv) {
    //cout << "Problem 1" << endl << endl;
    //prob1();
    //cout << "Problem 2" << endl << endl;
    //prob2();
    //cout << "Problem 3" << endl << endl;
    //prob3();
    cout << "Problem 4" << endl << endl;
    prob4();
    //cout << "Problem 5" << endl << endl;
    //prob5();
}

void prob1() {
   unsigned int P = 40;
   unsigned int Q = 17;
   int result = 0;

   result = P & Q;
   cout << "Result of P&Q is : " << result << endl ;

   result = P | Q;
   cout << "Result of P|Q is: " << result << endl ;

   result = P ^ Q;
   cout << "Result of P^Q is: " << result << endl ;

   result = ~P;
   cout << "Result of ~P is: " << result << endl ;

   result = ~(P & Q);
   cout << "Result of P~&Q is: " << result << endl;

   result = ~(P | Q);
   cout << "Result of P~|Q is: " << result << endl;

   result = P << 2;
   cout << "Result of P << 2 is: " << result << endl ;

   result = P >> 2;
   cout << "Result of P >> 2 is: " << result << endl ;
}

void prob2() {
   bool b(false);
   cout << "False and !False" << endl;
   cout << b << endl;
   cout << !b << endl << endl;
   cout << "True and !True" << endl;
   cout << true << endl;
   cout << !true << endl;
}

void prob3() {
   bool b(false);
   cout << "False and !False" << endl;
   cout << b << endl;
   cout << !b << endl << endl;
   cout << "True and !True" << endl;
   cout << true << endl;
   cout << !true << endl;

   cout << boolalpha << endl;

   cout << "False and !False" << endl;
   cout << b << endl;
   cout << !b << endl << endl;
   cout << "True and !True" << endl;
   cout << true << endl;
   cout << !true << endl;
}

void prob4() {
    const float MIN_DEGREE = 60.0f;
    const int MIN_SEMES    =     5;
    //   Student units
    float units = 0.0f;
    //   Student full time semesters
    int semesters = 0;
    cout << "Enter number of units completed: ";
    cin >> units;
    cout << "Enter number of semesters completed as full-time student: ";
    cin >> semesters;
    if (!(units >= MIN_DEGREE || semesters > MIN_SEMES)) {
        cout << "You need at least 60 units to receive an Associate's degree."
             << endl;
    }
    else {
        cout << "You qualify for an Associate's degree." << endl;
    }
    cout << endl << endl;
}

void prob5() {
   char ageLimit;
   char yearDrive;
   cout << "Are you currently 21 years of age and older? (Y/N): ";
   cin >> ageLimit;
   cout << "Have you been driving longer than at least 5 years? (Y/N): ";
   cin >> yearDrive;

    if (ageLimit == 'Y' && yearDrive == 'Y') {
        cout << "You qualify for a discount.";
    }
    else {
        cout << "You must be 21+ and have driven at least 5 years.";
    }
    cout << endl << endl;
}

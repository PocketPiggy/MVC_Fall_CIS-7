//System Libraries
#include <iostream>  //Input/Output Library
#include <stdlib.h>
#include <ctime>

using namespace std;

void prob1();
void prob2();
void prob3();

int main(int argc, char** argv) {
    prob1();
    prob2();
    prob3();
    return 0;
}

void prob1() {
    cout << "Problem 1" << endl << endl << endl;
    int counter = 1;
    cout << "Six-face die, 20 rolls." << endl;
    for (int i = 1; i <= 20; i++) {
        cout << ((rand() % 6 + 1));
        //  Check if divisible by 5
        if (counter % 5 == 0) {
            cout << ("\n");
        }
        counter++;
    }
    counter = 1;
    cout << endl << endl;

    cout << "Eight-face die, 20 rolls." << endl;
    for (int i = 1; i <= 20; i++) {
        cout << ((rand() % 8 + 1));
        //  Check if divisible by 5
        if (counter % 5 == 0) {
            cout << ("\n");
        }
        counter++;
    }
    cout << endl << endl;

    counter = 1;
    cout << "Eight-face die, 40 rolls." << endl;
    for (int i = 1; i <= 40; i++) {
        cout << ((rand() % 8 + 1));
        //  Check if divisible by 5
        if (counter % 5 == 0) {
            cout << ("\n");
        }
        counter++;
    }
    cout << endl << endl;

    cout << "1a. For one roll, 1/6. (1/6)^20 in 20 rolls." << endl;
    cout << "1b. (1 - 1/6)^20 = (5/6)^20 for 20 rolls." << endl;
    cout << "1c. #2) 6, #4) 5, #2): 4, #2) 3, #6) 2, #3) 1" << endl;
    cout << "1c. #1) 2,  #2) 6, #3) 2,  #4) 2,  #5) 5,  #6) 2" << endl;
    cout << "1d. #1) 3/20,  #2) 6/20,  #3) 2/20, #4) 2/20, #5) 5/20, #6) 2" << endl;
    cout << "1e. #2 appears the most." << endl;
    cout << "1f. It produces the same result, this is because there is no seed." << endl;
    cout << "1i. #1) 2, #2) 2, #3) 4, #4) 4, #5) 0, #6) 2, #7) 3, #8) 3"<< endl;
    cout << "1j. Numbers 3 & 4 appear the most; the outcome is different than 6 face die." << endl;
    cout << "1k. #1) 2, #2) 9, #3) 3, #4) 3, #5) 7, #6) 5, #7) 7, #8) 4 = Number 2 appears most."<< endl;
    cout << endl << endl << endl;
}

void prob2() {
    cout << "Problem 2" << endl << endl;
    int frequency1 = 0;
    int frequency2 = 0;
    int frequency3 = 0;
    int frequency4 = 0;
    int frequency5 = 0;
    int frequency6 = 0;
    int roll;
    int face;
    for (roll = 1; roll <= 6000; roll++) {
        face = (rand() % 6 + 1);
        switch (face) {
            case 1:
                ++frequency1;
                break;
            case 2:
                ++frequency2;
                break;
            case 3:
                ++frequency3;
                break;
            case 4:
                ++frequency4;
                break;
            case 5:
                ++frequency5;
                break;
            case 6:
                ++frequency6;
                break;
        }
    }

    cout << "\n" << "Face   " << "Frequency";
    cout << "\n" << "Face 1 " << (frequency1);
    cout << "\n" << "Face 2 " << (frequency2);
    cout << "\n" << "Face 3 " << (frequency3);
    cout << "\n" << "Face 4 " << (frequency4);
    cout << "\n" << "Face 5 " << (frequency5);
    cout << "\n" << "Face 6 " << (frequency6);

    cout << endl << endl;


    frequency1 = frequency2 = frequency3 = frequency4 = frequency5 = frequency6 = 0;
    for (roll = 1; roll <= 100; roll++) {
        face = (rand() % 6 + 1);
        switch (face) {
            case 1:
                ++frequency1;
                break;
            case 2:
                ++frequency2;
                break;
            case 3:
                ++frequency3;
                break;
            case 4:
                ++frequency4;
                break;
            case 5:
                ++frequency5;
                break;
            case 6:
                ++frequency6;
                break;
        }
    }


    cout << "\n" << "Face   " << "Frequency";
    cout << "\n" << "Face 1 " << (frequency1);
    cout << "\n" << "Face 2 " << (frequency2);
    cout << "\n" << "Face 3 " << (frequency3);
    cout << "\n" << "Face 4 " << (frequency4);
    cout << "\n" << "Face 5 " << (frequency5);
    cout << "\n" << "Face 6 " << (frequency6);

    cout << endl;

    frequency1 = frequency2 = frequency3 = frequency4 = frequency5 = frequency6 = 0;
    for (roll = 1; roll <= 1000; roll++) {
        face = (rand() % 6 + 1);
        switch (face) {
            case 1:
                ++frequency1;
                break;
            case 2:
                ++frequency2;
                break;
            case 3:
                ++frequency3;
                break;
            case 4:
                ++frequency4;
                break;
            case 5:
                ++frequency5;
                break;
            case 6:
                ++frequency6;
                break;
        }
    }


    cout << "\n" << "Face   " << "Frequency";
    cout << "\n" << "Face 1 " << (frequency1);
    cout << "\n" << "Face 2 " << (frequency2);
    cout << "\n" << "Face 3 " << (frequency3);
    cout << "\n" << "Face 4 " << (frequency4);
    cout << "\n" << "Face 5 " << (frequency5);
    cout << "\n" << "Face 6 " << (frequency6);

    cout << endl << endl;


    cout << "2a. The program provides the same result each time." << endl;
    cout << "2b. 3rd Face appears the most. 1021/6000 -> (1/6)^6000" << endl;
    cout << "2c. 1st Face appears the least. 979/6000 -> (1/6)^6000" << endl;
    cout << "2d. 3rd Face still appears the most at 25/100. 5th face appears least at 10/100. Both are (1/6)^100" << endl;
    cout << "2e. 3rd Face still appears the most @ 189/1000. 6th Face appears least @ 146/1000. Both are (1/6)^1000)" << endl;
    cout << "2f. The use and results of rand() are the same for both exercises. The calculation is the same." << endl;
    cout << endl << endl;
}

void prob3() {
    cout << "Problem 3" << endl << endl;
    srand(time(NULL));
    int i;

    for (i = 1; i <= 10; i++) {
        cout << ( 1 + (rand() % 6));
        if (i % 5 == 0) {
            cout << "\n";
        }
    }

    cout << endl << endl;

    for (i = 1; i <= 20; i++) {
        cout << ( 1 + (rand() % 6));
        if (i % 5 == 0) {
            cout << "\n";
        }
    }

    cout << endl << endl;

    cout << "REDO THIS ALL";

    cout << "3a. No, each result is different." << endl;
    cout << "3b. (1/6)^10" << endl;
    cout << "3c. #1) 6, #2) 3, #3) 2, #4) 2, #5) 5, #6) 2" << endl;
    cout << "3d. #3, #2, #6 are the lowest. All 2/10 -> (1/6)^10" << endl;
    cout << "3e. Yes." << endl;
    cout << "3f. #3 seems to show up the most." << endl;
    cout << "3g. #4 seems to show up the least." << endl;
    cout << "3e. There seems to be more variability or different numbers show up more." << endl;
    cout << "3i. rand() isn't truly random and seems more static once generated. "
         << "srand() has a seed which is tied to current time, allowing for dynamic"
         << " results each time" << endl;



}

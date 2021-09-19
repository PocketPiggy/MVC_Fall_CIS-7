/* 
 * File:        main.cpp
 * Author:      Matthew Mickey
 * Created on:  
 * Purpose:     
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <algorithm> // For next_permutation, sort

using namespace std;

//Function Prototypes
void example1();
void prob1();
void example2();
void prob2();
void example3();
void prob3();
void example4(string, string);
void prob4();

int main(int argc, char** argv) {
    string str0 = "ABCD";
    string str1 = "ABCDEF";
    //example1();
    //cout << "Problem 1" << endl << endl;
    //prob1();
    //cout << endl << endl;
    //cout << "Problem 2" << endl << endl;
    //example2();
    //prob2();
    //cout << endl << endl;
    //cout << "Problem 3" << endl << endl;
    //example3();
    //prob3();
    //cout << endl << endl;
    cout << "Problem 4" << endl << endl;
    //example4(str0, "");
    cout << endl << endl;
    example4(str1, "");
    prob4();
    //cout << endl << endl;
    return 0;
}

void example4(string str, string out) {
    if (str.size() == 0) {
        cout << out << endl;
    }

    for (int i = 0; i < str.size(); i++) {
        //  Remove first char and put it to out
        example4(str.substr(1), out + str[0]);  //  Permute
        //  Rotate string so second char moves to beginning
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}

void example1() {
    int i = 1, len = 4;
    int myints[] = {1, 2, 3, 4,};
    //  Sort array, ascending
    sort(myints, myints + 4);

    cout << "The 4! possible permutations with 4 elements: " << endl << endl;
    do {
        cout << i << ": " << myints[0] << " " << myints[1] << " " << myints[2]
             << " " << myints[3] << endl;
        i++;
        //  Stops when array is in descending order
    } while (next_permutation(myints, myints + 4));

    cout << endl;

    cout << "After loop: ";
    for (int i = 0; i < len; i++) {
        cout << myints[i] << " ";
    }
    cout << endl << endl;
}

void prob1() {
    int i = 1, len = 4;
    int myints[] = {13, 14, 3, 4,};
    //  Sort array, ascending
    sort(myints, myints + 4);

    cout << "The 4! possible permutations with 4 elements: " << endl;
    do {
        cout << i << ": " << myints[0] << " " << myints[1] << " " << myints[2]
             << " " << myints[3] << endl;
        i++;
        //  Stops when array is in descending order
    } while (next_permutation(myints, myints + 4));

    cout << endl;

    cout << "After loop: ";
    for (int i = 0; i < len; i++) {
        cout << myints[i] << " ";
    }
    cout << endl << endl;

    cout << "1a. Calculate the variation of arrangment in Example 1 program using N!:"
         << " 4! = 4 * 3 * 2 * 1 = 24";
    cout << endl;
    cout << "1b. The arrangment of the elements are in ascending order." << endl;
    cout << "1c. Replacing the values yields the same process. We also still have 24"
         << " total permutations as the previous example.";

    cout << endl;
}

void example2() {
    int i = 1, len = 4;
    int myints[] = {1, 2, 3, 4,};
    sort(myints, myints + 4);
    reverse(myints, myints + 4);

    cout << "The 4! possible permutations with 3 elements: " << endl;

    do {
        cout << i << ": " << myints[0] << " " << myints[1] << " " << myints[2]
             << " " << myints[3] << endl;
        i++;
    } while (prev_permutation(myints, myints + 4));

    cout << "After loop: ";
    for (int i = 0; i < len; i++) {
        cout << myints[i] << " ";
    }

}

void prob2() {
    int i = 1, len = 4;
    //int myints[] = {1, 2, 3, 4,};
    int myints[] = {18, 19, 20, 4,};
    sort(myints, myints + 4);
    reverse(myints, myints + 4);

    cout << "The 4! possible permutations with 3 elements: " << endl << endl;

    do {
        cout << i << ": " << myints[0] << " " << myints[1] << " " << myints[2]
             << " " << myints[3] << endl;
        i++;
    } while (prev_permutation(myints, myints + 4));
    cout << endl;

    cout << "After loop: ";
    for (int i = 0; i < len; i++) {
        cout << myints[i] << " ";
    }
    cout << endl << endl;

    cout << "2a. Calculate the possible arrangement of numbers that the Example 2 program will display: "
         << " N = 4, 4! = 24" << endl;
    cout << "2b. Opposite of the previous example; descending." << endl;
    cout << "2c. Similar outcome. It doesn't matter what the actual value is if they're higher." 
         << " It's still going off of the position of the elements." << endl;
}

void example3() {
    int arr_A[] = {1, 5, 0, 3};
    int arr_B[] = {0, 5, 3, 1};

    //  Checks arr B includes all eles of arr A
    if (is_permutation(arr_A, arr_A + 4, arr_B)) {
        cout << "B is a permutation of A";
    }
    else {
        cout << "B is not a permutation of A";
    }

    cout << endl << endl;
}

void prob3() {
    cout << endl << endl;
    int arr_A[] = {1, 5, 0, 3, 2};
    //int arr_B[] = {2, 0, 5, 3, 1};
    int arr_B[] = {0, 5, 3, 1, 2};
    int arr_C[] = {7, 8, 9, 1, 2};  //  Second array for 3c

    //  Checks arr B includes all eles of arr A
    if (is_permutation(arr_A, arr_A + 5, arr_B)) {
        cout << "B is a permutation of A";
    }
    else {
        cout << "B is not a permutation of A";
    }


    cout << endl << endl;
    cout << "3a. Calculate the number of arrangments or permutation given arr_A ="
         << " {1, 5, 0, 3, 2}: "
         << "N = 5, N! = 120" << endl;
    cout << "3b. It says that B is a permutation of A. This is because arr_B is a"
         << " just a rearranged order of the original." << endl;
    cout << endl << endl;
    //  Lazy; Arr_C in place for Arr_B
    cout << "Now changing arr_B's elements..." << endl << endl;
    if (is_permutation(arr_A, arr_A + 5, arr_C)) {
        cout << "B is a permutation of A";
    }
    else {
        cout << "B is not a permutation of A";
    }
    cout << endl << endl;

    cout << "3c. It goes to the else branch because it's false, there are different"
         << " numbers so they're not permutations." << endl;
    cout << endl << endl;
}

//void example4(string str, string out) {
    //if (str.size() == 0) {
        //cout << out << endl;
    //}

    //for (int i = 0; i < str.size(); i++) {
        ////  Remove first char and put it to out
        //example4(str.substr(1), out + str[0]);  //  Permute
        ////  Rotate string so second char moves to beginning
        //rotate(str.begin(), str.begin() + 1, str.end());
    //}
//}

void prob4() {
    cout << "4a. N = 4, N!= 24" << endl;
    cout << "4b. They are similar, but it's not the same. Some of the orders are "
         << "higher/lower, compared to example 1. It ends at the opposite as well."
         << endl;
    cout << "4c. If six, N = 6, N! = 720. The last character moved to the front"
         << " and it becomes the middle. (From C++ docs)" << endl;
}

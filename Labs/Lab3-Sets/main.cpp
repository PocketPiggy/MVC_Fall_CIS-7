//System Libraries
#include <iostream>  // Input/Output Library
#include <set>       // Set lib
#include <iomanip>   // Formatting lib
#include <string>  // String lib

using namespace std;

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void prob10();


int main(int argc, char** argv) {
    prob1();
    prob2();
    prob3();
    prob4();
    prob5();
    prob6();
    prob7();
    prob8();
    prob9();
    prob10();

    return 0;
}

void prob1() {
    set<int> myset;
    set<int>::iterator it;
    pair<set<int>::iterator,bool> ret;

    for (int i = 1; i <= 5; i++) {
        myset.insert(i * 10);
    }

    ret = myset.insert(20);

    if (!ret.second) {
        it = ret.first;
    }

    myset.insert(it, 25);
    myset.insert(it, 24);
    myset.insert(it, 26);

    int myints[] = {5, 10, 15};
    myset.insert (myints, myints + 3);

    cout << "Example #1:  myset contains:\t";
    for (it = myset.begin(); it != myset.end(); it++) {
        cout << " " << *it; //  Pointer
    }
    cout << endl << endl;
}

void prob2() {
    set<int> myset;
    set<int>::iterator it;
    pair<set<int>::iterator,bool> ret;

    for (int i = 1; i <= 5; i++) {
        myset.insert(i * 10);
    }

    ret = myset.insert(20);

    if (!ret.second) {
        it = ret.first;
    }

    myset.insert(it, 25);
    myset.insert(it, 24);
    myset.insert(it, 26);

    int myints[] = {30, 40, 50, 60};    //  Adding needed values
    myset.insert (myints, myints + 4);  //  Inserting

    cout << "Problem #1:   myset contains:\t";
    for (it = myset.begin(); it != myset.end(); it++) {
        cout << " " << *it; //  Pointer
    }
    cout << endl;
}

void prob3() {
    cout << "Observations: 30, 40, 50 is not inserted again." << endl
         << "If keeping 5, 10, 15, the set cardinality would " << endl
         << "larger even more so." << endl << endl;
}

void prob4() {
    set<int> theSet;                    //  Actual set
    set<int>::iterator itty;            //  Iterator
    pair<set<int>::iterator,bool> ree;  //  Returns

    for (int i = 0; i <= 8; i += 2) {
        theSet.insert(i);
    }

    ree = theSet.insert(42);
    if (!ree.second) {
        itty = ree.first;
    }

    int arrInts[] = {22, 68, 94};
    theSet.insert(arrInts, arrInts + 3);

    cout << "Problem #2: theSet contains:\t";
    for (itty = theSet.begin(); itty != theSet.end(); itty++) {
        cout << " " << *itty;
    }
    cout << endl
         << "Observations: Elements are inserted in order still, just replacing previous ones.";
    cout << endl << endl;
}

void prob5() {
    int myints[] = {75, 23, 65, 42, 13};
    set<int> myset(myints, myints + 5);

    cout << "Example #2: myset contains: ";
    for (set<int>::iterator it = myset.begin(); it !=myset.end(); it++) {
        cout << " " << *it;
    }
    cout << endl;
}

void prob6() {
    cout << "Problem #3 ";
    int myints[] = {55, 23, 65, 42, 13};
    set<int> myset(myints, myints + 5);

    cout << "Example #2 CHANGED: myset contains: ";
    for (set<int>::iterator it = myset.begin(); it !=myset.end(); it++) {
        cout << " " << *it;
    }
    cout << endl;
    cout << "Observation: Changing the element has made the new element sorted/moved" 
         << endl << "into another spot.";
    cout << endl << endl;
}

void prob7() {
    int myints[] = {};
    set<int> myset(myints, myints + 3);

    cout << "Problem #4: myset contains: ";
    for (set<int>::iterator it = myset.begin(); it !=myset.end(); it++) {
        cout << " " << *it;
    }
    cout << endl;
    cout << "Observation: Addresses are show, even though it's empty set.";
    cout << endl << endl;
}

void prob8() {
    cout << "Problem #5: ";
    set<int> myset;

    myset.insert(100);
    myset.insert(200);
    myset.insert(300);

    cout << "myset contains: ";
    for (set<int>::iterator it = myset.begin(); it != myset.end(); it++) {
        cout << " " << *it;
    }
    cout << endl;

    myset.clear();
    myset.insert(1101);
    myset.insert(2202);

    cout << "myset contains: ";
    for (set<int>::iterator it = myset.begin(); it != myset.end(); it++) {
        cout << " " << *it;
    }
    cout << endl << "Observations: First set of {100, 200, 300} is cleared." << endl
         << "Since myset contains those values first, clearing it would "
         << " clear those values.";
    cout << endl << endl;
}

void prob9() {
    cout << "Problem #6: ";
    set<int> myset;

    myset.insert(100);
    myset.insert(200);
    myset.insert(300);

    cout << "myset contains: ";
    for (set<int>::iterator it = myset.begin(); it != myset.end(); it++) {
        cout << " " << *it;
    }
    cout << endl;

    //myset.clear();
    myset.insert(0);
    myset.insert(1101);
    myset.insert(2202);

    cout << "myset contains: ";
    for (set<int>::iterator it = myset.begin(); it != myset.end(); it++) {
        cout << " " << *it;
    }
    cout << endl << "Observations: Inserts 0 at beginning, clear function is removed."
         << endl;
    cout << endl;
}

void prob10() {
    cout << "Problem #7 ";
    set<int> myset;

    myset.insert(20);
    myset.insert(30);
    myset.insert(10);

    cout << "myset contains: ";
    while (!myset.empty()) {
        cout << " " << *myset.begin();
        myset.erase(myset.begin());
    }
    cout << endl;
    cout << "Observation: While condition checks if set is empty or not. If not empty," << endl
         << "then print element, then erase it. Which happens to be the first element " << endl
         << "because the previous one was already erased.";
    cout << endl;
}

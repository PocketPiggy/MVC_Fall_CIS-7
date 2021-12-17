#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
string encrypt(string, int);
string encrypt2(string, int);
char caesar(char);

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

    cout << "Problem 5" << endl << endl;
    prob5();
    cout << endl;

    return 0;
}

string encrypt(string text, int s) {
    string result = ""; 

    // traverse text 
    for (int i=0; i < text.length(); i++) {
        // apply transformation to each character 
        // Encrypt Uppercase letters 
        if (isupper(text[i])) {
            result += char(int(text[i]+s-65)%26 +65); 
        }
        // Encrypt Lowercase letters 
        else {
            result += char(int(text[i]+s-97)%26 +97); 
        }
    }

    // Return the resulting string 
    return result; 
}


void prob1() {
    string text2 = "Hello!";
    int s2 = 8;
    string text = "ATTACKATONCE";
    int s = 4;
    cout << "Text : " << text;
    cout << "\nShift: " << s;
    cout << "\nCipher: " << encrypt(text, s);
    cout << endl << endl;

    cout << "Text2 : " << text2;
    cout << "\nShift: " << s2;
    cout << "\nCipher: " << encrypt(text2, s2);
    cout << endl << endl;

    cout << "1a. - Since s is 4, it's shifted 4 times." << endl;
    cout << "1b. - On my tablet, it checks out and lands on correct letters." << endl;
    cout << "1c. - Shift value is 8, plain text is 'Hello', output is 'Pmttw]'." << endl;
    cout << "1d. - First, goes through text, next checks of case type (lower/upper),"
         << " then concats/adds to result from text with shift.";

    cout << endl << endl;
};

void prob2() {
    char message[100], ch;
    int i, key;

    cout << "Enter a message to encrypt: ";
    cin.getline(message, 100);
    cout << "Enter shift value: ";
    cin >> key;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }

    cout << "Encrypted message: " << message;
    cout << endl << endl;

    cout << "2a. - I got 'JrnerXyvatba', however the last character went out of bounds"
         << " from past 127." << endl;
    cout << "2b. - Different by checking the ascii decimal values as conditions,"
         << " rather than using inbuilt functions checking." << endl;
    cout << "2c. - Similar to the previous answer, both use loops, however the second"
         << " example uses different way, rather than using inbuilt and seperate function"
         << " to encrypt. The first is cleaner and more modular as well.";
    cout << endl << endl;
};

void prob3() {
    char message[100], ch;
    int i, key;
    //cin.clear();
    cin.ignore();
    cout << "Enter a message to decrypt: ";
    cin.getline(message, 100);
    cout << message << endl;
    cout << "Enter shift value: ";
    cin >> key;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch > 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch > 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }

    cout << "Decrypted message: " << message;
    cout << endl << endl;

    cout << "3a. - I got only '=', similar results with other strings/shift combinations."
         << endl;
    cout << "3b. - The program has problems with boundaries, or rather the correct"
         << " boundaries being set, to stay within alphabet. Some shifts aren't handled"
         << " right either. (I also had to add a cin.ignore due to buffer problem)" << endl;
    cout << "3c. - Compared to exercise 2, the boundaries for this one definitely need"
         << " to be fixed. Otherwise the decryption result will never return back to the"
         << " original plain text." << endl;
    cout << endl << endl;
};

void prob4() {
    string Source;
    int Key;

    cin.ignore();
    cout<<"Input message: ";
    getline(cin, Source);

    cout<<"Input shift key: ";
    cin>> Key;

    cout<<"Encrypted: "<< encrypt2(Source, Key) << endl << endl;

    cout << "4a. - 'substitution' -> 'xzgxynyzynts'" << endl;
    cout << "4b. - Gets user input, then uses Encrypt function to manipulate the string"
         << "by going through it with a loop, and shifting it past with the amount of given"
         << " shifting value (key).";
    cout << "4c. - This program is the best in my opinion. It has less boundary problems compared"
         << " to the 3rd example. It's modular like the 1st (with use of seperate functions)," 
         << " and it's readability is higher. Overall, 4th is best, 3rd is worst." << endl;
};

string encrypt2(string Source, int Key) {
    string Crypted = Source;

    for(int Current = 0; Current < Source.length(); Current++)
        Crypted[Current] += Key;

    return Crypted;
}

char caesar(char c) {
    if( isalpha(c))
    {
        c = toupper(c); //use upper to keep from having to use two seperate for A..Z a..z
        c = (((c-65)+13) % 26) + 65;
    }
    //if c isn't alpha, just send it back.
    return c;
}

void prob5() {
    string input;
    cin.ignore();
    do {
        cout << "Enter ciphertext and press enter to continue." << endl;
        cout << "Enter blank line to quit." << endl;
        getline(cin, input);
        string output = "";
        for(int x = 0; x < input.length(); x++)
        {
            output += caesar(input[x]);
        }
        cout << output << endl;
    } while (input.length() != 0);

    cout << endl << endl;
    cout << "5a. - Shift value is 13 and doesn't encrypt symbols." << endl;
    cout << "5b. - 'characters' -> PUNENPGREF is accurate, though it's forced all upper." << endl;
    cout << "5c. - Checks if input is from alphabet, if so, then will start cipher. Will first"
         << " force uppercase. Then will go into the boundary which is result - 65 ('A') +"
         << " shift of 13, mod via alphabet + ('A') again." << endl;
    cout << "5d. - This is the most efficient, however not the best in terms of functionality."
         << " For example, it forces all input to be outputted to uppercase." << endl;
    cout << endl << endl;
};

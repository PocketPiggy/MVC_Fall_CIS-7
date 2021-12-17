#include<bits/stdc++.h>
using namespace std;

// the function "genKey" generates the key in a cyclic manner
string genKey(string str, string key)
{
   int z = str.size();

   for (int i = 0; ; i++)
   {
       if (z == i)
           i = 0;
       if (key.size() == str.size())
           break;
       key.push_back(key[i]);
   }
   return key;
}

// This function returns the encrypted text
string encryptedText(string str, string key)
{
   string encrypted_text;

   for (int i = 0; i < str.size(); i++)
   {
       // converting in range 0-25
       char z = (str[i] + key[i]) %26;

       // convert into alphabets(ASCII)
z += 'A';

encrypted_text.push_back(z);
   }
   return encrypted_text;
}

// This function decrypts the encrypted text and returns the original text
string originalText(string encrypted_text, string key)
{
   string orig_text;

   for (int i = 0 ; i < encrypted_text.size(); i++)
   {
       // converting in range 0-25
       char z = (encrypted_text[i] - key[i] + 26) %26;

       // convert into alphabets(ASCII)
z += 'A';
       orig_text.push_back(z);
   }
   return orig_text;
}

// Driver program to test the above function
int main()
{

string str;

cout<<"Enter The Original Message";

cin>>str;
   string keyword = "SAMPLE";

   string key = genKey(str, keyword);
   string encrypted_text = encryptedText(str, key);

   cout << "Ciphertext : "
       << encrypted_text << "\n";

   cout << "Original/Decrypted Text : "
       << originalText(encrypted_text, key);
   return 0;
}

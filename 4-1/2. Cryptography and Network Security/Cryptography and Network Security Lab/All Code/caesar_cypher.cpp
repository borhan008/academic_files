#include <bits/stdc++.h>
using namespace std;


// Function to encrypt and decrypt the plaintext (alphabet and spaces) using Caesar cipher
string caesar_encrypt(const string &plaintext, int shift) {
    string ciphertext = "";
    for(char c : plaintext){
        if(c == ' '){
            ciphertext += ' ';
            continue;
        }
        int base = isupper(c) ? 65 : 97;
        char encrypted_char = (c + shift - base) % 26 + base;
        ciphertext += encrypted_char;
    }
    return ciphertext;
}



int main(){
    cout << "Plaintext: ";
    string plaintext; 
    getline(cin, plaintext);
    
    cout << "Shift: ";
    int shift; cin >> shift;

    shift = (shift % 26 + 26) % 26; // Handle negative shifts

    cout << "Ciphertext: " << caesar_encrypt(plaintext, shift) << endl;

    cout << "Decrypted Text: " << caesar_encrypt(caesar_encrypt(plaintext, shift), -shift) << endl;        

   
    return 0;
}
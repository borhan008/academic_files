#include<bits/stdc++.h>
using namespace std;

int main() {
   
    string plaintext;
    cout  << "Enter plaintext: ";
    getline(cin, plaintext);

    string ciphermap;
    cout << "Enter cipher map (26 unique letters): ";
    cin >> ciphermap;

    if(ciphermap.length() != 26) {
        cout << "Cipher map must be 26 characters long." << endl;
        return 1;
    }

    string ciphertext = "";
    for(char c : plaintext) {
        if(c == ' ') {
            ciphertext += ' ';
        } else if(isalpha(c)) {
            bool is_upper = isupper(c);
            char base = is_upper ? 'A' : 'a';
            int index = tolower(c) - 'a';
            char mapped_char = ciphermap[index];
            if(is_upper) mapped_char = toupper(mapped_char);
            ciphertext += mapped_char;
        } else {
            ciphertext += c; 
        }
    }
    cout << "Ciphertext: " << ciphertext << endl;
    return 0;
}
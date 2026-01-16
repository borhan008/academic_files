#include<bits/stdc++.h>
using namespace std;
#define int long long

int binExpo(int a, int b, int m)
{

    int result = 1;
    a = a % m;
    if(b == 0) return 1;
    if(b%2 == 1) {     
        result = a*binExpo(a, b-1, m) % m;
    } else{
        int half = binExpo(a, b/2, m) % m;
        result = (half * half) % m;
    }

    return result;
}

int32_t main(){
    cout << "Input two prime numbers (p and q): ";
    int p, q;
    cin >> p >> q;

    int n = p * q; 
    int phi = (p-1)*(q-1); 

   int e;
   for(e = 2; e<phi; e++){
        if(__gcd(e, phi) == 1)  break; 
   }

   int d; 
   for(d = 2; d<phi; d++){
        if((d*e) % phi == 1) break; 
   }    

   cout << "Public key (n, e): (" << n << ", " << e << ")\n";
   cout << "Private key (n, d): (" << n << ", " << d << ")\n";


    cout << "Input plaintext (as integer): ";
    int plaintext; cin >> plaintext;

    
    int ciphertext = binExpo(plaintext, e, n);
    cout << "Ciphertext: " << ciphertext << endl;


    int decryptedtext = binExpo(ciphertext, d, n);
    cout << "Decrypted text: " << decryptedtext << endl;

}
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


bool checkPrimeSquare(long long num){
    int x = (int)sqrt(num)*(int)sqrt(num);
    if(x==num){
        int y = (int)sqrt(num); y=(int)sqrt(num);
        for(int i=2; i<y; i++){
            if(y%i == 0){
                 return false;
            }
        }

        return true;
    }
    return false;
}

int32_t main(){
    int N; cout << "N="; cin >> N;
    bool flag=true;
     int x,p=-1,q=-1;

    for(int i=0; i<N; i++){
        cin >> x;
        if(checkPrimeSquare(x)){
            if(p==-1) {
                p=sqrt(x); 
            } else {
                q = sqrt(x);
            }
        }
    }

    int plaintext;
    cout << "M="; cin >> plaintext;

    int n; n=p*q;


    cout << "Two primes are: " << p << " " << q << "\n";

    int phi = (p-1)*(q-1); 

   int e;
   for(e = 2; e<phi; e++){
        if(__gcd(e, phi) == 1)  break; 
   }

   int d; 
   for(d = 2; d<phi; d++){
        if((d*e) % phi == 1) break; 
   }    

   cout << "Public key " << e << " " << n << "\n";
   cout << "Private key " << d << " " << n << "\n";



    int ciphertext = binExpo(plaintext, e, n);
    cout << "Cipher: " << ciphertext << endl;


    int decryptedtext = binExpo(ciphertext, d, n);
    cout << "Plain text: " << decryptedtext << endl;

}



/*
5
121 45 65 49 32
30

7
34 361 23 78 169 40 50
30 
*/
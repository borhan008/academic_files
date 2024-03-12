// Version : 01
#include<bits/stdc++.h> 
using namespace std; 
int main() 
{ 
    string msg,crc,encoded=""; 
    cout<<"enter your message : \n"; 
    getline(cin,msg); 
    cout<<"enter your crc generator : \n"; 
    getline(cin,crc); 
    int m=msg.length(),n=crc.length(); 
    encoded+=msg; 
    for(int i=1;i<=n-1;i++) 
    { 
        encoded+='0'; 
    } 
 
    for(int i=0;i<=encoded.length()-n; ) 
    { 
        for(int j=0;j<n;j++) 
        encoded[i+j]=(encoded[i+j]==crc[j])? '0' : '1'; 
        for( ;i<encoded.length()&&encoded[i]!='1';i++); 
 
 
    } 
    cout<< msg+encoded.substr(m) << "\n"; 
 
 
}

// Version  : 02
#include<bits/stdc++.h>
using namespace std;

#define uint uint32_t

uint Adler(string str){
	uint sum1=1, sum2=0;
	for(int i=0; i<(int)str.size(); i++){
		sum1 += (str[i]); sum1 %= 65521;
		sum2 += sum1; sum2 %= 65521;
	}
	return (sum2 << 16) | sum1;
}

int main()
{
		cout << "Write the roll : \n";
		
		string str; getline(cin, str);
		printf("%x", Adler(str));

    return 0;
}
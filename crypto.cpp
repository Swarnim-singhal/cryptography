/*
============================================================================
Author : Swarnim singhal
Copyright : 2015
Description : Problem details are with the companion PDF.
============================================================================
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <bits/stdc++.h>
#include <cmath>
#include <cstring>
#include <set>
#include <fstream>
using namespace std;

#define keylength 5



char encrypt_shift(char pChar,char keyChar){

	int m,k,c;

	if(keyChar >= 65 && keyChar <= 90 )
		k = keyChar-65 ;		
	else if(keyChar >=97 && keyChar <= 122)
		k = keyChar-97;

	//uppercase letter in plaintext
	if(pChar >= 65 && pChar <= 90){
		m = pChar-65;		
		c = (m+k)%26;
		return (c+65);
	}

	//lowercase letter in plaintext
	if(pChar >= 97 && pChar <= 122){
		m = pChar-97;		
		c = (m+k)%26;
		return (c+97);
	}

}

char decrypt_shift(char cChar,char keyChar){

	int m,k,c;

	if(keyChar >= 65 && keyChar <= 90 )
		k = keyChar-65 ;		
	else if(keyChar >=97 && keyChar <= 122)
		k = keyChar-97;

	//uppercase letter in ciphertext
	if(cChar >= 65 && cChar <= 90){
		c = cChar-65;		
		m = (26+c-k)%26;
		return (m+65);
	}

	//lowercase letter in ciphertext
	if(cChar >= 97 && cChar <= 122){
		c = cChar-97;		
		m = (26+c-k)%26;
		return (m+97);
	}

}


void encrypt(){

	ofstream out;
	ifstream in;

	string plaintextFile,cipherFile,key;

	cout << "Enter the name of your input file you want to encrypt: ";
	cin >> plaintextFile;

	in.open(plaintextFile.c_str());

	if(in.fail()){
        cout<<"ERROR: Unable to open file: "<<plaintextFile<<". Terminating...";
        exit(1); // 0 – normal exit, non zero – some error
    }


	cout << "Enter the name of the output file to write the ciphertext: ";
	cin >> cipherFile;	
	out.open(cipherFile.c_str() );

	cout << "Enter a 5-letter key to encrypt file: " ;
	cin >> key;
	


	int j = 0;
	char pChar,cChar;
	

	while (in.get(pChar) ) {		
		if(pChar != ' '){
			cChar =  encrypt_shift(pChar,key[j]);
			//cout << pChar <<"  "<<cChar<<endl;
			out.put(cChar);
			j++;

			if(j>(keylength-1))
				j=0;			
		}
		else if(pChar == ' ' || pChar=='\n' || pChar =='\t'){
			out.put(pChar);
		}
	}	
	out.close();
	in.close();
}


void decrypt(){

	ofstream out;
	ifstream in;
	string cipherFile,plaintextFile,key;

	cout << "Enter the name of your input file you want to decrypt: : ";
	cin >> cipherFile;

	in.open(cipherFile.c_str());

	if(in.fail()){
        cout<<"ERROR: Unable to open file: "<<cipherFile<<". Terminating...";
        exit(1); // 0 – normal exit, non zero – some error
    }


	cout << "Enter the name of the output file to write the plaintext: ";
	cin >> plaintextFile;
	out.open(plaintextFile.c_str() );

	cout << "Enter a 5-letter key to decrypt file: " ;
	cin >> key;	
	

	int j = 0;
	char pChar,cChar;	

	while (in.get(cChar)) {
		
		if(cChar != ' '){
			pChar =  decrypt_shift(cChar,key[j]);
			out.put(pChar);
			j++;
			if(j>(keylength-1))
				j=0;			
		}
		else if(cChar == ' ' || cChar=='\n' || cChar =='\t'){
			out.put(cChar);
		}
	}	
	out.close();
	in.close();
}



int main(){

	char input = ' ';
	string inputFileName , outputFileName;
	string key;

	while(input != 'E' && input != 'D' && input != 'e' && input != 'd'){		
		cout << "Would you like to ENCRYPT or DECRYPT a file (E or D)? " ;
		cin  >> input ;
	}

	
	if(input == 'E' || input == 'e')
		encrypt();
	else if(input =='D'  || input =='d')
		decrypt();
		


	return 0;
}
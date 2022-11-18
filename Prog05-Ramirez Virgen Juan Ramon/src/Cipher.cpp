#include "Cipher.h"
#include<iostream>
#include <sstream>
#include<iomanip>
#include<fstream>
using namespace std;


void Cipher::write(string msg)
{
    ofstream File;
    File.open("File01.txt", ios::out);
    if(File.fail()){
        cout<<"The file can't be open";
        exit(1);
    }
    File<<msg;
    File.close();
}
string Cipher::retrieve(){
    ifstream File;
    string msg;
    File.open("File01.txt",ios::in);
    if(File.fail()){
		cout<<"Error"<<endl;
		exit(1);
	}
	while(!File.eof()){
        getline(File,msg);
	}
	return msg;
	File.close();
}
string Cipher::cesarEncryption(string msg,int n ){
    string encryptedText = msg;
    for(int i =0; i<msg.length(); i++){
        if(msg[i] == 32)
            continue; //32 is ASCII of space character, we will ignore it
        else{
            if(msg[i]+n>122){
                    //after lowercase z move again to a, Z's ascii  is 122
                    int temp = (msg[i]+n)-122;
                    encryptedText[i]=96+temp;
            }
            else if(msg[i]+n>90 && msg[i]<=96){
                //after Z uppercase move back to a, 90 is Z's ASCII
                int temp = (msg[i]+n) - 90;
                encryptedText[i]=64+temp;
            }
            else{
                //In case of characters being in between A-Z & a-z
                encryptedText[i] +=n;
            }
        } //else
    } //for
    return encryptedText;
}
string Cipher::cesarDecryption(string msg, int n){
    string decryptedText =  msg;
    for(int i =0; i<msg.length(); i++){
        if(msg[i] == 32){
            continue; //Ignoring space
        }else{
            if((msg[i]-n )<97 && (msg[i]-n)>90){
                int temp =  (msg[i]-n)+26;
                decryptedText[i]=temp;
            }else if((msg[i]-n)<65){
                int temp = (msg[i]- n)+26;
                decryptedText[i]=temp;
            }else{
                decryptedText[i] = msg[i]-n;

            }
        }
    }
    return decryptedText;
}
string Cipher::xorEncryption(string msg, string key){
    string encryHexa = "";
    int keyItr = 0;
    stringstream res;
    for(int i =0; i<msg.length(); i++){
        int temp = msg[i] ^ key[keyItr];
        res<<hex<<setfill('0')<<std::setw(2)<<(int)temp;
        keyItr++;
        if(keyItr>=key.length())
            //Once all key letters are used , repeat the key
            keyItr=0;
    }
    res>>encryHexa;
    return encryHexa;
};
string Cipher::xorDecryption(string msg, string key){
    string hexToUni= "";
    for(int i=0;i<msg.length()-1; i+=2){
        //Splitting hex into a pair of two
        string output = msg.substr(i,2);
        //Converting hex into unicode
        int decimal = strtol(output.c_str(),nullptr,16);
        hexToUni+=(char)decimal;
    }
    string decrypText = "";
    int keyItr = 0;
    for(int i =0;i<hexToUni.length(); i++){
        int temp = hexToUni[i] ^ key[keyItr];
        decrypText += (char)temp;
        keyItr++;
        if(keyItr>=key.length())
            //Once all key letters are used , repeat the key
        keyItr=0;
    }
    return decrypText;
}



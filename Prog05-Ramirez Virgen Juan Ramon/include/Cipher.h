#ifndef CIPHER_H
#define CIPHER_H
#include<iostream>
using namespace std;

class Cipher
{
    public:
        Cipher(){
        };
        string cesarEncryption(string,int);
        string cesarDecryption(string, int);
        string xorEncryption(string,string);
        string xorDecryption(string, string);
        void write(string);
        string retrieve();
};

#endif // CIPHER_H

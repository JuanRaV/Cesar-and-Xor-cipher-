#include <iostream>
#include<Cipher.h>

using namespace std;


int main(){
    Cipher *C=new Cipher();

    int opc,n;
    string key,msg;
    cout<<"===CIPHER PROGRAM==="<<endl;

    cout<<"Write the message: ";getline(cin,msg);
    cout<<"Write a number(0-25): ";cin>>n;
    cin.ignore();

    string firstEncrypted = C->cesarEncryption(msg,n);
    cout<<endl;
    cout<<"CESAR encrypted message: "<<firstEncrypted <<endl<<endl;

    cout<<"Write a key: ";getline(cin,key);

    string secondEncrypted = C->xorEncryption(firstEncrypted,key);
    cout<<"XOR encrypted message: "<<secondEncrypted<<endl;
    system("pause");
    system("cls");
    cout<<endl<<endl<<endl;

    cout<<"===Encrypted message written on File===="<<endl<<endl<<endl<<endl;
    C->write(secondEncrypted);
    system("pause");
    system("cls");

    cout<<"Do you want to Retrive and Decrypt "<<endl;
    cout<<"1.Yes"<<endl;
    cout<<"2.-No"<<endl;cin>>opc;
     if(opc==1){
        string decipher = C->retrieve();
        cout<<"Retrieve message: "<<decipher<<endl;
        string secondDecrypted = C->xorDecryption(decipher, key);
        cout<<"XOR decrypted message: "<<secondDecrypted<<endl<<endl;

        string firstDecripted=C->cesarDecryption(secondDecrypted, n);
        cout<<"Final decrypted message: "<<firstDecripted<<endl;
    }
    else
        return 0;

    /*cout<<"1.-Encrypt & Save"<<endl;
    cout<<"2.-Retrieve & Decrypt"<<endl;cin>>opc;
    do{
        switch(opc){
            case 1:
                string msg,key;
                int n;
                cout<<"Write the message: ";cin>>msg;
                cout<<"Write a number(0-25): ";cin>>n;
                cin.ignore();

                string firstEncrypted = C->cesarEncryption(msg,n);
                cout<<"CESAR encrypted message: "<<firstEncrypted <<endl;

                cout<<"Write a key: ";getline(cin,key);

                string secondEncrypted = C->xorEncryption(firstEncrypted,key);
                cout<<"XOR encrypted message: "<<secondEncrypted<<endl;
                system("pause");
                system("cls");
                cout<<endl<<endl<<endl;

                cout<<"===Encrypted message written on File===="<<endl<<endl<<endl<<endl;
                C->write(secondEncrypted);
                system("pause");
                system("cls");

                break;
            case 2:
                break;
            case 3:
                break;
        }
    }while(opc!=3);*/



    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include "AddressBook.pb.h"
using namespace std;

// This function fills in a Person message based on user input
void PromptForAddress(tutorial::Person* persion){
    cout << "Enter person ID number: ";
    int id;
    cin >> id;
    person->set_id(id);
    cin.ignare(256, '\n');

    cout << "Enter name: ";
    getline(cin, *person->mutable_name());

    cout << "Enter email address (blank for none): ";
    string email;
    getline(cin, email);
    if (!email.empty()){
        person->set_email(email);
    }
    
    while (true){
        cout << "Enter a phone number (or leave blank to finish): ";
        string number;
        getline(cin, number);
        if(number.empty()){
            break;
        }
    }
    
}
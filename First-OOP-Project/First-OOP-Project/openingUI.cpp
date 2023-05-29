#include <iostream>
#include "OpeningUI.h"
#include <string>
#include "User.h"
#include "Renter.h"
#include "Owner.h"
#include"Organization.h"
using namespace std;
void openingUI(Organization *org) {
    
    string n = "0";
    int i = 0;
    while (true) {
        system("cls");
        if (i)
            cout << "unvalid input please try again" << endl;
        i++;
        cout << "*********************\n";
        cout << "**      WELCOME    **\n";
        cout << "**   1. Sign in    **\n";
        cout << "**   2. Sign up    **\n";
        cout << "**   3. Admin      **\n";
        cout << "**   4. Close      **\n";
        cout << "*********************\n";
        cin >> n;
        system("cls");
        if (n == "1") {
            User* user = NULL;
            while (user == NULL) {
                system("cls");
                cout << "Username: ";
                string name, password;
                cin >> name;
                cout << "Password: ";
                cin >> password;
                user = org->authenticate(name, password);
                if (user == NULL) {
                    cout << "Account does not exist\n";
                    char c = '0';
                    cout << "1. Try again" << endl;
                    cout << "2. Go back" << endl;
                    cin >> c;
                    if (c == '2')
                    {
                        openingUI(org);
                    }
                }
                else
                    user->displayInfo(org);
            }
        }
        else  if (n == "2") {
            cout << "UserName: ";
            string name, password;
            cin >> name;
            cout << "Password: ";
            cin >> password;
            while (true) {
                cout << "Are You :\n" << "1-Renter\n" << "2-Car Owner\n";
                string response;
                cin >> response;
                if (response == "1" || response == "2") {
                    int r = stoi(response);
                    User* user;
                    user = org->signUp(name, password, r);
                    user->displayInfo(org);
                }
                else cout << "Unvalid input\n";
            }
        }
        else if (n == "3") {
            string name, password;
            while (name != "admin" || password != "pass") {
                system("cls");
                cout << "UserName: ";
                cin >> name;
                cout << "Password: ";
                cin >> password;
                if (name == "admin" && password == "pass") {
                    Admin a(org);
                    a.displayInfo(org);
                }
                else {
                    char c = '0';
                    cout << "1. Try again" << endl;
                    cout << "2. Go back" << endl;
                    cin >> c;
                    if (c == '2')
                    {
                        openingUI(org);
                    }
                }
            }
        }
        else if (n == "4") {
            cout << "Are you sure you want to exit\n";
            cout << "1. Exit\n";
            cout << "2. Continue\n";
            char ss;
            cin >> ss;
            if (ss == '1')
            {
                cout << "THANK YOU FOR USING THE APPLICATION\n";
                org->writeFiles();
                exit(0);
            }
        }
    }
    
}
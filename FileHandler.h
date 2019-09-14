#ifndef FILEHANDLER_H_INCLUDED
#define FILEHANDLER_H_INCLUDED

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "UserAccount.h"

using namespace std;

class FileHandler {
private:
    fstream accountsData;

public:
    FileHandler() {
        accountsData.open("AccountData.dat", ios::in | ios::app);
    }

    void writeDataToFile(UserAccount userData) {
        long int accNo = userData.getAccNo();
        string name = userData.getUserName();
        long int balance = userData.getAccountBalance();
        string email = userData.getEmail();
        string phone = userData.getPhoneNo();
        string add = userData.getAddr();
        int age = userData.getAge();

        accountsData.seekg(0, ios::end);
        if(accountsData.is_open()) {
            accountsData << accNo << ' ' << name << ' ' << balance << ' ' << email << ' ' << phone << ' ' << add << ' ' << age << endl;
        } else {
            cout << "File is not open!" << endl;
        }
    }

    void viewAllDataFromFile() {
        if(accountsData.is_open()) {

            cout << "ACC NO   " << "NAME    " << "BALANCE   " << "EMAIL   " << "PHONE   " << "LOCATION   " << "AGE   " << endl;

            string l;
            accountsData.clear();
            accountsData.seekp(0, ios::beg);

            while(getline(accountsData, l)) {
                cout << l << endl;
            }
        } else {
            cout << "Data store file is not available." << endl;
        }
    }

    UserAccount *loadDataFromFile(int accountCounts) {
        UserAccount accFromFile[accountCounts];

        if(accountsData.is_open()) {
            accountsData.clear();
            accountsData.seekp(0, ios::beg);
            int userIdx = 0;

            string line;
            while(getline(accountsData, line)) {
                vector<string> accValues;
                istringstream iss(line);
                for(string i; iss >> i;)
                    accValues.push_back(i);

                for(int i = 0; i < accValues.size(); i++) {
                    cout << "Data from file: " << accValues[i] << endl;
                }
                if(accountCounts > userIdx) {
//                    accFromFile[userIdx].inputData(accValues[0], accValues[1], accValues[2], accValues[3], stol(accValues[4]), stol(accValues[5]), stoi(accValues[6]));
                    userIdx++;
                } else {
                    cout << "Cannot load anymore data. Array limit exceeded." << endl;
                }
            }

            return accFromFile;
        } else {
            cout << "Data store file is not available." << endl;
            return NULL;
        }
    }

    ~FileHandler() {
        cout << "Closing data file." << endl;
        accountsData.close();
    }
};

#endif // FILEHANDLER_H_INCLUDED

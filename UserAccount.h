#ifndef USERACCOUNT_H_INCLUDED
#define USERACCOUNT_H_INCLUDED

using namespace std;

class UserAccount {
private:
    string name, addr, email, phone_no;
    long int acc_no, acc_balance;
    int age;

public:
    void inputData(long accNo, string userName, long accBal, string email, string phoneNo, string address, int userAge) {
        name = userName;
        addr = address;
        email = email;
        phone_no = phoneNo;
        acc_no = accNo;
        acc_balance = accBal;
        age = userAge;
    }

    string getUserName() {
        return name;
    }

    long int getAccNo() {
        return acc_no;
    }

    string getEmail() {
        return email;
    }

    string getPhoneNo() {
        return phone_no;
    }

    string getAddr() {
        return addr;
    }

    int getAge() {
        return age;
    }

    long int getAccountBalance() {
        return acc_balance;
    }

    void setAccountBalance(long int new_balance) {
        acc_balance = new_balance;
    }

    int valid_mob(string phone_no) {
        int len = phone_no.length();
        if (len == 10)
        {
            for(int i=0; i<len; i++)
            {
                if (phone_no[i]>='0' && phone_no[i]<='9')
                    continue;
                else
                    return 0;
            }
            return 1;
        }
        return 0;
    }

    int valid_email(string email) {
        int len = email.length();
        int dot = 0;
        int sign = 0;
        for(int i=0; i<len; i++)
        {
            if (email[i] == '.')
                dot = 1;
            if (email[i] == '@')
                sign = 1;
        }
        return sign*dot;
    }

    int valid_age(int age) {
        if (age >= 10 && age <= 110)
            return 1;
        return 0;
    }

    void createUserAccount() {
        cout << endl;
        cout << "Enter User Name: ";
        cin.ignore();
        getline(cin, name);
        age = 0;
        while (!valid_age(age)) {
            cout << "Enter Age: ";
            cin >> age;
        }
        cout << "Enter Account Number: ";
        cin >> acc_no;
        cout << "Enter Initial Balance: ";
        cin >> acc_balance;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, addr);
        email = "";
        while(!valid_email(email))
        {
            cout << "Enter user email: ";
            cin >> email;
        }
        phone_no = "";
        while(!valid_mob(phone_no))
        {
            cout << "Enter 10 digit phone Number: ";
            cin >> phone_no;
        }
        cout << "Successfully Created" << endl;

    }

    void updateUserAccount() {
        cout << endl;
        cout << "Change your User Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Change Initial Balance: ";
        cin >> acc_balance;
        cout << "Change Address: ";
        cin.ignore();
        getline(cin, addr);
        email = "";
        while(!valid_email(email))
        {
            cout << "Change user email: ";
            cin >> email;
        }
        phone_no = "";
        while(!valid_mob(phone_no))
        {
            cout << "Change 10 digit phone Number: ";
            cin >> phone_no;
        }
        cout << "Successfully Updated" << endl;
    }

    void displayAccData() {
        cout << endl;
        cout << "USER DATA:" << endl;
        cout << "Name: " << getUserName() << endl;
        cout << "Account Balance: " << getAccountBalance() << endl;
        cout << "Account Number: " << getAccNo() << endl;
        cout << "Phone Number: " << getPhoneNo() << endl;
        cout << "Address: " << getAddr() << endl;
        cout << "Age: " << getAge() << endl;
    }
    void deleteAcc(UserAccount allUserAccounts[], int ind, int newUserCount) {
        for (int j=ind; j<newUserCount; j++)
            allUserAccounts[j] = allUserAccounts[j+1];
    }
};

#endif // USERACCOUNT_H_INCLUDED

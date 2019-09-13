#include <iostream>
#include <stdlib.h>

using namespace std;


class UserAccount {
private:
    string name, addr, email;
    long int acc_no, acc_balance, phone_no, age;

public:
    string getUserName() {
        return name;
    }

    long int getAccNo() {
        return acc_no;
    }

    string getEmail() {
        return email;
    }

    long int getPhoneNo() {
        return phone_no;
    }

    string getAddr() {
        return addr;
    }

    long int getAge() {
        return age;
    }

    long int getAccountBalance() {
        return acc_balance;
    }

    void setAccountBalance(long int new_balance) {
        acc_balance = new_balance;
    }

    void createUserAccount() {
        cout << "Enter User Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Account Number: ";
        cin >> acc_no;
        cout << "Enter Initial Balance: ";
        cin >> acc_balance;
        cout << "Enter Address: ";
        cin >> addr;
        cout << "Enter user email: ";
        cin >> email;
        cout << "Enter phone Number: ";
        cin >> phone_no;
    }

    void updateUserAccount() {
        cout << "Enter new User Name: ";
        cin >> name;
        cout << "Enter new Age: ";
        cin >> age;
        cout << "Enter new Account Number: ";
        cin >> acc_no;
        cout << "Enter new Initial Balance: ";
        cin >> acc_balance;
        cout << "Enter new Address: ";
        cin >> addr;
        cout << "Enter new user email: ";
        cin >> email;
        cout << "Enter new phone Number: ";
        cin >> phone_no;
    }

    void displayAccData() {
        cout << "Name: " + name << endl;
        cout << "Account Balance: " << acc_balance << endl;
        cout << "Account Number: " << acc_no << endl;
        cout << "Phone Number: " << phone_no << endl;
        cout << "Address: " << addr << endl;
        cout << "Age: " << age << endl;
    }
};

class Transaction {
public:
    void transferMoney (UserAccount sender,UserAccount receiver, long int amount) {
    if(sender.getAccountBalance() >= amount)
    {
      long int senderCurrent = sender.getAccountBalance();
      sender.setAccountBalance(senderCurrent - amount);

      long int receiverCurrent = receiver.getAccountBalance();
      receiver.setAccountBalance(receiverCurrent + amount);

      cout << "Successfully Transfered " << amount << endl;
    } else
    {
     cout << "Insufficient Balance";
    }
    }

    void withdrawMoney (UserAccount user, long int amount)
    {
      long int userCurrent = user.getAccountBalance();
      userCurrent -= amount;
      user.setAccountBalance(userCurrent);

      cout<<"Successfully withdrawn "<< amount << endl;
    }

    void depositMoney (UserAccount user, long int amount)
    {
      long int userCurrent = user.getAccountBalance();
      userCurrent += amount;
      user.setAccountBalance(userCurrent);

      cout<<"Successfully deposited "<< amount << endl;
    }
};

int main() {
    int userCount = 0;
    UserAccount allUserAccounts[50];
    Transaction *transactionHandler = new Transaction;

    int cont;

    do {
        cout << "------- BANK ACCOUNTING SYSTEM -------\n\n" << endl;
        cout<<"\t1. Create new account"<<endl;
        cout<<"\t2. Deposit Money" << endl;
        cout<<"\t3. Withdraw Money" << endl;
        cout<<"\t4. Transfer Money" << endl;
        cout<<"\t5. View Account" << endl;
        cout<<"\t6. Update Account" << endl;
        cout<<"\t7. Delete Account" << endl;
        cout<<"\t8. Exit." << endl;

        cin >> cont;

        switch(cont) {
            case 1: {
                allUserAccounts[userCount].createUserAccount();
                userCount++;
            }
            break;
            case 2: {
                long accNo, amt;
                cout << "Enter account number: ";
                cin >> accNo;
                cout << "Enter Amount to be deposited: ";
                cin >> amt;
                for(int i = 0; i < userCount; i++) {
                    if(allUserAccounts[i].getAccNo() == accNo) {
                        transactionHandler->depositMoney(allUserAccounts[i], amt);
                    }
                }
            }
            break;
            case 3: {
                long accNo, amt;
                cout << "Enter account number: ";
                cin >> accNo;
                cout << "Enter Amount to be withdrawn: ";
                cin >> amt;
                for(int i = 0; i < userCount; i++) {
                    if(allUserAccounts[i].getAccNo() == accNo) {
                        transactionHandler->withdrawMoney(allUserAccounts[i], amt);
                    } else {
                        cout << "Invalid Account number.";
                    }
                }
            }
            break;
            case 4: {
                long senderNo, receiverNo, amt;
                cout << "Enter sender's account number: ";
                cin >> senderNo;
                cout << "Enter receiver's account number: ";
                cin >> receiverNo;
                cout << "Enter Amount to be withdrawn: ";
                cin >> amt;

                UserAccount s, r;
                for(int i = 0; i < userCount; i++) {
                    if(allUserAccounts[i].getAccNo() == senderNo) {
                        s = allUserAccounts[i];
                    } else {
                        cout << "Invalid Account Number: " << senderNo;
                    }
                }

                for(int i = 0; i < userCount; i++) {
                    if(allUserAccounts[i].getAccNo() == receiverNo) {
                        r = allUserAccounts[i];
                    } else {
                        cout << "Invalid Account Number: " << receiverNo;
                    }
                }

                transactionHandler->transferMoney(s, r, amt);
                }
                break;
            case 5: {
                long int accNo;
                cout << "Enter account number: ";
                cin >> accNo;

                for(int i = 0; i < userCount; i++) {
                    if(allUserAccounts[i].getAccNo() == accNo) {
                        allUserAccounts[i].displayAccData();
                    } else {
                        cout << "Invalid Account Number.";
                    }
                }
            }
            break;
            case 6: {
             long int accNo;
                cout << "Enter account number: ";
                cin >> accNo;
                 for(int i = 0; i < userCount; i++) {
                    if(allUserAccounts[i].getAccNo() == accNo) {
                        allUserAccounts[i].updateUserAccount();
                    } else {
                        cout << "Invalid Account Number.";
                    }
                }
            }
            break;
            default:
                cout << "Exiting the Program." << endl;
                exit(0);
                break;
        }
    } while(cont != 7);

    delete allUserAccounts;
    delete transactionHandler;
    return 0;
}

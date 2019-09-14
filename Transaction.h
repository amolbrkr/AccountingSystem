#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

class Transaction {
public:
    void transferMoney (UserAccount &sender,UserAccount &receiver, long int amount) {
    if(sender.getAccountBalance() >= amount)
    {
      long int senderCurrent = sender.getAccountBalance();
      sender.setAccountBalance(senderCurrent - amount);

      long int receiverCurrent = receiver.getAccountBalance();
      receiver.setAccountBalance(receiverCurrent + amount);

      cout << "Successfully Transfered " << amount << endl;
    }
    else
        {
        cout << "Insufficient Balance";
        }
    }

    void withdrawMoney (UserAccount &user, long int amount){
        if(user.getAccountBalance() >= amount)
    {
        long int userCurrent = user.getAccountBalance();
        userCurrent -= amount;
        user.setAccountBalance(userCurrent);

        cout<<"Successfully withdrawn "<< amount << endl;
    }
    else
        {
            cout << "Insufficient Balance"<< endl;
        }
    }


    void depositMoney (UserAccount &user, long int amount){
        if(user.getAccountBalance() >= amount)
    {
      long int userCurrent = user.getAccountBalance();
      userCurrent += amount;
      user.setAccountBalance(userCurrent);

      cout<<"Successfully deposited "<< amount << endl;
    }
    else
        {
            cout << "Insufficient Balance"<< endl;
        }
    }
};

#endif // TRANSACTION_H_INCLUDED

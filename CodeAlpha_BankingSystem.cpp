#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Transaction class history track karne ke liye
class Transaction {
public:
    string type;
    double amount;
    Transaction(string t, double a) : type(t), amount(a) {}
};

// Account class jo balance aur operations manage karti hai [cite: 44]
class Account {
private:
    long accountNumber;
    double balance;
    vector<Transaction> history;

public:
    Account(long accNo) : accountNumber(accNo), balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            history.push_back(Transaction("Withdrawal", amount));
            cout << "Withdrawal Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    void displayBalance() {
        cout << "Current Balance: " << balance << endl;
    }

    void showHistory() {
        cout << "--- Transaction History ---\n";
        for (auto &t : history) {
            cout << t.type << ": " << t.amount << endl;
        }
    }
};

int main() {
    // Basic menu-driven logic yahan likhein
    Account myAcc(123456);
    myAcc.deposit(5000);
    myAcc.withdraw(2000);
    myAcc.displayBalance();
    myAcc.showHistory();

    return 0;
}
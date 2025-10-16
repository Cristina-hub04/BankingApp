#ifndef BANK_H
#define BANK_H

#include <string>
#include <unordered_map>

struct Account {
    std::string name;
    double balance;
};

class Bank {
private:
    std::unordered_map<int, Account> accounts;
    int nextAccountID = 1;
public:
    int createAccount(const std::string& name);
    bool deposit(int id, double amount);
    bool withdraw(int id, double amount);
    bool transfer(int fromID, int toID, double amount);
    double checkBalance(int id);
};

#endif

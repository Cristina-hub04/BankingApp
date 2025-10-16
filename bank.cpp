#include "bank.h"

int Bank::createAccount(const std::string& name) {
    int id = nextAccountID++;
    accounts[id] = {name, 0.0};
    return id;
}

bool Bank::deposit(int id, double amount) {
    if(amount <= 0 || accounts.find(id) == accounts.end()) return false;
    accounts[id].balance += amount;
    return true;
}

bool Bank::withdraw(int id, double amount) {
    if(amount <= 0 || accounts.find(id) == accounts.end()) return false;
    if(accounts[id].balance < amount) return false;
    accounts[id].balance -= amount;
    return true;
}

bool Bank::transfer(int fromID, int toID, double amount) {
    if(!withdraw(fromID, amount)) return false;
    return deposit(toID, amount);
}

double Bank::checkBalance(int id) {
    if(accounts.find(id) == accounts.end()) return -1;
    return accounts[id].balance;
}

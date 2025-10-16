#include <iostream>
#include "bank.h"

int main() {
    Bank bank;

    std::cout << "=== BLACK BOX TESTS ===\n";

    
    int acc1 = bank.createAccount("Alice");
    int acc2 = bank.createAccount("Bob");

    
    std::cout << "Deposit 100 to Alice: ";
    std::cout << (bank.deposit(acc1, 100) ? "PASS" : "FAIL") << "\n";

    
    std::cout << "Withdraw 50 from Alice: ";
    std::cout << (bank.withdraw(acc1, 50) ? "PASS" : "FAIL") << "\n";

    
    std::cout << "Transfer 25 from Alice to Bob: ";
    std::cout << (bank.transfer(acc1, acc2, 25) ? "PASS" : "FAIL") << "\n";

    std::cout << "Alice balance: " << bank.checkBalance(acc1) << "\n";
    std::cout << "Bob balance: " << bank.checkBalance(acc2) << "\n\n";

    std::cout << "=== WHITE BOX TESTS (Edge Cases) ===\n";

    
    std::cout << "Withdraw 200 from Alice (should fail): ";
    std::cout << (!bank.withdraw(acc1, 200) ? "PASS" : "FAIL") << "\n";

    
    std::cout << "Deposit -50 to Bob (should fail): ";
    std::cout << (!bank.deposit(acc2, -50) ? "PASS" : "FAIL") << "\n";

   
    std::cout << "Transfer 10 from Alice to account 999 (should fail): ";
    std::cout << (!bank.transfer(acc1, 999, 10) ? "PASS" : "FAIL") << "\n";

    
    std::cout << "Withdraw 10 from account 999 (should fail): ";
    std::cout << (!bank.withdraw(999, 10) ? "PASS" : "FAIL") << "\n";

    
    std::cout << "Check balance for account 999 (should be -1): ";
    std::cout << ((bank.checkBalance(999) == -1) ? "PASS" : "FAIL") << "\n";

    return 0;
}

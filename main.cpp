#include <iostream>
#include <limits>
#include "bank.h"

int main() {
    Bank bank;
    int choice;

    while(true) {
        std::cout << "\n==== BANK MENU ====\n";
        std::cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Transfer\n5. Check Balance\n6. Exit\n";
        std::cout << "Choose: ";

        if(!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number 1-6.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

        if(choice == 6) break;

        int id, toID;
        double amount;
        std::string name;

        switch(choice) {
            case 1:
                std::cout << "Enter account name: ";
                std::getline(std::cin, name);
                id = bank.createAccount(name);
                std::cout << "Account created! ID: " << id << "\n";
                break;

            case 2:
                std::cout << "Enter account ID and deposit amount: ";
                if(!(std::cin >> id >> amount)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input.\n";
                    break;
                }
                if(bank.deposit(id, amount))
                    std::cout << "Deposit successful.\n";
                else
                    std::cout << "Deposit failed.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            case 3:
                std::cout << "Enter account ID and withdraw amount: ";
                if(!(std::cin >> id >> amount)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input.\n";
                    break;
                }
                if(bank.withdraw(id, amount))
                    std::cout << "Withdrawal successful.\n";
                else
                    std::cout << "Withdrawal failed.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            case 4:
                std::cout << "Enter FROM ID, TO ID, and amount: ";
                if(!(std::cin >> id >> toID >> amount)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input.\n";
                    break;
                }
                if(bank.transfer(id, toID, amount))
                    std::cout << "Transfer successful.\n";
                else
                    std::cout << "Transfer failed.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            case 5:
                std::cout << "Enter account ID: ";
                if(!(std::cin >> id)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input.\n";
                    break;
                }
                amount = bank.checkBalance(id);
                if(amount >= 0)
                    std::cout << "Balance: " << amount << "\n";
                else
                    std::cout << "Account not found.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            default:
                std::cout << "Invalid choice. Enter a number 1-6.\n";
        }
    }

    std::cout << "Exiting program. Goodbye!\n";
    return 0;
}

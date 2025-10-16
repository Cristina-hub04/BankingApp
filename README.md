# BankingApp

## Project Overview
**BankingApp** is a console-based banking application written in **C++**.  
It allows users to **create accounts, deposit, withdraw, transfer money, and check balances**.  
The project includes **black-box and white-box testing** to ensure correctness and reliability.

---

## Agile Workflow

### User Stories
- As a user, I want to **create an account** so I can store my balance.  
- As a user, I want to **deposit money** so I can increase my balance.  
- As a user, I want to **withdraw money** so I can spend my balance.  
- As a user, I want to **transfer money** so I can move funds between accounts.  
- As a user, I want to **check my balance** so I can monitor my funds.  

---

### Sprints

**Sprint 1: Core Banking Functions**
- Implemented `Bank` class  
- Created account creation, deposit, and withdraw functions  
- Tested basic functionality  

**Sprint 2: Extended Functionality**
- Implemented transfer between accounts  
- Added check balance function  
- Handled edge cases for invalid inputs  

**Sprint 3: Testing & Validation**
- Developed **black-box tests** (functional testing of the public API)  
- Developed **white-box tests** (edge cases, invalid inputs, logic coverage)  
- Added input validation and error handling  

---

### Daily Progress

| Day   | Tasks Completed |
|-------|----------------|
| Day 1 | Designed Bank class and account structure |
| Day 2 | Implemented deposit and withdraw functions |
| Day 3 | Added transfer and check balance functions |
| Day 4 | Developed main menu and handled invalid inputs |
| Day 5 | Created automated tests (black-box & white-box), documented Agile workflow |

---

## How to Compile and Run

1. Open terminal in the project folder.  

2. Compile main program:

```bash
g++ main.cpp bank.cpp -o BankingApp

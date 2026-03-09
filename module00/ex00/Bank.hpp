#ifndef BANK_HPP
#define BANK_HPP

#include "Account.hpp"
#include <iostream>
#include <vector>

class Account;

class Bank {
public:
    Bank();
    Bank(const Bank& other);
    Bank& operator=(const Bank& other);
    ~Bank();

    Account* createAccount();
    bool deleteAccount(int id);
    void deposit(Account& account, int amount);
    bool withdraw(Account& account, int amount);
    bool borrow(Account& account, int amount);
    bool repay(Account& account, int amount);
    int getLiquidity() const;

     friend std::ostream& operator<<(std::ostream& os, const Bank& bank);
private:
	int liquidity;
    int nextId;
	std::vector<Account *> clientAccounts;
};

#endif

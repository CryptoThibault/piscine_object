#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "Bank.hpp"
#include <iostream>

class Account {
public:
    Account(int accountId);
    Account(const Account& other);
    Account& operator=(const Account& other);
    ~Account();

    int getId() const;
    int getValue() const;
    int getLoan() const;

    friend std::ostream& operator<<(std::ostream& os, const Account& account);
private:
	int id;
	int value;
    int loan;
    friend class Bank;
};

#endif

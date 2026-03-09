#include "Account.hpp"

Account::Account(int accountId) : id(accountId), value(0), loan(0) {}

Account::Account(const Account& other) : id(other.id), value(other.value), loan(other.loan) {}

Account& Account::operator=(const Account& other) {
    if (this != &other) {
        id = other.id;
        value = other.value;
    }
    return *this;
}

Account::~Account() {}

int Account::getId() const {
    return id;
}

int Account::getValue() const {
    return value;
}

int Account::getLoan() const { 
    return loan;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "Account ID: " << account.getId()
       << ", Value: " << account.getValue()
       << ", Loan: " << account.getLoan();
    return os;
}
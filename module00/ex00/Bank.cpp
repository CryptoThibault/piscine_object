#include "Bank.hpp"

Bank::Bank() : liquidity(0), nextId(0) {}

Bank::Bank(const Bank& other) : liquidity(other.liquidity), nextId(other.nextId) {
    for (size_t i = 0; i < other.clientAccounts.size(); i++) {
        Account* newAcc = new Account(*other.clientAccounts[i]);
        clientAccounts.push_back(newAcc);
    }
}

Bank& Bank::operator=(const Bank& other) {
    if (this != &other) {
        for (size_t i = 0; i < clientAccounts.size(); i++)
            delete clientAccounts[i];
        clientAccounts.clear();

        liquidity = other.liquidity;
        nextId = other.nextId;

        for (size_t i = 0; i < other.clientAccounts.size(); i++)
            clientAccounts.push_back(new Account(*other.clientAccounts[i]));
    }
    return *this;
}

Bank::~Bank() {
    for(size_t i = 0; i < clientAccounts.size(); i++)
        delete clientAccounts[i];
    clientAccounts.clear();
}

Account* Bank::createAccount() {
    int newId = nextId++;
    Account* acc = new Account(newId);
    clientAccounts.push_back(acc);
    return acc;
}

bool Bank::deleteAccount(int id) {
    for(size_t i = 0; i < clientAccounts.size(); ++i) {
        if(clientAccounts[i]->getId() == id) {
            delete clientAccounts[i];
            clientAccounts.erase(clientAccounts.begin() + i);
            return true;
        }
    }
    return false;
}

void Bank::deposit(Account& account, int amount) {
    int fee = amount * 5 / 100;
    account.value += (amount - fee);
    liquidity += fee;
}

bool Bank::withdraw(Account& account, int amount) {
    if (account.value < amount)
        return false;
    account.value -= amount;
    return true;
}

bool Bank::borrow(Account& account, int amount) {
    if (amount > liquidity)
        return false;
    account.value += amount;
    account.loan += amount;
    liquidity -= amount;
    return true;
}

bool Bank::repay(Account& account, int amount) {
    if (amount > account.value || amount > account.loan)
        return false;
    account.value -= amount;
    account.loan -= amount;
    liquidity += amount;
    return true;
}

int Bank::getLiquidity() const {
    return liquidity;
}

std::ostream& operator<<(std::ostream& os, const Bank& bank) {
    os << "Bank liquidity: " << bank.liquidity << "\n";
    os << "Client accounts:\n";
    for (size_t i = 0; i < bank.clientAccounts.size(); ++i)
        os << "  " << *bank.clientAccounts[i] << "\n";
    return os;
}
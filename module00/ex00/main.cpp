#include <iostream>
#include "Bank.hpp"
#include "Account.hpp"

int main() {
    Bank bank;

    Account* acc1 = bank.createAccount();
    Account* acc2 = bank.createAccount();

	std::cout << "\nDEPOSIT" << std::endl;
    bank.deposit(*acc1, 1000);
    bank.deposit(*acc2, 500);
    std::cout << bank << std::endl;
	
	std::cout << "\nWITHDRAW" << std::endl;
    if (!bank.withdraw(*acc1, 200))
		std::cout << "Account 1 : Withdraw impossible" << std::endl;
    if (!bank.withdraw(*acc2, 600))
		std::cout << "Account 2 : Withdraw impossible" << std::endl;
    std::cout << bank << std::endl;

	std::cout << "\nBORROW" << std::endl;
    if (!bank.borrow(*acc1, 50))
        std::cout << "Account 1 : Borrow impossible" << std::endl;
    if (!bank.borrow(*acc1, 1000))
        std::cout << "Account 2 : Borrow impossible" << std::endl;
    std::cout << bank << std::endl;

	std::cout << "\nREPAY" << std::endl;
    if (!bank.repay(*acc1, 30))
        std::cout << "Account 1 : Repay impossible" << std::endl;
    if (!bank.repay(*acc1, 1000))
        std::cout << "Account 2 : Repay impossible" << std::endl;
    std::cout << bank << std::endl;

	std::cout << "\nDELETE" << std::endl;
	if (!bank.deleteAccount(acc1->getId()))
        std::cout << "Account 1 : Delete impossible" << std::endl;
	if (!bank.deleteAccount(acc1->getId()))
        std::cout << "Account 1 : Delete impossible" << std::endl;
    std::cout << bank << std::endl;

    return 0;
}
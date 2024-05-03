/**
 * @file Account.cpp
 * @brief Implementation file for the Account class.
 *
 * This file contains the implementation of the Account class, which represents
 * a bank account. It includes member variables for the account index, amount,
 * number of deposits, and number of withdrawals. The class also provides
 * methods for making deposits, withdrawals, and displaying the account status.
 * Additionally, it includes static member variables for tracking the total
 * number of accounts, total amount, total number of deposits, and total number
 * of withdrawals. The file also defines helper functions for formatting strings
 * and displaying timestamps.
 */
#include "Account.hpp"
#include <vector>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * vector of pointers to Account objects to store all the accounts and print 
 * the account index and amount when an account is created or closed.
 * Necessary to avoit objects destruction with "stack unwinding" process.
*/
std::vector<Account::t*> _accounts;

/**
 * @brief Formats and prints a string and an integer value.
 *
 * This function takes a string and an integer value as input,
 * and prints them to the standard output. The string is printed first,
 * followed by the integer value, without any spaces or other characters in between.
 *
 * @param str The string to be printed.
 * @param value The integer value to be printed.
 */

static void formatStr(std::string str, int value)
{
	std::cout << str;
	std::cout << value;
}

/**
 * @brief Displays the current timestamp.
 *
 * This method retrieves the current time and formats it into a timestamp,
 * which is then printed to the standard output. The timestamp is in the format
 * "YYYYMMDDhhmmss", where "YYYY" is the four-digit year, "MM" is the two-digit month,
 * "DD" is the two-digit day, "hh" is the two-digit hour, "mm" is the two-digit minute,
 * and "ss" is the two-digit second.
 */
void Account::_displayTimestamp(void)
{
	char strTime[20];
	std::time_t now;
	std::tm* localtm;

	now = std::time(NULL);
	localtm = std::localtime(&now);
	std::strftime(strTime, sizeof(strTime), "[%Y%m%d_%H%M%S] ", localtm);
	std::cout << strTime;
}

/*
 * * Constructor initializer lists
 * This method has several advantages:
 * Efficiency: When you use an initializer list, the member variables are
 * initialized directly when they are created. If you use assignment in the
 * constructor body, the member variables are first created and then assigned a
 * value, which can be less efficient.
 * 
 * Const and reference variables: In C++, const and reference variables must be
 * initialized when they are declared. This can only be done using an initializer
 * list.
 * 
 * Order of initialization: The order of initialization of member variables is
 * determined by the order in which they are declared in the class, not the order
 * in which they appear in the initializer list. Using an initializer list makes it
 * clear that the order of initialization is not determined by the order of
 * assignment in the constructor body.
 * 
 * Uniform initialization: Initializer lists allow you to use uniform
 * initialization (using braces {}), which can prevent narrowing conversions.
 * 
 * Therefore, it's generally considered best practice in C++ to use an initializer
 * list to initialize member variables in a constructor.
*/
Account::Account(void)
{

}

/**
 * @brief Constructs an Account object with the specified initial deposit.
 * 
 * This constructor initializes the Account object with the given initial deposit.
 * It also updates the account index, number of deposits, number of withdrawals,
 * and adds the account to the list of accounts.
 * 
 * @param initial_deposit The initial deposit amount for the account.
 */
Account::Account(int initial_deposit) :
_accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	// _accounts.push_back(this);
	_totalAmount += initial_deposit;
	_displayTimestamp();
	formatStr("index:", _accountIndex);
	formatStr(";amount:", _amount);
	std::cout << ";created" << std::endl;
}

/*
 *The order in which constructors and destructors are called is determined by
 * the order in which objects are created and destroyed. 

 * In C++, objects are destroyed in the reverse order of their creation. This is
 * known as the "stack unwinding" process.
 *
*/

/**
 * @brief Destructor for the Account class.
 *
 * This destructor is responsible for closing an account and updating the number
 * of accounts. If the account is not empty, it displays the timestamp, account
 * index, amount, and closes the account.
 */
// Account::~Account(void)
// {
// 	_nbAccounts--;
// 	if (!_accounts.empty())
// 	{
// 		_displayTimestamp();
// 		formatStr("index:", (*_accounts.begin())->_accountIndex);
// 		formatStr(";amount:", (*_accounts.begin())->_amount);
// 		std::cout << ";closed"<< std::endl;
// 		_accounts.erase(_accounts.begin());
// 		return ;
// 	}
// }
Account::~Account(void)
{
	_nbAccounts--;
	_displayTimestamp();
	formatStr("index:", _accountIndex);
	formatStr(";amount:", _amount);
	std::cout << ";closed"<< std::endl;
}

/**
 * @brief Makes a deposit into the account.
 * 
 * @param deposit The amount to deposit.
 */
void Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	formatStr("index:", _accountIndex);
	formatStr(";p_amount:", _amount - deposit);
	formatStr(";deposit:", deposit);
	formatStr(";amount:", _amount);
	formatStr(";nb_deposits:", _nbDeposits);
	std::cout << std::endl;
}

/**
 * @brief Makes a withdrawal from the account.
 * 
 * @param withdrawal The amount to be withdrawn.
 * @return true if the withdrawal was successful, false otherwise.
 */
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	formatStr("index:", _accountIndex);
	if (_amount < withdrawal)
	{
		formatStr(";p_amount:", _amount);
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	formatStr(";p_amount:", _amount + withdrawal);
	formatStr(";withdrawal:", withdrawal);
	formatStr(";amount:", _amount);
	formatStr(";nb_withdrawals:", ++_nbWithdrawals);
	std::cout << std::endl;
	return true;
}

/**
 * @brief Displays the status of the account.
 *
 * This function displays the current status of the account, including the
 * account holder's name, account number, balance, and total number of deposits
 * and withdrawals.
 */
void Account::displayStatus(void) const
{
	_displayTimestamp();
	formatStr("index:", _accountIndex);
	formatStr(";amount:", _amount);
	formatStr(";deposits:", _nbDeposits);
	formatStr(";withdrawals:", _nbWithdrawals);
	std::cout << std::endl;
}

/**
 * @brief Displays the information of all the accounts.
 * 
 * This function displays the timestamp, number of accounts, total amount,
 * total number of deposits, and total number of withdrawals.
 */
void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	formatStr("accounts:", _nbAccounts);
	formatStr(";total:", _totalAmount);
	formatStr(";deposits:", _totalNbDeposits);
	formatStr(";withdrawals:", _totalNbWithdrawals);
	std::cout << std::endl;
}

/**
 * @brief Get the current amount in the account.
 * 
 * @return int The current amount in the account.
 */
int Account::checkAmount(void) const
{
	return _amount;
}

/**
 * @brief Returns the total number of accounts created.
 * 
 * @return int The total number of accounts.
 */
int Account::getNbAccounts(void) {
	return _nbAccounts;
}

/**
 * @brief Returns the total amount of money in the account.
 * 
 * @return int The total amount of money in the account.
 */
int Account::getTotalAmount(void) {
	return _totalAmount;
}

/**
 * @brief Get the number of deposits made in the account.
 * 
 * @return int The number of deposits made.
 */
int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

/**
 * @brief Get the number of withdrawals made from the account.
 * 
 * @return int The number of withdrawals made.
 */
int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

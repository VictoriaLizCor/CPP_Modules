#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// static void formatStr()
// {

// }

void Account::_displayTimestamp(void)
{
	char strTime[20];
	std::time_t now;
	std::tm* localtm;

	now = std::time(NULL);
	localtm = std::localtime(&now);
	std::strftime(strTime, sizeof(strTime), "[%Y%m%d_%H%M%S]", localtm);
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
Account::Account(int initial_deposit) :
_accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

/*
 *The order in which constructors and destructors are called is determined by
 * the order in which objects are created and destroyed. 

 * In C++, objects are destroyed in the reverse order of their creation. This is
 * known as the "stack unwinding" process.
 *
*/
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}


void Account::makeDeposit(int deposit) {
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << (_amount - deposit) << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (_amount < withdrawal) {
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << (_amount + withdrawal) << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount(void) const {
	return _amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
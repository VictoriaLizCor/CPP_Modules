#include "Account.hpp"
#include <vector>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
std::vector<Account::t*> _accounts;

static void formatStr(std::string str, int value)
{
	std::cout << str;
	std::cout << value;
}

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

Account::Account(int initial_deposit) :
_accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_accounts.push_back(this);
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

Account::~Account(void)
{
	_nbAccounts--;
	if (!_accounts.empty())
	{
		_displayTimestamp();
		formatStr("index:", (*_accounts.begin())->_accountIndex);
		formatStr(";amount:", (*_accounts.begin())->_amount);
		std::cout << ";closed"<< std::endl;
		_accounts.erase(_accounts.begin());
		return ;
	}
}


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

void Account::displayStatus(void) const
{
	_displayTimestamp();
	formatStr("index:", _accountIndex);
	formatStr(";amount:", _amount);
	formatStr(";deposits:", _nbDeposits);
	formatStr(";withdrawals:", _nbWithdrawals);
	std::cout << std::endl;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	formatStr("accounts:", _nbAccounts);
	formatStr(";total:", _totalAmount);
	formatStr(";deposits:", _totalNbDeposits);
	formatStr(";withdrawals:", _totalNbWithdrawals);
	std::cout << std::endl;
}

int Account::checkAmount(void) const
{
	return _amount;
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

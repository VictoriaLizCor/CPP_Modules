#include "GradeExceptions.hpp"

TooHighException::TooHighException(const std::string& msg)
: _msg(msg) {}


TooHighException::~TooHighException() throw() {}
TooLowException::~TooLowException() throw() {}

const char* TooHighException::what() const throw(){
	return _msg.c_str();
}

TooLowException::TooLowException(const std::string& msg)
: _msg(msg) {}

const char* TooLowException::what() const throw()
{
	return _msg.c_str();
}
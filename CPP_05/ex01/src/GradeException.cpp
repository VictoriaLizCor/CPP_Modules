#include "GradeException.hpp"

GradeException::GradeException(const std::string& msg)
: _msg(msg) {}

GradeException::~GradeException() throw() {}

const char* GradeException::what() const throw(){
	return _msg.c_str();
}

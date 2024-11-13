#ifndef DATEUTILS_HPP
#define DATEUTILS_HPP

# include <ctime>
# include <sstream>
# include <stdexcept>
# include <cstring>
# include <Utils.hpp>

bool isLeap(int year);
bool isValidDate(int year, int month, int day);
void checkParseDate(std::string& date, std::tm& tm);
std::time_t getMonthAheadTime(std::tm const& dateTm);
void getCurrentTime(std::time_t& currentTime, std::tm& current);

#endif // DATEUTILS_HPP
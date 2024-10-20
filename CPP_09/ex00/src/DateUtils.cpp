#include "DateUtils.hpp"

/**
 * @brief Checks if a given year is a leap year.
 *
 * A leap year is a year that is evenly divisible by 4, except for years that are evenly divisible by 100.
 * However, years that are evenly divisible by 400 are also leap years.
 *
 * @param year The year to check.
 * @return true if the year is a leap year, false otherwise.
 */
bool isLeap(int year)
{
	if (year % 4 != 0)
		return false;
	if (year % 100 != 0)
		return true;
	if (year % 400 != 0)
		return false;
	return true;
}

/**
 * @brief Checks if a given date is valid.
 *
 * This function verifies whether the provided year, month, and day
 * constitute a valid date. It takes into account leap years when
 * determining the number of days in February.
 *
 * @param year The year of the date to be validated.
 * @param month The month of the date to be validated (1-12).
 * @param day The day of the date to be validated.
 * @return true if the date is valid, false otherwise.
 */
bool isValidDate(int year, int month, int day)
{
	if ((month < 1 || month > 12) || day < 1)
		return false;

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isLeap(year))
		daysInMonth[1] = 29;

	return (day <= daysInMonth[month - 1]);
}

//  if (date.size() != 10 || date[4] != '-' || date[7] != '-')
// 	throw std::runtime_error(errorFmt("Failed to parse date: ")) + line);
/**
 * @brief Parses and validates a date string in the format
 * "YYYY-MM-DD".
 *
 * This function takes a date string and a std::tm structure, parses
 * the date string, validates its format and logical correctness, and
 * then updates the date string to ensure it is in the correct format.
 *
 * @param date A reference to the date string to be parsed and
 * validated.
 * @param tm A reference to a std::tm structure to store the parsed
 * date components.
 *
 * @throws std::runtime_error If the date string is in an invalid
 *                            format or represents an invalid date.
 */
void checkParseDate(std::string& date, std::tm& tm)
{
	std::stringstream ss(date);
	std::memset(&tm, 0, sizeof(std::tm));
	char dash1, dash2;

	if (!(ss >> tm.tm_year >> dash1 >> tm.tm_mon >> dash2 >> tm.tm_mday) || dash1 != '-' || dash2 != '-')
		throw std::runtime_error(errorFmt("Invalid date") + date);
	if (!isValidDate(tm.tm_year, tm.tm_mon, tm.tm_mday))
		throw std::runtime_error(errorFmt("Invalid date") + date);

	char buffer[11];
	tm.tm_year -= 1900;
	tm.tm_mon -= 1;
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tm);
	date = std::string(buffer);
}


/**
 * @brief Calculates the time one month ahead of the given date.
 *
 * This function takes a `std::tm` structure representing a date and
 * returns the `std::time_t` value corresponding to the same date one
 * month ahead.
 *
 * @param dateTm A `std::tm` structure representing the initial date.
 * @return A `std::time_t` value representing the date one month
 * ahead.
 */
std::time_t getMonthAheadTime(const std::tm& dateTm)
{
	std::tm monthAhead = dateTm;
	monthAhead.tm_mon += 1;
	return std::mktime(&monthAhead);
}

/**
 * @brief Retrieves the current time and converts it to a tm
 * structure.
 *
 * This function gets the current time, converts it to a tm structure
 * representing local time, and then converts it back to a time_t
 * value.
 *
 * @param[out] currentTime A reference to a time_t variable where the
 * current time will be stored.
 * @param[out] current A reference to a tm structure where the local
 * time representation will be stored.
 */
void getCurrentTime(std::time_t& currentTime, std::tm& current)
{
	currentTime = std::time(0);
	current = *std::localtime(&currentTime);
	currentTime = std::mktime(&current);
}
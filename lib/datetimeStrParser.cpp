#include "datetimeStrParser.hpp"

#include "boost/date_time/posix_time/posix_time.hpp"

#include <ctime>

namespace eines
{
namespace timeUtils
{

void datetimeStringParser_c::setFormat(const std::string& formatStr_par_con)
{
	//you would think you need to destroy the pointer, but no, imbue does it alone, facets are destroyed
	//automatically
	//http://stackoverflow.com/questions/17779660/who-is-responsible-for-deleting-the-facet
	boost::posix_time::time_input_facet* inputFaced = new boost::posix_time::time_input_facet(formatStr_par_con);
	ss_pri.imbue(std::locale(std::locale(), inputFaced));
}
datetimeStringParser_c::datetimeStringParser_c(
	const std::string& dateTimeStr_par_con
	, const std::string& formatStr_par_con
) :
	dateTimeStr_pri(dateTimeStr_par_con)
{
	setFormat(formatStr_par_con);
}

std::chrono::system_clock::time_point datetimeStringParser_c::getSystemClockTimePoint()
{
	ss_pri << dateTimeStr_pri;
	boost::posix_time::ptime pt;
	ss_pri >> pt;
	tm pt_tm = to_tm(pt);
	auto timestamp(timegm(&pt_tm));
	return std::chrono::system_clock::from_time_t(timestamp);
}
void datetimeStringParser_c::setDatetimeStr(const std::string& dateTimeStr_par_con)
{
	dateTimeStr_pri = dateTimeStr_par_con;
}

}
}



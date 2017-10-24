#ifndef COMU_DATETIMESTRPARSER_H_
#define COMU_DATETIMESTRPARSER_H_

#include <chrono>
#include <string>
#include <sstream>

#ifdef __MINGW32__
#define timegm _mkgmtime
#endif

namespace eines
{
namespace timeUtils
{

class datetimeStringParser_c
{
		std::string dateTimeStr_pri;
		std::stringstream ss_pub;
	public:
		void setFormat(const std::string& formatStr_par_con);
		datetimeStringParser_c() = delete;
		datetimeStringParser_c(
			const std::string& dateTimeStr_par_con
			, const std::string& formatStr_par_con
		);

		void setDatetimeStr(const std::string& dateTimeStr_par_con);
		std::chrono::system_clock::time_point getSystemClockTimePoint();
};

}
}

#endif /* COMU_DATETIMESTRPARSER_H_ */

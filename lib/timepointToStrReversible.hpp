#ifndef COMU_TIMEPOINTTOSTRREVERSIBLE_H_
#define COMU_TIMEPOINTTOSTRREVERSIBLE_H_

#include <chrono>
#include <string>

#ifdef __MINGW32__
#define timegm _mkgmtime
#endif

namespace eines
{
namespace timeUtils
{
//this aren't seconds or any time unit, remember to convert it
//std::chrono::duration_cast<std::chrono::seconds>(eines::timeUtils::start_time.time_since_epoch())
//and then do a .count()
extern const std::chrono::steady_clock::time_point steady_start_time;
//this aren't seconds or any time unit, remember to convert it
//std::chrono::duration_cast<std::chrono::seconds>(eines::timeUtils::start_time.time_since_epoch())
//and then do a .count()
extern const std::chrono::system_clock::time_point system_start_time;

//static const std::chrono::system_clock::time_point staticSystem_start_time_glo =
//    std::chrono::system_clock::now();
//
//std::chrono::system_clock::time_point& staticFunctionSystem_start_time();

struct iso_to_time_point
{
	std::chrono::system_clock::time_point operator()(
	    const std::string& isoStr_par_con) const;
};

struct time_point_to_iso
{
	std::string operator()(
		const std::chrono::system_clock::time_point& time_point_par_con
	) const;
};

}
}

#endif /* COMU_TIMEPOINTTOSTRREVERSIBLE_H_ */

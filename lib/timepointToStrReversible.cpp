#include "timepointToStrReversible.hpp"

#include "boost/date_time/posix_time/posix_time.hpp"

namespace eines
{
namespace timeUtils
{
//this aren't seconds or any time unit, remember to convert it
//std::chrono::duration_cast<std::chrono::seconds>(eines::timeUtils::start_time.time_since_epoch())
//and then do a .count()
const std::chrono::steady_clock::time_point steady_start_time(std::chrono::steady_clock::now());
//this aren't seconds or any time unit, remember to convert it
//std::chrono::duration_cast<std::chrono::seconds>(eines::timeUtils::start_time.time_since_epoch())
//and then do a .count()

const std::chrono::system_clock::time_point system_start_time(std::chrono::system_clock::now());

//std::chrono::system_clock::time_point& staticFunctionSystem_start_time()
//{
//	static std::chrono::system_clock::time_point staticSystem_start_time(std::chrono::system_clock::now());
//	return staticSystem_start_time;
//}

std::chrono::system_clock::time_point iso_to_time_point::operator()(
	const std::string& isoStr_par_con) const
{
	boost::posix_time::ptime t(
		boost::posix_time::time_from_string(
			isoStr_par_con
		)
	);
	tm pt_tm = to_tm(t);

	//struct tm t;
	//strptime(isoStr.c_str(), "%F %T", &t);
	auto timestamp(timegm(&pt_tm));
	return std::chrono::system_clock::from_time_t(timestamp);
}


std::string time_point_to_iso::operator()(
	const std::chrono::system_clock::time_point& time_point_par_con
) const
{
	//that last point is necessary for the adequate "size"
	std::string buf("2011-10-08 07:07:09.");
	time_t time_t_time_point(std::chrono::system_clock::to_time_t(
								 time_point_par_con));
#ifdef __MINGW32__
	strftime(&buf[0], buf.size(), "%Y-%m-%d %H:%M:%S",
			 std::gmtime(&time_t_time_point));
#else
	strftime(&buf[0], buf.size(), "%F %T",
			 std::gmtime(&time_t_time_point));
#endif
	//strftime adds a null byte just because, then text editors begin to fail
	buf.pop_back();
	return buf;
}

}
}



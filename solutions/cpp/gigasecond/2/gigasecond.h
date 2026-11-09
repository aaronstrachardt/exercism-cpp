#pragma once
#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/posix_time/time_parsers.hpp>

namespace gigasecond {

boost::posix_time::ptime advance(boost::posix_time::ptime start);

}  // namespace gigasecond

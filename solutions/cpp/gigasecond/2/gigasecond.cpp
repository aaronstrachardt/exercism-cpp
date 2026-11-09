#include "gigasecond.h"
#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/posix_time/time_parsers.hpp>
#include <string>

namespace gigasecond {

    boost::posix_time::ptime advance(boost::posix_time::ptime start) {
        boost::posix_time::time_duration td = boost::posix_time::seconds(1000000000);
        return start + td;
    }
    
}  // namespace gigasecond

#ifndef ANH_LIB_LOGGER_H_
#define ANH_LIB_LOGGER_H_
// LOG
#include <boost/log/common.hpp>
#include <boost/log/core.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/formatters.hpp>
#include <boost/log/filters.hpp>
#include <boost/log/utility/init/to_console.hpp>
#include <boost/log/utility/init/to_file.hpp>
#include <boost/log/utility/init/common_attributes.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/event_log_backend.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include "anh/logger.h"
//



namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace fmt = boost::log::formatters;
namespace flt = boost::log::filters;
namespace keywords = boost::log::keywords;

enum severity_level
{
    event,
    trace,
    info,
    warning,
    error,
    fatal
};
// The formatting logic for the severity level
template< typename CharT, typename TraitsT >
inline std::basic_ostream< CharT, TraitsT >& operator<< (
std::basic_ostream< CharT, TraitsT >& strm, severity_level lvl)
{
    static const char* const str[] =
    {
        "event"
        "trace",
        "info",
        "warning",
        "error",
        "fatal"
    };
    if (static_cast< std::size_t >(lvl) < (sizeof(str) / sizeof(*str)))
        strm << str[lvl];
    else
        strm << static_cast< int >(lvl);
    return strm;
}

static src::severity_logger<severity_level> SeverityLogger;

#ifdef _DEBUG
#define LOG_NET BOOST_LOG_STREAM_SEV(SeverityLogger, event)
#else
#define LOG_NET BOOST_LOG_STREAM_SEV(SeverityLogger, event)
#endif

#define LOG(level) BOOST_LOG_STREAM_SEV(SeverityLogger, level)

#ifdef _DEBUG
#define DLOG(level) BOOST_LOG_STREAM_SEV(SeverityLogger, level)
#else
#define DLOG(level) BOOST_LOG_STREAM_SEV(SeverityLogger, level)
#endif

namespace anh {

/**
 * A general boost.log initialization logging object
 *
 */

class Logger
{
public:
    static Logger &getInstance();
    /**
     *  Init's the logging sinks and formatters
     *
     * @param string of the application name
     * two files are created in the logs folder of the application
     * one is created as app_name.log containing severity level of info and above
     * the other is created as app_name_warning.log containing severity level of warning and above
     */
    void init(const std::string& app_name);

private:
    Logger() {}
    ~Logger() {}
    Logger(const Logger&);
    Logger &operator=(const Logger &);
};

} // anh

#endif // ANH_LIB_LOGGER_H_
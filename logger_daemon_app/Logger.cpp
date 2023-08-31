#include <boost/log/core.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/sources/severity_logger.hpp>

// Create a file sink
auto sink = boost::log::add_file_log(
    boost::log::keywords::file_name = "%Y%m%d_%H%M%S.log",     // file name
    boost::log::keywords::rotation_size = 1024,                // max file size = 1K bytes
    boost::log::keywords::format = "[%TimeStamp%]: %Message%"  // log message format
);


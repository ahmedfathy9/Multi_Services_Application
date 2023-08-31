#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>


boost::property_tree::ptree pt;
boost::property_tree::ini_parser::read_ini("/etc/my_config.ini", pt);

for (const auto& section : pt) {
    std::string app_name = section.first;
    std::string queue_name = section.second.get<std::string>("Queue.Name");
    // Do something with app_name and queue_name
}


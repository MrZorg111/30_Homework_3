#pragma once
#include <string>
#include <map>

bool check_key(std::string check);
std::string url_updater(std::map<std::string, std::string>& map);
cpr::Payload resp (std::map<std::string, std::string>& map);
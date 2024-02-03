#include <string>
#include <map>
#include <cpr/cpr.h>

bool check_key(std::string check) {
    if (check == "post" || check == "get") {
        return true;
    }
    return false;
}

std::string url_updater(std::map<std::string, std::string>& map) {
    std::string url_adress = "http://httpbin.org/get?", add_url;
    
    for(std::map<std::string, std::string> :: iterator it = map.begin(); it != map.end(); it++) {
        add_url += it->first + "=" + it->second + "&";
    }
    return url_adress + add_url;
}

cpr::Payload resp (std::map<std::string, std::string>& map) {
    cpr::Payload pl({});
    for(std::map<std::string, std::string> :: iterator it = map.begin(); it != map.end(); it++) {
        cpr::Pair p = cpr::Pair(it->first.c_str(), it->second.c_str());
        pl.Add(p);
    }
    return pl;
}
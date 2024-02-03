#include <iostream>
#include <string>
#include <map>
#include <cpr/cpr.h>
#include "Function.h"


int main() {
    std::string key, value, answer = "Into";
    std::map<std::string, std::string> map;
    
    std::cout << "Enter an argument and a value: " << std::endl;
    std::cout << "To send a request, enter: get or post" << std::endl;
    
    do{
    
    std::cout << "The argument: ";
    std::cin >> key;
    

    if(!check_key(key)) {
        std::cout << "Value: ";
        std::cin >> value;
        map.insert(std::pair<std::string, std::string>(key, value));
        continue;
    }
    else {
        if (map.empty()) {
            std::cout << "You have not entered a key and an argument, the request is not possible!" << std::endl;
        }
        else if (key == "get") {
            cpr::Response r = cpr::Get(cpr::Url(url_updater(map)));
            std::cout << r.text << std::endl;
        }
        else {
            cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"), cpr::Payload(resp(map)));
            std::cout << r.text << std::endl;
        }
    }
    std::cout << "Do you want to stop the program? (yes/no)" << std::endl;
    std::cin >> answer;
    map.clear();
    }while(answer != "yes");
    

    return 0;
}
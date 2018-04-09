#include <iostream>
#include "serverlistener.h"
#include <windows.h>
#include "../lib/json/json.hpp"

using json = nlohmann::json;

int main() {
    json j;

    // add a number that is stored as double (note the implicit conversion of j to an object)
    j["pi"] = {"test", "true"};

    std::cout << j << std::endl;
    ServerListener().run();
    return 0;
}


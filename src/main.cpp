#include <iostream>
#include "serverlistener.h"
#include <windows.h>
#include "../lib/json/json.hpp"

using json = nlohmann::json;
using namespace std;

int main() {
    json j;

    // add a number that is stored as double (note the implicit conversion of j to an object)
    j["pi"] = {"test", "true"};
    
    cout << j << endl;
    ServerListener().run();
    return 0;
}


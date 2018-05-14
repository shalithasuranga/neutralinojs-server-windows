#include <iostream>
#include <fstream>
#include "../lib/json/json.hpp"

using namespace std;
using json = nlohmann::json;
json options;

namespace settings {

    json getOptions(){
        return options;
    }

    json getSettings() {
        json settings;
        try {
            ifstream t("app\\settings.json");
            string buffer = "";
            string line = "";
            while(!t.eof()){
                getline(t, line);
                buffer += line + "\r\n";
            }
            t.close();
            settings = json::parse(buffer);


        }
        catch(exception e){
            cout << e.what() << endl;
        }
        //return settings;
        options = settings;
        return options;
    }

}
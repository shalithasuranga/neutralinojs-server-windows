#include <iostream>
#include <fstream>
#include "../../lib/json/json.hpp"
#include <windows.h>

using namespace std;
using json = nlohmann::json;

namespace filesystem {

    string createDirectory(string jso) {
        json input;
        json output;
        try {
            input = json::parse(jso);
        }
        catch(exception e){
            output["error"] = "JSON parse error is occurred!";
            return output.dump();
        }
        string filename = input["name"];
        if(CreateDirectory(filename.c_str(), NULL)){
            output["success"] = filename + " directory was created!";
            return output.dump();
        }
        else{
            output["error"] = "Cannot create " + filename;
            return output.dump();
        }
       
        
    }

    string readFile(string jso) {
        json input;
        json output;
        try {
            input = json::parse(jso);
        }
        catch(exception e){
            output["error"] = "JSON parse error is occurred!";
            return output.dump();
        }
        string filename = input["filename"];
        ifstream t(filename);
        string buffer = "";
        string line = "";
        while(!t.eof()){
            getline(t, line);
            buffer += line + "\r\n";
        }
        t.close();
        output["success"] = "Reading "+ filename + " was succesful.";
        output["content"] = buffer;
        return output.dump();

       
        
    }
}

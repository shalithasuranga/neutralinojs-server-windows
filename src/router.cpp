#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "functions.h"
#include "core/filesystem.h"

using namespace std;
using namespace filesystem;

namespace routes {

    string getClientJs() {
        return "class Neutralino{static createFile(){console.log('done');}}";

    }
    
    string getFile(string file) {
        ifstream t;
        t.open(file);
        string buffer = "";
        string line;
        while(t){
        getline(t, line);
            buffer += line + "\r\n";
        }
        t.close();
        return buffer;
    }

    pair<string, string> handle(string path) {
        if(path == "/"){
            return make_pair(routes::getFile("app\\index.html"), "text/html");
        }
        else if(path == "/neutralino.js"){
            return make_pair(routes::getClientJs(), "text/javascript");
        }
        else {
            vector<string> portions = functions::split(path, '/');
            if(portions.size() == 3) {
                string module = portions[1];
                string func = portions[2];
                //cout << module << "."<< func << endl;
                pfunc f = filesystem::funcmap[module + "." + func];
                string output = (*f)(""); 
                return make_pair(output, "application/json");
            }
        }
        return make_pair(path, "application/json");
    }


}
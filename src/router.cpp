#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "functions.h"
#include "core/filesystem.h"
#include "settings.h"
#include "../lib/json/json.hpp"


using namespace std;
using namespace filesystem;
using json = nlohmann::json;

namespace routes {

    string getClientJs() {
        return "var Neutralino=function(e){var t={};function o(r){if(t[r])return t[r].exports;var n=t[r]={i:r,l:!1,exports:{}};return e[r].call(n.exports,n,n.exports,o),n.l=!0,n.exports}return o.m=e,o.c=t,o.d=function(e,t,r){o.o(e,t)||Object.defineProperty(e,t,{configurable:!1,enumerable:!0,get:r})},o.r=function(e){Object.defineProperty(e,\"__esModule\",{value:!0})},o.n=function(e){var t=e&&e.__esModule?function(){return e.default}:function(){return e};return o.d(t,\"a\",t),t},o.o=function(e,t){return Object.prototype.hasOwnProperty.call(e,t)},o.p=\"\",o(o.s=2)}([function(e,t){e.exports={ajax:function(e){if(e.url)if(e.type){e.method||(e.method=!0),e.debugLog||(e.debugLog=!1);var t=window.XMLHttpRequest?new XMLHttpRequest:new ActiveXObject(\"Microsoft.XMLHTTP\");t.onreadystatechange=function(){4==t.readyState&&200==t.status?(e.success&&e.success(JSON.parse(t.responseText),t.readyState),1==e.debugLog&&console.log(\"SuccessResponse\"),1==e.debugLog&&console.log(\"Response Data:\"+t.responseText)):4==t.readyState&&(1==e.debugLog&&console.log(\"FailureResponse --\\x3e State:\"+t.readyState+\"Status:\"+t.status),e.errorCallback&&e.errorCallback())},sendString=JSON.stringify(e.data),\"GET\"==e.type&&(t.open(\"GET\",e.url+\"?\"+sendString,e.method),t.send(),1==e.debugLog&&console.log(\"GET fired at:\"+e.url+\"?\"+sendString)),\"POST\"==e.type&&(t.open(\"POST\",e.url,e.method),t.setRequestHeader(\"Content-type\",\"application/x-www-form-urlencoded\"),t.send(sendString),1==e.debugLog&&console.log(\"POST fired at:\"+e.url+\" || Data:\"+sendString))}else 1==e.debugLog&&console.log(\"No Default type (GET/POST) given!\");else 1==e.debugLog&&console.log(\"No Url!\")}}},function(e,t,o){let r=o(0);e.exports={createDirectory:(e,t,o)=>{r.ajax({url:\"/filesystem/createDirectory\",type:\"POST\",data:{name:e},success:function(e){t(e)},errorCallback:()=>{o()}})}}},function(e,t,o){let r=o(1);e.exports={filesystem:r}}]);";
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

    pair<string, string> handle(string path, string j) {
        json options = settings::getOptions();
        string appname = options["appname"];
        if(path == "/" +  appname ){
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
                string output = (*f)(j); 
                return make_pair(output, "application/json");
            }
        }
        return make_pair(path, "application/json");
    }


}
var Neutralino=function(e){var t={};function o(r){if(t[r])return t[r].exports;var n=t[r]={i:r,l:!1,exports:{}};return e[r].call(n.exports,n,n.exports,o),n.l=!0,n.exports}return o.m=e,o.c=t,o.d=function(e,t,r){o.o(e,t)||Object.defineProperty(e,t,{configurable:!1,enumerable:!0,get:r})},o.r=function(e){Object.defineProperty(e,"__esModule",{value:!0})},o.n=function(e){var t=e&&e.__esModule?function(){return e.default}:function(){return e};return o.d(t,"a",t),t},o.o=function(e,t){return Object.prototype.hasOwnProperty.call(e,t)},o.p="",o(o.s=5)}([function(e,t){e.exports={ajax:function(e){if(e.url)if(e.type){e.method||(e.method=!0),e.debugLog||(e.debugLog=!1);var t=window.XMLHttpRequest?new XMLHttpRequest:new ActiveXObject("Microsoft.XMLHTTP");t.onreadystatechange=function(){4==t.readyState&&200==t.status?(e.success&&e.success(JSON.parse(t.responseText),t.readyState),1==e.debugLog&&console.log("SuccessResponse"),1==e.debugLog&&console.log("Response Data:"+t.responseText)):4==t.readyState&&(1==e.debugLog&&console.log("FailureResponse --\x3e State:"+t.readyState+"Status:"+t.status),e.errorCallback&&e.errorCallback())},void 0!==e.data&&(sendString=JSON.stringify(e.data)),"GET"==e.type&&(t.open("GET",e.url,e.method),t.send(),1==e.debugLog&&console.log("GET fired at:"+e.url+"?"+sendString)),"POST"==e.type&&(t.open("POST",e.url,e.method),t.setRequestHeader("Content-type","application/x-www-form-urlencoded"),t.send(sendString),1==e.debugLog&&console.log("POST fired at:"+e.url+" || Data:"+sendString))}else 1==e.debugLog&&console.log("No Default type (GET/POST) given!");else 1==e.debugLog&&console.log("No Url!")}}},function(e,t,o){let r=o(0);e.exports={getRamUsage:(e,t)=>{r.ajax({url:"/computer/getRamUsage",type:"GET",success:function(t){e(t)},errorCallback:()=>{t()}})}}},function(e,t,o){let r=o(0);e.exports={runCommand:(e,t,o)=>{r.ajax({url:"/os/runCommand",type:"POST",data:{command:e},success:function(e){t(e)},errorCallback:()=>{o()}})},getEnvar:(e,t,o)=>{r.ajax({url:"/os/getEnvar",type:"POST",data:{name:e},success:function(e){t(e)},errorCallback:()=>{o()}})}}},function(e,t,o){let r=o(0);e.exports={getSettings:(e,t)=>{r.ajax({url:"/settings.json",type:"GET",success:function(t){e(t)},errorCallback:()=>{t()}})}}},function(e,t,o){let r=o(0);e.exports={createDirectory:(e,t,o)=>{r.ajax({url:"/filesystem/createDirectory",type:"POST",data:{name:e},success:function(e){t(e)},errorCallback:()=>{o()}})}}},function(e,t,o){let r=o(4),n=o(3),s=o(2),a=o(1);e.exports={filesystem:r,settings:n,os:s,computer:a}}]);
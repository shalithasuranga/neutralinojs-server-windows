#ifndef COMPUTER_H
#define COMPUTER_H

#include <map>

namespace computer {
    
    typedef string (*pfunc)(string);

    map <string, pfunc> funcmap = {

    };
}

#endif
#include <iostream>

using namespace std;

#include "BMScontrol.h"

int main()
{
    BMScontrol* control = new BMScontrol();
    
    control->launch();
    
    delete control;
}


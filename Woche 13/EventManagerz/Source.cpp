#include <iostream>
#include "EventManager.h"
#include "SimpleEvent.h"
#include "EventWithIntermission.h"
#include "EventWithFixedIntermission.h"

int main() 
{
    EventManager em;

    em.add(new SimpleEvent(7,30,8,30));
    em.add(new EventWithIntermission(15, 10, 18, 30, 31));
    em.add(new EventWithFixedIntermission(9, 17, 10, 30));
    em.add(new EventWithFixedIntermission(10, 11, 14, 10));
   
    std::cout << em.isBusy(7,0);

    return 0;
}

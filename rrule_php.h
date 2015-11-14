#include <phpcpp.h>
#include <iostream>
#include <string>

extern "C" {
    #include "libical/icaltimezone.h"
    #include "libical/icalrecur.h"
}

class RrulePhp : public Php::Base
{
public:
    RrulePhp() { }  
    virtual ~RrulePhp()
    {
        if (icalRecurItt) {
            icalrecur_iterator_free(icalRecurItt);
        }
    }

    void __construct(Php::Parameters &params);
    Php::Value next();

    icaltimetype phpDateTimeToIcalTime(Php::Value datetime);
    Php::Value icalTimeToPhpDateTime(icaltimetype icaltime);

private:
    icalrecur_iterator* icalRecurItt;

};
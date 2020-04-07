#include "rrule_php.h"

void RrulePhp::__construct(Php::Parameters &params)
{
    icaltimetype startDate = phpDateTimeToIcalTime(params[1]);

    icalRecurItt = icalrecur_iterator_new(
        icalrecurrencetype_from_string(params[0]),
        startDate
    );
}

Php::Value RrulePhp::next()
{
    if (!icalRecurItt) {
        return Php::Value(nullptr);
    }

    icaltimetype event = icalrecur_iterator_next(icalRecurItt);

    if (icaltime_is_null_time(event)) {
        icalrecur_iterator_free(icalRecurItt);
        icalRecurItt = nullptr;
        return Php::Value(nullptr);
    }

    return icalTimeToPhpDateTime(event);
}

icaltimetype RrulePhp::phpDateTimeToIcalTime(Php::Value datetime)
{
    if (datetime.type() != Php::Type::Object || !datetime.instanceOf("DateTime")) {
        return icaltime_null_time();    
    }
    icaltimetype icalTime = icaltime_null_time();
    icalTime.year = datetime.call("format", "Y");
    icalTime.month = datetime.call("format", "n");
    icalTime.day = datetime.call("format", "j");
    icalTime.hour = datetime.call("format", "G");
    icalTime.minute = datetime.call("format", "i");
    icalTime.second = datetime.call("format", "s");
    icalTime.is_date = 1;
    icalTime.is_daylight = datetime.call("format", "I");
    icalTime.zone = icaltimezone_get_builtin_timezone( datetime.call("format", "T"));
    return icalTime;
}

Php::Value RrulePhp::icalTimeToPhpDateTime(icaltimetype icalTime)
{

    if (!icaltime_is_valid_time(icalTime)) {
        return Php::Value(nullptr);
    }

    Php::Object datetime("DateTime");
    datetime.call(
        "setDate",
        icalTime.year,
        icalTime.month,
        icalTime.day
    );
    datetime.call(
        "setTime",
        icalTime.hour,
        icalTime.minute,
        icalTime.second
    );

    Php::Object timezone(
        "DateTimeZone", 
        icaltimezone_get_display_name( (icaltimezone*) icalTime.zone ) 
    );
    datetime.call(
        "setTimezone",
        timezone
    );

    return datetime;
}
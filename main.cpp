#include <phpcpp.h>
#include "rrule_php.h"

extern "C" {
    PHPCPP_EXPORT void *get_module() 
    {
        static Php::Extension extension("cc-rrule", "0.0.2");        

        Php::Namespace extNamespace("ContextualCode");

        Php::Class<RrulePhp> rrulephp("Rrule");
        rrulephp.method(
            "__construct",
            &RrulePhp::__construct,
            {
                Php::ByVal("rrule", Php::Type::String),
                Php::ByVal("date", "DateTime")
            }
        );
        rrulephp.method("next", &RrulePhp::next);

        extNamespace.add(std::move(rrulephp));

        extension.add(std::move(extNamespace));

        return extension;
    }
}

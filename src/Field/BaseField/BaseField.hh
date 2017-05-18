#ifndef __BASE_FIELD_HH__
#define __BASE_FIELD_HH__

#include <string>

namespace ORM
{ 
    class BaseField
    {
        public:
            virtual                     ~BaseField() = default;
            virtual bool                isNull() const = 0;
            virtual bool                isAllowedType() const = 0;
            virtual const std::string   getStringValue() const = 0;
    };
}

#endif  /* __BASE_FIELD_HH__ */
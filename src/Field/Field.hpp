#ifndef __FIELD_HH__
#define __FIELD_HH__

#include "BaseField/BaseField.hh"

#include <string>
#include <sstream>

namespace ORM
{
    template<typename T>
    class Field: public BaseField
    {
        public:
                                Field(T t_value):
                                _isNull(false),
                                _isAllowedType(false),
                                _value(t_value)
                                {
                                };
                                ~Field() = default;
            bool                isNull() const override
            {
                return _isNull;
            }
            bool                isAllowedType() const override
            {
                return _isAllowedType;
            }
            const std::string  getStringValue() const override
            {
                std::ostringstream ss;
                ss << _value;

                return ss.str();
            }
        private:
            bool                _isNull;
            bool                _isAllowedType;
            T                   _value;
    };

    // Todo: find an other solution to specialize Field class using a types enum ?
    // Add char, float, long long, double, etc.. types

    template<>
    class Field<int>: public BaseField
    {
        public:
                                Field(int t_value):
                                _isNull(false),
                                _isAllowedType(true),
                                _value(t_value)
                                {
                                };
                                ~Field() = default;
            bool                isNull() const override
            {
                return _isNull;
            }
            bool                isAllowedType() const override
            {
                return _isAllowedType;
            }
            const std::string  getStringValue() const override
            {
                return std::to_string(_value);
            }
        private:
            bool                _isNull;
            bool                _isAllowedType;
            int                 _value;
    };

    template<>
    class Field<std::string>: public BaseField
    {
        public:
                                Field(const std::string& t_value):
                                _isNull(false),
                                _isAllowedType(true),
                                _value(t_value)
                                {
                                };
                                ~Field() = default;
            bool                isNull() const override
            {
                return _isNull;
            }
            bool                isAllowedType() const override
            {
                return _isAllowedType;
            }
            const std::string  getStringValue() const override
            {
                return _value;
            }
        private:
            bool                _isNull;
            bool                _isAllowedType;
            std::string         _value;
    };
}

#endif  /* __FIELD_HH__ */
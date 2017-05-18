#ifndef __TABLE_HH__
#define __TABLE_HH__

#include <string>
#include <unordered_map>

#include "../Field/BaseField/BaseField.hh"

namespace ORM
{
    // Todo: same for sqlAdapterMap
    typedef std::unordered_map<std::string, BaseField&> Fields;
    class Table
    {
        public:
                    Table(const std::string&, const std::string&);
                    ~Table() = default;
            void    addField(const std::string&, BaseField&);
            Fields  getFields() const;
            int     getPrimaryKeyValue() const;
            const   std::string& getTableName() const;
            const   std::string& getPrimaryKeyColumnName() const;
        private:
            int         _primaryKeyValue;
            std::string _tableName;
            std::string _primaryKeyColumnName;
            Fields      _fields;
    };
}

#endif  /* __TABLE_HH__ */
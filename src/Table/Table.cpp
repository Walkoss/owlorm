#include "Table.hh"

ORM::Table::Table(const std::string& t_tableName,
                  const std::string& t_primaryKeyColumnName):
_tableName(t_tableName),
_primaryKeyColumnName(t_primaryKeyColumnName)
{
}

void    ORM::Table::addField(const std::string& t_columnName, ORM::BaseField& t_field)
{
    _fields.insert({t_columnName, t_field});
}

int     ORM::Table::getPrimaryKeyValue() const
{
    return _primaryKeyValue;
}

ORM::Fields ORM::Table::getFields() const
{
    return _fields;
}

const std::string& ORM::Table::getTableName() const
{
    return _tableName;
}

const std::string& ORM::Table::getPrimaryKeyColumnName() const
{
    return _primaryKeyColumnName;
}
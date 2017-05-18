#include "MySqlAdapter.hh"

ORM::MySqlAdapter& ORM::MySqlAdapter::getMySqlAdapter()
{
    static MySqlAdapter instance;

    return instance;
}

void    ORM::MySqlAdapter::connect(const ORM::DBConfiguration& configuration)
{
    sql::Driver *driver;

    driver = get_driver_instance();
    _con = driver->connect(configuration.getHost(), configuration.getUser(), configuration.getPass());
    _con->setSchema(configuration.getDatabaseName());
}

void    ORM::MySqlAdapter::disconnect()
{
    if (_con)
        _con->close();
}

void    ORM::MySqlAdapter::insert(const ORM::Table& tab) const
{
    std::string                 keys;
    std::string                 values;
    std::string                 query;
    sql::PreparedStatement*     pstmt; 
    decltype(auto)              fieldMap = tab.getFields();
    
    for (auto it = fieldMap.begin(); it != fieldMap.end(); ++it)
    {
        ORM::BaseField& field = it->second;
        auto tmpIt = it;
        keys.append(it->first);
        values.append("\"" + (field).getStringValue() + "\"");

        if (++tmpIt != fieldMap.end())
        {
            keys.append(", ");
            values.append(", ");
        }
    }

    query.append("INSERT INTO " + tab.getTableName() + "(" + keys + ")" + " VALUES(" + values + ")");
    pstmt = _con->prepareStatement(query);
    pstmt->executeUpdate();
}

#include "DB.hh"

std::unordered_map<std::string, ORM::MySqlAdapter&> ORM::DB::_sqlAdapterMap
{
    {"mysql", ORM::MySqlAdapter::getMySqlAdapter()}
};

ORM::DB& ORM::DB::getDB()
{
    static DB instance;

    return instance;
}

bool    ORM::DB::connect(const ORM::DBConfiguration& configuration) const
{
    (void) configuration;
    // _sqlAdapterMap[configuration.getDriver()].connect(configuration);
    // Todo: store this configuration to retrieve an adapter with ORM::DB::getSqlAdapter()
    return true;
}

bool    ORM::DB::disconnect() const
{
    // Todo: Call disconnect on adapter
    return true;
}

// ORM::SqlAdapter& ORM::DB::getSqlAdapter() const
// {
//     return 
// }
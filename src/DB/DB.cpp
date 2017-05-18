#include "DB.hh"

std::unordered_map<std::string, ORM::SqlAdapter&> ORM::DB::_sqlAdapterMap
{
    {"mysql", ORM::MySqlAdapter::getMySqlAdapter()}
};

ORM::DB& ORM::DB::getDB()
{
    static DB instance;

    return instance;
}

bool    ORM::DB::connect(const ORM::DBConfiguration& configuration)
{
    try 
    {
        auto it = _sqlAdapterMap.find(configuration.getDriver());
        
        if (it != _sqlAdapterMap.end())
        {
            _sqlAdapter = &it->second;
            _sqlAdapter->connect(configuration);
        }

    } 
    catch (sql::SQLException & e) 
    {
        std::cerr << e.what() << std::endl;

        return false;
    }

    return true;
}

void    ORM::DB::disconnect() const
{
    if (_sqlAdapter)
        _sqlAdapter->disconnect();
}

ORM::DB::~DB() 
{
    disconnect();
}

ORM::SqlAdapter* ORM::DB::getSqlAdapter() const
{
    return _sqlAdapter;
}
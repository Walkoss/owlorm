#include "MySqlAdapter.hh"

ORM::MySqlAdapter& ORM::MySqlAdapter::getMySqlAdapter()
{
    static MySqlAdapter instance;

    return instance;
}

bool    ORM::MySqlAdapter::connect(const ORM::DBConfiguration& configuration)
{
    (void) configuration;
    return true;
}

bool    ORM::MySqlAdapter::disconnect()
{
    return true;
}
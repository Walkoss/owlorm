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
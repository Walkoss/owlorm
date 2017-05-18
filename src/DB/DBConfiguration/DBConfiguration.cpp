#include "DBConfiguration.hh"

const std::string& ORM::DBConfiguration::getDriver() const
{
    return _driver;
}

const std::string& ORM::DBConfiguration::getHost() const
{
    return _host;
}

const std::string& ORM::DBConfiguration::getUser() const
{
    return _user;
}

const std::string& ORM::DBConfiguration::getPass() const
{
    return _pass;
}

const std::string& ORM::DBConfiguration::getDatabaseName() const
{
    return _database_name;
}
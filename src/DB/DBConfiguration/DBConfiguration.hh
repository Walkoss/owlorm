#ifndef __DB_CONFIGURATION_HH__
#define __DB_CONFIGURATION_HH__

#include <string>

namespace ORM
{
  class DBConfiguration
  {
    public:
              std::string   _driver;
              std::string   _host;
              std::string   _user;
              std::string   _pass;
              std::string   _database_name;
        const std::string&  getDriver() const;
        const std::string&  getHost() const;
        const std::string&  getUser() const;
        const std::string&  getPass() const;
        const std::string&  getDatabaseName() const;
        
  };
}

#endif /* __DB_CONFIGURATION_HH__ */
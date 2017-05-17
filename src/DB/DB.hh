#ifndef __DB_HH__
#define __DB_HH__

#include "DBConfiguration/DBConfiguration.hh"
#include "../Adapter/SqlAdapter.hh"
#include "../Adapter/MySql/MySqlAdapter.hh"

#include <unordered_map>
#include <string>

namespace ORM
{
  class DB
  {
    public:
      static  DB&         getDB();
              bool        connect(const DBConfiguration&);
              bool        disconnect() const;
              SqlAdapter* getSqlAdapter() const;

    private:
      SqlAdapter* _sqlAdapter;
      static  std::unordered_map<std::string, ORM::SqlAdapter*>  _sqlAdapterMap;
  };
} 

#endif /* __DB_HH__ */
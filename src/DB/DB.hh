#ifndef __DB_HH__
#define __DB_HH__

#include "DBConfiguration/DBConfiguration.hh"
#include "../Adapter/SqlAdapter.hh"
#include "../Adapter/MySql/MySqlAdapter.hh"

#include <unordered_map>
#include <string>

namespace ORM
{
  typedef std::unordered_map<std::string, ORM::SqlAdapter&> SqlAdapterMap;
  class DB
  {
    public:
      static  DB&         getDB();
              bool        connect(const DBConfiguration&);
              void        disconnect() const;
              SqlAdapter* getSqlAdapter() const;
                          ~DB();

    private:
              SqlAdapter*   _sqlAdapter;
      static  SqlAdapterMap _sqlAdapterMap;
  };
} 

#endif /* __DB_HH__ */
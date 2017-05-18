#ifndef __MY_SQL_ADAPTER_HH__
#define __MY_SQL_ADAPTER_HH__

#include "../SqlAdapter.hh"
#include "../../DB/DBConfiguration/DBConfiguration.hh"

#include <stdexcept>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

namespace ORM
{
  class MySqlAdapter: public SqlAdapter
  {
    public:
      static  MySqlAdapter& getMySqlAdapter();
      void                  connect(const DBConfiguration&) override;
      void                  disconnect() override;
      void                  insert(const Table&) const override;

    private:
      sql::Connection* _con;
  };
}

#endif /* __MY_SQL_ADAPTER_HH__ */
#ifndef __MY_SQL_ADAPTER_HH__
#define __MY_SQL_ADAPTER_HH__

#include "../SqlAdapter.hh"
#include "../../DB/DBConfiguration/DBConfiguration.hh"

namespace ORM
{
  class MySqlAdapter: public SqlAdapter
  {
    public:
      static  MySqlAdapter& getMySqlAdapter();
      bool  connect(const DBConfiguration&) override;
      bool  disconnect() override;
  };
}

#endif /* __MY_SQL_ADAPTER_HH__ */
#ifndef __SQL_ADAPTER_HH__
#define __SQL_ADAPTER_HH__

#include "../DB/DBConfiguration/DBConfiguration.hh"

namespace ORM
{
  class SqlAdapter
  {
    public:
      virtual void  connect(const DBConfiguration&) = 0;
      virtual void  disconnect() = 0;
  };
}

#endif /* __SQL_ADAPTER_HH__ */
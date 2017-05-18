#include "../src/Table/Table.hh"
#include "../src/Field/Field.hpp"

#include "../src/Adapter/MySql/MySqlAdapter.hh"
#include "../src/DB/DB.hh"
#include "../src/DB/DBConfiguration/DBConfiguration.hh"
#include <iostream>

class Utilisateur : public ORM::Table
{

  public:
    ORM::Field<int> userID;
    ORM::Field<std::string> username;
    ORM::Field<char> test;
    Utilisateur(const std::string &t_username)
        : ORM::Table("utilisateurs", "user_id"), userID(0), username(t_username), test('c')
    {
         addField("user_id", userID);
         addField("username", username);
    }
};

int main()
{
    Utilisateur walkoss{"walkoss"};

    std::cout << "Is allowed type: " << walkoss.userID.isAllowedType() << std::endl;
    std::cout << "Value: " << walkoss.userID.getStringValue() << std::endl;
    std::cout << "Is allowed type: " << walkoss.username.isAllowedType() << std::endl;
    std::cout << "Value: " << walkoss.username.getStringValue() << std::endl;
    std::cout << "Is allowed type: " << walkoss.test.isAllowedType() << std::endl;
    std::cout << "Value: " << walkoss.test.getStringValue() << std::endl;

    ORM::DBConfiguration config{"mysql", "db-mysql", "root", "toor", "owlrom"};
    ORM::DB* db = &ORM::DB::getDB();
    db->connect(config);
    db->getSqlAdapter()->insert(walkoss);
} 
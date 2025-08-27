#include<iostream>
using namespace std;
class SaveToMongoDB{//LOW LEVEL MODULE
    public:
    void SaveToDB(string data){
        cout << "save data on mongo DB database===" << data << endl;
    }
};
class SaveToSQLDB{//LOW LEVEL MODULE
public:
    void SaveToDB(string data)
    {
        cout << "save data on SQL DB database===" << data << endl;
    }
};
class UserServices{//HIGH LEVEL MODULE
    private:
        SaveToMongoDB MongoDB;
        SaveToSQLDB Sql;
    public:
    void saveToMongo(string s){
        MongoDB.SaveToDB(s);
    }
    void saveToSQL(string s)
    {
        Sql.SaveToDB(s);
    }
};
int main(){
    UserServices *user;
    user->saveToMongo("trapti");
    user->saveToSQL("patel");
    return 0;
}
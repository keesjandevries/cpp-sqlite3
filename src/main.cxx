#include <iostream>
#include <sqlite3.h>

int main(){
    sqlite3 *db;
    sqlite3_stmt * statement;
    const char * not_used;
    int rc;

    rc=sqlite3_open("mydatabase.db", &db);
    if (rc) {
        std::cerr << "Cannot open database" << std::endl;
        sqlite3_close(db);
        return 1;
    }
    sqlite3_prepare_v2(db,"SELECT * FROM mytable",-1,&statement,&not_used);
    int i =0;
    while (sqlite3_step(statement)==SQLITE_ROW){
            i++;
            std::cout << "row "<< i <<": " <<  sqlite3_column_double(statement, 0) << std::endl;
        }
    sqlite3_finalize(statement);
    std::cout << "Closing database" << std::endl;
    sqlite3_close(db);
    return 0;
}

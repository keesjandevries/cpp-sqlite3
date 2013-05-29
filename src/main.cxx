#include <iostream>
#include <sqlite3.h>

int main(){
    sqlite3 *db;
    int rc;

    rc=sqlite3_open("mydatabase.db", &db);
    if (rc) {
        std::cerr << "Cannot open database" << std::endl;
        sqlite3_close(db);
        return 1;
    }
    std::cout << "Closing database" << std::endl;
    sqlite3_close(db);
    return 0;
}

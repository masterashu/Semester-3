// #include "sqlite3/sqlite3ext.h"
#include "sqlite3/sqlite3.h"
#include <iostream>

using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName) {
    cerr << (const char *)data << endl;
    for (int i = 0; i < argc; i++) {
        cout << (argv[i] ? argv[i] : "NULL") << "\t\t";
    }
    cout << endl;
    return 0;
}

int main() {
    sqlite3 *myDB;
    int rc = sqlite3_open("db1.sqlite3", &myDB);
    if (!rc) {
        string query = "SELECT * FROM books;";
        sqlite3_exec(myDB, query.c_str(), callback, NULL, NULL);
    } else {
        cerr << "Unable to Open Database\n";
        exit(19);
    }
    return 0;
}

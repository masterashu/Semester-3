#include <mysql-cppconn-8/jdbc/cppconn/driver.h>
#include <mysql-cppconn-8/jdbc/mysql_connection.h>
#include <mysql-cppconn-8/jdbc/mysql_driver.h>
#include <mysql-cppconn-8/mysql/jdbc.h>
#include <stdlib.h>
#include <boost/scoped_ptr.hpp>
#include <iostream>
#include <sstream>
#include <stdexcept>
#define DEFAULT_URI "tcp://127.0.0.1"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "A12b14CN"
#define EXAMPLE_DB "test"
using namespace std;
/*
  Usage example for Driver, Connection, (simple) Statement, ResultSet
*/
int main(int argc, const char** argv) {
    const char* url = (argc > 1 ? argv[1] : DEFAULT_URI);
    const string user(argc >= 3 ? argv[2] : EXAMPLE_USER);
    const string pass(argc >= 4 ? argv[3] : EXAMPLE_PASS);
    const string database(argc >= 5 ? argv[4] : EXAMPLE_DB);
    cout << endl;
    cout << "Connector/C++ standalone program example..." << endl;
    cout << endl;
    try {
        sql::Driver* driver = sql::mysql::get_driver_instance();
        /* Using the Driver to create a connection */
        cout << "Creating session on " << url << " ..." << endl << endl;
        boost::scoped_ptr<sql::Connection> con(
            driver->connect(url, user, pass));
        con->setSchema(database);
        boost::scoped_ptr<sql::Statement> stmt(con->createStatement());
        boost::scoped_ptr<sql::ResultSet> res(stmt->executeQuery(
            "SELECT name, roll from test1;"));
        while (res->next()) {
            cout << res->getString("name") << '\t' << res->getString("roll") << endl;
        }
    } catch (sql::SQLException& e) {
        /*
          The JDBC API throws three different exceptions:
        - sql::MethodNotImplementedException (derived from sql::SQLException)
        - sql::InvalidArgumentException (derived from sql::SQLException)
        - sql::SQLException (derived from std::runtime_error)
        */
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "("
             << "EXAMPLE_FUNCTION"
             << ") on line " << __LINE__ << endl;
        /* Use what() (derived from std::runtime_error) to fetch the error
         * message */
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        return EXIT_FAILURE;
    }
    cout << endl;
    return EXIT_SUCCESS;
}

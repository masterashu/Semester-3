#include <mysql-cppconn-8/jdbc/cppconn/driver.h>
#include <mysql-cppconn-8/jdbc/mysql_connection.h>
#include <mysql-cppconn-8/jdbc/mysql_driver.h>
#include <mysql-cppconn-8/mysql/jdbc.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <boost/scoped_ptr.hpp>
#include <fstream>
#include <iostream>
#include "dist/json/json.h"
#define DEFAULT_URI "tcp://127.0.0.1"
#define USER "root"
#define PASS "A12b14CN"
#define DB "test"
#define PORT 8080

using namespace std;

void load_data_to_server() {
    ifstream t("event.json");
    string str((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());
    Json::Reader reader;
    Json::Value events(Json::arrayValue);
    reader.parse(str, events, false);

    if (events.size() == 0) {
        cerr << "Events.json is empty\n";
        return;
    }
    const char* url = (DEFAULT_URI);
    const string user(USER);
    const string pass(PASS);
    const string database(DB);
    try {
        sql::Driver* driver = sql::mysql::get_driver_instance();
        /* Using the Driver to create a connection */
        cout << "Creating to MySQL Server on " << url << " ..." << endl << endl;
        boost::scoped_ptr<sql::Connection> con(
            driver->connect(url, user, pass));
        con->setSchema(database);
        boost::scoped_ptr<sql::Statement> stmt(con->createStatement());
        boost::scoped_ptr<sql::ResultSet> res(
            stmt->executeQuery("SELECT count(*) as count from events;"));
        res->next();
        if (res->getInt("count") == 0) {
            res->close();
            for (unsigned int i = 0; i < events.size(); i++) {
                Json::Value event = events[i];
                string insertQuery =
                    "INSERT INTO events VALUES (" + event["id"].asString() +
                    ", \"" + event["title"].asString() + "\", \"" +
                    event["start_time"].asString() + "\", \"" +
                    event["end_time"].asString() + "\"," +
                    event["max_participants"].asString() + ");";
                cout << "Running: " << insertQuery << endl;
                stmt->execute(insertQuery);
            }
        } else {
            cout << "Data is Already Loaded!" << endl;
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
        return;
    }
}

bool check_existing_registration(int person_id, int event_id) {
    const char* url = (DEFAULT_URI);
    const string user(USER);
    const string pass(PASS);
    const string database(DB);
    try {
        sql::Driver* driver = sql::mysql::get_driver_instance();
        /* Using the Driver to create a connection */
        cout << "Creating to MySQL Server on " << url << " ..." << endl << endl;
        boost::scoped_ptr<sql::Connection> con(
            driver->connect(url, user, pass));
        con->setSchema(database);
        boost::scoped_ptr<sql::Statement> stmt(con->createStatement());
        boost::scoped_ptr<sql::ResultSet> res(stmt->executeQuery(
            "SELECT count(*) as count from registration where person=" +
            to_string(person_id) + " AND event =" + to_string(event_id) + ";"));
        res->next();
        if (res->getInt("count") == 0) {
            res->close();
            return true;
        } else {
            res->close();
            return false;
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
        return false;
    }
}

bool check_ug(int person_id, int ug) {
    const char* url = (DEFAULT_URI);
    const string user(USER);
    const string pass(PASS);
    const string database(DB);
    try {
        sql::Driver* driver = sql::mysql::get_driver_instance();
        /* Using the Driver to create a connection */
        cout << "Creating to MySQL Server on " << url << " ..." << endl << endl;
        boost::scoped_ptr<sql::Connection> con(
            driver->connect(url, user, pass));
        con->setSchema(database);
        boost::scoped_ptr<sql::Statement> stmt(con->createStatement());
        boost::scoped_ptr<sql::ResultSet> res(stmt->executeQuery(
            "SELECT ug from person where id=" + to_string(person_id) +
            ";"));
        res->next();
        if (res->getInt("ug") == ug) {
            res->close();
            return true;
        } else {
            res->close();
            return false;
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
        return false;
    }
}

bool add_registration(int event_id, int person_id) {
    const char* url = (DEFAULT_URI);
    const string user(USER);
    const string pass(PASS);
    const string database(DB);
    try {
        sql::Driver* driver = sql::mysql::get_driver_instance();
        /* Using the Driver to create a connection */
        cout << "Creating to MySQL Server on " << url << " ..." << endl << endl;
        boost::scoped_ptr<sql::Connection> con(
            driver->connect(url, user, pass));
        con->setSchema(database);
        boost::scoped_ptr<sql::Statement> stmt(con->createStatement());
        boost::scoped_ptr<sql::ResultSet> req(
            stmt->executeQuery("SELECT max_participants FROM events WHERE id = " +
                               to_string(event_id) + ";"));
        req->next();
        float max_participants = req->getInt("max_participants");
        req->close();
        boost::scoped_ptr<sql::ResultSet> req1(stmt->executeQuery(
            "SELECT count(*) as count FROM registration LEFT JOIN person ON "
            "person.id = registration.person AND gender=\"male\" AND registration.event = " +
            to_string(event_id) + ";"));
        req1->next();
        float male_count = req1->getInt("count");
        req1->close();
        boost::scoped_ptr<sql::ResultSet> req2(stmt->executeQuery(
            "SELECT count(*) as count FROM registration LEFT JOIN person ON "
            "person.id = registration.person AND gender=\"female\" AND registration.event = " +
            to_string(event_id) + ";"));
        req2->next();
        float female_count = req2->getInt("count");
        req2->close();
        if ((male_count + 1) / max_participants < 0.6 &&
            (male_count + female_count + 1) <= 1) {
            string insertQuery = "INSERT INTO registration VALUES (" +
                                 to_string(person_id) + "," +
                                 to_string(event_id) + ");";
            cout << "Running: " << insertQuery << endl;
            stmt->execute(insertQuery);
            return true;
        }
        else {
            return false;
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
        return false;
    } catch (exception e) {
        return false;
    }
    return false;
}

int main(int argc, char const* argv[]) {
    load_data_to_server();
    // Server side C/C++ program to demonstrate Socket programming
    Json::Reader reader;
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[2048] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address,
                             (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    // Console
    while (true) {
        valread = read(new_socket, buffer, 2048);
        printf("%d: %s\n", valread, buffer);
        string request(buffer);
        if (request == "end") {
            cout << "Client Disconnected!\n";
            return 0;
        }
        Json::Value reg;
        reader.parse(request, reg, false);
        string action = reg["action"].asString();
        if (action == "register") {
            // Checking Event
            int event_id = reg["event_id"].asInt();
            int person_id = reg["person_id"].asInt();

            if (event_id == 1) {  // Paper Presentation
                // Checking existing registration
                if (check_existing_registration(person_id, 1) ||
                    check_existing_registration(person_id, 2)) {
                    if (check_ug(person_id, 4)) {
                        if (add_registration(event_id, person_id)) {
                            char registration_success[] =
                                "Registration Successful!\n";
                            send(new_socket, registration_success,
                                 strlen(registration_success), 0);
                        } else {
                            char limit_exceeded[] =
                                "Sorry Registrations are full!\n";
                            send(new_socket, limit_exceeded,
                                 strlen(limit_exceeded), 0);
                        }

                    } else {
                        char ug_criteria_not_met[] = "Only UG4 can register!\n";
                        send(new_socket, ug_criteria_not_met,
                             strlen(ug_criteria_not_met), 0);
                    }
                } else {
                    char already_registered[] =
                        "You have already registered for this or Poster "
                        "Event.!\n";
                    send(new_socket, already_registered,
                         strlen(already_registered), 0);
                }
            }
            if (event_id == 2) {
                if (check_existing_registration(person_id, 1) ||
                    check_existing_registration(person_id, 2)) {
                    if (check_ug(person_id, 4)) {
                        if (add_registration(event_id, person_id)) {
                            char registration_success[] =
                                "Registration Successful!\n";
                            send(new_socket, registration_success,
                                 strlen(registration_success), 0);
                        } else {
                            char limit_exceeded[] =
                                "Sorry Registrations are full!\n";
                            send(new_socket, limit_exceeded,
                                 strlen(limit_exceeded), 0);
                        }

                    } else {
                        char ug_criteria_not_met[] = "Only UG4 can register!\n";
                        send(new_socket, ug_criteria_not_met,
                             strlen(ug_criteria_not_met), 0);
                    }
                } else {
                    char already_registered[] =
                        "You have already registered for this or Paper "
                        "Event.!\n";
                    send(new_socket, already_registered,
                         strlen(already_registered), 0);
                }
            }
            if (event_id == 3) {
                if (add_registration(event_id, person_id)) {
                    char registration_success[] = "Registration Successful!\n";
                    send(new_socket, registration_success,
                         strlen(registration_success), 0);
                } else {
                    char limit_exceeded[] = "Sorry Registrations are full!\n";
                    send(new_socket, limit_exceeded, strlen(limit_exceeded), 0);
                }
            }
            if (event_id == 4) {
                if (add_registration(event_id, person_id)) {
                    char registration_success[] = "Registration Successful!\n";
                    send(new_socket, registration_success,
                         strlen(registration_success), 0);
                } else {
                    char limit_exceeded[] = "Sorry Registrations are full!\n";
                    send(new_socket, limit_exceeded, strlen(limit_exceeded), 0);
                }
            }
        } else {
            char error[] = "Unsupported Request!\n";
            send(new_socket, error, strlen(error), 0);
        }
    }

    return 0;
}

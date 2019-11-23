#include <arpa/inet.h>
#include <bits/stdc++.h>
#include <mysql-cppconn-8/jdbc/cppconn/driver.h>
#include <mysql-cppconn-8/jdbc/mysql_connection.h>
#include <mysql-cppconn-8/jdbc/mysql_driver.h>
#include <mysql-cppconn-8/mysql/jdbc.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <boost/scoped_ptr.hpp>
#include "dist/json/json.h"
#define PORT 8080
#define DEFAULT_URI "tcp://127.0.0.1"
#define USER "root"
#define PASS "A12b14CN"
#define DB "test"

using namespace std;

class Participant {
    string name;
    string address;
    string gender;
    string email;
    string mobile;
    int ug;

   public:
    Participant() {
        name = "";
        address = "";
        gender = "";
        email = "";
        mobile = "";
    }

    Participant(string name,
                string address,
                string gender,
                string email,
                string mobile,
                int ug)
        : name(name),
          address(address),
          gender(gender),
          email(email),
          mobile(mobile),
          ug(ug) {}

    int get_ug() { return this->ug; }

    void set_ug(int ug) { this->ug = ug; }

    string get_mobile() { return this->mobile; }

    void set_mobile(string mobile) { this->mobile = mobile; }

    string get_email() { return this->email; }

    void set_email(string email) { this->email = email; }

    string get_gender() { return this->gender; }

    void set_gender(string gender) { this->gender = gender; }

    string get_address() { return this->address; }

    void set_address(string address) { this->address = address; }

    string get_name() { return this->name; }

    void set_name(string name) { this->name = name; }
};

class Event {
   protected:
    string title;
    string start_time;
    string end_time;
    int max_participants;

   public:
    Event()
        : title("Event"),
          start_time("2019-01-01 12:00:00"),
          end_time("2019-01-01 12:00:00"),
          max_participants(20){};
    Event(string title,
          string start_time,
          string end_time,
          int max_participants)
        : title(title),
          start_time(start_time),
          end_time(end_time),
          max_participants(max_participants){};
    int get_max_participants() { return this->max_participants; }

    void set_max_participants(int max_participants) {
        this->max_participants = max_participants;
    }

    string get_end_time() { return this->end_time; }

    void set_end_time(string end_time) { this->end_time = end_time; }

    string get_start_time() { return this->start_time; }

    void set_start_time(string start_time) { this->start_time = start_time; }

    string get_title() { return this->title; }

    void set_title(string title) { this->title = title; }
};

class PaperPresentation : public Event {
   public:
    PaperPresentation()
        : Event("Paper Presentation",
                "2019-12-01 10:00:00",
                "2019-12-01 10:15:00",
                10) {}
    PaperPresentation(string start_time, string end_time, int max_participants)
        : Event("Paper Presentation", start_time, end_time, max_participants) {}
};

class PosterPresentation : public Event {
   public:
    PosterPresentation()
        : Event("Poster Presentation",
                "2019-12-01 10:00:00",
                "2019-12-01 10:15:00",
                10) {}
    PosterPresentation(string start_time, string end_time, int max_participants)
        : Event("Poster Presentation", start_time, end_time, max_participants) {
    }
};

class Quiz : public Event {
   public:
    Quiz() : Event("Quiz", "2019-12-01 15:00:00", "2019-12-01 15:30:00", 20) {}
    Quiz(string start_time, string end_time, int max_participants)
        : Event("Quiz", start_time, end_time, max_participants) {}
};

class CulturalProgram : public Event {
   public:
    CulturalProgram()
        : Event("Cultural Program",
                "2019-12-01 10:00:00",
                "2019-12-01 10:00:00",
                10) {}
    CulturalProgram(string start_time, string end_time, int max_participants)
        : Event("Cultural Program", start_time, end_time, max_participants) {}
};

class Registration {
   public:
    vector<string> get_event_list() {
        ifstream t("event.json");
        string str((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());
        Json::Reader reader;
        Json::Value events(Json::arrayValue);
        reader.parse(str, events, false);
        vector<string> events_list;
        for (unsigned int i = 0; i < events.size(); i++) {
            string event = events[i]["id"].asString() + ". " +
                           events[i]["title"].asString() + "\t\tFrom " +
                           events[i]["start_time"].asString() + " To " +
                           events[i]["end_time"].asString();
            events_list.push_back(event);
        }
        return events_list;
    }

    string get_person_detail(int id) {
        const char* url = (DEFAULT_URI);
        const string user(USER);
        const string pass(PASS);
        const string database(DB);
        try {
            sql::Driver* driver = sql::mysql::get_driver_instance();
            /* Using the Driver to create a connection */
            // cout << "Creating to MySQL Server on " << url << " ..." << endl
            // << endl;
            boost::scoped_ptr<sql::Connection> con(
                driver->connect(url, user, pass));
            con->setSchema(database);
            boost::scoped_ptr<sql::Statement> stmt(con->createStatement());
            boost::scoped_ptr<sql::ResultSet> res(stmt->executeQuery(
                "SELECT * FROM person where id=" + to_string(id) + ";"));
            if (res->next()) {
                string person = "Id:\t" + res->getString("id") + "\nName:\t" +
                                res->getString("name") + "\nGender:\t" +
                                res->getString("gender") + "\nEmail:\t" +
                                res->getString("email") + "\nMobile:\t" +
                                res->getString("mobile") + "\nUG:\t" +
                                res->getString("ug");
                res->close();
                return person;
            } else {
                cout << "Not Found" << endl;
                res->close();
                return "";
            }

        } catch (sql::SQLException& e) {
            /*
              The JDBC API throws three different exceptions:
            - sql::MethodNotImplementedException (derived from
            sql::SQLException)
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
            return "";
        }
    }
};

int main() {
    // Creating Socket
    Registration registration;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    string hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cout << "\n Socket creation error \n";
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        cout << "\nInvalid address/ Address not supported \n";
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        cout << "\nConnection Failed \n";
        return -1;
    }
    // Sample Requests/Resposes
    // send(sock, hello, hello.length(), 0);
    // cout << "Hello message sent\n";
    // valread = read(sock, buffer, 1024);
    // cout << "%s\n", buffer;
    // Prompt
    int choice = 1;
    while (choice) {
        cout << "Enter 1 to Register for Event:\n";
        cout << "Enter 0 to Exit:\n";
        cin >> choice;
        if (choice == 1) {
            vector<string> events = registration.get_event_list();
            for (unsigned int i = 0; i < events.size(); i++) {
                cout << events[i] << endl;
            }
            cout << "Choose Event: ";
            unsigned int ev;
            cin >> ev;
            if (ev <= events.size()) {
                cout << "Enter your ID number: ";
                int id;
                cin >> id;
                cout << "Verify your Details: \n";
                string person = registration.get_person_detail(id);
                if (person != "") {
                    cout << person << endl;
                    cout << "Confirm Registration? (y/n): ";
                    char verify;
                    cin >> verify;
                    if (verify == 'y' || verify == 'Y') {
                        Json::Value req;
                        req["action"] = "register";
                        req["event_id"] = ev;
                        req["person_id"] = id;
                        Json::StyledWriter writer;
                        string reg_request = writer.write(req);
                        char c_reg_request[reg_request.length() + 1];
                        strcpy(c_reg_request, reg_request.c_str());
                        send(sock, c_reg_request, strlen(c_reg_request), 0);
                        cout << "Sent: " << c_reg_request << endl;
                        valread = read(sock, buffer, 1024);
                        cout << buffer << endl;
                    }

                } else {
                    cout << "You are not a member!\n";
                }
            }
        }
        if (choice == 0) {
            send(sock, "end", 3, 0);
        }
    }
}

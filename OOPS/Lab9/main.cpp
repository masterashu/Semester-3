#include <iostream>
#include <string>

using namespace std;

class Student {
   protected:
    string name;
    int age;
    string address;
    // int subjectMarks[];
    // int subjectWeightage[];

   public:
    void setInfo(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void setInfo(string name, int age, string address) {
        this->name = name;
        this->age = age;
        this->address = address;
    }
    virtual char getGrades() = 0;
    string getaddress() {
        return this->address;
    }
    void setaddress(string address) {
        this->address = address;
    }
    int getage() {
        return this->age;
    }
    void setage(int age) {
        this->age = age;
    }
    string getname() {
        return this->name;
    }
    void setname(string name) {
        this->name = name;
    }
    Student() {
        this->name = "unknown";
        this->age = 0;
        this->address = "not available";
    }
};

class UGStudent : public Student {
   protected:
    int subjectMarks[4];

   public:
    void setMarks(int s1, int s2, int s3, int p1){
        this->subjectMarks[0] = s1;
        this->subjectMarks[1] = s2;
        this->subjectMarks[2] = s3;
        this->subjectMarks[3] = p1;
    }
    UGStudent() : Student() {
        for (int i = 0; i < 4; i++) {
            subjectMarks[i] = 0;
        }
    }
    int* getSubjectMarks() {
        return this->subjectMarks;
    }
    void setMarks(string test, int marks) {
        if (test == "s1") {
            this->subjectMarks[0] = marks;
        }
        if (test == "s2") {
            this->subjectMarks[1] = marks;
        }
        if (test == "p3") {
            this->subjectMarks[2] = marks;
        }
        if (test == "p1") {
            this->subjectMarks[3] = marks;
        }
    }
    char getGrades() {
        int weightage[] = {10, 20, 30, 40};
        float score;
        for (int i = 0; i < 4; i++) {
            score += weightage[i] * this->subjectMarks[i];
        }
        score /= 100;
        if (score >= 90) {
            return 'O';
        } else if (score >= 80) {
            return 'A';
        } else if (score >= 70) {
            return 'B';
        } else if (score >= 60) {
            return 'C';
        } else if (score >= 50) {
            return 'P';
        } else {
            return 'F';
        }
    }
};

class PGStudent : public Student {
   protected:
    int subjectMarks[7];

   public:
    void setMarks(int s1, int p1, int s2, int p2, int s3, int p3, int r1){
        this->subjectMarks[0] = s1;
        this->subjectMarks[1] = p1;
        this->subjectMarks[2] = s2;
        this->subjectMarks[3] = p2;
        this->subjectMarks[4] = s3;
        this->subjectMarks[5] = p3;
        this->subjectMarks[6] = r1;
    }
    int* getSubjectMarks() {
        return this->subjectMarks;
    }
    PGStudent() : Student() {
        for (int i = 0; i < 7; i++) {
            subjectMarks[i] = 0;
        }
    }
    void setMarks(string test, int marks) {
        if (test == "s1") {
            this->subjectMarks[0] = marks;
        }
        if (test == "s2") {
            this->subjectMarks[2] = marks;
        }
        if (test == "p3") {
            this->subjectMarks[4] = marks;
        }
        if (test == "p1") {
            this->subjectMarks[1] = marks;
        }
        if (test == "p2") {
            this->subjectMarks[3] = marks;
        }
        if (test == "s3") {
            this->subjectMarks[5] = marks;
        }
        if (test == "r1") {
            this->subjectMarks[6] = marks;
        }
    }
    char getGrades() {
        int weightage[] = {10, 15, 10, 15, 10, 15, 25};
        double score;
        for (int i = 0; i < 7; i++) {
            score += weightage[i] * this->subjectMarks[i];
        }
        score /= 100;
        if (score >= 90) {
            return 'O';
        } else if (score >= 80) {
            return 'A';
        } else if (score >= 70) {
            return 'B';
        } else if (score >= 60) {
            return 'C';
        } else if (score >= 50) {
            return 'P';
        } else {
            return 'F';
        }
    }
};

int main(int argc, char const* argv[]) {
    UGStudent UGStudents[5];
    PGStudent PGStudents[5];
    cout << "----- UG Students -----" << endl;
    for (int i = 0; i < 5; i++) {
        string name, address;
        int age, s1, s2, s3, p1;
        cout << "Student " << i+1 << endl;
        cout << "Enter Student name: ";
        cin >> name;
        cout << "Enter Student age: ";
        cin >> age;
        cout << "Enter Student address: ";
        cin >> address;
        UGStudents[i].setInfo(name, age, address);
        cout << "Enter Marks in the Order: S1 S2 S3 P1\n\t:";
        cin >> s1 >> s2 >> s3 >> p1;
        UGStudents[i].setMarks(s1, s2, s3, p1);
    }
    cout << "----- PG Students -----" << endl;
    for (int i = 0; i < 5; i++) {
        string name, address;
        int age, s1, s2, s3, p1, p2, p3, r1;
        cout << "Student " << i+1 << endl;
        cout << "Enter Student name: ";
        cin >> name;
        cout << "Enter Student age: ";
        cin >> age;
        cout << "Enter Student address: ";
        cin >> address;
        PGStudents[i].setInfo(name, age, address);
        cout << "Enter Marks in the Order: S1 P1 S2 P2 S3 P3 R1\n\t:";
        cin >> s1 >> p1 >> s2 >> p2 >> s3 >> p3 >> r1;
        PGStudents[i].setMarks(s1, p1, s2, p2, s3, p3, r1);
    }

    cout << "\n----- UG Students -----" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Student " << i+1 << endl;
        cout << "Student name: " << UGStudents[i].getname() << endl;
        cout << "Student age: " << UGStudents[i].getage ()<< endl;
        cout << "Student address: " << UGStudents[i].getaddress() << endl;
        cout << "Student grade: " << UGStudents[i].getGrades() << endl;
        cout << "--------------------------\n";
    }
    cout << "\n----- PG Students -----" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Student " << i+1 << endl;
        cout << "Student name: " << PGStudents[i].getname() << endl;
        cout << "Student age: " << PGStudents[i].getage ()<< endl;
        cout << "Student address: " << PGStudents[i].getaddress() << endl;
        cout << "Student grade: " << PGStudents[i].getGrades() << endl;
        cout << "--------------------------\n";
    }

    return 0;
}
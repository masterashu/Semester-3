#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Student {
   private:
    string Name;
    string RollNo;
    string PhoneNo;
    int Year;

   public:
    // Constructors
    Student() {
        this->Name = "";
        this->RollNo = "";
        this->PhoneNo = "";
        this->Year = 0;
    }
    Student(string Name, string RollNo, string PhoneNo, int Year) {
        this->Name = Name;
        this->RollNo = RollNo;
        this->PhoneNo = PhoneNo;
        this->Year = Year;
    }
    // Getters & Setters
    string getPhoneNo() {
        return this->PhoneNo;
    }
    void setPhoneNo(string PhoneNo) {
        this->PhoneNo = PhoneNo;
    }
    int getYear() {
        return this->Year;
    }
    void setYear(int Year) {
        this->Year = Year;
    }
    string getRollNo() {
        return this->RollNo;
    }
    void setRollNo(string RollNo) {
        this->RollNo = RollNo;
    }

    string getName() {
        return this->Name;
    }
    void setName(string Name) {
        this->Name = Name;
    }
};

class Management {
   private:
    string Name;
    string ManagementId;
    string Mobile;
    string Dept;

   public:
    string getDept() {
        return this->Dept;
    }
    void setDept(string Dept) {
        this->Dept = Dept;
    }

    string getMobile() {
        return this->Mobile;
    }
    void setMobile(string Mobile) {
        this->Mobile = Mobile;
    }
    string getManagementId() {
        return this->ManagementId;
    }
    void setManagementId(string ManagementId) {
        this->ManagementId = ManagementId;
    }
    string getName() {
        return this->Name;
    }
    void setName(string Name) {
        this->Name = Name;
    }
    Management() {
        this->Name = "";
        this->Mobile = "";
        this->ManagementId = "";
        this->Dept = "";
    }
    Management(string Name, string Mobile, string TeacheId, string Dept) {
        this->Name = Name;
        this->Mobile = Mobile;
        this->ManagementId = ManagementId;
        this->Dept = Dept;
    }
};

class NonTeacher {
   private:
    string Name;
    string NonTeacherId;
    string Mobile;
    string Job;

   public:
    string getJob() {
        return this->Job;
    }
    void setJob(string Job) {
        this->Job = Job;
    }

    string getMobile() {
        return this->Mobile;
    }
    void setMobile(string Mobile) {
        this->Mobile = Mobile;
    }
    string getNonTeacherId() {
        return this->NonTeacherId;
    }
    void setNonTeacherId(string NonTeacherId) {
        this->NonTeacherId = NonTeacherId;
    }
    string getName() {
        return this->Name;
    }
    void setName(string Name) {
        this->Name = Name;
    }
    NonTeacher() {
        this->Name = "";
        this->Mobile = "";
        this->NonTeacherId = "";
        this->Job = "";
    }
    NonTeacher(string Name, string Mobile, string TeacheId, string Job) {
        this->Name = Name;
        this->Mobile = Mobile;
        this->NonTeacherId = NonTeacherId;
        this->Job = Job;
    }
};

class Teacher {
   private:
    string Name;
    string TeacherId;
    string Mobile;

   public:
    // Getters & Setters
    string getMobile() {
        return this->Mobile;
    }
    void setMobile(string Mobile) {
        this->Mobile = Mobile;
    }
    string getTeacherId() {
        return this->TeacherId;
    }
    void setTeacherId(string TeacherId) {
        this->TeacherId = TeacherId;
    }
    string getName() {
        return this->Name;
    }
    void setName(string Name) {
        this->Name = Name;
    }
    // Constructors
    Teacher() {
        this->Name = "";
        this->Mobile = "";
        this->TeacherId = "";
    }
    Teacher(string Name, string Mobile, string TeacheId) {
        this->Name = Name;
        this->Mobile = Mobile;
        this->TeacherId = TeacherId;
    }
};

class Stream {
   protected:
    string StreamName;
    Teacher* StreamHead;

   public:
    // Constructor
    Stream() {
        this->StreamName = "";
        this->StreamHead = NULL;
    }
    Stream(string StreamName, Teacher* pTeacher) {
        this->StreamName = StreamName;
        this->StreamHead = pTeacher;
    }
    // Getters & Setters
    Teacher* getStreamHead() {
        return this->StreamHead;
    }
    void setStreamHead(Teacher* StreamHead) {
        this->StreamHead = StreamHead;
    }
    string getStreamName() {
        return this->StreamName;
    }
    void setStreamName(string StreamName) {
        this->StreamName = StreamName;
    }
};

class Branch : protected Stream {
   protected:
    string BranchName;
    Teacher* BranchHead;
    vector<Student> Students;

   public:
    void AddStudent(Student student) {
        this->Students.push_back(student);
    }
    // Getters & Setters
    vector<Student> getStudents() {
        return this->Students;
    }
    void setStudents(vector<Student> Students) {
        this->Students = Students;
    }

    Teacher* getBranchHead() {
        return this->BranchHead;
    }
    void setBranchHead(Teacher* BranchHead) {
        this->BranchHead = BranchHead;
    }
    string getBranchName() {
        return this->BranchName;
    }
    void setBranchName(string BranchName) {
        this->BranchName = BranchName;
    }
    // Constructors
    Branch() {
        this->BranchHead = NULL;
        this->BranchName = "";
        this->Students = vector<Student>();
    }
    Branch(string StreamName, Teacher* StreamHead, string BranchName, Teacher* BranchHead) : Stream(StreamName, StreamHead) {
        this->BranchHead = BranchHead;
        this->BranchName = BranchName;
        this->Students = vector<Student>();
    }
};

class University {
   private:
    string Name;
    string RegNo;
    string Address;

    // Management
    vector<NonTeacher> NonTeachingMembers;
    vector<Management> ManagementMembers;

    // Academics
    vector<Stream> Streams;
    vector<Branch> Branches;
    vector<Teacher> Teachers;

   public:
    void AddTeacher(string TName, string TId, string TMobile) {
        Teacher teacher(TName, TId, TMobile);
        this->Teachers.push_back(teacher);
    }
    void AddBranch(string StreamName, string BranchName, string BranchHeadName) {
        // Get Stream
        Stream* stream = NULL;
        Teacher* branch_head = NULL;
        for (int i = 0; i < this->Streams.size(); i++) {
            if (StreamName.compare(this->Streams[i].getStreamName()) == 0) {
                stream = &(this->Streams[i]);
            }
        }
        if (stream == NULL) {
            cout << "Stream Not Found!";
            return;
        }
        for (int i = 0; i < this->Teachers.size(); i++) {
            if (BranchHeadName.compare(this->Teachers[i].getName()) == 0) {
                branch_head = &(this->Teachers[i]);
            }
        }
        if (branch_head == NULL) {
            cout << "Teacher Not Found!";
            return;
        }
        Branch branch(StreamName, stream->getStreamHead(), BranchName, branch_head);
        this->Branches.push_back(branch);
    }
    void AddStream(string StreamName, string StreamHeadName) {
        Teacher* branch_head = NULL;
        for (int i = 0; i < this->Teachers.size(); i++) {
            if (StreamHeadName.compare(this->Teachers[i].getName()) == 0) {
                branch_head = &(this->Teachers[i]);
            }
        }
        if (branch_head == NULL) {
            cout << "Teacher Not Found!";
            return;
        }
        Stream stream(StreamName, branch_head);
        this->Streams.push_back(stream);
    }
    void AddNonTeachingMember(string NTName, string NTId, string NTMobile, string NTJob) {
        NonTeacher nonTeacher(NTName, NTId, NTMobile, NTJob);
        this->NonTeachingMembers.push_back(nonTeacher);
    }
    void AddManagementMember(string MName, string MId, string MMobile, string MDept) {
        Management management(MName, MId, MMobile, MDept);
        this->ManagementMembers.push_back(management);
    }
    void AddStudent(string SName, string SRollNo, string SMobile, int SYear) {
        Student student(SName, SRollNo, SMobile, SYear);
        if (this->Branches.size() == 0) {
            cout << "Add a Branch First!\n";
            return;
        }
        cout << "Choose A Branch:\n";
        for (int i = 0; i < this->Branches.size(); i++) {
            cout << i + 1 << ": " << this->Branches[i].getBranchName() << endl;
        }
        cout << "Choose A Branch: ";
        int x;
        cin >> x;
        if (x >= 0 & x < this->Branches.size()) {
            this->Branches[x].AddStudent(student);
        } else {
            cout << "Add a Branch First!\n";
            return;
        }
    }
    // Getters & Setters
    vector<Management> getManagementMembers() {
        return this->ManagementMembers;
    }
    void setManagementMembers(vector<Management> ManagementMembers) {
        this->ManagementMembers = ManagementMembers;
    }
    vector<NonTeacher> getNonTeachingMembers() {
        return this->NonTeachingMembers;
    }
    void setNonTeachingMembers(vector<NonTeacher> NonTeachingMembers) {
        this->NonTeachingMembers = NonTeachingMembers;
    }
    vector<Teacher> getTeachers() {
        return this->Teachers;
    }
    void setTeachers(vector<Teacher> Teachers) {
        this->Teachers = Teachers;
    }

    vector<Branch> getBranches() {
        return this->Branches;
    }
    void setBranches(vector<Branch> Branches) {
        this->Branches = Branches;
    }

    vector<Stream> getStreams() {
        return this->Streams;
    }
    void setStreams(vector<Stream> Streams) {
        this->Streams = Streams;
    }

    string getaddress() {
        return this->Address;
    }
    void setaddress(string Address) {
        this->Address = Address;
    }

    string getRegNo() {
        return this->RegNo;
    }
    void setRegNo(string RegNo) {
        this->RegNo = RegNo;
    }

    string getName() {
        return this->Name;
    }
    void setName(string Name) {
        this->Name = Name;
    }
    // Constructor
    University() {
        this->Name = "";
        this->RegNo = "";
        this->Address = "";
        this->ManagementMembers = vector<Management>();
        this->NonTeachingMembers = vector<NonTeacher>();
        this->Teachers = vector<Teacher>();
        this->Branches = vector<Branch>();
    }

    University(string Name, string RegNo, string Address) {
        this->Name = Name;
        this->RegNo = RegNo;
        this->Address = Address;
        this->ManagementMembers = vector<Management>();
        this->NonTeachingMembers = vector<NonTeacher>();
        this->Teachers = vector<Teacher>();
        this->Branches = vector<Branch>();
    }
};

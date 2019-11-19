#include <iostream>
#include "university.h"

using namespace std;

int main(int argc, char const *argv[]) {
    string UName, URegNo, UAddress;
    cout << "Enter University Name:";
    cin >> UName;
    cout << "Enter University RegNo:";
    cin >> URegNo;
    cout << "Enter University Address:";
    cin >> UAddress;
    University U(UName, URegNo, UAddress);

    int ch = 1;
    while (ch != 0) {
        cout << "1: Add New Teacher" << endl;
        cout << "2: Add New Non Teaching Member" << endl;
        cout << "3: Add New Management" << endl;
        cout << "4: Add New Student" << endl;
        cout << "5: Add New Branch" << endl;
        cout << "6: Add New Stream" << endl;
        cout << "0: To EXIT" << endl;
        cout << "Enter Choice: ";
        cin >> ch;
        string SName, SMobile, SRollNo, TName, TMobile, TId;
        int SYear;
        string NTName, NTMobile, NTId, NTJob, MName, MMobile, MId, MDept;
        string StreamName, StreamHeadName, BranchName, BranchHeadName;

        switch (ch) {
            // Add New Teacher
            case 1:
                cout << "Adding New Teacher\n";
                cout << "Enter Teacher Name: ";
                cin >> TName;
                cout << "Enter Teacher Id: ";
                cin >> TId;
                cout << "Enter Teacher Mobile: ";
                cin >> TMobile;
                U.AddTeacher(TName, TId, TMobile);
                break;

            // Add New Non Teaching Member
            case 2:
                cout << "Adding New NonTeacher\n";
                cout << "Enter NonTeacher Name: ";
                cin >> NTName;
                cout << "Enter NonTeacher NonTeacherID: ";
                cin >> NTId;
                cout << "Enter NonTeacher Mobile: ";
                cin >> NTMobile;
                cout << "Enter NonTeacher Year: ";
                cin >> NTJob;
                U.AddNonTeachingMember(NTName, NTId, NTMobile, NTJob);
                break;

            // Add New Management Member
            case 3:
                cout << "Adding New Management Employee\n";
                cout << "Enter Management Name: ";
                cin >> MName;
                cout << "Enter Management Id: ";
                cin >> MId;
                cout << "Enter Management Mobile: ";
                cin >> MMobile;
                cout << "Enter Management Year: ";
                cin >> MDept;
                U.AddManagementMember(MName, MId, MMobile, MDept);
                break;

            // Add New Student
            case 4:
                cout << "Adding New Student\n";
                cout << "Enter Student Name: ";
                cin >> SName;
                cout << "Enter Student RollNo: ";
                cin >> SRollNo;
                cout << "Enter Student Mobile: ";
                cin >> SMobile;
                cout << "Enter Student Year: ";
                cin >> SYear;
                U.AddStudent(SName, SRollNo, SMobile, SYear);
                break;

            // Add Branch
            case 5:
                cout << "Enter Stream Name: ";
                cin >> StreamName;
                cout << "Enter Branch Name: ";
                cin >> BranchName;
                cout << "Enter Branch Head Name";
                cin >> BranchHeadName;
                U.AddBranch(StreamName, BranchName, BranchHeadName);
                break;
            // Add Stream
            case 6:
                cout << "Enter Stream Name: ";
                cin >> StreamName;
                cout << "Enter Strean Head Name";
                cin >> StreamHeadName;
                U.AddStream(StreamName, StreamHeadName);
                break;
        }
    }

    return 0;
}

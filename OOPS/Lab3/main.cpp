#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Student{
    private:
        char name[20];
        int year;
        char branch[20];
        int sem;
        float marks[5]; // 0-MidSem1 1-MidSem2 2-Assignment 3-LabExam 4-EndSem
    public:
        Student(char *student_name, int student_year, char *student_branch, int student_sem){
            strcpy(branch, student_branch);
            year = student_year;
            strcpy(name, student_name);
            sem = student_sem;
        }
        // Getters
        char* Name(){
            return name;
        }
        int Year(){
            return year;
        }
        char* Branch(){
            return branch;
        }
        int Sem(){
            return sem;
        }
        float* Marks(){
            return marks;
        }
        // Setters
        void Name(char *student_name){
            strcpy(name, student_name);
        }
        void Year(int student_year){
            year = student_year;
        }
        void Branch(char *student_branch){
            strcpy(branch, student_branch);
        }
        void Sem(int student_sem){
            sem = student_sem;
        }
        void Marks(float mark, int type){
            if(type >= 1 && type <=5){
                marks[type-1] = mark;
            }
        }
        // Calculate CGPA
        float Cgpa(){
            float weigtage[] = {0.15, 0.15, 0.2, 0.2, 0.3};
            float cgpa = 0;
            for (int i = 0; i < 5; i++){
                cgpa += marks[i] * weigtage[i];
            }
            return cgpa/10;
        }
};

int main(){
    int year, sem;
    char name[20], branch[20];
    float mark;
    cout << "Enter Student name: ";
    cin >> name;
    cout << "Enter Student year: ";
    cin >> year;
    cout << "Enter Student branch: ";
    cin >> branch;
    cout << "Enter Student semester: ";
    cin >> sem;
    cout << "Marks: ";
    Student student(name, year, branch, sem);
    for(int i = 0; i < 5; i++){
        cin >> mark;
        student.Marks(mark, i+1);
    }
    cout << "\nCGPA is: " << student.Cgpa() << endl;
    return 0;
}
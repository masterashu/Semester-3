import java.util.*;

class Manage{
    class Student{
        private:
            String name;
            int year;
            String branch;
            int sem;
            float marks[5];
        public:
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
    }
}

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Matrix {
    private:
        // Matrix Elements
        double MatA[2][2];
        double MatB[2][2];
        double MatC[2][2];

    public:
        // DEFAULT CONTRUCTOR
        Matrix(){
            MatA[0][0] = 0;
            MatA[0][1] = 0;
            MatA[1][0] = 0;
            MatA[1][1] = 0;
            MatB[0][0] = 0; 
            MatB[0][1] = 0;
            MatB[1][0] = 0;
            MatB[1][1] = 0;
            MatB[0][0] = 0; 
            MatC[0][1] = 0;
            MatC[1][0] = 0;
            MatC[1][1] = 0;
        }

        // Constructor with Single data 
        Matrix(double matA[2][2], char *opr){
            MatA[0][0] = matA[0][0]; 
            MatA[0][1] = matA[0][1];
            MatA[1][0] = matA[1][0];
            MatA[1][1] = matA[1][1];
            MatB[0][0] = 0; 
            MatB[0][1] = 0;
            MatB[1][0] = 0;
            MatB[1][1] = 0;
            if (strcmp(opr, "trans") == 0) {
                MakeTrans();
            }
            if (strcmp(opr, "inv") == 0) {
                MakeInv();
            }
        }

        // Constructor with Two data 
        Matrix(double matA[2][2], double matB[2][2], char *opr) {
            MatA[0][0] = matA[0][0]; 
            MatA[0][1] = matA[0][1];
            MatA[1][0] = matA[1][0];
            MatA[1][1] = matA[1][1];
            MatB[0][0] = matB[0][0]; 
            MatB[0][1] = matB[0][1];
            MatB[1][0] = matB[1][0];
            MatB[1][1] = matB[1][1];
            if (strcmp(opr, "add") == 0) {
                MakeAddition();
            }
            if (strcmp(opr, "mul") == 0) {
                MakeMultiplication();
            }
        }

        // Save Tranpose of the Matrix
        void MakeTrans(){
            MatC[0][0] = MatA[0][0];
            MatC[0][1] = MatA[1][0];
            MatC[1][0] = MatA[0][1];
            MatC[1][1] = MatA[1][1];
        }

        // Save Inverse of the Matrix
        void MakeInv() {
            double det = MatADet();
            MatC[0][0] = MatA[1][1] / det;
            MatC[0][1] = -MatA[0][1] / det;
            MatC[1][0] = -MatA[1][0] / det;
            MatC[1][1] = MatA[0][0] / det;
        }

        // Addition of matrices
        void MakeAddition(){
            MatC[0][0] = MatA[0][0] + MatB[0][0]; 
            MatC[0][1] = MatA[0][1] + MatB[0][1];
            MatC[1][0] = MatA[1][0] + MatB[1][0];
            MatC[1][1] = MatA[1][1] + MatB[1][1];
        }
        // Multiplication of matrices
        void MakeMultiplication(){
            MatC[0][0] = MatA[0][0] * MatB[0][0] + MatA[0][1] * MatB[1][0];
            MatC[0][1] = MatA[0][0] * MatB[0][1] + MatA[0][1] * MatB[1][1];
            MatC[1][0] = MatA[1][0] * MatB[0][0] + MatA[1][1] * MatB[1][0];
            MatC[1][1] = MatA[1][0] * MatB[0][1] + MatA[1][1] * MatB[1][1];
        }

        // determinant of matrix
        double MatADet(){
            return (MatA[0][0] * MatA[1][1]) - (MatA[1][0] * MatA[0][1]);
        }

        // setter for a matrix
        void setMatrix(double d[2][2], char ch){
            if (ch == 'A'){
                MatA[0][0] = d[0][0]; 
                MatA[0][1] = d[0][1];
                MatA[1][0] = d[1][0];
                MatA[1][1] = d[1][1];
            }
            if (ch == 'B'){
                MatB[0][0] = d[0][0]; 
                MatB[0][1] = d[0][1];
                MatB[1][0] = d[1][0];
                MatB[1][1] = d[1][1];
            }
        }

        // Printing the Matrices
        void PrintMatrix(){
            cout << "Matrix A:\n";
            cout << MatA[0][0] << ' ' << MatA[0][1] << endl;
            cout << MatA[1][0] << ' ' << MatA[1][1] << endl;

            cout << "Matrix B:\n";
            cout << MatB[0][0] << ' ' << MatB[0][1] << endl;
            cout << MatB[1][0] << ' ' << MatB[1][1] << endl;
            
            cout << "Matrix C:\n";
            cout << MatC[0][0] << ' ' << MatC[0][1] << endl;
            cout << MatC[1][0] << ' ' << MatC[1][1] << endl;
        }

};

int main(int argc, char const *argv[])
{
    double data1[2][2];
    double data2[2][2];

    // Addition
    cout << "// Addition" << endl;
    cout << "Enter Data:\n";
    // Entering Value
    cin >> data1[0][0] >> data1[0][1] >> data1[1][0] >> data1[1][1];
    cin >> data2[0][0] >> data2[0][1] >> data2[1][0] >> data2[1][1];
    char add[] = "add";
    // Calling Constructor
    Matrix mat3(data1, data2, add);
    mat3.PrintMatrix();

    // Multiplication
    cout << "// Multiplication" << endl;
    cout << "Enter Data:\n";
    // Entering Value
    cin >> data1[0][0] >> data1[0][1] >> data1[1][0] >> data1[1][1];
    cin >> data2[0][0] >> data2[0][1] >> data2[1][0] >> data2[1][1];
    char mul[] = "mul";
    // Calling Constructor
    Matrix mat4(data1, data2, mul);
    mat4.PrintMatrix();
    
    // Transpose
    cout << "// Transpose" << endl;
    cout << "Enter Data:\n";
    // Entering Value
    cin >> data1[0][0] >> data1[0][1] >> data1[1][0] >> data1[1][1];
    char trans[] = "trans";
    // Calling Constructor
    Matrix mat1(data1, trans);
    mat1.PrintMatrix();

    // Inverse
    cout << "// Inverse" << endl;
    cout << "Enter Data:\n";
    // Entering Value
    cin >> data1[0][0] >> data1[0][1] >> data1[1][0] >> data1[1][1];
    char inv[] = "inv";
    // Calling Constructor
    Matrix mat2(data1, inv);
    mat2.PrintMatrix();

    return 0;
}


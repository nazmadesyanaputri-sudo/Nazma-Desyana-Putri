#include <iostream>
#include <string>
using namespace std;

const int NUM_STUDENT = 20;

struct studentType {
    string studentFname;
    string studentLname;
    float testScore;
    char grade;
};

struct studentList {
    studentType student_array[NUM_STUDENT];
    int listLength;
};

void Studentsdata(studentList& ListStudent) {
    for (int i = 0; i < ListStudent.listLength; ++i) {
        cout << "Masukkan nama depan, nama belakang, dan hasil test " << i + 1 << ": ";
        cin >> ListStudent.student_array[i].studentFname
            >> ListStudent.student_array[i].studentLname
            >> ListStudent.student_array[i].testScore;
    }
}

void assignGrades(studentList& ListStudent) {
    for (int i = 0; i < ListStudent.listLength; ++i) {
        float score = ListStudent.student_array[i].testScore;
        if (score >= 88)
            ListStudent.student_array[i].grade = 'A';
        else if (score >= 80)
            ListStudent.student_array[i].grade = 'B';
        else if (score >= 70)
            ListStudent.student_array[i].grade = 'C';
        else if (score >= 60)
            ListStudent.student_array[i].grade = 'D';
        else
            ListStudent.student_array[i].grade = 'F';
    }
}

float HighestScore(const studentList& ListStudent) {
    float highest = ListStudent.student_array[0].testScore;
    for (int i = 1; i < ListStudent.listLength; ++i) {
        if (ListStudent.student_array[i].testScore > highest)
            highest = ListStudent.student_array[i].testScore;
    }
    return highest;
}

void PrintTopScore(const studentList& ListStudent, float highestScore) {
    cout << "\nNilai Tertinggi Jatuh Kepada: " << highestScore << endl;
    for (int i = 0; i < ListStudent.listLength; ++i) {
        if (ListStudent.student_array[i].testScore == highestScore) {
            string fullName = ListStudent.student_array[i].studentLname + ", " +
                              ListStudent.student_array[i].studentFname;
            cout << fullName << endl;
        }
    }
}

void displayAllStudent(const studentList& ListStudent) {
    cout << "\nData Siswa\n";
    cout << "Nama\t\t\tScore\tGrade\n";
    for (int i = 0; i < ListStudent.listLength; ++i) {
        string fullName = ListStudent.student_array[i].studentLname + ", " +
                          ListStudent.student_array[i].studentFname;
        cout << fullName << "\t\t"
             << ListStudent.student_array[i].testScore << "\t"
             << ListStudent.student_array[i].grade << endl;
    }
}

int main() {
    studentList ListStudent;
    ListStudent.listLength = NUM_STUDENT;

    Studentsdata(ListStudent);
    assignGrades(ListStudent);
    float highestScore = HighestScore(ListStudent);
    displayAllStudent(ListStudent);
    PrintTopScore(ListStudent, highestScore);

    return 0;
}
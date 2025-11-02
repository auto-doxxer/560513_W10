#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


struct studentType {
    string studentFname;
    string studentLname;
    int testScore;
    char grade;
};


void getData(studentType list[], int size);
void assignGrade(studentType list[], int size);
int highestScore(studentType list[], int size);
void printHighest(studentType list[], int size, int highest);

int main() {
    studentType classList[20];

    getData(classList, 20);
    assignGrade(classList, 20);

     
cout << "\nName\t\t\tScore\tGrade\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < 20; i++) {
        cout << left << setw(20) 
             << (classList[i].studentLname + ", " + classList[i].studentFname)
             << setw(12) << classList[i].testScore
             << classList[i].grade << endl;
    }

    int topScore = highestScore(classList, 20);
    printHighest(classList, 20, topScore);

    return 0;
}


void getData(studentType list[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "\nEnter student's first name: ";
        cin >> list[i].studentFname;
        cout << "Enter student's last name: ";
        cin >> list[i].studentLname;
        
        do {
            cout << "Enter student's test score (0-100): ";
            cin >> list[i].testScore;

            if (list[i].testScore < 0 || list[i].testScore > 100)
                cout << "Invalid score! Please enter a value between 0 and 100.\n";
        } while (list[i].testScore < 0 || list[i].testScore > 100);
    }
}



void assignGrade(studentType list[], int size) {
    for (int i = 0; i < size; i++) {
        int score = list[i].testScore;
        if (score >= 90)
            list[i].grade = 'A';
        else if (score >= 75)
            list[i].grade = 'B';
        else if (score >= 55)
            list[i].grade = 'C';
        else if (score >= 35)
            list[i].grade = 'D';
        else
            list[i].grade = 'E';
    }
}


int highestScore(studentType list[], int size) {
    int highest = list[0].testScore;
    for (int i = 1; i < size; i++) {
        if (list[i].testScore > highest)
            highest = list[i].testScore;
    }
    return highest;
}


void printHighest(studentType list[], int size, int highest) {
    cout << "\nHighest score: " << highest << endl;
    cout << "Students with highest score:\n";
    for (int i = 0; i < size; i++) {
        if (list[i].testScore == highest)
            cout << list[i].studentLname << ", " << list[i].studentFname << endl;
    }
}

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int numCourses;
    cout << "Kitne courses hain? ";
    cin >> numCourses; // [cite: 24]

    float totalPoints = 0;
    float totalCredits = 0;

    for (int i = 0; i < numCourses; i++) {
        float grade, credits;
        cout << "\nCourse " << i + 1 << " ka Grade (0-4): ";
        cin >> grade; // [cite: 25]
        cout << "Course " << i + 1 << " ke Credit Hours: ";
        cin >> credits; // [cite: 25]

        totalPoints += (grade * credits); // [cite: 26]
        totalCredits += credits; // [cite: 26]
    }

    float cgpa = totalPoints / totalCredits; // [cite: 27]

    cout << "\n--- Result ---" << endl;
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Aapka Final CGPA hai: " << fixed << setprecision(2) << cgpa << endl; // [cite: 28]

    return 0;
}
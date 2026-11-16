#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    vector<int> marks = {75, 90, 65, 85, 40};

    
    sort(marks.begin(), marks.end());

    cout << "Sorted Marks: ";
    for (int m : marks)
        cout << m << " ";
    cout << endl;

    
    auto it = find(marks.begin(), marks.end(), 90);

    if (it != marks.end())
        cout << "90 Found\n";
    else
        cout << "90 Not Found\n";

    
    cout << "Marks >= 75: ";
    for (int m : marks) {
        if (m >= 75)
            cout << m << " ";
    }
    cout << endl;

    
    vector<int> updated(marks.size());

    transform(marks.begin(), marks.end(),
              updated.begin(),
              [](int m) { return m + 5; });

    cout << "Updated Marks: ";
    for (int m : updated)
        cout << m << " ";
    cout << endl;

   
    map<string, int> studentMarks;
    studentMarks["Rahul"] = 90;
    studentMarks["Amit"] = 85;

    cout << "Rahul: " << studentMarks["Rahul"] << endl;

    
    unordered_map<string, int> rollNo;
    rollNo["Rahul"] = 101;
    rollNo["Amit"] = 102;

    cout << "Amit Roll: " << rollNo["Amit"] << endl;

    return 0;
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students) q.push(s);

    int top = 0;        
    int count = 0;      

    while (!q.empty() && count < q.size()) {
        if (q.front() == sandwiches[top]) {
            q.pop();
            top++;
            count = 0;  
        } else {
            q.push(q.front());
            q.pop();
            count++;
        }
    }
    return q.size();  
}

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    cout << "Output: " << countStudents(students, sandwiches) << endl;
    return 0;
}

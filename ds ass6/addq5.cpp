#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;

    Node(int val) {
        data = val;
        next = prev = up = down = NULL;
    }
};


Node* convertToLinkedList(vector<vector<int>>& mat) {

    int n = mat.size();
    int m = mat[0].size();

    
    vector<vector<Node*>> nodes(n, vector<Node*>(m));

    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            nodes[i][j] = new Node(mat[i][j]);

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            
            if (j > 0)
                nodes[i][j]->prev = nodes[i][j - 1];
            if (j < m - 1)
                nodes[i][j]->next = nodes[i][j + 1];

            
            if (i > 0)
                nodes[i][j]->up = nodes[i - 1][j];
            if (i < n - 1)
                nodes[i][j]->down = nodes[i + 1][j];
        }
    }

    return nodes[0][0];  
}


void printRow(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

       
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = convertToLinkedList(mat);

    printRow(head);              
    printRow(head->down);        
    printRow(head->down->down);  

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int graph[n][n];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    // Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }

    cout << "\nPath Matrix:\n";
    for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
           
        }
    }
}
        
    cout<<"Output Matrix :- \n";
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               cout<<graph[i][j] <<" ";
            }
            cout<<endl;
    }
    
  
}
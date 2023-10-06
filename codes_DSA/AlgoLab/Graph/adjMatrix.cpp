#include<bits/stdc++.h>
using namespace std;

bool isEdge(int a, int b, vector<vector<int>> adjMat)
{
    if(adjMat[a][b] != 0) return true;
    return false;
}

void printAllEdges(vector<vector<int>> adjMat)
{
    for(int i=0; i<adjMat.size(); i++)
    {
        for(int j=0; j<adjMat.size(); j++)
        {
            if(adjMat[i][j] != 0)
            {
                cout<<"The exist an edge between "<<i<<" and "<<j<<endl;
            }
        }
    }
}

bool insertEdge(vector<vector<int>>&adjMat, int i, int j)
{
    if(adjMat[i][j] != 0)
    {
        cout<<"An edge already exists.";
        return false;
    }
    else{
        adjMat[i][j] = adjMat[j][i] = 1;
        return true;
    }
}

bool deleteEdge(vector<vector<int>>&adjMat, int i, int j)
{
    if(adjMat[i][j] != 0)
    {
        adjMat[i][j] = adjMat[j][i] = 0;
        return true;
    }
    else {
        cout<<"There is no edge."<<endl;
        return false;
    }
}

void addNewNode(vector<vector<int>> &adjMat)
{
    int n = adjMat.size();
    
    adjMat.push_back(vector<int>(n, 0));
    for (int i = 0; i < n + 1; i++)
    {
        adjMat[i].push_back(0);
    }
    
    cout << "Node added successfully." << endl;
}

vector<pair<int, list<int>>> convertMatrixToList(const vector<vector<int>>& adjMatrix){
    int n = adjMatrix.size();
    vector<pair<int, list<int>>> adjList(n);

    for(int i=0; i<n; i++){
        adjList[i].first = i;
        for(int j=0; j<n; j++){
            if(adjMatrix[i][j] == 1){
                adjList[i].second.push_back(j);
            }
        }
    }

    return adjList;
}

void BFS(vector<vector<int>>& adjMat, int startNode) {
    int n = adjMat.size();
    vector<bool> visited(n, false);
    queue<int> q;

    cout << "BFS starting from node " << startNode << ": ";

    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for (int i = 0; i < n; i++) {
            if (adjMat[current][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    cout <<"\n"<< endl;
}

void DFSrec(vector<vector<int>>& adjMat, int startNode, vector<bool>& visited) {
    visited[startNode] = true;
    cout << startNode << " ";

    for (int i = 0; i < adjMat.size(); i++) {
        if (adjMat[startNode][i] == 1 && !visited[i]) {
            DFSrec(adjMat, i, visited);
        }
    }
}

void DFS(vector<vector<int>>& adjMat, int startNode) {
    vector<bool> visited(adjMat.size(), false);
    cout << "DFS starting from node " << startNode << ": ";
    DFSrec(adjMat, startNode, visited);
    cout << endl;
}
int main()
{
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;
    cout << "Enter the adjacency Matrix:" << endl;
    cout << "The indexing is Zero Based" << endl;
    vector<vector<int>> adjMat(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adjMat[i][j];
        }
    }

    int choice;
    while (true)
    {
        cout << "\nMain Menu:" << endl;
        cout << "1. Check if an edge exists" << endl;
        cout << "2. Print all edges" << endl;
        cout << "3. Insert an edge" << endl;
        cout << "4. Delete an edge" << endl;
        cout << "5. Add a new node" << endl;
        cout << "6. Perform Breadth-First Search (BFS)" << endl;
        cout << "7. Perform Depth-First Search (DFS)" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int a, b;
            cout << "Enter nodes (a and b) to check if an edge exists: ";
            cin >> a >> b;
            if (isEdge(a, b, adjMat))
                cout << "An edge exists between " << a << " and " << b << endl;
            else
                cout << "No edge exists between " << a << " and " << b << endl;
            break;

        case 2:
            printAllEdges(adjMat);
            break;

        case 3:
            int i, j;
            cout << "Enter nodes (i and j) to insert an edge: ";
            cin >> i >> j;
            if (insertEdge(adjMat, i, j))
                cout << "Edge inserted successfully." << endl;
            break;

        case 4:
            cout << "Enter nodes (i and j) to delete an edge: ";
            cin >> i >> j;
            if (deleteEdge(adjMat, i, j))
                cout << "Edge deleted successfully." << endl;
            break;

        case 5:
            addNewNode(adjMat);
            break;

        case 6:
            int startNodeBFS;
            cout << "Enter the starting node for BFS: ";
            cin >> startNodeBFS;
            BFS(adjMat, startNodeBFS);
            break;

        case 7:
            int startNodeDFS;
            cout << "Enter the starting node for DFS: ";
            cin >> startNodeDFS;
            DFS(adjMat, startNodeDFS);
            break;

        case 8:
            cout << "Exiting the program." << endl;
            exit(0);

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

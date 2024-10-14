#include<iostream>
#include<queue>
using namespace std;

const int MAX = 100;  

class BFS
{
  public:
  void bfs(int n, int g[MAX][MAX], int s)
  {     
     string color[n];
     int distance[n];
     int parent[n];
     
     for(int i=0; i<n; i++)
     {
       color[i] = "W";
       distance[i] = -1;
       parent[i] = -1;
     }
     
     queue<int> q;
     
     color[s] = "G";
     distance[s] = 0;
     q.push(s);

     cout << "BFS: ";
     while( !q.empty() )
     {
        int u = q.front();
        q.pop();
        cout << u+1 << " ";  
        
        for( int v=0; v<n; v++ )
        {
          if( g[u][v] == 1 && color[v] == "W" )
          {
             color[v] = "G";
             distance[v] = distance[u] + 1;
             parent[v] = u;
             q.push(v);
          }
        }
        color[u] = "BLACK";
     }
     cout << endl;
  } 
};

int main()
{
   int n;
   cout << "Enter the number of Vertices in graph: ";
   cin >> n;
   
   int graph[MAX][MAX];  
   
   cout << "Enter adjacency matrix:\n";
   for(int i=0; i<n; i++)
   {
      for(int j=0; j<n; j++)
      {
          cin >> graph[i][j];
      }
   }
   
   int s;
   cout << "Enter start index: ";
   cin >> s;
   
   BFS b;
   b.bfs(n, graph, s-1);
   return 0;
}



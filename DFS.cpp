#include<iostream>
#include<queue>
using namespace std;

   
class DFS
{   
  public:
  
  static const int max = 100;

    string color[max];
    int time;
    int distance[max];
    int parent[max];
  
  void depthFirst ( int n , int g[][max] ,int s )
  {
     for(int i=0; i<n; i++)
     {
       color[i] = "W";
       parent[i] = -1;
     }
     time = 0;
     
     for(int u=0; u<n; u++)
     {
       if ( color[u] == "W" )
          dfs( g , u );
     }
  }

  void dfs( int g[][max] , int u )
  {
      time++;
      distance[u] = time;
      color[u] = "G" ;
      cout<< u+1 << " " ;
      
      for(int v=0 ; v<max ; v++)
      {
         if( g[u][v] == 1 && color[v] == "W" )
         {
           parent[v] = u;
           dfs( g , v );
         }
      }
      time++;
      color[u] = "B";
  }
};

int main()
{
   int n;
   cout << "Enter the number of Vertices in graph: ";
   cin >> n;
   
   int graph[100][100]; 
   
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
   
   DFS d;
   d.depthFirst(n, graph, s-1);
   return 0;
}


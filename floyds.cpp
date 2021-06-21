#include<bits/stdc++.h>

using namespace std;

void init(vector<vector<int>> &Graph, vector<vector<int>> &track , int E){
       
     for(int i=0;i < Graph.size();i++){
      Graph[i] = vector<int>(Graph.size(),INT_MAX);
      track[i] = vector<int>(Graph.size(), INT_MAX);
      Graph[i][i] = 0;
      track[i][i] = i; 
     }

     cout << "Enter the Edges and Weigth : "<< endl;
     for(int i=0;i< E; i++){
       int from , to , w;
       cin >> from >> to >> w;
       Graph[from][to] = w;
     }
     for(int i=0;i < Graph.size();i++){
       for(int j=0;j < Graph.size() ; j++){
          if(Graph[i][j] != INT_MAX){
	     track[i][j] = j;
	  }
       }
     }
}

vector<int>& showingPath(int u , int v, vector<vector<int>> track){
   
     vector<int> path;
     if(track[u][v] == INT_MAX){
       return path;
     }

     path.push_back(u);
     while(u != v){
       u = track[u][v];
       path.push_back(u);
     }
    return path;
}

void floyds(vector<vector<int>> &Graph, int E){
   vector<vector<int>> track(Graph.size());
   init(Graph, track, E);

   for(int k =0; k < Graph.size();k++){
       for(int i=0;i < Graph.size() ; i++){
           for(int j=0; j < Graph.size() ; j++){
	       if(Graph[i][j] > Graph[i][k] + Graph[k][j]){
	           Graph[i][j] = Graph[i][k] + Graph[k][j];
		   track[i][j] = track[i][k];
	       }
	   }
       }
   }
   char ch;
   vector <int> path;
   do {
     cout << "From Where you want to go : \n";
     int from ,to;
     cin >> from >> to ;
     path = showingPath(from,to, track);
 //    reverse(path.begin(), path.end());
     int n,i=0;
     n = path.size();
     while(i < n){
	     if(i + 1 == n){
	      
	       cout << path[i] << "    and cost is " << Graph[from][to] ;
	       i++;
	       continue;

	     }
	     cout << path[i] << "------->";
            i++;
     }
     cout << "\n Do you wanna continue : ";
     cin >> ch;
   }while(ch == 'Y' || ch == 'y');
}

int main(){
 int V,E;
 cout << "Enter the number of vertex and Edges : ";
 cin >> V >> E;
 vector<vector<int>> Graph(V);
 floyds(Graph,E);
 return 0;
}

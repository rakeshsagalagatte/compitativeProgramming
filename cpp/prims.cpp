#include <bits/stdc++.h>

using namespace std;

bool visited(int p, vector<int> MST){
    for(int i=0;i<MST.size();i++){
      if(MST[i] == p){
         return true;
      }
    }
    return false;
}

int findMinVertex(vector<int> key, vector<int> MST){
  //sort(key.begin() , key.end());
  int min = INT_MAX;
  for(int i=0;i < key.size() ; i++){
     if(min > key[i] && ! visited(i , MST)){
       min=i;
     }
  }
  return min;
} 


void primsAlgo(int src , vector<vector<int> > Graph){

  vector<int> key_value(Graph.size(), INT_MAX);
  key_value[src] = 0;
  vector<int> parent(Graph.size());
  vector<int> MST;
  while(MST.size() != Graph.size()){
      
    int min_vertx = findMinVertex(key_value , MST);
    MST.push_back(min_vertx);
    for(int p=0;p < Graph.size();p++){
      if(Graph[min_vertx][p] != INT_MAX && ! visited(p , MST) && Graph[min_vertx][p] < key_value[p]){
        key_value[p] = Graph[min_vertx][p];
        parent[p] = min_vertx;
      }
    }
  }
  cout << "MST Graph : " << endl << endl;
  for(int i=0;i < Graph.size();i++){
    cout << i  << "  ---->  "  << parent[i] << "   " << key_value[i] << endl; 
  }
 
  parent.erase(parent.begin());
  MST.erase(MST.begin());
  key_value.erase(key_value.begin());
}


int main(){
  int V,E;
  cout << "Enter the number of vertices and edges : ";
  cin >> V >> E;
  vector<vector<int>> Graph(V); 
  for(int i=0;i< Graph.size();i++){
     Graph[i] = vector<int>(Graph.size(), INT_MAX);
     Graph[i][i] = 0;
  }
  cout << "Enter the edges and weigth : \n";
  for(int i=0;i < E;i++){
     int f,t,w;
     cin >> f >> t >> w;
     Graph[f][t] = w;
     Graph[t][f] = w;
  }
  char ch;
  do{
     cout << "Enter the source vertex : ";
     int src;
     cin >> src;
     primsAlgo(src , Graph);
     cout << "Do you wanna continue : ";
     cin >> ch;
  }while(ch=='y'|| ch=='Y');
  return 0;
}

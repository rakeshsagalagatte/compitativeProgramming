#include<bits/stdc++.h>


using namespace std;

bool visted(vector<int> SPT , int n){
 int i =0;
       	while(i < SPT.size()){
	  if(SPT[i] == n){
	     return true;
	  }
		i++; 
	}
	return false;
}

int findMinDistanceVertx(vector<int> Dist, vector<int> SPT){
    int min = INT_MAX;
    int minV = INT_MAX;
    for(int i=0 ; i < Dist.size() ; i++){
        if(min > Dist[i] && ! visted(SPT, i)){
	  min = Dist[i];
	  minV = i;
	}
    }
    return minV;
}


void Dijsktras(vector<vector<int>> &Graph , int src){
   vector<int> SPT;
   vector<int> Distance(Graph.size() , INT_MAX);
   Distance[src] = 0;
   vector<int> Parent(Graph.size() , INT_MAX);
   Parent[src] = src;
   while(SPT.size() < Distance.size()){
     
      int minVertx = findMinDistanceVertx(Distance, SPT);
      SPT.push_back(minVertx);
      for(int i =0; i < Graph.size() ; i++){
        if(Graph[minVertx][i] != INT_MAX && Graph[minVertx][i] + Distance[minVertx] < Distance[i] && ! visted(SPT,i)){
           Distance[i] = Graph[minVertx][i] + Distance[minVertx];
	   Parent[i] = minVertx;
        }
      }
   }
   cout << "Results : \n" ;
   for(int i =0;i< Distance.size();i++){
      //cout << src << " to " << i << " vertex distance " << " " << Distance[i] << endl;
      
       int v =i;
       while(src != i){
        cout << i << "<------" << Graph[Parent[i]][i] << "------"; 
	i = Parent[i];
      }

      i = v;
      cout << src << "   and the Total cost is : " << Distance[i] << endl;
   } 
   SPT.erase(begin(SPT) , end(SPT));
   Distance.erase(begin(Distance) , end(Distance));
}

int main(){
   int V,E;
   cout << "Enter the number of Vertices and edges : ";
   cin >> V >> E;
    
   vector<vector<int>> Graph(V);

   for(int i=0;i < V ; i++){
     Graph[i] = vector<int>(V,INT_MAX);

   }
   cout << "Enter the edges and weight:- " << endl;
   for(int i=0;i < E;i++){
     int from ,to, we;
     cin >> from >> to >> we;
     Graph[from][to] = we;
     Graph[to][from] = we;
   }
   char ch;
   do{
     
     cout << "Enter the source vertex : \n";
     int src;
     cin >> src;
     Dijsktras(Graph, src);
     cout << "\nDo u want to continue : ";
     cin >> ch;
   }while(ch == 'Y'|| ch== 'y');

   Graph.erase(begin(Graph), end(Graph));
   return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;


void dijkstra(vector<vector<pair<int,int>>> &graph, int start)
{
    int n = graph.size();

    vector<int> distance(n, INF);

    priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;


    distance[start] = 0;

    pq.push({0,start});


    while(!pq.empty())
    {
        int current = pq.top().second;
        pq.pop();


        for(auto edge : graph[current])
        {
            int next = edge.first;
            int weight = edge.second;


            if(distance[current] + weight < distance[next])
            {
                distance[next] =
                distance[current] + weight;

                pq.push({distance[next], next});
            }
        }
    }


    for(int i=0;i<n;i++)
        cout<<"Node "<<i<<" Distance: "
            <<distance[i]<<endl;
}


int main()
{
    vector<vector<pair<int,int>>> graph =
    {
        {{1,4},{2,2}},
        {{2,5},{3,10}},
        {{4,3}},
        {{5,1}},
        {{3,4}},
        {}
    };


    dijkstra(graph,0);
}

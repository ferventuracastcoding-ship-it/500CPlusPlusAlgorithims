#include <iostream>
#include <queue>
#include <cmath>

using namespace std;


struct Node
{
    int x,y;
    int g,h;


    int f()
    {
        return g+h;
    }
};


struct Compare
{
    bool operator()(Node a,Node b)
    {
        return a.f()>b.f();
    }
};


int heuristic(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}



int main()
{

    priority_queue<Node,
    vector<Node>,
    Compare> open;


    open.push(
    {
        0,0,
        0,
        heuristic(0,0,5,5)
    });


    while(!open.empty())
    {

        Node current=open.top();

        open.pop();


        cout<<"Exploring "
            <<current.x
            <<","
            <<current.y
            <<endl;


        if(current.x==5 &&
           current.y==5)
        {
            cout<<"Path Found!";
            break;
        }


        open.push(
        {
            current.x+1,
            current.y,
            current.g+1,
            heuristic(
            current.x+1,
            current.y,
            5,5)
        });

    }

}

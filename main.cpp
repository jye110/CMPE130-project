
#include "MGraph.h"
#include <iostream>
using namespace std;
int main()
{
    MGraph G;

    int location,operation;
    int n=8,e=16;
    int path[20];


    Type v[8]={0,1,2,3,4,5,6,7};
    Type ed[16][2]={0,1,1,0,0,2,2,0,0,3,3,0,3,4,4,3,5,6,6,5,5,7,7,5,2,6,6,2,7,4,4,7};
    Weight a[16]={110,110,210,210,200,200,270,270,210,210,350,350,180,180,170,170}; //price
    Weight b[16]={90,90,375,375,330,330,280,280,180,180,250,250,165,165,150,150}; 	//time
    Weight c[16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};			//transfer numbers
    Weight dist[100];

    cout <<"Please enter your departure city£¨0£ºNew York£¬1£ºDC£º2£ºSeattle£¬3£ºLas Vegas£¬4£ºMaiami£¬5£ºLos Angeles£¬6£ºHouston£¬7£ºAtlanta£©"<<endl;
    cin >> location;
    cout <<"Please enter the selected operation (1: Search the lowest price, 2: Search the shortest flight time, 3: Find the least number of transfers£©£º" << endl;
    cin >> operation;

    switch(operation){
        case 1:{
            createMGraph(G,v,n,ed,a,e);
            ShortestPath(G,location,dist,path);
            printShortestPath_price(G,location,dist,path);
            break;}
        case 2:{
            createMGraph(G,v,n,ed,b,e);
            ShortestPath(G,location,dist,path);
            printShortestPath_time(G,location,dist,path);
            break;}
        case 3:{
            createMGraph(G,v,n,ed,c,e);
            ShortestPath(G,location,dist,path);
            printShortestPath_num(G,location,dist,path);
            break;}
        default:
            break;
    }

    return 0;



}
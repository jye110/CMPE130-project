//
// Created by yu950 on 2020/5/3.
//

#ifndef CLIONPROJECTSPROJECT_MGRAPH_H
#define CLIONPROJECTSPROJECT_MGRAPH_H

#endif //CLIONPROJECTSPROJECT_MGRAPH_H

#include <stdio.h>
#define maxVertices 30
#define maxEdges 900
#define maxWeight 32767
#define impossibleVablue '#'
#define impossibleWeight -1
typedef int Type;
typedef int Weight;
typedef struct{
    int numVertices,numEdges;
    Type VerticesList[maxVertices];
    Weight Edge[maxVertices][maxVertices];
}MGraph;


int getVertexPos(MGraph& G,Type x)
{
    for(int i=0;i<G.numVertices;i++)
    {
        if(G.VerticesList[i]==x)
            return i;
    }
    return -1;
}


int numberOfVertices(MGraph& G)
{
    return G.numVertices;
}

void createMGraph(MGraph& G,Type v[],int n,Type ed[][2],Weight c[],int e)
{
    G.numVertices=n;G.numEdges=e;
    int i,j,k;
    for(i=0;i<G.numVertices;i++)
    {
        G.VerticesList[i]=v[i];
        for(j=0;j<G.numVertices;j++)
            G.Edge[i][j]=(i==j) ? 0:maxWeight;
    }
    for(k=0;k<G.numEdges;k++)
    {
        i=getVertexPos(G,ed[k][0]);
        j=getVertexPos(G,ed[k][1]);
        G.Edge[i][j]=c[k];
    }
}

void ShortestPath(MGraph& G,int v,Weight dist[],int path[])
{
    int n=numberOfVertices(G);
    int S[maxVertices];
    int i,j,k;
    Weight w,min;
    for(i=0;i<n;i++)
    {
        dist[i]=G.Edge[v][i];
        S[i]=0;
        if(i!=v&&dist[i]<maxWeight)
            path[i]=v;
        else
            path[i]=-1;
    }
    S[v]=1;  dist[v]=0;
    for(i=0;i<n-1;i++)
    {
        min=maxWeight;
        int u=v;
        for(j=0;j<n;j++)
            if(!S[j]&&dist[j]<min){
                u=j;
                min=dist[j];
            }
        S[u]=1;
        for(k=0;k<n;k++){
            w=G.Edge[u][k];
            if(!S[k]&&w < maxWeight && dist[u]+w < dist[k])
            {
                dist[k]=dist[u]+w;
                path[k]=u;
            }
        }

    }

}

void printShortestPath_price(MGraph& G,int v,Weight dist[],int path[])
{
    printf("From [%d]to other city will cost£º\n",G.VerticesList[v]);
    int i,j,k,n=numberOfVertices(G);
    int d[maxVertices];
    for(i=0;i<n;i++)
        if(i!=v){
            j=i;k=0;
            while(j!=v){
                d[k++]=j;
                j=path[j];
            }
            d[k++]=v;
            printf("From [%d] to other city the £º",G.VerticesList[i]);
            while(k>0)
                printf("%d",G.VerticesList[d[--k]]);
            printf("\nPrice is:%d $\n",dist[i]);
        }
}


void printShortestPath_time(MGraph& G,int v,Weight dist[],int path[])
{
    printf("The flight time from city[%d] to other city is:\n",G.VerticesList[v]);
    int i,j,k,n=numberOfVertices(G);
    int d[maxVertices];
    for(i=0;i<n;i++)
        if(i!=v){
            j=i;k=0;
            while(j!=v){
                d[k++]=j;
                j=path[j];
            }
            d[k++]=v;
            printf("To city [%d] shortest path is£º",G.VerticesList[i]);
            while(k>0)
                printf("%d",G.VerticesList[d[--k]]);
            printf("\nFlight time is :%d\n",dist[i]);
        }
}

void printShortestPath_num(MGraph& G,int v,Weight dist[],int path[])
{
    printf("From city [%d]Number of transfers is:%d\n",G.VerticesList[v]);
    int i,j,k,n=numberOfVertices(G);
    int d[maxVertices];
    for(i=0;i<n;i++)
        if(i!=v){
            j=i;k=0;
            while(j!=v){
                d[k++]=j;
                j=path[j];
            }
            d[k++]=v;
            printf("to the city [%d} The shortest path length is£º",G.VerticesList[i]);
            while(k>0)
                printf("%d",G.VerticesList[d[--k]]);
            printf("Number of transfers is:%d\n",dist[i]-1);
        }
}

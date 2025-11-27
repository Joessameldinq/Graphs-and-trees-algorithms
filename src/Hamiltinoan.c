#include <stdio.h>
#include <stdbool.h>
#define NUM_OF_VERTICES 5

//Adjancy matrix


int graph[NUM_OF_VERTICES][NUM_OF_VERTICES] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int path[NUM_OF_VERTICES];

//We will use back tracking algorithm
// Check if vertex v can be added at position pos
bool isSave(int v,int pos)
{
    if(!graph[path[pos-1]][v])
        return false;
    
    //Vertix must not be used in the path
    for(int i = 0 ; i  < pos ;i++)
        if(path[i] == v)
            return false;

    return true;
}

//Recursive backtracking algorithm

bool hamCycleUtility(int pos)
{
    if(pos == NUM_OF_VERTICES)
    {
        if(graph[path[pos-1]][path[0]])
            return true;
        else    
            return false;

    }
    //Try vertice from 1 to V-1
    for(int v = 1 ; v < NUM_OF_VERTICES ; v++)
    {
        if(isSave(v,pos))
        {
            path[pos] = v;
            if(hamCycleUtility(pos+1))
                return true;
            
            path[pos] = -1; //Back Tracking
        }
    }
    return false;
}

bool hamCycle()
{
    for(int i = 0 ; i < NUM_OF_VERTICES ;i++)
        path[i] = -1;

    path[0] = 0;

    if(hamCycle(1))
    {
        printf("Hamlitonian Cycle was found");
        for(int i = 0 ; i <NUM_OF_VERTICES;i++)
            printf("%d",path[i]);
        printf("%d\n",path[0]); // Close the cycle
        return true;
    }
    printf("NO Hamiltonian cycle \n");
    return false;
}
int main() {
    hamCycle();
    return 0;
}

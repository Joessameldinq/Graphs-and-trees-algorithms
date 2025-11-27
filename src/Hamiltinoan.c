#include <stdio.h>
#include <stdbool.h>

#define NUM_OF_VERTICES 5

//Adjacency matrix
int graph[NUM_OF_VERTICES][NUM_OF_VERTICES] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int path[NUM_OF_VERTICES];

// Check if vertex v can be added at position pos
bool isSafe(int v, int pos)
{
    // Must be adjacent to previous vertex
    if (!graph[path[pos - 1]][v])
        return false;

    // Must not already be in path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive backtracking algorithm
bool hamCycleUtility(int pos)
{
    if (pos == NUM_OF_VERTICES)
    {
        // Check last <-> first connection
        if (graph[path[pos - 1]][path[0]])
            return true;
        else
            return false;
    }

    // Try vertices from 1 to V-1 (0 is fixed at start)
    for (int v = 1; v < NUM_OF_VERTICES; v++)
    {
        if (isSafe(v, pos))
        {
            path[pos] = v;

            if (hamCycleUtility(pos + 1))
                return true;

            path[pos] = -1; // Backtrack
        }
    }
    return false;
}

bool hamCycle()
{
    // Initialize path to -1
    for (int i = 0; i < NUM_OF_VERTICES; i++)
        path[i] = -1;

    // Start at vertex 0
    path[0] = 0;

    // FIXED: call hamCycleUtility, NOT hamCycle()
    if (hamCycleUtility(1))
    {
        printf("Hamiltonian Cycle Found: ");
        for (int i = 0; i < NUM_OF_VERTICES; i++)
            printf("%d ", path[i]);
        printf("%d\n", path[0]); // Close the cycle
        return true;
    }

    printf("No Hamiltonian Cycle\n");
    return false;
}

int main()
{
    hamCycle();
    return 0;
}

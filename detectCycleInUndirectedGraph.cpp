#include <bits/stdc++.h>
using namespace std;

int parentArray[1005];
int sizeArray[1005];

int find(int node)
{
    if (parentArray[node] == -1)
    {
        return node;
    }
    else
    {
        int leader = find(parentArray[node]);
        parentArray[node] = leader;
        return leader;
    }
}

void dsuUnion(int firstNode, int secondNode)
{
    int firstLeader = find(firstNode);
    int secondLeader = find(secondNode);

    if (sizeArray[firstLeader] > sizeArray[secondLeader])
    {
        parentArray[secondLeader] = firstLeader;
        sizeArray[firstLeader] = sizeArray[firstLeader] + sizeArray[secondLeader];
    }
    else
    {
        parentArray[firstLeader] = secondLeader;
        sizeArray[secondLeader] = sizeArray[secondLeader] + sizeArray[firstLeader];
    }
}

int main()
{
    memset(parentArray, -1, sizeof(parentArray));
    memset(sizeArray, 1, sizeof(sizeArray));

    int numberOfNode, numberOfEdge;
    cin >> numberOfNode >> numberOfEdge;

    bool cycle = false;

    for (int i = 0; i < numberOfEdge; i++)
    {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;

        int firstLeader = find(firstNode);
        int secondLeader = find(secondNode);

        if (firstLeader == secondLeader)
        {
            cycle = true;
        }
        else
        {
            dsuUnion(firstNode, secondNode);
        }
    }

    if (cycle)
    {
        cout << "Cycle detected" << endl;
    }
    else
    {
        cout << "There is no cycle" << endl;
    }

    return 0;
}

// Input
// 6 5
// 0 1
// 1 2
// 0 4
// 4 5
// 3 4
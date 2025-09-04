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

    dsuUnion(1, 2);

    for (int i = 0; i < 6; i++)
    {
        cout << i << " -> " << parentArray[i] << endl;
    }

    // parentArray[0] = 1;
    // parentArray[1] = -1;
    // parentArray[2] = 1;
    // parentArray[3] = 1;
    // parentArray[4] = 5;
    // parentArray[5] = 3;

    // cout << find(4) << endl;

    return 0;
}
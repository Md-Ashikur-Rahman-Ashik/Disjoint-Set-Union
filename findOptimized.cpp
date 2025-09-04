#include <bits/stdc++.h>
using namespace std;

int parentArray[1005];

int find(int node)
{
    if (parentArray[node] == -1)
    {
        return node;
    }

    int leader = find(parentArray[node]);
    parentArray[node] = leader;

    return leader;
}

int main()
{
    memset(parentArray, -1, sizeof(parentArray));

    parentArray[0] = 1;
    parentArray[1] = -1;
    parentArray[2] = 1;
    parentArray[3] = 1;
    parentArray[4] = 5;
    parentArray[5] = 3;

    cout << find(4) << endl;

    return 0;
}
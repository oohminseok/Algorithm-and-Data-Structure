﻿#include <iostream>
#include <vector>

int number = 7;
int c[8];
std::vector<int> a[8];

void dfs(int x)
{
    if (c[x])
    {
        return;
    }
    c[x] = true;
    std::cout << x << ' ';
    for (int i = 0; i < a[x].size(); i++)
    {
        int y = a[x][i];
        dfs(y);
    }
}


int main()
{
    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);

    a[4].push_back(5);
    a[5].push_back(4);

    a[6].push_back(7);
    a[7].push_back(6);

    dfs(1);
}

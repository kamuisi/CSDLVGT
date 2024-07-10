#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int v, e;
    string val_1, val_2, s, g, p;
    cin >> v >> e;
    vector<string> v_list(v);
    for (int i = 0; i < v; i++)
    {
        cin >> v_list[i];
    }
    map<string, int> v_index;
    for (int i = 0; i < v; i++)
    {
        v_index[v_list[i]] = i;
    }
    vector<vector<int>> matrix(v, vector<int>(v, 0));
    for (int i = 0; i < e; i++)
    {
        cin >> val_1 >> val_2;
        matrix[v_index[val_1]][v_index[val_2]] += 1;
    }
    cin >> s >> g;
    bool found = false;
    queue<string> open;
    vector<bool> open_yet(v, false);
    vector<bool> close(v, false);
    map<string, string> parent;
    open.push(s);
    open_yet[v_index[s]] = true;
    while (!open.empty())
    {
        p = open.front();
        open.pop();

        if (p == g)
        {
            found = true;
            break;
        }

        if (close[v_index[p]])
        {
            continue;
        }
        close[v_index[p]] = true;
        for (int i = 0; i < v; i++)
        {
            if (matrix[v_index[p]][i] == 1 && close[i] == 0 && open_yet[i] == 0)
            {
                open.push(v_list[i]);
                open_yet[i] = true;
                parent[v_list[i]] = p;
            }
        }
    }
    if (found)
    {
        stack<string> path;
        string point = g;
        path.push(g);
        while (point != s)
        {
            point = parent[point];
            path.push(point);
        }
        cout << "Duong di tu " << s << " toi " << g << " la: ";
        while (!path.empty())
        {
            cout << path.top() << ' ';
            path.pop();
        }
    }
    else
    {
        cout << "Khong tim thay duong di";
    }
    cout << "\n";

    return 0;
}
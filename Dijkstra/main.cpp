#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <string>
#include <climits>
using namespace std;

int main()
{
    int v, e;
    string s, g, p;
    string val_1, val_2;
    int cost;
    cin >> v >> e;
    vector<string> v_list(v);
    for(int i = 0; i < v; i++)
    {   
        cin >> v_list[i];
    }
    map<string, int> v_index;
    for(int i =0 ;i < v; i++)
    {
        v_index[v_list[i]] = i;
    }
    vector<vector<int>> matrix(v, vector<int>(v, 0));
    map<string, string> parent;
    for(int i =0 ; i < e; i++)
    {
        cin >> val_1 >> val_2 >> cost;
        matrix[v_index[val_1]][v_index[val_2]] += cost;
    }






    cin >> s >> g;
    bool found = false;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> open;
    vector<int> d(v, INT_MAX);
    pair<int, string> top;
    vector<bool> close(v, 0);
    open.push({0, s});
    d[v_index[s]] = 0;
    while(!open.empty())
    {
        top = open.top();
        open.pop();
        p = top.second;
        if(close[v_index[p]])
        {
            continue;
        }
        close[v_index[p]] = 1;
        if(p == g)
        {
            found = true;
            break;
        }
        for(int i = 0 ;i < v; i++)
        {
            if(matrix[v_index[p]][i] != 0 && !close[i])
            {
                if(d[i] > d[v_index[p]] + matrix[v_index[p]][i])
                {
                    d[i] = d[v_index[p]] + matrix[v_index[p]][i];
                    open.push({d[i], v_list[i]});
                    parent[v_list[i]] = p;
                }
            }
        }
    }
    if(found)
    {
        cout << "Duong di tu " << s << " den " << g << " la: ";
        stack<string> path;
        string point = g;
        path.push(g);
        while(point != s)
        {
            point = parent[point];
            path.push(point);
        }
        while(!path.empty())
        {
            cout << path.top() << " ";
            path.pop();
        }
        cout << "\nVoi chi phi la: " << d[v_index[g]];
    }
    else
    {
        cout << "Khong tim thay duong di";
    }
    cout << '\n';
    return 0;
}
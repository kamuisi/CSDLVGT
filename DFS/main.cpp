#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int v, e;
    string s, g, p;
    string val_1, val_2;
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
        cin >> val_1 >> val_2;
        matrix[v_index[val_1]][v_index[val_2]]+=1;
    }






    cin >> s >> g;
    bool found = false;
    stack<string> open;
    vector<bool> close(v, 0);

    open.push(s);
    while(!open.empty())
    {
        p = open.top();
        open.pop();
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
                open.push(v_list[i]);
                parent[v_list[i]] = p;
            }
        }
    }
    if(found)
    {
        stack<string> path;
        string point = g;
        path.push(g);
        while(point != s)
        {
            point = parent[point];
            path.push(point);
        }
        cout << "Duong di tu " << s << " den " << g << " la: ";
        while(!path.empty())
        {
            cout << path.top() << " ";
            path.pop();
        }
    }
    else
    {
        cout << "Khong tim thay duong di";
    }
    cout << '\n';
    return 0;
}
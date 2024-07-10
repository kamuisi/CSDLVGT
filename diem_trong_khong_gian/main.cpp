#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct diem
{
    float x, y, z;
};

bool compare(const diem &point_1, const diem &point_2)
{
    if(point_1.x == point_2.x)
    {
        if(point_1.y == point_2.y)
        {
            return point_1.z < point_2.z;
        }
        return point_1.y < point_2.y;
    }
    return point_1.x < point_2.x;
}

int binary_search(vector<diem> Array, diem k)
{
    int l = 0;
    int r = Array.size() - 1;
    int j = 1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(compare(k, Array[m])) r = m - 1;
        else if(compare(Array[m], k)) l = m + 1;
        else return j;
        j++;
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n;    
    vector<diem> Array(n);
    for(int i = 0; i < n; i++)
    {
        cin >> Array[i].x >> Array[i].y >> Array[i].z;
    }
    sort(Array.begin(), Array.end(), compare);
    cin >> m;
    vector<diem> Compare_Array(m);
    for(int i = 0; i < m; i++)
    {
        cin >> Compare_Array[i].x >> Compare_Array[i].y >> Compare_Array[i].z;
    }
    for(int i = 0; i < m; i++)
    {
        int k = binary_search(Array, Compare_Array[i]);
        if(k == -1) cout << "KHONG\n";
        else cout << k << endl;
    }
    return 0;
}
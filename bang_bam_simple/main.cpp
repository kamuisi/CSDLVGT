#include <iostream>
using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n;
    int hash_value;
    int rehash_value;
    int hash_table[m]{0};
    for(int j = 1; j <= n; j++)
    {
        cin >> k;
        hash_value = k % m;      
        if(hash_table[hash_value] == 0)
        {
            hash_table[hash_value] = k;
        }
        else
        {
            int i = 1;
            do
            {
                rehash_value = (hash_value + i*i) % m;
                i++;
            } while (hash_table[rehash_value] != 0 && i < m);
            if(i < m)
            {
                hash_table[rehash_value] = k;
            }
            else
            {
                cout << k << " FULL\n";      
            }
        }      
    }
    for(int j = 0; j < m; j++)
    {   
        if(hash_table[j] == 0)
        {
            cout << j << endl;
        }
    }
    return 0;
}
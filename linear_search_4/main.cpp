#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
struct test_case
{
    int n, k;
    std::vector<int> A;
};

void DsNhap(test_case T[], int t)
{
    int a;
    for (int i{0}; i < t; i++)
    {
        std::cin >> T[i].n >> T[i].k;
        for (int j{0}; j < T[i].n; j++)
        {
            std::cin >> a;
            T[i].A.push_back(a);
        }
    }
}
void Find_X(test_case T[], int t)
{
    int j;
    int h;
    int g;
    std::stringstream ss;
    for (int i{0}; i < t; i++)
    {
        g = j = h = 0;
        int B[100000]{0};
        sort(T[i].A.begin(), T[i].A.end());
        for (int m{0}; m < T[i].n; m++)
        {
            B[T[i].A[m]]++;
        }
        while (j < T[i].n)
        {
            h++;
            if(B[T[i].A[j]] >= 2)
            {
                g+=1;
            }
            j += B[T[i].A[j]];
        }
        while(h < 2 * T[i].k && g > 0)
        {
            h++;
            g--;
        }
        if (h == 2 * T[i].k)
        {
            ss << "YES\n";
        }    
        else
        {
            ss << "NO\n";
        }
    }
    std::cout << ss.str();
}
int main()
{
    int t{0};
    std::cin >> t;
    test_case T[t];
    DsNhap(T, t);
    Find_X(T, t);
    return 0;
}
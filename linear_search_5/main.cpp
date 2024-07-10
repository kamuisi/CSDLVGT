#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

struct test_case
{
    int n;
    std::vector<int> A;
};

void DsNhap(test_case T[], int t)
{
    int a;
    for(int i{0}; i < t; i++)
    {
        std::cin >> T[i].n;
        for(int j{0}; j < T[i].n; j++)
        {
            std::cin >> a;
            T[i].A.push_back(a);
        }
    }

}

void Comp(test_case T[], int t)
{
    int x;
    std::stringstream ss;
    for(int i{0}; i < t; i++)
    {
        sort(T[i].A.begin(), T[i].A.end());
        x = T[i].A[T[i].n - 1] - T[i].A[0];
        if(T[i].n > 2)
        {
            x+= T[i].A[T[i].n - 2] - T[i].A[1];
        } 
        ss << x << '\n';
    }
    std::cout << ss.str();
}

int main()
{
    int t;
    std::cin >> t;
    test_case T[t];
    DsNhap(T, t);
    Comp(T, t);
    return 0;
}
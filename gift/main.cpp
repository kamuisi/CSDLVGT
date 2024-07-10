#include <iostream>
#include <algorithm>
#include <vector>

void DsNhap(int &n, int &x, std::vector<int> &A)
{
    std::cin >> n >> x;
    int a;
    for (int i{0}; i < n; i++)
    {
        std::cin >> a;
        A.push_back(a);
    }
}

void Find_Max(int n, int x, std::vector<int> A)
{
    std::sort(A.begin(), A.end());
    int i{0};
    int j{n - 1};
    int sum{0};
    int cost{0};
    while(j > i)
    {
        sum = A[i] + A[j];
        if(sum == x)
        {
            cost = sum;
            break;
        }
        if(sum < x)
        {
            if(sum > cost)
            {
                cost = sum;
            }
            i++;
        }
        else
        {
            j--;
        }
    }
    std::cout << cost;
}

int main()
{
    std::vector<int> A;
    int n, x;
    DsNhap(n, x, A);
    Find_Max(n, x, A);
    return 0;
}

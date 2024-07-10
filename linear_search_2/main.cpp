#include <iostream>



void DsNhap(int A[], int &n, int &x)
{
    std::cin >> n;
    for(int i{0}; i < n; i++)
    {
        std::cin >> A[i];
    }
    std::cin >> x;
}
void Find_X(int A[], int n, int x)
{
    int location[9999];
    int k{0};
    for(int i{0} ;i < n; i++)
    {
        if(x == A[i])
        {
            location[k] = i;
            k++;
        }
    }
    if(k == 0)
    {
        std::cout << 0;
    }
    else 
    {
        std::cout << k << '\n';
        for(int i{0}; i < k; i++)
        {
            std::cout << location[i] << " " << location[i] + 1 << '\n';
        }
    }
}
int main()
{
    int A[9999];
    int n{0};
    int x{0};
    DsNhap(A, n, x);
    Find_X(A, n, x);
    return 0;
}
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
    int i{0};
    for( ;i < n; i++)
    {
        if(x == A[i])
        {
            std::cout << i << '\n';
            std::cout << i + 1 << '\n';
            std::cout << n - i - 1 << '\n';
            std::cout << n - i;
            break;
        }
    }
    if(i == n)
    {
        std::cout << -1;
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
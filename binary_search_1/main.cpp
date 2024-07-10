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
    int mid{0};
    int r{n - 1};
    int l{0};
    for( ;i < n; i++)
    {
        mid = (r + l) / 2;
        if(A[mid] == x)
        {
            std::cout << mid << '\n';
            std::cout << i + 1;
            break;
        }  
        if(A[mid] > x)
        {
            r = mid - 1;
        } 
        else
        {
            l = mid + 1;
        }
    }
    if(i == n)
    {
        std::cout << -1;
    }
}
int main()
{
    int A[31999];
    int n{0};
    int x{0};
    DsNhap(A, n, x);
    Find_X(A, n, x);
    return 0;
}
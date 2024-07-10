#include <iostream>



void DsNhap(int A[], int &n)
{
    std::cin >> n;
    for(int i{0}; i < n; i++)
    {
        std::cin >> A[i];
    }
}
void Find_X(int A[],int B[], int n)
{
    int j{0};
    for(int i{0} ;i < n; i++)
    {
        B[A[i]] = 1;
        while(B[j] != 0)
        {
            j++;
        }
        std::cout << j << ' ';
    }
}
int main()
{
    int A[200000];
    int B[200001]{0};
    int n{0};
    DsNhap(A, n);
    Find_X(A, B,n);
    return 0;
}
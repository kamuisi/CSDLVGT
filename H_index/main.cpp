#include <iostream>
#define MAX 1000000

void DsNhap(int A[], int &n)
{
    std::cin >> n;
    for(int i{0}; i < n; i++)
    {
        std::cin >> A[i];
    }
}

void Sort_Array(int A[], int C[], int n)
{
    int *B = new int[MAX];
    for(int i{0}; i < n; i++)
    {
        B[A[i]]++;
    }
    for(int i{1}; i < MAX; i++)
    {
        B[i] += B[i - 1];
    }
    for(int i{n - 1}; i > -1; i--)
    {
        B[A[i]]--;
        C[B[A[i]]] = A[i];
    }
}

void Find_X(int C[], int n)
{
    int i{0};
    for( ; i < n; i++)
    {
        if(C[i] >= n - i)
        {
            std::cout << n - i;
            break;
        }
    }
    if(i == n)
    {
        std::cout << 0;
    }
}

int main()
{
    int *A = new int[500000];
    int n;
    DsNhap(A, n);
    int C[n];
    Sort_Array(A, C, n);
    Find_X(C, n);
    return 0;
}

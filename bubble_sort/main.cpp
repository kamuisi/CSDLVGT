#include <iostream>
#include <sstream>
#include <algorithm>

int *DsNhap(int &n)
{
    std::cin >> n;
    int *A = new int[n];
    for (int i{0}; i < n; i++)
    {
        std::cin >> A[i];
    }
    return A;
}

void Sort(int A[], int n)
{
    std::stringstream ss;
    for (int i{0}; i < n - 1; i++)
    {
        for (int j{0}; j < n - 1; j++)
        {
            if(A[j] > A[j + 1])
            {
                std::swap(A[j], A[j + 1]);
                for(int k{0}; k < n; k++)
                {
                    ss << A[k] << " ";
                }
                ss << '\n';
            }
        }
    }
    std::cout << ss.str();
}

int main()
{
    int n{0};
    int *A = DsNhap(n);
    Sort(A, n);
    return 0;
}
#include <iostream>
#include <algorithm>
#include <sstream>

void DsNhap(int A[], int &n)
{
    std::cin >> n;
    for(int i{0}; i < n; i++)
    {
        std::cin >> A[i];
    }
}

void Sort(int A[], int n)
{
    std::stringstream ss;
    for(int i{0}; i < n; i++)
    {
        int min = i;
        for(int j{i + 1}; j < n; j++)
        {
            if(A[min] > A[j])
            {
                min = j;
            }
        }
        if(min != i)
        {
            std::swap(A[min], A[i]);
            for(int j{0}; j < n; j++)
            {
                ss << A[j] << " ";
            }
            ss << '\n';
        }
    }
    std::cout << ss.str();
}

int main()
{
    int A[119];
    int n;
    DsNhap(A, n);
    Sort(A, n);
    return 0;
}
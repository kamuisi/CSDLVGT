#include <iostream>
#include <sstream>

void DsNhap(int A[], int &n)
{
    std::cin >> n;
    for (int i{0}; i < n; i++)
    {
        std::cin >> A[i];
    }
}

void Insertion_Sort(int A[], int n)
{
    std::stringstream ss;
    int i{1};
    while (i < n)
    {
        int k{i - 1};
        int x{A[i]};
        while (k >= 0 && A[k] >= x)
        {
            A[k + 1] = A[k];
            for (int j{0}; j < n; j++)
            {
                ss << A[j] << " ";
            }
            ss << '\n';
            k--;
        }
        A[k + 1] = x;
        for (int j{0}; j < n; j++)
        {
            ss << A[j] << " ";
        }
        ss << '\n';
        i++;
    }
    std::cout << ss.str();
}

int main()
{
    int n;
    int A[199];
    DsNhap(A, n);
    Insertion_Sort(A, n);
    return 0;
}
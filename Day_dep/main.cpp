#include <iostream>
#include <algorithm>
#include <vector>

void DsNhap(std::vector<int> &A, int &n)
{
    int a;
    std::cin >> n;
    for(int i{0}; i < n; i++)
    {
        std::cin >> a;
        A.push_back(a);
    }
}

void Cal(std::vector<int> &A , int n)
{
    std::sort(A.begin(), A.end());
    int h = 0;
    int j = 0;
    int count = 0;
    for(int i{0}; i < n;)
    {
        j = A[i];
        count = 0;
        while(j == A[i + count])
        {
            count++;
        }
        if(count > A[i])
        {
            h+= count - A[i];
        }
        else if(count < A[i])
        {
            h+= count;
        }
        i+= count;
    }
    std::cout << h;
}

int main()
{
    int n{0};
    std::vector<int> A;
    DsNhap(A, n);
    Cal(A, n);
    return 0;
}
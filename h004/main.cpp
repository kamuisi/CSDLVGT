#include <iostream>
#include <vector>
#include <algorithm>

void DsNhap(std::vector<int> &A, int &n, int &s)
{
    int a;
    std::cin >> n >> s;
    A.reserve(n); // cap phat toi thieu cho vector 
    for (int i{0}; i < n; i++)
    {
        std::cin >> a;
        A.push_back(a);
    }
}

void Sift_Up(std::vector<int> &A, int k)
{
    while(k > 0 && A[k] < A[(k - 1) / 2])   // min heap 1 2 3     3      4 5 6  2  (k moi them vao)
    {                                       //                (k - 1)/2         k
        std::swap(A[k], A[(k - 1) / 2]);
        k = (k - 1) / 2;
    }
}

void Min_Cost(std::vector<int> A, int s)
{
    int sum{0};
    int i{0};
    int k{0};
    std::sort(A.begin(), A.end());
    while(A.size() != 1)
    {
        i = A[0] + A[1];
        sum+= i;
        A.erase(A.begin(), A.begin() + 2);
        A.push_back(i);
        Sift_Up(A, A.size() - 1);
        
    }
    std::cout << sum;
}

int main()
{
    std::vector<int> A;
    int n{0};
    int s{0};
    DsNhap(A, n, s);
    Min_Cost(A, s);
    return 0;
}
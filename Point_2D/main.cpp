#include <iostream>

struct Point
{
    int x,y;
};

void DsNhap(Point A[], int &n)
{
    std::cin >> n;
    for(int i{0}; i < n; i++)
    {
        std::cin >> A[i].x;
        std::cin >> A[i].y;
    }
}

void Swap(Point &A, Point &B)
{
    Point buff = A;
    A = B;
    B = buff;
}

void Heapify(Point A[], int k, int n)
{
    int j{k*2 + 1};
    while(j < n)
    {
        if(j + 1 < n)
        {
            if(A[j].x < A[j + 1].x)
            {
                j = j + 1;
            }
            else if(A[j].x == A[j + 1].x && A[j].y > A[j + 1].y)
            {
                j = j + 1;
            }
        }
        if(A[j].x < A[k].x)
        {
            break;
        }
        else if(A[j].x == A[k].x && A[j].y > A[k].y)
        {
            break;
        }
        Swap(A[j], A[k]);
        k = j;
        j = 2*k + 1;
    }
}

void Build_Heap(Point A[], int n)
{
    int i{(n-1)/2};
    while(i >= 0)
    {
        Heapify(A, i, n);
        i--;
    }

}

void Sort_Heap(Point A[], int n)
{
    Build_Heap(A, n);
    while(n > 0)
    {
        n--;
        Swap(A[0], A[n]);
        Heapify(A, 0, n);
    }

}

void Print_Array(Point A[], int n)
{
    for(int i{0}; i < n; i++)
    {
        std::cout << A[i].x << " " << A[i].y << '\n';
    }
}

int main()
{
    Point *A = new Point[1000000];
    int n;
    DsNhap(A, n);
    Sort_Heap(A, n);
    Print_Array(A, n);
    return 0;
}
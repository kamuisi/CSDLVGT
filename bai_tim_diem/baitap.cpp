#include <iostream>
#include <cmath>
using namespace std;
struct point {
    double x;
    double y;
};
void printlist (point A[],int n, point p)
{
    point min;
    int d;
    double c;
    double b;
    for(int i{0}; i<n; i++ )
    {
        min = A[i];
        d = i;
        for(int k = i + 1; k < n; k++)
        {
            c = abs(min.x - p.x) + abs(min.y - p.y);
            b = abs(A[k].x - p.x) + abs(A[k].y - p.y);
            if ( c > b){
                min = A[k];
                d = k;
            }
        }
        A[d] = A[i];
        A[i] = min;
    }

    for(int i{0}; i < 5; i++)
    {
        cout << A[i].x << " , " << A[i].y << '\n';
    }
}
void NhapDs(point A[], int &n, point &p)
{
    int i{0};
    cin >> n;
    while(i<n)
    {
        cin >> A[i].x ;
        cin >> A[i].y ;
        i++;
    }
    cin >> p.x;
    cin >> p.y;
}
int main()
{
    point A[100];
    int n;
    point p;
    NhapDs(A, n, p);
    printlist(A, n, p);
    return 0;
}

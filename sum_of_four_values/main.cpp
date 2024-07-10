#include <iostream>
#include <vector>
#include <algorithm>

void DsNhap(int A[], int &n, int &x)
{
    std::cin >> n >> x;
    for(int i{0}; i < n; i++)
    {
        std::cin >> A[i];
    }
}

void Find_Four(int A[], int n, int x)
{
    int lock_1 = 0;
    int lock_2;
    int sum = 0;
    int i = 0;
    int j = n - 1;
    std::vector<std::vector<int>> vec(n, std::vector<int>(2));
    for(int k{0}; k < n; k++)
    {
        vec[k][0] = A[k];
        vec[k][1] = k;
    }
    std::sort(vec.begin(), vec.end());
    for(; lock_1 < n - 3; lock_1++)
    {
        for(lock_2 = lock_1 + 1; lock_2 < n - 2; lock_2++)
        {
            sum = vec[lock_1][0] + vec[lock_2][0];
            if(sum >= x)
            {
                continue;
            }
            j = n - 1;
            for(i = lock_2 + 1; i < j;)
            {
                sum+= vec[i][0] + vec[j][0];
                if(sum < x)
                {
                    sum-= (vec[i][0] + vec[j][0]);
                    i++;
                }
                else if(sum > x)
                {
                    sum-= (vec[i][0] + vec[j][0]);
                    j--;
                }
                else
                {
                    break;
                }
            }
            if(sum == x)
            {
                break;
            }

        }
        if(sum == x)
        {
            break;
        }
    }
    if(sum == x)
    {
        std::vector<int> result{vec[lock_1][1] + 1, vec[lock_2][1] + 1, vec[i][1] + 1, vec[j][1] + 1};
        std::sort(result.begin(), result.end());
        for(int i{0}; i < 4; i++)
        {
            std::cout << result[i] << " ";
        }
    }
    else
    {
        std::cout << "IMPOSSIBLE";
    }
}

int main()
{
    int n{0};
    int x{0};
    int A[1001];
    DsNhap(A, n, x);
    Find_Four(A, n, x);
    return 0;
}
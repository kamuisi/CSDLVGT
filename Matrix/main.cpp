#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;
    int A[n][m];
    int buff{0};
    int min{0};
    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < m; j++)
        {
            std::cin >> A[i][j];
        }
    }
    min = A[0][0] + A[0][1] + A[0][2] + A[1][1] + A[1][2] + A[1][0] + A[2][0] + A[2][1] + A[2][2];
    for (int i{0}; i <= n - 3; i++)
    {
        buff = A[i][0] + A[i][1] + A[i][2] + A[i + 1][1] + A[i + 1][2] + A[i + 1][0] + A[i + 2][0] + A[i + 2][1] + A[i + 2][2];
        for (int j{3}; j <= m; j++)
        {
            if (buff < min)
            {
                min = buff;
            }
            if (j == m)
            {
                break;
            }
            buff = buff - A[i][j - 3] - A[i + 1][j - 3] - A[i + 2][j - 3] + A[i][j] + A[i + 1][j] + A[i + 2][j];
        }
    }
    std::cout << min;
    return 0;
}
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    int x, y;
    std::cin >> x >> y;
    std::string Account[x][2];
    std::string TK[y];
    std::stringstream ss;
    std::cin.ignore();
    for(int i{0}; i < x; i++)
    {
        std::getline(std::cin, Account[i][0], ' ');
        std::getline(std::cin, Account[i][1], '\n');
    }
    for(int i{0}; i < y; i++)
    {
        std::getline(std::cin, TK[i], '\n');
    }
    int j;
    for(int i{0}; i < y; i++)
    {
        j = x - 1;
        for(; j >= 0; j--)
        {
            if(Account[j][0].compare(TK[i]) == 0)
            {
                ss << Account[j][1] << '\n';
                break;
            }
        }
        if(j == -1)
        {
            ss << "Chua Dang Ky!\n";
        }
    }
    std::cout << ss.str();
    return 0;
}
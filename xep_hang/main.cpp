#include <iostream>
#include <vector>
#include <sstream>

int main()
{
    std::stringstream ss;
    int x, y;
    std::cin >> x >> y;
    std::vector<int> n;
    n.reserve(x);
    int T[y];
    int DEL[x + 1]{0};
    for(int i{0}; i < y; i++)
    {
        std::cin >> T[i];
    }
    for(int i{x}; i > 0; i--)
    {
        n.push_back(i);
    }
    int j{0};
    for(int i{0}; i < y; i++)
    {
        n.push_back(T[i]);
        DEL[T[i]]++;
        while(DEL[n[j]] > 0)
        {
            DEL[n[j]]--;
            j++;
        }
        ss << n[j] << " ";
    }
    std::cout << ss.str();
    return 0;
}
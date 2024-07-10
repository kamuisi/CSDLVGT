#include <iostream>
#include <vector>

int main()
{
    int x{0};
    std::vector<int> n;
    std::cin >> x;
    while(x != 0)
    {
        if(x % 2 == 0)
        {
            n.insert(n.begin(), 0);
        }
        else
        {
            n.insert(n.begin(), 1);
        }    
        x/=2;
    }
    int i{0};
    while(i < n.size())
    {
        std::cout << n[i];
        i++;
    }
    return 0;
}
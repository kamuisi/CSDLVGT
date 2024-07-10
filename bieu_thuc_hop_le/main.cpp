#include <iostream>
#include <string>
#include <math.h>
#include <vector>

int main()
{

    std::string s;
    std::getline(std::cin, s, '\n');
    int i{0};
    std::vector<int> count;
    count.push_back(0);
    while (i < s.length())
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            count.push_back(int(s[i]));
        }
        else if (s[i] == ']')
        {
            if (int(count.back()) != '[')
            {
                break;
            }
            count.pop_back();
        }
        else if (s[i] == '}')
        {
            if (int(count.back()) != '{')
            {
                break;
            }
            count.pop_back();
        }
        else if (s[i] == ')')
        {
            if (int(count.back()) != '(')
            {
                break;
            }
            count.pop_back();
        }
        i++;
    }
    if (count.size() == 1 && i == s.length())
    {
        std::cout << 1;
    }
    else
    {
        std::cout << 0;
    }

    return 0;
}
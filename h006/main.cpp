#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void DsNhap(std::vector<char> &vec)
{
    std::string a;
    std::cin >> a;

    for (int i{0}; i < a.length(); i++)
    {
        vec.push_back(a[i]);
    }
}

void Work_Merge(std::vector<char> &vec)
{
    std::vector<char>::iterator i;
    std::vector<char>::iterator j;
    int still_have = 1;
    while (still_have)
    {
        i = vec.begin();
        j = i + 1;
        still_have = 0;
        while (j < vec.end())
        {
            if (*i == *j)
            {
                vec.erase(i, j + 1);
                still_have = 1;
                if(i != vec.begin())
                {
                    i--;
                    j--;
                }
            }
            else
            {
            i++;
            j++;
                
            }
        }
    }

    std::cout << vec.size();
}

int main()
{
    std::vector<char> vec;
    DsNhap(vec);
    Work_Merge(vec);
    return 0;
}
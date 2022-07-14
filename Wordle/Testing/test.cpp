#include <iostream>
#include <algorithm>
#include <string>
 
int main()
{
    std::string s = "C++,Java";
    char ch = '+';
 
    int count = std::count(s.begin(), s.end(), ch);
    std::cout << "Character " << ch << " occurs " << count << " times\n";
 
    return 0;
}

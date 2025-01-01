#include<iostream>
#include<string>
#include<algorithm>

using std::string;

int main(){
    int pos = 0;
    std::cin >> pos;
    string s;
    std::cin >> s;
    int string_length = s.size();
    std::reverse(s.begin(), s.end());
    std::reverse(s.begin(), s.begin() + pos);
    std::reverse(s.begin() + pos, s.end());
    std::cout << s << '\n';
    return 0;
}
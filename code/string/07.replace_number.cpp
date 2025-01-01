#include<string>
#include<iostream>

using std::string;

void replace_number(string& s){
    int old_size = s.size();
    int new_size = s.size();
    for(int i = 0; i < s.size(); ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            new_size += 5;
        }
    }
    s.resize(new_size);
    new_size = s.size();
    for(int i = old_size - 1, j = new_size - 1; i < j; i--, j--){// 后序填充处理
        if(s[i] < '0' || s[i] > '9'){
            s[j] = s[i];
        }
        else{
            s[j - 5] = 'n';
            s[j - 4] = 'u';
            s[j - 3] = 'm';
            s[j - 2] = 'b';
            s[j - 1] = 'e';
            s[j] = 'r';
            j -= 5;
        }
    }
}

int main(){
    string s;
    while(std::cin >> s){
        replace_number(s);
        std::cout << s << std::endl;
    }
    return 0;
}
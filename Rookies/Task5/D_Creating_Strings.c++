#include <iostream>
#include <algorithm>

using namespace std;

void num(string &s, int index, int &var)
{
    if (index == s.size())
    {
        var++;
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        if (i != index && s[i] == s[index])
            continue;
        swap(s[index], s[i]);
        num(s, index + 1, var);
        swap(s[index], s[i]);
    }
}

void generator(string &s, int index)
{
    if (index == s.size())
    {
        cout << s << endl;
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        if (i != index && s[i] == s[index])
            continue;
        swap(s[index], s[i]);
        generator(s, index + 1);
        swap(s[index], s[i]);
    }
}
int main()
{
    string word;
    cin >> word;
    if(word.size()>=1 && word.size()<=8)
    {
        sort(word.begin(), word.end());

        int var = 0;
        num(word, 0, var);
        cout << var << endl;
        generator(word, 0);
    }


    return 0;
}

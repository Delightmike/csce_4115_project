#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void translate(vector<string> s)
{
    vector<string> t;
    fstream f;
    f.open("dictionary.txt");
    string word;
    string eng, spa, spa2;
    
    for(int i=0; i<s.size(); i++)
    {
        while(getline(f,word))
        {
            stringstream w(word);
            w >> eng >> spa >> spa2;
            if(eng == s[i])
            {
                t.push_back(spa);
                f.clear();
                f.seekg(0);
                break;
            }
            if(spa == s[i])
            {
                t.push_back(eng);
                f.clear();
                f.seekg(0);
                break;
            }
        }
        f.clear();
        f.seekg(0);
    }
    f.close();
    for(int i=0; i<t.size(); i++)
    {
        cout<<t[i]<<" ";
    }
}

int main()
{
    vector<string> v;
    string t;
    cout << "Enter the sentence you would like to translate: ";
    getline(cin, t);
    
    stringstream ss(t);
    string sentence;
    
    while(ss >> sentence)
    {
        v.push_back(sentence);
    }

    translate(v);

    return 0;
}

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> translate(vector<string> s)
{
    vector<string> t;
    fstream f;
    f.open("dictionary.txt");
    string word;
    string eng, spa, spa2;
    int pos=0;
    
    for(int i=0; i<s.size(); i++)
    {
        while(getline(f,word))
        {
            string prev;
            stringstream w(word);
            w >> eng >> spa >> spa2;
            if(!t.empty())
                prev=t[pos-1];
            if(eng == s[i])
            {
                t.push_back(spa);
                f.clear();
                f.seekg(0);
                break;
            }
            if(spa == s[i] || spa2 == s[i])
            {
                t.push_back(eng);
                f.clear();
                f.seekg(0);
                break;
            }
        }
        pos++;
        f.clear();
        f.seekg(0);
    }
    f.close();
    
    return t;
}

int main()
{
    vector<string> v;
    vector<string> r;
    string t;
    cout << "Enter the sentence you would like to translate: ";
    getline(cin, t);
    
    stringstream ss(t);
    string sentence;
    
    while(ss >> sentence)
    {
        v.push_back(sentence);
    }

    r=translate(v);

    cout<<"Translation: ";
    for(int i=0; i<r.size(); i++)
    {
        cout<<r[i]<<" ";
    }

    return 0;
}

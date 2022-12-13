#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void translate(vector<string> s)
{
    fstream f;
    f.open("dictionary.txt");
    string word;
    string eng, spa;
    
    for(int i=0; i<s.size(); i++)
    {
        while(getline(f,word))
        {
            stringstream w(word);
            w >> eng >> spa;
            if(eng == s[i])
            {
                cout << spa << " ";
                break;
            }
        }
    }
    
    f.close();
    
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

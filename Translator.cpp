#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void translate(vector<string> s)
{
    ofstream f;
    f.open("dictionary.txt");
    
    for(int i=0; i<s.size(); i++)
    {
        cout << s[i] << " ";
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
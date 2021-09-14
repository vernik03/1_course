#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

bool palindrome(string str,int n) {
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    for (int m = 0; m < str.length(); m++)
    {
        int i = m - 1;
        int j = m + 1;
        while (i>=0 && j<=str.length() && str[i]==str[j])
        {
            i--;
            j++;
            m++;
        }
        if (j-i-1>=n)
        {
            return true;
        }
       
    }
    for (int m = 0; m < str.length(); m++)
    {
        int i = m;
        int j = m + 1;     
        while (i >= 0 && j <= str.length() && tolower(str[i]) == tolower(str[j]))
        {
            i--;
            j++;
            m++;
        }
        if (j - i - 1 >= n)
        {
            return true;
        }

    }
    return false;
}

int main()
{
    int n;
    int c = 0;
    cout << "N: " << endl;
    cin >> n;
    fstream fin;
    fin.open("input.txt", fstream::in);
    fstream fout;
    fout.open("output.txt", fstream::out);   
    string str;
    while (!fin.eof()) {
        fin >> str;
        string garbage = "";
        while (!(isalpha(str[str.size() - 1]))) {
            garbage += str[str.size() - 1];
            str.erase(str.size() - 1);
        }
        if (!(palindrome(str, n))) {
            fout << str + garbage << " ";
        }
        else {
            c++;
        }
    }
    fin.close();
    fout.close();
    cout << c<<" palindromes" << endl;
 
}

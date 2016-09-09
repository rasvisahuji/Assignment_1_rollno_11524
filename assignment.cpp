#include<iostream>
#include <sstream>
#include<fstream>
#include <cstring>
using namespace std;

void preKMP(string patrn, int g[])

{
    int m = patrn.length(), k;
    g[0] = -1;
    for (int a = 1; a < m; a++)
    {
        k = g[a - 1];
        while (k >= 0)
        {
            if (patrn[k] == patrn[a - 1])
                break;
            else
                k = g[k];
        }
        g[a] = k + 1;
    }
}
 
int KMP(int a,string patrn, string target)

{
    int m = patrn.length();
    int n = target.length();
    int g[m];     
    preKMP(patrn, g);     
    
    int k = 0;        
    while (a < n)
    {
        if (k == -1)
        {
            a++;
            k = 0;
        }
        else if (target[a] == patrn[k])
        {
            a++;
            k++;
            if (k == m)
                return a-k+1;
        }
        else
            k = g[k];
    }
    return -2;
}

void word(int m,int count)
{
	ifstream file("cic.txt");
	string myArray[1000];
    if(file.is_open())
    {
        for(int a = 0; a < 1000; a++)
        {
            file >> myArray[a];
        }
    }
    cout<<myArray[count]<<endl;
}

 
int main()
{
	ifstream file("cic.txt");
	int a=0;
    stringstream buffer;
    buffer << file.rdbuf();
    string str = buffer.str();
    cout << str<<endl;
    string pat;
    int m=0;
    int para=1;
    for(int k=0;k<str.length();k++)
	{
    	if(str[k]=='\n' && str[k+1]=='\n')
		{
    		para++;
		}
	}
	cout<<""<<endl;
	cout<<"the no. of paragraphs is "<<para<<endl;
	cout<<""<<endl;
    cout<<"Enter substring"<<endl;
    cin>>pat;
    while(a < str.length() && a >= 0)
	{
	    int m=KMP(a, pat, str);
	    int count=0;
	    m++;
	    a = m;
	    if(a != -1)
		{
	    	for (int b= 0; b < a; b++)
			{
	            if (str[b] == ' ' ||(str[b]=='\n' && str[b+1]=='\n'))
				{
	                	count++;
	            }
			}
			cout<<"The substring starts at "<< a-1 <<" and the word is ";
			word(a,count);
		}  
	}
}

#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main()
{
	stack <char> s;
	stack <char> p;
	stack <char> ne;
	int i,j,n,k;
	char m;
	string str;
	cin>>str;
	char l;
	n=str.length();
	str[n]=')';
	s.push('(');
	//cout<<s.top();
	for(i=0;i<=n;i++)
	{
		if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z')||(str[i]>='0'&&str[i]<='9'))
		{
			p.push(str[i]);
		}
		else if(str[i]=='(')
		{
			s.push(str[i]);
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='^'||str[i]=='/')
		{
			if((str[i]=='+'||str[i]=='-')&&(s.top()=='*'||s.top()=='/'||s.top()=='^'))
			{
			 m=s.top();
			 s.pop();
			 p.push(m);
			 s.push(str[i]);
		    }
		    else if((str[i]=='*'||str[i]=='/')&&(s.top()=='^'))
		    {
		    	m=s.top();
		    	s.pop();
		    	p.push(m);
		    	s.push(str[i]);
			}
			else
			{
				s.push(str[i]);
			}
		}
		else if(str[i]==')')
		{
			while(s.top()!='(')
			{
				l=s.top();
				s.pop();
				p.push(l);
			}
			s.pop();
		}
		//cout<<s.top();
	}
	while(!p.empty())
	{
		ne.push(p.top());
		p.pop();
	}
	while(!ne.empty())
	{
		cout<<ne.top();
		ne.pop();
	}
	return 0;
}

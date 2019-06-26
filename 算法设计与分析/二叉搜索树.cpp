#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;


int main()
{
	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(5);
	set<int>::iterator iter;
	iter=s.find(2);
	if(iter==s.end())
		cout<<"2 not found!" << endl;
	else
		cout<<"2 found!"<<endl;
	iter = s.find(3);
	if (iter == s.end())
		cout << "3 not found!" << endl;
	else
		cout << "3 found!" << endl;

	for (iter = s.begin();iter != s.end();iter++)
	{
		cout<<*iter<<" "<<endl;
	}

	map<int,string> m;
	m.insert(make_pair(1,"this is 1"));
	m.insert(make_pair(2, "this is 2"));
	m[3]="this is 3";

	map<int, string>::iterator it;
	it=m.find(2);
	if(it!=m.end())
		cout<<it->second<<endl;

	cout<<m[5]<<endl;

	for (it = m.begin();it != m.end();it++)
	{
		cout << it->first << "-->"<< it->second<<" "<<endl;
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,ans=1,n=0;
	int p[9999];
    vector<vector<int> > o(9999);
	cin>>a;
	vector<int> v;
	for(int i=0;i<a;i++) cin>>p[i];
	v.push_back(p[0]);
	for(int i=1;i<a;i++)
	{
		sort(v.begin(),v.end());
		for(int j=0;j<v.size();j++)
		{
			if(v[j]>=p[i])
			{
				n=1;
				v[j]=p[i];
                o[j].push_back(p[i]);
				break;
			}
		}
		if(n==0)
		{
			v.push_back(p[i]);
			o[v.size()-1].push_back(p[i]);
			ans++;
		}
		n=0;
	}
	cout<<ans<<'\n';
	for(int i=0;i<v.size();i++)
	{
		cout<<i+1<<":";
		for(int j=0;j<o[i].size();j++)
		{
			cout<<o[i][j]<<" ";
		}
		cout<<'\n';
	}
}
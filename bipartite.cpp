#include <iostream>
#include <array>
#include <vector>
#include <set>

using namespace std;

#define N 10

array<array<bool,N>,N> graph;

array<int,N> PreNum;
array<bool,N> visited;

void dfs(int n,vector<array<int,N> > &group,array<int,N> &match)
{
	if (n >= N)
	{
		group.push_back(match);
		return;
	}
	if (match[n] == -1)
	{
		for(int i=n;i<N;i++)
		{
			if(graph[n][i] && match[i] == -1)
			{
				{
					match[i] = n;
					match[n] = i;
					dfs(n+1,group,match);
					match[i] = -1;
					match[n] = -1;
				}
			}
		}
	}	
	dfs(n+1,group,match);
	return;
}

bool Hungary(int n)
{
	for(int i=0;i<N;i++)
	{
		if(graph[n][i] && !visited[i])
		{
			if (PreNum[i] == -1)
			{
				PreNum[i] = n;
				return true;
			}
			else
			{
				visited[i] = true;
				if(Hungary(PreNum[i]))
				{
					PreNum[i] = n;
					visited[i] = false;
					return true;
				}
				visited[i] = false;
			}
		}
	}
	return false;
}

void PrintGroup(vector<string> &Person,array<int,N> match)
{
	cout << "组合配对：" << endl;
	for (auto k:match)
	{
		if (k > -1)
		{
			string a,b;
			a = Person[k];
			b = Person[match[k]];
			match[k] = -1;
			cout << a << " -- " << b << endl;
		}
	}
	cout << "-----------------" << endl;
}

int main()
{
	vector<string> Person ={"王菲","李亚鹏","瞿颖","张柏芝","谢霆锋","周迅","张亚东","窦唯","李大齐"};
	vector<array<int,2> > Rel = { {0,1}, {0,4}, {0,7}, {1,2}, {1,5}, {2,6}, {3,4}, {4,5}, {5,8}};
	memset(&graph,false,sizeof(graph));
	for (auto i:Rel)
	{
		graph[i[0]][i[1]] = true;
		graph[i[1]][i[0]] = true;
	}
	/*
	for(auto i:graph)
	{
		for (auto j:i)
			cout << j <<" ";
		cout << endl;
	}
	*/
	
	memset(&PreNum,-1,sizeof(PreNum));
	memset(&visited,false,sizeof(visited));
	for(int i=0;i<Person.size();i++)
	{
		Hungary(i);
	}
	PrintGroup(Person,PreNum);
	vector<array<int,N> > group;
	array<int,N> match;
	memset(&match,-1,sizeof(match));
	dfs(0,group,match);
	int size = group.size();
	cout << "Size:" << size << endl;
	for (auto i:group)
	{
		PrintGroup(Person,i);
	}
	return 0;
}
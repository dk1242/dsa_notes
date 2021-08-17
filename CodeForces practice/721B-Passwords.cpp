#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>

using namespace std;

#define fastio()                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define mem(a, val) memset(a, val, sizeof(a))
#define eb emplace_back
#define f first
#define s second
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)       \
	cerr << #x << " "; \
	_print(x);         \
	cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
	cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
	cerr << "{";
	_print(p.ff);
	cerr << ",";
	_print(p.ss);
	cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(set<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
	cerr << "[ ";
	for (auto i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
bool compare(string s1, string s2){
	return s1.size()<s2.size();
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio();
	int n,k;
	string s;
	cin>>n>>k;
	vector<string>str;
	for(int i=0;i<n;i++){
		cin>>s;
		str.push_back(s);
	}
	int count=0,min=0,max=0;
	string pass;
	cin>>pass;
	int l=pass.length();
	int rnd=0;
	sort(str.begin(), str.end(), compare);
	for(int i=0;i<str.size();i++){
		rnd++;
		if(str[i].length()>l){
			break;
		}else if(str[i].length()<l){
			count+=1;
		}else{
			count++;
			
			if(i>0 && str[i-1].length()<str[i].length()){
				min=count;
				
			}else if(i==0 && str[i].length() == l){
				min=count;//cout<<min<<"#";
			}
			if(i<str.size()-1 && str[i+1].length() > str[i].length()){
				max=count;
			}else if(i==str.size()-1 && str[i].length() == l){
				max=count;
			}
		}
		if(rnd==k){
			count+=5;
			rnd=0;
		}
	}
	cout<<min<<" "<<max;
	// your code goes here
	return 0;
}
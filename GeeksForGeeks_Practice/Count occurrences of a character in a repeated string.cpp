// Given a string, the master string is obtained by repeating the string infinite number of times. 
// You are given q queries, each query having L , R and a character C.
// Find the number of instances of C in the master string in [L, R]
//  Similar to "Count occurrences of a character in a repeated string"
//  https://www.geeksforgeeks.org/count-occurrences-of-a-character-in-a-repeated-string/

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
#define ff first
#define ss second
typedef unsigned long long ull;
typedef long double lld;

//********************Debugging code************************

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

//**************************************************************
int findCount(int l, int r, char c, string s, map<char, int>mp){
	//debug(mp[c]);
	//cout<<c;
	int cc1=mp[c];
	//debug(cc1);
	
	int rep1=r/s.length();
	cc1*=rep1;
	for(int i=0;i<r%s.length();i++){
		if(s[i]==c)
		cc1++;
	}
	debug(cc1);

	int cc2=mp[c];
	int rep2=l/s.length();
	cc2*=rep2;
	for(int i=1;i<l%s.length();i++){
		if(s[i-1]==c)
		cc2++;
	}
	debug(cc2);
	return cc1-cc2;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio();
	string str="abcac";
	map<char, int>mp;
	for(int i=0;i<str.length();i++){
		mp[str[i]]++;
	}
	debug(mp);
	int n=str.length();
	int q;
	cin>>q;
	while(q--){
		int l, r;
		char c;
		cin>>l>>r>>c;
		int cnt=findCount(l,r,c,str,mp);
		cout<<cnt<<endl;
	}
	// your code goes here
	return 0;
}

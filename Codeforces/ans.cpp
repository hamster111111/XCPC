#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,x,n,m;
inline ll read(){
	ll s = 0,w = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0'){ if (ch == '-') w = -1; ch = getchar();}
	while (ch <= '9' && ch >= '0') s = (s << 1) + (s << 3) + (ch ^ 48),ch = getchar();
	return s * w;
}
ll F(ll x,ll n){
	while (n --){
		if (!x) return x;
		x = (x >> 1);
	}
	return x;
}
ll C(ll x,ll n){
	while (n --){
		if (x <= 1) return x;
		x = ((x + 1) >> 1);
	}
	return x;
}
int main(){
    freopen("data.out", "r", stdin);
    freopen("ans.out", "w", stdout);
	t = read();
	while (t --){
		x = read(),n = read(),m = read();
		printf("%lld %lld\n",F(C(x,m),n),C(F(x,n),m));
	}
	return 0;
}
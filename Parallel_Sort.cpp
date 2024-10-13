#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t=0;
	cin>>t;
	for(int i=0;i<t;i++) {
		int n,k,m,a=0;
		cin>>n>>k;
        m = 0;
        int* dynamicArr=new int[n];
	for(int i=0;i<n;i++) {
		cin>>dynamicArr[i];
	}
	//sort(dynamicArr,dynamicArr+n);
	for(int i=0;i<n;i++) {
		if(dynamicArr[i]>=k) {
			m+=dynamicArr[i];
		}
		if((dynamicArr[i]==0)&&(m>0)) {
			a+=1;
			m-=1;
		}
	}
	cout<<a<<endl;
	delete[] dynamicArr;
}
return 0;
}

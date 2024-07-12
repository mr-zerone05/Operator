#include<bits/stdc++.h>
using namespace std;

#define ll long long

typedef vector<ll> bignum;

bignum add(bignum a, bignum b) {
    bignum c;
    c.resize(max(a.size(), b.size()));
  
    a.resize(c.size());
    b.resize(c.size());
    ll mem = 0;
    for (int i = 0; i < c.size(); ++i){
        ll sum = mem + a[i] + b[i];
        c[i] = sum%10;
        mem = sum/10;
    }
    if(mem > 0) c.push_back(mem);
    return c;
}

bignum toBignum(string a){
    bignum c;
    c.clear();
    for(int i = a.size()-1; i >=0; i--)
        c.push_back(a[i] - 48);
    return c;
}

string toString(bignum a){
    string s = "";
    for(int i = a.size()-1; i >=0; i--)
        s += char(a[i]+48);
    return s;
}

int main() {
    string a,b;
    cin>>a>>b;
    bignum A = toBignum(a);
    bignum B = toBignum(b);
    bignum C = add(A,B);
    cout<<toString(C);
}

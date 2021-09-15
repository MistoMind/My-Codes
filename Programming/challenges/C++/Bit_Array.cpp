#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

union myUnion {
    double dValue;
    uint64_t iValue;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    myUnion is, ip, iq, num;
    long long s, p, q;
    long n;
    bool check=true;
    int output=0;
    
    cin >> n >> s >> p >> q;
    
    is.dValue = s;
    iq.dValue = q;
    num.dValue = pow(2,31);
    myUnion smod;
    smod.iValue = is.iValue%num.iValue;
    myUnion qmod;
    qmod.iValue = iq.iValue%num.iValue;
    try{
    unsigned long long *a = new unsigned long long[n];
    unsigned long long a1, a2;
    // cout << "before smod assignation" << endl;
    a[0] = smod.dValue;
    a1 = smod.dValue;
    // cout << "before for loop" << endl;
    // cout << "a[0] = " << a[0] << endl;
    for(int i=1;i<n;i++){
        // cout << "Before assigning a[i]" << endl;
        a[i] = a[i-1]*p+qmod.dValue;
        a2 = a1*p+qmod.dValue;
        
        // cout << "After assigning a[i] " << endl;
        // cout << "a[" << i << "] = " << a[i] << endl;
    }
    
    // cout << "Before the checking loop" << endl;
    for(int i=0;i<n;i++){
        check = true;
        for(int j=i+1;j<n;j++){
            // printf("a[%d] = %lf && a[%d] = %lf\n", i, a[i], j, a[j]);
            if(a[i]==a[j]){
                check = false;
                break;
            }
        }
        if(check)
            output++;
    }
    }catch(std::bad_alloc e){
        cout << "Error: cannot allocate this shit!!!!" << endl;
    }
    cout << output << endl;
    
    return 0;
}
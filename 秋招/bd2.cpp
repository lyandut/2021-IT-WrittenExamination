#include <iostream>

using namespace std;

int func(int n) {
    int cnt = 0;
    for(int i=1; i*i<=n; ++i) {
        if(n % i) continue;
        int a = min(i, n/i), b = max(i, n/i);
        int flag = 1;
        for(int j=2; j<=a; ++j) {
            if(a%j==0 && b%j==0) {
                flag = 0;
                break;
            }
        }
        cnt += flag;
    }
    return cnt;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << func(n) << endl;
    }
    return 0;
}
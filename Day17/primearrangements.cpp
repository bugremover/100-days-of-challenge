class Solution {
public:
    int numPrimeArrangements(int n) {
        
        int arr[100];
        for (int i=0; i<100; i++) {
            arr[i] = 1;
        }
        arr[0] = 0;
        for (int i=2; i*i<=100; i++) {
            for (int j=i; j*i<=100; j++) {
                arr[(i*j)-1] = 0;
            }
        }
        for (int i=1; i<100; i++) {
            arr[i] += arr[i-1];
        }
        long long int ans =1; int r = arr[n-1];
        long long int req = 1e9 + 7;
        for (int i=1; i<=r; i++) {
            ans = (ans%req * i%req)%req;
        }
        for (int i=1; i<=(n-r); i++) {
            ans = (ans%req * i%req)%req;
        }
        return ans;
    }
};
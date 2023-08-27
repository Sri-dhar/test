#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n; 
        cin >> n;
        
        if(n == 1) {     
            int x;     
            cin >> x;       
            cout << x << endl;
        } 
        else {        
            int b[n*(n-1)/2];        
            for (int i = 0; i < n*(n-1)/2; i++)       
                cin >> b[i];
                 
            int a[n];     
                 
            for (int i = 0; i < n; i++) {    
                a[i] = b[i];
                                 
                int index = i * (n-1) - (i * (i + 1)) / 2;          
                for (int j = i+1; j < n; j++) {  
                    index++;                
                    a[j] = min(a[j], b[index]);   
                }
            }
            
            for (int i = 0; i < n; i++)     
                cout << a[i] << " ";    
            cout << endl; 
        } 
    }
    return 0;
}
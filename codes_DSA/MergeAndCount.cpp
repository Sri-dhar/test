#include<iostream>
#include<vector>
using namespace std;

int mergeNcount(vector<int> a, vector<int> b)
{
    int aa{}, bb{};
    int ctr{};
    vector<int> merged;
    int count{};
    while(ctr != a.size()+b.size())
    {
        if(aa == a.size()){
            count+=bb;
            merged.push_back(b[bb++]);
        }
        else if(bb == b.size()){
            merged.push_back(a[aa++]);
        }
        else if(a[aa]<b[bb]){
            merged.push_back(a[aa++]);
        } 
        else{
            count+=bb;
            merged.push_back(b[bb++]);
        }
        ctr++;
    }
    
    cout<<"Merged array: "<<endl;
    for(auto i : merged) cout<<i<<" ";
    cout<<endl;
    
    return count;
}

int main()
{   
    cout<<"Enter the sizes of the arrays:"<<endl;
    int a , b;
    cin>>a>>b;
    vector<int> aa;
    vector<int> bb;
    
    cout<<"Enter the first array: ";
    for(int i =0 ;i<a ; i++) {
        int temp; 
        cin>>temp; 
        aa.push_back(temp);
    }
    
    cout<<"Enter the second array: ";
    for(int i =0 ;i<b ; i++) {
        int temp; 
        cin>>temp; 
        bb.push_back(temp);
    }

    cout<<endl;
    cout<<"The count is : "<<mergeNcount(aa,bb);

    return 0;
}

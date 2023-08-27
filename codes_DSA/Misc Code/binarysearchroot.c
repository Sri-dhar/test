#include<stdio.h>
#include<stdio.h>
#include<math.h>

double binaryrootsearch(double a,double n)
{
    double low =1;
    double high=a;
    double mid=(low+high)/2;
    while(high-low> 1e-6)
    {
        if(pow(mid,n)>a)
        {
            high=mid;
            mid=(low+high)/2;

        }else 
        {
            low=mid;
            mid=(low+high)/2;
        }
    }
    return mid;
}

int main()
{
    double a;
    printf("Enter the number you want to get the nth root of: ");
    scanf("%lg",&a);
    printf("Enter the value of n : ");
    double n;
    scanf("%lg",&n);
    double ans = binaryrootsearch(a,n);
    printf("the answer is : %lg",ans);
}
#include<iostream>
using namespace std;

void printbasic(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout << "* ";
        cout << endl;
    }
    cout << "\n\n";
}

void printline(int n)
{
    for (int i = 0; i < n; i++) cout << "* ";
    cout << endl;
}

void printLineWithDir(int n, int dir)
{
    if (dir == -1)
    {
        cout << "* ";
        for (int i = 0; i < n - 1; i++) cout << "  ";
    }
    else
    {
        for (int i = 0; i < n - 1; i++) cout << "  ";
        cout << "* ";
    }
    cout << endl;
}

void printwitharg(int n, int arg)
{
    int argg = arg;
    int dir = 1; // -1 means left // 1 means right
    int linecount{};
    int i = -1;
    while (linecount <= n-1)
    {
        i++;
        if (i % 2 && linecount <= n - 1)
        {
            while (argg-- && linecount <= n - 1) {
                printLineWithDir(n, dir);
                linecount++;
            }
            argg = arg;
            dir *= -1;
        }
        else if(linecount <=n+1){
            printline(n);
            linecount++;
        }
    }
}


int main(void)
{
    cout << "Enter the size of the matrix (n) : ";
    int n{};
    cin >> n;
    printbasic(n);
    cout << "Do you want to print matrix with arguments :" << endl;
    cout << "Enter 1 for yes and 0 for no : ";
    int option{};
    cin >> option;
    while (option)
    {
        cout << "Enter the argument : ";
        int arg{};
        cin >> arg;
        printwitharg(n, arg);
        cout << "Do you want to print matrix with arguments :" << endl;
        cout << "Enter 1 for yes and 0 for no";
        cin >> option;
        if (!option) break;
    }
    return 0;
}
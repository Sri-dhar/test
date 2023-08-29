#include<bits/stdc++.h>

std::pair<int, int> ans1, ans2;
int n{};

bool compareX(std::pair<int, int> &a, std::pair<int, int> &b) {
    return a.first < b.first;
}

bool compareY(std::pair<int, int> &a, std::pair<int, int> &b) {
    return a.second < b.second;
}

long long int distance(std::pair<int, int> a, std::pair<int, int> b)
{
    long long int x = a.first - b.first;
    long long int y = a.second - b.second;
    return (x * x) + (y * y);
}

/////////   PRINTING PX AND PY

void printVector(const std::vector<std::pair<int, int>>& vec) {
    for (const auto& p : vec) {
        std::cout << "{" << p.first << ", " << p.second << "} ";
    }
    std::cout << std::endl;
}

void printPxPy(const std::vector<std::pair<int, int>>& Px, const std::vector<std::pair<int, int>>& Py) {
    std::cout<<std::endl;
    std::cout << "Px: ";
    printVector(Px);
    std::cout<<std::endl;

    std::cout << "Py: ";
    printVector(Py);
    std::cout<<std::endl;
}

std::pair<std::pair<int,int>,std::pair<int,int>> closestPairRec(std::vector<std::pair<int, int>> &P , std::vector<std::pair<int, int>> Px , std::vector<std::pair<int, int>> Py , int low, int high)
{
    if(abs(high-low) <= 3)
    {
        //base case we are bruteforcing our way for 3 points
        std::pair<std::pair<int,int>,std::pair<int,int>> localAns;
        long long int mini = INT_MAX;
        for(int i= low; i<= high; ++i)
        {
            for(int j = i+1 ; j <= high; ++j)
            {
                long long int len = distance(Px[i],Px[j]);
                if(len < mini)
                { 
                    mini = len;
                    localAns = {Px[i],Px[j]};
                }
            }
        }
        return localAns;
    }

    int mid = low + (high - low)/2 ;
    std::pair<std::pair<int,int> ,std::pair<int,int>> a, b;
    a = closestPairRec(P,Px,Py, low, mid);
    b = closestPairRec(P,Px,Py,mid+1,high);

    long long int da = distance(a.first,a.second);
    long long int db = distance(b.first,b.second);
    long long int s = std::min(da,db);

    std::vector<std::pair<int,int>> Sy;
    //Sy contains all the points which lie in the regin of mid-s to mid+s by checking the x coordinates and pushing in Sy
    for(int i = low ; i<=high ; i++) if(std::abs(Py[i].first-Px[mid].first) < s) Sy.push_back(Py[i]);
    //warning is coming here because we have i as int whereas Sy.size() return type is size_t
    int count = 0;
    for(int i=0 ; i<Sy.size(); i++){
        for(int j= i+1; j<Sy.size()  && (Sy[j].second - Sy[i].second) < s && count++<14; j++) {
            long long int dis = distance(Sy[i],Sy[j]);
            if(dis<s){
                s = dis;
                a ={Sy[i],Sy[j]};
            }
        }
    }
    

    return (da <= db) ? a : b;
}

void findClosestPair(std::vector<std::pair<int, int>> &points) {

    std::vector<std::pair<int, int>> Px = points;
    std::sort(Px.begin(), Px.end(), compareX);

    std::vector<std::pair<int, int>> Py = points;
    std::sort(Py.begin(), Py.end(), compareY);

    printPxPy(Px, Py);
    std::cout<<std::endl;
    
    std::pair<std::pair<int, int>, std::pair<int, int>> closestPair = closestPairRec(points ,Px, Py, 0, points.size() - 1);
    
    ans1 = closestPair.first;
    ans2 = closestPair.second;
}

int main() {
    std::cout << "Enter the number of points : " << std::endl;
    std::cin >> n;
    std::vector<std::pair<int, int>> points(n, {0, 0});
    std::cout << "Enter the points in the following format : {x,y}" << std::endl;
    for (int i = 0; i < n; i++) {
        int temp{};
        std::cin >> temp;
        points[i].first = temp;
        std::cin >> temp;
        points[i].second = temp;
    }

    findClosestPair(points);
    
    std::cout << "The closest pair of points are : " << ans1.first << " , " << ans1.second << " and " << ans2.first<< " , " << ans2.second << std::endl;
}
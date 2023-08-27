#include <bits/stdc++.h>

std::pair<int, int> ans1, ans2;
int n{};

bool compareX(std::pair<int, int> &a, std::pair<int, int> &b) {
    return a.first < b.first;
}

bool compareY(std::pair<int, int> &a, std::pair<int, int> &b) {
    return a.second < b.second;
}

long long int distance(std::pair<int, int> a, std::pair<int, int> b) {
    long long int x = a.first - b.first;
    long long int y = a.second - b.second;
    return (x * x) + (y * y);
}

void printVector(const std::vector<std::pair<int, int>>& vec) {
    for (const auto& p : vec) {
        std::cout << "{" << p.first << ", " << p.second << "} ";
    }
    std::cout << std::endl;
}

void printPxPy(const std::vector<std::pair<int, int>>& Px, const std::vector<std::pair<int, int>>& Py) {
    std::cout << "Px: ";
    printVector(Px);

    std::cout << "Py: ";
    printVector(Py);
}

std::pair<std::pair<int,int>,std::pair<int,int>> closestPairRec(std::vector<std::pair<int, int>> &Px , std::vector<std::pair<int, int>> &Py , int low, int high)
{
    if(abs(high-low) <= 3)
    {
        // Base case: Use brute-force for a small number of points
        std::pair<std::pair<int,int>,std::pair<int,int>> closestPair;
        long long int minDist = LLONG_MAX;

        for (int i = low; i <= high; ++i) {
            for (int j = i + 1; j <= high; ++j) {
                long long int dist = distance(Px[i], Px[j]);
                if (dist < minDist) {
                    minDist = dist;
                    closestPair = {Px[i], Px[j]};
                }
            }
        }

        return closestPair;
    }
    
    int mid = low + (high - low) / 2 ;

    std::pair<std::pair<int,int>,std::pair<int,int>> a,b;
    a = closestPairRec(Px, Py, low, mid);
    b = closestPairRec(Px, Py, mid + 1, high);
    
    // Calculate the minimum distance between pairs from left and right partitions
    double da = distance(a.first, a.second);
    double db = distance(b.first, b.second);
    double s = std::min(da, db);

    // Merge the two sorted arrays while keeping the Py order
    std::vector<std::pair<int, int>> Sy;
    for (int i = low; i <= high; ++i) {
        if (std::abs(Py[i].first - Px[mid].first) < s) {
            Sy.push_back(Py[i]);
        }
    }

    // Check for closer pairs in the strip
    for (size_t i = 0; i < Sy.size(); ++i) {
        for (size_t j = i + 1; j < Sy.size() && (Sy[j].second - Sy[i].second) < s; ++j) {
            double dist = distance(Sy[i], Sy[j]);
            if (dist < s) {
                s = dist;
                a = {Sy[i], Sy[j]};
            }
        }
    }
 
    // Return the closest pair among a and b
    return (da <= db) ? a : b;
}

void findClosestPair(std::vector<std::pair<int, int>> &points) {

    std::vector<std::pair<int, int>> Px = points;
    std::sort(Px.begin(), Px.end(), compareX);

    std::vector<std::pair<int, int>> Py = points;
    std::sort(Py.begin(), Py.end(), compareY);

    printPxPy(Px, Py);
    std::cout<<std::endl;
    
    std::pair<std::pair<int, int>, std::pair<int, int>> closestPair = closestPairRec(Px, Py, 0, points.size() - 1);
    
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

#include<iostream>
#include<vector>
#include "closestPairHeader.h"

int main() {
    std::cout << "Enter the number of points : " << std::endl;
    std::cin >> n;
    std::vector<std::pair<int, int>> points(n, { 0, 0 });
    std::cout << "Enter the points in the following format : {x,y}" << std::endl;
    for (int i = 0; i < n; i++) {
        int temp{};
        std::cin >> temp;
        points[i].first = temp;
        std::cin >> temp;
        points[i].second = temp;
    }

    findClosestPair(points);
    std::pair<int, int> ans1Of1CP = { ans11.first,ans11.second };
    std::pair<int, int> ans2Of1CP = { ans12.first,ans12.second };

    std::cout << "The first closest pair of points are : " << ans11.first << " , " << ans11.second << " and " << ans12.first << " , " << ans12.second << std::endl;

    std::vector<std::pair<int, int>> pointsWithout1;
    std::vector<std::pair<int, int>> pointsWithout2;

    for (auto i : points) if (i.first != ans11.first && i.second != ans11.second) pointsWithout1.push_back(i);
    for (auto i : points) if (i.first != ans12.first && i.second != ans12.second) pointsWithout2.push_back(i);

    findClosestPair(pointsWithout1);
    std::pair<int, int> pw11 = ans11, pw12 = ans12;
    long long int distance_between_pw1 = distance(ans11, ans12);

    findClosestPair(pointsWithout2);
    std::pair<int, int> pw21 = ans11, pw22 = ans12;
    long long int distance_between_pw2 = distance(ans11, ans12);

    // if(distance_between_pw1>distance_between_pw2) {
    //     std::cout << "The second closest pair of points are : " << pw21.first << " , " << pw21.second << " and " << pw22.first<< " , " << pw22.second << std::endl;
    //     std::cout << "The third closest pair of points are : " << pw11.first << " , " << pw11.second << " and " << pw12.first<< " , " << pw12.second << std::endl;
    // }
    // else{
    //         std::cout << "The second closest pair of points are : " << pw11.first << " , " << pw11.second << " and " << pw12.first<< " , " << pw12.second << std::endl;
    //         std::cout << "The third closest pair of points are : " << pw21.first << " , " << pw21.second << " and " << pw22.first<< " , " << pw22.second << std::endl;

    // }

    std::pair<int, int> secCloPt1;
    std::pair<int, int> secCloPt2;
    if (distance_between_pw1 > distance_between_pw2)
    {
        secCloPt1.first = pw21.first;
        secCloPt1.second = pw21.second;

        secCloPt2.first = pw22.first;
        secCloPt2.second = pw22.second;
    }
    else {
        secCloPt1.first = pw11.first;
        secCloPt1.second = pw11.second;

        secCloPt2.first = pw12.first;
        secCloPt2.second = pw12.second;
    }

    std::cout << "The second closest pair of points are : " << secCloPt1.first << " , " << secCloPt1.second << " and " << secCloPt2.first << " , " << secCloPt2.second << std::endl;

    //FOR THIRD CLOSEST PAIR OF POINTS

    std::vector<std::pair<int, int>> poiWithout1;
    std::vector<std::pair<int, int>> poiWithout2;
    std::vector<std::pair<int, int>> poiWithout3;
    std::vector<std::pair<int, int>> poiWithout4;

    //we currently have secCloPt1 || secCloPt2 || 
    //               || ans1Of1CP || ans2Of1CP

    for (auto i : points) if ((i.first != secCloPt1.first && i.second != secCloPt1.second) &&(i.first != ans1Of1CP.first && i.second != ans1Of1CP.second)) poiWithout1.push_back(i);
    for (auto i : points) if ((i.first != secCloPt1.first && i.second != secCloPt1.second) && (i.first != ans2Of1CP.first && i.second != ans2Of1CP.second)) poiWithout2.push_back(i);
    for (auto i : points) if ((i.first != secCloPt2.first && i.second != secCloPt2.second) && (i.first != ans1Of1CP.first && i.second != ans1Of1CP.second)) poiWithout3.push_back(i);
    for (auto i : points) if ((i.first != secCloPt2.first && i.second != secCloPt2.second) && (i.first != ans2Of1CP.first && i.second != ans2Of1CP.second)) poiWithout4.push_back(i);

    findClosestPair(poiWithout1);
    std::pair<std::pair<int, int>, std::pair<int, int>> pointpair1 = { ans11,ans12 };

    findClosestPair(poiWithout2);
    std::pair<std::pair<int, int>, std::pair<int, int>> pointpair2 = { ans11,ans12 };

    findClosestPair(poiWithout3);
    std::pair<std::pair<int, int>, std::pair<int, int>> pointpair3 = { ans11,ans12 };

    findClosestPair(poiWithout4);
    std::pair<std::pair<int, int>, std::pair<int, int>> pointpair4 = { ans11,ans12 };

    //getting minimum distance

    std::pair<std::pair<int, int>, std::pair<int, int>> minDistPair, minDistPair1, minDistPair2;

    if (distance(pointpair1.first, pointpair1.second) > distance(pointpair2.first, pointpair2.second)) minDistPair1 = pointpair1;
    else minDistPair1 = pointpair2;

    if (distance(pointpair3.first, pointpair3.second) > distance(pointpair4.first, pointpair4.second)) minDistPair1 = pointpair1;
    else minDistPair2 = pointpair2;

    if (distance(minDistPair2.first, minDistPair2.second) > distance(minDistPair1.first, minDistPair1.second)) minDistPair = pointpair1;
    else minDistPair = minDistPair2;

    std::cout << "The third closest pair of points are : " << minDistPair.first.first << " , " << minDistPair.first.second << " and " << minDistPair.second.first << " , " << minDistPair.second.second << std::endl;

    return 0;
}

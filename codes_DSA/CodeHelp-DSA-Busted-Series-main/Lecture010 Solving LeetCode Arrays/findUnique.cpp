#include<iostream>
#include<vector>
#include<bits/stdc++.h>

int main()
{
	std::vector <int> v{1,2,34,45};
	std::cout << "size-> " << v.capacity() << std::endl;
	// v.push_back(1);
	// v.push_back(1);
	// v.push_back(1);
	std::cout << "size-> " << v.capacity() << std::endl;
	// for (int i = 0; i < 5; i++)
	// {	
	// 	std::cout << v.at(i) << std::endl;
	// }

	for (int i : v)
	{
		std::cout << i << std::endl;
	}
	
	v.pop_back();

	for (int i : v)
	{
		std::cout << i << std::endl;
	}

    std::cout << "\n\n"<< std::endl;
	
	std::cout << v.size() << std::endl;
	v.clear();
	std::cout << v.size() << std::endl;
    
	return 0;
}
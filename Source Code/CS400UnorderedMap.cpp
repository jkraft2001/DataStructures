// CS400UnorderedMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    // Declaring umap to be of 
    // <string, double> type key 
    // will be of string type and 
    // mapped value will be of double type
    std::unordered_map<std::string, double> umap = {  //inserting element directly in map
    {"One", 1.0},
    {"Two", 2.0},
    {"Three", 3.0}
    };

    // inserting values by using [] operator
    umap["PI"] = 3.14;
    umap["root2"] = 1.414;
    umap["root3"] = 1.732;
    umap["log10"] = 2.302;
    umap["loge"] = 1.0;

    // inserting value by insert function
    umap.insert(std::make_pair("e", 2.718));

    std::string key = "PI";

    // If key not found in map iterator 
    // to end is returned
    if (umap.find(key) == umap.end())
        std::cout << key << " not found\n\n";

    // If key found then iterator to that 
    // key is returned
    else
        std::cout << "Found " << key << "\n\n";

    key = "rong";
    if (umap.find(key) == umap.end())
        std::cout << key << " not found\n";
    else
        std::cout << "Found " << key << std::endl;

    // iterating over all value of umap
    std::unordered_map<std::string, double>::iterator itr;
    std::cout << "\nAll Elements : \n";
    for (itr = umap.begin(); itr != umap.end(); itr++)
    {
        // itr works as a pointer to 
        // pair<string, double> type 
        // itr->first stores the key part and
        // itr->second stores the value part
        std::cout << itr->first << "  " << itr->second << std::endl;
    }






    return 0;
}


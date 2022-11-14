#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

bool cmp(std::pair<std::string, int>& a,
         std::pair<std::string, int>& b)
{
    return a.second > b.second;
}

int main()
{
    // exp.1: Decl & Def map variable
    // std::map<std::string, int> map;
    // map["blue"] = 10;
    // map["red"] = 20;
    // map["orange"] = 30;
    // map["green"] = 40;

    // std::cout << map["green"] << '\n';

    // for (const auto& item : map) {
    //     std::cout << "Key: " << item.first << " | Value: " << item.second << '\n';
    // }

    // exp.2: Decl & Def map variable
    // std::map<std::string, int> map {{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};

    // for (const auto& item : map) {
    //     std::cout << "Key: " << item.first << " | Value: " << item.second << '\n';
    // }

    // Erase element
    // std::map<std::string, int> map {{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
    // map.erase("CPU");

    // for (const auto& item : map) {
    //     std::cout << "Key: " << item.first << " | Value: " << item.second << '\n';
    // }

    // Add element
    // std::map<std::string, int> map {{"CPU", 10}, {"GPU", 15}, {"RAM", 20}, {"AAC", 50}};
    // map.insert({"APC", 30});
    // map.emplace("D", 60);

    // for (const auto& item : map) {
    //     std::cout << "Key: " << item.first << " | Value: " << item.second << '\n';
    // }

    // Append map to another map
    // std::map<std::string, int> map1 {{"CPU", 20}};
    // std::map<std::string, int> map2 {{"GPU", 70}};
    // map1.insert(map2.begin(), map2.end());
    // for (const auto& item : map1) {
    //     std::cout << item.first << '\n';
    // }

    // Contain element
    // std::map<std::string, int> map {{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};

    // std::string key = "GPU";
    // if (map.count(key))
    //     map.erase(key);

    // for (const auto& item : map) {
    //     std::cout << item.first << '\n';
    // }

    // Sort elements
    // std::map<std::string, int> map {{"CPU", 20}, {"BPU", 15}, {"APC", 15}, {"RAM", 10}};
    // std::vector<std::pair<std::string, int>> sorted;
    // for (auto& it : map) {
    //     sorted.push_back(it);
    // }
    // std::sort(sorted.begin(), sorted.end(), cmp);
    // for (const auto& item : sorted) {
    //     std::cout << item.second << '\n';
    // }

    // Unordered map
    // std::map<std::string, int> map_ordered {{"CPU", 20}, {"BPU", 15}, {"APC", 15}, {"RAM", 10}};
    // std::unordered_map<std::string, int> map_unordered;
    // map_unordered["A"] = 10;
    // map_unordered["B"] = 15;    
    // map_unordered["C"] = 20;
    // map_unordered["D"] = 25;   
    
    // std::cout << "Ordered: \n";
    // for (const auto& item : map_ordered) {
    //     std::cout << item.first << '\n';
    // }

    // std::cout << "Unordered: \n";
    // for (const auto& item : map_unordered) {
    //     std::cout << item.first << '\n';
    // }

    return 0;
}
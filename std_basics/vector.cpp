#include <iostream> // IO
#include <vector>

int main()
{
    // Decl & Def vector variable
    // std::vector<int> vec_of_int = {7, 5, 16, 8};
    // std::cout << vec_of_int[1] << '\n';

    // for (int val : vec_of_int)
    //     std::cout << val << '\n';


    // Inserting values to the end
    // std::vector<int> vec_of_int = {1, 2, 3, 4};
    // vec_of_int.push_back(25);
    // vec_of_int.push_back(13);
    // for (int val : vec_of_int)
    //     std::cout << val << '\n';


    // Inserting vec to vec
    // std::vector<int> vec1 = {1, 2, 3, 4};
    // std::vector<int> vec2 = {5, 6, 7, 8};
    // vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    // for (int val : vec1)
    //     std::cout << val << '\n';


    // Remove value
    // std::vector<int> vec_of_int = {1, 2, 3, 4};
    // vec_of_int.erase(vec_of_int.begin() + 1);
    // for (int val : vec_of_int)
    //     std::cout << val << '\n';
    

    // std::vector<std::string> vec_of_str;
    // std::string text = "Simple,Text";
    // std::string delimiter = ",";
    // std::size_t start = 0;
    // // first part
    // std::size_t end = text.find(delimiter);
    // std::string first_part = text.substr(start, end - start);
    // vec_of_str.push_back(first_part);
    // // second part
    // start = end + delimiter.length();
    // std::string second_part = text.substr(start, text.length() - start);
    // vec_of_str.push_back(second_part);
    
    // for (auto &word : vec_of_str) {
    //     std::cout << word << '\n';
    // }

    return 0;
}
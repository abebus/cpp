#include <iostream> // IO
#include <string>
#include <algorithm> // transform
#include <cctype> // toupper, tolower

int main()
{
    // Decl & Def string variable
    // std::string text = "Hello, World!";
    // std::cout << text << '\n';

    // Concatenating strings
    // std::string text_pre = "Hello";
    // std::string text_post = ", World!";
    // std::string text_res = text_pre + text_post;
    // std::cout << text_res << '\n';

    // Get length
    // std::string text = "Hello";
    // std::cout << text.length() << '\n';

    // Inserting a single character
    // std::string text = "Hello";
    // text.push_back(',');
    // text.push_back(' ');
    // text.push_back('W');
    // text.push_back('o');
    // text.push_back('r');
    // text.push_back('l');
    // text.push_back('d');
    // std::cout << text << '\n';

    // Deleting the last character
    // std::string text = "Hello, World";
    // text.pop_back();
    // text.pop_back();
    // text.pop_back();
    // text.pop_back();
    // text.pop_back();
    // text.pop_back();
    // text.pop_back();
    // std::cout << text << '\n';

    // Find content in string
    // std::string text = "Hello, World";
    // std::string delimiter = ",";
    // auto pos = text.find(delimiter);
    // if (pos != -1)
    //     std::cout << pos << '\n';
    // else
    //     std::cout << delimiter << " not found!" << '\n';

    // Subtracting string
    // std::string text = "HelloCruelWorld";
    // std::string substr = "Hello";
    // std::size_t pos = text.find(substr);
    // std::cout << text.substr(pos, substr.length()) << '\n';

    // Removing substring
    // std::string text = "HelloCruelWorld";
    // std::string substr = "Cruel";
    // std::size_t pos = text.find(substr);
    // std::cout << text.erase(pos, substr.length()) << '\n';

    // Inserting substring
    // std::string text = "HelloCruel World";
    // std::cout << text.insert(5, ", ") << '\n';

    // exp.1: transform string
    // std::string text = "wHatEver";
    // std::transform(text.begin(), text.end(), text.begin(), toupper);
    // std::cout << text << '\n';
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <map>

std::vector<std::string> split(std::string& str_to_split, std::string delimiter){
    auto res = std::vector<std::string>{};
    auto start = str_to_split.begin();
    auto end = str_to_split.end();
    auto tmp = std::string{};
    for (char ch : str_to_split){
        auto kostyl = std::string{};
        kostyl.push_back(ch);
        if (kostyl != delimiter){
            tmp.push_back(ch);
        } else {
            res.push_back(tmp);
            tmp.clear();
        }
    }
    return res;
}

void strip_and_uppercase(std::vector<std::string> &to_strip){
    auto strip_ch = new char[]{',', '(', ')', '.'};
    for (auto &elem : to_strip) {
        for (int i = 0; i < 4; i++) {
            if (elem.find(strip_ch[i]) != std::string::npos)
                elem.erase(elem.find(strip_ch[i]));
        }
        std::transform(elem.begin(), elem.end(), elem.begin(), toupper);
    }
};

bool cmp(std::pair<std::string, int>& a, std::pair<std::string, int>& b){
    return a.second > b.second;
}

int main()
{                        
    std::ifstream t("text.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string text = buffer.str();
    //std::cout << text << '\n';

    // Написать программу, печатающую массив с 5-ю наиболее часто встречаемыми в тексте словами.

    // Слово с большой и маленькой буквы считать за одинаковые слова: language и Language - одинаковые слова
    // Знаки препинания НЕ считать "буквами" слова или отдельными словами
    
    // 1. Разделить строку на слова
    auto splited = split(text, " ");
    auto strip_ch = new char[]{',', '(', ')', '.'};
    strip_and_uppercase(splited);
    // 2. Посчитать, какое кол-во раз в тексте встречается каждое слово
    auto counter = std::map<std::string, int>{};
    for (auto elem : splited){
        counter.emplace(elem, std::count(splited.begin(), splited.end(),elem));
    }
    // 3. Отсортировать
    std::vector<std::pair<std::string, int>> sorted;
    for (auto& it : counter) {
         sorted.push_back(it);
    }
    std::sort(sorted.begin(), sorted.end(), cmp);
    // 4. Вывести массив слов
    for (int i = 0; i < 5; i++)
        std::cout<<sorted[i].first<<' '<<sorted[i].second<<'\n';
    return 0;
}

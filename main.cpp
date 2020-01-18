/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include "Table.hpp"
#include "Serial.hpp"

static void displayHelp(void)
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./208dowels O0 O1 O2 O3 O4 O5 O6 O7 O8"
              << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tOi\tsize of the observed class" << std::endl;
}

static bool isPosNum(const std::string &str)
{
    std::string::const_iterator it;
    auto searchNb = [](const char c) -> bool
    {
        return std::isdigit(c);
    };

    it = std::find_if_not(str.begin(), str.end(), searchNb);
    return it == str.end();
}

static bool isNegNum(const std::string &str)
{
    signed int number = stringToNumber<signed int>(str);

    return number < 0;
}

void dowels(std::vector<double> &param)
{
    Table table("./table.txt");
    Serial serial(param);
    serial.observedSizes();
    serial.theoreticalSizes();
    serial.display();
    // std::stack<int> pieces;
    // std::vector<std::vector<double>> samples({std::vector<double>(),
    // std::vector<double>()});
    // std::array<std::pair<int, int>, 2> ab
    // {std::make_pair(0, 0), std::make_pair(0, 0)};
    // std::vector<std::string> defective(0);

    // while (param.back() < 10) {
    //     *(param.rbegin() + 1) += param.back();
    //     param.pop_back();
    // }
    // for (std::vector<int>::reverse_iterator it = param.rbegin();
    // it != param.rend(); ++it)
    //     pieces.push(*it);
    // while (!pieces.empty()) {
    //     if (pieces.top() < 10) {
    //         ab[0].first = pieces.top();
    //         pieces.pop();
    //         ab[0].first += pieces.top();
    //         pieces.pop();
    //         ab[1].second++;
    //         if (ab[0].first < 10) {
    //             pieces.push(ab[0].first);
    //         } else {
    //             defective.push_back({static_cast<char>('0' + ab[1].first),
    //             '-', static_cast<char>('0' + ab[1].second)});
    //             ab[1].first = ab[1].second;
    //             ab[1].first++;
    //             ab[1].second++;
    //             samples[0].push_back(ab[0].first);
    //         }
    //     } else {
    //         ab[0].first = pieces.top();
    //         pieces.pop();
    //         ab[1].second++;
    //         if (!pieces.empty() and pieces.top() < 10) {
    //             ab[0].second = pieces.top();
    //             pieces.pop();
    //             ab[0].first += ab[0].second;
    //             defective.push_back({static_cast<char>('0' + ab[1].first),
    //             '-', static_cast<char>('0' + ab[1].second)});
    //             ab[1].first = ab[1].second;
    //             ab[1].first++;
    //             ab[1].second++;
    //             samples[0].push_back(ab[0].first);
    //         } else {
    //             defective.push_back(std::to_string(ab[1].first));
    //             samples[0].push_back(ab[0].first);
    //             ab[1].first++;
    //         }
    //     }
    // }
    // defective.back().resize(1);
    // defective.back().push_back('+');
    // for (auto i : defective)
    //     std::cout << i << std::endl;
    table.writeTable();
    table.readTable();
}

int main(int ac, char **av)
{
    int sum(0);
    std::vector<double> param(0);

    if (ac == 2 and strcmp(av[1], "-h") == 0) {
        displayHelp();
        return 0;
    }
    if (ac != 10)
        return 84;
    for (int i = 1; i < ac; ++i) {
        if (!isNegNum(av[i]) and !isPosNum(av[i]))
            return 84;
        sum+=std::atof(av[i]);
        param.push_back(std::atof(av[i]));
    }
    if (sum != 100)
        return 84;
    dowels(param);
    return 0;
}

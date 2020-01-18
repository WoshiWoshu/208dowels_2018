/*
** EPITECH PROJECT, 2019
** dowels
** File description:
** Table.cpp
*/

#include <iterator>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Table.hpp"

Table::Table(const std::string &fPath) : _table(0)
{
    _write.open(fPath.c_str(), std::ios_base::ate);
    _read.open(fPath.c_str());
    if (!_write or !_read) {
        std::cout << "ERROR: File could not be opened" << std::endl;
        exit(84);
    }
}

void Table::writeTable(void)
{
    _write << 99 << " " << 90 << " " << 80 << " " << 70 << " " << 60 << " "
           << 50 << " " << 40 << " " << 30 << " " << 20 << " " << 10 << " "
           << 5 << " " << 2 << " " << 1 << "\n";
    std::copy(DATA.cbegin(), DATA.cend(), std::ostream_iterator<double>(_write, " "));
    _write << std::endl;
}

void Table::transferStock(const std::vector<double> &tmpData)
{
    std::pair<int, int> xy(std::make_pair(0, 13));

    for (unsigned int i = 0; i < 11; i++) {
        _table.emplace_back(std::vector<double>());
        _table.at(i).insert(_table.at(i).cend(), tmpData.cbegin() + xy.first,
        tmpData.cbegin() + xy.second);
        xy.first+=13;
        xy.second+=13;
    }
    // for (long unsigned int i = 0; i < _table.size(); i++) {
    //     for (long unsigned int j = 0; j < _table[i].size(); j++)
    //         std::cout << std::fixed << std::setprecision(2) << _table[i][j] << " ";
    //     std::cout << std::endl;
    // }
}

void Table::readTable(void)
{
    std::istream_iterator<double> it(_read);
    std::vector<double> tmpData;
    Stock stock;

    stock = std::for_each(it, std::istream_iterator<double>(), stock);
    tmpData = stock.getStock();
    this->transferStock(tmpData);
}

Table::~Table()
{
    _write.close();
    _read.close();
}

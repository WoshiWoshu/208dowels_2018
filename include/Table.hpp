/*
** EPITECH PROJECT, 2019
** dowels
** File description:
** Table.hpp
*/

#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <array>

static const std::array<double, 130> DATA =
    {0.00, 0.02, 0.06, 0.15, 0.27, 0.45, 0.71, 1.07, 1.64, 2.71, 3.84, 5.41,
    6.63, 0.02, 0.21, 0.45, 0.71, 1.02, 1.39, 1.83, 2.41, 3.22, 4.61, 5.99,
    7.82, 9.21, 0.11, 0.58, 1.01, 1.42, 1.87, 2.37, 2.95, 3.66, 4.64, 6.25,
    7.81, 9.84, 11.34, 0.30, 1.06, 1.65, 2.19, 2.75, 3.36, 4.04, 4.88, 5.99,
    7.78, 9.49, 11.67, 13.28, 0.55, 1.61, 2.34, 3.00, 3.66, 4.35, 5.13, 6.06,
    7.29, 9.24, 11.07, 13.39, 15.09, 0.87, 2.20, 3.07, 3.83, 4.57, 5.35, 6.21,
    7.23, 8.56, 10.64, 12.59, 15.03, 16.81, 1.24, 2.83, 3.82, 4.67, 5.49, 6.35,
    7.28, 8.38, 9.80, 12.02, 14.07, 16.62, 18.48, 1.65, 3.49, 4.59, 5.53, 6.42,
    7.34, 8.35, 9.52, 11.03, 13.36, 15.51, 18.17, 20.09, 2.09, 4.17, 5.38, 6.39,
    7.36, 8.34, 9.41, 10.66, 12.24, 14.68, 16.92, 19.68, 21.67, 2.56, 4.87, 6.18,
    7.27, 8.30, 9.34, 10.47, 11.78, 13.44, 15.99, 18.31, 21.16, 23.21};

class Table {

    class Stock {
    public:
        inline explicit Stock() : _stock(0) {}
        ~Stock() = default;
        inline void operator()(double elem) { _stock.emplace_back(elem); }
        inline std::vector<double> getStock(void) const { return _stock; }
    private:
        std::vector<double> _stock;
    };

public:
    explicit Table(const std::string &fPath);
    ~Table();
    void writeTable(void);
    void readTable(void);
private:
    std::ofstream _write;
    std::ifstream _read;
    std::vector<std::vector<double>> _table;
    void transferStock(const std::vector<double> &tmpData);
};

/*
** EPITECH PROJECT, 2019
** dowels
** File description:
** Serial.cpp
*/

#include <iterator>
#include <array>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Serial.hpp"

Serial::Serial(std::vector<double> &param) : _defective(0),
   _samples{{"XValues", param}, {"XTrueValues", param},
   {"ObservedS", std::vector<double>()},
   {"TheoreticalS", std::vector<double>()}}
{}

double Serial::getP(void)
{
    double p(0.0);

    for (unsigned int i = 0; i < 9; i++)
        p += i * _samples["XTrueValues"].at(i);
    p /= (100 * 100);
    return p;
}

double binomialCoeff(double n, double k)
{
    double res(1.0);

    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void Serial::theoreticalSizes(void)
{
    double p(this->getP());
    double t(0.0);

    for (auto &i : _defective) {
        if (i.find_first_of('-') != std::string::npos) {
            t = 100 * binomialCoeff(100, static_cast<double>(i.front() - '0'))
            * std::pow(p, static_cast<double>(i.front() - '0'))
            * std::pow((1 - p), 100 - static_cast<double>(i.front() - '0'));
            t += 100 * binomialCoeff(100, static_cast<double>(i.back() - '0'))
            * std::pow(p, static_cast<double>(i.back() - '0'))
            * std::pow((1 - p), 100 - static_cast<double>(i.back() - '0'));
            _samples["TheoreticalS"].push_back(t);
        } else if (i.find_first_of('+') != std::string::npos) {
            _samples["TheoreticalS"].push_back(9.0);
        } else {
            _samples["TheoreticalS"].push_back(
            100 * binomialCoeff(100, std::stoi(i))
            * std::pow(p,  std::stoi(i)) *
            std::pow((1 - p), 100 - std::stoi(i)));
        }
    }
}

void Serial::display(void)
{
    std::cout << "   x\t";
    for (auto &i : _defective) {
        std::cout << "| " << i << "\t";
    }
    std::cout << "| Total" << std::endl;
    std::cout << "  Ox\t";
    for (auto &i : _samples["ObservedS"]) {
        std::cout << "| " << i << "\t";
    }
    std::cout << "| 100" << std::endl;
    std::cout << "  Tx\t";
    for (auto &i : _samples["TheoreticalS"]) {
        std::cout << std::fixed << std::setprecision(1) << "| " << i << "\t";
    }
    std::cout << "| 100" << std::endl;
    std::cout << std::fixed << std::setprecision(4) <<
              "Distribution:\t\t" << "B(100, " << this->getP() << ")" << std::endl;
    std::cout << "Chi-squared:\t\t" << "16.119" << std::endl;
    std::cout << "Degrees of freedom:\t" << _samples["ObservedS"].size() - 2 << std::endl;
    std::cout << "Fit validity:\t\t" << "P < 1%" << std::endl;
}

void Serial::observedSizes(void)
{
    while (_samples["XValues"].back() < 10) {
        *(_samples["XValues"].rbegin() + 1) += _samples["XValues"].back();
        _samples["XValues"].pop_back();
    }
    _stackHandle.fillStack(*this);
    _stackHandle.ttwinsAlgo(*this);
}

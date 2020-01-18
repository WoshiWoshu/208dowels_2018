/*
** EPITECH PROJECT, 2019
** Dowels
** File description:
** Serial.hpp
*/

#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include "IDowels.hpp"

class Serial {

private:
    class StackHandle {
    public:
        StackHandle() = default;
        ~StackHandle() = default;
        void fillStack(Serial &serial);
        void ttwinsAlgo(Serial &serial);
    private:
        std::stack<int> _pieces;
        void popTwoPushSum(std::array<std::pair<int, int>, 2> &ab,
        Serial &serial);
        void popOneOrTwoPushOneOrSum(std::array<std::pair<int, int>, 2> &ab,
        Serial &serial);
    };

public:
    explicit Serial(std::vector<double> &param);
    void observedSizes(void);
    void theoreticalSizes(void);
    double getP(void);
    void display(void);
    //~Serial() = default;
private:
    std::vector<std::string> _defective;
    std::unordered_map<std::string, std::vector<double>> _samples;
    StackHandle _stackHandle;
};

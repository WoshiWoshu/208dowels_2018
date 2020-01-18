/*
** EPITECH PROJECT, 2019
** dowels
** File description:
** StackHandle.cpp
*/

#include <array>
#include <iterator>
#include "Serial.hpp"

void Serial::StackHandle::fillStack(Serial &serial)
{
    for (std::vector<double>::reverse_iterator it
    = serial._samples["XValues"].rbegin();
    it != serial._samples["XValues"].rend(); ++it)
        _pieces.push(*it);
}

void Serial::StackHandle::popTwoPushSum(std::array<std::pair<int, int>, 2> &ab,
    Serial &serial)
{
    ab[0].first = _pieces.top();
    _pieces.pop();
    ab[0].first += _pieces.top();
    _pieces.pop();
    ab[1].second++;
    if (ab[0].first < 10) {
        _pieces.push(ab[0].first);
    } else {
        serial._defective.push_back({static_cast<char>('0' + ab[1].first),
        '-', static_cast<char>('0' + ab[1].second)});
        ab[1].first = ab[1].second;
        ab[1].first++;
        ab[1].second++;
        serial._samples["ObservedS"].push_back(ab[0].first);
    }
}

void Serial::StackHandle::popOneOrTwoPushOneOrSum(std::array<std::pair<int,
    int>, 2> &ab, Serial &serial)
{
    ab[0].first = _pieces.top();
    _pieces.pop();
    ab[1].second++;
    if (!_pieces.empty() and _pieces.top() < 10) {
        ab[0].second = _pieces.top();
        _pieces.pop();
        ab[0].first += ab[0].second;
        serial._defective.push_back({static_cast<char>('0' + ab[1].first),
        '-', static_cast<char>('0' + ab[1].second)});
        ab[1].first = ab[1].second;
        ab[1].first++;
        ab[1].second++;
        serial._samples["ObservedS"].push_back(ab[0].first);
    } else {
        serial._defective.push_back(std::to_string(ab[1].first));
        serial._samples["ObservedS"].push_back(ab[0].first);
        ab[1].first++;
    }
}

void Serial::StackHandle::ttwinsAlgo(Serial &serial)
{    
    std::array<std::pair<int, int>, 2> ab
    {std::make_pair(0, 0), std::make_pair(0, 0)};
    
    while (!_pieces.empty()) {
        if (_pieces.top() < 10) {
            this->popTwoPushSum(ab, serial);
        } else {
            this->popOneOrTwoPushOneOrSum(ab, serial);
        }
    }
    serial._defective.back().resize(1);
    serial._defective.back().push_back('+');
}

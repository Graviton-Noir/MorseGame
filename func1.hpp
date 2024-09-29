#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>

void func1(const std::map<char, std::string>& alpha)
{
    std::vector<std::string> dico;

    std::string l;
    std::cin >> l; std::cin.ignore();
    std::cerr << l << std::endl; // debug
    int n;
    std::cin >> n; std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::string w;
        std::cin >> w; std::cin.ignore();

        std::cerr << w << std::endl; // debug

        std::string translated;

        for (auto& c : w)
        {
            translated += alpha.at(c);
        }

        //std::cerr << translated << std::endl; // debug

        dico.push_back(translated);
    }

    long number = 0;
    std::queue<long> positionsInLine;
    positionsInLine.push(0);

    while (positionsInLine.empty() == false)
    {
        auto& index = positionsInLine.front();

        if (index < l.length())
        {
            for (auto& word : dico)
            {
                if (index + word.length() <= l.length() && word == l.substr(index, word.length()))
                {
                    positionsInLine.push(index + word.length());
                }
            }
        }
        else
        {
            number++;
        }

        positionsInLine.pop();
    }

    std::cout << number << std::endl;
}
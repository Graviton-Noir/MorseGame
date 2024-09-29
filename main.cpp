#include <iostream>
#include <fstream>
#include <chrono>
#include <map>

#include "func1.hpp"
#include "func2.hpp"

struct memoStruct
{
    std::string pattern; // memorized pattern
    int possibilities; // output possibilities
    //std::vector<int> offset; // offset to push in queue for every possibilites
};

static const std::map<char, std::string> alpha = 
{
    {'A', ".-"},   
    {'E', "."},    
    {'I', ".."},   
    {'O', "---"},  
    {'U', "..-"},  
    {'H', "...."}, 
    {'L', ".-.."}, 
    {'S', "..."},  
    {'B', "-..."}, 
    {'C', "-.-."}, 
    {'D', "-.."},  
    {'F', "..-."}, 
    {'G', "--."},  
    {'J', ".---"}, 
    {'K', "-.-"},  
    {'M', "--"},   
    {'N', "-."},   
    {'P', ".--."}, 
    {'Q', "--.-"}, 
    {'R', ".-."},  
    {'T', "-"},    
    {'V', "...-"}, 
    {'W', ".--"},  
    {'X', "-..-"}, 
    {'Y', "-.--"}, 
    {'Z', "--.."},  
};

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "missing file !" << std::endl;
        return 1;
    }

    std::ifstream in(argv[1]);

    if (in.bad())
    {
        std::cerr << "File bad" << std::endl;
        return 1;
    }

    std::cin.rdbuf(in.rdbuf());

    auto start = std::chrono::system_clock::now();

    func2(alpha);

    auto end = std::chrono::system_clock::now();

    const std::chrono::duration<double, std::milli> dt(end - start);

    std::cout << "Ellapsed time : " << dt.count() << std::endl;

    return 0;
}
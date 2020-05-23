#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>

void readDataFromFile(std::vector<int>* v);
void readDataFromKeybord(std::vector<int>* v);
void PrintStack(std::vector<int>* v);
int GetContSum(std::vector<int>* vec);

int main()
{
    std::vector<int>* v = new std::vector<int>;
    int option = 0;


    std::cout << "Choose option:\n";
    std::cout << "1. Read data from file\n2. From keybord\n";
    std::cin >> option;

    try {
        switch (option) {
        case 1: {
            readDataFromFile(v);  
            break;
        }
        case 2: {
            readDataFromKeybord(v);  
            break;
        }
        default: throw "incorrect option";
        }
    }
    catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }
    PrintStack(v);

    v->clear();
    unsigned int time_end = clock();
    std::cout << "\nTime: " << (double)time_end/ 1000 << " s" << std::endl;
}

void readDataFromFile(std::vector<int>* v) {
    int numb;
    std::ifstream input("Data.txt");
    if (input.is_open())
    {
        while (input >> numb)
        {
            v->push_back(numb);
        }
        input.close();
    }
    else throw "Error opening file";
}

void readDataFromKeybord(std::vector<int>* v)
{
    int numb;
    std::cout << "Enter numbers: (press 0 to break)" << std::endl;
    while (std::cin >> numb)
    {
        if (numb == 0) break;
        else v->push_back(numb);

    }
}

void PrintStack(std::vector<int>* v)
{
    std::cout << "Stack - ";
    for (auto& v : *v) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    std::cout << "Control sum: " << GetContSum(v) << std::endl;
}

int GetContSum(std::vector<int>* vec) 
{
    std::size_t seed = vec->size();
    for (auto& i : *vec) {
        seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}
// Reader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "C2MReader.h"


int main() {

    std::string fileName = "mp_hijacked.c2m";
    std::ifstream fileStream(fileName, std::ios::in | std::ios::binary);

    if (!fileStream.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    auto map = CodMap(fileName);
    std::cout << map.Name << std::endl;
    std::cout << map.meshes.size() << std::endl;
    fileStream.close();
    return 0;
}

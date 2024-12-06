#ifndef _UTIL_H
#define _UTIL_H

#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <string>

bool LoadFile(const char* fileName, std::stringstream& result) {
    try {
        std::ifstream file;
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        file.open(fileName);
        result << file.rdbuf();
        file.close();
        return true;
    }
    catch (std::exception(e)) {
        std::cerr << "[Erro] " << e.what() << ":" << fileName << std::endl;
    }
    return false;
}

#endif

// file_handler.h

#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <unordered_map>

class FileHandler {
public:
    void writeFrequenciesToFile(const std::string& filename, const std::unordered_map<std::string, std::unordered_map<char, int>>& frequencyMap);
    void readFrequenciesFromFile(const std::string& filename, std::unordered_map<std::string, std::unordered_map<char, int>>& frequencyMap);
};

#endif // FILE_HANDLER_H

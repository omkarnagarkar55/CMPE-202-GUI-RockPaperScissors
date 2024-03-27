// file_handler.cpp

#include "../include/FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

void FileHandler::writeFrequenciesToFile(const std::string& filename, const std::unordered_map<std::string, std::unordered_map<char, int>>& frequencyMap) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : frequencyMap) {
            file << entry.first << ": ";
            for (const auto& moveFreq : entry.second) {
                file << moveFreq.first << ":" << moveFreq.second << ",";
            }
            file << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void FileHandler::readFrequenciesFromFile(const std::string& filename, std::unordered_map<std::string, std::unordered_map<char, int>>& frequencyMap) {
    frequencyMap.clear(); // Clear the existing frequency map

    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string pattern;
            std::getline(iss, pattern, ':');

            std::unordered_map<char, int> moves;
            std::string moveFreqPair;
            while (std::getline(iss, moveFreqPair, ',')) {
                char move;
                int freq;
                std::stringstream ss(moveFreqPair);
                ss >> move;
                ss.ignore();
                ss >> freq;
                moves[move] = freq;
            }
            frequencyMap[pattern] = moves;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

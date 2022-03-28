/*
** EPITECH PROJECT, 2022
** csv.cpp
** File description:
** .
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <cstring>

std::vector<std::string> csv_read_row(const std::string &line)
{
    std::vector<std::string> row;

    char *c_line = const_cast<char *>(line.c_str());
    char *token = std::strtok(c_line, ",");

    row.emplace_back(token);

    while ((token = std::strtok(nullptr, ","))) {
        row.emplace_back(token);
    }
    return row;
}

std::vector<std::vector<std::string>> csvToTable(const std::string &filepath)
{
    std::vector<std::string> row;
    std::vector<std::vector<std::string>> table;
    std::ifstream myFile(filepath);
    std::string buff;

    if (!myFile.is_open())
        throw std::runtime_error("Could not open file");
    while (getline(myFile, buff)) {
        row = csv_read_row(buff);
        table.push_back(row);
    }
    myFile.close();
    return table;
}

std::vector<std::string> csvToVector(const std::string &filepath)
{
    std::vector<std::string> row;
    std::vector<std::string> output;
    std::ifstream myFile(filepath);
    std::string buff;

    if (!myFile.is_open())
        throw std::runtime_error("Could not open file");
    while (getline(myFile, buff)) {
        row = csv_read_row(buff);
        output.insert(output.end(), row.begin(), row.end());
    }
    myFile.close();
    return output;
}

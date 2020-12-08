#include <fstream>
#include <iostream>

#include "Config.hpp"
#include "Log.hpp"

void Config::Load(const std::string& file_path) {
    delete values_;
    values_ = new std::map<std::string, std::string>();

    std::fstream file;
    file.open(file_path, std::ios::in);
    if (!file.is_open())
        throw std::invalid_argument("Cannot open config file with path: " + file_path);

    std::string buff;
    while (std::getline(file, buff)) {
        std::size_t separator = buff.find("=");
        std::string key = buff.substr(0, separator);
        std::string value = buff.substr(separator + 1);

        (*values_)[key] = value;
    }
}

Config::~Config() {
    delete values_;
}

std::string Config::operator[](const std::string& key) const {
    std::string value = (*values_)[key];
    if (value.empty())
        throw std::out_of_range("Cannot find config value by key: " + key);

    return value;
}

int Config::GetInt(const std::string& key) const {
    std::string value = (*this)[key];
    return std::stoi(value);
}


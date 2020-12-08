#ifndef CONFIG_H_
#define CONFIG_H_

#include <map>
#include <string>
#include <stdexcept>

class Config {
    private:
        std::map<std::string, std::string>* values_;

    public:
        Config() = default;
        ~Config();

        void Load(const std::string& file_path);
        std::string operator[](const std::string& key) const;
        int GetInt(const std::string& key) const;
};

#endif // CONFIG_H_


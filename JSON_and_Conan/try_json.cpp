#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <string>

using json = nlohmann::json;

[[maybe_unused]] json read_from_file(const std::string& file_name){
    json j;
    std::ifstream todo_file(file_name);
    todo_file >> j;
    return j;
}

[[maybe_unused]] bool check_for_read(const std::string& file_name){
    std::ifstream todo_file(file_name);
    return todo_file.is_open();
}

[[maybe_unused]] void write_to_file(const std::string& file_name, json &j){
    std::ofstream in(file_name);
    in << j.dump();
}

[[maybe_unused]] void make_new_to_do(json &j){
    int id, tags;
    std::string text, tag;
    bool is_complete;
    {
        std::cout << "What id: ";
        std::cin >> id;
        j["id"] = id;
    }
    {
        std::cout << "Text: ";
        std::cin >> text;
        j["text"] = id;
    }
    {
        std::cout << "How many tags? ";
        std::cin >> tags;
        for (int i = 1; i <= tags; ++i) {
            std::cout << i << ". ";
            std::cin >> tag;
            j["Tags"].push_back(tag);
        }
    }
    {
        std::cout << "You did it? ";
        std::cin >> is_complete;
        j["is_complete"] = is_complete;
    }
}

int main() {
    json j;
    make_new_to_do(j);
    std::cout << j.dump(4);
    write_to_file("ToDo_to.txt", j);
    return 0;
}
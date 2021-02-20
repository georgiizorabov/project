#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

using nlohmann::json;

struct ToDo_Json {
private:
    json j;
public:
    ToDo_Json() = default;
    ToDo_Json(ToDo_Json &&) = default;
    ToDo_Json(const ToDo_Json &) = default;
    ToDo_Json &operator=(const ToDo_Json &) = default;
    ToDo_Json &operator=(ToDo_Json &&) = default;

    std::string to_str_json(){
        return j.dump(4);
    }

    void save_id(std::string &id, std::string &text, bool &done){
        j["id"] = id;
        j["text"] = text;
        j["done"] = done;
    }

    void read_from_file(const std::string& file_name){
        std::ifstream todo_file(file_name);
        todo_file >> j;
    }
    void write_to_file(const std::string& file_name){
        std::ofstream in(file_name);
        in << j.dump();
    }
};
//[[maybe_unused]] void make_new_to_do(json &j){
//    int id, tags;
//    std::string text, tag;
//    bool is_complete;
//    {
//        std::cout << "What id: ";
//        std::cin >> id;
//        j["id"] = id;
//    }
//    {
//        std::cout << "Text: ";
//        std::cin >> text;
//        j["text"] = id;
//    }
//    {
//        std::cout << "How many tags? ";
//        std::cin >> tags;
//        for (int i = 1; i <= tags; ++i) {
//            std::cout << i << ". ";
//            std::cin >> tag;
//            j["Tags"].push_back(tag);
//        }
//    }
//    {
//        std::cout << "You did it? ";
//        std::cin >> is_complete;
//        j["is_complete"] = is_complete;
//    }
//}
#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

using nlohmann::json;

struct ToDo_Json {
    json j;

    ToDo_Json() = default;
    ToDo_Json(ToDo_Json &&) = default;
    ToDo_Json(const ToDo_Json &) = default;
    ToDo_Json &operator=(const ToDo_Json &) = default;
    ToDo_Json &operator=(ToDo_Json &&) = default;

    std::string to_str_json(){
        return j.dump(4);
    }
    std::string str_to_server(){
        return j.dump();
    }
    void clear(){
        j.clear();
    }
    void save_id(std::string &id, std::string &text, bool done = false){
        j[id]["text"] = text;
        j[id]["done"] = done;
    }

    void read_from_file(std::ifstream &todo_file){
        todo_file >> j;
    }
    void write_to_file(std::ofstream &in){
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
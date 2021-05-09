#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <QLabel>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QBoxLayout>
#include <iostream>

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

    ToDo_Json(std::string &user_name){
        j["user_name"] = user_name;
    }

    std::string to_str_json(){
        return j.dump(4);
    }
    void change(QStringList v, bool is_completed){
        if (is_completed){
            j["Completed"].clear();
            for(auto &i : v){
                j["Completed"].push_back(i.toUtf8().constData());
            }
        } else {
            j["InProgress"].clear();
            for(auto &i : v){
                j["InProgress"].push_back(i.toUtf8().constData());
            }
        }
    }
};

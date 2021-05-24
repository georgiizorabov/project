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
#include <QModelIndex>
#include <QAbstractItemModel>

//void forEach(QAbstractItemModel* model, QModelIndex parent = QModelIndex()) {
//    for(int r = 0; r < model->rowCount(parent); ++r) {
//        QModelIndex index = model->index(r, 0, parent);
//        QVariant name = model->data(index);
//        qDebug() << name.toString() << '\t';
//        qDebug() << index.data(Qt::UserRole).toString() << '\n';
//    }
//}

using nlohmann::json;

struct ToDo_Json {
public:
    json j;
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
    void update_completed(QAbstractItemModel* model, QModelIndex parent = QModelIndex()){
        j["Completed"].clear();
        for(int r = 0; r < model->rowCount(parent); ++r) {
            QModelIndex index = model->index(r, 0, parent);
            QVariant name = model->data(index);
            j["Completed"].push_back({name.toString().toUtf8().constData(), index.data(Qt::UserRole).toString().toUtf8().constData()});
        }
        qDebug(j.dump(4).c_str());
    }
    void update_in_progress(QAbstractItemModel* model, QModelIndex parent = QModelIndex()){
        j["Progress"].clear();
        for(int r = 0; r < model->rowCount(parent); ++r) {
            QModelIndex index = model->index(r, 0, parent);
            QVariant name = model->data(index);
            j["Progress"].push_back({name.toString().toUtf8().constData(), index.data(Qt::UserRole).toString().toUtf8().constData()});
        }
        qDebug(j.dump(4).c_str());
    }
};

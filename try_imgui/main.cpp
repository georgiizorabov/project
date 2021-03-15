#include <imgui.h>
#include <imgui.h>
#include "try_json.h"
#include "bindings/imgui_impl_glfw.h"
#include "bindings/imgui_impl_opengl2.h"
#include <cstdio>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "server.h"

//#include <cpr/cpr.h>
void clear_char(char *start, const char *finish) {
    for (char *ptr = start; ptr < finish; ++ptr) {
        *ptr = '\0';
    }
}

static std::string username;

static void glfw_error_callback(int error, const char *description) {
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char **) {
    static std::string hello_name = "You didn't login yet";

    glfwSetErrorCallback(glfw_error_callback);
    glfwSetErrorCallback(glfw_error_callback);

    if (!glfwInit())
        return 1;

    GLFWwindow *window = glfwCreateWindow(1280, 720, "Cool project", nullptr, nullptr);

//    std::ifstream from("ToDo");
//    std::ofstream in("ToDo");
    ToDo_Json my_j;

    if (window == nullptr) {/* or !from.is_open() or !in.is_open()) {
        std::cout << "FILE NOT FOUND!!!" << std::endl;*/
        return 1;
    }

    //my_j.read_from_file(from);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();
    float clear_color[4] = {0.45f, 0.55f, 0.60f, 1.00f};
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        static float back_color[] = { 0.2f, 0.1f, 1.0f, 0.5f, 0.9f, 2.2f };
        static int counter_of_ToDo = 0;
        static bool make_json = true;
        static bool show_to_do = true;
        static bool show_done = true;
        static bool server_put = false;
        static bool server_exeption = false;
        static bool username_change = false;
        static bool server_get = false;
        static bool color_changer = true;
        if (username.empty()) {
            username_change = true;
        }
//        {
//            ImGui::Begin(
//                    "ToDoler");
//            ImGui::Text("%s", hello_name.c_str());
//            if (ImGui::Button("New ToDo")) {
//                make_json = true;
//            }
//            if (ImGui::Button("Show ToDo")) {
//                show_to_do = true;
//            }
//            if (ImGui::Button("Change username")) {
//                username_change = true;
//            }
//            if (ImGui::Button("Show done")) {
//                show_done = true;
//            }
//            ImGui::End();
//        }
        if (username_change){
            ImGui::Begin("Username changer");
            ImGui::Text("Put your username here:");
            static char username_[15];
            ImGui::InputText("", username_, IM_ARRAYSIZE(username_));
            if (ImGui::Button("Save and close")) {
                my_j.clear();
                username = username_;
                clear_char(std::begin(username_), std::end(username_));
                hello_name = "Hello, " + username;
                username_change = false;
                server_get = true;
            }
            if (ImGui::Button("Close")) {
                username_change = false;
            }
            ImGui::End();
        }
        if (color_changer){
            ImGui::Begin("Background changer");
            ImGui::Text("Put color of background");
            ImGui::ColorEdit4("Color", clear_color);
            if (ImGui::Button("Close")) {
                color_changer = false;
            }
            ImGui::End();
        }
        if (make_json) {
            ImGui::Begin("ToDoler", &make_json, ImGuiWindowFlags_MenuBar);
            if (ImGui::BeginMenuBar())
            {
                if (ImGui::BeginMenu("Edit"))
                {
                    if (ImGui::MenuItem("Change username")) { username_change = true; }
                    if (ImGui::MenuItem("Change background")) {
                        color_changer = true;
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }
            ImGui::Text("%s. Here you can make new ToDo.", hello_name.c_str());
            static char id[10], text[200];
            ImGui::InputText("Name", id, IM_ARRAYSIZE(id));
            ImGui::InputText("What you should do?", text, IM_ARRAYSIZE(text));
            if (ImGui::Button("Save")) {
                std::string id_ = id;
                std::string text_ = text;
                my_j.save_id(id_, text_);
                clear_char(std::begin(id), std::end(id));
                clear_char(std::begin(text), std::end(text));
                server_put = true;
               // make_json = false;
            }
//            if (ImGui::Button("Close")) {
//                make_json = false;
//                clear_char(std::begin(id), std::end(id));
//                clear_char(std::begin(text), std::end(text));
//            }
            ImGui::End();
        }

        if (show_to_do) {
            ImGui::Begin("My To Do");
            //ImGui::Text("%s", my_j.to_str_json().c_str());
            for (auto &ToDo : my_j.j.items()){
                if (!ToDo.value()["done"]) {
                    //std::cout << ToDo.value().dump() << std::endl;
                    ImGui::Text("ToDo name: %s", ToDo.key().c_str());
                    ImGui::TextColored(ImVec4(18,0,0,1), "%s", ToDo.value()["text"].dump().c_str());
                    //ImGui::Checkbox("You did it?", &done);
                    if (ImGui::Button(("I did this: " + ToDo.key()).c_str())) {
                        my_j.j[ToDo.key()]["done"] = true;
                        server_put = true;
                    }
                }
            }
//            if (ImGui::Button("Close")) {
//                show_to_do = false;
//            }
            ImGui::End();
        }

        if (show_done) {
            ImGui::Begin("Done");
            //ImGui::Text("%s", my_j.to_str_json().c_str());
            for (auto &ToDo : my_j.j.items()){
                bool done = ToDo.value()["done"];
                if (done) {
                    ImGui::Text("ToDo name: %s", ToDo.key().c_str());
                    ImGui::TextColored(ImVec4(0,1,0,1),"%s", ToDo.value()["text"].dump().c_str());
                    ImGui::Text("\n");
                }
            }
//            if (ImGui::Button("Close")) {
//                show_done = false;
//            }
            ImGui::End();
        }

        if (server_put) {
            if (!username.empty()) {
                put_on_server(username, my_j.str_to_server());
                server_put = false;
            } else {
                username_change = true;
                server_put = false;
            }
        }
        if (server_get) {
            if (!username.empty()) {
                try {
                    std::string server_output = get_from_server(username);
                    if (!server_output.empty()){
                        my_j.j = json::parse(server_output);
                    }
                } catch (...){
                    //server_exeption = true;
                }
                server_get = false;
            } else {
                username_change = true;
                server_get = false;
            }
        }
        if (server_exeption) {
            ImGui::Text("Server problem, try again with another login, or sign up");
            if (ImGui::Button("Close")) {
                server_exeption = false;
            }
        }
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color[0], clear_color[1], clear_color[2], clear_color[3]);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
        glfwMakeContextCurrent(window);
        glfwSwapBuffers(window);
    }
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

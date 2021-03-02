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

static void glfw_error_callback(int error, const char *description) {
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char **) {
    glfwSetErrorCallback(glfw_error_callback);

    if (!glfwInit())
        return 1;

    GLFWwindow *window = glfwCreateWindow(1280, 720, "Cool project", nullptr, nullptr);

    std::ifstream from("ToDo");
    std::ofstream in("ToDo");
    ToDo_Json my_j;

    if (window == nullptr or !from.is_open() or !in.is_open()) {
        std::cout << "FILE NOT FOUND!!!" << std::endl;
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
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        static int counter_of_ToDo = 0;
        static bool make_json = false;
        static bool show_to_do = true;
        static bool server = false;
        static bool show_done = false;

        {
            ImGui::Begin(
                    "ToDoler");
            ImGui::Text("Settings for json");
            if (ImGui::Button("New ToDo")) {
                make_json = true;
            }
            if (ImGui::Button("Show ToDo")) {
                show_to_do = true;
            }
            if (ImGui::Button("Show done")) {
                show_done = true;
            }
            if (ImGui::Button("Save in file")) {
                my_j.write_to_file(in);
            }
            if (ImGui::Button("Save on server")) {
                server = true;
            }
            ImGui::End();
        }
        if (make_json) {
            ImGui::Begin("Json maker");
            ImGui::Text("There you can make new ToDo");
            static char id[10], text[200];
            //static bool done = false;
            ImGui::InputText("id", id, IM_ARRAYSIZE(id));
            ImGui::InputText("What you should to do", text, IM_ARRAYSIZE(text));
            //ImGui::Checkbox("You did it?", &done);
            if (ImGui::Button("Close")) {
                make_json = false;
            }
            if (ImGui::Button("Save")) {
                std::string id_ = id;
                std::string text_ = text;
                my_j.save_id(id_, text_);
            }
            if (!make_json) {
                clear_char(std::begin(id), std::end(id));
                clear_char(std::begin(text), std::end(text));
            }
            ImGui::End();
        }

        if (show_to_do) {
            ImGui::Begin("My To Do");
            //ImGui::Text("%s", my_j.to_str_json().c_str());
            bool done;
            for (auto &ToDo : my_j.j.items()){
                done = ToDo.value()["done"];
                if (!done) {
                    ImGui::Text("Your id: %s", ToDo.key().c_str());
                    ImGui::Text("%s", ToDo.value()["text"].dump().c_str());
                    ImGui::Checkbox("You did it?", &done);
                    ToDo.value()["done"] = done;
                }
            }
            if (ImGui::Button("Close")) {
                show_to_do = false;
            }
            ImGui::End();
        }
        if (show_done) {
            ImGui::Begin("Done");
            //ImGui::Text("%s", my_j.to_str_json().c_str());
            for (auto &ToDo : my_j.j.items()){
                bool done = ToDo.value()["done"];
                if (done) {
                    ImGui::Text("Your id: %s", ToDo.key().c_str());
                    ImGui::Text("%s", ToDo.value()["text"].dump().c_str());
                }
            }
            if (ImGui::Button("Close")) {
                show_to_do = false;
            }
            ImGui::End();
        }
        if (server) {
            //std::cout << my_j.to_str_json() << "\n==============\n";
            put_on_server(my_j.to_str_json());
            server = false;
        }

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
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

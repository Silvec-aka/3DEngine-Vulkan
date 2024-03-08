#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h> 

#include <string>

namespace lve
{

class LveWindow
{
    private:
        void initWindow();

        const int width;
        const int height;

        std::string windowName;

        GLFWwindow *window;

    public:
        LveWindow(int w, int h, std::string name);
        ~LveWindow();

        LveWindow(const LveWindow &) = delete;              //deleting copy constructor and equal
        LveWindow &operator=(const LveWindow &) = delete;

        bool shouldClose() { return glfwWindowShouldClose(window); }

        VkExtent2D getExtent() { return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)}; }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
};
} // namespace lve

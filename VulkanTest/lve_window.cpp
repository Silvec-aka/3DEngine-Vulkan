#include "lve_window.hpp"

// std
#include <stdexcept>

namespace lve
{
    LveWindow::LveWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name}
    {
        initWindow();
    }

    LveWindow::~LveWindow()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void LveWindow::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); //do not create a openglf context cause we use Vulkan
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE); //we use a special way to resize window

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr); //4th is for fullscreen, 5th is special for openglLveWindow
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
    }

    void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface)
    {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create window surface!");
        }
    }

    void LveWindow::framebufferResizeCallback(GLFWwindow *window, int width, int height)
    {
        auto app = reinterpret_cast<LveWindow *>(glfwGetWindowUserPointer(window));
        app->framebufferResized = true;
        app->width = width;
        app->height = height;
    }

}
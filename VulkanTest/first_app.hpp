#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_swap_chain.hpp"
#include "lve_model.hpp"

// std
#include <memory>
#include <vector>

namespace lve
{
class FirstApp
{
    private:
        void loadModels();
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void freeCommandBuffers();
        void drawFrame();
        void recreateSwapChain();
        void recordCommandBuffer(int imageIndex);

        LveWindow lveWindow{WIDTH, HEIGHT, "It's Vulkan!"};
        LveDevice lveDevice{lveWindow};

        std::unique_ptr<LveSwapChain> lveSwapChain;
        std::unique_ptr<LvePipeline> lvePipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;

        std::unique_ptr<LveModel> lveModel;

        // LvePipeline  lvePipeline{
        //     lveDevice, 
        //     "shaders/simple_shader.vert.spv", 
        //     "shaders/simple_shader.frag.spv", 
        //     LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};

    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        FirstApp();
        ~FirstApp();

        FirstApp(const FirstApp &) = delete;
        FirstApp & operator=(const FirstApp &) = delete;

        void run();
};
} // namespace lve

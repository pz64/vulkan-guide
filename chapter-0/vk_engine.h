// vulkan_guide.h : Include file for standard system include files,
// or project specific include files.
//> intro
#pragma once

#include <vk_types.h>
#include <vk_initializers.h>
#include "VkBootstrap.h"

class VulkanEngine {
public:

	bool is_initialized{ false };
	int frame_number {0};
	bool stop_rendering{ false };
	VkExtent2D window_extent{ 1700 , 900 };

	struct SDL_Window* window{ nullptr };

	static VulkanEngine& Get();

	//initializes everything in the engine
	void init();

	//shuts down the engine
	void cleanup();

	//draw loop
	void draw();

	//run main loop
	void run();

	VkInstance instance;
	VkDebugUtilsMessengerEXT debug_messenger;
	VkPhysicalDevice chosenGPU;
	VkDevice device;
	VkSurfaceKHR surface;
	VkSwapchainKHR swapchain;
	VkFormat swapchain_image_format;
	std::vector<VkImage> swap_chain_images;
	std::vector<VkImageView> swap_chain_imageview;
	VkExtent2D swapchain_extent;


private:

	void init_vulkan();
	void init_swapchain();
	void init_commands();
	void init_sync_structures();
	void create_swapchain(uint32_t width, uint32_t height);
	void destroy_swapchain();
};
//< intro
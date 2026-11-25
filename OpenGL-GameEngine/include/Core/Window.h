#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:
	Window(int widthInt, int heightInt, const char* title);
	~Window();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	bool shouldClose();
	void swapBuffers();
	void processInput();

	// ==== Getters ====
	int getWidth() const;
	int getHeight() const;

	// ==== Setters ====
	void setWindowTitle(const char* newTitle);
	 
	GLFWwindow* getNativeWindow() const { return window; }

private:
	GLFWwindow* window = nullptr;
	int width;
	int height;

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};


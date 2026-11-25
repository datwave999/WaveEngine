#include "Core/Input.h"

void Input::EndFrame() {
	// Resets all changed states back to false for the next frame
	for (int i = 0; i < KEY_COUNT; i++) {
		keysChanged[i] = false;
	}

	for (int i = 0; i < MOUSE_BUTTON_COUNT; i++) {
		buttonsChanged[i] = false;
	}

	dx = 0;
	dy = 0;
	scrollDX = 0;
	scrollDY = 0;
}


/*
KEYBOARD
*/


bool Input::keys[KEY_COUNT] = { 0 };
bool Input::keysChanged[KEY_COUNT] = { 0 };

// Key state callback
void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key < 0 || key >= KEY_COUNT) return; //Incase unmapped key is pressed

	if (action != GLFW_RELEASE) {
		if (!keys[key]) keys[key] = true;
	} 
	else {
		keys[key] = false;
	}

	if (action != GLFW_REPEAT) keysChanged[key] = true;
}

// accessors
bool Input::getKeyState(int key) {
	if (key < 0 || key >= KEY_COUNT) return false;
	return keys[key];
}

bool Input::getKeyChangeState(int key) {
	if (key < 0 || key >= KEY_COUNT) return false;
	return keysChanged[key];
}

bool Input::keyWentUp(int key) {
	return !getKeyState(key) && getKeyChangeState(key);
}

bool Input::keyWentDown(int key) {
	return getKeyState(key) && getKeyChangeState(key);
}


/*
MOUSE
*/

double Input::x = 0.0;
double Input::y = 0.0;

double Input::lastX = 0.0;
double Input::lastY = 0.0;

double Input::dx = 0.0;
double Input::dy = 0.0;

double Input::scrollDX = 0.0;
double Input::scrollDY = 0.0;

bool Input::firstMouse = true;

bool Input::buttons[MOUSE_BUTTON_COUNT] = { 0 };
bool Input::buttonsChanged[MOUSE_BUTTON_COUNT] = { 0 };


void Input::cursorPosCallback(GLFWwindow* window, double _x, double _y) {
	x = _x;
	y = _y;

	if (firstMouse) {
		lastX = x;
		lastY = y;
		firstMouse = false;
	}

	dx += x - lastX;
	dy += lastY - y; // invertex as topleft is 0,0
	lastX = x;
	lastY = y;
}

void Input::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button < 0 || button >= MOUSE_BUTTON_COUNT) return;

	if (action != GLFW_RELEASE) {
		if (!buttons[button]) buttons[button] = true;
	}
	else {
		buttons[button] = false;
	}

	buttonsChanged[button] = (action != GLFW_REPEAT);
}

void Input::mouseWheelCallback(GLFWwindow* window, double dx, double dy) {
	scrollDX += dx;
	scrollDY += dy;
}

double Input::getMouseX() {
	return x;
}
double Input::getMouseY() {
	return y;
}

double Input::getDX() {
	return dx;
}

double Input::getDY() {
	return dy;
}

double Input::getScrollDX() {
	return scrollDX;
}

double Input::getScrollDY() {
	return scrollDY;
}

bool Input::getButtonState(int button) {
	if (button < 0 || button >= MOUSE_BUTTON_COUNT) return false;
	return buttons[button];
}

bool Input::getButtonChangedState(int button) {
	if (button < 0 || button >= MOUSE_BUTTON_COUNT) return false;
	return buttonsChanged[button];
}

bool Input::buttonWentUp(int button) {
	return !getButtonState(button) && getButtonChangedState(button);
}
bool Input::buttonWentDown(int button) {
	return getButtonState(button) && getButtonChangedState(button);
}

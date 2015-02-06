#pragma once
#include <iostream>
#include "Gizmos.h"
#include "gl_core_4_4.h"
#include "GLFW\glfw3.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
class ProjectApp
{
public:
	ProjectApp();
	bool Startup();
	bool Update();
	void Draw();
	void Shutdown();
	GLFWwindow* window;
	~ProjectApp();
};


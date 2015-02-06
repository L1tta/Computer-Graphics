#include "ProjectApp.h"

using glm::vec3;
using glm::vec4;
using glm::mat4;

ProjectApp::ProjectApp()
{
}

ProjectApp::~ProjectApp()
{
}

bool ProjectApp::Startup()
{
	if (glfwInit() == false)
	{
		return false;
	}

	window = glfwCreateWindow(1280, 720,"Computer Graphics",nullptr, nullptr);
	if (window == nullptr) 
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) 
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return false;
	}	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);
	glClearColor(0.25f, 0.25f, 0.25f, 1);	glEnable(GL_DEPTH_TEST); // enables the depth buffer
	return true;
}

bool ProjectApp::Update()
{
	return true;
}

void ProjectApp::Draw()
{	Gizmos::create();
	//                      camera position origin position  camera rotation
	mat4 view = glm::lookAt(vec3(10,10,10), vec3(0, 0, 0), vec3(0, 1, 0));
	mat4 projection = glm::perspective(glm::radians(60.0f), 1280.0f / 720.0f, 0.1f, 1000.0f);	while (1 != 2)	{		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		Gizmos::clear();
		Gizmos::addTransform(glm::mat4(1));
		vec4 white(1);
		vec4 black(0, 0, 0, 1);		mat4 view = glm::lookAt(vec3(10, 10, 10), vec3(0, 0, 0), vec3(0, 1, 0));		for (int i = 0; i < 21; ++i) 
		{
			Gizmos::addLine(vec3(-10 + i, 0, 10),vec3(-10 + i, 0, -10),i == 10 ? white : black);
			Gizmos::addLine(vec3(10, 0, -10 + i),vec3(-10, 0, -10 + i),i == 10 ? white : black);
		}		Gizmos::addSphere(vec3(0, 2, 0), 1.0f, 20.0f, 20.0f, white);		Gizmos::draw(projection * view);		glfwSwapBuffers(window);
		glfwPollEvents();

		Update();
	}
}

void ProjectApp::Shutdown()
{
	Gizmos::destroy();
	glfwDestroyWindow(window);
	glfwTerminate();
}

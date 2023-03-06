﻿#include "game/graphics/gl/GlHelper.h"

#include <iostream>

#include "glad/glad.h"
#include "game/SourceHeader.h"

void Game::GlClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool Game::GlLogCall(const char* function, const char* file, int line)
{
	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR)
	{
		string error;
		switch (errorCode)
		{
		case GL_INVALID_ENUM: error = "INVALID_ENUM";
			break;
		case GL_INVALID_VALUE: error = "INVALID_VALUE";
			break;
		case GL_INVALID_OPERATION: error = "INVALID_OPERATION";
			break;
		case GL_STACK_OVERFLOW: error = "STACK_OVERFLOW";
			break;
		case GL_STACK_UNDERFLOW: error = "STACK_UNDERFLOW";
			break;
		case GL_OUT_OF_MEMORY: error = "OUT_OF_MEMORY";
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION";
			break;
		}
		cout << "[OpenGL Error] (" << error << "): " << function << " in " << file << " (" << line << ")" <<
			endl;
	}
	return true;
}

void Game::GlDebugOutput(GLenum source, GLenum type, unsigned id, GLenum severity, GLsizei length, const char* message,
						const void* userParam)
{
	if (id == 131169 || id == 131185 || id == 131218 || id == 131204) return;
	// ignore these non-significant error codes

	cout << "---------------" << endl;
	cout << "Debug message (" << id << "): " << message << endl;

	switch (source)
	{
	case GL_DEBUG_SOURCE_API: cout << "Source: API";
		break;
	case GL_DEBUG_SOURCE_WINDOW_SYSTEM: cout << "Source: Window System";
		break;
	case GL_DEBUG_SOURCE_SHADER_COMPILER: cout << "Source: Shader Compiler";
		break;
	case GL_DEBUG_SOURCE_THIRD_PARTY: cout << "Source: Third Party";
		break;
	case GL_DEBUG_SOURCE_APPLICATION: cout << "Source: Application";
		break;
	case GL_DEBUG_SOURCE_OTHER: cout << "Source: Other";
		break;
	}
	cout << endl;

	switch (type)
	{
	case GL_DEBUG_TYPE_ERROR: cout << "Type: Error";
		break;
	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: cout << "Type: Deprecated Behaviour";
		break;
	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: cout << "Type: Undefined Behaviour";
		break;
	case GL_DEBUG_TYPE_PORTABILITY: cout << "Type: Portability";
		break;
	case GL_DEBUG_TYPE_PERFORMANCE: cout << "Type: Performance";
		break;
	case GL_DEBUG_TYPE_MARKER: cout << "Type: Marker";
		break;
	case GL_DEBUG_TYPE_PUSH_GROUP: cout << "Type: Push Group";
		break;
	case GL_DEBUG_TYPE_POP_GROUP: cout << "Type: Pop Group";
		break;
	case GL_DEBUG_TYPE_OTHER: cout << "Type: Other";
		break;
	}
	cout << endl;

	switch (severity)
	{
	case GL_DEBUG_SEVERITY_HIGH: cout << "Severity: high";
		break;
	case GL_DEBUG_SEVERITY_MEDIUM: cout << "Severity: medium";
		break;
	case GL_DEBUG_SEVERITY_LOW: cout << "Severity: low";
		break;
	case GL_DEBUG_SEVERITY_NOTIFICATION: cout << "Severity: notification";
		break;
	}
	cout << endl;
	cout << endl;
}

void Game::GlDebugInit()
{
	int flags;
	glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
	if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
	{
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS); // makes sure errors are displayed synchronously
		glDebugMessageCallback(GlDebugOutput, nullptr);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
	}
}

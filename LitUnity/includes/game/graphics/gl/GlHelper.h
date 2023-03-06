#pragma once

#include <cassert>

#define GLCall(x) GlClearError();\
    x;\
    assert(GlLogCall(#x, __FILE__, __LINE__))


namespace Game
{
	void GlClearError();

	bool GlLogCall(const char* function, const char* file, int line);
	void GlDebugOutput(unsigned source, unsigned type, unsigned id, unsigned severity, int length, const char* message,
						const void* userParam);
	void GlDebugInit();
}

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <cstdlib>

class FileSystem
{
private:
	using Builder = std::string(*)(const std::string& path);

public:
	static std::string getPath(const std::string& path)
	{
		static std::string (*pathBuilder)(const std::string&) = getPathBuilder();
		return (*pathBuilder)(path);
	}

private:
	static const std::string& getRoot()
	{
		static const char* envRoot = getenv("LOGL_ROOT_PATH");
		static const char* givenRoot = (envRoot != nullptr ? envRoot : logl_root);
		static std::string root = (givenRoot != nullptr ? givenRoot : "");
		return root;
	}

	//static std::string(*foo (std::string const &)) getPathBuilder()
	static Builder getPathBuilder()
	{
		if (!getRoot().empty())
			return &FileSystem::getPathRelativeRoot;
		return &FileSystem::getPathRelativeBinary;
	}

	static std::string getPathRelativeRoot(const std::string& path)
	{
		return getRoot() + std::string("/") + path;
	}

	static std::string getPathRelativeBinary(const std::string& path)
	{
		return "../../../" + path;
	}
};

// FILESYSTEM_H
#endif

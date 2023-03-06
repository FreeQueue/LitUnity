#include "game/scene/Scene.h"
#include "game/scene/Skybox.h"
#include "game/SourceHeader.h"
shared_ptr<Scene> Scene::defaultScene;
size_t Scene::GetId()
{
	return m_IdMaker++;
}

void Scene::Update()
{
	root.UpdateSelfAndChild();
	skybox->Update();
}

void Scene::Save()
{
	XMLDocument document;
	Serialize(document.RootElement());
	ResUtil::SaveXml(&document, xmlPath);
}


void Scene::Serialize(XMLElement* writer)
{
	writer->DeleteChildren();
	auto settings = writer->InsertNewChildElement("settings");
	if (skybox != nullptr)skybox->Serialize(settings);

	auto children = writer->InsertNewChildElement("objects");
	root.SerializeChildren(children);
}

void Scene::Deserialize(XMLElement* reader)
{
	mainCamera = nullptr;
	mainLight = nullptr;
	auto settings = reader->FirstChildElement("settings");
	auto skyboxSetting = settings->FirstChildElement("skybox");
	if (skyboxSetting != nullptr)
	{
		skybox = make_unique<Skybox>();
		skybox->Deserialize(skyboxSetting);
	}
	else skybox = nullptr;

	auto children = reader->FirstChildElement("objects");
	root.DeserializeChildren(children);
}

void Scene::SetCurrent()
{
	Entry::scene.current = this;
}

Object& Scene::GetRoot()
{
	return root;
}

#include "game/scene/Skybox.h"
#include "game/scene/Scene.h"
#include "game/scene/Camera.h"
#include "game/SourceHeader.h"

Skybox::Skybox(): object("skybox")
{
	modelRenderer = object.AddComponent<ModelRenderer>();
}

void Skybox::Update()
{
	Camera* camera = Entry::scene.current->mainCamera;
	object.transform.SetLocalPosition(
		camera->GetTransform()->GetGlobalPosition());
	object.transform.ComputeModelMatrix();
}

void Skybox::Draw(Renderer& renderer) const
{
	renderer.Draw(modelRenderer);
}

void Skybox::Serialize(XMLElement* writer)
{
	const auto skybox = writer->InsertNewChildElement("skybox");
	skybox->SetAttribute("scale",
						StringUtil::WriteVec3(
							modelRenderer->GetObject()->transform.
											GetLocalScale()).c_str());
	skybox->SetAttribute("model", modelRenderer->model->xmlPath.c_str());
	skybox->SetAttribute("shader", modelRenderer->shader->xmlPath.c_str());
}

void Skybox::Deserialize(XMLElement* reader)
{
	modelRenderer->GetObject()->transform.SetLocalScale(
		StringUtil::ParseVec3(reader->Attribute("scale")));
	const auto model = Entry::res.LoadModel(reader->Attribute("model"));
	modelRenderer->model = Entry::res.GetModel(model);
	const auto shader = Entry::res.LoadShader(reader->Attribute("shader"));
	modelRenderer->shader = Entry::res.GetShader(shader);
}

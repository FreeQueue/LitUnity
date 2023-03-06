#include "game/graphics/model/ModelRenderer.h"
#include "game/SourceHeader.h"

void ModelRenderer::OnEnable()
{
	Entry::render.Register(this);
}

void ModelRenderer::OnDisable()
{
	Entry::render.Unregister(this);
}

void ModelRenderer::Serialize(XMLElement* writer)
{
	auto modelRenderer = writer->InsertNewChildElement("modelRenderer");
	modelRenderer->SetAttribute("model", model.get()->xmlPath.c_str());
	modelRenderer->SetAttribute("material", shader.get()->xmlPath.c_str());
}

void ModelRenderer::Deserialize(XMLElement* reader)
{
	string modelPath = reader->Attribute("model");
	string shaderPath = reader->Attribute("material");
	auto shaderId = Entry::res.LoadShader(shaderPath);
	auto modelId = Entry::res.LoadModel(modelPath);
	shader = Entry::res.GetShader(shaderId);
	model = Entry::res.GetModel(modelId);
}

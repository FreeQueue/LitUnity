#include "game/graphics/RenderManager.h"
#include "game/SourceHeader.h"

bool RenderManager::Update()
{
	for (auto& pair : m_ModelRendererMap)
	{
		renderer.Draw(pair.second);
	}
	return true;
}

void RenderManager::Register(ModelRenderer* modelRenderer)
{
	m_ModelRendererMap.emplace(modelRenderer->id, modelRenderer);
}

void RenderManager::Unregister(ModelRenderer* modelRenderer)
{
	if (m_ModelRendererMap.find(modelRenderer->id) != m_ModelRendererMap.end())
	{
		m_ModelRendererMap.erase(modelRenderer->id);
	}
}

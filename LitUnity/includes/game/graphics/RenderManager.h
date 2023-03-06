#pragma once
#include "game/base/ManagerBase.h"
#include "game/graphics/model/ModelRenderer.h"

namespace Game
{
	class RenderManager : public ManagerBase
	{
	public:
		Renderer renderer;

	private:
		std::map<size_t, ModelRenderer*> m_ModelRendererMap;

	public:
		bool Update() override;
		void Register(ModelRenderer* modelRenderer);
		void Unregister(ModelRenderer* modelRenderer);
	};
}

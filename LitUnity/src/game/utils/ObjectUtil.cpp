#include "game/utils/ObjectUtil.h"
#include "game/graphics/model/ModelRenderer.h"
#include "game/graphics/light/Light.h"
#include "game/scene/Camera.h"
#include "game/SourceHeader.h"

Component* ObjectUtil::ParseComponent(XMLElement* element)
{
	const string name = element->Name();
	if(name=="modelRenderer"){
		auto component= new ModelRenderer;
		component->Deserialize(element);
		return component;
	}else if(name=="camera"){
		auto component= new Camera;
		component->Deserialize(element);
		return component;
	}else if(name=="light"){
		auto component= new Light;
		component->Deserialize(element);
		return component;
	}
	return nullptr;
}

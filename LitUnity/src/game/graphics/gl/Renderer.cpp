#include "game/graphics/gl/Renderer.h"
#include "game/graphics/gl/GlHelper.h"
#include "glad/glad.h"
#include "game/base/Object.h"
#include "game/SourceHeader.h"


void Renderer::Clear() const
{
	GLCall(
		glClearColor(background.r, background.g, background.b, background.a));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(ModelRenderer* modelRenderer)
{
	if (modelRenderer->model == nullptr)return;
	if (!modelRenderer->model->bounds->IsOnFrustum(
		frustum, modelRenderer->GetObject()->transform))
		return;

	auto model = modelRenderer->GetObject()->transform.GetModelMatrix();

	if (currentShader == nullptr || modelRenderer->shader->ID != currentShader->
		ID)
		currentShader = modelRenderer->shader.get();
	if (currentShader == nullptr)
		currentShader =
#ifdef _DEBUG
			Shader::debugShader.get();
#else
			Shader::defaultShader.get();
#endif
	currentShader->Bind();
	currentShader->SetMat4("projection", projection);
	currentShader->SetMat4("view", view);
	currentShader->SetMat4("model", model);

	modelRenderer->model->Draw(*this);
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib)
{
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

	// always good practice to set everything back to defaults once configured.
	GLCall(glActiveTexture(GL_TEXTURE0));
}

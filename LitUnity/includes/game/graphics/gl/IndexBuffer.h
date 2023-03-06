#pragma once
namespace Game
{
	class IndexBuffer
	{
	private:
		unsigned int m_RendererID{};
		size_t m_Count; // ¶àÉÙ¸ö indices
	public:
		IndexBuffer(const unsigned int* data, size_t count);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;

		size_t GetCount() const { return m_Count; }
	};
}

#pragma once
#include <tuple>
#include <type_traits>
#include <list>
#include <functional>
namespace Game
{
	class TemplateUtil
	{
	public:
		template <typename Fn, typename Pm>
		static auto Apply(Fn fn, Pm t)
		{
			//获取参数元组的尺寸
			static constexpr auto size = std::tuple_size<Pm>::value;
			//构建访问元组容器中参数的
			return ApplyImpl(fn, t, std::make_index_sequence<size>{});
		}
		template <typename T>
		static void ListRemoveOne(std::list<T>& list,std::function<bool(T&)> condition){
			for(auto iter=list.begin();iter!=list.end();iter++){
				if(condition(*iter)){
					list.erase(iter);
					break;
				}
			}
		}
	private:
		template <typename Fn, typename Pm, size_t ... N>
		static auto ApplyImpl(Fn fn, Pm pa, std::index_sequence<N...>)
		{
			//实现tuple传参回调函数，得对tuple中的参数包进行拆包
			return fn(std::get<N>(pa)...);
		}
	};
}

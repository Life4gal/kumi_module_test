module;

#include <kumi/tuple.hpp>

export module gal.kumi;

export namespace gal
{
	template<typename... Args>
	[[nodiscard]] constexpr auto make_tuple(Args &&...args) -> decltype(auto)
	{
		return kumi::make_tuple(std::forward<Args>(args)...);
	}

	template<typename T, typename Tuple>
	[[nodiscard]] constexpr auto get(Tuple &&tuple) -> decltype(auto)
		requires requires { kumi::get<T>(std::forward<Tuple>(tuple)); }
	{
		return kumi::get<T>(std::forward<Tuple>(tuple));
	}

	template<std::size_t Index, typename Tuple>
	[[nodiscard]] constexpr auto get(Tuple &&tuple) -> decltype(auto)
		requires requires { kumi::get<Index>(std::forward<Tuple>(tuple)); }
	{
		return kumi::get<Index>(std::forward<Tuple>(tuple));
	}

	template<typename Function, typename Tuple, typename... Tuples>
	constexpr auto for_each_index(Function &&function, Tuple &&tuple, Tuples &&...tuples) -> decltype(auto)
		requires requires { kumi::for_each_index(std::forward<Function>(function), std::forward<Tuple>(tuple), std::forward<Tuples>(tuples)...); }
	{
		return kumi::for_each_index(std::forward<Function>(function), std::forward<Tuple>(tuple), std::forward<Tuples>(tuples)...);
	}

	template<typename Tuple>
	[[nodiscard]] constexpr auto transpose(const Tuple &tuple) -> decltype(auto)
		requires requires { kumi::transpose(tuple); }
	{
		return kumi::transpose(tuple);
	}
}// namespace gal

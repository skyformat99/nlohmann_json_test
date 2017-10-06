#pragma once
namespace tmp
{
	template <class T>
	struct Allocator {
		using value_type = T;

		using Traits = std::allocator_traits<Allocator<T>>;

		explicit Allocator() {};

		template<class U> Allocator(const Allocator<U>& other){};

		T* allocate(std::size_t n) { return reinterpret_cast<T*>(new unsigned char[n * sizeof(T)]); };

		void deallocate(T* p, std::size_t n) { delete[] reinterpret_cast<unsigned char*>(p); };

		template<class U, class... Args> void construct(U* p, Args&&... args) { std::allocator<T>().construct(p, std::forward<Args>(args)...); };

		template<class U> void destroy(U* p) { std::allocator<T>().destroy(p); };

		template<class U> struct rebind { using other = Allocator<U>; };
	};

	template<class T, class U> bool operator==(const Allocator<T>& lhs, const Allocator<U>& rhs) { return &lhs.m_allocator_impl == &rhs.m_allocator_impl; }
	template<class T, class U> bool operator!=(const Allocator<T>& lhs, const Allocator<U>& rhs) { return !(lhs == rhs); }

	using string = std::basic_string<char, std::char_traits<char>, Allocator<char>>;

	using ifstream = std::ifstream;

	template<class T>
	using list = std::list<T, Allocator<T>>;

	using ifstream = std::basic_ifstream<char, std::char_traits<char> >;

	using stringstream = std::basic_stringstream<char, std::char_traits<char>, Allocator<char>>;

	using istringstream = std::basic_istringstream<char, std::char_traits<char>, Allocator<char>>;

	template<class _Ty1, class _Ty2>
	using pair = std::pair<_Ty1, _Ty2>;

	template<class _Kty, class _Ty, class _Pr = std::less<_Kty>, class _Alloc = Allocator<pair<const _Kty, _Ty> > >
	using map = std::map<_Kty, _Ty, _Pr, _Alloc>;

	template<class _Ty, class _Alloc = Allocator<_Ty> >
	using vector = std::vector<_Ty, _Alloc>;

	using json = nlohmann::basic_json<map, vector, string, bool, int64_t, uint64_t, double, Allocator, nlohmann::adl_serializer>;
}

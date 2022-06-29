#include <cstddef>
#include <cstdlib>

template <class T>
class Allocator {
	static std::size_t l;
	public:
	static inline void allocate(const std::size_t);
	static T *data;
	static inline void construct(T);
	static T test(unsigned);
};

template <class T>
Allocator<T>::data{ nullptr };

template <class T>
void Allocator<T>::allocate(const std::size_t size)
{
	data = (T*) calloc(size, sizeof(T));
}

template <class T>
void Allocator<T>::construct(T val)
{
	data[l++] = val;
}

#include <iostream>

template <class T>
T Allocator<T>::test(unsigned i)
{
	return data[i];
}

template <class T>
std::size_t Allocator<T>::l{ 0 };

int main()
{
	Allocator<int>::allocate(5);
	Allocator<int>::construct(69);
	std::cout << Allocator<int>::test(0);

	return 0;
}

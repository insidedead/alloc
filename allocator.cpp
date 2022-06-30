#include <cstddef>
#include <cstdlib>
#include <iostream>

template <typename T>
class Allocator {
	static T* data;
	static unsigned track;
	public:
	static T* allocate(std::size_t);
	static inline void construct(T);
	static inline void print(std::size_t);
};

template <typename T>
T* Allocator<T>::data { nullptr };

template <typename T>
unsigned Allocator<T>::track { 0 };

template <typename T>
T* Allocator<T>::allocate(std::size_t size)
{
	data = (T*) calloc(size, sizeof(T));

	return data;
}

template <typename T>
void Allocator<T>::construct(T v)
{
	data[track++] = v;
}

template <typename T>
void Allocator<T>::print(std::size_t index)
{
	std::cout << data[index];
}

int main()
{
	int *i = Allocator<int>::allocate(5);
	Allocator<int>::construct(69);
	Allocator<int>::print(0);
}

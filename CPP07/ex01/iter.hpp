#ifndef ITER_HPP
#define ITER_HPP

template<typename T, typename Func>
void iter(T &a, unsigned int length, Func f)
{
	for (unsigned int i = 0; i < length; ++i)
		f(a[i]);
}

#endif
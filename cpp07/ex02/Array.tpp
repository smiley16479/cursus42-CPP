#include <array>
#include <iostream>

template<typename T = int>
class Array
{
private:
	unsigned int _n;
	T *_array;
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array<T>& copy);
	unsigned int size(void) const;
	void show(void) const;
	// Array<T> operator=(const Array<T>& src);
	T operator=(const T& src);
	T operator[](unsigned int idx);
	~Array();
};

template< typename T >
Array<T>::Array() : _n( 0 )
{
	int * _array = new T[_n]();
}

template< typename T >
Array<T>::Array(unsigned int n) : _n( n )
{
	T * _array = new T[_n]();
}

template< typename T >
Array<T>::Array(const Array<T>& src)
{
	*this = src;
}

template< typename T >
Array<T>::~Array()
{
	delete [] _array;
}

template< typename T >
unsigned int Array<T>::size(void) const
{
	return _n;
}

template< typename T>
void Array<T>::show(void) const
{
	for (size_t i = 0; i < _n; i++)
		std::cout << _array[i] << std::endl;	
}

// template< typename T>
// Array<T> Array<T>::operator=(const Array<T>& src)
// {
// 	if (this != &src)
// 	{
// 		delete [] _array;
// 		T * _array = new T[src._n];
// 		for (size_t i = 0; i < src._n; i++)
// 			_array[i] = src._array[i];
// 	}
// 	return ;
// }

template< typename T>
T Array<T>::operator=(const T& src)
{
	if (this != &src)
		return (*this) = src;
	return ;
}

template< typename T>
T Array<T>::operator[](unsigned int n)
{
	if (n > _n)
		throw std::out_of_range ("out of range accesion");
	else
		return _array[n];
}

/////////////////////////////////////////////////
/*
#include <iostream>   
  
template<typename T> class Exemple; 
  
template<typename T> 
std::ostream& operator<<(std::ostream&, Exemple<T> const&); 
  
template <typename T>   
class Exemple   
{   
public :   
  
    Exemple(const T& Val = T());   
  
    template <typename U>   
    Exemple(const Exemple<U>& Copy);   
  
    const T& Get() const;   
  
    // Spécialisation template <> selon le type T 
    friend std::ostream& operator << <>(std::ostream& Stream, const Exemple<T>& Ex);   
  
private :   
  
    T Value;   
};   
  
template <typename T>   
Exemple<T>::Exemple(const T& Val) 
  : Value(Val)   
{   
  
}   
  
template <typename T>   
template <typename U>   
Exemple<T>::Exemple(const Exemple<U>& Copy) 
  : Value(static_cast<T>(Copy.Get()))   
{   
    // Attention, ceci n'est pas le constructeur par copie !   
}   
  
template <typename T>   
const T& Exemple<T>::Get() const   
{   
    return Value;   
}   
  
template <typename T>   
std::ostream& operator <<(std::ostream& Stream, const Exemple<T>& Ex)   
{   
    return Stream << Ex.Value;   
}   
  
int main()   
{   
    Exemple<int> A(3);   
    Exemple<float> B(A);   
  
    std::cout << A << std::endl;   
    std::cout << B << std::endl;   
  
    return 0;   
}
*/
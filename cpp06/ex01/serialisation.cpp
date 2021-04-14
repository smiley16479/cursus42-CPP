#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

struct Data { std::string s1; int n; std::string s2; };

void * serialize(void)
{
	unsigned char *ptr = new unsigned char[20]; 
	for (size_t i = 0; i < (2 * 8 + 4) ; i++)
	{
		if (8 > i || i > 11) {
			ptr[i] = (rand() % (127 - ' ') + 32);
			// std::cout << "char " << (i + 1) % 12 << ": " << ptr[i] << std::endl;
		}
		else {
			ptr[i] = (rand());
			// std::cout << "octet du int " << (i - 7)  << ": " << static_cast<u_short>(ptr[i]) << std::endl;
			// if (i == 11) {
			// 	std::cout << *reinterpret_cast<int*>(&ptr[i - 3]) << std::endl;
			// 	std::cout << *((int*)&ptr[i - 3]) << std::endl;
			// }
		}
	}
	return reinterpret_cast<void*>(ptr);
}

Data * deserialize(void * raw)
{
	Data *ptr = new Data;
	char *c_ptr = reinterpret_cast<char*>(raw);
	int	 *i_ptr = reinterpret_cast<int*>(raw);
	for (size_t i = 0; i < 20 ; i++)
	{
		if (8 > i || i > 11) {
			// std::cout << "deserialize i: " << i << " et c : " << c_ptr[i] << std::endl;
			if ( 8 > i )
				ptr->s1 += c_ptr[i];
			else
				ptr->s2 += c_ptr[i];
		}
		else if (i == 8) {
			ptr->n = i_ptr[2];
			// std::cout << "deserialize i: " << i << " et i : " << i_ptr[2] << std::endl;
		}
	}
	return ptr;
}


int main()
{
	srand (time(NULL));
	void *ptr  = serialize();
	Data *data = deserialize(ptr);

	std::cout << "data.s1 : " << data->s1 << std::endl;
	std::cout << "data.n  : " << data->n  << std::endl;
	std::cout << "data.s2 : " << data->s2 << std::endl;

	// int j = 0;
	// for (size_t i = 2147483648; i > 0; i /= 2){
	// 	if (!(j++ % 4)) std::cout << " "; 
	// 	-10 & i ? std::cout << "1" : std::cout << "0";
	// }
	// std::cout << std::endl;
	delete [] static_cast<unsigned char*>(ptr);
	delete  data;
	return 0;
}
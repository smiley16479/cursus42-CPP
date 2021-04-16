#include "Array.tpp"

int main()
{
	Array<int> arrayI(5);
	Array<int> arrayI2(5);
	Array<float> arrayf(3);
	arrayI[0] = 0.5;
	arrayI[1] = 1;
	arrayI[2] = 2;
	arrayI2 = arrayI;
	arrayf[2] = 2.222;
	try
	{
		arrayI.show();
		std::cout << arrayf[2] << std::endl;
		std::cout << arrayf.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

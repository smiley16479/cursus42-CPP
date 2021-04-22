#include "span.hpp"

int main(/* int argc, char const *argv[] */)
{
	Span array(1000000); // <-- remettre une longeur adéquate pour ne pas lever l'exception
	Span array1(array);
	try
	{
		array.generate(100000);
		array.addNumber(5);
		// array.display();
		array.showElem(100000);
		std::cout << array.getIdx() << "\n";
		// array.addNumber(10);
		// array.addNumber(7);
		// array.display(); // commenté pour évité l'isoc++11 av la norme
		std::cout << array.shortestSpan() << std::endl;
		std::cout << array.longestSpan() << std::endl;
	}
	catch(const std::string& e)
	{
		std::cerr << e << '\n';
	}
	return 0;
}

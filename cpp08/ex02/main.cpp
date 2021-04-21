#include "MutantStack.tpp"
#include <list>
// #include "MutantStack.hpp"
// #include "MutantStack.cpp"

int main()
{
	std::stack<int>  nstack;
	MutantStack<int>    mstack;
	std::list<int>    list;

	// list.
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	std::cout << mstack << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.generate(5);
	std::cout << mstack;
	std::cout << "size : " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while(it != ite){std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

/* 
int main()
{
	MutantStack<float>    mstack;
	// mstack.
	mstack.push(5.5);
	mstack.push(17.17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3.3);
	mstack.push(5.5);
	mstack.push(737.737);
	//[...]mstack.push(0);
	MutantStack<float>::iterator it = mstack.begin();
	MutantStack<float>::iterator ite = mstack.end();
	++it;
	--it;
	while(it != ite){std::cout << *it << std::endl;
	++it;
	}
	std::stack<float> s(mstack);
	return 0;
} */

/* int main()
{
	std::list<int>    mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while(it != ite){std::cout << *it << std::endl;
	++it;
	}
	std::list<int> s(mstack);
	return 0;
} */


/*int main()
{
	std::stack<int>    mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.top() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]mstack.push(0);
	// std::stack<int>::iterator it = mstack.begin();
	// std::stack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while(it != ite){std::cout << *it << std::endl;
	// ++it;
	// }
	std::stack<int> s(mstack);
	return 0;
} */
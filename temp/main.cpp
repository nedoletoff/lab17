#include "double_list.hpp"

int main()
{
	DoubleList<int> lst_int;
	
	lst_int.push_back(1);
	lst_int.push_back(2);
	lst_int.push_front(3);
	lst_int.print();
	lst_int.push_back(1);
	lst_int.push_back(1);
	std::cout << "size - " << lst_int.size() << std::endl;
	try 
		lst_int.at();
	catch(str* i)
		std::cout << i << std::endl;

	lst_int.print();
	lst_int.find_and_erase(1);
	lst_int.print();
	
	lst_int.pop_back();
	lst_int.print();
	
	return 0;
}

#include "double_list.hpp"

int main()
{

	DoubleList<double> lst_int;

	lst_int.push_back(2);	
	lst_int.push_back(1);

	
	lst_int.push_front(3);
	lst_int.push_front(1);
	lst_int.print();
	lst_int.push_back(1);
	lst_int.push_back(2);
	lst_int.push_back(1);
	std::cout << "size - " << lst_int.get_size() << std::endl;
	try 
	{
		lst_int.at();
	}
	catch(int i)
	{
		std::cout << i << std::endl;
		std::cout << "Caught an exception" << std::endl;
	}

	lst_int.print();

	std::cout << "find_and_erase(1)" << std::endl;
	lst_int.find_and_erase(1);
	lst_int.print();

	DoubleList<Point> point_lst;
	struct Point e;
	e.x = 1; e.y = 2; e.z = 3;

	point_lst.push_back(e);
	e.x = 11;
	std::cout << e.x << " " << e.y << " " << e.z << std::endl;
	e = point_lst.pop_back();
	std::cout << e.x << " " << e.y << " " << e.z << std::endl;

	try 
	{
		point_lst.pop_back();
	}
	catch(double r)
	{
		std::cout << r << std::endl;
		std::cout << "list is empty" << std::endl;
	}
	return 0;
}

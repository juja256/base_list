#include "base_list.h"
#include <iostream>
#include <cstring>

int main() {
	char** s = new char*[4];
	s[0] = strdup("justin");
	s[1]=strdup("bieber");
	s[2]=strdup("is");
	s[3]=strdup("faggot");
	base_list a = init_base_list_by_array(s, 4);
	try {
		erase_element(a, 3);
		insert_after(a, strdup("alive"), 2);
	}
	catch(std::logic_error& e) {
		std::cout << e.what();
	}

	list_dump(a, std::cout);
	std::cout << "\n";

	base_list b = init_base_list_by_file("text.txt");
	list_dump(b, std::cout);
	std::cout << "\n";

	clear(b);
	list_dump(b, std::cout);
	
	#ifdef _WIN32
		system("PAUSE");
	#endif

	return 0;
}

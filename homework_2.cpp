#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <unistd.h>
#include <cerrno>
#include <sstream>
#include <cstring>

int main() {
	int count;
	std::cout << "Files count: ";
	std::cin >> count;
	
	if (count < 0) { return -1; }

	std::cout << "Text in files: ";
	std::string start_text;
	std::cin >> start_text;

    std::cout << "Name of files: "
    std::string file_name;
	std::cin >> file_name;

	for (int i = 1; i < count+1; ++i) {
		std::string file = file_name;
		std::string new_text = start_text;

		file+=(std::to_string(i));
		file+=(".txt");
		new_text+=(" ");
		new_text+=(std::to_string(i));
		
		int fd = open(file.c_str(), O_WRONLY | O_CREAT, S_IRWXU);
		
		if(fd < 0) { return errno; }
	
		write(fd, new_text.c_str(), new_text.size());
		close(fd);
	}
}

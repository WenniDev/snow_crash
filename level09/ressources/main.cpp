#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("token");
    std::string line;
	std::string res;

    if (file.is_open()) {
        while (std::getline(file, line)) {
			int i = 0;
			while (line[i]) {
				res += line[i] - i;
				i++;
			}
			std::cout << res << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
    }

    return 0;
}
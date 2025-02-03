#include <chrono>
#include <stdexcept>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 3 || argc == 1) {
        std::cerr << "Usage: " << argv[0] << " <command>" << " <s | ms | ns>"<< std::endl;
        return 1;
    }

    try {
        auto start = std::chrono::high_resolution_clock::now();
        system(argv[1]);
        auto end = std::chrono::high_resolution_clock::now();

        std::string time_unit = argv[2];
        if (time_unit == "s") {
            std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << " s" << std::endl;
        } else if (time_unit == "ms") {
            std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
        }
        else if (time_unit == "ns") {
            std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;
        }
    } catch (std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    

    return 0;
}
#include <iostream>
#include <memory>
#include <cstdio>   // For file handling (C-style)
#include <cstdlib>  // For malloc/free
#include <unistd.h> // for write, read, close
#include <fcntl.h>  // for open flags

// Basic usage: custom deleter function for simple types
void customIntDeleter(int* ptr) {
    std::cout << "Custom deleter for int called. Deleting pointer: " << ptr << std::endl;
    delete ptr;
}

// Intermediate usage: custom deleter for arrays
void customArrayDeleter(int* ptr) {
    std::cout << "Custom deleter for array called. Deleting array pointer: " << ptr << std::endl;
    delete[] ptr;
}

// Advanced usage: Custom deleter for C-allocated memory (free)
void customFreeDeleter(void* ptr) {
    std::cout << "Custom deleter using free called. Freeing pointer: " << ptr << std::endl;
    free(ptr);
}

// Advanced usage: Custom deleter for file resources (fclose)
void customFileDeleter(FILE* file) {
    std::cout << "Custom deleter for FILE* called. Closing file.\n";
    fclose(file);
}

// Custom deleter for file descriptors
void customFileDeleter_fd(int* fd) {
    if (fd && *fd != -1) {
        close(*fd);  // Close the file descriptor
        std::cout << "File closed." << std::endl;
    }
}

size_t mystrlen(const char* str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    // 1. Basic usage: Unique pointer with a custom deleter for an int
    {
        std::unique_ptr<int, decltype(&customIntDeleter)> intPtr(new int(42), customIntDeleter);
        std::cout << "intPtr value: " << *intPtr << std::endl;
        // Custom deleter will be called when intPtr goes out of scope
    }

    std::cout << "----------------------------------\n";

    // 2. Intermediate usage: Unique pointer with a custom deleter for an array
    {
        std::unique_ptr<int[], decltype(&customArrayDeleter)> arrayPtr(new int[5]{1, 2, 3, 4, 5}, customArrayDeleter);
        std::cout << "arrayPtr values: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << arrayPtr[i] << " ";
        }
        std::cout << std::endl;
        // Custom deleter will be called when arrayPtr goes out of scope
    }

    std::cout << "----------------------------------\n";

    // 3. Advanced usage: Unique pointer managing C-allocated memory (using malloc/free)
    {
        std::unique_ptr<void, decltype(&customFreeDeleter)> cMemPtr(malloc(100), customFreeDeleter);
        if (cMemPtr) {
            std::cout << "Allocated 100 bytes using malloc and managing it with a custom deleter." << std::endl;
            // Custom deleter will call free() when cMemPtr goes out of scope
        }
    }

    std::cout << "----------------------------------\n";

    // 4. Advanced usage: Unique pointer managing FILE* resource
    {
        std::unique_ptr<FILE, decltype(&customFileDeleter)> filePtr(fopen("example.txt", "w"), customFileDeleter);
        if (filePtr) {
            std::cout << "File opened and managed with a custom deleter." << std::endl;
            fprintf(filePtr.get(), "This is a test line written to the file.\n");
            // Custom deleter will call fclose() when filePtr goes out of scope
        }
    }

    //Unique pointer managing file descriptors
    {
        // Open the file with read and write permissions, create it if it doesn't exist
        int fd = open("example2.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
        std::unique_ptr<int, decltype(&customFileDeleter_fd)> filePtr(&fd, customFileDeleter_fd);
        if (filePtr && fd != -1) {
            std::cout << "File Descriptor opened and managed with a custom deleter." << std::endl;
            const char* content = "This is a test line written to the file.\n";
            ssize_t bytes_written = write(fd, content, mystrlen(content));
            if (bytes_written == -1) {
                std::cerr << "Error writing to file." << std::endl;
            }
            if (lseek(fd, 0, SEEK_SET) == -1) {
               std::cerr << "Error seeking to the beginning of the file." << std::endl;
               return 1;
            }

            // Reading and printing the file content using read()
            char buffer[256];
            ssize_t bytes_read;
            while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
                buffer[bytes_read] = '\0';  // Null-terminate the buffer to treat it as a string
                std::cout << buffer;
            }

            if (bytes_read == -1) {
                std::cerr << "Error reading from file." << std::endl;
            }
            // Custom deleter will call close() when filePtr goes out of scope
        } else {
            std::cerr << "Error opening file." << std::endl;
        }
    }

    std::cout << "----------------------------------\n";

    // 5. Bonus: Using a lambda function as a custom deleter for a dynamically allocated double
    {
        auto lambdaDeleter = [](double* ptr) {
            std::cout << "Lambda custom deleter called. Deleting double pointer: " << ptr << std::endl;
            delete ptr;
        };
        std::unique_ptr<double, decltype(lambdaDeleter)> doublePtr(new double(3.1415), lambdaDeleter);
        std::cout << "doublePtr value: " << *doublePtr << std::endl;
        // Lambda deleter will be called when doublePtr goes out of scope
    }

    return 0;
}

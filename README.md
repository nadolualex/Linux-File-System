# Linux File System - Binary Search Trees

## Overview

This project implements a basic Linux File System using Binary Search Trees. The file system consists of two main components: files and directories. Each file node contains information such as the file name, left and right connections, and the parent directory. Similarly, each directory node contains details like the directory name, left and right connections, parent directory, subdirectories, and files.

## Implementation

### 1. `root_alloc` function
- Initializes the root and allocates memory for the directory.

### 2. `create_file` function
- Initializes a file node within a directory.

### 3. `create_directory` function
- Initializes a directory node within a directory.

### 4. `duplicate_file_check` and `duplicate_dir_check` functions
- Check if a file or directory already exists in the tree.

### 5. `print_file` and `print_dir` functions
- Traverse the tree in an SRD (in-order) manner to print file and directory names.

### 6. `ls` function
- Lists the contents of the current directory.

### 7. `touch` function
- Creates a file within the current directory.

### 8. `mkdir` function
- Creates a directory within the current directory.

### 9. `rmdir` function
- Removes a directory within the current directory.

### 10. `pwd_func` function
- Prints the current working directory.

### 11. `cd` function
- Changes the current working directory.

### 12. `rm` function
- Removes a file within the current directory.

### 13. `main` function
- Initializes the root directory and reads user instructions to perform file system operations.

## Usage

1. Clone the repository.
2. Compile the program.
3. Run the executable.
4. Enter commands such as `touch`, `mkdir`, `ls`, `cd`, `pwd`, `rm`, `rmdir`, and `quit` to interact with the simulated file system.

Feel free to explore and contribute to the project! If you encounter any issues or have suggestions for improvements, please open an issue or pull request.

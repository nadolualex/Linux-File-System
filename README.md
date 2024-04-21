# Linux File System - Binary Search Trees

## Overview

This project implements a basic Linux File System using Binary Search Trees. The file system utilizes Binary Search Trees to efficiently store and manage directories and files. Each directory and file is organized within the tree structure, enabling operations such as printing directory contents in a lexicographic order and searching for files using the `find` command.

## Implementation

### 1. `root_alloc` function
- Initializes the root directory and allocates memory for it.

### 2. `create_file` function
- Creates a file node within a directory.

### 3. `create_directory` function
- Creates a directory node within a directory.

### 4. `duplicate_file_check` and `duplicate_dir_check` functions
- Check if a file or directory already exists in the tree.

### 5. `print_file` and `print_dir` functions
- Traverse the tree in an SRD (in-order) manner to print file and directory names in lexicographic order.

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

### 13. `find` function
- Searches for a file within the file system.

### 14. `main` function
- Initializes the root directory and reads user instructions to perform file system operations.

## Complexity

The complexity of various operations in the file system implemented using Binary Search Trees is as follows:

- Insertion of a file or directory: O(log n), where n is the number of files or directories in the tree. This is because Binary Search Trees provide efficient insertion by maintaining the tree structure.

- Searching for a file or directory using `find`: O(log n) on average. Similar to insertion, searching in a Binary Search Tree is efficient due to its structure.

- Listing directory contents (`ls`): O(n), where n is the number of files or directories in the current directory. This is because listing contents involves traversing all elements in the directory.

- Changing directory (`cd`): O(log n), where n is the number of directories in the file system.

- Removing a file or directory: O(log n), where n is the number of files or directories in the tree. Removal involves finding the node to delete, which is efficient in a Binary Search Tree.

#Linux File System
=========BINARY-SEARCH-TREES========

1) Structures
For the structure part, I was inspired by the statement of the homework,
which seemed to have begged me to use this implementation of 2 structures: 
one for the file and one for the directory. For the file I have his name,
root, the file on the left or on the right connected. For the
directory I have the directory name, subdirectories, root, files and 
directories left or right connected.

2) Implementation
This part does not need much explication, as I left comments along the code.
aloca_root -> allocates memory for root directory

create_file and create_directory -> creates the node for file and directory
and allocates memory

duplicate_file_check and duplicate_dir_check -> checks if the file/directory
which has to join the three is already in three

print_file and print_dir -> SRD crossing - searches for the name of file/create_directory
and prints them

touch and mkdir -> the functions , the kernel of the entire homework. I implemented
an iterative buggy function for touch at first with ~60 lines of code but
didn't work for mkdir too so i spent some time debugging. Then I deleted
everything and started from the bottom with a recursive function which
turned out to be much more effective, easier and shorter. I checked the duplicity
of files and directories alongside touch function but it didn't work well
when i tried to do the same thing for mkdir, so I moved the condition into main
because i was in a time crisis

main function reunites them all and produces the homework.

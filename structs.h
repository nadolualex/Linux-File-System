typedef struct directory_name 
{
    char *nume; 
    struct directory_name *directories;
    struct directory_name *parent;
    struct directory_name *st,*dr;
    struct sfile  *files; 
} directory, *directories;

typedef struct sfile
{
    char* nume;
    struct sfile* st, *dr;
    struct directory* parent;
} file, *files;
/* Nadolu Robert-Alexandru 314CB */

#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARMAX 50

// function which initializes the root and allocates memory


directory *root_alloc (char *dir_name) 
{
    directory *dir = calloc(1, sizeof(directory));
    dir->nume = calloc(1, CHARMAX);
    strcpy(dir->nume, dir_name);
    return dir;
}



// function for initializing the node file
file* create_file (directories d, char* name_file) 
{   
    files aux = (files)malloc(sizeof(file));
	if (!aux) return NULL;
    aux->nume = strdup(name_file);
	aux->st = aux->dr = NULL;
    aux->parent = d;

	return aux;
}

// function for initializing the directory file
directories create_directory (directories d, char* name_dir) 
{
    directories aux = calloc(1, sizeof(directory));
	if (!aux) 
        return NULL;
    aux->nume = strdup(name_dir);
	aux->parent = d;

	return aux;
}

//function for checking if we have the file in tree
int duplicate_file_check (file* fisier, char* nume) 
{
    if (fisier == NULL)
        return 0;
    else 
        if(!strcmp(nume, fisier->nume))
            return 1;
        else 
            if (duplicate_file_check(fisier->st,nume))
                return 1;
    return duplicate_file_check(fisier->dr, nume);
}

int duplicate_dir_check (directory* dir, char* nume) 
{
    if (dir == NULL)
        return 0;
    else
        if(!strcmp(nume, dir->nume))
            return 1;
        else
            if (duplicate_dir_check(dir->st,nume))
                return 1;
    return duplicate_dir_check(dir->dr, nume);
}

//prints file name
void print_file (file *file)
{
	if(!file) 
        return;
    //left, root, right (SRD)
	print_file (file->st);
    printf("%s ", file->nume);
	print_file(file->dr);
}

//prints directory name
void print_dir (directory *dir)
{
	if(!dir) 
        return;
    //SRD
	print_dir (dir->st);
    printf ("%s ", dir->nume);
	print_dir (dir->dr);
}

void ls (directories d) {
    print_dir(d->directories);
    print_file(d->files);
    printf("\n");
}

//function in which we call create_file
files touch(directories parinte, char *name_file, files fisier) 
{
    //checking if the file is already existent
    if(duplicate_file_check(fisier, name_file)) {
        printf("File %s already exists!\n", name_file);
        return fisier;
    }
    if(duplicate_dir_check(parinte->directories, name_file)) {
            printf("Directory %s already exists!\n",name_file);
            return fisier;
    }
    //when we reach an unpopulated branch we create the file
    if(!fisier){
        return create_file(parinte, name_file);
    }
    else {
        if(strcmp(fisier->nume, name_file) < 0) {
            fisier->dr = touch(parinte, name_file, fisier->dr);
            return fisier;
        }
        else if(strcmp(fisier->nume, name_file) > 0) {
            fisier->st = touch(parinte, name_file, fisier->st);
            return fisier;
        }
    }
        
    return parinte->files;
}

//function in which we call create_directory
directories mkdir(directory* parinte, char* a, directories dir) 
{
    if (duplicate_dir_check(dir, a) == 1) {
		printf("Directory %s already exists!\n", a);
		return dir;
	}
    if (duplicate_file_check(parinte->files, a) == 1) {
        printf("File %s already exists!\n", a);
		return dir;
    }
    else {
        if(!dir) {
            return create_directory(parinte, a);
        }
        else {
            if(strcmp(dir->nume, a) < 0) {
                dir->dr = mkdir(parinte, a, dir->dr);
                return dir;
            }
            else if(strcmp(dir->nume,a) > 0) {
                dir->st = mkdir(parinte, a, dir->st);
                return dir;
            }
        }
    } 
    return parinte->directories;
}


directories rmdir(directories parinte, char *a) {
    if (duplicate_dir_check(parinte->directories, a) != 1) {
        printf("Directory %s doesn't exist!\n", a);
        return parinte->directories;
    } // if the name doesn't exist

    if (parinte->directories == NULL) return parinte->directories;
    
    directories curent = parinte->directories, ant = NULL;
    int st_dr = 0; // direction

    while (curent) {
        if (!strcmp(curent->nume, a))
            break;
            //deleting the directory

        if (strcmp(curent->nume, a) > 0) {
            ant = curent;
            curent = curent->st;
            st_dr = 1;
        }
        else if (strcmp(curent->nume, a) < 0) {
            ant = curent;
            curent = curent->dr; 
            st_dr = 2;
        }
    }

    directories inloc = NULL, ant_in = NULL;
    if (curent->st != NULL) {
        inloc = curent->st, ant_in = curent;
        while (inloc->dr) {
            ant_in = inloc;
            inloc = inloc->dr;
        }
        if (ant_in == curent) { // only for one left node
            inloc->dr = curent->dr;
        } else {
            ant_in->dr = inloc->st; 
            inloc->st = curent->st;
            inloc->dr = curent->dr;
            
        }
    }
    else if (curent->dr != NULL) {
        //check if there are little names
        inloc = curent->dr;
        ant_in = curent;
        // curent->st already NULL
    }

    if (ant == NULL) { // when current is root
        parinte->directories = inloc;
    } else {
        if (st_dr == 1)
            ant->st = inloc;
        else if (st_dr == 2)
            ant->dr = inloc;
    }

    curent->st = curent->dr = NULL; 
    return parinte->directories;
}

void pwd_func (directory *dir){
    if(dir ->parent)
        pwd_func(dir->parent);
    printf("/%s", dir->nume);
    return;
}



directories cd(directories parinte, char *a) {
    if (!strcmp(a, "..")) {
        if (parinte->parent)
            parinte = parinte->parent;
        return parinte;
    } //check if it isn't already in root
    if (duplicate_dir_check(parinte->directories, a) != 1) {
        printf("Directory not found!\n");
        return parinte;
        // if the directory doesn't exist
    } else {
        directories newdir = parinte->directories;
        while (newdir) {
            if (!strcmp(newdir->nume, a)) {
                parinte = newdir;
                return parinte;
            }
            if (strcmp(newdir->nume, a) > 0)
                newdir = newdir->st;
            else
                newdir = newdir->dr;
        }
        return parinte;
    }
}


void rm(directories parinte, char *a) {
    if (duplicate_file_check(parinte->files, a) != 1) {
        printf("File %s doesn't exist!\n", a);
        return;
    } // if the name doesn't exist
    
    files curent = parinte->files, ant = NULL;
    int st_dr = 0; // direction

    while (curent) {
        if (!strcmp(curent->nume, a)) {
            break;
            //deleting the file
        }
        if (strcmp(curent->nume, a) > 0) {
            ant = curent;
            curent = curent->st;
            st_dr = 1;
        }
        else
        if (strcmp(curent->nume, a) < 0) {
            ant = curent;
            curent = curent->dr;
            st_dr = 2;
        }
    }

    files inloc = NULL, ant_in = NULL;
    if (curent->st != NULL) {
        inloc = curent->st, ant_in = curent;
        while (inloc->dr) {
            ant_in = inloc;
            inloc = inloc->dr;
        }
        if (ant_in == curent) { // only for one left node
            inloc->dr = curent->dr;
        } else {
            ant_in->dr = inloc->st;
            inloc->st = curent->st;
            inloc->dr = curent->dr;
        }
    }
    else if (curent->dr != NULL) {
        //check if there are little names
        inloc = curent->dr;
        ant_in = curent;
        // curent->st already NULL
    }

    if (ant == NULL) { // when current is root
        parinte->files = inloc;
    } else {
        if (st_dr == 1)
            ant->st = inloc;
        else if (st_dr == 2)
            ant->dr = inloc;
    }

    free(curent->nume);
    free(curent);
}

int main() 
{
    directories root = (directories)malloc(sizeof(directory));
    directories pwd = root;

    root->parent = NULL;
    const char *s = "root";
    root->nume = strdup(s);
    root->directories = NULL;
    root->files = NULL;
    root->dr = NULL;
    root->st = NULL;
    char *instr = calloc (1,CHARMAX);
    directory ** alldirectories = malloc(500);
    int nr = 0;
    alldirectories[nr] = root;
    //reads the instruction and executes the needed tasks
    while(scanf("%s", instr)) 
    {
        if(strcmp(instr, "touch") == 0) 
        {
            char *nume_fisier= calloc(1,CHARMAX);
            scanf("%s", nume_fisier);
            //checks for duplicates
            pwd->files = touch(pwd,nume_fisier,pwd->files);
            free(nume_fisier);
        } else 
            if(strcmp(instr, "mkdir") == 0) 
            {
                char *nume_director = calloc(1,CHARMAX);
                scanf("%s", nume_director);
                //checks for duplicates
                if(duplicate_file_check(root->files, nume_director)) 
                    printf("File %s already exists!\n", nume_director);
                else    
                    if(!duplicate_file_check(root->files, nume_director)) {    
                        pwd->directories = mkdir(pwd, nume_director, pwd->directories);
                        free(nume_director);
                    }
           
        } else 
            if(strcmp(instr,"ls") == 0) 
            {
                ls(pwd);
            } else 
                if (!strcmp(instr, "rm")) {
                    char *fis = malloc(45);
                    scanf("%s", fis);
                    rm(pwd, fis);
                    free(fis);
                }
                if (!strcmp(instr, "rmdir")) {
                    char *dir = malloc(45);
                    scanf("%s", dir);
                    rmdir(pwd, dir);
                    free(dir);
                }
                        else
                            if(!strcmp(instr, "quit"))  break;
                            else
                                if(strcmp(instr,"pwd") == 0){
                                    pwd_func(root);
                                    printf("\n");
                                }
                                else
                                    if(strcmp(instr, "cd") == 0) {
                                        char *dir = malloc(45);
                                        scanf("%s", dir);
                                        pwd = cd(pwd, dir);
                                        free(dir);
                                    }
                                
    }
   return 0;
}
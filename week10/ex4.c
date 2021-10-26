#include<stdio.h>
#include<dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int find_inode (unsigned long i_node, char* file_name)
{
    DIR *temp_dr = opendir("./tmp/");
    struct dirent* de;
	int count = 0;

	char **s = malloc(10*sizeof(char*));
    
	while ((de = readdir(temp_dr)) != NULL){
		if (de->d_ino==i_node){
			s[count] = de->d_name;
			count++;
		}
	}  
    closedir(temp_dr); 

    if (count > 1) {
    	printf("%s - ", file_name);
    	for (int i = 0; i < count-1; i++) {
    		printf("%s, ", s[i]);
    	}
    	printf("%s\n", s[count-1]);
    }
}

int main(){

    DIR *dr = opendir("./tmp/"); 
    
    struct dirent* de;

    while ((de = readdir(dr)) != NULL){ 
        find_inode(de->d_ino, de->d_name);
	}  
    closedir(dr);     	

	return 0;
}
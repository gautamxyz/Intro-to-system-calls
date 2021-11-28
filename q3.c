#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
int check_dir(char path[])
{
    struct stat stats;
    stat(path, &stats);
    if (S_ISDIR(stats.st_mode))
        return 1;
    return 0;
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        write(1, "Error:Incorrect number of arguments\n", 37);
        _exit(0);
    }
    char path[] = "./Assignment";
    int check = check_dir(path); // check if Assignment directory is created. Stop execution if it is not
    
    if (check == 0)
    {
        write(1, "Directory is created: No\n", 26);
        _exit(0);
    }
    else if (check == 1)
    {
        write(1, "Directory is created: Yes\n", 27);
    }
    char in[300];
    int pos = 0; // check for last '/' in file path
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] == '/')
            pos = i + 1;
    }
   
    for (int i = pos; i < strlen(argv[1]); i++)
    {
        in[i - pos] = argv[1][i];
    }
    char filename[100] = "./Assignment/1_";
    strcat(filename, in); // first output file to look out for

    struct stat fs;
    int r;
    
    r = stat(filename, &fs);
    if (r == -1) // file doesn't exist
    {
        
        perror(filename);
        
        goto L1; // check for the other file
    }
    // one by one check each type of permission for user, group and others
    if (fs.st_mode & S_IRUSR)
        write(1,"User has read permission on output_file_1: Yes\n",48);
    else if (!(fs.st_mode & S_IRUSR))
    {
        write(1,"User has read permission on output_file_1: No\n",47);
    }
    
    if (fs.st_mode & S_IWUSR)
        write(1,"User has write permission on output_file_1: Yes\n",49);
    else if (!(fs.st_mode & S_IWUSR))
        write(1,"User has write permission on output_file_1: No\n",48);
    
    if(fs.st_mode & S_IXUSR)
        write(1,"User has execute permission on output_file_1: Yes\n",51);
    else if(!(fs.st_mode & S_IXUSR))
        write(1,"User has execute permission on output_file_1: No\n",50);
    
    write(1,"\n",2);

    if (fs.st_mode & S_IRGRP)
        write(1,"Group has read permission on output_file_1: Yes\n",49);
    else if (!(fs.st_mode & S_IRGRP))
    {
        write(1,"Group has read permission on output_file_1: No\n",48);
    }
    
    if (fs.st_mode & S_IWGRP)
        write(1,"Group has write permission on output_file_1: Yes\n",50);
    else if (!(fs.st_mode & S_IWGRP))
        write(1,"Group has write permission on output_file_1: No\n",49);
    
    if(fs.st_mode & S_IXGRP)
        write(1,"Group has execute permission on output_file_1: Yes\n",52);
    else if(!(fs.st_mode & S_IXGRP))
        write(1,"Group has execute permission on output_file_1: No\n",51);
    
    write(1,"\n",2);

    if (fs.st_mode & S_IROTH)
        write(1,"Others has read permission on output_file_1: Yes\n",50);
    else if (!(fs.st_mode & S_IROTH))
    {
        write(1,"Others has read permission on output_file_1: No\n",49);
    }
    
    if (fs.st_mode & S_IWOTH)
        write(1,"Others has write permission on output_file_1: Yes\n",51);
    else if (!(fs.st_mode & S_IWOTH))
        write(1,"Others has write permission on output_file_1: No\n",50);
    
    if(fs.st_mode & S_IXOTH)
        write(1,"Others has execute permission on output_file_1: Yes\n",53);
    else if(!(fs.st_mode & S_IXOTH))
        write(1,"Others has execute permission on output_file_1: No\n",52);
    
   L1: write(1,"\n",2);

    // ==================================================================================================
    // Output_file_2 ====================================================================================

    char filename_2[100] = "./Assignment/2_";
    strcat(filename_2, in); // second output file to look out for

    struct stat f2s;
    //int r;
    //printf("Obtaining permission mode for '%s':\n", filename);
    r = stat(filename_2, &f2s);
    if (r == -1) // if output file doesn't exist
    {
       
        perror(filename_2);
       
       goto L2; // check for directory and skip looking for second output file
    }
    // one by one check each type of permission for user, group and others
    if (f2s.st_mode & S_IRUSR)
        write(1,"User has read permission on output_file_2: Yes\n",48);
    else if (!(f2s.st_mode & S_IRUSR))
    {
        write(1,"User has read permission on output_file_2: No\n",47);
    }
    
    if (f2s.st_mode & S_IWUSR)
        write(1,"User has write permission on output_file_2: Yes\n",49);
    else if (!(fs.st_mode & S_IWUSR))
        write(1,"User has write permission on output_file_2: No\n",48);
    
    if(f2s.st_mode & S_IXUSR)
        write(1,"User has execute permission on output_file_2: Yes\n",51);
    else if(!(f2s.st_mode & S_IXUSR))
        write(1,"User has execute permission on output_file_2: No\n",50);
    
    write(1,"\n",2);

    if (f2s.st_mode & S_IRGRP)
        write(1,"Group has read permission on output_file_2: Yes\n",49);
    else if (!(f2s.st_mode & S_IRGRP))
    {
        write(1,"Group has read permission on output_file_2: No\n",48);
    }
    
    if (f2s.st_mode & S_IWGRP)
        write(1,"Group has write permission on output_file_2: Yes\n",50);
    else if (!(f2s.st_mode & S_IWGRP))
        write(1,"Group has write permission on output_file_2: No\n",49);
    
    if(f2s.st_mode & S_IXGRP)
        write(1,"Group has execute permission on output_file_2: Yes\n",52);
    else if(!(f2s.st_mode & S_IXGRP))
        write(1,"Group has execute permission on output_file_2: No\n",51);
    
    write(1,"\n",2);

    if (f2s.st_mode & S_IROTH)
        write(1,"Others has read permission on output_file_2: Yes\n",50);
    else if (!(f2s.st_mode & S_IROTH))
    {
        write(1,"Others has read permission on output_file_2: No\n",49);
    }
    
    if (f2s.st_mode & S_IWOTH)
        write(1,"Others has write permission on output_file_2: Yes\n",51);
    else if (!(f2s.st_mode & S_IWOTH))
        write(1,"Others has write permission on output_file_2: No\n",50);
    
    if(f2s.st_mode & S_IXOTH)
        write(1,"Others has execute permission on output_file_2: Yes\n",53);
    else if(!(f2s.st_mode & S_IXOTH))
        write(1,"Others has execute permission on output_file_2: No\n",52);
    
  L2:  write(1,"\n",2);

  // ===============================================================================================
  // Directory =====================================================================================

  char dir_name[13] = "./Assignment";
    

    struct stat fds;
    
    r = stat(dir_name, &fds);
    // one by one check for each type of permission for user, group and others
    if (fds.st_mode & S_IRUSR)
        write(1,"User has read permission on directory: Yes\n",44);
    else if (!(fds.st_mode & S_IRUSR))
    {
        write(1,"User has read permission on directory: No\n",43);
    }
    
    if (fds.st_mode & S_IWUSR)
        write(1,"User has write permission on directory: Yes\n",45);
    else if (!(fds.st_mode & S_IWUSR))
        write(1,"User has write permission on directory: No\n",44);
    
    if(fds.st_mode & S_IXUSR)
        write(1,"User has execute permission on directory: Yes\n",47);
    else if(!(fds.st_mode & S_IXUSR))
        write(1,"User has execute permission on directory: No\n",46);
    
    write(1,"\n",2);

    if (fds.st_mode & S_IRGRP)
        write(1,"Group has read permission on directory: Yes\n",45);
    else if (!(fds.st_mode & S_IRGRP))
    {
        write(1,"Group has read permission on directory: No\n",44);
    }
    
    if (fds.st_mode & S_IWGRP)
        write(1,"Group has write permission on directory: Yes\n",46);
    else if (!(fds.st_mode & S_IWGRP))
        write(1,"Group has write permission on directory: No\n",45);
    
    if(fds.st_mode & S_IXGRP)
        write(1,"Group has execute permission on directory: Yes\n",48);
    else if(!(fds.st_mode & S_IXGRP))
        write(1,"Group has execute permission on directory: No\n",47);
    
    write(1,"\n",2);

    if (fds.st_mode & S_IROTH)
        write(1,"Others has read permission on directory: Yes\n",46);
    else if (!(fds.st_mode & S_IROTH))
    {
        write(1,"Others has read permission on directory: No\n",45);
    }
    
    if (fds.st_mode & S_IWOTH)
        write(1,"Others has write permission on directory: Yes\n",47);
    else if (!(fds.st_mode & S_IWOTH))
        write(1,"Others has write permission on directory: No\n",46);
    
    if(fds.st_mode & S_IXOTH)
        write(1,"Others has execute permission on directory: Yes\n",49);
    else if(!(fds.st_mode & S_IXOTH))
        write(1,"Others has execute permission on directory: No\n",48);
    
    write(1,"\n",2);


    
    return 0;
}
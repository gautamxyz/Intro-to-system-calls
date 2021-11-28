#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>



long long int power(long long int pref_byte_size)
{
    int i;
    long long int A[32];
    A[0]=1;
    
    int count=0;
    long long int l,s;
    for(int i=1;i<32;i++)
    {
        A[i]=A[i-1]*2;
        if(A[i]>pref_byte_size && count==0)
        {
            count=1;
            l=A[i];
            s=A[i-1];
            return(s);

        }
    }
}
int main(int argc,char* argv[])
{
  
    
    if(argc<2 || argc > 2)
    {

        
        write(1,"Invalid number of arguments entered: Failure\n",46);
        _exit(0);
    }
    char in[300];
    int pos=0; // to check position of the last '/'
    for(int i=0;i<strlen(argv[1]);i++)
    {
        if(argv[1][i]=='/')
        pos=i+1;
    }
   
    //extracting name of input file from the path by keeping track of the last '/' in path
    for(int i=pos;i<strlen(argv[1]);i++)
    {
        in[i-pos]=argv[1][i];
    }
    
    
    int in_file=open(argv[1],O_RDONLY); // check if in_file exists
    if(in_file==-1)
    {
        
        perror( argv[1] ); 
        
       
        _exit(0);
    }
    char* dirname="Assignment";
    int check_dir = mkdir(dirname,0700); // creating Assignment directory
    char out_[100]="./Assignment/1_";
    strcat(out_,in); // obtaining name of output file
    
    int out_file = open(out_ , O_CREAT | O_RDWR | O_TRUNC, 0600);  //creating out_file

    off_t file_len=lseek(in_file,0,SEEK_END);
    // repositioning file descriptor offsets
    lseek(out_file, 0, SEEK_SET);
    lseek(in_file, -1, SEEK_END);
    //set block size
    long long int pref_byte_size=file_len/500;
    long long int num_bytes_per_read=(pref_byte_size==0) ? 1 : power(pref_byte_size);

    char *c, *r;
    c = (char *)malloc(num_bytes_per_read);
    r = (char *)malloc(num_bytes_per_read);
    //  Set start location and the initial length to move
    long long int start = ((file_len - 1) / num_bytes_per_read) * num_bytes_per_read; //start location is set as the starting location of the last block
    long long int length_to_move = file_len - start;
    lseek(in_file, start, SEEK_SET);
    
    double perc=0;
    int count=0;
    
    while (1)
    {
        count++;
        
        fflush(stdout);
        write(1,"\r",1);
        // Read `length_to_move` bytes from `source_file` and store in `c`
        
        read(in_file, c, length_to_move);
        
        // Store contents of c in r in reverse 
        for (int begin = 0, end = length_to_move - 1; begin < length_to_move; begin++, end--)
        {    
            r[begin] = c[end];
        }
      
        r[length_to_move] = '\0';
        
        
        
        
        
        perc+=length_to_move;  
        
        
        
        if(perc>file_len)
        perc=file_len;
        
        write(out_file, r, length_to_move); // write the block to which r is pointing to in the out_file
        
        
        
        
        
        double x= (perc*100.00)/file_len;
        char output[8];
        sprintf(output,"%.2lf",x);
        

        write(1,"Progress : ",12);       // printing progress on terminal
        write(1,&output,sizeof(output));
        write(1,"% ",1);
       
        // Check if there are any more blocks to read
        if (lseek(in_file, 0, SEEK_CUR) - num_bytes_per_read - length_to_move < 0)
            break;
        // Moving the 'source_file' to the start of the previous block
        lseek(in_file, -num_bytes_per_read - length_to_move, SEEK_CUR);
        length_to_move = num_bytes_per_read;
        
        
    }
    close(in_file); //closing the files
    close(out_file);
    
    
    write(1,"\n",2);
    
    
    return 0;
}
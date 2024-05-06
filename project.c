#include <stdio.h>
#include <string.h>
int main(){
    char c[100];
    // strcpy (c , "c programing");
    // printf("nilainya %s\n",c);
    // printf("ukuran c adalah %zu\n",sizeof(c)/sizeof(c[0]));
    // printf("ukuran c adalah %zu\n",strlen(c));
    printf("enter name :");
    // scanf("%s\n",c);
    fgets(c,sizeof(c),stdin);
    puts(c);
}
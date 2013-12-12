#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
       int n=0;
       char str[100];
       const char* c=NULL;
       do{
               c=strerror(n);
               sprintf(str,"%d:%s",n,c);
               puts(str);
               n++;
       }while(n<200);
		//!strstr(c,"Unknown error")
      // free(e);
       //assert(1);
       return 0;
}


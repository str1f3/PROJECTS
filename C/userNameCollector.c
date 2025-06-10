




#include <stdio.h>
#include <string.h>

int main(void)
{
  char userName[1000][26];
  int nameCount = 0;
  
  puts("Enter usernames then enter 'quit' once done.");
  
  for (int i = 0; nameCount < 1000; i++){
    printf("Enter username%d : ", nameCount + 1);
	scanf("%25s", userName[i]);
	
	if (strcmp(userName[i], "quit") == 0){
	  break;
	}
	nameCount++;
  }
  
  for (int i = 0; i < nameCount; i++){
    printf("Username%d:  %s\n", i + 1, userName[i]);
  }
  
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char  s[1000];

  gets(s);
  
  int len = strlen(s);
  s[len] = ' '; s[len + 1] = 0; //=> cong them khoang trang cuoi chuoi

  len = len + 1;
  char* pWord = s;

  long long tong = 0;
  
  for (int i = 0; i < len; ++i){
    
    if (!(s[i] >= '0' && s[i] <= '9')){
      s[i] = 0;
      if (pWord[0] != 0){
        //printf("[%s]\n",pWord);
        long long x = atoll(pWord);
        tong = tong + x;
      }
            
      pWord = &s[i + 1];
    }    
  }//for (int i = 0; i < len; ++i){
  
  printf("%lld",tong);

  return 0;
}
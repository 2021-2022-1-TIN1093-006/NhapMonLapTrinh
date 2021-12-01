#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//chuyển ký tự thành ký tự thường
char convertLower(char c){
  if  (c >= 'A' && c <= 'Z') return (c + 32);
  if (c >= 'a' && c <= 'z' ) return c;
  return 0;
}

//kiểm tra ký tự tồn tại trong chuỗi 
//+ c đã chuyển chử thường 
//+ str[0->len] là chử thường
bool isExist(char c, char* str, int len){
  if (len == 0) return false;       //là ký tự đầu tiên
  for (int i = 0; i < len; ++i)
    if (c == str[i]) return true;   //kiểm tra ký tự với dãy ký tự trước nó
  return false;
}

int main(){
  char  s[500];
  gets(s);
  
  int len = strlen(s);
  int count = 0;

  for (int i = 0; i < len; ++i){
    char c = convertLower(s[i]);
    if (c == 0) continue;
    s[i] = c; //gán s[i] thành chử thường
    if (!isExist(c,s,i)){
      //printf("[%c][%c] IN [%s]\n",s[i],ch,str);      
      ++count;    
    }    
  }//for (int i = 0; i < len; ++i){
  
  //printf("[%s]\n",s);
  printf("%lld",count);
  
  return 0;
}
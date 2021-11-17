#include <stdio.h>

void He10_He2_Cong(long long dec){
  long long rem, sum = 0, i = 1;
  do {
    rem = dec % 2;
    sum = sum + (i * rem);
    dec = dec/2;
    i = i * 10;
  }while(dec > 0);
  printf("%llu",sum);
}

void He10_He2_Mang(long long dec){
  int bin[64];  
  int count = 0;
  if (dec == 0){ bin[0] = 0; count = 1;}
  
  while (dec != 0)
  {    
    bin[count++] = dec % 2;
    dec = dec / 2;
  }
  for (;--count >= 0;) printf("%d",bin[count]);
}

void He10_He2_Dequy(long long dec){
  if (dec == 0) return;
  He10_He2_Dequy(dec / 2);
  printf("%d",dec % 2);
}

#include <string>
void He10_He2_Chuoi(long long dec){
  std::string bin = "";  
  if (dec == 0) bin = "0";
  while (dec != 0)
  {
    
    if (dec % 2 == 0) bin.insert(0,"0");
    else bin.insert(0,"1");    
    dec = dec / 2;
  }
  printf("%s",bin.c_str());
}


void Nopbai_OJ(){
long long n;
  scanf("%lld",&n);
  He10_He2_Cong(n);   printf("\n");
  //He10_He2_Mang(n);   printf("\n");
  //He10_He2_Chuoi(n); printf("\n");
  //He10_He2_Dequy(n);
}

void Kiemthu_taimay(){
  long long n;
  printf("Nhap n = "); scanf("%lld",&n);

  printf("He10_He2_Cong  : ");  He10_He2_Cong(n);   printf("\n");
  printf("He10_He2_Mang  : ");  He10_He2_Mang(n);   printf("\n");
  printf("He10_He2_Chuoi : "); He10_He2_Chuoi(n);   printf("\n");
  printf("He10_He2_Dequy : "); He10_He2_Dequy(n);
}

int main(){

  //bỏ comment để nộp bài lên OJ
  //Nopbai_OJ();

  //thêm comment để nộp bài lên OJ
  Kiemthu_taimay();

  return 0;
}

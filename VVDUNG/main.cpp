#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void NhapMang(int a[], int n){
  for (int i = 0; i < n; ++i)
  {
    printf("a[%d] = ",i);
    scanf("%d",&a[i]);
  }
}
void XuatMang(int a[], int n){
  for (int i = 0; i < n; ++i) printf("%d ",a[i]);
}

//Hiển thị số nhị phân 64bit (chỉ số dương)
void He10_He2_Mang(long long dec){
  int bin[64];  
  int count = 0;
  if (dec == 0) { bin[0] = 0; count = 1;}
  
  while (dec != 0)
  {    
    bin[count++] = dec % 2;
    dec = dec / 2;
  }
  for (;--count >= 0;) printf("%d",bin[count]);
}

//Hiển thị số nhị phân 64bit (âm/dương)
void He10_He2_Mang_SoBuHai(long long dec){
  int rem, bin[64];   
  int count = 0;
  if (dec == 0){ bin[0] = 0; count = 1;}

  int isNegativeNumber = (dec < 0);
  if (isNegativeNumber){
    for (int i = 0; i < 64; ++i) bin[i] = 1; //khởi tạo tất cả giá trị của bin[] = 1
     dec = (~dec + 1); //so bu 2 => so duong; chuyển số âm => dương (-7 => 7)
  }
  int one_plus = 1; //lưu trạng thái nhớ khi tính toán số bù2
  while (dec != 0)
  { 
    rem = dec % 2;  //số dư
    
    if (isNegativeNumber){// là số âm => tính toán bù 2
      int tmp = (rem == 0? 1 : 0); //bù 1
      tmp = tmp + one_plus;        //+ 1 => bù 2 (có nhớ)
      one_plus = tmp / 2;          //lưu lại trạng thái nhớ cho vòng lặp tiếp theo
      rem = tmp % 2;               //số bù 2 sau khi đã tính toán
    }

    bin[count++] = rem;
    dec = dec / 2; //chia cho 2 theo cách tính hệ 10 -> hệ 2
  }

  //in mảng theo chiều ngược lại để hiển thị số nhị phân
  if (!isNegativeNumber)
    for (;--count >= 0;) printf("%d",bin[count]);
  else{
    //in 64 bit
    for (int i = 63; i>= 0; --i) printf("%d",bin[i]);
  }
}
//Hiển thị số nhị phân 64bit (âm/dương)
void He10_He2_BIT(long long dec){
  unsigned long long mask = 0x8000000000000000; //8bytes = 64bit 0x8 = 1000 = 4bits
  unsigned long long value;
  int oneFirst = 0;   //sử dụng để không hiển thị các số 0 đứng trước số nhị phân
  for (int i = 1; i <= 64; ++i){    
    value = (dec & mask);      //lấy giá trị bit [0 hoặc 1] tại vị trí mask
    value = value >> (64 - i); //dịch phải tương ứng với số bit của mask - 1
    mask = mask >> 1;          //dịch phải mask để tính giá trị bit tiếp theo
    if (oneFirst == 0) oneFirst = (value == 1);
    if (oneFirst) printf("%d",value);
  }
}

int main(){
  char  s[1000];
  gets(s);
  //printf("%s\n",s); //tin    hoc    dai    cuong
  
  int len = strlen(s);
  s[len] = ' '; s[len + 1] = 0; //=> cong them khoang trang cuoi chuoi

  len = len + 1;
  char* pWord = s;

  int dem = 0;
  long long tong = 0;
  
  for (int i = 0; i < len; ++i){
    if (s[i] == ' '){
      if (pWord[0] != ' '){
        s[i] = 0;
        //printf("[%s]",pWord);
        long long x = atoll(pWord);
        tong = tong + x;
        ++dem;
      }
      
      pWord = &s[i + 1];
    }    
  }//for (int i = 0; i < len; ++i){
  
  //printf("\nso luong tu dem dc: %d\n",dem);
  //printf("Tong so trong xau: %d",tong);
  printf("%lld",tong);

  //printf("\n***** EXIT *****\n");
  return 0;
}
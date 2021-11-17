#include <stdio.h>
#include <string>

//Hiển thị số nhị phân (chỉ số dương - 19 bits)
void He10_He2_Cong(long long dec){
  unsigned long long rem, sum = 0, dv = 1;
  do {
    rem = dec % 2;
    sum = sum + (dv * rem);
    dec = dec / 2;
    dv = dv * 10;
  }while(dec > 0);
  printf("%llu",sum);
}
//Hiển thị số nhị phân 64bit (chỉ số dương)
void He10_He2_Dequy(long long dec){
  //1 - Tham số hóa: Định nghĩa hàm
  //2 - Điều kiện suy biến: dec  = 0
  //3 - Giải thuật đệ quy; He10_He2_Dequy(n) = He10_He2_Dequy(n/2) -> hienthi so du
  if (dec == 0) return;
  He10_He2_Dequy(dec/2);
  printf("%d",dec % 2);
}
//Hiển thị số nhị phân 64bit (chỉ số dương)
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
//Hiển thị số nhị phân 64bit (chỉ số dương)
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

void Nopbai_OJ(){
  long long n;
  scanf("%lld",&n);
  //He10_He2_Cong(n);
  //He10_He2_Dequy(n);
  //He10_He2_Mang(n);
  //He10_He2_Chuoi(n);
  He10_He2_BIT(n);
  //He10_He2_Mang_SoBuHai(n);
}

void Kiemthu_Taimay(){
  printf("[RUNNING AT PC]\n");
  printf("SIZE of long long: %d\n",sizeof(long long));
  long long n;
  printf("Nhap n [am/duong] = "); scanf("%lld",&n);
  if (n >= 0){
    printf("He10_He2_Cong  : "); He10_He2_Cong(n);  printf(" (chi dung voi 19bit)\n");
    printf("He10_He2_Dequy : "); He10_He2_Dequy(n); printf("\n");
    printf("He10_He2_Mang  : "); He10_He2_Mang(n);  printf("\n");
    printf("He10_He2_Chuoi : "); He10_He2_Chuoi(n); printf("\n");
  }
  printf  ("He10_He2_BIT   : "); He10_He2_BIT(n); printf("\n");
  printf  ("Mang_SoBuHai   : "); He10_He2_Mang_SoBuHai(n); printf("\n");
}

/*Bỏ commnet dòng dưới để nộp bài trên OJ.HUSC.EDU.VN*/
//#define OJ 1

int main(){

#ifdef OJ
  Nopbai_OJ();
#else
  Kiemthu_Taimay();
#endif   

  return 0;
}
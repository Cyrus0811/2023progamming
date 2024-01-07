#include <stdio.h>
/* source: https://www.runoob.com/cprogramming/c-standard-library-stdio-h.html

1. int printf(const char *format, ...)
    发送格式化输出到标准输出 stdout
//ex:
int main (){
   int ch;
   for( ch = 75 ; ch <= 100; ch++ ) {
      printf("ASCII 值 = %d, 字符 = %c\n", ch , ch );
   } 
   return(0);
}

2. int scanf(const char *format, ...)
    从标准输入 stdin 读取格式化输入
int main(void) { 
    int a,b,c; 
    printf("请输入三个数字：");
    scanf("%d%d%d",&a,&b,&c); 
    printf("%d,%d,%d\n",a,b,c);
    return 0; 
}

3. char *tmpnam(char *str)
    生成并返回一个有效的临时文件名，该文件名之前是不存在的。如果 str 为空，则只会返回临时文件名
//ex:
int main(){
   char buffer[L_tmpnam];
   char *ptr;
   tmpnam(buffer);
   printf("临时名称 1: %s\n", buffer); 
   ptr = tmpnam(NULL);
   printf("临时名称 2: %s\n", ptr);
   return(0);
}
-->临时名称 1: /tmp/filebaalTb
   临时名称 2: /tmp/filedCIbb0

4. FILE *freopen(const char *filename, const char *mode, FILE *stream)
    把一个新的文件名 filename 与给定的打开的流 stream 关联，同时关闭流中的旧文件
//ex:
int main (){
   FILE *fp;
   printf("该文本重定向到 stdout\n");
   fp = freopen("file.txt", "w+", stdout);
   printf("该文本重定向到 file.txt\n");
   fclose(fp); 
   return(0);
}

5. int fclose(FILE *stream)
    关闭流 stream。刷新所有的缓冲区
//ex:
int main()
{
   FILE *fp;
 
   fp = fopen("file.txt", "w");

   fprintf(fp, "%s", "这里是 runoob.com");
   fclose(fp);
   
   return(0);
}
*/

#include <string.h>
/* source: https://www.runoob.com/cprogramming/c-standard-library-string-h.html

1. int __cdecl strcmp(const char *_Str1,const char *_Str2);
    把 str1 所指向的字符串和 str2 所指向的字符串进行比较
//ex:
int main (){
   char str1[15];
   char str2[15];
   int ret;
   strcpy(str1, "abcdef");
   strcpy(str2, "ABCDEF");
   ret = strcmp(str1, str2); 
   if(ret < 0) {
      printf("str1 小于 str2");
   }
   else if(ret > 0){
      printf("str1 大于 str2");
   }
   else {
      printf("str1 等于 str2");
   }   
   return(0);
}

2. char *strchr(const char *str, int c);
    strchr() 用于查找字符串中的一个字符，并返回该字符在字符串中第一次出现的位置。
//ex:
int main (){
   const char str[] = "https://www.runoob.com";
   const char ch = 'o';
   char *ptr;
   ptr = strchr(str, ch);
    if (ptr != NULL) {
        printf("字符 'o' 出现的位置为 %ld。\n", ptr - str + 1);
        printf("|%c| 之后的字符串是 - |%s|\n", ch, ptr);
    } else {
        printf("没有找到字符 'o' 。\n");
    }
   return(0);
}

3. size_t strcspn(const char *str1, const char *str2);
    检索字符串 str1 开头连续有几个字符都不含字符串 str2 中的字符
//ex:
int main (){
   int len;
   const char str1[] = "ABCDEF4960910";
   const char str2[] = "013";
   len = strcspn(str1, str2);
   printf("第一个匹配的字符是在 %d\n", len + 1);   
   return(0);
}

4. char *strerror(int errnum)
    从内部数组中搜索错误号 errnum，并返回一个指向错误消息字符串的指针
//ex:
int main (){
   FILE *fp;
   fp = fopen("file.txt","r");
   if( fp == NULL ) {
      printf("Error: %s\n", strerror(errno));
   }
  return(0);
}
 --> 當我们尝试打开一个不存在的文件,將顯示：Error: No such file or directory

5. char *strpbrk(const char *str1, const char *str2)
    检索字符串 str1 中第一个匹配字符串 str2 中字符的字符，不包含空结束字符。也就是说，依次检验字符串 str1 中的字符，
    当被检验字符在字符串 str2 中也包含时，则停止检验，并返回该字符位置。
//ex:
int main ()
{
   const char str1[] = "abcde2fghi3jk4l";
   const char str2[] = "34";
   char *ret;
   ret = strpbrk(str1, str2);
   if(ret)  {
      printf("第一个匹配的字符是： %c\n", *ret);
   }
   else  {
      printf("未找到字符");
   } 
   return(0);
}

*/

#include <math.h>
/* source: https://www.runoob.com/cprogramming/c-standard-library-string-h.html

1. double sin(double x)
     返回弧度角 x 的正弦
//ex:
#define PI 3.14159265

int main (){
   double x, ret, val;
   x = 45.0;
   val = PI / 180;
   ret = sin(x*val);
   printf("%lf 的正弦是 %lf 度", x, ret);   
   return(0);
}

2. double cos(double x)
    返回弧度角 x 的余弦
//ex:
int main (){
   double x, ret, val;
   x = 60.0;
   val = PI / 180.0;
   ret = cos( x*val );
   printf("%lf 的余弦是 %lf 度\n", x, ret);
   x = 90.0;
   val = PI / 180.0;
   ret = cos( x*val );
   printf("%lf 的余弦是 %lf 度\n", x, ret);   
   return(0);
}

3. double exp(double x)
     返回 e 的 x 次幂的值
//ex:
  int main (){
   double x = 0;  
   printf("e 的 %lf 次幂是 %lf\n", x, exp(x));
   printf("e 的 %lf 次幂是 %lf\n", x+1, exp(x+1));
   printf("e 的 %lf 次幂是 %lf\n", x+2, exp(x+2));   
   return(0);
}

4. double log(double x)
    返回 x 的自然对数（基数为 e 的对数）
//ex:
int main (){
   double x, ret;
   x = 2.7;
   ret = log(x);
   printf("log(%lf) = %lf", x, ret);   
   return(0);
}

5. double floor(double x)
    返回小于或等于 x 的最大的整数值
//ex:
int main (){
   float val1, val2, val3, val4;
   val1 = 1.6;
   val2 = 1.2;
   val3 = 2.8;
   val4 = 2.3;
   printf("Value1 = %.1lf\n", floor(val1));
   printf("Value2 = %.1lf\n", floor(val2));
   printf("Value3 = %.1lf\n", floor(val3));
   printf("Value4 = %.1lf\n", floor(val4));   
   return(0);
}

*/

#include <aasert.h>
/* source: https://www.runoob.com/cprogramming/c-standard-library-assert-h.html

1. void assert(int expression);
    允许诊断信息被写入到标准错误文件中。换句话说，它可用于在 C 程序中添加诊断
//ex:
int main(){
   int a;
   char str[50];     
   printf("请输入一个整数值： ");
   scanf("%d", &a);
   assert(a >= 10);
   printf("输入的整数是： %d\n", a);    
   printf("请输入字符串： ");
   scanf("%s", str);
   assert(str != NULL);
   printf("输入的字符串是： %s\n", str);    
   return(0);
}
*/

#include <ctype.h>
/* source: https://www.runoob.com/cprogramming/c-standard-library-ctype-h.html

1. int isalnum(int c);
    检查所传的字符是否是字母和数字
//ex:
int main(){
   int var1 = 'd';
   int var2 = '2';
   int var3 = '\t';
   int var4 = ' ';   
   if( isalnum(var1) ){
      printf("var1 = |%c| 是字母数字\n", var1 );
   }
   else{
      printf("var1 = |%c| 不是字母数字\n", var1 );
   }
   if( isalnum(var2) ){
      printf("var2 = |%c| 是字母数字\n", var2 );
   }
   else{
      printf("var2 = |%c| 不是字母数字\n", var2 );
   }
   if( isalnum(var3) ){
      printf("var3 = |%c| 是字母数字\n", var3 );
   }
   else {
      printf("var3 = |%c| 不是字母数字\n", var3 );
   }
   if( isalnum(var4) ) {
      printf("var4 = |%c| 是字母数字\n", var4 );
   }
   else {
      printf("var4 = |%c| 不是字母数字\n", var4 );
   }    
   return(0);
}
 -->var1 = |d| 是字母数字
    var2 = |2| 是字母数字
    var3 = | | 不是字母数字
    var4 = | | 不是字母数字

2. int isalpha(int c);
     检查所传的字符是否是字母
//ex:
int main(){
   int var1 = 'd';
   int var2 = '2';
   int var3 = '\t';
   int var4 = ' ';
    
   if( isalpha(var1) ){
      printf("var1 = |%c| 是一个字母\n", var1 );
   }
   else{
      printf("var1 = |%c| 不是一个字母\n", var1 );
   }
   if( isalpha(var2) ){
      printf("var2 = |%c| 是一个字母\n", var2 );
   }
   else {
      printf("var2 = |%c| 不是一个字母\n", var2 );
   }
   if( isalpha(var3) ) {
      printf("var3 = |%c| 是一个字母\n", var3 );
   }
   else {
      printf("var3 = |%c| 不是一个字母\n", var3 );
   }
   if( isalpha(var4) ) {
      printf("var4 = |%c| 是一个字母\n", var4 );
   }
   else  {
      printf("var4 = |%c| 不是一个字母\n", var4 );
   }   
   return(0);
}
 -->var1 = |d| 是一个字母
    var2 = |2| 不是一个字母
    var3 = | | 不是一个字母
    var4 = | | 不是一个字母

3. int iscntrl(int c);
    检查所传的字符是否是控制字符
//ex:
int main (){
   int i = 0, j = 0;
   char str1[] = "all \a about \t programming";
   char str2[] = "Runoob \n tutorials";
   // 输出字符串直到控制字符 \a //
   while( !iscntrl(str1[i]) ) {
      putchar(str1[i]);
      i++;
   }
   // 输出字符串直到控制字符 \n //
   while( !iscntrl(str2[j]) ) {
      putchar(str2[j]);
      j++;
   } 
   return(0);
}

4. int isdigit(int c);
    检查所传的字符是否是十进制数字字符
//ex:
int main(){
   int var1 = 'h';
   int var2 = '2';
    
   if( isdigit(var1) ){
      printf("var1 = |%c| 是一个数字\n", var1 );
   }
   else{
      printf("var1 = |%c| 不是一个数字\n", var1 );
   }
   if( isdigit(var2) ){
      printf("var2 = |%c| 是一个数字\n", var2 );
   }
   else{
      printf("var2 = |%c| 不是一个数字\n", var2 );
   }  
   return(0);
}

5. int isgraph(int c);
    检查所传的字符是否有图形表示法
//ex:
int main(){
   int var1 = '3';
   int var2 = 'm';
   int var3 = ' ';
    
   if( isgraph(var1) ){
       printf("var1 = |%c| 是可打印的\n", var1 );
   }
   else{
      printf("var1 = |%c| 是不可打印的\n", var1 );
   }
   if( isgraph(var2) ){
       printf("var2 = |%c| 是可打印的\n", var2 );
   }
   else{
      printf("var2 = |%c| 是不可打印的\n", var2 );
   }
   if( isgraph(var3) ){
       printf("var3 = |%c| 是可打印的\n", var3 );
   }
   else{
      printf("var3 = |%c| 是不可打印的\n", var3 );
   } 
   return(0);
}
*/

#include <stdlib.h>
/* source: https://www.runoob.com/cprogramming/c-standard-library-stdlib-h.html

1. int atoi(const char *str)
    把参数 str 所指向的字符串转换为一个整数（类型为 int 型）
//ex:
int main(){
   int val;
   char str[20];   
   strcpy(str, "98993489");
   val = atoi(str);
   printf("字符串值 = %s, 整型值 = %d\n", str, val);
   strcpy(str, "runoob.com");
   val = atoi(str);
   printf("字符串值 = %s, 整型值 = %d\n", str, val);
   return(0);
}

2. int abs(int x)
    返回整数 x 的绝对值
//ex:
int main (){
   int a, b;
   a = abs(5);
   printf("a 的值 = %d\n", a);
   b = abs(-10);
   printf("b 的值 = %d\n", b);   
   return(0);
}

3. void *malloc(size_t size)
     分配所需的内存空间，并返回一个指向它的指针
//ex:
int main(){
   char *str;
   // 最初的内存分配 //
   str = (char *) malloc(15);
   strcpy(str, "runoob");
   printf("String = %s,  Address = %u\n", str, str);
   // 重新分配内存 //
   str = (char *) realloc(str, 25);
   strcat(str, ".com");
   printf("String = %s,  Address = %u\n", str, str);
   free(str);
   return(0);
}

4. int rand(void)
    返回一个范围在 0 到 RAND_MAX 之间的伪随机数
    RAND_MAX 是一个常量，它的默认值在不同的实现中会有所不同，但是值至少是 32767
//ex:
int main(){
   int i, n;
   time_t t;   
   n = 5;   
   // 初始化随机数发生器 //
   srand((unsigned) time(&t)); 
   // 输出 0 到 49 之间的 5 个随机数 //
   for( i = 0 ; i < n ; i++ ) {
      printf("%d\n", rand() % 50);
   }   
  return(0);
}

5. void srand(unsigned int seed);
    播种由函数 rand 使用的随机数发生器
//ex:
int main(){
   int i, n;
   time_t t;
   n = 5;
   // 初始化随机数发生器 //
   srand((unsigned) time(&t));
   // 输出 0 到 50 之间的 5 个随机数 //
   for( i = 0 ; i < n ; i++ ) {
      printf("%d\n", rand() % 50);
   }   
  return(0);
}
*/

#include <time.h>
/* source: https://www.runoob.com/cprogramming/c-standard-library-time-h.html

1. char *asctime(const struct tm *timeptr)
     返回一个指向字符串的指针，它代表了结构 struct timeptr 的日期和时间
//ex:
struct tm {
   int tm_sec;         // 秒，范围从 0 到 59    //            
   int tm_min;         // 分，范围从 0 到 59    //            
   int tm_hour;        // 小时，范围从 0 到 23     //           
   int tm_mday;        // 一月中的第几天，范围从 1 到 31        //            
   int tm_mon;         // 月份，范围从 0 到 11       //        
   int tm_year;        // 自 1900 起的年数     //           
   int tm_wday;        // 一周中的第几天，范围从 0 到 6     //         
   int tm_yday;        // 一年中的第几天，范围从 0 到 365     //              
   int tm_isdst;       // 夏令时                          
};

int main(){
   struct tm t;
   t.tm_sec    = 10;
   t.tm_min    = 10;
   t.tm_hour   = 6;
   t.tm_mday   = 25;
   t.tm_mon    = 2;
   t.tm_year   = 89;
   t.tm_wday   = 6;
   puts(asctime(&t));  
   return(0);
}

2. clock_t clock(void)
    返回程序执行起（一般为程序的开头），处理器时钟所使用的时间。为了获取 CPU 所使用的秒数，您需要除以 CLOCKS_PER_SEC。
    在 32 位系统中，CLOCKS_PER_SEC 等于 1000000，该函数大约每 72 分钟会返回相同的值。
//ex:
int main(){
   clock_t start_t, end_t;
   double total_t;
   int i; 
   start_t = clock();
   printf("程序启动，start_t = %ld\n", start_t);    
   printf("开始一个大循环，start_t = %ld\n", start_t);
   for(i=0; i< 10000000; i++)
   {
   }
   end_t = clock();
   printf("大循环结束，end_t = %ld\n", end_t);   
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("CPU 占用的总时间：%f\n", total_t  );
   printf("程序退出...\n"); 
   return(0);
}

3. char *ctime(const time_t *timer)
    返回一个表示当地时间的字符串，当地时间是基于参数 timer
//ex:
int main (){
   time_t curtime;
   time(&curtime);
   printf("当前时间 = %s", ctime(&curtime)); 
   return(0);
}
 -->当前时间 = Mon Aug 13 08:23:14 2012

 4. time_t time(time_t *seconds)
    返回自纪元 Epoch（1970-01-01 00:00:00 UTC）起经过的时间，以秒为单位。如果 seconds 不为空，则返回值也存储在变量 seconds 中
//ex:
int main (){
  time_t seconds;
  seconds = time(NULL);
  printf("自 1970-01-01 起的小时数 = %ld\n", seconds/3600);  
  return(0);
}
-->自 1970-01-01 起的小时数 = 373711

5. struct tm *gmtime(const time_t *timer)
     使用 timer 的值来填充 tm 结构，并用协调世界时（UTC）也被称为格林尼治标准时间（GMT）表示
//ex:
#define BST (+1)
#define CCT (+8)
 
int main (){
   time_t rawtime;
   struct tm *info;
   time(&rawtime);
   // 获取 GMT 时间 //
   info = gmtime(&rawtime );   
   printf("当前的世界时钟：\n");
   printf("伦敦：%2d:%02d\n", (info->tm_hour+BST)%24, info->tm_min);
   printf("中国：%2d:%02d\n", (info->tm_hour+CCT)%24, info->tm_min);
   return(0);
}
 -->当前的世界时钟：
    伦敦：14:10
    中国：21:10

*/







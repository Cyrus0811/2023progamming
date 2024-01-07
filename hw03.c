#include <stdio.h>

#include <string.h>
/* https://www.runoob.com/cprogramming/c-standard-library-string-h.html

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


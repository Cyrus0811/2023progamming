#include <stdio.h>
#include <string.h>

// 1. int __cdecl strcmp(const char *_Str1,const char *_Str2);

int main(){
    printf("as two words is same.strcmp=%d\n",strcmp("abc","abc"));
    printf("as two words is diffiren.The front is smaller than the back,strcmp=%d\n",strcmp("abc","cba"));
    printf("as two words is diffiren.The front is bigger than the back,strcmp=%d\n",strcmp("cba","abc"));

}
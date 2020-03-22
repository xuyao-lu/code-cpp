#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 64
 
int main(void)
{
    int words;
    int len;
    char ** pwords;
    char * temp;
    int i; 
    printf("How many words do you wish to enter?");
    scanf("%d",&words);
    pwords = (char **)malloc(words * sizeof(char *));  //数组里储存的是指向char类型的指针，pwords是指向指针的指针
    
	printf("Enter %d words now:\n",words);
    
	temp = (char *)malloc(SIZE * sizeof(char)); //分配一段动态内存，用来临时储存每个单词，并返回指向该单词的指针
    
	for(i = 0; i < words; i++)
    {
        scanf("%s",temp);   //scanf在从第一个非空格读取到第一个空格时结束第一次读取，用循环来分别读取五个单词，每个单词用字符串形式储存在动态分配的内存中，由temp指向这段内存
        len = strlen(temp); //检查第i+1个单词的长度，用于分配空间
        pwords[i] = (char *)malloc((len + 1) * sizeof(char)); //pwords的元素是指针，这里分配一个动态内存，用pwords中的指针指向该动态内存，且内存的长度是单词长度加一，即多储存一个'\0'，字符串结尾
        strcpy(pwords[i],temp); //在pwords[i]指向的内存分配完成后，将该字符串temp拷贝到这个动态内存中
    }
   
    free(temp); //临时空间使用完毕后释放
    
	printf("Here are your words:\n");
   
    for(i = 0; i < words; i++)
    {
        puts(pwords[i]); //打印pwords[i]所指向的地址中的内容（是一个字符串，即用%s的形式来储存每一个单词），并用puts()自动打印换行符
    }
 
    free(pwords); //释放内存
 
    return 0
        ;
}

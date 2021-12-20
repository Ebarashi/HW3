#include<stdio.h>
#include<string.h>
#include"my_string.h"

#define TXT 1024
#define WORD 30
#define tilda 126

int main()
{
    char word [WORD] = {0};
    char txt [TXT]={0};
    

    int i = 0;
    char c;
    while(c != ' ' && c != '\t' && c != '\n' && i < WORD){
        scanf("%c", &c);
        word[i] = c;  
        i++;
    }
    word[i] = '\0';
   

    int index = 0;
    char x;
    while(index < 1024)
    {
        scanf("%c",&x);
        if(x == tilda){
            break;
        }else{
            txt[index]=x;
            index++;
        }
    }
    
    GematriaSequences(word,txt);
    AtbashSequences(word,txt);
    AnagramSequences(word,txt);

    return 0;
}
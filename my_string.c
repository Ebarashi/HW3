#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30
#define tilda 126

int gValue(char c){
    if(c >= 'A' && c <= 'Z'){
        return (c - 'A' + 1);
    }
    if(c >= 'a' && c <= 'z'){
        return (c - 'a' + 1);
    }
    return 0;
}

int GematriaSequences(char word[],char txt[])
{
    printf("Gematria Sequences: ");
    int startSentence = 0;
    int wordGV = 0;


    int i=0;
    while(i<strlen(word)){ wordGV=wordGV+gValue(word[i]); i++;}

    for (int i = 0; i < strlen(txt); i++)
    {
        int tempGV = 0;
        if (gValue(txt[i]) != 0)
        {
            for (int j = i; (j < strlen(txt)) && (tempGV <= wordGV); j++)
            {
                tempGV += gValue(txt[j]);
                if (tempGV == wordGV)
                {
                    if (startSentence == 1) printf("~");
                    startSentence = 1;
                    for (int k = i; k <= j; k++)
                    {
                        printf("%c", txt[k]);
                    }
                    break;  
                } 
            }  
        }   
    }
    return 0;   
}


int AtbashSequences(char word[],char txt[]){
printf("\nAtbash Sequences: ");


return 0;

}
int AnagramSequences(char word[],char txt[]){return 0;}





#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

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
int gValueWord(char word[]){
    int sum=0;
    for(int i =0;i<strlen(word);i++){
        sum+=gValue(word[i]);
    }
    return sum;
}

int GematriaSequences(char word[],char txt[])
{
    printf("Gematria Sequences: ");
    int startSentence = 0;
    int wordGV = gValueWord(word);

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
                    for (int pr = i; pr <= j; pr++)
                    {
                        printf("%c", txt[pr]);
                    }
                    break;  
                } 
            }  
        }   
    }
    printf("\n");
    return 0;   
}


char *Atbash(char Atbash[])
{
    char *ansA;
    ansA = (char*)malloc(strlen(Atbash));

    for(int i =0; i < strlen(Atbash); i++)
    {
        if(Atbash[i] >= 'A' && Atbash[i] <= 'Z')
        {
            char str[] = {Atbash[i],'\0'};
            ansA[i] = 'Z' - gValueWord(str) + 1;
        }
        if(Atbash[i] >= 'a' && Atbash[i] <= 'z')
        {
            char str[] = {Atbash[i],'\0'};
            ansA[i] = 'z' - gValueWord(str) + 1;
        }
    }
    return ansA;
}

char *Srev(char *str)
{
    char *ansR;
    ansR = (char*)malloc(strlen(str));
    //int len = strlen(str);
    int j = 0;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
       ansR[j] = str[i];
       j++; 
    }
    
    //str [len] = '0';
    // int k = len - 1;
    // if(len%2 == 0)
    // {
    //     for(int i = 0; i < len/2; i++)
    //     {
    //         char temp = str[k];
    //         str[k--] = str[i];
    //         str[i] = temp;
    //     }
    // }
    // else
    // {
    //     for(int i = 0; i < ((len-1)/2) + 1; i++)
    //     {
    //         char temp = str[k];
    //         str[k--] = str[i];
    //         str[i] = temp;
    //     }
    // }
    // str[len]='\0';
     return ansR;
}

int compareAtbash (char txt[],char *atbash, int s , int e)
{
    int j=0;
    for(int i=s; i <= e; i++)
    {
        if(isalpha(txt[i]))
        {
            if(txt[i]!=atbash[j])
            {
                return 0;
            }
            else if(txt[i]==atbash[j])
            {
                j++;
            }
        }
        else if(!isalpha(txt[i]))
        {
            continue;
        }
    }
    return 1;
}


 int AtbashSequences(char *word , char *txt)
 {
    char *atbash = Atbash(word);
    char *atbashRev = Srev(atbash);
    printf("Atbash Sequences: " );
    int ansIndex=0;
    for(int i = 0; i < strlen(txt); i++)
    {
        for(int j=i; j < strlen(txt); j++)
         {
            if((isalpha(txt[i])!=0) && (isalpha(txt[j])!=0) )
            {
                if((compareAtbash(txt,atbash,i,j) == 1 || compareAtbash(txt,atbashRev,i,j) == 1) && (j-i >= strlen(word)-1) )
                {
                  if (ansIndex == 0)
                    {
                        for(int k=i; k <= j; k++)
                        {
                            printf("%c", txt[k]);
                        }
                        ansIndex++;

                    }
                    else{
                            printf("~");
                            for(int k=i; k <= j; k++)
                            {
                                printf("%c", txt[k]);
                            }

                         }
                }     

            }
        }
            

    }
    printf("\n");
    free(atbash);
    free(atbashRev); 
    return 0; 
 }

int compareAnagram(char txt[],char word[], int start,int end)
{
    int word_Anagram[128] = {0};
    int txt_Anagram[128] = {0};

    for(int i=0; i < strlen(word); i++)
    {
        if(word[i] != ' ' && word[i] != '\n' && word[i] != '\t')
        {
            char c = word[i];
            int index = (int)(c);
            word_Anagram[index]++;
        }
    }
    for(int i=start; i <= end;i++)
    {
        if(txt[i] != ' ' && txt[i] != '\n' && txt[i] != '\t')
        {
            char c = txt[i];
            int index = (int)(c);
            txt_Anagram[index]++;
        }
    }
    for(int i = 0; i < 128; i++)
    {
        if(txt_Anagram[i] != word_Anagram[i])
        {
            return 0;
        }
    }
    return 1;
}


int AnagramSequences(char *word, char *txt)
{
    printf("Anagram Sequences: " );
    int ansIndex=0;
    for(int i = 0; i < strlen(txt); i++)
    {
        for(int j=i; j < strlen(txt); j++)
         {
            if((isalpha(txt[i])!=0) && (isalpha(txt[j])!=0))
            {
             if(compareAnagram(txt,word,i,j) == 1)
             {
                  if (ansIndex == 0)
                    {
                        for(int k=i; k <= j; k++)
                        {
                            printf("%c", txt[k]);
                        }
                        ansIndex++;

                    }
                    else{
                        printf("~");
                        for(int k=i; k <= j; k++)
                        {
                             printf("%c", txt[k]);
                        }

                    }     
             }

            }
        }
            

    }
    //printf("\n");
    return 0; 

}
   



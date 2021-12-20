#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30
#define tilda 126

int gValue(char c){
    if(c >= 'A' && c <= 'Z'){
        return (c - 'A' + 1);
    }
    
    return sum;

}

int compareAnagram (char *check,char *word){
    int sort_word[128] = {0};
    int sort_check[128] = {0};
    for(int i=0; i<strlen(word);i++){
        if(word[i] != ' ' && word[i] != '\n' && word[i] != '\t'){
            char c = word[i];
            int ind = (int)(c);
            sort_word[ind]++;
        }
    }
    for(int i=0; i < strlen(check); i++){
        if(check[i] != ' ' && check[i] != '\n' && check[i] != '\t'){
            char c = check[i];
            int ind = (int)(c);
            sort_check[ind]++;
        }
    }
    for(int i=0; i<128; i++){
        if(sort_check[i] != sort_word[i]){
            return 0;
        }
    }
    return 1;
}

int AtbashSequences(char word [],char txt[]){
    return 0;
}

int AnagramSequences(char word[], char txt[])
{
    int value = Gvalue(word);
    int currIndex=0;
    int ansIndex=0;
    char ans[TXT] = {0};
    char *checkSeq;
    for(int i = 0; i < strlen(txt); i++)
    {
        currIndex=0;
        char str1[] = {txt[i],'\0'};
        if(Gvalue(str1)==0)
        {
            continue;
        }
        checkSeq[currIndex++]=txt[i];
        for(int j=i; j < strlen(txt); j++)
        {
            char str2[] ={txt[j],'\0'};
            if(Gvalue(checkSeq) + Gvalue(str2) < value)
            {
                checkSeq[currIndex++] = txt[j];
            }
            if(Gvalue(checkSeq) == value )
            {
                if ((txt[j] >=a && txt[j] <= z) || (txt[j] >= A && txt[j] <= Z))
                {
                    if (compareAnagram(checkSeq,word) == 1 )
                    {
                        for(int k=0; k<currIndex; k++)
                        {
                        ans[ansIndex++] = checkSeq[k]; 
                        }
                    }
                  ans[ansIndex++] = tilda;
                }
            
            }
        }
    }
    ans[ansIndex-1]='\0';
    printf("Anagram Sequences: %s\n" , ans);
    return 0;
}
int AnagramSequences(char word[],char txt[]){return 0;}





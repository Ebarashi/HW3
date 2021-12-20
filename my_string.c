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
                    for (int pr = i; pr <= j; pr++)
                    {
                        printf("%c", txt[pr]);
                    }
                    break;  
                } 
            }  
        }   
    }
    return 0;   
}


char *Atbash(char *Atbash)
{
    for(int i =0; i < sizeof(Atbash); i++)
    {
        if(Atbash[i] >= A && Atbash[i] <= Z)
        {
            char str[] = {Atbash[i],'\0'};
            Atbash[i] = Z - Gvalue(str) + 1;
        }
        if(Atbash[i] >= a && Atbash[i] <= z)
        {
            char str[] = {Atbash[i],'\0'};
            Atbash[i] = z - Gvalue(str) + 1;
        }
    }
    return Atbash;
}

char *Srev(char *str)
{
    int len = strlen(str);
    //str [len] = '0';
    int k = len - 1;
    if(len%2 == 0)
    {
        for(int i = 0; i < len/2; i++)
        {
            char temp = str[k];
            str[k--] = str[i];
            str[i] = temp;
        }
    }
    else
    {
        for(int i = 0; i < ((len-1)/2) + 1; i++)
        {
            char temp = str[k];
            str[k--] = str[i];
            str[i] = temp;
        }
    }
    str[len]='\0';
    return str;
}

int compareAtbash (char *check,char *atbash)
{
    int j=0;
    for(int i=0; i < strlen(atbash); i++)
    {
        if(isalpha(check[i]))
        {
            if(check[i]!=atbash[j])
            {
                return 0;
            }
            else if(check[i]==atbash[j])
            {
                j++;
            }
        }
        else if(!isalpha(check[i]))
        {
            continue;
        }
    }
    return 1;
}


int AtbashSequences(char word [],char txt[]){
    return 0;
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
    return 0;   
}




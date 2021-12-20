#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
#define A 65
#define Z 90
#define a 97
#define z 122
#define tilda 126

int Gvalue(char Mseq[])
{
    int sum = 0;
    for(int i = 0; i < strlen(Mseq); i++)
    {
        if(Mseq[i] >= A && Mseq[i] <= Z)
        {
            sum += Mseq[i]-A + 1;
        }
        else if(Mseq[i] >=a && Mseq[i] <= z)
        {
            sum += Mseq[i]-a + 1;
        }
    }
    
    return sum;

}

int Gematrias (char w[], char t[])
{
    int value = Gvalue(w);
    char ans[TXT]={0};

     for(int i = 0; i < strlen(t); i++)
     {
        char check[] = t[i];
        if(Gvalue(check) ==0 )
         {
            continue;
         }
             for(int j=i;j<strlen(t);j++)
             {
               char str[] =t[j];
               if (Gvalue(str)==0)
               {
                   continue;
               }
                if ()
                {
                    /* code */
                }
                
             }
        }
       
}



void GematriaSequences(char word[],char txt[])
{
   // char *SEQUENCE;
    int value = Gvalue(word);
    int currIndex=0;
    int ansIndex=0;
    char ans[TXT] = {0};
    char checkSeq[TXT]={0};
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
                if ((checkSeq[j] >=a && checkSeq[j] <= z) || (checkSeq[j] >= A && checkSeq[j] <= Z))
                {
                  for(int k=0; k<currIndex; k++)
                  {
                   ans[ansIndex++] = checkSeq[k]; 
                  }
                  ans[ansIndex++] = tilda;
                }
            }
        }
    }
    ans[ansIndex-1]='\0';
    printf("Gematria Sequences: %s\n" , ans);
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

char AtbashSquences(char word[],char txt[]){
    char *atbash = Atbash(word);
    char *atbashRev = Srev(atbash);
    int value = Gvalue(atbash);
    int currIndex=0;
    int ansIndex=0;
    char ans[TXT] = {0};
    char checkSeq[TXT]={0};
    for(int i = 0; i < strlen(txt); i++)
    {
        currIndex=0;
        char str1[] = {txt[i],'\0'};
        if(Gvalue(str1)==0)
        {
            continue;
        }
        if(atbash[0] == txt[i] || atbashRev[0] == txt[i] )
        {
        checkSeq[currIndex++]=txt[i];
        }
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
                    if (compare(checkSeq,atbash) == 1 || compare(checkSeq,atbashRev) == 1 )
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
    printf("Atbash Sequences: %s\n" , ans);
}

int compare (char *check,char *atbash)
{
    int j=0;
    for(int i=0; i < len(atbash); i++)
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



void swap(char *x, char *y){
    char tmp = *x;
    *x=*y;
    *y=tmp;
}
void sort(char *str){
    for(int i =0;i<strlen(str)-1;i++){
        for(int j=i+1;j<strlen(str);j++){
            if(str[i]>str[j]){
                swap(&str[i],&str[j]);
            }
        }
    }
}


int anagramSequences(){
    printf("Anagram Sequences: ");
    int tiltdaPrint = 0;
    int i = 0;
    while (txt[i] != '\0'){
        if (txt[i] != ' ' && txt[i] != '\t' && txt[i] != '\n'){
            char copy[CHECKEDWORDLEN];
            strcpy(copy, word);
            int flag = 0;
            int j = i;
            while (txt[j] != '\0' && flag == 0) {
                if (txt[j] != ' ' && txt[j] != '\t' && txt[j] != '\n'){
                    flag = -1;
                    for (int b = 0; copy[b] != '\0' && flag <= -1; b++){
                        if (txt[j] == copy[b]) {
                            copy[b] *= -1;
                            flag = 0;
                        }
                    }
                    if (flag == 0){
                        flag = 1;
                        for (int b = 0; copy[b] != '\0' && flag == 1; b++) {
                            if (copy[b] > 0) {
                                flag = 0;
                            }
                        }
                    }
                }
                ++j;
            }
            --j;
            if (flag == 1){
                if (tiltdaPrint){
                    printf("~");
                }
                for (int b = i; b <= j; b++){
                    printf("%c", txt[b]);
                }
                ++tiltdaPrint;
            }
        }
        ++i;
    }
    return 0;
}


















}
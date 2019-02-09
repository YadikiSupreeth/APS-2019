#include <stdio.h>
#include <string.h>
int len1, len2, count[1000][1000];
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int findLongest_subsequence_length(char string1[], char string2[])
{
    len1 = strlen(string1) + 1;
    len2 = strlen(string2) + 1;
    int i = 0, j = 0;
    memset(count, 0, sizeof(count[0][0]) * len1 * len2);
    for (i = 1; i < len1; i++)
    {
        for (j = 1; j < len2; j++)
        {
            if (string1[i - 1] == string2[j - 1])
            {
                count[i][j] = count[i - 1][j - 1] + 1;
            }
            else
            {
                count[i][j] = max(count[i][j - 1], count[i - 1][j]);
            }
        }
    }
    return count[len1 - 1][len2 - 1];
}
char* PrintLongest_subsequence(char string1[], char string2[],int sequence_length)
{
   int  i = strlen(string1) ;
    int j = strlen(string2) ;
    
    char seq[sequence_length+1];
    int n=sequence_length;
    seq[n--]='\0';
    while(i>0 && j>0)
    {
   
            if(string1[i-1]==string2[j-1])
                {
                    seq[n--]=string1[i-1];
                    i--;j--;
                }
            else
            {
                if(count[i-1][j]>count[i][j-1])
                {
                    i--;
                }
                else
                {
                    j--;
                }
                
            }
            

    
    }
    printf("%s\n",seq);

}

int main()
{
    char s1[] = "1211";
    char s2[] = "22";
    int count = findLongest_subsequence_length(s1, s2);
    PrintLongest_subsequence(s1,s2,count);
    printf("%d", count);
    return 0;
}
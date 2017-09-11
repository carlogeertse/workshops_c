#include <stdio.h>

int main()
{
    char word[4] = "xml";
    char reverse[4];
    int j = 0;
    for(int i = sizeof(word)-1; i--; i==0){
        reverse[j] = word[i];
        j++;
    }
    printf(reverse);
    return 0;
}
#include <ctype.h>
#include <stdio.h>
#include <string.h>
 
char* ReFormatString(char* S, int K){
    // create a temporary string to store
    // the alphanumeric characters only
    char temp[100];
    int n = strlen(S);
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] != '-') {
            temp[len++] = toupper(S[i]);
        }
    }
 
    // string ans is created to store
    // the final string.
    char* ans
        = (char*)malloc(sizeof(char) * (len + len / K + 1));
    int val = K;
    int j = 0;
 
    // iterate over the string from right
    // to left and start pushing
    // characters at an interval of K
    for (int i = len - 1; i >= 0; i--) {
        if (val == 0) {
            val = K;
            ans[j++] = '-';
        }
        ans[j++] = temp[i];
        val--;
    }
 
    // reverse the final string and
    // return it.
    ans[j] = '\0';
    int i = 0, k = j - 1;
    while (i < k) {
        char t = ans[i];
        ans[i++] = ans[k];
        ans[k--] = t;
    }
    return ans;
}
 

int main() {
    char s[] = "bkl-lepe-odacarmospgha";
    int K = 4;
 
    // function call
    printf("%s", ReFormatString(s, K));
    return 0;
}

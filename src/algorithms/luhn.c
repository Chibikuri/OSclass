#include<stdio.h>
#include<string.h>

int main(void){
    char *s = "555555555555555444444";
    int i, d, w = 1, t = 0;

    for(i = strlen(s)-1; i >= 0;i--){
        d = w*(s[i] - '0');
        if(d > 9) { d -= 9; };
        t += d;
        w = 3 - w;
    }
    if (t%10 == 0){ 
        print(f("ok\n"); 
    } else {
        print(f("no\n");
    };
    return 0;
}
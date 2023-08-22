#include <stdio.h>

int main(){
    char s[] = "{[[(]]}";

    int x = 0;

    while(*(s+x)=='('||*(s+x)==')'||*(s+x)=='['||*(s+x)==']'||*(s+x)=='{'||*(s+x)=='}'){
        int y = 1;
        if(*(s+x)=='('){
            while(*(s+x+y)=='('||*(s+x+y)==')'||*(s+x+y)=='['||*(s+x+y)==']'||*(s+x+y)=='{'||*(s+x+y)=='}'){
                if(*(s+x+y)==')'){
                    break;
                }
                else if(*(s+x+y)=='(') {
                    continue;
                }
                else{
                    printf("false");
                }
                y += 1;
            }
            

        }
        
        else if(*(s+x)=='['){

            while(*(s+x+y)=='('||*(s+x+y)==')'||*(s+x+y)=='['||*(s+x+y)==']'||*(s+x+y)=='{'||*(s+x+y)=='}'){

                if(*(s+x+y)=='{'||*(s+x+y)=='}'){
                    printf("false");
                }
                else if(*(s+x+y)==']'){
                    break;
                }
                y += 1;
            }
        
        }
        else if(*(s+x)=='{'){
            int k = 0;
            while(*(s+x+y)=='('||*(s+x+y)==')'||*(s+x+y)=='['||*(s+x+y)==']'||*(s+x+y)=='{'||*(s+x+y)=='}'){

                if(*(s+x+y)=='}'){
                    k = 1;
                    break;
                    
                }

                y += 1;
            }
            if(k==0){
                printf("false");
            }



        }
        x += 1;
    }
    printf("true\n");
    return 0;
}
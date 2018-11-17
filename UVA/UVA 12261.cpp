/*
Description of the topic:
When the game sets its own name, the default fields are all 'A', then the current position is at the far left, use the arrow keys to convert it to the target name. After going to the destination, you can change the character of the current position. Move forward or move backwards (here is the ring 'A'-'Z'), and to the left and right is to change the next character (the position is also ring, left to the right) The final stop position is not limited. 
What is the minimum number of operations? 

Problem Solving:
Basically, the modified character is irrelevant to the moving position, and it will be adjusted to the correct character after a certain position. 
Then the title is converted to cover the position to be modified with a minimum number of steps. 
Divided into four possible considerations. 
 1 is to be modified, the rest is not modified, that is, the position of the target name is 'A' 

1) All the way to the right to be modified 
....1.....1 .... 1 ... 1 ... 
>>>>>>>>>>>>>>>>>>>>>>>>>> 

2) All the way to the left to be modified 
....1.....1 .. .. 1 ... 1 ... 
<<<<<<<<<<<<<<<<<<<<<<<<< 

3) turns to the right on the left , adjacent to find any Modify this action
....1.....



4) Zigzag first to the left and to the right , find any adjacent to modify this action
....1.....1 ....   .... 1....1...1. .. 
<<<<<<<<< 
>>>>>>>>>>>>>>>>>>>>>>>> >>>>>>>>
*/
 #include<stdio.h>
 #include<algorithm>
 #include<string.h>
 using namespace std;
 int main(){
    int testcase;
    char s[1005];
    int cost[1005];
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%s", s);
        int n = strlen(s);
        int ret = 0, dp = 0;
        int i, j, k;
        for(i=0;i<n;i++){
            cost[i]=min(s[i]-'A',26-(s[i]-'A'));
            ret+=cost[i];
        }
        if(ret==0){
            puts("0");
            continue;
        }
        int pre=-1,count=0;
        for(i=0;i<n;i++){
            if(cost[i]){
                count++;
                if(pre==-1){
                    pre=i;
                    dp=n-i;
                }else{
                    if(dp==0)dp=0xfffffff;
                    dp=min(dp,pre+pre+n-i);
                    dp=min(dp,n-i+n-i+pre);
                    pre=i;
                }
            }
        }
        if(count==1)dp=min(pre,n-pre);
        dp = min(dp,pre);
        printf("%d\n",ret+dp);
    }
    return 0;
}

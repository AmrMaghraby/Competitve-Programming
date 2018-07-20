 ///IN THE NAME OF ALLAH
 #include<stdio.h>
 int main(){
    int n, k, v[1024];
    while (scanf("%d %d", &n, &k) != EOF){
        int i, vk, max = 0, min = 0, count = 1, total = 1 << n;
        for (i = 0; i < total; i++) scanf("%d", &v[i]);
        vk = v[k];
        for (i = 0; i < total; i++)
            if (v[i] < vk) count++;
        if (count == total)
            max = min = n;
        else{
            while (1 << max <= count)
                max++;
            max--;
        }
        printf("%d %d\n", min, max);
    }
    return 0;
 }

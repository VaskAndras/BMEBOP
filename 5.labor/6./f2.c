int main(){
    int a[10];
    for(int i=0;i<10;i++){
        printf("Please enter the %d. number: ",i+1);
        scanf("%d",&a[i]);
    }
    int c = 0;
    for (int i = 0 ;i < 9; i++){
        if (a[i] > a[i+1]){
            c++;
        }
        if  (a[i] < a[i+1]){
            c--;
        } 
    }
    if (c == 9){
        printf("The array is strictly decreasing.\n");
    }
    else if (c == -9){
        printf("The array is strictly increasing.\n");
    }
    else {
        printf("The array is unordered.\n");
    }
    return 0;
}


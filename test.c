int main(){
int a=1;
int b=2;
int* p1=&a;
int* p2=&b;
p1=p2;
printf("%d,%d",*p1,*p2);
return 0;
}

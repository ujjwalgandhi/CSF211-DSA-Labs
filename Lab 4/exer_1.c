#include<stdio.h>
void p();
void g();
void h();
void d();
int bits;

int main(){
    printf("%u\n", &bits);
    p();
    g();
    h();
    d();
    return 0;
}

void p(){
    int pilani;
    printf("%u\n", &pilani);
    // g();
    return;
}

void g(){
    int goa;
    printf("%u\n", &goa);
    // h();
    return;
}

void h(){
    int hyd;
    printf("%u\n", &hyd);
    // d();
    return;
}

void d(){
    int dubai;
    printf("%u\n", &dubai);
    return;
}
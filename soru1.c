#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void listyaz(int liste[],int uzunluk)
{
    for (int i=0; i<uzunluk ;i++)
    {
        printf("%d\n",liste[i]);
    }
}

void insertion(int liste[],int len) {
    int gecici;
    for(int i =0;i<len;i++){
        for(int j=1;j<len;j++){
            if(liste[j]<liste[j-1]){
                gecici=liste[j-1];
                liste[j-1]=liste[j];
                liste[j]=gecici;
            }
        }
    }
    }
    
void selection(int liste[],int len){
    for (int i = 0; i< len - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j <len; j++)
            if (liste[j] < liste[index])
                index = j;
        int smallerNumber = liste[index];
        liste[index] = liste[i];
        liste[i] = smallerNumber;
    }
}


long long zaman_farki_bul(struct timespec bas, struct timespec bitis)
{
    long long bas_zaman = bas.tv_sec * 1e9 + bas.tv_nsec;
    long long bitis_zaman = bitis.tv_sec * 1e9 + bitis.tv_nsec;
    return bitis_zaman - bas_zaman;
}

double nanosaniyeyi_saniyeye_cevir(long long zaman)
{
    return (double)zaman / 1.0e9;
}

#define DIZI_UZUNLUK 500
void main(){
    struct timespec start = {0};
    struct timespec end = {0};

    int insal[DIZI_UZUNLUK],selal[DIZI_UZUNLUK],sayi,min=0,max=1000;
    srand(time(NULL));
    for(int i =0;i<=DIZI_UZUNLUK;i++){
        sayi = rand()% (max-min +1)+min;
        insal[i]=sayi;
        selal[i]=sayi;
    }

    clock_gettime(CLOCK_MONOTONIC, &start);
    insertion(insal,DIZI_UZUNLUK);
    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("insertion sort hesaplama süresi %f saniye\n", nanosaniyeyi_saniyeye_cevir(zaman_farki_bul(start, end)));

    clock_gettime(CLOCK_MONOTONIC, &start);
    selection(selal,DIZI_UZUNLUK);
    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("selection sort hesaplama süresi %f saniye\n", nanosaniyeyi_saniyeye_cevir(zaman_farki_bul(start, end)));
}

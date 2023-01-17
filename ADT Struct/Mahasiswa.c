#include <stdio.h>
#include <string.h>
typedef struct{
    int nim;
    char nama[100];
    char kelas[2];
    int umur;


}mahasiswa;
int main(){
    mahasiswa aku;
    mahasiswa sebelah;
    mahasiswa sebelah2;
    int a;
    int b;
printf("Apakah ada mahasiswa disebelah kiri anda ada orang tulis dengan 1 dan 0 jika tdk ada orang \n");
scanf("%i",&a);
getchar() != '\n';
printf("Apakah ada mahasiswa disebelah kanan anda ada orang tulis dengan 1 dan 0 jika tdk ada orang \n");
scanf("%i",&b);
getchar() != '\n';
printf("Masukan nim-nama-umur-kelas untuk nama pribadi berurutan! :\n");
scanf("%i",&aku.nim);
getchar() != '\n';
scanf("%s",&aku.nama);
getchar() != '\n';
scanf("%i",&aku.umur);
getchar() != '\n';
scanf("%s",&aku.kelas);
getchar() != '\n';
if(a == 1 ){
printf("Masukan nim-nama-kelas untuk nama orang sebelah kiri berurutan!: \n");
scanf("%i",&sebelah.nim);
getchar() != '\n';
scanf("%s",&sebelah.nama);
getchar() != '\n';
scanf("%i",&sebelah.umur);
getchar() != '\n';
scanf("%s",&sebelah.kelas);
getchar() != '\n';
}
else{
    sebelah.nim = 0;
    strcpy(sebelah.nama, "");
    sebelah.umur = 0;
    strcpy(sebelah.kelas,"");
}
if(b == 1){
printf("Masukan nim-nama-kelas untuk nama orang sebelah kanan berurutan! :\n");
scanf("%i",&sebelah2.nim);
getchar() != '\n';
scanf("%s",&sebelah2.nama);
getchar() != '\n';
scanf("%i",&sebelah2.umur);
getchar() != '\n';
scanf("%s",&sebelah2.kelas);
getchar() != '\n';
}
else{
    sebelah2.nim = 0;
    strcpy(sebelah2.nama, "");
    sebelah2.umur = 0;
    strcpy(sebelah2.kelas,"");
}

printf("\n");
printf("Data Mahasiswa saya: %i-%s-%i-%s \n",aku.nim,aku.nama,aku.umur,aku.kelas);
printf("Data Mahasiswa sebelah kiri : %i-%s-%i-%s \n",sebelah.nim,sebelah.nama,sebelah.umur,sebelah.kelas);
printf("Data Mahasiswa sebelah kanan: %i-%s-%i-%s \n",sebelah2.nim,sebelah2.nama,sebelah2.umur,sebelah2.kelas);

return 0;


}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fungsi di admin
void papandonasi();
// fungsi di user
void donasi(),Dompet(),topup(),withdraw(),main(),pengunjung(),menu_pengunjung(),login_pengunjung(),regis_pengunjung();
//pointer 
FILE *f_user;
//struct
struct user{
    char nama[50];
    int saldo;
}user,masuk,daftar,sumbang;

//variabel global
int menu,uang,i;
char nama[50];

void main(){
    system("cls");
    printf("1. donasi\n2. Dompet\n3. Papan donasi\n");
    printf("Pilih menu : "); scanf("%d",&menu);
    switch(menu){
        case 1 : donasi(); break;
        case 2 : Dompet(); break;
        case 3 : papandonasi(); break;
        default : printf("\nMenu Tidak Tersedia"); getchar(); break;
        }     
}
void donasi(){
    system("cls");
	printf(" ==== DONASI ====\n");
	printf("Saldo \t\t: %d\n",masuk.saldo);
	printf("Donasi sebesar \t\t: ");scanf("%d",&uang);
	getchar();
	if(uang > 0 && masuk.saldo >= uang){
		f_user = fopen("User.txt","rb+");
		while(fread(&user,sizeof(user),1,f_user) == 1){
				sumbang.saldo += uang;
                user.saldo -= uang;
				masuk.saldo = sumbang.saldo;
                masuk.saldo = user.saldo;
				fwrite(&user,sizeof(user),1,f_user);
				break;
		}
		fclose(f_user);
		printf("Donasi Berhasil!!!\n");
		getchar();
	}
	else{
		printf("Donasi Gagal!!!\n");
		getchar();
	}
	return main();
}

void Dompet(){
    system("cls");
    f_user = fopen("User.txt","rb+");
    printf("=====JUDUL NYA HEADER CEUNAH ======\n");
    printf("Dompet\t: %d\n",masuk.saldo);
    printf("Silahkan pilih menu berikut\n");
    printf("[1]. Top Up\n[2]. Withdraw\n[3]. Kembali\n");
    printf("Pilih Menu\t: "); scanf("%d",&menu); fflush(stdin);
    switch (menu)
    {
    case 1 : topup(); break;
    case 2 : withdraw(); break;
    case 3 : main(); break;
    default: printf("\nMenu Tidak Tersedia"); getchar(); break;
    }
}

void topup(){
    system("cls");
	printf(" ==== TOP UP ====\n");
	printf("Saldo \t\t: %d\n",masuk.saldo);
	printf("Nominal\t\t: ");scanf("%d",&uang);
	getchar();
	if(uang > 0){
		f_user = fopen("User.txt","rb+");
		while(fread(&user,sizeof(user),1,f_user) == 1){
				user.saldo += uang;
				masuk.saldo = user.saldo;
				fwrite(&user,sizeof(user),1,f_user);
				break;
		}
		fclose(f_user);
		printf("Top Up Berhasil!!!\n");
		getchar();
	}
	else{
		printf("Top Up Gagal!!!\n");
		getchar();
	}
	return main();
}

void withdraw(){
    system("cls");
    printf(" ==== WALLET WITHDRAWAL ====\n");
	printf("Saldo\t\t: %d\n",masuk.saldo);
	printf("Penarikan\t: ");scanf("%d",&uang);
	getchar();
	if(uang > 0 && masuk.saldo >= uang){
		f_user = fopen("User.txt","rb+");
		while(fread(&user,sizeof(user),1,f_user) == 1){
				user.saldo -= uang;
				masuk.saldo = user.saldo;
				fwrite(&user,sizeof(user),1,f_user);
				break;
		}
		fclose(f_user);
		printf("Penarikan Berhasil!!!");
		getchar();
	}
	else{
		printf("Penarikan Gagal!!!");
		getchar();
	}
	return main();
}

void papandonasi(){
   system("cls");
	printf(" ==== PAPAN DONASI ====\n");
	printf("Donasi Terkumpul \t\t: %d\n",masuk.saldo);
	printf("List Doonatur\n");
		f_user = fopen("User.txt","rb");
		while(fread(&user,sizeof(user),1,f_user) == 1){
	        printf("\n%d. Nama Donatur\t: %s\n",i+1,user.nama);
            printf("   Donasi Sebesar\t: %d\n",sumbang.saldo);
				break;
		}
		fclose(f_user); system("pause");
	return main();
}
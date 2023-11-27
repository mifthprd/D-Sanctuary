//Header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Batas Percobaan Login
int batas = 3;

//Struct
struct Admin{
    char username[50], pass[50];
}admin;

struct Pengunjung{
    char username[50], pass[50], nama[50], alamat[50], telp[50];
    int saldo;
}pengunjung,masuk;

//Prototype Fungsi
void title();
void menu();
void menu_login();
void menu_register();
int cek_pengunjung(char *);
int login_pengunjung(int);
int login_admin(int);
void menu_pengunjung();
void info_pengunjung();
void bayar_pengunjung();
void etiket_pengunjung();
void daftar_pengunjung();
void donasi_pengunjung();
int dompet_pengunjung();
int topup();
int withdraw();

// file pointer
FILE *file_pengunjung;
FILE *file_admin;
FILE *f_pengunjung;

//variabel global
int pilihan,keluar,uang;
char username[20], pass[20];

//Fungsi Utama
int main(){
    title();
    menu();
}

//Title Screen
void title() {
  system("cls");
  printf("==================================\n");
  printf("===========D'SANCTUARY============\n");
  printf("==================================\n");
}

//Menu
void menu() {
  fflush(stdin);
  printf("=== Menu ===\n 1. Login\n 2. Register\n 3. Keluar\n");
  printf("Masukkan Pilihan (1-3): ");
  scanf("%d", &pilihan);
  switch (pilihan) {
  case 1:
    menu_login();
    break;

  case 2:
    menu_register();
    break;

  case 3:
    system("cls");
    printf("=== Apakah anda yakin ingin keluar? ===\n 1. Ya\n 2. Tidak\n");
    printf("Masukkan Pilihan (1-2): ");
    scanf("%d", &keluar);
    switch (keluar) {
    case 1:
      system("cls");
      printf("Terima Kasih telah menggunakan D'Sanctuary\n");
      exit(0);
      break;

    case 2:
      system("cls");
      title();
      menu();
      break;

    default:
      system("cls");
      printf("Angka yang dimasukkan invalid, silahkan coba kembali\n");
      system("pause");
      title();
      menu();
    }

  default:
      system("cls");
      printf("Angka yang dimasukkan invalid, silahkan coba kembali\n");
      system("pause");
      title();
      menu();
  }
}

//Menu Login
void menu_login(){
  fflush(stdin);
  system("cls");
  printf("=== Login Sebagai? ===\n 1. Admin\n 2. Pengunjung\n 3. Back\n");
  printf("Masukkan Pilihan (1-3): ");
  scanf("%d", &pilihan);
  switch (pilihan){
  case 1:
    login_admin(batas);
    break;

  case 2:
    login_pengunjung(batas);
    break;

  case 3:
    title();
    menu();
    break;

  default:
    system("cls");
    printf("Angka yang dimasukkan invalid, silahkan coba kembali\n");
    system("pause");
    menu_login();
    break;
  }
}

//Login Admin
int login_admin(int batas){
    fflush(stdin);
    system("cls");
    printf("=== Silahkan Login ===\n\n");
    printf("Username :"); gets(admin.username);
    printf("Password :"); gets(admin.pass);
    if(strcmp(admin.username,"admin")==0 && strcmp(admin.pass,"admin123")==0){
        printf("Login berhasil!\n");
        system("pause");
        } 
    else{
        printf("Login gagal, %d cobaan lagi.\n", batas - 1);
        if (batas > 1){
            system("pause");
            return login_admin(batas - 1);
            } 
        else{
            printf("Kesempatan login habis.\n");
            system("pause");
            title();
            menu();
            }
        }
        return 0;
  
}

//Registrasi Pengunjung
void menu_register(){
    system("cls");
    f_pengunjung = fopen("pengunjung.dat", "ab");

    if (f_pengunjung == NULL) {
        printf("File gagal dibuka.\n");
        return;
    }

    printf("=== Register Pengunjung ===\n");
    printf("Username: ");
    fflush(stdin);
    gets(pengunjung.username);

    if (cek_pengunjung(pengunjung.username)) {
        fclose(f_pengunjung);
        printf("Username sudah terdaftar. Silahkan coba dengan username lain.\n");
        system("pause");
        menu_register();
        return;
    }

    printf("Password: ");
    fflush(stdin);
    gets(pengunjung.pass);
    pengunjung.saldo = 0.0;
    system("cls");
    printf("===Masukkan Identitas Anda===\n");
    printf("Nama: ");
    gets(pengunjung.nama);
    printf("Alamat: ");
    gets(pengunjung.alamat);
    printf("No. Telepon: ");
    gets(pengunjung.telp);
    fwrite(&pengunjung, sizeof(pengunjung), 1, f_pengunjung);

    fclose(f_pengunjung);
    printf("Registrasi sukses.\n");
    system("pause");
    title();
    menu();
}

//Cek Username Pengunjung
int cek_pengunjung(char *username) {
  FILE * file = fopen("pengunjung.dat", "rb");
  
  if (file == NULL) {
    printf("File gagal dibuka.\n");
    return 0;
  }
  
  struct Pengunjung pengunjung;
  while (fread( &pengunjung, sizeof(struct Pengunjung), 1, file) == 1) {
    if (strcmp(pengunjung.username, username) == 0) {
      fclose(file);
      return 1;
    }
  }

  fclose(file);
  return 0;
}

//Login Pengunjung
int login_pengunjung(int batas){
  system("cls");
  f_pengunjung = fopen("pengunjung.dat", "rb");

  if (f_pengunjung == NULL) {
    printf("Tidak ada data pengunjung, silahkan coba lagi.\n");
    system("pause");
    title();
    menu();
    return 0;
  }

  printf("=== Login Pengunjung ===\n");
  printf("Username: ");
  scanf("%s", username);
  printf("Password: ");
  scanf("%s", pass);

  while (fread(&pengunjung, sizeof(struct Pengunjung), 1, f_pengunjung) == 1){
    if (strcmp(pengunjung.username, username) == 0 && strcmp(pengunjung.pass, pass) == 0){
      fclose(f_pengunjung);
      printf("Login sukses.\n");
      system("pause");
      title();
      menu_pengunjung();
    }
  }

  fclose(f_pengunjung);
  printf("Login Gagal, %d kali percobaan lagi.\n", batas - 1);
  if (batas > 1) {
    system("pause");
    return login_pengunjung(batas - 1);
  } else {
    printf("Percobaan Login sudah habis.\n");
    system("pause");
    title();
    menu();
  }

  return 0;
}

//menu_Pengunjung
void menu_pengunjung(){
  int pilihan;
  system("cls");
  title();
  printf("\nSilahkan Pilih Menu Berikut\n");
	printf(" [1] Pencarian info\n [2] Pembayaran Tiket\n [3] E-tiket\n [4] Daftar Relawan\n [5] Donasi\n [6] Saldo\n [7] Logout\n");
	printf("\nMasukkan Pilihan : "); 
	scanf("%d",&pilihan); fflush(stdin);
	switch(pilihan){
		case 1 :
			info_pengunjung();
			break;
		case 2 :
			bayar_pengunjung();
			break;
		case 3 :
			etiket_pengunjung();
      break;
		case 4 :
			daftar_pengunjung();
      break;
		case 5 :
			donasi_pengunjung();
      break;
		case 6 :
			dompet_pengunjung();
      break;
		case 7 :
			menu_pengunjung();
			break;
		default :
			printf("\nMenu Tidak Tersedia");
			getchar();
			menu_pengunjung();
}
}

void info_pengunjung(){

}

void bayar_pengunjung(){

}

void etiket_pengunjung(){

}

void daftar_pengunjung(){

}

void donasi_pengunjung(){

}

int dompet_pengunjung(){
    system("cls");
    f_pengunjung = fopen("pengunjung.dat", "rb");
    printf("=====DOMPETKU ======\n");
    printf("Dompet\t: %d\n",masuk.saldo);
    printf("Silahkan pilih menu berikut\n");
    printf("[1]. Top Up\n[2]. Withdraw\n[3]. Kembali\n");
    printf("Pilih Menu\t: "); scanf("%d",&pilihan); fflush(stdin);
    switch (pilihan)
    {
    case 1 : topup(); break;
    case 2 : withdraw(); break;
    case 3 : menu_pengunjung(); break;
    default: printf("\nMenu Tidak Tersedia"); getchar(); break;
    }
}

int topup(){
  system("cls");
	printf(" ==== TOP UP ====\n");
	printf("Saldo \t\t: %d\n",masuk.saldo);
	printf("Nominal\t\t: ");scanf("%d",&uang);
	getchar();
	if(uang > 0){
		f_pengunjung = fopen("pengunjung.dat","rb+");
		while(fread(&pengunjung,sizeof(pengunjung),1,f_pengunjung) == 1){
        if(strcmp(pengunjung.username,masuk.username) == 0){
				pengunjung.saldo += uang;
				masuk.saldo = pengunjung.saldo;
				fwrite(&pengunjung,sizeof(pengunjung),1,f_pengunjung);
				break;
		}
    }
		fclose(f_pengunjung);
		printf("Top Up Berhasil!!!\n");
		getchar();
	}
	else{
		printf("Top Up Gagal!!!\n");
		getchar();
	}
	return dompet_pengunjung();
}

int withdraw(){
  system("cls");
	printf(" ==== WITHDRAW ====\n");
	printf("Saldo \t\t: %d\n",masuk.saldo);
	printf("Nominal\t\t: ");scanf("%d",&uang);
	getchar();
	if(uang > 0 && masuk.saldo >= uang){
		f_pengunjung = fopen("pengunjung.dat","rb+");
		while(fread(&pengunjung,sizeof(pengunjung),1,f_pengunjung) == 1){
        if(strcmp(pengunjung.username,masuk.username) == 0){
				pengunjung.saldo -= uang;
				masuk.saldo = pengunjung.saldo;
				fwrite(&pengunjung,sizeof(pengunjung),1,f_pengunjung);
				break;
		}
    }
		fclose(f_pengunjung);
		printf("Penrikan Berhasil!!!\n");
		getchar();
	}
	else{
		printf("Penarikan Gagal!!!\n");
		getchar();
	}
	return dompet_pengunjung();
}

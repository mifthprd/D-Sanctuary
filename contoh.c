#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Utama
void MenuUtama(void);

//Penjual
void MenuPenjual(void);
void LoginPenjual(void);
void DaftarPenjual(void);
void DashboardPenjual(void);
void TokoPembeli(void);
void TambahKeyboard(void);
void TambahAksesoris(void);
void Konfirmasi(void);

struct Penjual{
    char nama[50], password[50], toko[50], email[50], kota[50], konfirmasi[50];
    int harga;
} dataPenjual, data2[100], temp;

struct Keyboard{
    char namatoko[50], namaKeyboard[50], tipe[50], tipeswitch[50], lube[50], namapembeli[50], password[50];
    int harga;
} keyboard, keyboard2[100], temp2;

struct Aksesoris{
    char nama[50], profilkeycaps[50], namatoko[50], namapembeli[50];
    int harga, klasifikasi;
} aksesoris, aksesoris2[100], temp3;

//Pembeli
void MenuPembeli(void);
void LoginPembeli(void);
void DaftarPembeli(void);
void DashboardPembeli(void);
void TopupSaldo(void);
void Magazine(void);
void Riwayat(void);

struct Pembeli{
    char nama[50], password[50], email[50], alamat[50], notel[50], konfirmasi[50];
    int saldo;
} dataPembeli;

//Admin
char emailadmin[50] = {"admin"};
char passwordadmin[50] = {"123*"};
void LoginAdmin(void);
void DashboardAdmin(void);
void ListPenjual(void);
void ListBarangPenjual(void);
void HapusPenjual(void);
void HapusBarangPenjual(void);

int main()
{
    MenuUtama();

    return 0;
}

void MenuUtama(void)
{
    int pilihanUtama;
    char konfirmasi;

    system("cls");
    printf("\n ,---,---,---,---,---,---,---,---,---,---,---,---,---,-------, ");
    printf("\n |   |   |   |   |   |   |   |   |   |   |   |   |   |       | ");
    printf("\n |---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----| ");
    printf("\n |  -> | S | E | L | A | M | A | T |   |   |   |   |   |     | ");
    printf("\n |-----',--',--',--',--',--',--',--',--',--',--',--',--'|    | ");
    printf("\n |      | D | A | T | A | N | G |   | K | E |   |   |   |    | ");
    printf("\n |----,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'---'----| ");
    printf("\n |    |   | D | ' | K | E | Y | B | O | A | R | D | <-       | ");
    printf("\n |----'-,-',--'--,'---'---'---'---'---'---'-,-'---',--,------| ");
    printf("\n |      |  |     |                          |      |  |      | ");
    printf("\n '------'--'-----'--------------------------'------'--'------' ");
    printf("\n\n\t\t1. Login/Daftar sebagai PENJUAL");
    printf("\n\t\t2. Login/Daftar sebagai PEMBELI");
    printf("\n\t\t3. Login sebagai ADMIN");
    printf("\n\t\t4. Keluar");
    printf("\n\t\tPilih salah satu opsi:\t");
    scanf("%d", &pilihanUtama);

    switch(pilihanUtama){
        case 1:
            MenuPenjual();
            break;
        case 2:
            MenuPembeli();
            break;
        case 3:
            LoginAdmin();
            break;
        case 4:
            system("cls");
            printf("\n ,---,---,---,---,---,---,---,---,---,---,---,---,---,-------, ");
            printf("\n |   |   |   |   |   |   |   |   |   |   |   |   |   |       | ");
            printf("\n |---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----| ");
            printf("\n |  -> | T | E | R | I | M | A |   | K | A | S | I | H |     | ");
            printf("\n |-----',--',--',--',--',--',--',--',--',--',--',--',--'|    | ");
            printf("\n |      | T | E | L | A | H |   | P | A | K | A | I |   |    | ");
            printf("\n |----,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'---'----| ");
            printf("\n |    |   | D | ' | K | E | Y | B | O | A | R | D | <-       | ");
            printf("\n |----'-,-',--'--,'---'---'---'---'---'---'-,-'---',--,------| ");
            printf("\n |      |  |     |                          |      |  |      | ");
            printf("\n '------'--'-----'--------------------------'------'--'------' \n");
            break;
        default:
            printf("Opsi tidak ada!\n");
            MenuUtama();
    }
}

void MenuPenjual(void)
{
    int pilihanPenjual;

    system("cls");
    printf("===============================================================");
    printf("\n\t\t    M E N U   P E N J U A L");
    printf("\n===============================================================");
    printf("\n\t\t    1. Login sebagai PENJUAL");
    printf("\n\t\t    2. Daftar sebagai PENJUAL");
    printf("\n\t\t    3. Kembali ke menu utama");
    printf("\n\t\t    Pilih salah satu opsi: ");
    scanf("%d", &pilihanPenjual);

    switch(pilihanPenjual){
        case 1:
            LoginPenjual();
            break;
        case 2:
            DaftarPenjual();
            break;
        case 3:
            MenuUtama();
            break;
        default:
            printf("Opsi tidak ada!\n");
            MenuPenjual();
    }
}

void LoginPenjual(void)
{
    FILE *fpLoginPenjual;
    fpLoginPenjual = fopen("DataPenjual.dat","rb");

    char loginPenjual[50], loginPassword[50];
    int i=3, ada=0;
    
    system("cls");
    printf("===============================================================");
    printf("\n\t\t   L O G I N   P E N J U A L");
    printf("\n===============================================================");
    printf("\nEMAIL\t : ");
    fflush(stdin); gets(loginPenjual);

    while(fread(&dataPenjual, sizeof(dataPenjual), 1, fpLoginPenjual)==1){
        if(strcmp(loginPenjual, dataPenjual.email)==0){
            ada = 1;
            while(i>0){
                printf("PASSWORD : ");
                gets(loginPassword);
                if(strcmp(loginPassword, dataPenjual.password)==0){
                    DashboardPenjual();
                    break;
                }else if(strcmp(loginPassword, dataPenjual.password)!=0){
                    printf("Password atau Email salah! Silahkan coba lagi! Anda mempunyai %d kesempatan lagi!\n", i-1);
                    i--;
                }
            }
            if(i==0){
                MenuUtama();
            }
        }
    }

    if(!ada){
        printf("Email tidak terdaftar!\n");
        system("pause");
        MenuPenjual();
    }

    fclose(fpLoginPenjual);
}

void DaftarPenjual(void)
{
    FILE *fpDaftarPenjual;
    fpDaftarPenjual = fopen("DataPenjual.dat","ab");

    system("cls");
    printf("===============================================================");
    printf("\n\t\t  D A F T A R     P E N J U A L");
    printf("\n===============================================================");
    printf("\nNama Lengkap\t\t: ");
    fflush(stdin); gets(dataPenjual.nama);
    printf("Nama Toko\t\t: ");
    gets(dataPenjual.toko);
    printf("Kota Asal\t\t: ");
    gets(dataPenjual.kota);
    printf("Alamat Email\t\t: ");
    gets(dataPenjual.email);
    printf("Password\t\t: ");
    gets(dataPenjual.password);
    printf("Konfirmasi Password\t: ");
    gets(dataPenjual.konfirmasi);

    if(strcmp(dataPenjual.password, dataPenjual.konfirmasi)==0){
        fwrite(&dataPenjual, sizeof(dataPenjual), 1, fpDaftarPenjual);
        printf("Pendaftaran anda berhasil!\n");
        system("pause");
    } else if(strcmp(dataPenjual.password, dataPenjual.konfirmasi)!=0){

        printf("Konfirmasi Password Salah! Silahkan coba lagi!\n");
        system("pause");
        DaftarPenjual();
    }

    fflush(fpDaftarPenjual);
    fclose(fpDaftarPenjual);

    MenuUtama();
}

void DashboardPenjual(void)
{
    int pilihan;

    system("cls");
    printf("===============================================================");
    printf("\n\t\t  S E L A M A T   D A T A N G\n\t\t  %s", dataPenjual.nama);
    printf("\n===============================================================");
    printf("\n\t\t1. List barang di tokomu");
    printf("\n\t\t2. Tambah keyboard ke tokomu");
    printf("\n\t\t3. Tambah aksesoris ke tokomu");
    printf("\n\t\t4. Konfirmasi pembelian");
    printf("\n\t\t5. Kembali ke menu utama");
    printf("\n\t\tPilih salah satu opsi: ");
    scanf("%d", &pilihan);

    switch(pilihan){
        case 1:
            system("cls");
            TokoPembeli();
            break;
        case 2:
            system("cls");
            TambahKeyboard();
            break;
        case 3:
            system("cls");
            TambahAksesoris();
            break;
        case 4:
            system("cls");
            Konfirmasi();
            break;
        case 5:
            system("cls");
            MenuUtama();
            break;
        default:
            printf("Opsi tidak ada!");
            DashboardPenjual();
    }
}

void TokoPembeli(void)
{
    FILE *fpDataPenjual;
    FILE *fpKeyboard;
    FILE *fpAksesoris; 

    fpDataPenjual = fopen("DataPenjual.dat","rb");
    fpKeyboard = fopen("DataProduk.dat","rb");
    fpAksesoris = fopen("DataAksesoris.dat","rb");

    char kembali[50];
    int i=0, j=0;

    system("cls");
    printf("===============================================================");
    printf("\n\t\t    T O K O   P E N J U A L");
    printf("\n===============================================================");
    printf("\nProduk Toko %s: ", keyboard.namatoko);
    printf("\n1) Keyboard");
    while(fread(&keyboard, sizeof(keyboard), 1, fpKeyboard)==1){
        if(strcmp(keyboard.namatoko, dataPenjual.toko)==0){
            printf("\n%d. Nama Keyboard : %s", i+1, keyboard.namaKeyboard);
            printf("\n   Tipe Keyboard : %s", keyboard.tipe);
            printf("\n   Tipe Switch\t : %s", keyboard.tipeswitch);
            printf("\n   Lube\t\t : %s", keyboard.lube);
            printf("\n   Harga\t : Rp%d\n", keyboard.harga);
            i++;
        }
    }

    printf("\n2) Aksesoris");
    while(fread(&aksesoris, sizeof(aksesoris), 1, fpAksesoris)==1){
        if(strcmp(aksesoris.namatoko, dataPenjual.toko)==0){
            if(aksesoris.klasifikasi == 1){
                printf("\n%d. Nama Keycaps\t : %s", j+1, aksesoris.nama);
                printf("\n   Profil Keycaps: %s", aksesoris.profilkeycaps);
                printf("\n   Harga\t : Rp%d\n", aksesoris.harga);
                j++;
            } else if(aksesoris.klasifikasi == 2){
                printf("\n%d. Nama Numpad\t : %s", j+1, aksesoris.nama);
                printf("\n   Harga\t : Rp%d\n", aksesoris.harga);
                j++;
            } else if(aksesoris.klasifikasi == 3){
                printf("\n%d. Nama Handrest : %s", j+1, aksesoris.nama);
                printf("\n   Harga\t : Rp%d\n", aksesoris.harga);
                j++;
            } else if(aksesoris.klasifikasi == 4){
                printf("\n%d. Nama Kabel\t : %s", j+1, aksesoris.nama);
                printf("\n   Harga\t : Rp%d\n", aksesoris.harga);
                j++;
            }
        }
    }

    fflush(fpKeyboard);
    fclose(fpKeyboard);
    fclose(fpDataPenjual);

    printf("===============================================================");
    printf("\nApakah anda ingin kembali ke dashboard? [iya/tidak]\n> ");
    fflush(stdin); gets(kembali);
    if(strcmp(kembali, "iya")==0){
        DashboardPenjual();
    }else if(strcmp(kembali, "tidak")==0){
        MenuUtama();
    }else{
        printf("Opsi tidak ada!\n");
        TokoPembeli();
    }
}

void TambahKeyboard(void)
{
    FILE *fpKeyboard;
    FILE *fpDataPenjual;

    fpKeyboard = fopen("DataProduk.dat","ab");
    fpDataPenjual = fopen("DataPenjual.dat","rb");

    int i, jumlah;
    char pilihan[50];

    system("cls");
    printf("===============================================================");
    printf("\n\t\t T A M B A H   K E Y B O A R D");
    printf("\n===============================================================");
    printf("\nMasukkan jumlah keyboard yang ingin dimasukkan: ");
    scanf("%d", &jumlah);
    for(i=0; i<jumlah; i++){
        printf("Keyboard %d", i+1);
        printf("\nNama Toko\t: ");
        fflush(stdin); gets(keyboard.namatoko);
        printf("Nama Keyboard\t: ");
        gets(keyboard.namaKeyboard);
        printf("Tipe Keyboard\t: ");
        gets(keyboard.tipe);
        printf("Tipe Switch\t: ");
        gets(keyboard.tipeswitch);
        printf("Lube\t\t: ");
        gets(keyboard.lube);
        printf("Harga\t\t: ");
        scanf("%d", &keyboard.harga); getchar();
        fwrite(&keyboard, sizeof(keyboard), 1, fpKeyboard);
    }

    fflush(fpKeyboard);
    fclose(fpKeyboard);
    fclose(fpDataPenjual);

    DashboardPenjual();
}

void TambahAksesoris(void)
{
    FILE *fpAksesoris;
    FILE *fpDataPenjual;

    fpAksesoris = fopen("DataAksesoris.dat","ab");
    fpDataPenjual = fopen("DataPenjual.dat","rb");

    int i;
    char pilihan[50];

    system("cls");
    printf("===============================================================");
    printf("\n\t\tT A M B A H   A K S E S O R I S");
    printf("\n===============================================================");
    printf("\n\t\t1. Keycaps");
    printf("\n\t\t2. Numpad");
    printf("\n\t\t3. Handrest");
    printf("\n\t\t4. Kabel");
    printf("\n\t\tPilih salah satu opsi: ");
    scanf("%d", &aksesoris.klasifikasi); getchar();

    if(aksesoris.klasifikasi == 1){
        printf("Keycaps");
        printf("\nNama Toko\t: ");
        fflush(stdin); gets(aksesoris.namatoko);
        printf("Nama Keycaps\t: ");
        gets(aksesoris.nama);
        printf("Profil Keycaps\t: ");
        gets(aksesoris.profilkeycaps);
        printf("Harga\t\t: ");
        scanf("%d", &aksesoris.harga); getchar();
        fwrite(&aksesoris, sizeof(aksesoris), 1, fpAksesoris);

        fflush(fpAksesoris);
        fclose(fpAksesoris);
        fclose(fpDataPenjual);

        DashboardPenjual();
    } else if(aksesoris.klasifikasi == 2){
        printf("Numpad");
        printf("\nNama Toko\t: ");
        fflush(stdin); gets(aksesoris.namatoko);
        printf("Nama Numpad\t: ");
        gets(aksesoris.nama);
        printf("Harga\t\t: ");
        scanf("%d", &aksesoris.harga); getchar();
        fwrite(&aksesoris, sizeof(aksesoris), 1, fpAksesoris);

        fflush(fpAksesoris);
        fclose(fpAksesoris);
        fclose(fpDataPenjual);

        DashboardPenjual();
    } else if(aksesoris.klasifikasi == 3){
        printf("Handrest");
        printf("\nNama Toko\t: ");
        fflush(stdin); gets(aksesoris.namatoko);
        printf("Nama Handrest\t: ");
        gets(aksesoris.nama);
        printf("Harga\t\t: ");
        scanf("%d", &aksesoris.harga); getchar();
        fwrite(&aksesoris, sizeof(aksesoris), 1, fpAksesoris);

        fflush(fpAksesoris);
        fclose(fpAksesoris);
        fclose(fpDataPenjual);

        DashboardPenjual();
    } else if(aksesoris.klasifikasi == 4){
        printf("Kabel");
        printf("\nNama Toko\t: ");
        fflush(stdin); gets(aksesoris.namatoko);
        printf("Nama Kabel\t: ");
        gets(aksesoris.nama);
        printf("Harga\t\t: ");
        scanf("%d", &aksesoris.harga); getchar();
        fwrite(&aksesoris, sizeof(aksesoris), 1, fpAksesoris);

        fflush(fpAksesoris);
        fclose(fpAksesoris);
        fclose(fpDataPenjual);

        DashboardPenjual();
    } else {
        printf("Opsi tidak ada!\n");
        TambahAksesoris();
    }
}

void Konfirmasi(void)
{
    FILE *fpTransaksi1;
    FILE *fpTransaksi2;
    FILE *fpProdukKey;
    FILE *fpProdukAcc;
    FILE *fpPembeli;
    FILE *fpKonfirmasiAcc;
    FILE *fpKonfirmasiKey;
    FILE *fpProdukKey2;
    FILE *fpProdukAcc2;

    fpTransaksi1 = fopen("Transaksi1.dat","rb");
    fpTransaksi2 = fopen("Transaksi2.dat","rb");
    fpProdukKey = fopen("DataProduk.dat","rb");
    fpPembeli = fopen("DataPembeli.dat","rb");
    fpProdukAcc = fopen("DataAksesoris.dat","rb");

    int i=1, j=1, nourut, offsetbyte;
    char kembali[50], pilihan[50], konfirmasi[50];

    system("cls");
    printf("===============================================================");
    printf("\n\t    K O N F I R M A S I   P E N J U A L A N");
    printf("\n===============================================================");
    printf("\n1) Keyboard");
    while(fread(&keyboard, sizeof(keyboard), 1, fpTransaksi1)==1){
        if(strcmp(dataPenjual.toko, keyboard.namatoko)==0){
            printf("\n%d. Nama Produk\t : %s", i, keyboard.namaKeyboard);
            printf("\n   Harga\t : %d", keyboard.harga);
            printf("\n   Nama Pembeli\t : %s\n", keyboard.namapembeli);
            i++;
        }
    }

    printf("\n\n2) Aksesoris");
    while(fread(&aksesoris, sizeof(aksesoris), 1, fpTransaksi2)==1){
        if(strcmp(dataPenjual.toko, keyboard.namatoko)==0){
            printf("\n%d. Nama Produk\t : %s", j, aksesoris.nama);
            printf("\n   Harga\t : %d", aksesoris.harga);
            printf("\n   Nama Pembeli\t : %s\n", aksesoris.namapembeli);
            j++;
        }
    }

    fclose(fpPembeli);
    fclose(fpTransaksi1);
    fclose(fpTransaksi2);
    fclose(fpProdukKey);
    fclose(fpProdukAcc);

    fpProdukKey = fopen("Transaksi1.dat","rb");
    fpKonfirmasiKey = fopen("KonfirmasiKeyboard.dat","ab");
    fpProdukKey2 = fopen("Transaksi1TEMP.dat","wb");
    fpProdukAcc = fopen("Transaksi2.dat","rb");
    fpKonfirmasiAcc = fopen("KonfirmasiAksesoris.dat","ab");
    fpProdukAcc2 = fopen("Transaksi2TEMP.dat","wb");

    printf("\nMasukkan nama produk yang ingin dikonfirmasi: ");
    fflush(stdin); gets(konfirmasi);

    while(fread(&keyboard, sizeof(keyboard), 1, fpProdukKey)==1){
        if(strcmp(keyboard.namaKeyboard, konfirmasi) != 0){
            fwrite(&keyboard, sizeof(keyboard), 1, fpProdukKey2);
        } else if(strcmp(keyboard.namaKeyboard, konfirmasi) == 0){
            fwrite(&keyboard, sizeof(keyboard), 1, fpKonfirmasiKey);
        }
    }

    while(fread(&aksesoris, sizeof(aksesoris), 1, fpProdukAcc)==1){
        if(strcmp(aksesoris.nama, konfirmasi) != 0){
            fwrite(&aksesoris, sizeof(aksesoris), 1, fpProdukAcc2);
        } else if(strcmp(aksesoris.nama, konfirmasi) == 0){
            fwrite(&aksesoris, sizeof(aksesoris), 1, fpKonfirmasiAcc);
        }
    }

    fflush(fpProdukKey2);
    fclose(fpProdukKey);
    fclose(fpProdukKey2);

    fflush(fpProdukAcc2);
    fclose(fpProdukAcc);
    fclose(fpProdukAcc2);

    remove("Transaksi1.dat");
    rename("Transaksi1TEMP.dat","Transaksi1.dat");
    remove("Transaksi1TEMP.dat");

    remove("Transaksi2.dat");
    rename("Transaksi2TEMP.dat","Transaksi2.dat");
    remove("Transaksi2TEMP.dat");

    fflush(fpKonfirmasiAcc);
    fclose(fpKonfirmasiAcc);
    fflush(fpKonfirmasiKey);
    fclose(fpKonfirmasiKey);
    fflush(fpProdukKey2);
    fclose(fpProdukKey2);
    fflush(fpProdukAcc2);
    fclose(fpProdukAcc2);
    fclose(fpProdukKey);
    fclose(fpProdukAcc);

    printf("===============================================================");
    printf("\nApakah anda ingin kembali ke dashboard? [iya/tidak]\n> ");
    fflush(stdin); gets(kembali);
    if(strcmp(kembali, "iya")==0){
        DashboardPenjual();
    }else if(strcmp(kembali, "tidak")==0){
        MenuUtama();
    }else{
        printf("Opsi tidak ada!\n");
        Konfirmasi();
    }
}

void MenuPembeli(void)
{
    int pilihanPembeli;

    system("cls");
    printf("===============================================================");
    printf("\n\t\t    M E N U   P E M B E L I");
    printf("\n===============================================================");
    printf("\n\t\t    1. Login sebagai PEMBELI");
    printf("\n\t\t    2. Daftar sebagai PEMBELI");
    printf("\n\t\t    3. Kembali ke menu utama");
    printf("\n\t\t    Pilih salah satu opsi: ");
    scanf("%d", &pilihanPembeli);

    switch(pilihanPembeli){
        case 1:
            LoginPembeli();
            break;
        case 2:
            DaftarPembeli();
            break;
        case 3:
            MenuUtama();
            break;
        default:
            printf("Opsi tidak ada!\n");
            MenuPembeli();
    }
}

void LoginPembeli(void)
{
    FILE *fpLoginPembeli;
    fpLoginPembeli = fopen("DataPembeli.dat","rb");

    char loginEmail[50], loginPassword[50];
    int i=3, ada=0;

    system("cls");
    printf("===============================================================");
    printf("\n\t\t   L O G I N   P E M B E L I");
    printf("\n===============================================================");
    printf("\nEMAIL\t : ");
    fflush(stdin); gets(loginEmail);

    while(fread(&dataPembeli, sizeof(dataPembeli), 1, fpLoginPembeli)==1){
        if(strcmp(loginEmail, dataPembeli.email)==0){
            ada = 1;
            while(i>0){
                printf("PASSWORD : ");
                gets(loginPassword);
                if(strcmp(loginPassword, dataPembeli.password)==0){
                    DashboardPembeli();
                    break;
                }else if(strcmp(loginPassword, dataPembeli.password)!=0){
                    printf("Password atau Email salah! Silahkan coba lagi! Anda mempunyai %d kesempatan lagi!\n", i-1);
                    i--;
                }
            }
            break;
            if(i==0){
                MenuUtama();
            }
        }
    }

    if(!ada){
        printf("Email tidak terdaftar!\n");
        MenuPembeli();
    }

    fclose(fpLoginPembeli);
}

void DaftarPembeli(void)
{
    FILE *fpDaftarPembeli;
    fpDaftarPembeli = fopen("DataPembeli.dat","ab");

    system("cls");
    printf("===============================================================");
    printf("\n\t\t  D A F T A R     P E M B E L I");
    printf("\n===============================================================");
    printf("\nNama Lengkap\t\t: ");
    fflush(stdin); gets(dataPembeli.nama);
    printf("Alamat Rumah\t\t: ");
    gets(dataPembeli.alamat);
    printf("Alamat Email\t\t: ");
    gets(dataPembeli.email);
    printf("Nomor Telepon\t\t: ");
    gets(dataPembeli.notel);
    printf("Password\t\t: ");
    gets(dataPembeli.password);
    printf("Konfirmasi Password\t: ");
    gets(dataPembeli.konfirmasi);

    if(strcmp(dataPembeli.password, dataPembeli.konfirmasi)==0){
        fwrite(&dataPembeli, sizeof(dataPembeli), 1, fpDaftarPembeli);
        printf("Pendaftaran anda berhasil!\n");
        system("pause");
    } else if(strcmp(dataPembeli.password, dataPembeli.konfirmasi)!=0){
        printf("Konfirmasi Password Salah! Silahkan coba lagi!\n");
        system("pause");
        DaftarPembeli();
    }

    fclose(fpDaftarPembeli);

    MenuUtama();
}

void DashboardPembeli(void)
{
    FILE *fpPembeli;
    fpPembeli = fopen("DataPembeli.dat","rb");

    int pilihan;

    system("cls");
    printf("===============================================================");
    printf("\n\t\t  S E L A M A T   D A T A N G\n\t\t  %s", dataPembeli.nama);
    printf("\n\t\t  S A L D O : Rp%d", dataPembeli.saldo);
    printf("\n===============================================================");
    printf("\n\t\t1. Top-up saldo");
    printf("\n\t\t2. Beli produk");
    printf("\n\t\t3. Riwayat pembelian");
    printf("\n\t\t4. Kembali ke menu utama");
    printf("\n\t\tPilih salah satu opsi: ");
    scanf("%d", &pilihan);

    switch (pilihan){
        case 1:
            TopupSaldo();
            break;
        case 2:
            Magazine();
            break;
        case 3:
            Riwayat();
            break;
        case 4:
            MenuUtama();
            break;
        default:
            printf("Opsi tidak ada!\n");
            DashboardPembeli();
    }

    fclose(fpPembeli);
}

void TopupSaldo(void)
{
    FILE *fpPembeli;
    FILE *fpPembeli1;

    fpPembeli = fopen("DataPembeli.dat","rb");
    fpPembeli1 = fopen("Temp.dat","wb");
    
    char nomortelepon[50], password[50], kembali[50], curName[50];
    int topup, curSaldo, ada = 0;

    system("cls");
    printf("===============================================================");
    printf("\n\t\t    T O P - U P   S A L D O");
    printf("\n===============================================================");
    printf("\nMasukkan nomor telepon: ");
    fflush(stdin); gets(nomortelepon);
    while(fread(&dataPembeli, sizeof(dataPembeli), 1, fpPembeli)==1){
        if(strcmp(nomortelepon, dataPembeli.notel)==0){
            ada = 1;
            fflush(stdin);
            printf("Masukkan jumlah saldo: Rp");
            scanf("%d", &topup); getchar();
            dataPembeli.saldo += topup;
            curSaldo = dataPembeli.saldo;
            strcpy(curName, dataPembeli.nama);
            fwrite(&dataPembeli, sizeof(dataPembeli), 1, fpPembeli1);
        }else fwrite(&dataPembeli, sizeof(dataPembeli), 1, fpPembeli1);
    }

    fflush(fpPembeli1);
    fclose(fpPembeli1);
    fclose(fpPembeli);

    if(ada){
        fpPembeli = fopen("DataPembeli.dat","wb");
        fpPembeli1 = fopen("Temp.dat","rb");

        while(fread(&dataPembeli, sizeof(dataPembeli), 1, fpPembeli1)==1){
            fwrite(&dataPembeli, sizeof(dataPembeli), 1, fpPembeli);
        }
        fflush(fpPembeli);
        fclose(fpPembeli1);
        fclose(fpPembeli);

        remove("Temp.dat");

        strcpy(dataPembeli.nama, curName);
        dataPembeli.saldo = curSaldo;
        printf("Top up anda berhasil!\n");
        
        system("pause");
        DashboardPembeli();
    } else {
        printf("Nomor telepon tidak terdaftar!\n");
        DashboardPembeli();
    }
}

void Magazine(void)
{
    FILE *fpListPenjual;
    FILE *fpBarangPenjual;
    FILE *fpAksesoris;
    FILE *fpTrans1;
    FILE *fpTrans2;
    FILE *fpPembeli;
    FILE *fpPembeli1;

    fpListPenjual = fopen("DataPenjual.dat","rb");
    fpBarangPenjual = fopen("DataProduk.dat","rb");
    fpAksesoris = fopen("DataAksesoris.dat","rb");

    int i, j, k=1, count=0, ada = 0, ada2 = 0, ada3 = 0, nourut, offsetbyte, curSaldo;
    char pilihan[50], kembali[50], beli[50], dibeli[50], nama[50], curName[50];

    system("cls");
    printf("===============================================================");
    printf("\n\t\t     B E L I   P R O D U K");
    printf("\n===============================================================");
    printf("\n1) Keyboard");
    while(fread(&keyboard, sizeof(keyboard), 1, fpBarangPenjual)==1){
        printf("\n%d. Nama Keyboard : %s", i, keyboard.namaKeyboard);
        printf("\n   Tipe Keyboard : %s", keyboard.tipe);
        printf("\n   Tipe Switch\t : %s", keyboard.tipeswitch);
        printf("\n   Lube\t\t : %s", keyboard.lube);
        printf("\n   Harga\t : Rp%d", keyboard.harga);
        i++;
    }

    printf("\n\n2) Aksesoris");
    while(fread(&aksesoris, sizeof(aksesoris), 1, fpAksesoris)==1){
        if(aksesoris.klasifikasi == 1){
            printf("\n%d. Nama Keycaps\t : %s", j, aksesoris.nama);
            printf("\n   Profil Keycaps: %s", aksesoris.profilkeycaps);
            printf("\n   Harga\t : Rp%d", aksesoris.harga);
            j++;
        } else if(aksesoris.klasifikasi == 2){
            printf("\n%d. Nama Numpad\t : %s", j, aksesoris.nama);
            printf("\n   Harga\t : Rp%d", aksesoris.harga);
            j++;
        } else if(aksesoris.klasifikasi == 3){
            printf("\n%d. Nama Handrest : %s", j, aksesoris.nama);
            printf("\n   Harga\t : Rp%d", aksesoris.harga);
            j++;
        } else if(aksesoris.klasifikasi == 4){
            printf("\n%d. Nama Kabel\t : %s", j, aksesoris.nama);
            printf("\n   Harga\t : Rp%d", aksesoris.harga);
            j++;
        }
    }

    fclose(fpAksesoris);
    fclose(fpBarangPenjual);
    fclose(fpListPenjual);

    fpBarangPenjual = fopen("DataProduk.dat","rb");
    fpTrans1 = fopen("Transaksi1.dat","ab");
    fpAksesoris = fopen("DataAksesoris.dat","rb");
    fpTrans2 = fopen("Transaksi2.dat","ab");

    printf("\n===============================================================");
    printf("\nMasukkan jenis produk yang ingin dibeli: [keyboard/aksesoris]\n> ");
    fflush(stdin); gets(pilihan);

    if(strcmp(pilihan, "keyboard")==0){
        printf("Masukkan angka produk yang ingin dibeli: ");
        scanf("%d", &nourut); getchar();

        offsetbyte = (nourut - 1) * sizeof(keyboard);
        fseek(fpBarangPenjual, offsetbyte, SEEK_SET);

        if(fread(&keyboard, sizeof(keyboard), 1, fpBarangPenjual)==1){
            ada = 1;
            printf("Masukkan nama: ");
            fflush(stdin); gets(keyboard.namapembeli);
            fwrite(&keyboard, sizeof(keyboard), 1, fpTrans1);
        }else printf("Produk tidak ada!");

    } else if(strcmp(pilihan, "aksesoris")==0){
        printf("Masukkan angka produk yang ingin dibeli: ");
        scanf("%d", &nourut); getchar();

        offsetbyte = (nourut - 1) * sizeof(aksesoris);
        fseek(fpAksesoris, offsetbyte, SEEK_SET);

        if(fread(&aksesoris, sizeof(aksesoris), 1, fpAksesoris)==1){
            ada2 = 1;
            printf("Masukkan nama: ");
            fflush(stdin); gets(aksesoris.namapembeli);
            fwrite(&aksesoris, sizeof(aksesoris), 1, fpTrans2);
        }else printf("Produk tidak ada!");       
    }

    fflush(fpTrans2);
    fclose(fpTrans2);
        
    fflush(fpTrans1);
    fclose(fpTrans1);

    fpPembeli = fopen("DataPembeli.dat","rb");
    fpPembeli1 = fopen("Temp.dat","wb");

    while(fread(&dataPembeli, sizeof(dataPembeli), 1, fpPembeli)==1){
        if(ada){
            if(strcmp(keyboard.namapembeli, dataPembeli.nama)==0){
                ada3 = 1;
                dataPembeli.saldo -= keyboard.harga;
                if(dataPembeli.saldo < 0){
                    printf("Saldo tidak cukup!\n");
                    DashboardPembeli();
                } else {
                    curSaldo = dataPembeli.saldo;
                    strcpy(curName, dataPembeli.nama);
                    fwrite(&dataPembeli, sizeof(dataPembeli), 1, fpPembeli1);
                }
            } else fwrite(&dataPembeli, sizeof(dataPembeli), 1, fpPembeli1);

        } else if(ada2){
            if(strcmp(aksesoris.namapembeli, dataPembeli.nama)==0){
                ada3 = 1;
                dataPembeli.saldo -= aksesoris.harga;
                if(dataPembeli.saldo < 0){
                    printf("Saldo tidak cukup!\n");
                    DashboardPembeli();
                } else {
                    curSaldo = dataPembeli.saldo;
                    strcpy(curName, dataPembeli.nama);
                    fwrite(&dataPembeli, sizeof(dataPembeli), 1, fpPembeli1);
                }
            } else fwrite(&dataPembeli, sizeof(dataPembeli), 1, fpPembeli1);
        }
    }

    fflush(fpPembeli1);
    fclose(fpPembeli1);
    fclose(fpPembeli);
    fclose(fpBarangPenjual);
    fclose(fpAksesoris);

    if(ada3){
        fpPembeli = fopen("DataPembeli.dat","wb");
        fpPembeli1 = fopen("Temp.dat","rb");

        while(fread(&dataPembeli, sizeof(dataPembeli), 1, fpPembeli1)==1){
            fwrite(&dataPembeli, sizeof(dataPembeli), 1, fpPembeli);
        }
        fflush(fpPembeli);
        fclose(fpPembeli1);
        fclose(fpPembeli);

        remove("Temp.dat");

        strcpy(dataPembeli.nama, curName);
        dataPembeli.saldo = curSaldo;
        printf("Transaksi berhasil!\n");
    }
    system("pause");
    DashboardPembeli();
}

void Riwayat(void)
{
    FILE *fpTransaksi1;
    FILE *fpTransaksi2;
    FILE *fpProdukKey;
    FILE *fpProdukAcc;
    FILE *fpPembeli;
    FILE *fpKonfirmasiAcc;
    FILE *fpKonfirmasiKey;

    fpTransaksi1 = fopen("Transaksi1.dat","rb");
    fpTransaksi2 = fopen("Transaksi2.dat","rb");
    fpProdukKey = fopen("DataProduk.dat","rb");
    fpPembeli = fopen("DataPembeli.dat","rb");
    fpProdukAcc = fopen("DataAksesoris.dat","rb");

    int i=1, j=1;
    char nama[50], password[50], kembali[50];

    system("cls");
    printf("===============================================================");
    printf("\n\t       R I W A Y A T   P E M B E L I A N");
    printf("\n===============================================================");
    printf("\nMenunggu Konfirmasi: ");
    while(fread(&keyboard, sizeof(keyboard), 1, fpTransaksi1)==1){
        if(strcmp(keyboard.namapembeli, dataPembeli.nama)==0){
            printf("\n%d. Nama Keyboard : %s", i, keyboard.namaKeyboard);
            printf("\n   Tipe Keyboard : %s", keyboard.tipe);
            printf("\n   Tipe Switch\t : %s", keyboard.tipeswitch);
            printf("\n   Lube\t\t : %s", keyboard.lube);
            printf("\n   Harga\t : Rp%d\n\n", keyboard.harga);
            i++;
        }
    }

    while(fread(&aksesoris, sizeof(aksesoris), 1, fpTransaksi2)==1){
        if(strcmp(aksesoris.namapembeli, dataPembeli.nama)==0){
            if(aksesoris.klasifikasi == 1){
                printf("\n%d. Nama Keycaps\t : %s", i, aksesoris.nama);
                printf("\n   Profil Keycaps: %s", aksesoris.profilkeycaps);
                printf("\n   Harga\t : Rp%d\n", aksesoris.harga);
                i++;
            } else if(aksesoris.klasifikasi == 2){
                printf("\n%d. Nama Numpad\t : %s", i, aksesoris.nama);
                printf("\n   Harga\t : Rp%d\n", aksesoris.harga);
                i++;
            } else if(aksesoris.klasifikasi == 3){
                printf("\n%d. Nama Handrest : %s", i, aksesoris.nama);
                printf("\n   Harga\t : Rp%d\n", aksesoris.harga);
                i++;
            } else if(aksesoris.klasifikasi == 4){
                printf("\n%d. Nama Kabel\t : %s", i, aksesoris.nama);
                printf("\n   Harga\t : Rp%d\n", aksesoris.harga);
                i++;
            }
        }
    }

    fclose(fpPembeli);
    fclose(fpTransaksi1);
    fclose(fpTransaksi2);
    fclose(fpProdukKey);
    fclose(fpProdukAcc);

    printf("\nSudah terkonfirmasi: ");
    fpProdukKey = fopen("DataProduk.dat","rb");
    fpKonfirmasiKey = fopen("KonfirmasiKeyboard.dat","rb");
    fpProdukAcc = fopen("DataAksesoris.dat","rb");
    fpKonfirmasiAcc = fopen("KonfirmasiAksesoris.dat","rb");

    while(fread(&keyboard, sizeof(keyboard), 1, fpKonfirmasiKey)==1){
        if(strcmp(keyboard.namapembeli, dataPembeli.nama)==0){
            printf("\n%d. Nama Keyboard : %s", j, keyboard.namaKeyboard);
            printf("\n   Tipe Keyboard : %s", keyboard.tipe);
            printf("\n   Tipe Switch\t : %s", keyboard.tipeswitch);
            printf("\n   Lube\t\t : %s", keyboard.lube);
            printf("\n   Harga\t : Rp%d\n", keyboard.harga);
            j++;
        }
    }

    while(fread(&aksesoris, sizeof(aksesoris), 1, fpKonfirmasiAcc)==1){
        if(strcmp(keyboard.namapembeli, dataPembeli.nama)==0){
            if(aksesoris.klasifikasi == 1){
                printf("\n%d. Nama Keycaps\t : %s", j, aksesoris.nama);
                printf("\n   Profil Keycaps: %s", aksesoris.profilkeycaps);
                printf("\n   Harga\t : Rp%d\n", aksesoris.harga);
                j++;
            } else if(aksesoris.klasifikasi == 2){
                printf("\n%d. Nama Numpad\t : %s", j, aksesoris.nama);
                printf("\n   Harga\t : Rp%d\n", aksesoris.harga);
                j++;
            } else if(aksesoris.klasifikasi == 3){
                printf("\n%d. Nama Handrest : %s", j, aksesoris.nama);
                printf("\n   Harga\t : Rp%d\n", aksesoris.harga);
                j++;
            } else if(aksesoris.klasifikasi == 4){
                printf("\n%d. Nama Kabel\t : %s", j, aksesoris.nama);
                printf("\n   Harga\t : Rp%d\n", aksesoris.harga);
                j++;
            }
        }
    }

    fclose(fpKonfirmasiAcc);
    fclose(fpKonfirmasiKey);
    fclose(fpProdukKey);
    fclose(fpProdukAcc);

    printf("===============================================================");
    printf("\nKembali ke dashboard? [iya/tidak]\n> ");
    fflush(stdin); gets(kembali);

    if(strcmp(kembali, "iya")==0){
        DashboardPembeli();
    }else if(strcmp(kembali, "tidak")==0){
        MenuUtama();
    }else{
        printf("Opsi tidak ada!\n");
        Riwayat();
    }
}

void LoginAdmin(void)
{
    char loginAdmin[50], loginPassword[50];
    int i=3;

    system("cls");
    printf("===============================================================");
    printf("\n\t\t     L O G I N   A D M I N");
    printf("\n===============================================================");
    while(i>0){
        printf("\nEMAIL\t : ");
        fflush(stdin); gets(loginAdmin);
        printf("PASSWORD : ");
        gets(loginPassword);

        if(strcmp(loginAdmin, emailadmin)==0 && strcmp(loginPassword, passwordadmin)==0){
            DashboardAdmin();
            break;
        }else if(strcmp(loginAdmin, emailadmin)!=0 || strcmp(loginPassword, passwordadmin)!=0){
            printf("Password atau Email salah! Silahkan coba lagi! Anda mempunyai %d kesempatan lagi!\n", i-1);
            i--;
        }

    }if(i==0){
    MenuUtama();
    }
}

void DashboardAdmin(void)
{
    int pilihanAdmin;

    system("cls");
    printf("===============================================================");
    printf("\n\t\t  S E L A M A T   D A T A N G\n\t\t  A D M I N");
    printf("\n===============================================================");
    printf("\n\t\t  1. List penjual");
    printf("\n\t\t  2. List barang penjual");
    printf("\n\t\t  3. Hapus akun penjual");
    printf("\n\t\t  4. Hapus barang penjual");
    printf("\n\t\t  5. Kembali ke menu utama");
    printf("\n\t\t  Pilih salah satu opsi: ");
    scanf("%d", &pilihanAdmin);

    switch(pilihanAdmin){
        case 1:
            ListPenjual();
            break;
        case 2:
            ListBarangPenjual();
            break;
        case 3:
            HapusPenjual();
            break;
        case 4:
            HapusBarangPenjual();
            break;
        case 5:
            MenuUtama();
            break;
        default:
            printf("Opsi tidak ada!\n");
            MenuUtama();
    }
}

void ListPenjual(void)
{
    FILE *fpListPenjual;
    fpListPenjual = fopen("DataPenjual.dat","rb");

    int i, j, count = 0;
    char kembali[50];

    system("cls");
    printf("===============================================================");
    printf("\n\t\t    L I S T   P E N J U A L");
    printf("\n===============================================================");
    while(fread(&dataPenjual, sizeof(dataPenjual), 1, fpListPenjual)==1){
        data2[count] = dataPenjual;
        count++;
    }

    for(i=0; i<count-1; i++){
        for(j=i+1; j<count; j++){
            if(strcmp(data2[i].nama, data2[j].nama)>0){
                temp = data2[i];
                data2[i] = data2[j];
                data2[j] = temp;
            }
        }
    }

    for(i=0; i<count; i++){
        printf("\nPenjual %d", i+1);
        printf("\nNama Lengkap\t: %s", data2[i].nama);
        printf("\nNama Toko\t: %s", data2[i].toko);
        printf("\nKota Asal\t: %s", data2[i].kota);
        printf("\nAlamat Email\t: %s", data2[i].email);
        printf("\n");
    }

    fclose(fpListPenjual);

    printf("===============================================================");
    printf("\nKembali ke dashboard? [iya/tidak]\n> ");
    fflush(stdin); gets(kembali);

    if(strcmp(kembali, "iya")==0){
        DashboardAdmin();
    }else if(strcmp(kembali, "tidak")==0){
        MenuUtama();
    }else{
        printf("Opsi tidak ada!\n");
        ListPenjual();
    }
}

void ListBarangPenjual(void)
{
    FILE *fpListPenjual;
    FILE *fpBarangPenjual;
    FILE *fpAksesoris;

    fpListPenjual = fopen("DataPenjual.dat","rb");
    fpBarangPenjual = fopen("DataProduk.dat","rb");
    fpAksesoris = fopen("DataAksesoris.dat","rb");

    int i, j, k,count=0;
    char pilihan[50], kembali[50];

    system("cls");
    i=1;
    printf("===============================================================");
    printf("\n\t     L I S T   B A R A N G   P E N J U A L");
    printf("\n===============================================================");
    while(fread(&dataPenjual, sizeof(dataPenjual), 1, fpListPenjual)){
        printf("\n%d. %s", i, dataPenjual.toko);
        i++;
    }

    printf("\nTulis nama toko yang ingin dilihat produknya: ");
    fflush(stdin); gets(pilihan);
    printf("===============================================================");
    
    printf("\n1) Keyboard");
    while(fread(&keyboard, sizeof(keyboard), 1, fpBarangPenjual)==1){
        keyboard2[count] = keyboard;
        count++;
    }

    for(i=0; i<count; i++){
        for(j=i+1; j<count; j++){
            if(keyboard2[i].harga < keyboard2[j].harga){
                temp2 = keyboard2[i];
                keyboard2[i] = keyboard2[j];
                keyboard2[j] = temp2;
            }
        }
    }

    j=0;
    for(i=0; i<count; i++){
        if(strcmp(keyboard2[i].namatoko, pilihan)==0){
            printf("\n%d. Nama Keyboard : %s", j+1, keyboard2[i].namaKeyboard);
            printf("\n   Tipe Keyboard : %s", keyboard2[i].tipe);
            printf("\n   Tipe Switch\t : %s", keyboard2[i].tipeswitch);
            printf("\n   Lube\t\t : %s", keyboard2[i].lube);
            printf("\n   Harga\t : Rp%d", keyboard2[i].harga);
            j++;
        }
    }

    printf("\n\n2) Aksesoris");
    count = 0;
    while(fread(&aksesoris, sizeof(aksesoris), 1, fpAksesoris)==1){
        aksesoris2[count] = aksesoris;
        count++;
    }

    for(i=0; i<count; i++){
        for(j=i+1; j<count; j++){
            if(aksesoris2[i].harga < aksesoris2[j].harga){
                temp3 = aksesoris2[i];
                aksesoris2[i] = aksesoris2[j];
                aksesoris2[j] = temp3;
            }
        }
    }

    k=1;
    for(i=0; i<count; i++){
        if(strcmp(aksesoris2[i].namatoko, pilihan)==0){
            if(aksesoris2[i].klasifikasi == 1){
                printf("\n%d. Nama Keycaps\t : %s", k, aksesoris2[i].nama);
                printf("\n   Profil Keycaps: %s", aksesoris2[i].profilkeycaps);
                printf("\n   Harga\t : Rp%d", aksesoris2[i].harga);
                k++;
            } else if(aksesoris2[i].klasifikasi == 2){
                printf("\n%d. Nama Numpad\t : %s", k, aksesoris2[i].nama);
                printf("\n   Harga\t : Rp%d", aksesoris2[i].harga);
                k++;
            } else if(aksesoris2[i].klasifikasi == 3){
                printf("\n%d. Nama Handrest : %s", k, aksesoris2[i].nama);
                printf("\n   Harga\t : Rp%d", aksesoris2[i].harga);
                k++;
            } else if(aksesoris2[i].klasifikasi == 4){
                printf("\n%d. Nama Kabel\t : %s", k, aksesoris2[i].nama);
                printf("\n   Harga\t : Rp%d", aksesoris2[i].harga);
                k++;
            }
        }
    }

    fclose(fpAksesoris);
    fclose(fpBarangPenjual);
    fclose(fpListPenjual);

    printf("\n===============================================================");
    printf("\nKembali ke dashboard? [iya/tidak]");
    printf("\n> ");
    fflush(stdin); gets(kembali);

    if(strcmp(kembali, "iya")==0){
        DashboardAdmin();
    }else if(strcmp(kembali, "tidak")==0){
        MenuUtama();
    }else{
        printf("Opsi tidak ada!\n");
        ListBarangPenjual();
    }
}

void HapusPenjual(void)
{
    FILE *fpRead;
    FILE *fpDelete;
    FILE *fpDataBelumDihapus;
    FILE *fpDataSudahDihapus;

    int i, j, count = 0;
    char namaDihapus[50], pilihan[50];

    system("cls");
    printf("===============================================================");
    printf("\n\t      H A P U S   A K U N   P E N J U A L");
    printf("\n===============================================================");
    fpDataBelumDihapus = fopen("DataPenjual.dat","rb");
    while(fread(&dataPenjual, sizeof(dataPenjual), 1, fpDataBelumDihapus)==1){
        data2[count] = dataPenjual;
        count++;
    }

    for(i=0; i<count-1; i++){
        for(j=i+1; j<count; j++){
            if(strcmp(data2[i].nama, data2[j].nama)>0){
                temp = data2[i];
                data2[i] = data2[j];
                data2[j] = temp;
            }
        }
    }

    for(i=0; i<count; i++){
        printf("\nPenjual %d", i+1);
        printf("\nNama Lengkap\t: %s", data2[i].nama);
        printf("\nNama Toko\t: %s", data2[i].toko);
        printf("\nKota Asal\t: %s", data2[i].kota);
        printf("\nAlamat Email\t: %s", data2[i].email);
        printf("\n");
    }

    fclose(fpDataBelumDihapus);

    fpRead = fopen("DataPenjual.dat","rb");
    fpDelete = fopen("DataPenjual2.dat","wb");
    printf("\nMasukkan nama penjual yang ingin dihapus: ");
    fflush(stdin); gets(namaDihapus);
    printf("===============================================================");

    while(fread(&dataPenjual, sizeof(dataPenjual), 1, fpRead)==1){
        if(strcmp(dataPenjual.nama, namaDihapus) != 0){
            fwrite(&dataPenjual, sizeof(dataPenjual), 1, fpDelete);
        }
    }

    fflush(fpDelete);
    fclose(fpRead);
    fclose(fpDelete);

    remove("DataPenjual.dat");
    rename("DataPenjual2.dat","DataPenjual.dat");
    remove("DataPenjual2.dat");

    fpDataSudahDihapus = fopen("DataPenjual.dat","rb");
    count = 0;
    while(fread(&dataPenjual, sizeof(dataPenjual), 1, fpDataSudahDihapus)==1){
        data2[count] = dataPenjual;
        count++;
    }

    for(i=0; i<count-1; i++){
        for(j=i+1; j<count; j++){
            if(strcmp(data2[i].nama, data2[j].nama)>0){
                temp = data2[i];
                data2[i] = data2[j];
                data2[j] = temp;
            }
        }
    }

    for(i=0; i<count; i++){
        printf("\nPenjual %d", i+1);
        printf("\nNama Lengkap\t: %s", data2[i].nama);
        printf("\nNama Toko\t: %s", data2[i].toko);
        printf("\nKota Asal\t: %s", data2[i].kota);
        printf("\nAlamat Email\t: %s", data2[i].email);
        printf("\n");
    }

    fclose(fpDataSudahDihapus);

    printf("===============================================================");
    printf("\nHapus lagi? [iya/tidak]\n> ");
    gets(pilihan);
    if(strcmp(pilihan, "iya")==0){
        HapusPenjual();
    }else if(strcmp(pilihan, "tidak")==0){
        DashboardAdmin();
    }else{
        printf("Opsi tidak ada!");
        MenuUtama();
    }
}

void HapusBarangPenjual(void)
{
    FILE *fpListPenjual;    
    FILE *fpBarangPenjual;
    FILE *fpAksesoris;
    FILE *fpRead;
    FILE *fpDelete;
    FILE *fpReadAcc;
    FILE *fpDeleteAcc;

    fpListPenjual = fopen("DataPenjual.dat","rb");
    fpBarangPenjual = fopen("DataProduk.dat","rb");
    fpAksesoris = fopen("DataAksesoris.dat","rb");

    int i, j=1, k=1, count = 0;
    char pilihan[50], kembali[50], namaDihapus[50];

    system("cls");
    i=1;
    printf("===============================================================");
    printf("\n\t    H A P U S   B A R A N G   P E N J U A L");
    printf("\n===============================================================");
    while(fread(&dataPenjual, sizeof(dataPenjual), 1, fpListPenjual)){
        printf("\n%d. %s", i, dataPenjual.toko);
        i++;
    }

    printf("\nTulis nama toko yang ingin dilihat produknya: ");
    fflush(stdin); gets(pilihan);
    printf("===============================================================");
    
    printf("\n1) Keyboard");
    while(fread(&keyboard, sizeof(keyboard), 1, fpBarangPenjual)==1){
        keyboard2[count] = keyboard;
        count++;
    }

    for(i=0; i<count; i++){
        for(j=i+1; j<count; j++){
            if(keyboard2[i].harga < keyboard2[j].harga){
                temp2 = keyboard2[i];
                keyboard2[i] = keyboard2[j];
                keyboard2[j] = temp2;
            }
        }
    }

    for(i=0; i<count; i++){
        if(strcmp(keyboard2[i].namatoko, pilihan)==0){
            printf("\n%d. Nama Keyboard : %s", i+1, keyboard2[i].namaKeyboard);
            printf("\n   Tipe Keyboard : %s", keyboard2[i].tipe);
            printf("\n   Tipe Switch\t : %s", keyboard2[i].tipeswitch);
            printf("\n   Lube\t\t : %s", keyboard2[i].lube);
            printf("\n   Harga\t : Rp%d", keyboard2[i].harga);
        }
    }

    printf("\n\n2) Aksesoris");
    count = 0;
    while(fread(&aksesoris, sizeof(aksesoris), 1, fpAksesoris)==1){
        aksesoris2[count] = aksesoris;
        count++;
    }

    for(i=0; i<count; i++){
        for(j=i+1; j<count; j++){
            if(aksesoris2[i].harga < aksesoris2[j].harga){
                temp3 = aksesoris2[i];
                aksesoris2[i] = aksesoris2[j];
                aksesoris2[j] = temp3;
            }
        }
    }

    k=1;
    for(i=0; i<count; i++){
        if(strcmp(aksesoris2[i].namatoko, pilihan)==0){
            if(aksesoris2[i].klasifikasi == 1){
                printf("\n%d. Nama Keycaps\t : %s", k, aksesoris2[i].nama);
                printf("\n   Profil Keycaps: %s", aksesoris2[i].profilkeycaps);
                printf("\n   Harga\t : Rp%d", aksesoris2[i].harga);
                k++;
            } else if(aksesoris2[i].klasifikasi == 2){
                printf("\n%d. Nama Numpad\t : %s", k, aksesoris2[i].nama);
                printf("\n   Harga\t : Rp%d", aksesoris2[i].harga);
                k++;
            } else if(aksesoris2[i].klasifikasi == 3){
                printf("\n%d. Nama Handrest : %s", k, aksesoris2[i].nama);
                printf("\n   Harga\t : Rp%d", aksesoris2[i].harga);
                k++;
            } else if(aksesoris2[i].klasifikasi == 4){
                printf("\n%d. Nama Kabel\t : %s", k, aksesoris2[i].nama);
                printf("\n   Harga\t : Rp%d", aksesoris2[i].harga);
                k++;
            }
        }
    }

    fclose(fpAksesoris);
    fclose(fpBarangPenjual);
    fclose(fpListPenjual);

    fpRead = fopen("DataProduk.dat","rb");
    fpDelete = fopen("DataProduk2.dat","wb");
    fpReadAcc = fopen("DataAksesoris.dat","rb");
    fpDeleteAcc = fopen("DataAksesoris2.dat","wb");
    printf("\n\nMasukkan nama produk yang ingin dihapus: ");
    fflush(stdin); gets(namaDihapus);

    while(fread(&keyboard, sizeof(keyboard), 1, fpRead)==1){
        if(strcmp(keyboard.namaKeyboard, namaDihapus) != 0){
            fwrite(&keyboard, sizeof(keyboard), 1, fpDelete);
        }
    }

    while(fread(&aksesoris, sizeof(aksesoris), 1, fpReadAcc)==1){
        if(strcmp(aksesoris.nama, namaDihapus) != 0){
            fwrite(&aksesoris, sizeof(aksesoris), 1, fpDeleteAcc);
        }
    }

    fflush(fpDelete);
    fclose(fpRead);
    fclose(fpDelete);

    fflush(fpDeleteAcc);
    fclose(fpReadAcc);
    fclose(fpDeleteAcc);

    remove("DataProduk.dat");
    rename("DataProduk2.dat","DataProduk.dat");
    remove("DataProduk2.dat");

    remove("DataAksesoris.dat");
    rename("DataAksesoris2.dat","DataAksesoris.dat");
    remove("DataAksesoris2.dat");

    printf("\nProduk berhasil dihapus!\n");

    printf("===============================================================");
    printf("\nHapus lagi? [iya/tidak]\n> ");
    gets(pilihan);
    if(strcmp(pilihan, "iya")==0){
        HapusBarangPenjual();
    }else if(strcmp(pilihan, "tidak")==0){
        DashboardAdmin();
    }else{
        printf("Opsi tidak ada!");
        MenuUtama();
    }
}

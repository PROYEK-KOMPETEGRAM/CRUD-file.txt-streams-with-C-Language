#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>

using namespace std;

int main() {
   int agt_opt;
   awal:
      system("color F0");
   system("cls");
   cout << endl;
   cout << "   1. Input Data Anggota Baru" << endl;
   cout << "   2. Daftar Data Anggota" << endl;
   cout << "   3. Sunting Data Anggota" << endl;
   cout << "   4. Hapus Data Anggota" << endl;
   cout << "   Input pilihan: ";
   cin >> agt_opt;

   switch (agt_opt) {

   case 1: //menu create

   {
      system("cls"); //menghapus output layar
      string agt_nama, agt_nim, agt_detil; //variabel tipe data string
      int agt_simpan; //variabel tipe data integer
      cout << "\n   Nama Panjang: "; //menampilkan output program
      cin >> agt_nama; //menampilkan input program
      cout << "   NIM: "; //menampilkan output program
      cin >> agt_nim; //menampilkan input program
      cout << "   Prodi*Kelas*Tahun: "; //menampilkan output program
      cin >> agt_detil; //menampilkan input program
      cout << "   Simpan? (1) Ya / (2) Tidak: "; //menampilkan output program
      cin >> agt_simpan; //menampilkan input program
      if (agt_simpan == 1) { //bersyarat
         ofstream data_anggota_update("data_anggota.txt", ios::app); //membuat file dan update isi file tanpa membuat file baru
         data_anggota_update << agt_nim << ' ' << agt_nama << ' ' << agt_detil << endl; //menyimpan data menuju file data_anggota.txt
         data_anggota_update.close(); //menutup file
         cout << "\n   Simpan berhasil."; //menampilkan output program
         goto awal; //unconditional jump statement
      } else { //jika tidak sesuai syarat
         cout << "\n   Simpan gagal."; //menampilkan output program
         goto awal; //unconditional jump statement
      }

   }
   break;
   case 2: //menu read

   {
      system("cls"); //menghapus output layar
      ifstream data_anggota_daftar("data_anggota.txt"); //membaca file
      string agt_nama, agt_nim, agt_detil, pilih; //variabel tipe data string
      cout << "\n   Daftar Anggota Koperasiku"; //menampilkan output program
      cout << "\n   -------------------------\n"; //menampilkan output program
      while (data_anggota_daftar >> agt_nim >> agt_nama >> agt_detil) { //Membaca isi dari data_anggota.txt
         cout << "\n   " << agt_nim << ' ' << agt_nama << ' ' << agt_detil << endl; //untuk menampilkan output dari isi data_anggota.txt
      }
      cout << "\n    Kembali ke awal? (1) Ya / (2) Tidak: "; //menampilkan output program
      cin >> pilih; //menampilkan input program
      if (pilih == "1") { //pernyataan apabila kondisi benar (true)
         goto awal; //unconditional statement
      } else {
         abort(); // program berhenti
      }

   }
   break;
   case 3: //menu update

   {
      system("cls"); //menghapus output layar
      ifstream data_anggota_sunting("data_anggota.txt"); //membaca file
      char agt_nim[25]; //variabel tipe data char dengan array ukuran 25
      char agt_nama[25]; //variabel tipe data char dengan array ukuran 25
      char agt_detil[25]; //variabel tipe data char dengan array ukuran 25
      char sunting_agt_nim[25]; //variabel tipe data char dengan array ukuran 25
      string sunting_agt_nim_string, agt_nim_string, agt_nama_string, agt_detil_string, agt_nama_br, agt_nim_br, agt_detil_br; //variabel tipe data string
      int sunting_opt, sunting_opt_fix; //variabel tipe data integer
      cin.ignore(); //mengabaikan atau menghapus karakter dari input buffer
      cout << "\n   Input NIM Anggota: "; //menampilkan output program
      cin.getline(sunting_agt_nim, 25); //membaca spasi pada karakter yang diinputkan
      sunting_agt_nim_string = string(sunting_agt_nim); //mengkonversi nilai char ke string
      while (data_anggota_sunting >> agt_nim_string >> agt_nama_string >> agt_detil_string) { //membaca data (variabel) apabila data ada yang tidak lengkap maka berhenti
         if (sunting_agt_nim_string == agt_nim_string) { //pernyataan apabila kondisi benar (true)
            cout << "\n   " << agt_nim_string << ' ' << agt_nama_string << ' ' << agt_detil_string << endl; //menampilkan output program
            cout << "\n   (1) Sunting / (2) Batal : "; //menampilkan output program
            cin >> sunting_opt; //menampilkan input program
            if (sunting_opt == 1) { //pernyataan apabila kondisi benar (true)
               cout << "\n   Input Nama Anggota        : "; //menampilkan output program
               cin >> agt_nama_br; //menampilkan input program
               cout << "\n   Input NIM Anggota         : "; //menampilkan output program
               cin >> agt_nim_br; //menampilkan input program
               cout << "\n   Input Prodi*Kelas*Tahun   : "; //menampilkan output program
               cin >> agt_detil_br; //menampilkan input program
               cout << "\n   (1) Ubah / (2) Batal      : "; //menampilkan output program
               cin >> sunting_opt_fix; //menampilkan input program
               if (sunting_opt_fix == 1) { //pernyataan apabila kondisi benar (true)
                  fstream data_anggota_sementara, data_anggota_override; //tipe data input dan output file
                  data_anggota_sementara.open("data_anggota_sementara.txt", ios::out); //membuka file data_anggota_sementara.txt dengan parameter out (output)
                  data_anggota_override.open("data_anggota.txt", ios:: in ); //membuka file data_anggota.txt dengan parameter in (input)
                  while (!data_anggota_override.eof()) { //End Of File, apabila input tidak berhenti maka akan membaca perintah di dalam while
                     data_anggota_override.getline(agt_nim, 25, ' '); //membaca spasi pada karakter yang diinputkan
                     data_anggota_override.getline(agt_nama, 25, ' '); //membaca spasi pada karakter yang diinputkan
                     data_anggota_override.getline(agt_detil, 25); //membaca spasi pada karakter yang diinputkan
                     if (strcmp(agt_nim, sunting_agt_nim) == 0) { //membandingkan dua variabel bertipe data char dalam string
                        continue; //memecah iterasi (melewati) atau (skip)
                     } else {
                        data_anggota_sementara << agt_nim << ' ' << agt_nama << ' ' << agt_detil << endl;
                        //apabila perbandingan tidak sama maka data akan disimpan pada file data_anggota_sementara.txt
                     }
                  }
                  data_anggota_sementara.close(); //menutup file
                  data_anggota_override.close(); //menutup file
                  data_anggota_sementara.open("data_anggota_sementara.txt", ios:: in ); //membuka file data_anggota_sementara.txt dengan parameter in (input)
                  data_anggota_override.open("data_anggota.txt", ios::out); //membuka file data_anggota.txt dengan parameter out (output)
                  while (!data_anggota_sementara.eof()) {
                     //End Of File, apabila input tidak berhenti maka akan membaca perintah di dalam while
                     data_anggota_sementara.getline(agt_nim, 25, ' '); //membaca spasi pada karakter yang diinputkan
                     data_anggota_sementara.getline(agt_nama, 25, ' '); //membaca spasi pada karakter yang diinputkan
                     data_anggota_sementara.getline(agt_detil, 25, ' '); //membaca spasi pada karakter yang diinputkan
                     data_anggota_override << agt_nim << ' ' << agt_nama << ' ' << agt_detil << ' '; //data akan disimpan pada file data_anggota.txt
                  }
                  data_anggota_override.close(); //menutup file
                  data_anggota_sementara.close(); //menutup file
                  remove("data_anggota_sementara.txt"); //menghapus file data_anggota_sementara.txt
                  ofstream data_anggota_sunting("data_anggota.txt", ios::app); //membuat file dan update isi file tanpa membuat file baru
                  agt_nama_string = agt_nama_br; //deklarasi variabel baru
                  agt_nim_string = agt_nim_br; //deklarasi variabel baru
                  agt_detil_string = agt_detil_br; //deklarasi variabel baru
                  data_anggota_sunting << endl << agt_nim_string << ' ' << agt_nama_string << ' ' << agt_detil_string; //data akan disimpan pada file data_anggota.txt
                  data_anggota_sunting.close(); //menutup file
                  cout << "\n   Penyuntingan data berhasil."; //menampilkan output program
                  Sleep(3000); //menangguhkan eksekusi
                  goto awal; //unconditional jump statement
               } else {
                  cout << "\n   Penyuntingan data batal.";
                  Sleep(3000); //menangguhkan eksekusi
                  goto awal; //unconditional jump statement
               }
            } else {
               Sleep(3000); //menangguhkan eksekusi
               goto awal; //unconditional jump statement
            }
         }
      }

   }
   break;

   case 4: {
      hapus_anggota: //unconditional jump statement
         {
            system("cls"); //menghapus output layar
            ifstream data_anggota_hapus("data_anggota.txt"); //membaca file
            char agt_nim[25]; //variabel tipe data char dengan array ukuran 25
            char agt_nama[25]; //variabel tipe data char dengan array ukuran 25
            char agt_detil[25]; //variabel tipe data char dengan array ukuran 25
            char hapus_agt_nim[25]; //variabel tipe data char dengan array ukuran 25
            int hapus_lagi_anggota; //variabel tipe data integer
            string hapus_agt_nim_string,
            line,
            deleteLine,
            agt_nama_string,
            agt_nim_string,
            agt_detil_string; //variabel tipe data string
            int hapus_opt,
            hapus_opt_fix; //variabel tipe data integer
            cout << "\n   Input NIM Anggota: "; //menampilkan output program
            cin.ignore(); //mengabaikan atau menghapus karakter dari input buffer
            cin.getline(hapus_agt_nim, 25); //membaca spasi pada karakter yang diinputkan
            hapus_agt_nim_string = string(hapus_agt_nim); //mengkonversi nilai char ke string
            while (data_anggota_hapus >> agt_nim_string >> agt_nama_string >> agt_detil_string) { //membaca data (variabel) apabila data ada yang tidak lengkap maka berhenti
               if (hapus_agt_nim_string == agt_nim_string) { //pernyataan apabila kondisi benar (true)
                  line = agt_nim_string + ' ' + agt_nama_string + ' ' + agt_detil_string; //variable yang mencakup variable nim, nama, dan detil
                  cout << "\n   " << line << endl; //menampilkan output program
                  cout << "\n   (1) Hapus / (2) Batal: "; //menampilkan output program
                  cin >> hapus_opt; //menampilkan input program
                  if (hapus_opt == 1) { //pernyataan apabila kondisi benar (true)
                     cout << "\n Apakah Anda yakin ingin menghapus anggota tersebut? (1) Ya; (2) Tidak: "; //menampilkan output program
                     cin >> hapus_opt_fix; //menampilkan input program
                     if (hapus_opt_fix == 1) { //pernyataan apabila kondisi benar (true)
                        fstream data_anggota_sementara, data_anggota_override; //tipe data input dan output file
                        data_anggota_sementara.open("data_anggota_sementara.txt", ios::out); //membuka file anggota sementara dengan parameter out (output)
                        data_anggota_override.open("data_anggota.txt", ios:: in ); //membuka file data_anggota.txt dengan parameter in (input)
                        while (!data_anggota_override.eof()) { //End Of File, apabila input tidak berhenti maka akan membaca perintah di dalam while
                           data_anggota_override.getline(agt_nim, 25, ' '); //membaca spasi pada karakter yang diinputkan
                           data_anggota_override.getline(agt_nama, 25, ' '); //membaca spasi pada karakter yang diinputkan
                           data_anggota_override.getline(agt_detil, 25); //membaca spasi pada karakter yang diinputkan
                           if (strcmp(agt_nim, hapus_agt_nim) == 0) { //membandingkan dua variabel bertipe data char dalam string
                              continue; //memecah iterasi (melewati) atau (skip)
                           } else {
                              data_anggota_sementara << agt_nim << ' ' << agt_nama << ' ' << agt_detil << endl; //apabila perbandingan tidak sama maka data akan disimpan pada file data_anggota_sementara.txt
                           }
                        }
                        data_anggota_sementara.close(); //menutup file
                        data_anggota_override.close(); //menutup file
                        data_anggota_sementara.open("data_anggota_sementara.txt", ios:: in ); //membuka file data_anggota_sementara.txt dengan parameter in (input)
                        data_anggota_override.open("data_anggota.txt", ios::out); //membuka file data_anggota_sementara.txt dengan parameter out (output)
                        while (!data_anggota_sementara.eof()) { //End Of File, apabila input tidak berhenti maka akan membaca perintah di dalam while
                           data_anggota_sementara.getline(agt_nim, 25, ' '); //membaca spasi pada karakter yang diinputkan
                           data_anggota_sementara.getline(agt_nama, 25, ' '); //membaca spasi pada karakter yang diinputkan
                           data_anggota_sementara.getline(agt_detil, 25); //membaca spasi pada karakter yang diinputkan
                           data_anggota_override << agt_nim << ' ' << agt_nama << ' ' << agt_detil << endl; //data akan disimpan pada file data_anggota.txt
                        }
                        data_anggota_override.close(); //menutup file
                        data_anggota_sementara.close(); //menutup file
                        remove("data_anggota_sementara.txt"); //menghapus file data_anggota_sementara.txt
                        cout << "\n Anggota berhasil dihapus. Ada lagi?: (1) Ya / (2) Tidak "; //menampilkan output program
                        cin >> hapus_lagi_anggota; //menampilkan input program
                        if (hapus_lagi_anggota == 1) { //pernyataan apabila kondisi benar (true)
                           goto hapus_anggota; //unconditional jump statement
                        } else {
                           goto awal; //unconditional jump statement
                        }
                     } else {
                        goto awal; //unconditional jump statement
                     }
                  } else {
                     goto awal; //unconditional jump statement
                  }
               }
            }
            data_anggota_hapus.close(); //menutup file
         }
   }
   break;

   default: //jika input salah
      goto awal;

      break;

   }
}

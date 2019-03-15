# SoalShift_Modul2_F16

Kelompok F16 :
Hisam Widi Prayoga - 17-0026
Alfin Pradana
Himawan

# Nomor 1
Pertama yang harus dilakukan adalah mencari file yang memiliki ext dengan jpg. setelah mendapat file dengan extension .jpg, maka string tersebut harus dipotong sehingga menjadi nama file tanpa extension .jpg setelah dipotong, tambahkan extension _grey dan tambahkan lagi .png pada nama file tersebut. lalu rename nama file dengan string dengan fungsi rename() yang berfungsi untuk move dalam fungsi yang sama.

# Nomor 2

Pertama mengambil stat dari file yang akan dihapus (elen.ku). Setelah mendapatkan stat dari file tersebut, kita ambil nama owner dan nama group file tersebut. Lalu mengubah permission dari file tersebut menjadi 777. Lalu berikan kondisi, apabila nama user dan owner sama dengan "www-data" maka file elen.ku di hatiku akan terhapus. Diulang setiap 3 detik.

# Nomor 3
Pertama hal yang harus dilakukan adalah melakukan fork di dalam child sebanyak tiga kali agar mendapatkan parent dan hasil akhir yang bisa dimasukan dengan function. setelah mendapatkan urutan fork yang sesuai. masukan function unzip, touch, ls, dan grep. lalu gunakan pipe untuk mengoper hasil dari function ls yang telah melakukan list data kepada grep. lalu hasil dari grep lakukan dup untuk memasukan kedalam daftar.txt

# Nomor 4

Pertama mengambil waktu akses dari file, lalu mengambil waktu dari sistem kita. Setelah mendapatkan kedua waktu tersebut, kita bandingkan selisih waktu tersebut. Jika selisih kurang dari sama dengan 30, maka buat sebuah file baru dengan nama makan_sehat#.txt. Dimana # merupakan iterasi dari 1 sampai tak hingga. Diulang setiap 5 detik.

# Nomor 5

Buatlah sebuah counter, dikarenakan di soal nomer 5 kita akan membuat folder setiap 30menit, dimana folder tersebut diisi log setiap 1 menit. Berikan kondisi, apabila counter mod 30 sama dengan 0, maka buat sebuah folder baru. Dimana folder baru tersebut bernama waktu sistem saat membuat folder tersebut. Dalam membuat folder baru tersebut, perlu mengambil waktu system kita, lalu disimpan dalam string. Untuk permission, menggunakan permission 777, karena melibatkan file syslog. Lalu setelah keuar dari kondisi, iterasi counter. Buat sebuah file dengan nama log#.log, dimana # merupakan iterasi dari counter. Permission dari file tersebut adalah 777, karena melibatkan file system syslog. Setelah membuat file baru, copykan isi dari file var/log/syslog ke log#.log. Diulang setiap 60 detik.

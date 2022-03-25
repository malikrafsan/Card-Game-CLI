# IF2210_TB1_Laporan_03_08

> Program ini merupakan program yang ditujukan untuk Tugas Besar I Pemrograman Berorientasi Objek IF2210 Tahun ajaran 2021/2022.

## Dokumentasi Program
- Dokumentasi program ini dapat dilihat pada [link ini](https://malikrafsan.github.io/Tubes1-OOP-Doxygen-Documentation/index.html)

## Isi Repository
- Program ini terdiri atas:
  - classes folder, berisi modul dan kelas yang ada pada program ini
  - config folder, berisi semua file-file konfigurasi (items dan recipes)
  - doxygen folder (jika di-generate), berisi dokumentasi yang dihasilkan oleh doxygen secara otomatis
  - generated_tests folder, berisi test case generator untuk fungsionalitas craft
  - tests folder (jika di-generate), berisi hasil output file
  - .gitignore untuk mengabaikan file dan folder yang tidak perlu
  - dconfig berisi file konfigurasi doxygen
  - main.cpp, berisi main program
  - check.cpp, berisi program untuk testing
  - Makefile untuk compile dan testing
  - README.md berisi penjelasan program secara umum

## Cara Menjalankan Makefile
- Pastikan anda menggunakan Linux dengan C++17 atau WSL jika anda menggunakan Windows.
  ```
  sudo apt-get install make g++
  make all
  ```

## Cara Men-generate Ulang Test Case Otomatis
- Jalankan program Test Case Generator sebagai berikut.
  ```
  cd generated_tests
  g++ -std=c++17 main.cpp ../classes/FileManager/FileManager.cpp ../classes/Recipe/Recipe.cpp -o main
  ./main
  ```

## Kontributor
- 13520009 / Ahmad Romy Zahran
- 13520012 / Aji Andhika Falah
- 13520039 / Rozan Fadhil Al Hafidz
- 13520105 / Malik Akbar Hashemi Rafsanjani
- 13520117 / Hafidz Nur Rahman Ghozali

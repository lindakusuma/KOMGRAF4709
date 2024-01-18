#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
string pilih;
string pilih2;

void Translasi2D(){
    int x, y, t1, t2; // Koordinat awal (x, y) dan vektor translasi (t1, t2).

    // Meminta input koordinat awal dan vektor translasi dari pengguna
    cout << "Masukkan Titik Awal (x, y): ";
    cin >> x >> y;
    cout << "Masukkan Vektor Translasi (t1, t2): ";
    cin >> t1 >> t2;

    x = x + t1; // Melakukan translasi koordinat x.
    y = y + t2; // Melakukan translasi koordinat y.

    // Mencetak hasil translasi
    cout << "Hasil Translasi: " << x << "," << y << endl;    
}
void Rotasi2D(){
    int x, y, angle;
    const double PI = 3.14159265359;

    // Meminta input koordinat titik dan sudut rotasi dari pengguna
    cout << "Masukkan Koordinat Titik (x, y): ";
    cin >> x >> y;
    cout << "Masukkan Sudut Rotasi (derajat): ";
    cin >> angle;

    // Mengonversi sudut dari derajat ke radian
    double radianAngle = angle * (PI / 180.0);

    // Melakukan rotasi menggunakan rumus rotasi matriks
    int rotatedX = round(x * cos(radianAngle) - y * sin(radianAngle));
    int rotatedY = round(x * sin(radianAngle) + y * cos(radianAngle));
    cout << "Hasil Rotasi: " << rotatedX << "," << rotatedY << endl;
}
void Skala2D(){
    int x, y, scale_factor;

    // Meminta input koordinat titik dan faktor skala dari pengguna
    cout << "Masukkan Koordinat Titik (x, y): ";
    cin >> x >> y;
    cout << "Masukkan Faktor Skala: ";
    cin >> scale_factor;

    // Melakukan skala dengan mengalikan koordinat x dan y dengan faktor skala
    int scaledX = round(x * scale_factor);
    int scaledY = round(y * scale_factor);

    // Mencetak hasil skala
    cout << "Hasil Skala: " << scaledX << "," << scaledY << endl;
}
void Translasi3D(){
   int x, y, z, t1, t2, t3;

    // Meminta input koordinat awal dan vektor translasi dari pengguna
    cout << "Masukkan Titik Awal (x, y, z): ";
    cin >> x >> y >> z;
    cout << "Masukkan Vektor Translasi (t1, t2, t3): ";
    cin >> t1 >> t2 >> t3;

    x = x + t1; // Melakukan translasi koordinat x.
    y = y + t2; // Melakukan translasi koordinat y.
    z = z + t3; // Melakukan translasi koordinat z.

    // Mencetak hasil translasi
    cout << "Hasil Translasi 3D: " << x << "," << y << "," << z << endl;
}
void Rotasi3D(){
  int x, y, z;
    double angleX, angleY, angleZ;
    const double PI = 3.14159265359;

    // Meminta input koordinat titik dan sudut rotasi dari pengguna
    cout << "Masukkan Koordinat Titik (x, y, z): ";
    cin >> x >> y >> z;
    cout << "Masukkan Sudut Rotasi terhadap sumbu X (derajat): ";
    cin >> angleX;
    cout << "Masukkan Sudut Rotasi terhadap sumbu Y (derajat): ";
    cin >> angleY;
    cout << "Masukkan Sudut Rotasi terhadap sumbu Z (derajat): ";
    cin >> angleZ;

    // Mengonversi sudut dari derajat ke radian
    double radianAngleX = angleX * (PI / 180.0);
    double radianAngleY = angleY * (PI / 180.0);
    double radianAngleZ = angleZ * (PI / 180.0);

    // Melakukan rotasi menggunakan rumus rotasi matriks 3D
    int rotatedX = round(x * (cos(radianAngleY) * cos(radianAngleZ)) -
                         y * (cos(radianAngleX) * sin(radianAngleZ) +
                              sin(radianAngleX) * sin(radianAngleY) * cos(radianAngleZ)) +
                         z * (sin(radianAngleX) * sin(radianAngleZ) -
                              cos(radianAngleX) * sin(radianAngleY) * cos(radianAngleZ)));

    int rotatedY = round(x * (-cos(radianAngleY) * sin(radianAngleZ)) +
                         y * (cos(radianAngleX) * cos(radianAngleZ) -
                              sin(radianAngleX) * sin(radianAngleY) * sin(radianAngleZ)) +
                         z * (sin(radianAngleX) * cos(radianAngleZ) +
                              cos(radianAngleX) * sin(radianAngleY) * sin(radianAngleZ)));

    int rotatedZ = round(x * (sin(radianAngleY)) +
                         y * (-sin(radianAngleX) * cos(radianAngleY)) +
                         z * (cos(radianAngleX) * cos(radianAngleY)));

    // Mencetak hasil rotasi
    cout << "Hasil Rotasi 3D: " << rotatedX << "," << rotatedY << "," << rotatedZ << endl;
}
void Skala3D(){
   int x, y, z;
    double scale_factorX, scale_factorY, scale_factorZ;

    // Meminta input koordinat titik dan faktor skala dari pengguna
    cout << "Masukkan Koordinat Titik (x, y, z): ";
    cin >> x >> y >> z;
    cout << "Masukkan Faktor Skala terhadap sumbu X: ";
    cin >> scale_factorX;
    cout << "Masukkan Faktor Skala terhadap sumbu Y: ";
    cin >> scale_factorY;
    cout << "Masukkan Faktor Skala terhadap sumbu Z: ";
    cin >> scale_factorZ;

    // Melakukan skala dengan mengalikan koordinat x, y, dan z dengan faktor skala
    int scaledX = round(x * scale_factorX);
    int scaledY = round(y * scale_factorY);
    int scaledZ = round(z * scale_factorZ);

    // Mencetak hasil skala
    cout << "Hasil Skala 3D: " << scaledX << "," << scaledY << "," << scaledZ << endl;
}
void Clipping(){
    int x1, y1, x2, y2;
  int xmax, ymax, xmin, ymin;

  cout << "Masukkan koordinat titik awal (x1, y1): ";
  cin >> x1 >> y1;
  cout << "Masukkan koordinat titik akhir (x2, y2): ";
  cin >> x2 >> y2;
  cout << "Masukkan koordinat titik sudut kiri atas (xmin, ymin): ";
  cin >> xmin >> ymin;
  cout << "Masukkan koordinat titik sudut kanan bawah (xmax, ymax): ";
  cin >> xmax >> ymax;

  // Menentukan apakah titik awal dan titik akhir berada di dalam atau di luar
  bool titik1DiDalam = true;
  bool titik2DiDalam = true;

  // Memeriksa titik awal
  if (x1 < xmin || x1 > xmax || y1 < ymin || y1 > ymax) {
    titik1DiDalam = false;
  }

  // Memeriksa titik akhir
  if (x2 < xmin || x2 > xmax || y2 < ymin || y2 > ymax) {
    titik2DiDalam = false;
  }

  // Menentukan region code
  int regionCode = 0;
  if (titik1DiDalam && titik2DiDalam) {
    regionCode = 1;
  } else if (!titik1DiDalam && !titik2DiDalam) {
    regionCode = 2;
  } else {
    if (x1 < xmin && x2 < xmin) {
      regionCode = 3;
    } else if (x1 > xmax && x2 > xmax) {
      regionCode = 4;
    } else if (y1 < ymin && y2 < ymin) {
      regionCode = 5;
    } else if (y1 > ymax && y2 > ymax) {
      regionCode = 6;
    } else {
      regionCode = 7;
    }
    if (x1 < xmin && y1 < ymin) {
      regionCode |= 1;
    }
  }

  // Menampilkan hasil
  switch (regionCode) {
    case 1:
      cout << "Region code: 0000" << endl;
      cout << "terletak di dalam viewport." << endl;
      break;
    case 2:
      cout << "Region code: 0001" << endl;
      cout << "terletak sebelah kiri viewport." << endl;
      break;
       case 3:
        cout << "Region code: 0010" << endl;
      cout << "terletak di sebelah kanan viewport." << endl;
      break;
    case 4:
        cout << "Region code: 0100" << endl;
      cout << "terletak di sebelah bawah viewport." << endl;

      break;
    case 5:
    cout << "Region code: 0101" << endl;
      cout << "terletak di sebelah kiri bawah viewport." << endl;

      break;
    case 6:
    cout << "Region code: 0110" << endl;
      cout << "terletak di sebelah kanan bawah viewport." << endl;

      break;
    case 7:
    cout << "Region code: 1000" << endl;
      cout << "terletak di sebelah atas viewport." << endl;

      break;
    case 8:
    cout << "Region code: 1001" << endl;
      cout << "terletak di sebelah kiri atas viewport." << endl;

      break;
    case 9:
    cout << "Region code: 1010" << endl;
      cout << "terletak di sebelah kanan atas viewport." << endl;

      break;
  }
}

void runScript() {
    const char* namaSkrip = "UAS.exe"; // Ganti dengan nama skrip yang ingin dijalankan
    int hasil = system(namaSkrip);

    if (hasil == 0) {
        std::cout << "Skrip berhasil dijalankan.\n";
    } else {
        std::cerr << "Gagal menjalankan skrip.\n";
    }
}

int main(){
int choice;
int choice2;


menu:
    cout << "====================================" << endl;
    cout << "IMPLEMENTASI UAS LINDA KUSUMANINGRUM" << endl;
    cout << "====================================" << endl;
    cout << "Pilih opsi: " << endl;
    cout << "1. Transformasi 2D" << endl;
    cout << "2. Transformasi 3D" << endl;
    cout << "3. Clipping" << endl;
    cout << "4. jalankan skrip Transformasi 3D Opengl" << endl;
    cout << "Pilihanmu (1-4) = ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    Transformasi2D:
        cout << "TRANSFORMASI 2D" << endl;
        cout << "Pilih opsi: " << endl;
        cout << "1.Translasi" << endl;
        cout << "2.Rotasi" << endl;
        cout << "3.Skala" << endl;
        cout << "Pilihanmu (1-3) = ";
        cin >> choice2;
        switch (choice2){
            case 1: Translasi2D();
                goto milih;
                break;
            case 2: Rotasi2D();
                goto milih;
                break;
            case 3: Skala2D();
                goto milih;
                break;
        }
        milih:
        cout <<  "pilih lagi y/n = ";
        cin >> pilih2;
        if (pilih2== "y"){
            goto Transformasi2D;
        }
        else {
            goto menu;
        }

    case 2:
        cout << "TRANSFORMASI 3D" << endl;
        cout << "Pilih opsi: " << endl;
        cout << "1.Translasi" << endl;
        cout << "2.Rotasi" << endl;
        cout << "3.Skala" << endl;
        cout << "Pilihanmu (1-3) = ";
        cin >> choice2;
        switch (choice2){
            case 1: Translasi3D();
                break;
            case 2: Rotasi3D();
                break;
            case 3: Skala3D();
                break;
        }
        break;
    case 3:
        Clipping();
            break; 
    case 4:
        runScript(); // Memanggil fungsi untuk menjalankan skrip
        break;
    default:
        std::cout << "Opsi tidak valid.\n";
            break;
    }
    cout <<  "Coba lagi y/n = ";
    cin >> pilih;
    if (pilih== "y"){
        goto menu;
    }
}

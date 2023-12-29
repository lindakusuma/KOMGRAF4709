#include <iostream>
#include <cmath>

using namespace std;

int pilih, jumlah = 0, x, y, m, n;
int i, j, k;
int hasil[3][1];
double sudut;
char ulang = 'y';

void translasi(int x, int y)
{
    cout << "Masukkan Titik Translasi : ";
    cin >> m >> n;

    cout << "Titik awal P = " << x << " " << y << endl;

    int matriks [3][3]= {{1,0,m},{0,1,n},{0,0,1}};
    
    cout << "Matriks T = " << endl;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    int matriks2 [3][1] = {{x},{y},{1}};
    int hasil[3][1] = {{0},{0},{0}};
    

    for(i = 0; i < 3; ++i) 
    {
        for(int j = 0; j < 1; ++j) 
        {
            for(int k = 0; k < 3; ++k) 
            {
                hasil[i][j] += matriks[i][k] * matriks2[k][j];
            }
        }
    }
    
    cout << "Matriks P' = " << endl;
    for(int i = 0; i < 3; ++i) 
    {
        for(int j = 0; j < 1; ++j) 
        {
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Titik akhir P' = " << hasil[0][0] << " " << hasil[0][1] << endl;
}

void skala(int x, int y)
{
    cout << "Masukkan Titik Skala : ";
    cin >> m >> n;

    cout << "Titik awal P = " << x << " " << y << endl;

    int matriks [3][3]= {{m,0,0},{0,n,0},{0,0,1}};
    int hasil[3][1] = {{0},{0},{0}};
    
    cout << "Matriks T = " << endl;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    int matriks2 [3][1] = {{x},{y},{1}};

    for(i = 0; i < 3; ++i) 
    {
        for(int j = 0; j < 1; ++j) 
        {
            for(int k = 0; k < 3; ++k) 
            {
                hasil[i][j] += matriks[i][k] * matriks2[k][j];
            }
        }
    }

    cout << "Matriks P' = " << endl;
    for(int i = 0; i < 3; ++i) 
    {
        for(int j = 0; j < 1; ++j) 
        {
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Titik akhir P' = " << hasil[0][0] << " " << hasil[0][1] << endl;

}

void rotasi(int x, int y)
{

    cout << "Masukkan Sudut Rotasi : ";
    cin >> sudut;

    double cosSudut = round(cos(sudut));
    double sinSudut = round(sin(sudut) * -1);
    cout << "Titik awal P = " << x << " " << y << endl;

    double matriks [3][3]= {{cosSudut,-sinSudut,0},{sinSudut,cosSudut,0},{0,0,1}};
    double hasil[3][1] = {{0},{0},{0}};
    
    cout << "Matriks T = " << endl;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    double matriks2 [3][1] = {{x},{y},{1}};

    for(i = 0; i < 3; ++i) 
    {
        for(int j = 0; j < 1; ++j) 
        {
            for(int k = 0; k < 3; ++k) 
            {
                hasil[i][j] += matriks[i][k] * matriks2[k][j];
            }
        }
    }

    cout << "Matriks P' = " << endl;
    for(int i = 0; i < 3; ++i) 
    {
        for(int j = 0; j < 1; ++j) 
        {
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Titik akhir P' = " << hasil[0][0] << " " << hasil[0][1] << endl;
    
}

int main()
{
   
    cout << "- Transformasi Matriks 2D - " << endl;
    menu:
    cout << "Silahkan dipilih : " << endl;
    cout << "1. Translasi " << endl;
    cout << "2. Skala " << endl;
    cout << "3. Rotasi " << endl;
    cout << "Pilihanmu (1-3) = ";
    cin >> pilih;

    if(pilih <= 3)
    {
        int hasil[3][1] = {{0},{0},{0}};
        cout << "Masukkan Titik Awal P : ";
        cin >> x >> y;
        switch (pilih)
        {
        case 1 : translasi(x, y);
            break;

        case 2 : skala(x, y);
            break;

        case 3 : rotasi(x, y);
            break;
        }

        cout << "Ingin mencoba lagi ? (y/n) : ";
        cin >> ulang;
        if(ulang == 'y')
        {
            goto menu;
        }
        else 
        {
            cout << "Terima kasih sudah mampir :)" << endl;
            cout << "Jangan lupa Bahagia :)" << endl;
        }
    }
    else 
    {
        cout << "Mohon Maaf Pilihanmu Tidak Tersedia :(" << endl;
        goto menu;
    }

    return 0;
}
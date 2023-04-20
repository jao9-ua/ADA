#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm> //Función max()

using namespace std;

bool lecturaFichero(string inputFile, int &n, int &T, vector<vector<int>> &matriz)
{
    // Creamos un archivo de lectura
    ifstream file;
    file.open(inputFile.c_str(), ios::in);
    if (file.is_open())
    {
        string numero = "";

        // Recorremos el fichero linea a linea
        file >> n >> T;

        // Leer valores de la matriz
        int valor;
        for (int i = 0; i < n; i++)
        {
            vector<int> fila;
            for (int j = 0; j < T; j++)
            {
                file >> valor;
                fila.push_back(valor);
            }
            matriz.push_back(fila);
        }
        file.close();
        return true;
    }
    else
    {
        cout << "No se pudo abrir:  " << inputFile << endl;
        return false;
    }
}

bool esUno(vector<vector<int>> &matrix, int i, int j)
{
    if (i < 0 || j < 0 || (unsigned long)i >= matrix.size() || (unsigned long)j >= matrix[0].size() || matrix[i][j] == 0)
    {
        return false;
    }
    return true;
}



bool maze_naive(vector<vector<int>> &matrix, int i, int j, vector<vector<string>> &res, int cont)
{
    // Si llega a la esquina inferior derecha, devuelve true
    cout << "holu: " << cont << endl;
    if(!esUno(matrix, i, j))
    {
        res[i][j]='X';
        return false;
    }
    else if(i==0 && j==0)
    {
        res[i][j]==to_string(1);
    }
    
    if ((unsigned long)i == matrix.size() - 1 && (unsigned long)j == matrix[0].size() - 1)
    {
        if (esUno(matrix, i, j))
        {
            res[i][j] = to_string(cont);
            return true;
        }
        else
        {
            return false;
        }
    }

    if (esUno(matrix, i+1, j+1))
    { // Mover hacia abajo derecha
        if ( maze_naive(matrix, i + 1, j + 1, res, cont+1))
        {
            res[i][j] = to_string(cont);
            return true;
        }
    }
    // Comprueba si la posición actual es una posición válida
    if (esUno(matrix, i, j+1))
    { // Mover hacia la derecha
        if ( maze_naive(matrix, i, j + 1, res, cont+1))
        {
            res[i][j] = to_string(cont);
            return true;
        }
    }

    if (esUno(matrix, i+1, j))
    { // Mover hacia abajo
        if (maze_naive(matrix, i + 1, j, res, cont+1))
        {
            res[i][j] = to_string(cont);
            return true;
        }
    }
    
   
    

    // Si no se puede mover hacia la derecha ni hacia abajo, devuelve false
    return false;
}

bool maze_memo()
{
    return false;
}

int main(int argc, char *argv[])
{

    string file_name;
    int n = -1, T = -1;
    vector<vector<int>> matriz;

    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];
        if (arg == "-f")
        {
            // Comprobamos que no sea el último argumento
            if (i != argc - 1)
            {
                file_name = argv[i + 1];
                i++;
            }
            else
            {
                cout << "ERROR: file name needed." << endl;
                return false;
            }
        }
        else if (arg == "--ignore-naive")
        {
        }
        else if (arg == "-p")
        {
        }
        else if (arg == "-t")
        {
        }
    }
    if (lecturaFichero(file_name, n, T, matriz))
    {
        cout << "mostrar matriz" << endl;
        for (unsigned long i = 0; i < matriz.size(); i++)
        {
            for (unsigned long j = 0; j < matriz[i].size(); j++)
            {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
        
    }
    vector<vector<string>> res (matriz.size(), vector<string>(matriz[0].size()));
    if (maze_naive(matriz, 0, 0, res, 1))
    {
        cout << "holi" << endl;
    }
    cout << "mostrar res" << endl;
        for (unsigned long i = 0; i < res.size(); i++)
        {
            for (unsigned long j = 0; j < res[i].size(); j++)
            {
                if(res[i][j].empty())
                {
                    res[i][j]= '-';
                }
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
}

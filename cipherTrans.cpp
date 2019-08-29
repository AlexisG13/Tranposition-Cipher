#include <map>
#include <iostream>
using namespace std; 

string const key = "KEOLAND"; 
map<int,int> keyMap; 

void ordenColumnas() 
{			 
	for(int i=0; i < key.length(); i++) 
	{ 
		keyMap[key[i]] = i; 
	} 
} 


string encriptarMensaje(string msg) 
{ 
	int row,col,j; 
	string cipher = ""; 
	
	col = key.length(); 
	row = msg.length()/col; 
	
	if (msg.length() % col) 
		row += 1; 

	char matrix[row][col]; 

	for (int i=0,k=0; i < row; i++) 
	{ 
		for (int j=0; j<col; ) 
		{ 
			if(msg[k] == '\0') 
			{ 
				
				matrix[i][j] = '_'; 
				j++; 
			} 
			
			if( isalpha(msg[k]) || msg[k]==' ') 
			{ 
				matrix[i][j] = msg[k]; 
				j++; 
			} 
			k++; 
		} 
	} 

	for (map<int,int>::iterator ii = keyMap.begin(); ii!=keyMap.end(); ++ii) 
	{ 
		j=ii->second; 
		
		for (int i=0; i<row; i++) 
		{ 
			if( isalpha(matrix[i][j]) || matrix[i][j]==' ' || matrix[i][j]=='_') 
				cipher += matrix[i][j]; 
		} 
	} 
	return cipher; 
} 



int main(void) 
{ 
	string msg = "DRACUKEO EL EMPALADOR"; 
	ordenColumnas(); 
	string cifrado = encriptarMensaje(msg); 
	cout << "Tu mensaje cifrado es: " << cifrado << endl; 
	return 0; 
} 

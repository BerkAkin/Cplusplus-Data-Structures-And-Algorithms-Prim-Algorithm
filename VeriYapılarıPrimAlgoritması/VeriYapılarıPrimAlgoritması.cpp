//191307012 BERK AKIN
#include "stdafx.h"
#include <iostream>
#include <list> 
#include <queue>
using namespace std; 

# define Sonsuz 999999 
typedef pair<int, int> �ift; 

class Graf 
{ 
    int Vertex;
    list<�ift> *Kom�u; 
public: 
    Graf(int Vertex);
    void YeniKenar(int i, int j, int k); 
    void Prim(); 
}; 
 
Graf::Graf(int Vertex) 
{ 
    this->Vertex = Vertex; 
    Kom�u = new list<�ift> [Vertex]; 
} 
  
void Graf::YeniKenar(int i, int j, int k) 
{ 
    Kom�u[i].push_back(make_pair(j, k)); 
} 
  
 
void Graf::Prim() 
{ 
    priority_queue< �ift, vector <�ift> , greater<�ift> > �ncelik; 

    int Ba�lang�� = 0; 

    vector<int> De�er(Vertex, Sonsuz); 
    vector<int> Bir�st(Vertex, -1); 
    vector<bool> A�a�(Vertex, false); 

    �ncelik.push(make_pair(0, Ba�lang��)); 
    De�er[Ba�lang��] = 0; 

    while (!�ncelik.empty()) 
    {
        int u = �ncelik.top().second; 
        �ncelik.pop(); 
        A�a�[u] = true;  
        list<�ift>::iterator i; 
        for (i = Kom�u[u].begin(); i != Kom�u[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int A��rl�k = (*i).second; 
            if (A�a�[v] == false && De�er[v] > A��rl�k) 
            {           
                De�er[v] = A��rl�k; 
                �ncelik.push(make_pair(De�er[v], v)); 
                Bir�st[v] = u; 
            } 
        } 
    } 
	cout<<"S�ra�yla En K�sa Yollar:"<<endl;
    for (int i = 1; i < Vertex; ++i) 
		cout<<Bir�st[i]<<" --> "<< i<<endl;
} 
  

int main() 
{ 
	setlocale(LC_ALL,"Turkish");
    int B�y�kl�k = 9; 
    Graf YeniGraf(B�y�kl�k); 
    YeniGraf.YeniKenar(0, 1, 4); YeniGraf.YeniKenar(0, 5, 8); YeniGraf.YeniKenar(1, 2, 8);YeniGraf.YeniKenar(1, 7, 11); 
    YeniGraf.YeniKenar(2, 3, 7); YeniGraf.YeniKenar(2, 8, 2); YeniGraf.YeniKenar(2, 5, 4); YeniGraf.YeniKenar(3, 4, 9); 
    YeniGraf.YeniKenar(3, 5, 14); YeniGraf.YeniKenar(4, 4, 10);YeniGraf.YeniKenar(5, 6, 2); YeniGraf.YeniKenar(6, 7, 1); 
    YeniGraf.YeniKenar(6, 8, 6); YeniGraf.YeniKenar(7, 8, 7); 
  
    YeniGraf.Prim(); 
	cout<<endl<<endl;
    return 41; 
} 
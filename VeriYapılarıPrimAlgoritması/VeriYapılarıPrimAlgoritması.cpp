//191307012 BERK AKIN
#include "stdafx.h"
#include <iostream>
#include <list> 
#include <queue>
using namespace std; 

# define Sonsuz 999999 
typedef pair<int, int> Çift; 

class Graf 
{ 
    int Vertex;
    list<Çift> *Komþu; 
public: 
    Graf(int Vertex);
    void YeniKenar(int i, int j, int k); 
    void Prim(); 
}; 
 
Graf::Graf(int Vertex) 
{ 
    this->Vertex = Vertex; 
    Komþu = new list<Çift> [Vertex]; 
} 
  
void Graf::YeniKenar(int i, int j, int k) 
{ 
    Komþu[i].push_back(make_pair(j, k)); 
} 
  
 
void Graf::Prim() 
{ 
    priority_queue< Çift, vector <Çift> , greater<Çift> > Öncelik; 

    int Baþlangýç = 0; 

    vector<int> Deðer(Vertex, Sonsuz); 
    vector<int> BirÜst(Vertex, -1); 
    vector<bool> Aðaç(Vertex, false); 

    Öncelik.push(make_pair(0, Baþlangýç)); 
    Deðer[Baþlangýç] = 0; 

    while (!Öncelik.empty()) 
    {
        int u = Öncelik.top().second; 
        Öncelik.pop(); 
        Aðaç[u] = true;  
        list<Çift>::iterator i; 
        for (i = Komþu[u].begin(); i != Komþu[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int Aðýrlýk = (*i).second; 
            if (Aðaç[v] == false && Deðer[v] > Aðýrlýk) 
            {           
                Deðer[v] = Aðýrlýk; 
                Öncelik.push(make_pair(Deðer[v], v)); 
                BirÜst[v] = u; 
            } 
        } 
    } 
	cout<<"Sýraýyla En Kýsa Yollar:"<<endl;
    for (int i = 1; i < Vertex; ++i) 
		cout<<BirÜst[i]<<" --> "<< i<<endl;
} 
  

int main() 
{ 
	setlocale(LC_ALL,"Turkish");
    int Büyüklük = 9; 
    Graf YeniGraf(Büyüklük); 
    YeniGraf.YeniKenar(0, 1, 4); YeniGraf.YeniKenar(0, 5, 8); YeniGraf.YeniKenar(1, 2, 8);YeniGraf.YeniKenar(1, 7, 11); 
    YeniGraf.YeniKenar(2, 3, 7); YeniGraf.YeniKenar(2, 8, 2); YeniGraf.YeniKenar(2, 5, 4); YeniGraf.YeniKenar(3, 4, 9); 
    YeniGraf.YeniKenar(3, 5, 14); YeniGraf.YeniKenar(4, 4, 10);YeniGraf.YeniKenar(5, 6, 2); YeniGraf.YeniKenar(6, 7, 1); 
    YeniGraf.YeniKenar(6, 8, 6); YeniGraf.YeniKenar(7, 8, 7); 
  
    YeniGraf.Prim(); 
	cout<<endl<<endl;
    return 41; 
} 
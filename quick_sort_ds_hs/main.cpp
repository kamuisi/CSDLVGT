#include <iostream>

using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};
void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
void Output(Hocsinh hs) {
    cout << '[' << hs.Maso << "\t" << hs.Hoten << "\t" << hs.Gioitinh << "\t" << hs.Namsinh << "\t" << hs.TBK << "]\n";
}


int QuickSort(Hocsinh [] , int, int);

int main()
{
    Hocsinh *ls = NULL;
    int n;
    cin >> n;
    ls = new Hocsinh[n];
    for (int i = 0; i < n; i++) {
        Input(ls[i]);
    }
    cout << QuickSort(ls, 0, n-1) << endl;
    for (int i = 0; i < n; i++) {
        Output(ls[i]);
    }
    delete [] ls;
    return 0;
}

int QuickSort(Hocsinh ls[], int b, int e) {
   int i,j;
    int count=0;
    if(b>=e) return 0;
    i=b; j=e;
    while(i<j){
        while(ls[i].Hoten<ls[b].Hoten) i++;
        while(ls[j].Hoten>ls[b].Hoten) j--;
        if(i<j){
            swap(ls[i],ls[j]);
            i++; j--;
            count++;
        }
    }
    count+=QuickSort(ls,b,j);
    count+=QuickSort(ls,i,e);
    return count;
}
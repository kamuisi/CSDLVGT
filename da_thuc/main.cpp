/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};


void Nhap(DATHUC &B,const double &heso,const int &somu)
{
    Node *Insert = new Node();
    Insert->data= new DONTHUC(heso, somu);
    if( B.head != nullptr)
    {
        B.tail->next = Insert;
    }
    else
    {
        B.head = Insert;
    }
    B.tail = Insert;
}

void Xuat(DATHUC &B)
{
    stringstream ss;
    DATHUC *Buff = new DATHUC(); 
    Buff->head = B.head;
    while(Buff->head != nullptr)
    {   
        if(Buff->head->data->heso == 0)
        {
            Buff->head = Buff->head->next;
            continue;
        }
        else if(Buff->head->data->heso == 1)
        {
            if(ss.rdbuf()->in_avail() != 0)
            {
                ss << '+';
            }
        }
        else if(Buff->head->data->heso == -1)
        {
            ss << '-';
        }
        else 
        {
            if(Buff->head->data->heso > 0 && ss.rdbuf()->in_avail() != 0)
            {
                ss << '+';
            }
            ss << Buff->head->data->heso;
        }
        if(Buff->head->data->somu == 0)
        {
            if(abs(Buff->head->data->heso) == 1)
            {
                ss << '1';
            }
            Buff->head = Buff->head->next;
            continue;
        }
        else if(Buff->head->data->somu == 1)
        {
            ss << 'x';
        }
        else
        {
            ss << "x^" << Buff->head->data->somu;
        }
        Buff->head = Buff->head->next;
    }
    if(ss.rdbuf()->in_avail() != 0)
    {
        cout << ss.str();
    }
    else
    {
        cout << '0';
    }
}

double TinhDaThuc(DATHUC &B, const double &x)
{
    double Result{0};
    while(B.head != nullptr)
    {
        Result+= double(B.head->data->heso * pow(x, B.head->data->somu));
        B.head = B.head->next;
    }
    return Result;
}

int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}

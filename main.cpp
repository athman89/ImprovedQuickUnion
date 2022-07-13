#include <iostream>

using namespace std;
//Quick union with path compression
class QUImproved{
private:
    int root (int i);
    int M;
    int* id;
    int* sz;//array to keep count of number of objects in the tree with root i
public:
    QUImproved(int N):M{N}{
        int i;
     id =new int[N];
     sz = new int[N];
        for (i = 0; i < N; i++) {
         id[i] = i;
         sz[i] = 1;
        }

    }
    bool Connected(int p,int q);
    void Union(int p, int q);
    ~QUImproved();
};

void QUImproved::Union(int p, int q) {//root of smaller tree is linked to root of larger tree
  int i = root(p);                   //update s[] array
  int j = root(q);
  if (i == j) return;
  if (sz[i] < sz[j]){
      id[i] = j;
      sz[j] += sz[i];
  } else{
      id[j] = i;
      sz[i] += sz[j];
  }
}

bool QUImproved::Connected(int p, int q) {//check if the roots are equal
    return root(p) == root(q);
}

int QUImproved::root(int i) {//
    while (i != id[i]){
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

QUImproved::~QUImproved() {    //destructor
    cout <<"we are done";
}

int main() {
 int A,b,c;
 cout <<"Enter any number 10 and above"<<endl;
 cin >> A;
 QUImproved Q(A);
 while (cin >> b >> c){
     if (!Q.Connected(b,c)){
         Q.Union(b,c);}
         cout << b <<"-"<< c <<endl;

 }
    return 0;
}

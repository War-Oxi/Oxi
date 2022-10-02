#include <iostream>
using namespace std;

int global_fiboarr[42] = {0, 1,};

int Fibo(int num){
    if (num == 0 || num == 1)
        return global_fiboarr[num];
    else if(global_fiboarr[num] == 0)
        global_fiboarr[num] = Fibo(num-1) + Fibo(num-2);
    return global_fiboarr[num];
}

int main(){
    int repeat_num(0);
    cin >> repeat_num;

    int tmp(0);
    for(int i=0; i<repeat_num; i++){
        cin >> tmp;
        if(tmp == 0)
            cout << "1 0" << endl;
        else
            cout << Fibo(tmp-1) << " " << Fibo(tmp) << endl;
    }

    return 0;
}


//#include <iostream>
//using namespace std;
//long long fiboarr[50] = {0,1,};
//long long fibo(int N)
//{
//    if(N == 0 || N == 1)
//        return fiboarr[N];
//    else if(fiboarr[N] == 0)
//        fiboarr[N] = fibo(N-1) + fibo(N-2);
//    return fiboarr[N];
//}
//int main() {
//    int T;
//    cin >> T;
//    int tmp;
//    for(int i = 0; i < T; i++)
//    {
//        cin >> tmp;
//        if(tmp == 0)
//            cout << "1 0" << '\n';
//        else
//            cout << fibo(tmp-1) << ' ' << fibo(tmp) << '\n';
//    }
//}
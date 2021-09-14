#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <chrono>
#include <list>
using namespace std;

struct triangle
{
    int a;    
    int b;    
    int c;
    vector <int> co;    
    float area;
    
};

struct areas_t {
    vector <triangle> areas_v;
    int count;
};

struct List
{
    int data;
    List* next;
};

void Merge(triangle* arr, int begin, int end)
{
    int i = begin,
        t = 0,
        mid = begin + (end - begin) / 2,
        j = mid + 1;
        triangle* d = new triangle[1000];
        

    while (i <= mid && j <= end) {

        if (arr[i].area <= arr[j].area) {
            d[t] = arr[i]; i++;
        }
        else {
            d[t] = arr[j]; j++;
        }
        t++;
    }

    while (i <= mid) {
        d[t] = arr[i]; i++; t++;
    }

    while (j <= end) {
        d[t] = arr[j]; j++; t++;
    }

    for (i = 0; i < t; i++)
        arr[begin + i] = d[i];
}

void MergeSort(triangle* arr, int left, int right)
{
    triangle temp;
    if (left < right)
        if (right - left == 1) {
            if (arr[right].area < arr[left].area) {
                temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        }
        else {
            MergeSort(arr, left, left + (right - left) / 2);
            MergeSort(arr, left + (right - left) / 2 + 1, right);
            Merge(arr, left, right);
        }
}



triangle* QuckSort(triangle* mas, int size) {
    
    int i = 0;
    int j = size - 1;

    
    triangle mid = mas[size / 2];

   
    do {
       
        while (mas[i].area < mid.area) {
            i++;
        }
        
        while (mas[j].area > mid.area) {
            j--;
        }

        
        if (i <= j) {
            triangle tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    
    if (j > 0) {
        
        QuckSort(mas, j + 1);
    }
    if (i < size) {
        
        QuckSort(&mas[i], size - i);
    }
    return mas;
}



areas_t countTricycles(vector<vector<int>> m, int n) {
    
    vector <triangle> areas;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] != 0) {
                for (int k = 0; k < n; k++) {
                    if (k != i && m[j][k] != 0 && m[i][k] != 0) {
                        count++;
                        bool flag=true;
                        vector <int> vec;
                        vector <int> coords;                       
                        vec.push_back(m[i][k]);
                        vec.push_back(m[j][k]);
                        vec.push_back(m[i][j]);
                        coords.push_back(i*k);
                        coords.push_back(j*k);
                        coords.push_back(i*j);
                        sort(coords.begin(), coords.end());
                        sort(vec.begin(), vec.end());            
                        for (int i = 0; i < areas.size(); i++)
                        {                            
                            if (areas[i].co == coords) {
                                flag = false;
                            }
                        }

                        if (flag)
                        {
                            triangle t;
                            t.a = vec[0];                            
                            t.b = vec[1];
                            t.c = vec[2];
                            t.co = coords;
                            //cout << coords[0] << " " << coords[1] << " " << coords[2] << endl;
                            float p = (t.a + t.b + t.c);
                            p = p / 2;                            
                            t.area = sqrt(p * (p - t.a) * (p - t.b) * (p -  t.c));                        
                            areas.push_back(t);
                            
                        }
                        

                    }                    
                }
            }
        }
    }
    cout<<"Number of cycles length 3: "<<count / 6<<endl;
    areas_t areas_end;
    areas_end.areas_v = areas;
    areas_end.count = count/6;
    return areas_end;
}

//int fill_the_matrix_binar(const int N, int** m){
//    ifstream F;
//    F.open("in.txt", ios::in);
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            int a;
//            F >> a;
//            if (a==0)
//                m[i][j] = 0;
//            else
//                m[i][j] = 1;
//            
//            
//            //cout << m[i][j] << " ";
//        }
//        //cout << endl;
//    }
//    return m;
//}



//int **fill_the_matrix_binar_arr(const int N, const int m) {
//    ifstream F;
//    F.open("in.txt", ios::in);
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            int a;
//            F >> a;
//            if (a == 0)
//                m[i][j] = 0;
//            else
//                m[i][j] = 1;
//
//
//            //cout << m[i][j] << " ";
//        }
//        //cout << endl;
//    }
//    return m;
//}

//List adjacency_structure(int arr, const int N) {
//    using list = std::list<int>;
//
//    
//
//}


list* adjacency_structure(int** arr, const int N) {
    list* adj = new list[N]();
    for (int i = 0; i < N; i++) {
        list ll;
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] != 0) {
                ll.push_back(j);
            }
        }
        adj[i] = ll;
    }

    return adj;
}

int** array_generator(unsigned int dim1, unsigned int dim2) {
    int** ptrary = new int* [dim1];
    for (int i = 0; i < dim1; i++) {
        ptrary[i] = new int[dim2];
    }
    return ptrary;
}

vector<vector<int>> fill_the_matrix(const int N, vector<vector<int>> m) {
    ifstream F;
    F.open("in.txt", ios::in);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            F >> m[i][j];
            //cout << m[i][j] << " ";
        }
        //cout << endl;
    }
    return m;
}

bool dfs(int s, const int N, vector<vector<int>> m, bool *used) {
    used[s] = 1;
    for (int i = 0; i < N; i++) {
        if (used[i] == 0 && m[s][i] == 1)
            dfs(i, N, m, used);
    }
    return *used;
}

int main()
{
    const int N = 8;
    vector < vector <int> > m(N, vector <int>(N));
    vector < vector <int> > g(N, vector <int>(N));
    
    bool used[N]{};
    //int arr[N][N];
    int cnt = 0;
    int** arr;
   
    arr = array_generator(N,N);
   /* arr = fill_the_matrix_binar_arr(N, arr);*/
    //cout << endl;
    //g = fill_the_matrix(N, g);
    

    for (int i = 0; i < N; i++) {
        if (used[i] == 0) {
            *used=dfs(i, N, m, used);
            cnt++;
        }
    }

    


    //
    //cout<<"Number of components: " << cnt << endl;  
   
    //areas_t areas;
    //areas = countTricycles(g, N);
    //triangle* arr = new triangle[areas.count];
    //triangle* arr2 = new triangle[areas.count];
    ////cout << endl;
    //for (int i = 0; i < areas.count; i++)
    //{
    //    arr[i] = areas.areas_v[i];
    //    //cout <<"S_"<<i<<": "<< areas[i].area<<endl;
    //    
    //}
    //arr2 = arr;
    //chrono::steady_clock sc;   
    //auto start = sc.now();     

    //arr = QuckSort(arr, areas.count);

    //auto end = sc.now();       
    //auto time_span = static_cast<chrono::duration<double>>(end - start);   
    //cout << endl;
    //cout << "QuckSort took: " << time_span.count() << " seconds"<<endl;
    //cout << endl;
    //for (int i = 0; i < areas.count; i++)
    //{
    //    cout << i + 1 << ": ";
    //    cout << "a = " << arr[i].a << ", ";
    //    cout << "b = " << arr[i].b << ", ";
    //    cout << "c = " << arr[i].c << ", ";
    //    cout << "S = " << arr[i].area << endl;
    //}

    //chrono::steady_clock sc2;
    //auto start2 = sc2.now();

    //MergeSort(arr2, 0, areas.count-1);

    //auto end2 = sc2.now();
    //auto time_span2 = static_cast<chrono::duration<double>>(end2 - start2);
    //cout << endl;
    //cout << "MergeSort took: " << time_span2.count() << " seconds"<<endl;
    //cout << endl;
    //arr = arr2;
    //for (int i = 0; i < areas.count; i++)
    //{
    //    cout << i+1 << ": ";
    //    cout << "a = " << arr[i].a<<", ";
    //    cout << "b = " << arr[i].b << ", ";
    //    cout << "c = " << arr[i].c << ", ";
    //    cout <<"S = "<< arr[i].area <<endl;

    //}

    return 0;
}
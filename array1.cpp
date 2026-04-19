#include<iostream>
#include<cmath>
using namespace std; 

int main(){
    int n , arr[100];
    cout << " Enter number of elements - ";
    cin >> n;
    cout << "Enter " << n << " elements: \n " ;

    for( int i= 0 ; i<n ; i++){
        cin >> arr[i];
        cout << arr[i] ;
    }

    int max ;
    max = arr[0];
    for( int i = 1 ; i < n ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout << "Maximum element is - " << max ;
    cout <<endl;

    int min ;
    min = arr[0];
    for( int i = 1 ; i < n ; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    cout << "Minimum element is - " << min ;    

int average;
int sum =0;



    


return 0; 
}
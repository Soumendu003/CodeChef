#include<iostream>
#include<stdlib.h>
using namespace std;

struct value{
    uint32_t A;
    uint32_t B;
};


int main(){
    uint32_t N, i;

    cin >> N;       // Takes number of Nodes

    value* val_list = (value*)calloc(N,sizeof(value));

    for(i = 0; i < N; i++){
        cin >> val_list[i].A;     // Takes the A val
    }

    for(i = 0; i < N; i++){
        cin >> val_list[i].B;     // Takes the B val
    }

    
}
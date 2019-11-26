#include<iostream>
#include<stdlib.h>
using namespace std;

struct value{
    uint32_t A;
    uint32_t B;
    uint32_t child_ptr;
};

struct links{
    uint32_t child_index;
    uint32_t next_ptr;
};

void link_edge(uint32_t u, uint32_t v, uint32_t loc, value* val_list, links* link_list){
    if(val_list[u].child_ptr == 0){
        link_list[loc].child_index = v;
        link_list[loc].next_ptr = 0; // invalid ptr
        val_list[u].child_ptr = loc;
    }
    else{
        uint32_t pre_loc = val_list[u].child_ptr = loc;
        link_list[loc].child_index = v;
        link_list[loc].next_ptr = pre_loc;  // re-directs to previously got childs list
        val_list[u].child_ptr = loc;
    }
}



int main(){
    uint32_t N, i;

    cin >> N;       // Takes number of Nodes

    value* val_list = (value*)calloc(N, sizeof(value));
    links* link_list = (links*)calloc(N, sizeof(links));           // First entry in the link_list is invalid

    for(i = 0; i < N; i++){
        cin >> val_list[i].A;     // Takes the A val
    }

    for(i = 0; i < N; i++){
        cin >> val_list[i].B;     // Takes the B val
    }

    uint32_t u, v;
    for(i = 1; i < N ; i++){      // N-1 iteration. one for each edge.
        cin >> u;
        cin >> v;
        link_edge(u-1, v-1, i, val_list, link_list);
    }


}
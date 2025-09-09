#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum e_type {
TypeFAT32 = 0,
TypeEXT4 = 1,
TypeNTFS = 2
} type_t;

typedef struct node {
    void* data;
    struct node* next;
    struct node* prev;
} node_t;
typedef struct list {
    type_t type;
    uint8_t size;
    node_t* first;
    node_t* last;
} list_t;




typedef uint32_t fat32_t;
typedef uint32_t ext4_t;
typedef uint32_t ntfs_t;

fat32_t* new_fat32(){
    return malloc(sizeof(fat32_t));
}
ext4_t* new_ext4() {
    return malloc(sizeof(ext4_t));
}
ntfs_t* new_ntfs(){
    return malloc(sizeof(ntfs_t));
}
fat32_t* copy_fat32(fat32_t* file){
    fat32_t* archivo = malloc(sizeof(fat32_t));
    *archivo = *file;
    return archivo;
}
ext4_t* copy_ext4(ext4_t* file){
    ext4_t* archivo = malloc(sizeof(ext4_t));
    *archivo = *file;
    return archivo;
}
ntfs_t* copy_ntfs(ntfs_t* file){
    ntfs_t* archivo = malloc(sizeof(ntfs_t));
    *archivo = *file;
    return archivo;
}
void rm_fat32(fat32_t* file){
    free(file);
}
void rm_ext4(ext4_t* file){
    free(file);
}
void rm_ntfs(ntfs_t* file){
    free(file);
}

list_t* listNew(type_t t) {
    list_t* l = malloc(sizeof(list_t));
    l->type = t; // l->type es equivalente a (*l).type
    l->size = 0;
    l->first = NULL;
    l->last = NULL;
    return l;

}

void listAddFirst(list_t* l, void* data) {
    node_t* n = malloc(sizeof(node_t));
    switch(l->type) {
        case TypeFAT32:
            n->data = (void*) copy_fat32((fat32_t*) data);
            break;
        case TypeEXT4:
            n->data = (void*) copy_ext4((ext4_t*) data);
            break;
        case TypeNTFS:
            n->data = (void*) copy_ntfs((ntfs_t*) data);
            break;
    }

    n -> prev = NULL;
    n->next = l->first;
    if (l->first){
        l -> first ->prev = n;
    }
    l->first = n;
    l->size++;
}

void listAddLast(list_t* l, void* data) {
    node_t* n = malloc(sizeof(node_t));
    switch(l->type) {
        case TypeFAT32:
            n->data = (void*) copy_fat32((fat32_t*) data);
            break;
        case TypeEXT4:
            n->data = (void*) copy_ext4((ext4_t*) data);
            break;
        case TypeNTFS:
            n->data = (void*) copy_ntfs((ntfs_t*) data);
            break;
    }

    n -> next = NULL;
    n -> prev = l ->last;
    if (l->last){
        l -> last -> next = n;
    }
    l -> last = n;
    l->size++;
}

//se asume: i < l->size
void* listGet(list_t* l, uint8_t i){
node_t* n = l->first;
for(uint8_t j = 0; j < i; j++)
    n = n->next;
return n->data;
}

void listSwap(list_t* l, uint8_t i, uint8_t j){
    if (l->size > 1 && i != j){
        node_t* n = l->first;
        node_t* ant1 = NULL;
        node_t* post1 = n -> next;
        for(uint8_t k = 0; k < i; k++){
            ant1 = n;
            n = n-> next;
            post1 = n -> next;
        }
        node_t* m = l->first;
        
        for(uint8_t k = 0; k < j - 1; k++){
            m = m->next;
        }
        if (i != 0 && j != 0){
            n -> next = m -> next -> next;
            m -> next -> next = post1;
            ant1 -> next = m -> next;
            m -> next = n;
        } else if (i != 0){
            l -> first = n;
            n -> next = m -> next;
            m -> next = post1;
            ant1 -> next = m;
        } else {
            l->first = m ->next;
            n -> next = m -> next -> next;
            m -> next -> next = post1;
            m -> next = n;
            
        }

    }
    return;

    
}

//Mejor version
void listSwap2(list_t* l, uint8_t i, uint8_t j) {
    // If indices are the same, no need to swap
    if (i == j) return;

    if (l->size > 1 && i < l->size && j < l->size) {
        // Ensure i < j to simplify the logic
        if (i > j) {
            uint8_t temp = i;
            i = j;
            j = temp;
        }

        node_t* prev1 = NULL;
        node_t* node1 = l->first;
        node_t* prev2 = NULL;
        node_t* node2 = l->first;

        // Traverse to the i-th node (node1) and its previous node (prev1)
        for (uint8_t k = 0; k < i; k++) {
            prev1 = node1;
            node1 = node1->next;
        }

        // Traverse to the j-th node (node2) and its previous node (prev2)
        for (uint8_t k = 0; k < j; k++) {
            prev2 = node2;
            node2 = node2->next;
        }

        // If one of the nodes is the head node, handle this separately
        if (prev1) {
            prev1->next = node2;
            node2 -> prev = prev1;
        } else {
            l->first->prev = node2;
            l->first = node2;  // node1 is the head, so update the head pointer
        }

        if (prev2) {
            prev2->next = node1;
            node1->prev = prev2;
        } else {
            l->first->prev = node1;
            l->first = node1;  // node2 is the head, so update the head pointer
        }

        // Swap the next pointers of the two nodes
        node_t* temp = node1->next;
        node_t* tempPrev = node1->prev;
        node1->next = node2->next;
        node1->prev = node2->prev;
        node2->next = temp;
        node2->prev = tempPrev;
    }
}

//se asume: i < l->size
void* listRemove(list_t* l, uint8_t i){
    node_t* tmp = NULL;
    void* data = NULL;
    if(i == 0){
        data = l->first->data;
        tmp = l->first;
        l->first = l->first->next;
    }else{
        node_t* n = l->first;
        for(uint8_t j = 0; j < i - 1; j++)
            n = n->next;
        data = n->next->data;
        tmp = n->next;
        n->next = n->next->next;
    }
    free(tmp);
    l->size--;
    return data;
}




void listDelete(list_t* l){
node_t* n = l->first;
while(n){
    node_t* tmp = n;
    n = n->next;
    switch(l->type) {
    case TypeFAT32:
        rm_fat32((fat32_t*) tmp->data);
        break;
    case TypeEXT4:
        rm_ext4((ext4_t*) tmp->data);
        break;
    case TypeNTFS:
        rm_ntfs((ntfs_t*) tmp->data);
        break;
    }
}
free(l);
}

int main(){
    list_t* l = listNew(TypeFAT32);
    fat32_t* f1 = new_fat32();
    fat32_t* f2 = new_fat32();
     
    listAddFirst(l, f1);
    listAddFirst(l, f2);

    listDelete(l);
    rm_fat32(f1);
    rm_fat32(f2);
    return 0;
}

// Force el error liberando solo la memoria de la lista y no la de sus nodos
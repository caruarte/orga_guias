#include <stdint.h>
#include <stdio.h>

typedef struct node {
    void* data;
    struct node* next;
} node_t;
typedef struct list {
    type_t type;
    uint8_t size;
    node_t* first;
} list_t;


typedef enum e_type {
TypeFAT32 = 0,
TypeEXT4 = 1,
TypeNTFS = 2
} type_t;

typedef uint32_t fat32_t;
typedef uint32_t ext4_t;
typedef uint32_t ntfs_t;

fat32_t* new_fat32(){
    return malloc(sizeof(fat32_t));
};
ext4_t* new_ext4() {
    return malloc(sizeof(ext4_t));
};
ntfs_t* new_ntfs(){
    return malloc(sizeof(ntfs_t));
};
fat32_t* copy_fat32(fat32_t* file){
    fat32_t* archivo = malloc(sizeof(fat32_t));
    *archivo = *file;
    return archivo;
};
ext4_t* copy_ext4(ext4_t* file){
    ext4_t* archivo = malloc(sizeof(ext4_t));
    *archivo = *file;
    return archivo;
};
ntfs_t* copy_ntfs(ntfs_t* file){
    ntfs_t* archivo = malloc(sizeof(ntfs_t));
    *archivo = *file;
    return archivo;
};
void rm_fat32(fat32_t* file){
    free(file);
};
void rm_ext4(ext4_t* file){
    free(file);
};
void rm_ntfs(ntfs_t* file){
    free(file);
};

list_t* listNew(type_t t) {
    list_t* l = malloc(sizeof(list_t));
    l->type = t; // l->type es equivalente a (*l).type
    l->size = 0;
    l->first = NULL;
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

    n->next = l->first;
    l->first = n;
    l->size++;
}

//se asume: i < l->size
void* listGet(list_t* l, uint8_t i){
node_t* n = l->first;
for(uint8_t j = 0; j < i; j++)
    n = n->next;
return n->data;
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
    free(tmp);
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
/*simple method */
int* twoSum_basic(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 0;
    for(int i=0; i<numsSize; i++){
        for(int j=i+1; j<numsSize; j++){
            if(nums[i]+nums[j] == target){
                int* ret = (int*)malloc(2*sizeof(int));
                if(ret ==NULL)
                    return NULL;
                *returnSize = 2;
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return NULL;
}

 /* hash map method */

struct hash_data{
    int index;
    // int data;
};
struct hash_table
{
    struct hash_data* element;
    const int* nums;
    int count;
};

int hash_init(struct hash_table* table, int count){
    if(count<=0)
        return -1;
    table->element = (struct hash_data*)malloc(sizeof(struct hash_data)*count);
    if(table->element==NULL)
        return -1;
    for(int i=0; i<count; i++){
        table->element[i].index = -1;
        //table->element[i].data = 0;
    }
    table->count = count;
    return 0;
}

void hash_free(struct hash_table* table){
    if(table->element!=NULL){
        free(table->element);
        table->element = NULL;
    }
    table->count = 0;
}

int hash_addr(int data, int table_count){
    int addr = data % table_count;
    return (addr>=0)?addr:(addr+table_count);
}

void hash_insert(struct hash_table* table, int data, int index){
    int addr = hash_addr(data, table->count);
    while(table->element[addr].index>=0){
        addr = (addr+1)%table->count;
    }
    table->element[addr].index = index;
    //table->element[addr].data = data;
}

struct hash_data* hash_find(struct hash_table* table, int data){
    int primary;
    int addr = primary = hash_addr(data, table->count);
    do{
        if(table->element[addr].index<0)
            return NULL;
        if(table->nums[table->element[addr].index] == data){
            return &table->element[addr];
        }
        addr = (addr+1)%table->count;
    }while(addr!=primary);
    return NULL;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int * ret = NULL;
    int addr;
    struct hash_table table;
    struct hash_data *p_data;
    if(hash_init(&table, numsSize+numsSize/5)<0){
        return twoSum_basic(nums, numsSize, target, returnSize);
    };
    table.nums = nums;
    *returnSize = 0;
    for(int i=0; i<numsSize; i++){
        if ((p_data=hash_find(&table,target-nums[i]))!=NULL){
                if((ret = (int*)malloc(2*sizeof(int)))==NULL){
                    break;
                }
                ret[0] = p_data->index;
                ret[1] = i;
                *returnSize = 2;
                return ret;
        }
        hash_insert(&table, nums[i], i);
    }
    hash_free(&table);
    return NULL;
}
void SetMinJump(int pos, int input[], int *minJump, int size){
    
    int i;
    if (pos < size && pos >= 0 && minJump[pos] > 0){
        for (i = pos; i <= size - 1 && i <= pos + input[pos]; i++){
            if (minJump[i] == 0){
                minJump[i] = minJump[pos] + 1;
            }
            else if (minJump[i] > minJump[pos] + 1){
                minJump[i] = minJump[pos] + 1;
            }
        }
    }
}

int walk(int array_size, int* array) {
    
    int *minJump = (int *)malloc(array_size * sizeof(int));
    int i;
    
    if (array == NULL || array_size <= 0)
        return -1;
    if (array_size == 1 && array[0] == 0)
        return -1;
    memset(minJump, 0, array_size * sizeof(int));
    minJump[0] = 1;

    for (i = 0; i <= array_size - 1; i++){
        SetMinJump(i, array, minJump, array_size);
    }
    

    i = minJump[array_size - 1] - 1;
    free(minJump);
    return i;

}

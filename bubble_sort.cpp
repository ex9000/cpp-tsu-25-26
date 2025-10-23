struct Index { long long int index; double value; };

void bubble_sort(Index arr[], long long int n){
    for(long long int i = 0; i < (n - 1); i++){
        for(long long int j = 0; j < (n - i - 1); j++){
            Index tec_el = arr[j];
            if(arr[j].value > arr[j+1].value){
                arr[j] = arr[j+1];
                arr[j+1] = tec_el;
            }
        }
    }
}

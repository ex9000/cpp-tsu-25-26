void insertion_sort(Index arr[], long long int n){
    for(long long int i = 1; i < n; i++){
        Index tec_el = arr[i];
        long long int j = i - 1;
        while(j >= 0 && arr[j].value > tec_el.value){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tec_el;
    }
}
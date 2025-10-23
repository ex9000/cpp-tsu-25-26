ScoredProduct convert_product(Product p, long long int k){
    ScoredProduct sp;
    sp.name = p.name;
    Index indices[k];
    for (long long int i = 0; i < k; i++) {
        indices[i].index = i;
        indices[i].value = p.prices[i];
    }
    insertion_sort(indices, k);
    double arr1[19];
    for(int i = 0; i < 19; i++){
        arr1[i] = p.prices[indices[i].index];
    };
    sp.score = average(arr1, 19);
    return sp;
}
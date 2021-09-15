int migratoryBirds(vector<int> arr) {
    int bird_id;
    int count, max_count=1, num;

    sort(arr.begin(), arr.end());

    for(int i=0;i<arr.size();){
        count = 1;
        num = arr[i];
    
        for(int j=i+1; ;j++){
            if(num == arr[j]){
                count++;
            }else{
                i = j;
                break;
            }
        }

        if(max_count<count){
            bird_id = num;
            max_count = count;
        }
    }
    
    return bird_id;
}
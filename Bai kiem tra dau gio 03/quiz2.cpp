int* merge(int* firstArr, int lenArr1, int* secondArr, int lenArr2){
    int *mergeArr = new int[lenArr1 + lenArr2];  // Tạo mảng mergeArr và cấp phát
    int firstIndex = 0, secondIndex = 0, mergeIndex = 0;
    if (firstArr[0] < firstArr[1]) {
        while (firstIndex < lenArr1 && secondIndex < lenArr2){
        if(firstArr[firstIndex] <= secondArr[secondIndex]){
            mergeArr[mergeIndex] = firstArr[firstIndex];
            firstIndex++;
        }else{
            mergeArr[mergeIndex] = secondArr[secondIndex];
            secondIndex++;
        }
        mergeIndex++;
    }
    while(firstIndex < lenArr1){
        // Nếu mảng firstArr còn phần tử thì thêm vào cuối mảng mergeArr
        mergeArr[mergeIndex++] = firstArr[firstIndex++];
    }
    
    while(secondIndex < lenArr2){
        // Nếu mảng secondArr còn phần tử thì thêm vào cuối mảng mergeArr
        mergeArr[mergeIndex++] = secondArr[secondIndex++];
    }
    return mergeArr;
    }
    else {
        while (firstIndex < lenArr1 && secondIndex < lenArr2){
        if(firstArr[firstIndex] >= secondArr[secondIndex]){
            mergeArr[mergeIndex] = firstArr[firstIndex];
            firstIndex++;
        }else{
            mergeArr[mergeIndex] = secondArr[secondIndex];
            secondIndex++;
        }
        mergeIndex++;
    }
    while(firstIndex < lenArr1){
        // Nếu mảng firstArr còn phần tử thì thêm vào cuối mảng mergeArr
        mergeArr[mergeIndex++] = firstArr[firstIndex++];
    }
    
    while(secondIndex < lenArr2){
        // Nếu mảng secondArr còn phần tử thì thêm vào cuối mảng mergeArr
        mergeArr[mergeIndex++] = secondArr[secondIndex++];
    }
    return mergeArr;
    }
}
void reverseString(char* s, int sSize) {
    
    int start, end;
    char aux;
    
    end = sSize-1;
    
    while(start < end){
        aux = s[end];
        s[end] = s[start];
        s[start] = aux;
        start++;
        end--;
    }
    
}
int GCD(int a, int b) {
     int x = min(a,b);
     int y = max(a,b);
     
     if (y%x==0) return x;
     return GCD(y%x,x);
}
 
bool is_coprime(int a, int b) {
    if (GCD(a,b)==1) return 1;
    return 0;
}
bool is_prime(int n) {
    if(n ==2) return 1;
    for(int i = 2; i*i<=n; i++) {
        if(n%i==0) return 0;
    }
    return 1;
}
void print_prime(int n) {
    for(int i = 2; i<=n ; i++) {
        if(is_prime(i)==1) cout<<i<<endl;
    }
}
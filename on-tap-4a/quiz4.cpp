struct Time {
    // your code goes here
    // Cac bien thanh vien
    // your code goes here
    // Hai ham khoi tao
    int h;
    int m;
    int s;
    
    Time() {
        h = 0;
        m = 0;
        s = 0;
    }
    
    Time(int hour, int minute, int second) {
        h = hour;
        m = minute;
        s = second;
    }

    int second() {
        return h*60*60 + m*60 + s;
    }
    
    void print() {
        string h1 = to_string(h);
        string m1 = to_string(m);
        string s1 = to_string(s);
        
        s1 = (s1.length() == 1) ? "0" + s1 : s1;
        m1 = (m1.length() == 1) ? "0" + m1 : m1;
        h1 = (h1.length() == 1) ? "0" + h1 : h1;
        
        cout<< h1 << ":" << m1 << ":" << s1 << endl;
    }
};

Time normalize(int hour, int minute, int second) {
    int h = hour;
    int m = minute;
    int s = second;
    if (s >= 60) {
        m += s/60;
        s = s%60;
    }
    if (m >= 60) {
        h += m/60;
        m = m%60;
    }
    
    return Time(h, m, s);
}
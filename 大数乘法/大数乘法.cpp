    string a, b;
    int aa[maxn], bb[maxn], result[2 * maxn];
    while(cin >> a >> b) {
        memset(aa, 0, sizeof(aa));
        memset(bb, 0, sizeof(bb));
        memset(result, 0, sizeof(result));
        int a_len = a.length();
        int b_len = b.length();
        if((a_len == 1 && a[0] == '0') || (b_len == 1 && b[0] == '0')) {
            cout << "0" << endl;
            continue;
        }
        for(int i = 0; i < a_len; i++) {
            aa[i] = a[a_len - i - 1] - '0';
        }
        for(int i = 0; i < b_len; i++) {
            bb[i] = b[b_len - i - 1] - '0';
        }
        for(int i = 0; i < a_len; i++) {
            for(int j = 0; j < b_len; j++) {
                result[i + j] += aa[i] * bb[j];
            }
        }
        int len = a_len + b_len;
        for(int i = 0; i <= len; i++) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
        while(result[len] == 0)
            len--;
        for(int i = len; i >= 0; i--) {
            cout << result[i];
        }

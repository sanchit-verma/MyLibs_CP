struct suffix
{
    int k,n;
    vector<int> p,c;
    vector<pair<char,int> > a;
    vector<pair<pair<int,int>,int> > ad;
    string s;
    suffix(string st){
        k  = 0;
        s = st + '_';
        n = st.length()+1;
        a.assign(n,{'_',0});
        ad.assign(n,{{0,0},0});
        p.assign(n,0); c.assign(n,0);
    }
    void radixsort(){
        {
            vector<pair<pair<int,int>,int> > adn(n);
            vector<int> cnt(n);
            for(auto x : ad){
                cnt[x.first.second]++;
            }
            vector<int> pos(n);
            pos[0] = 0;
            for(int i = 1; i < n; i++) {
                pos[i] = pos[i-1] + cnt[i-1];
            }
            for(auto x : ad){
                int i = x.first.second;
                adn[pos[i]] = x;
                pos[i]++;
            }
            ad = adn;
        }
        {
            vector<int> cnt(n);
            for(auto x : ad){
                cnt[x.first.first]++;
            }
            vector<pair<pair<int,int>,int> > adn(n); vector<int> pos(n);
            for(int i = 1; i < n; i++) {
                pos[i] = pos[i-1] + cnt[i-1];
            }
            for(auto x : ad){
                int i = x.first.first;
                adn[pos[i]] = x;
                pos[i]++;
            }
            ad = adn;
        }
    }
    void process(){
        for(int i = 0; i < n; i++) {
        a[i] = {s[i],i};
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for(int i = 1; i < n; i++) {
            if(a[i].first == a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else
                c[p[i]] = c[p[i-1]]+ 1;
        }
        while(1<<k < n){
            for(int i = 0; i < n; i++) {
                ad[i] = {{c[i],c[(i+(1<<k))%n]},i};
            }
            radixsort();
            for(int i = 0; i < n; i++) {
                p[i] = ad[i].second;
            }
            c[p[0]] = 0;
            for(int i = 1; i < n; i++) {
                if(ad[i].first == ad[i-1].first)
                    c[p[i]] = c[p[i-1]];
                else
                    c[p[i]] = c[p[i-1]]+1;
            }
            k++;
        }
    }
};

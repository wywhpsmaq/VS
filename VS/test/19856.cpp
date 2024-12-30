#include <bits/stdc++.h>
using namespace std;
struct Trieno {
    bool is;
    Trieno* ch[10];
    Trieno() : is(false) {
        for(int i=0;i<10;i++) ch[i]=nullptr;}
};
int ns(int p){
    if(p ==0) return 1;
    int cnt=0;
    while(p>0){
        p /=10;
        cnt++;}
    return cnt;}
int po[19];
void cp(){
    po[0]=1;
    for(int i=1;i<=18;i++) po[i]=po[i-1]*10;}
void tt(Trieno* no, string ct, vector<int> &fn){
    if(no->is){
        int num = 0;
        if(!ct.empty()){
            num = stoull(ct);
            fn.push_back(num);}
        return;}
    for(int i=0;i<10;i++) if(no->ch[i]!=nullptr) tt(no->ch[i], ct + to_string(i), fn);}
int cpx(int p, int lp, int x, int y){
    int cnt=0;
    for(int k=0; k<=18 - lp; k++){
        int pr = po[k];
        int stt = p * pr;
        int end = (p +1)*pr -1;
        if(stt > y || end <x) continue;
        int ast = max(stt, x);
        int aen = min(end, y);
        if(ast <= aen) cnt += (aen - ast +1);
    }
    return cnt;
}
int main(){
    cp();
    int x, y;
    int m;
    cin >> x >> y >> m;
    Trieno* root = new Trieno();
    for(int i=0;i<m;i++){
        int p;
        cin >> p;
        if(p ==0) continue;
        string s = to_string(p);
        Trieno* no = root;
        bool ct = true;
        for(char c : s){
            if(no->is){
                ct = false;
                break;}
            if(no->ch[c - '0'] == nullptr) no->ch[c - '0'] = new Trieno();
            no = no->ch[c - '0'];}
        if(ct) no->is = true;}
    vector<int> fn;
    tt(root, "", fn);
    int ted =0;
    for(auto p : fn){
        int lp = ns(p);
        ted += cpx(p, lp, x, y);}
    int tns = y - x +1;
    int sr =0;
    if(ted >= tns) sr =0;
    else sr = tns - ted;
    cout << sr;
}
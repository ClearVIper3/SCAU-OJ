class treeArr{
#define Mytype int
private:
    vector<Mytype> tarr;
    vector<Mytype> arr;
    Mytype n;
public:
    treeArr(){
        cin >> n;
        tarr.resize(n + 1,0);
        arr.resize(n + 1,0);
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        init();
    }
    
    treeArr(vector<int>& nums){
        n = nums.size();//nums下标从0开始
        tarr.resize(n + 1,0);
        arr.resize(n + 1,0);
        for (int i = 0; i < n; ++i) {
            arr[i + 1] = nums[i]; 
        }
        init();
    }

    Mytype lowbit(Mytype x){
        return x & -x;
    }

    void init(){
        for(int i = 1; i <= n; i++)
        {
            tarr[i] += arr[i];
            int j = i + lowbit(i);
            if(j <= n) tarr[j] += tarr[i];
        }
    }

    void add(Mytype x,Mytype nnew){
        Mytype k = nnew - arr[x];
        arr[x] = nnew;
        for(; x <= n; x += lowbit(x))
            tarr[x] += k;
    }

    Mytype ask(Mytype x)
    {
        Mytype ans = 0;
        for(; x > 0; x -= lowbit(x))
            ans += tarr[x];
        return ans;
    }
};

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> arr
    for(int i = 0; i < n; i++)
}

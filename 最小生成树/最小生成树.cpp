现在假设有一个很实际的问题：我们要在n个城市中建立一个通信网络，则连通这n个城市需要布置n-1一条通信线路，这个时候我们需要考虑如何在成本最低的
情况下建立这个通信网？ 
于是我们就可以引入连通图来解决我们遇到的问题，n个城市就是图上的n个顶点，然后，边表示两个城市的通信线路，每条边上的权重就是我们搭建这条线路
所需要的成本，所以现在我们有n个顶点的连通网可以建立不同的生成树，每一颗生成树都可以作为一个通信网，当我们构造这个连通网所花的成本最小时，搭
建该连通网的生成树，就称为最小生成树。
构造最小生成树有很多算法，但是他们都是利用了最小生成树的同一种性质：MST性质（假设N=(V,{E})是一个连通网，U是顶点集V的一个非空子集，如果（u，v）
是一条具有最小权值的边，其中u属于U，v属于V-U，则必定存在一颗包含边（u，v）的最小生成树），下面就介绍两种使用MST性质生成最小生成树的算法：普里
姆算法和克鲁斯卡尔算法。


Kruskal算法
算法思路： 
（1）将图中的所有边都去掉。 
（2）将边按权值从小到大的顺序添加到图中，保证添加的过程中不会形成环 
（3）重复上一步直到连接所有顶点，此时就生成了最小生成树。这是一种贪心策略。

        for(int i = 1; i <= n; i++) {
            gather[i] = i;
        }
        for(int i = 1; i <= m; i++) {
            scanf("%d %d %lld", &rode[i].from, &rode[i].to, &rode[i].cost);
        }

int gather[maxn];
struct rode_in {
    int from, to;
    long long cost;
} rode[maxn];

int Find(int x) {
    if(gather[x] == x) return x;
    return gather[x] = Find(gather[x]);
}

void Link(int x, int y) {
    int u = Find(x);
    int v = Find(y);
    if(u == v) return ;
    gather[u] = v;
}

bool cmp(rode_in a, rode_in b) {
    return a.cost < b.cost;
}

bool same(int x, int y) {
    return Find(x) == Find(y);
}

long long kruskal() {
    long long ans = 0;
    sort(rode + 1, rode + 1 + m, cmp);
    for(int i = 1; i <= m; i++) {
        if(same(rode[i].from, rode[i].to)) continue;
        Link(rode[i].from, rode[i].to);
        ans += rode[i].cost;
    }
    return ans;
}


prim算法
算法思路： 
首先就是从图中的一个起点a开始，把a加入U集合，然后，寻找从与a有关联的边中，权重最小的那条边并且该边的终点b在顶点集合：（V-U）中，
我们也把b加入到集合U中，并且输出边（a，b）的信息，这样我们的集合U就有：{a,b}，
然后，我们寻找与a关联和b关联的边中，权重最小的那条边并且该边的终点在集合：（V-U）中，我们把c加入到集合U中，并且输出对应的那条边的信息，
这样我们的集合U就有：{a,b,c}这三个元素了，一次类推，直到所有顶点都加入到了集合U。

        memset(gather, INF, sizeof(gather));
        scanf("%d", &m);
        while(m--) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            if(gather[u][v] > w) {
                gather[u][v] = gather[v][u] = w;
            }
        }

int n, m, gather[maxn][maxn], d[maxn];
bool vis[maxn];

int prim() {
    for(int i = 1; i <= n; i++) {
        vis[i] = 1;
        d[i] = gather[1][i];
    }
    vis[1] = 0;
    int ans = 0;
    while(true) {
        int t = -1;
        for(int i = 1; i <= n; i++) {
            if(vis[i] && (t == -1 || d[t] > d[i])) t = i;
        }
        if(t == -1) break;
        vis[t] = 0;
        ans += d[t];
        for(int i = 1; i <= n; i++) {
            d[i] = min(d[i], gather[t][i]);
        }
    }
    return ans;
}

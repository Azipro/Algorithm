一 概述

又称单词查找树，Trie树，是一种树形结构，是一种哈希树的变种。典型应用是用于统计，排序和保存大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。

二 优点

利用字符串的公共前缀来减少查询时间，最大限度地减少无谓的字符串比较，查询效率比哈希表高。

三 性质

（1）根节点不包含字符，除根节点外每一个节点都只包含一个字符； 
（2）从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串； 
（3）每个节点的所有子节点包含的字符都不相同。

四 应用

（1）串的快速检索

给出N个单词组成的熟词表，以及一篇全用小写英文书写的文章，请你按最早出现的顺序写出所有不在熟词表中的生词。 
在这道题中，我们可以用数组枚举，用哈希，用字典树，先把熟词建一棵树，然后读入文章进行比较，这种方法效率是比较高的。

（2）“串”排序

给定N个互不相同的仅由一个单词构成的英文名，让你将他们按字典序从小到大输出用字典树进行排序，采用数组的方式创建字典树，这棵树的每个结点的所有儿子很显然地按照其字母大小排序。对这棵树进行先序遍历即可。

（3）最长公共前缀

对所有串建立字典树，对于两个串的最长公共前缀的长度即他们所在的结点的公共祖先个数，于是，问题就转化为当时公共祖先问题。

五 实现

字典树的插入（Insert）、删除（ Delete）和查找（Find ）都非常简单，用一个一重循环即可，即第 i 次循环找到前 i 个字母所对应的子树，然后进行相应的操作。实现这棵字典树，我们用最常见的数组保存即可，当然也可以开动态的指针类型。至于结点对儿子的指向，一般有三种方法： 
（1）对每个结点开一个字母集大小的数组，对应的下标是儿子所表示的字母，内容则是这个儿子对应在大数组上的位置，即标号； 
（2）对每个结点挂一个链表，按一定顺序记录每个儿子是谁； 
（3）使用左儿子右兄弟表示法记录这棵树。 
三种方法，各有千秋。第一种易实现，但实际的空间要求较大；第二种， 
较易实现，空间要求相对较小，但比较费时；第三种，空间要求最小，但相对费时且不易写。但总的来说，几种实现方式都是比较简单的，只要在做题时加以合理选择即可。

指针实现：
struct node {
    int count;
    node* next[26];
    node() {
        count = 0;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
}*tree;

tree = new node();

void creat(char* s) {
    node* p = tree;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - 'a';
        if(p->next[x] == NULL) {
            p->next[x] = new node();
        }
        p = p->next[x];
        p->count++;//前缀出现次数
    }
（p -> count++)//这里则是记录整个字符串出现次数
}

int find(char* s) {
    node* p = tree;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - 'a';
        if(p->next[x] == NULL) {
            return 0;
        }
        p = p->next[x];
    }
    return p->count;
}


数组实现：
int tree[maxn][26];
int num[maxn];
int pos = 1;

    memset(tree, 0, sizeof(tree));
    memset(num, 0, sizeof(num));

void creat(char* s) {
    int root = 0;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - 'a';
        if(!tree[root][x]) {
            tree[root][x] = pos++;
        }
        root = tree[root][x];
        num[root]++;
    }
}

int  find(char* s) {
    int root = 0;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - 'a';
        if(!tree[root][x]) {
            return 0;
        }
        root = tree[root][x];
    }
    return num[root];
}

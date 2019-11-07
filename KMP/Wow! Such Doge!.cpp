//HDU 4847
Chen, Adrian (November 7, 2013). “Doge Is An Ac- tually Good Internet Meme. Wow.”. Gawker. Retrieved November 22, 2013.

Doge is an Internet meme that became popular in 2013. The meme typically con- sists of a picture of a Shiba Inu dog ac- companied by
multicolored text in Comic Sans MS font in the foreground. The text, representing a kind of internal monologue, is deliberately written 
in broken English, and usually contains the word “wow” and the phrases “such x”, “much x”, “many x”, “very x” and “so x”.
Kabosu, the Shiba Inu featured in the original meme, was first pictured in a 2010 blog post by Atsuko Sato, a Japanese kindergarten 
teacher. Afterwards, varia- tions of the pictures using overlaid Comic Sans text were posted from a Tumblr blog, Shiba Confessions. 
However, the use of the intentionally misspelled “doge” dates back to June 2005, when it was mentioned in an episode of Homestar Runners
puppet series.
In August 2013, images of the meme were spammed on Reddit’s r/MURICA subreddit by 4chan’s random imageboard, /b/. A search of the term 
doge on Google Trends shows an explosion of popularity occurring in October 2013, and more so in the following month. By November 2013, 
the meme had become widespread on the Internet. Google later created a Doge Easter egg: when doge meme was entered into the YouTube 
search bar, all of the site’s text would be displayed in colorful Comic Sans, similar to the kind used by the meme.
The meme was ranked #12 on MTV’s list of “50 Things Pop Culture Had Us Giving Thanks For” in 2013. Io9 compared the internal dialog of 
the Shiba Inu dogs to lolcat-speak. The image most commonly associated with the meme is of a female Shiba Inu named Kabosu, taken from
a Japanese blog documenting the dog’s daily activities. The spelling of doge has several variants, leading to debate on its actual 
pronunciation. On December 13, Doge was named the “top meme” of 2013 by Know Your Meme.
In December 2013, the Dogecoin was introduced as a new cryptocurrency, making it the first cryptocurrency to be based on an Internet
meme; the viral phenomenon, along with usage of the Comic Sans MS typeface, gave it “the Internet density of a large star” according 
to Medium writer Quinn Norton.
In late December 2013, members of the U.S. Congress produced material in the meme’s style. Huffington Post commented that Doge was 
“killed” because of the Congress members’ usage of the meme.
By early 2014, Doge’s popularity was sustained by internet communities on social media, accompanied by the rapid growth and acceptance 
of Dogecoin. In April 2014, Doge experienced a second major media resurgence due to revelations of the Dogecoin community’s intent to 
sponsor Josh Wise in NASCAR and place a picture of the Shiba Inu on his vehicle.

—— Doge (meme). (2014, May 18).
In Wikipedia, The Free Encyclopedia. Retrieved 02:00, May 22, 2014, from
http://en.wikipedia.org/w/index.php?title=Doge_(meme)&oldid=609040691

Now, Doge wants to know how many words “doge” are there in a given article. Would you like to help Doge solve this problem?
 

Input
An article that Doge wants to know.
The size of the article does not exceed 64KB. The article contains only ASCII characters.
 

Output
Please output the number of word “doge” (case-insensitive). Refer to the samples for more details.
 

Sample Input
adoge
cutedo 
yourge 
blownDoge
lovelyDooge
Wow!	Such Dooooooooooooooge!!!
D0ge
dOge DOGE 
dogedoge
 

Sample Output
6



#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include <queue>
#include<map>
#define maxn 3000005
#define mod 10007
using namespace std;

int t, n, m, a, b, ans, which, arr[maxn], prefix[maxn];
bool vis[maxn];
char s[maxn], str[maxn];

/*void setPrefix(){
    int i = 0;
    int len = -1;
    prefix[0] = -1;
    while(i < m){
        if(len == -1 || in[i] == in[len]){
            len++;
            i++;
            prefix[i] = len;
        }else{
            len = prefix[len];
        }
    }
}

void KMP(){
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(j == -1 || s[i] == str[j]){
            i++;
            j++;
        }else{
            j = prefix[j];
        }
        if(j == m){
            ans++;
            j = prefix[i];
        }
    }
}*/

int main() {
    //freopen("Test.txt", "r", stdin);
    ans = 0;
    while(scanf("%s", s) != EOF){
        int len = strlen(s);
        for(int i = 0; i < len; i++) {
            if((s[i] == 'd' || s[i] == 'D') && (len - i) >= 4) {
                if(s[i + 1] == 'O' || s[i + 1] == 'o') {
                    if(s[i + 2] == 'G' || s[i + 2] == 'g') {
                        if(s[i + 3] == 'E' || s[i + 3] == 'e')
                            ans++;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

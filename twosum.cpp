#include<stdio.h>
#include <string.h>
#include <string>
#include<utility>
#include <map>
using namespace std;

int main(){

        int a[6]={2,3,5,7,8,11};
        int target = 12;

        map<int, int> mp;
        map<int, int>::iterator it;

        for (int i = 0; i < 6; i++) {
            int diff = target - a[i];
            if (diff < 0) { return 0;}
            //printf("%d:%d\n",a[i],diff); 
            it = mp.find(diff);    
            printf("%d-->%d value:%d\n",it->first,it->second,diff);         
            if(it != mp.end()){
                printf("%d-->%d\n",it->first,a[i]); 
                //printf("%d-->%d\n",it->first,i); 
             }
             mp.insert(make_pair(a[i], i));
        }
       
        //  for (it = mp.begin(); it != mp.end(); it++){
        //          printf("result:%d-->%d\n", it->first, it->second);
        //  }

        return 0;
}
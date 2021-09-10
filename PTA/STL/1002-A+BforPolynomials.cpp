#include<iostream>
#include<list>

using namespace std;

struct poly {
    int ex;
    double co;
};

int main(){
    int k;
    scanf("%d", &k);
    list<poly> lst;    
    while (k--) {
        poly tmp;
        scanf("%d %lf", &tmp.ex, &tmp.co);
        lst.push_back(tmp);
    }
    scanf("%d", &k);
    list<poly>::iterator i = lst.begin();
    
    while (k--) {
        poly tmp;
        scanf("%d %lf", &tmp.ex, &tmp.co);
        while (i !=lst.end() && tmp.ex < (*i).ex) i++;
        if (i == lst.end()) lst.insert(i, tmp);//在i之前插入，i仍然指向插入的元素之后的元素
        else {
            if (tmp.ex > (*i).ex) lst.insert(i, tmp);
            else if (tmp.ex == (*i).ex) {
                double sum = tmp.co + (*i).co;
                if (sum == 0) i=lst.erase(i); //此步容易错,需要把i重新赋值，不然i还指向删除的元素
                else (*i).co = sum;
            }
        }
    }
    printf("%d", lst.size());
    i = lst.begin();
    while(i != lst.end()) {
        printf(" %d %.1lf", (*i).ex, (*i).co);
        i++;
    }
    return 0;
}
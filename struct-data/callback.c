#include <stdio.h>
#include <stdlib.h>

//C 库函数 void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)) 对数组进行排序。
// compar 参数指向一个比较两个元素的函数。比较函数的原型应该像下面这样。
// 注意两个形参必须是 const void * 型，同时在调用 compar 函数（compar 实质为函数指针，
// 这里称它所指向的函数也为 compar）时，传入的实参也必须转换成const void * 型。
// 在 compar 函数内部会将 const void * 型转换成实际类型，见下文。

// int compar(const void *p1, const void *p2);
// 如果 compar 返回值小于 0（< 0），那么 p1 所指向元素会被排在p2所指向元素的前面如果 compar 返回值等于 0（= 0），
// 那么 p1 所指向元素与 p2 所指向元素的顺序不确定如果 compar 返回值大于 0（> 0），
// 那么 p1 所指向元素会被排在 p2 所指向元素的后面

int sort_function(const void *a, const void *b);
int list[5] = {54, 21, 11, 67, 22};

int main(void)
{
    int x;
    qsort((void *)list, 5, sizeof(list[0]), sort_function);
    for (x = 0; x < 5; x++){
        printf("%i\n", list[x]);
        }
    return 0;
}

int sort_function(const void *a, const void *b) {
    printf("sort_function %d\n",*(int *)a - *(int *)b);
    return *(int *)a - *(int *)b;
}
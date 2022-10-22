#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define true 1
#define false 0
typedef char* string;
typedef int bool;
typedef int Item;






/*
	排序算法
*/
int* Bubble_Sort(int input[], int length); //冒泡排序
int* Selection_Sort(int input[], int length); //选择排序
int* Insertion_Sort(int input[], int length);//插入排序
int* Shell_Sort(int input[], int length); //Shell排序
int* Shell3n_Sort(int input[], int length); //Shell3n排序
int* Merge_Sort(int input[], int length); //归并排序
void Divide(int* array, int begin, int end, int* output);
void Conquer(int* array, int begin, int mid, int end, int* output);
void QuickSort(int* input, int length);
void  Qsort(int* input, int Left, int Right);
int Median3(int* input, int Left, int Right);
/*
	字符串全排列算法
*/
void ListPermutations(string str);  //全排列算法主函数
void PermuteWithFixedPrefix(string str, int k); //辅助函数
void ExchangeCharacters(string str, int p1, int p2);//辅助函数


/*
	斐波那契数列算法
*/
int fibocir(int n); //斐波那契循环算法
int fibofun(int n); //斐波那契迭代算法



bool isPrime(int n);  //素数判断算法


double fact(int n);  //阶乘计算算法


int digitCount(long int n); //计算数字位数



void swap(Item* a, Item* b);//交换两个int变量的值



void printCycleSquare(int n);//打印回文正方形

int gcd(int a, int b);//最大公约数

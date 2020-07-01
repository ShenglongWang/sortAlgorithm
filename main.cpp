#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;


//冒泡排序
void bubbleSort(vector<int> &q)
{
    for(int i = q.size()-1; i > 0; i--)
    {
        bool flag = false;
        for(int j = 0; j + 1 <= i; j++)
        {
            if(q[j] > q[j+1])
            {
                swap(q[j],q[j+1]);
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}



//选择排序
/*
# 每次选择最小的放在最前面
#第一次遍历选择出数组中最小值
#第二次遍历选择出除最小值外数组中的最小值
#依次类推，知道未排序数组为0
*/
void selectionSort(vector<int> &q)
{
    int i,j;
    for(i = 0; i < q.size(); i++)
    {
        for(j = i; j < q.size(); j++)
        {
            if(q[i] > q[j])
            {
                swap(q[i],q[j]);
            }
        }
    }
}


//插入排序
/*
#
#
#
*/
void insertionSort(vector<int> &q)
{
    int i,j,tmp;
    for(i = 1; i < q.size(); i++)
    {
        tmp = q[i];
        for(j = i - 1; j >= 0; j--)
        {
            if(q[j] > tmp)
            {
                q[j+1] = q[j];
            }
            else
            {
                break;
            }
        }
        q[j+1] = tmp;
    }

}



//堆排序

// 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
void adjust(vector<int> &arr, int len, int index)
{
    int left = 2*index + 1; // index的左子节点
    int right = 2*index + 2;// index的右子节点

    int maxIdx = index;
    if(left<len && arr[left] > arr[maxIdx])     maxIdx = left;
    if(right<len && arr[right] > arr[maxIdx])     maxIdx = right;

    if(maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }

}

// 堆排序
void heapSort(vector<int> &arr, int size)
{
    // 构建大根堆（从最后一个非叶子节点向上）
    for(int i=size/2 - 1; i >= 0; i--)
    {
        adjust(arr, size, i);
    }

    // 调整大根堆
    for(int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
        adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
    }
}



//打印Vector 信息
void infoVector(vector<int> Vec)
{
    int i;
    for(i = 0; i < Vec.size(); i++)
    {
        if (i == 0)
        {
            cout << "[";
        }
        cout << Vec[i];
        if(i != Vec.size() -1)
        {
            cout << " ";
        }
        else
        {
            cout << "]" << endl;
        }
    }
}


int main()
{

    //随机生成数组
    vector<int> temp;
    for(int i = 0; i < 100; i++)
    {
        temp.push_back(i + 1);
    }
    random_shuffle(temp.begin(),temp.end());



    //冒泡排序
    cout << "冒泡排序" << endl;
    vector<int> bubbVector = temp;
    cout << "Before Sorted " << endl;
    infoVector(bubbVector);
    bubbleSort(bubbVector);
    cout << "After Sorted " << endl;
    infoVector(bubbVector);


    //选择排序
    cout << "选择排序 "<< endl;
    vector<int> selectVec = temp;
    cout << "Before Sorted " << endl;
    infoVector(selectVec);
    selectionSort(selectVec);
    cout << "After Sorted " << endl;
    infoVector(selectVec);


    //插入排序
    cout << "插入排序 "<< endl;
    vector<int> insertVec = temp;
    cout << "Before Sorted " << endl;
    infoVector(insertVec);
    insertionSort(insertVec);
    cout << "After Sorted " << endl;
    infoVector(insertVec);


    //堆排序
    cout << "堆排序" <<endl;
    vector<int> heapVec = temp;
    cout << "Before Sorted" << endl;
    infoVector(heapVec);
    heapSort(heapVec,heapVec.size());
    cout << "After Sorted "<<endl;
    infoVector(heapVec);






    return 0;
}

#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;


//ð������
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



//ѡ������
/*
# ÿ��ѡ����С�ķ�����ǰ��
#��һ�α���ѡ�����������Сֵ
#�ڶ��α���ѡ�������Сֵ�������е���Сֵ
#�������ƣ�֪��δ��������Ϊ0
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


//��������
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



//������

// �ݹ鷽ʽ���������(len��arr�ĳ��ȣ�index�ǵ�һ����Ҷ�ӽڵ���±�)
void adjust(vector<int> &arr, int len, int index)
{
    int left = 2*index + 1; // index�����ӽڵ�
    int right = 2*index + 2;// index�����ӽڵ�

    int maxIdx = index;
    if(left<len && arr[left] > arr[maxIdx])     maxIdx = left;
    if(right<len && arr[right] > arr[maxIdx])     maxIdx = right;

    if(maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }

}

// ������
void heapSort(vector<int> &arr, int size)
{
    // ��������ѣ������һ����Ҷ�ӽڵ����ϣ�
    for(int i=size/2 - 1; i >= 0; i--)
    {
        adjust(arr, size, i);
    }

    // ���������
    for(int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);           // ����ǰ���ķ��õ�����ĩβ
        adjust(arr, i, 0);              // ��δ�������Ĳ��ּ������ж�����
    }
}



//��ӡVector ��Ϣ
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

    //�����������
    vector<int> temp;
    for(int i = 0; i < 100; i++)
    {
        temp.push_back(i + 1);
    }
    random_shuffle(temp.begin(),temp.end());



    //ð������
    cout << "ð������" << endl;
    vector<int> bubbVector = temp;
    cout << "Before Sorted " << endl;
    infoVector(bubbVector);
    bubbleSort(bubbVector);
    cout << "After Sorted " << endl;
    infoVector(bubbVector);


    //ѡ������
    cout << "ѡ������ "<< endl;
    vector<int> selectVec = temp;
    cout << "Before Sorted " << endl;
    infoVector(selectVec);
    selectionSort(selectVec);
    cout << "After Sorted " << endl;
    infoVector(selectVec);


    //��������
    cout << "�������� "<< endl;
    vector<int> insertVec = temp;
    cout << "Before Sorted " << endl;
    infoVector(insertVec);
    insertionSort(insertVec);
    cout << "After Sorted " << endl;
    infoVector(insertVec);


    //������
    cout << "������" <<endl;
    vector<int> heapVec = temp;
    cout << "Before Sorted" << endl;
    infoVector(heapVec);
    heapSort(heapVec,heapVec.size());
    cout << "After Sorted "<<endl;
    infoVector(heapVec);






    return 0;
}

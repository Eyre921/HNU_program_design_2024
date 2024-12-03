#include <bits/stdc++.h>
using namespace std;

// �������ܽṹ��
struct Frog {
    int position;       // ����λ��
    long long tongueLength; // ��ͷ����
    int mosquitoesEaten;  // �Ե�����������
    int originalIndex;    // ���ܵ�ԭʼ���
};

// �������ӽṹ��
struct Mosquito {
    int position;       // ����λ��
    long long weight;   // ��������
};

bool compareFrogsByPosition(const Frog& a, const Frog& b) {
    return a.position < b.position;  // �����ܵ�λ������
}

bool compareFrogsByOriginalIndex(const Frog& a, const Frog& b) {
    return a.originalIndex < b.originalIndex;  // ��ԭʼ�������
}

int main() {
    long long n, m;
    cin >> n >> m;

    vector<bool> mosquitoEaten(m, false);  // ��������Ƿ��ѱ��Ե�
    vector<Frog> frogs(n);                 // �洢��������
    vector<Mosquito> mosquitoes(m);        // �洢��������

    // ������������
    for (int i = 0; i < n; i++) {
        cin >> frogs[i].position >> frogs[i].tongueLength;
        frogs[i].mosquitoesEaten = 0;
        frogs[i].originalIndex = i + 1;
    }

    // ������������
    for (int i = 0; i < m; i++) {
        cin >> mosquitoes[i].position >> mosquitoes[i].weight;
    }

    // ������λ������
    sort(frogs.begin(), frogs.end(), compareFrogsByPosition);

    // ����ÿһֻ����
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (!mosquitoEaten[j] && frogs[i].position <= mosquitoes[j].position && frogs[i].position + frogs[i].tongueLength >= mosquitoes[j].position) {
                // �����ܳԵ�����
                frogs[i].tongueLength += mosquitoes[j].weight;  // ���ܳԵ����ӣ���ͷ��������
                mosquitoEaten[j] = true;  // ��������ѱ��Ե�
                frogs[i].mosquitoesEaten++;  // �������ܳԵ���������

                // �Ե�ǰ���ܣ�����Ƿ��ܳԵ���������
                for (int k = 0; k < j; k++) {
                    if (!mosquitoEaten[k] && frogs[i].position <= mosquitoes[k].position && frogs[i].position + frogs[i].tongueLength >= mosquitoes[k].position) {
                        frogs[i].tongueLength += mosquitoes[k].weight;  // �Ե�����
                        mosquitoEaten[k] = true;  // ��������ѱ��Ե�
                        frogs[i].mosquitoesEaten++;  // �������ܳԵ���������
                        k = -1;  // ����k�����¼����������
                    }
                }
                break;  // һ�����ܳԵ������ӣ��Ϳ���������ǰѭ����������һֻ����
            }
        }
    }

    // �������ܵ�ԭʼ˳��������
    sort(frogs.begin(), frogs.end(), compareFrogsByOriginalIndex);
    for (const Frog& frog : frogs) {
        cout << frog.mosquitoesEaten << " " << frog.tongueLength << endl;
    }

    return 0;
}
/*
������������

       �� n ֻ����λ�������� OX �ϣ�����ÿֻ���ܣ���������ֵ֪ xi��ti����ʾ�� i ֻ�����������λ�ã�������ͬ���Լ�������ͷ�ĳ��ȡ�ͬ���� m ֻ����һֻ��һֻ���䵽�������ϣ�����ÿֻ���ӣ���������ֵ֪�� pj ��ʾ�� j ֻ�������ڵ�λ�ã�bj Ϊ�� j ֻ���ӵ����������ܺ����ӱ�ʾΪ�����ϵĵ㡣

       ������Ӻ�������ͬһλ�û������ұߣ����ܿ��ԳԵ����ӣ�����֮��ľ��벻����������ͷ�ĳ��ȡ�

       ����м�ֻ���ܶ�����ĳһʱ�̳Ե�һֻ���ӣ�����ߵ����ܾͻ�Ե�������С�� xi�����������Ӻ����ܵ���ͷ���������������ĳ��ȣ���֮���������ܹ�����������(����ͷ��������֮��)��

       ���������������Լ����ܳԵ����п��ܵ�����֮�󣬶���ÿ�����ܣ��������ֵ���������ӵ������Լ���ͷ�ĳ��ȡ�

       ÿֻ����ֻ�������ܳ���֮ǰ���п��ܵ�����֮��Ż��䵽�����ϣ����ӵ�ֵ�ǰ����䵽�������ϵ�˳������ġ�

��������ʽ��

       ����ĵ�һ��Ϊ��������(1 �� n��m �� 2*105������ʾ���ܺ����ӵ�������

       �������� n �У�ÿ���������� xi��ti��0 �� xi��ti �� 109������ʾ�� i ֻ�������ڵ�λ���Լ�������ͷ�ĳ�ʼ���ȣ����뱣֤���е� xi ������ͬ��

       �������� m �У�ÿ���������� pj��bj��0 �� pj��bj �� 109������ʾ�� j ֻ�������µ�λ���Լ�����������

�������ʽ��

       ���Ϊ n �У��� i �а�������������ֵ ci��li����ʾ���� i ֻ���ܳԵ������������Լ����յ����ܵ���ͷ���ȡ�
����������1��

4 6
10 2
15 0
6 1
0 1
110 10
1 1
6 0
15 10
14 100
12 2
���������1��

3 114
1 10
1 1
1 2
����������2��

1 2
10 2
20 2
12 1
���������2��

1 3
 */